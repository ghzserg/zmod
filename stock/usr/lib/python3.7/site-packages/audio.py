#from MIDI import MIDIFile
from time import sleep
import signal
import sys
import argparse
from pathlib import Path

DEBUG = False
NOPWM = False
pwm = None


class PWMAudio:
    chip = 0
    device = 0
    PWMEXPORT = "/sys/class/pwm/pwmchip%d/export"
    PWMCLASS = "/sys/class/pwm/pwmchip%d/pwm%d/%s"
    ENABLE = "enable"
    PERIOD = "period"
    DUTY_CYCLE = "duty_cycle"

    DC = 0.5  # fixed
    enabled = False

    def __init__(self, chip, device):
        self.chip = chip
        self.device = device
        self.export()
        self.disable()

    def pwmdevice(self, end):
        return self.PWMCLASS % (self.chip, self.device, end)

    def export(self):
        # check if exists
        pwmpath = Path(self.PWMEXPORT[:-6] % (self.chip) + "/pwm%d" % (self.device))
        if pwmpath.is_dir():
            return
        with open(self.PWMEXPORT % self.chip, 'wb') as f:
            f.write(b"%d" % self.device)
            f.flush()

    def enable(self, enable=True):
        self.enabled = enable
        
        if self.period == 0:  # period needs to be set otherwise errors will be thrown
            self.set(1000)
        with open(self.pwmdevice(self.ENABLE), "wb") as f:
            f.write(b"1" if enable else b"0")
            f.flush

    def disable(self):
        self.enable(enable=False)

    @property
    def period(self):
        with open(self.pwmdevice(self.PERIOD), "rb") as f:
            return int(f.read())

    @period.setter
    def period(self, period):
        with open(self.pwmdevice(self.PERIOD), "wb") as f:
            f.write(b"%d" % period)
            f.flush()

    @property
    def duty_cycle(self):
        with open(self.pwmdevice(self.DUTY_CYCLE), "rb") as f:
            return int(f.read())

    @duty_cycle.setter
    def duty_cycle(self, dc):
        with open(self.pwmdevice(self.DUTY_CYCLE), "wb") as f:
            f.write(b"%d" % dc)
            f.flush()

    def set(self, frequency):
        period = 1000000000 / frequency
        dc = int(period * self.DC)
        if period < self.duty_cycle:
            self.duty_cycle = dc
            self.period = period
        else:
            self.period = period
            self.duty_cycle = dc

# needed due to how it's played
# def midinote(note, reference=440):
#     frequency = midinumber_to_frequency(note, reference) 
#     self.set(frequency)

def midinumber_to_frequency(number, reference=440, pitch=0):
    if pitch == 0:
        return (reference / 32) * (2 ** ((number - 9) / 12))
    elif pitch < 0:
        freq = (reference / 32) * (2 ** ((number - 9) / 12))
        down = (reference / 32) * (2 ** ((number - 9 - 12) / 12))
        return freq - ((freq - down) * (pitch / 8192))
    else:
        up = (reference / 32) * (2 ** ((number - 9 + 12) / 12))
        freq = (reference / 32) * (2 ** ((number - 9) / 12))
        return freq + ((up - freq) * (pitch / 8192))


def midinote_to_number(note, octave):
    m = {
        'cb': -1,
        'c': 0,
        'c#': 1,
        'db': 1,
        'd': 2,
        'd#': 3,
        'eb': 3,
        'e': 4,
        'f': 5,
        'f#': 6,
        'gb': 6,
        'g': 7,
        'g#': 8,
        'ab': 8,
        'a': 9,
        'a#': 10,
        'bb': 10,
        'b': 11,

    }
    return m[note] + (octave+1) * 12




