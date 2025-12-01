# ZMOD Macros List
A macro is a small program written in Klipper/Gcode.

It can be called from:
- A GCODE file
- The Fluidd/Mainsail console (press the `C` key in Fluidd).

*Default values are shown in parentheses.*

---

## Main
### LANG

Set the language for zMod to work in.

- LANG - language, en - English, ru - Russian, de - German, fr - French, it - Italian, es - Spanish, zh - Chinese, ja - Japanese, ko - Korean, pt - Portugal

Example:
```
LANG LANG=en
```

### START_PRINT
Replaces the native start G-code (if using the screen, add M140/M190 for bed temp and M109/M104 for extruder temp).
- **EXTRUDER_TEMP**: Extruder temperature (245).
- **BED_TEMP**: Bed temperature (80).
- **MESH**: Name of the bed mesh to load. If empty, no mesh is loaded. If it doesn’t exist, a new mesh will be created ("").
- **FORCE_LEVELING**: Force bed leveling (False).
- **SKIP_LEVELING**: Skip bed leveling under any conditions. Overrides FORCE_KAMP and FORCE_LEVELING (False).
- **FORCE_KAMP**: Build an adaptive bed mesh (False). *Recommended to also set `SAVE_ZMOD_DATA CLEAR=LINE_PURGE` to use the purge area for mesh calibration.*
- **Z_OFFSET**: Set Z offset (0.0).
- **SKIP_ZOFFSET**: For native screen printing, do not set Z offset (True for native screen / False for headless mode).
- **INTERNAL**: For Pro versions in headless mode: 0 = external airflow, 1 = internal recirculation (1).