def main():
    parser = argparse.ArgumentParser(
            prog="FF AD5M Audio 'player'",
            description='This program can either play a midi file, single track, single note, single chanel or a frequency for a specific duration',
            epilog="See https://github.com/xblax/flashforge_adm5_klipper_mod and https://github.com/consp/flashforge_adm5_audio")

    parser.add_argument('mode', type=str, help="Either midi or freq", choices=['midi', 'freq', 'disable'])
    parser.add_argument('-f', '--frequency', type=int, help="Frequency", default=440)
    parser.add_argument('-d', '--duration', type=float, help="Duration of frequency", default=1.0)
    parser.add_argument('-c', '--channel', type=str, help="Channel of track to play", default="0")
    parser.add_argument('-m', '--midifile', type=str, help="Midi filename")
    parser.add_argument('-p', '--pwm', type=int, help="pwm device to use", default=6)
    parser.add_argument('-v', '--verbose', action="store_true", default=False, help="Be verbose (might slow down playback in case of heavy pitch changes)")
    parser.add_argument('-s', '--skip', action='store_true', default=False, help="Skip start rest")
    parser.add_argument('--nopwm', action='store_true', default=False, help="Disable PWM driver, used for testing midi file reading")

    args = parser.parse_args()

    global DEBUG
    global NOPWM
    DEBUG = args.verbose
    NOPWM = args.nopwm

    if not NOPWM:
        if DEBUG:
            print("Opening pwm ", args.pwm)
        pwm = PWMAudio(0, args.pwm)
    else:
        if DEBUG:
            print("PWM driver disabled")
        pwm = None

    def signal_handler(sig, frame):
        pwm.disable()
        sys.exit(0)

    for sig in ('TERM', 'HUP', 'INT'):
        signal.signal(getattr(signal, 'SIG'+sig), signal_handler)

    if args.mode == "disable" and not NOPWM:
        pwm.disable()
    elif args.mode == "freq" and not NOPWM:
        pwm.set(args.frequency)
        pwm.enable()
        sleep(args.duration)
        pwm.disable()
    elif args.mode == 'midi':
        # lazy load

        def play(filename, channel, pwm=None, skip_start=False):
            import mido
            import threading
            def work(filename, channel, pwm, skip_start):
                midi = mido.MidiFile(filename)
                ticks_per_beat = midi.ticks_per_beat
                tracks = midi.tracks
                tracks_to_play = []
                tempo = 500000
                if DEBUG:
                    print("Looking for track %s" % (str(channel)))
                if "," in channel:
                    channels = [int(x) for x in channel.split(",")]
                else:
                    channels = [int(channel)]

                for track in tracks:
                    for msg in track:
                        if msg.type in ['control_change', 'note_on', 'note_off'] and msg.channel in channels:
                            tracks_to_play.append(track)
                            break
                        elif hasattr(msg, 'channel') and msg.channel not in channels:
                            break

                if len(tracks_to_play) == 0:
                    print("Channel %s not found" % channel)
                    return
                started = False
                # play index track and track to play
                pitch = 0
                note = 0
                started = False

                for event in mido.merge_tracks(tracks_to_play):
                    # if hasattr(event, 'channel') and event.channel not in channels:
                    #     continue
                    interval = mido.tick2second(event.time, ticks_per_beat, tempo)
                    if DEBUG and interval > 0:
                        print("Rest: ", interval)
                    if not skip_start or (skip_start and started):
                        sleep(interval)
                    if event.type == 'copyright':
                        print("Copyright ", event.text)
                    elif event.type == "track_name":
                        print("Track: ", event.name)
                    elif event.type == 'set_tempo':
                        tempo = event.tempo
                        if DEBUG:
                            print("Tempo change: %d %d %d" % (ticks_per_beat, tempo, interval))
                    elif event.type == 'note_on':
                        started = True
                        note = event.note
                        if DEBUG:
                            print("%d Note ON: %d" % (event.channel, event.note))
                        if pwm:
                            pwm.set(midinumber_to_frequency(note, pitch=pitch))
                            pwm.enable()
                    elif event.type == 'note_off':
                        if DEBUG:
                            print("%d Note OFF: %d" % (event.channel, event.note))
                        if pwm:
                            pwm.disable()
                    elif event.type == "pitchwheel":
                        pitch = event.pitch
                        if DEBUG:
                            print("%d Pitch change by %d" % (event.channel, event.pitch))
                        if pwm:
                            pwm.set(midinumber_to_frequency(note, pitch=pitch))
                    else:
                        if DEBUG:
                            print(event)
                # silence
                pwm.disable()

            t = threading.Thread(target=work, args=(filename, channel, pwm, skip_start))
            t.start()
        if args.midifile is None:
            print("--midifile/-m needs to be set")
            exit(1)
        print("Loading %s ..." % args.midifile)
        try:
            play(args.midifile, args.channel, pwm, skip_start=args.skip)
        except Exception as e:
            if pwm:
                pwm.disable()
            raise

if __name__ == '__main__':
    main()