**Notes:**
- Any calibration (FORCE_KAMP or FORCE_LEVELING) triggers [CLEAR_NOZZLE](https://github.com/ghzserg/zmod/wiki/Macros_en_old#clear_nozzle).
- During START_PRINT, [ZSSH_RELOAD](https://github.com/ghzserg/zmod/wiki/Macros_en_old#zssh_reload) restores SSH connections if needed.

**Example for Orca with native screen:**
Replace the start G-code with:
```
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single]
M104 S[nozzle_temperature_initial_layer]
```

**Example for Orca in headless mode:**
```
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
```

To display layer count correctly in Fluidd, add to the start G-code:
```
SET_PRINT_STATS_INFO TOTAL_LAYER=[total_layer_count]
```
And add to the layer change G-code:
```
SET_PRINT_STATS_INFO CURRENT_LAYER={layer_num + 1}
```

[Bed leveling options](https://github.com/ghzserg/zmod/wiki/FAQ_en#what-bed-leveling-methods-are-available)

#### Global Flags (set via [SAVE_ZMOD_DATA](https://github.com/ghzserg/zmod/wiki/Macros_en_old#save_zmod_data)):
- **PRECLEAR**: Enable nozzle pre-cleaning in [CLEAR_NOZZLE](https://github.com/ghzserg/zmod/wiki/Macros_en_old#clear_nozzle) (0 = off, 1 = on).
- **CLEAR**: Nozzle purge method (LINE_PURGE).
- **PRINT_LEVELING**: Always build a bed mesh before printing (0 = off, 1 = on).
- **USE_KAMP**: Use adaptive mesh (KAMP) instead of full mesh (0 = off, 1 = on).
- **DISABLE_PRIMING**: Disable priming extrusion (0 = off, 1 = on).
- **FORCE_MD5**: Verify file MD5 checksums (1 = enabled by default).
- **DISABLE_SKEW_CORRECT**: Disable skew correction (1 = disabled).
- **AUTO_REBOOT**: Auto-reboot after print (0 = off, 1 = reboot, 2 = firmware restart).
- **CLOSE_DIALOGS**: Auto-close dialogs post-print (0 = off, 1 = slow, 2 = fast).
- **STOP_MOTOR**: Disable motors 25 seconds after print (1 = on).
- **MIDI_START/END**: Play MIDI files at print start/end ("").

---

### END_PRINT
Replaces the native end G-code.

#### Global Flags (set via [SAVE_ZMOD_DATA](https://github.com/ghzserg/zmod/wiki/Macros_en_old#save_zmod_data)):
- **AUTO_REBOOT**: Auto-reboot after print (0 = off, 1 = reboot, 2 = firmware restart).
- **CLOSE_DIALOGS**: Auto-close dialogs post-print (0 = off, 1 = slow, 2 = fast).
- **STOP_MOTOR**: Disable motors 25 seconds after print (1 = on).
- **MIDI_END**: Play MIDI at print end ("").

---

### KAMP
Adaptive bed leveling with nozzle cleaning.
- **EXTRUDER_TEMP**: Extruder temperature (240).
- **BED_TEMP**: Bed temperature (80).

**Recommended:** Use [START_PRINT](https://github.com/ghzserg/zmod/wiki/Macros_en_old#start_print) with `SAVE_ZMOD_DATA PRINT_LEVELING=1 USE_KAMP=1`.

---

### AUTO_FULL_BED_LEVEL
Full bed calibration with nozzle cleaning.
- **EXTRUDER_TEMP**: Extruder temperature (230).
- **BED_TEMP**: Bed temperature (80).
- **PROFILE**: Mesh profile name (auto).

---

### CANCEL
Abort the current print.

---

### CLEAR_NOZZLE
Nozzle cleaning (native method).
- **EXTRUDER_TEMP**: Extruder temperature (230).
- **BED_TEMP**: Bed temperature (80).

*Enable pre-cleaning via `SAVE_ZMOD_DATA PRECLEAR=1`.*

---

### LED_ON
Turn on LED lighting.

### LED_OFF
Turn off LED lighting.

### LED
Set LED brightness.
- **S**: Brightness percentage (50).

---

### PAUSE
Pause the print.

### RESUME
Resume the print.

---

### PLAY_MIDI
Play a MIDI file.
- **FILE**: Filename (e.g., `For_Elise.mid`). Files are stored in `mod_data/midi/`.

---

### REBOOT
Reboot the printer.

---

### CLOSE_DIALOGS
Slowly close dialogs on the native screen (may cause freezes).

### FAST_CLOSE_DIALOGS
Quickly close dialogs on the native screen. *Requires enabling "Local Network Only".*

---

### NEW_SAVE_CONFIG
Save Klipper configuration without freezing the screen (experimental).

---

### ZRESTORE
Resume print after power loss or errors. *Disabled when using the native screen.*

---

## Calibrations
### BED_LEVEL_SCREWS_TUNE
Bed screw adjustment using probe.
- **EXTRUDER_TEMP**: Extruder temperature (240).
- **BED_TEMP**: Bed temperature (80).

---

### LOAD_CELL_TARE
Reset strain gauge weight.

---

### PID_TUNE_BED
PID calibration for the bed.
- **TEMPERATURE**: Target temperature (80).

---

### PID_TUNE_EXTRUDER
PID calibration for the extruder.
- **TEMPERATURE**: Target temperature (245).
- **COOLER**: Fan speed (255).

---

### ZSHAPER
Input shaper calibration. Graphs are saved in `mod_data/`.

### BELTS_SHAPER_CALIBRATION
Belt resonance analysis.
- **SPECTROGRAM**: Generate spectrogram (1 = enabled).

---

### NOZZLE_CONTROL

Detects part detachment or nozzle collision with the bed.

Emergency printer shutdown if weight limit is exceeded.

WEIGHT - weight in grams (1500)

Settings persist after reboot.

Set `NOZZLE_CONTROL WEIGHT=0` to disable this feature.

*Control is disabled until the first macro call.*

When using the stock screen, executing the macro reboots the printer.

When operating without the stock screen, it restarts Klipper since configuration files are modified.

Everything works automatically, but the following macros are also available for use in Gcode:

- `ZCONTROL_ON` - activate monitoring
- `ZCONTROL_OFF` - deactivate monitoring
- `ZCONTROL_STATUS` - check function status
- `ZCONTROL_PAUSE` - trigger pause on detection (pause executes only after command queue clears; avoid enabling on first layers)
- `ZCONTROL_ABORT` - trigger KLIPPER shutdown on detection

To enable nozzle monitoring on first layers, add `ZCONTROL_PAUSE` via the slicer at the layer where pause should replace abort.

---

## Layer Pause
### SET_PAUSE_NEXT_LAYER
Pause/trigger macro on the next layer.
- **ENABLE**: 0 = off, 1 = on (1).
- **MACRO**: Macro to execute (`PAUSE`).

### SET_PAUSE_AT_LAYER
Pause/trigger macro at a specific layer.
- **ENABLE**: 0 = off, 1 = on (1).
- **MACRO**: Macro to execute (`PAUSE`).
- **LAYER**: Layer number (0).

---

## Filament
### COLDPULL
Cold pull nozzle cleaning. Follow on-screen instructions.

### M600
Filament change.

### COLOR
*AD5X only*: Filament type/color management (native screen required).

---

## System
### CAMERA_ON
Enable alternate camera.
- **WIDTH**: Resolution width (640).
- **HEIGHT**: Resolution height (480).
- **FPS**: Framerate (20).
- **VIDEO**: Camera device (`video0`).
- **FS**: Fix frame size for unstable cameras (0 = off).

### CAMERA_OFF
Disable alternate camera.

### CAMERA_RESTART
Restart alternate camera.

---

### GET_ZMOD_DATA
View current ZMOD parameters.

### SAVE_ZMOD_DATA
Save global ZMOD parameters (persistent after reboots).

**Usage:**
```
SAVE_ZMOD_DATA PARAMETER=value
```
Example:
```
SAVE_ZMOD_DATA CLOSE_DIALOGS=2
```
### Parameters Used During Print Start and Bed Leveling [START_PRINT]
#### MIDI_START
Play MIDI at print start (""). Use `0` to disable.
**Example:** `SAVE_ZMOD_DATA MIDI_START=Pain-Shut-your-mouth.mid`

#### PRECLEAR
Enable nozzle pre-cleaning in [CLEAR_NOZZLE](#clear_nozzle).
- `0` = Disabled (default)
- `1` = Enabled
**Example:** `SAVE_ZMOD_DATA PRECLEAR=0`

#### PRINT_LEVELING
Always build a bed mesh before printing (using the native screen if enabled).
- `0` = Disabled (default)
- `1` = Enabled
*To use native screen bed leveling, enable "Local Network Only" in printer settings:
`Settings` → `WiFi icon` → `Network Mode` → Toggle "Local Network Only`.*
**Example:** `SAVE_ZMOD_DATA PRINT_LEVELING=1`

#### USE_KAMP
Use adaptive bed mesh (KAMP) instead of full mesh where possible.
- `0` = Disabled (default)
- `1` = Enabled
*Recommended to set `SAVE_ZMOD_DATA CLEAR=LINE_PURGE` to use the purge area for mesh calibration.*
**Example:** `SAVE_ZMOD_DATA USE_KAMP=1`

#### MESH_TEST
Test bed mesh before printing.
- `0` = Disabled
- `1` = Enabled (default)
Probes the bed to verify the loaded mesh matches the physical setup. Triggers a warning if deviations exceed ±0.21mm.
**Example:** `SAVE_ZMOD_DATA MESH_TEST=0`

#### FORCE_MD5
Validate file integrity using MD5 checksums. Corrupted files are deleted.
- `0` = Disabled
- `1` = Enabled (default)
*Add [addMD5.bat](https://github.com/ghzserg/zmod/releases/download/R/addMD5.bat) (Windows) or [addMD5.sh](https://github.com/ghzserg/zmod/releases/download/R/addMD5.sh) (Linux) to post-processing scripts in your slicer.*
**Example:** `SAVE_ZMOD_DATA FORCE_MD5=1`

#### DISABLE_SKEW_CORRECT
Disable skew correction.
- `0` = Load `skew_profile` (default)
- `1` = Disabled
[Learn more](https://www.klipper3d.org/Skew_Correction.html)
**Example:** `SAVE_ZMOD_DATA DISABLE_SKEW_CORRECT=1`

#### LOAD_ZOFFSET
Load saved Z-offset from `SET_GCODE_OFFSET`.
- `0` = Disabled
- `1` = Enabled (default)
[How Z-offset works](https://github.com/ghzserg/zmod/wiki/FAQ_en#how-does-z-offset-work)
**Example:** `SAVE_ZMOD_DATA LOAD_ZOFFSET=0`

#### DISABLE_PRIMING
Disable nozzle priming extrusion.
- `0` = Enabled (default)
- `1` = Disabled
**Example:** `SAVE_ZMOD_DATA DISABLE_PRIMING=0`

#### CLEAR
Select nozzle purge method:
- `_CLEAR1`: Orca-style (may scratch bed with KAMP)
- `_CLEAR2`: FF group variant 1 (may scratch bed)
- `_CLEAR3`: FF group variant 2 (may scratch bed)
- `_CLEAR4`: Top-right to bottom-left wipe
- `_CLEAR_TRAP`: Brush-assisted wipe (top-right)
- `LINE_PURGE`: KAMP purge (default)
*Custom purge macros can be added to `mod_data/user.cfg`.*
**Example:** `SAVE_ZMOD_DATA CLEAR=LINE_PURGE`

---

### Parameters Used During Print End/Cancel [END_PRINT]
#### MIDI_END
Play MIDI at print end (""). Use `0` to disable.
**Example:** `SAVE_ZMOD_DATA MIDI_END=Pain-Shut-your-mouth.mid`

#### CLOSE_DIALOGS
Auto-close print completion dialogs.
- `0` = Disabled (default)
- `1` = Slow close
- `2` = Fast close
*Enable "Local Network Only" for fast closing.*
**Example:** `SAVE_ZMOD_DATA CLOSE_DIALOGS=2`

#### STOP_MOTOR
Disable motors 25 seconds after print/cancel.
- `0` = Disabled
- `1` = Enabled (default)
**Example:** `SAVE_ZMOD_DATA STOP_MOTOR=1`

#### AUTO_REBOOT
Auto-reboot after print:
- `0` = Disabled (default)
- `1` = Full reboot (`REBOOT`)
- `2` = Firmware restart (`FIRMWARE_RESTART` for headless mode)
**Example:** `SAVE_ZMOD_DATA AUTO_REBOOT=0`

---

### System-Wide Parameters
#### MOTION_SENSOR
Use [filament motion sensor](https://aliexpress.ru/item/1005007480443587.html) instead of filament runout sensor.
- `0` = Disabled (default)
- `1` = Enabled
*Disable native filament sensor on the screen.*
**Example:** `SAVE_ZMOD_DATA MOTION_SENSOR=1`

#### FIX_SCV
Correct [square_corner_velocity](https://www.klipper3d.org/Config_Reference.html#printer) in shaper graphs.
- `0` = Stock value (`5`, default)
- `1` = Use value from `mod_data/user.cfg`
*Recommended: Add `square_corner_velocity: 9` to `mod_data/user.cfg` for better print quality.*
**Example:** `SAVE_ZMOD_DATA FIX_SCV=1`

#### FIX_E0011
**This is an experimental parameter**

**Global causes of E0011 error:**
- Host did not respond within allotted time (0.025 sec)
- MCU did not respond within allotted time (0.025 sec)

**Specific causes:**
- Frozen Nations MCU mainboard or eboard (`Lost communication with MCU 'mcu'`).
  **Fix:** Reboot. Replace mainboard (`mcu`) or extruder board (`eboard`).
- Host processor overload (shaper calculations/graph generation).
- EMMC overload (git operations, backups, large file uploads during printing).
- Insufficient RAM. **Fix:** Re-solder CPU and upgrade RAM to 256 MB.
- Damaged extruder cable. **Fix:** Replace/adjust cable.
- Extruder head board connector issues. **Fix:** Replace extruder board.
- SWAP data loading (SWAP on EMMC with 10 MB/s speed; SWAP usage during shaper generation reaches 25 MB).
  **Fix:** Disable SWAP if using 256 MB RAM: `SAVE_ZMOD_DATA USE_SWAP=0`.
- MCU firmware failure. **Fix:** Reflash MCU via [factory reset](https://github.com/ghzserg/zmod/wiki/Setup_en#restoring-printer-to-factory-settings-required-for-mod-installation) or use mod [UPDATE_MCU](#update_mcu).

**Fix E0011 and `Communication timeout during homing`:**
Printer reboots when changing parameter. 0=No, 1=Yes (default: 0)
- `0` keeps stock value: **0.025**
- `1` sets value to: **0.05**

Example: `SAVE_ZMOD_DATA FIX_E0011=1`

**About `Communication timeout during homing`:**
Occurs due to high latency between host and MCUs. Round-trip time should consistently stay below 10 ms. Short latency spikes can cause homing failures.

**TRSYNC_TIMEOUT** (Klipper parameter):
- Stock value: `0.025` sec (file: `/opt/klipper/klippy/mcu.py`)
- Patched value: `0.1` sec

**Stock firmware fix:**
1. Format USB as FAT32.
2. Save to USB flash:
   - **[Fix parameter](https://github.com/ghzserg/zmod/blob/main/Native_firmware/e0011/fix/flashforge_init.sh)**
   - **[Restore stock parameter](https://github.com/ghzserg/zmod/blob/main/Native_firmware/e0011/orig/flashforge_init.sh)**
3. Power off printer.
4. Insert USB into printer.
5. Power on printer (loud beeping will occur).
6. Wait for reboot.
7. Remove USB.
8. Reprint problematic file — E0011 should resolve.

**Manual stock firmware fix:**
1. Install [root](https://github.com/ghzserg/zmod/tree/main/Native_firmware/root).
2. Connect via [WinSCP](https://winscp.net/eng/download.php) over SSH.
3. Edit `/opt/klipper/klippy/mcu.py`.
4. Find line: `TRSYNC_TIMEOUT = 0.025`.
5. Replace with: `TRSYNC_TIMEOUT = 0.1`.
6. Save file.
7. Reboot printer.

#### FIX_E0017

Fix E0017 error - printer will reboot when changing parameter. 0=No, 1=Yes (1)

In file `/opt/klipper/klippy/toolhead.py`:
Stock parameter `LOOKAHEAD_FLUSH_TIME = 0.5`, original Klipper uses `LOOKAHEAD_FLUSH_TIME = 0.250`.
Our modification works well with `LOOKAHEAD_FLUSH_TIME = 0.150`

- 0 sets parameter to stock value
- 1 sets parameter to 0.150

Example: `SAVE_ZMOD_DATA FIX_E0017=1`

**Stock firmware fix:**
- Format USB as FAT32
- Save to USB flash:
  - [Adventurer5M-e0017-4.tgz](https://github.com/ghzserg/zmod/releases/download/R/Adventurer5M-e0017-4.tgz) for FlashForge 5M
  - [Adventurer5MPro-e0017-4.tgz](https://github.com/ghzserg/zmod/releases/download/R/Adventurer5MPro-e0017-4.tgz) for FlashForge 5M Pro
- Power off printer
- Insert USB into printer
- Power on printer
- Printer will beep loudly
- Wait for automatic reboot
- Remove USB flash
- Reprint problematic file - E0017 error should be resolved

**Manual stock firmware fix:**
- Install [root](https://github.com/ghzserg/zmod/tree/main/Native_firmware/root)
- Connect via [WinSCP](https://winscp.net/eng/download.php) over SSH
- Edit file `/opt/klipper/klippy/toolhead.py`
- Find line: `LOOKAHEAD_FLUSH_TIME = 0.5`
- Replace with: `LOOKAHEAD_FLUSH_TIME = 0.150`
- Save file to printer
- Reboot printer

#### LED
LED brightness at startup (50%).
**Example:** `SAVE_ZMOD_DATA LED=50`

#### MIDI_ON
Play MIDI at printer startup (""). Use `0` to disable.
**Example:** `SAVE_ZMOD_DATA MIDI_ON=Pain-Shut-your-mouth.mid`

#### NEW_SAVE_CONFIG
Use non-freezing `SAVE_CONFIG` for PID calibration.
- `0` = Disabled (default)
- `1` = Enabled
**Example:** `SAVE_ZMOD_DATA NEW_SAVE_CONFIG=0`

#### USE_SWAP
Enable swap memory:
- `0` = Disabled (requires 256MB RAM)
- `1` = Use EMMC (default)
- `2` = Prefer USB flash
**Example:** `SAVE_ZMOD_DATA USE_SWAP=1`

#### CHINA_CLOUD
##### CHINA_CLOUD
Enable Chinese cloud services: 0=No, 1=Yes (default: 0)

Example: `SAVE_ZMOD_DATA CHINA_CLOUD=0`

[Disabling Chinese clouds (recommended)](https://github.com/ghzserg/zmod/wiki/Recomendations_en#disable-chinese-cloud-services)

**Important:**
Even if all cloud-related options are disabled via the printer interface, the device may still attempt to send photos, videos, and telemetry to Chinese servers. Setting this parameter to `0` partially blocks these manufacturer-background activities.

⚠️ **WARNING:**
Disabling Chinese clouds **stops automatic firmware updates**. To update stock firmware:
1. Re-enable cloud services: `SAVE_ZMOD_DATA CHINA_CLOUD=1`
2. Reboot the printer
3. Perform firmware update

### **Stock firmware configuration**

#### To **disable** Chinese clouds:
1. Format USB drive as FAT32
2. Download file:
   [flashforge_init.sh (disable cloud)](https://github.com/ghzserg/zmod/blob/main/Native_firmware/cloud/rem/flashforge_init.sh)
3. Copy the file to the USB drive
4. Power off the printer
5. Insert USB into the printer
6. Power on the printer
7. Wait for 1 reboot cycle
8. Remove USB drive

#### To **enable** Chinese clouds:
1. Format USB drive as FAT32
2. Download file:
   [flashforge_init.sh (enable cloud)](https://github.com/ghzserg/zmod/blob/main/Native_firmware/cloud/orig/flashforge_init.sh)
3. Copy the file to the USB drive
4. Follow steps 4-8 above

#### NICE
Set Klipper process priority (1-40, higher = more resources). Default: `20`.
**Example:** `SAVE_ZMOD_DATA NICE=20`

#### DISPLAY_OFF_TIMEOUT
Native screen timeout in headless mode (seconds). Default: `180`.
**Example:** `SAVE_ZMOD_DATA DISPLAY_OFF_TIMEOUT=120`

#### PRO_POWEROFF_TIMEOUT
Auto-poweroff timer for FF5M Pro (minutes). `0` = Disabled.
**Example:** `SAVE_ZMOD_DATA PRO_POWEROFF_TIMEOUT=10`

#### SAVE_MOONRAKER
Custom macro button layouts:
- `0` = Use ZMOD defaults (default)
- `1` = Allow user-defined layouts
**Example:** `SAVE_ZMOD_DATA SAVE_MOONRAKER=1`

---

### SHUTDOWN
Power off the printer.
---

### REMOVE_ZMOD

Remove zMod.

- **FULL**: 0 – keep the `/opt/config/mod_data` folder, 1 – delete the `/opt/config/mod_data` folder (0)

The `/opt/config/mod_data` folder stores configurations for `zmod`, `fluidd`, `moonraker`, and `mainsail`.

By default, it is not deleted because users often accidentally run the `REMOVE_ZMOD` macro.

---

### SKIP_ZMOD

Reboot into the original system without launching zMod.

Disables configuration files for ZMOD, Moonraker, and Fluidd.

The following remain active:
- Alternative camera
- SSH

---

### DISPLAY_ON
Enable native screen.

### DISPLAY_OFF
Disable native screen (saves RAM).

---

### MEM
Show memory usage.

### TEST_EMMC
Test EMMC/USB/SWAP performance.

### CLEAR_EMMC
Clear logs/GCODE.

---

### DATE_GET
Show current time.

### DATE_SET
Set system time.

---

### WEB
Switch between Fluidd and Mainsail.

### SET_TIMEZONE
Configure timezone.

---

### TAR_CONFIG
Backup logs and configs.

### RESTORE_TAR_CONFIG

Restores configuration files from the `config.tar` archive

The archive must be loaded in 'Configuration' -> 'mod_data' -> `config.tar`

---

### ZFLASH
Update ZMOD via USB.

---

### STOP_ZMOD
Stop Moonraker/Fluidd.

### START_ZMOD
Start Moonraker/Fluidd.

---

### CHECK_MD5
Validate file checksums.

### UPDATE_MCU
Update MCU firmware.

### CHECK_SYSTEM
Verify OS file integrity.

---

### ZSSH_ON
Enable SSH server.
- **SSH_SERVER**: SSH server IP.
- **SSH_PORT**: SSH port.
- **SSH_USER**: SSH username.
- **VIDEO_PORT**: Camera port.
- **MOON_PORT**: Moonraker port.

### ZSSH_OFF
Disable SSH server.

### ZSSH_RESTART
Restart SSH server.

### ZSSH_RELOAD
Reload SSH configuration.

---
#### SSH Keys
Add your SSH public key to `authorized_keys` on the printer.

#### Start ZSSH
Run `ZSSH_ON` on the printer.

### SHUTDOWN
Power off the printer.

### REMOVE_ZMOD
Uninstall ZMOD.
- `FULL=0`: Keep `/opt/config/mod_data` (default).
- `FULL=1`: Delete all configs.

### SKIP_ZMOD
Reboot into stock firmware (disables ZMOD services).

### DISPLAY_ON
Enable native screen and reboot.

### DISPLAY_OFF
Disable native screen to save RAM.
- `GUPPY=0`: Disable GuppyScreen.
- `GUPPY=1`: Enable GuppyScreen (default).

### MEM
Show memory usage.

### TEST_EMMC
Test storage performance.
- `SIZE`: Data size in MB (100).
- `SYNC`: Sync mode (1 = enabled).
- `FLASH`: Test target (`0`=EMMC, `1`=USB, `2`=RAM).
- `RANDOM`: Use random data (`0`=off).

### CLEAR_EMMC
Clear logs/files.
- `LOG=1`: Clear logs (default).
- `ANY=1`: Clear all non-log files.

### DATE_GET
Show current time.

### DATE_SET
Set system time (format: `YYYY.MM.DD-HH:MM:SS`).
**Example:** `DATE_SET DT=2024.01.01-00:00:00`

### WEB
Switch between Fluidd and Mainsail.

### SET_TIMEZONE
Set timezone.
**Example:** `SET_TIMEZONE ZONE=Asia/Yekaterinburg`

### TAR_CONFIG
Backup configs to `mod_data/config.tar`.

### ZFLASH
Update ZMOD via USB.

### STOP_ZMOD
Stop Moonraker/Fluidd services.

### START_ZMOD
Restart Moonraker/Fluidd.

### CHECK_MD5
Validate G-code MD5 checksums.
- `DELETE=yes`: Delete corrupted files.

### UPDATE_MCU
**Experimental** - Update MCU firmware (Klipper v12).

### CHECK_SYSTEM
Verify OS file integrity.
- `RESTORE=1`: Auto-repair files.

### ZSSH_ON
Enable SSH tunneling to remote server.
- `SSH_SERVER`: Server IP/hostname.
- `SSH_PORT`: SSH port (22).
- `SSH_USER`: Remote username.
- `VIDEO_PORT`: Camera port (8080).
- `MOON_PORT`: Moonraker port (7125).
- `REMOTE_RUN`: Command to execute on server (e.g., `./ff5m.sh bot1`).

### ZSSH_OFF
Disable SSH tunneling.

### ZSSH_RESTART
Restart SSH tunnel.

### ZSSH_RELOAD
Reload SSH config (called automatically during prints).

---

## Telegram Bot
### Description
Due to the printer's limited hardware resources (slow CPU and low RAM), running moonraker-telegram-bot directly on the printer is impractical. Instead, the bot is deployed on an external server.

**Requirements:**
- A server (physical/virtual) accessible via SSH from the printer.

**Automatic SSH Key Generation:**
ZMOD automatically creates SSH keys for passwordless authentication:
- Public key: `/mod_data/ssh.pub.txt` → Add to server's `~/.ssh/authorized_keys`.
- Private key: `/mod_data/ssh.key` → Used by the printer for SSH connections.

**Setup via Macro:**
Use the [ZSSH_ON](https://github.com/ghzserg/zmod/wiki/Macros_en_old#zssh_on) macro with these parameters:
- `SSH_SERVER`: Server IP/hostname.
- `SSH_PORT`: SSH port (usually 22).
- `SSH_USER`: Server username.
- `VIDEO_PORT`: Camera stream port (default: 8080).
- `MOON_PORT`: Moonraker API port (default: 7125).
- `REMOTE_RUN`: Command to execute on the server (e.g., `./ff5m.sh bot1`).

**Note:** SSH consumes ~300KB of memory. If the printer and server are on the same LAN, SSH tunneling is optional. Configure directly via [telegram.conf](https://github.com/ghzserg/zmod_ff5m/blob/1.6/telegram/telegram.conf) (located in `mod/telegram/` on the printer).

---

### Bot Registration
1. Visit [@BotFather](https://t.me/BotFather) on Telegram.
2. Send `/newbot`.
3. Choose a display name (e.g., "My Printer Bot").
4. Choose a bot username ending with `_bot` (e.g., `ff5msuper_bot`).
5. Copy the provided `bot_token` for server configuration.

---

### Server Deployment
#### One-Command Install (Debian)
Run as `root`:
```bash
bash <(wget --cache=off -qO- https://github.com/ghzserg/zmod_ff5m/raw/1.5/telegram/telegram.sh)
```
**Script Actions:**
1. Installs Docker.
2. Downloads `docker-compose.yml` and `telegram.conf`
3. Creates `tbot` user.
4. Guides through bot setup (requires `bot_token` and `chat_id`).
5. Installs [ff5m.sh](https://github.com/ghzserg/zmod_ff5m/blob/1.6/telegram/ff5m.sh).

*Manually add the SSH public key from `mod_data/ssh.pub.txt` to the server.*

#### Manual Setup
1. Install Docker:
   ```bash
   apt update && apt install docker.io docker-compose apparmor -y
   ```
2. Create bot directory:
   ```bash
   mkdir bot1 && cd bot1
   ```
3. Add [docker-compose.yml](https://github.com/ghzserg/zmod_ff5m/blob/1.6/telegram/docker-compose.yml) and [telegram.conf](https://github.com/ghzserg/zmod_ff5m/blob/1.6/telegram/telegram.conf).
4. Configure `telegram.conf` with your `bot_token` and `chat_id`.
5. Start the bot:
   ```bash
   docker-compose up -d
   ```
6. Create a dedicated user:
   ```bash
   useradd tbot && usermod -aG docker tbot
   ```

#### SSH Key Configuration
1. Switch to `tbot` user:
   ```bash
   su - tbot
   ```
2. Add public key:
   ```bash
   mkdir -p .ssh
   echo "PASTE_PUBLIC_KEY_HERE" > .ssh/authorized_keys
   ```

---

### Printer Configuration
Run the [ZSSH_ON](https://github.com/ghzserg/zmod/wiki/Macros_en_old#zssh_on) macro on the printer with your server details. SSH tunnels automatically restart 3 minutes after reboots.

**Example:**
```
ZSSH_ON SSH_SERVER=192.168.1.100 SSH_USER=tbot VIDEO_PORT=8080 MOON_PORT=7125 REMOTE_RUN="./ff5m.sh bot1"
```
