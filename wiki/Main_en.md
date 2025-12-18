<h1 align="center">Main</h1>

*[Прочитать на русском языке](https://github.com/ghzserg/zmod/wiki/Main_ru)*

A macro is a small program written in Klipper/Gcode language.

It can be called from:
- A GCODE file
- The Fluidd/Mainsail console (press the English letter `C` in Fluidd)

> [!NOTE]
> *The value in parentheses is the default value*

[@zmod_help_bot](http://t.me/zmod_help_bot)

---

<table style="width: 100%; table-layout: fixed;" align="center">
<thead><tr>
  <th colspan="4"><p align="center"><strong>🔷 Core Macros 🔷</strong></p></th>
</tr></thead>
<tbody>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#start_print">START_PRINT</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#end_print">END_PRINT</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#close_dialogs">CLOSE_DIALOGS</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#fast_close_dialogs">FAST_CLOSE_DIALOGS</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#led">LED</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#led_off">LED_OFF</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#led_on">LED_ON</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#play_midi">PLAY_MIDI</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#clear_nozzle">CLEAR_NOZZLE</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#new_save_config">NEW_SAVE_CONFIG</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#cancel">CANCEL</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#pause">PAUSE</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#resume">RESUME</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#reboot">REBOOT</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#shutdown">SHUTDOWN</a></td>
 </tr>
</tbody>
</table>

### START_PRINT

Replaces the default start G-code.
**For printers with a native screen**, add `M140`/`M190 S[bed_temp]` and `M109`/`M104 S[nozzle_temp]`.

Parameters:
- `EXTRUDER_TEMP` — extruder temperature (default: `245`)
- `BED_TEMP` — bed temperature (default: `80`)
- `MESH` — bed mesh profile name (empty = no mesh loaded/created)
- `FORCE_LEVELING` — force bed leveling (default: `False`)
- `SKIP_LEVELING` — skip bed leveling entirely (overrides `FORCE_KAMP`/`FORCE_LEVELING`, default: `False`)
- `FORCE_KAMP` — build an adaptive bed mesh (KAMP, default: `False`).
  *Recommended to add `SAVE_ZMOD_DATA CLEAR=LINE_PURGE` to use purge areas for KAMP.*
- `Z_OFFSET` — set Z offset (default: `0.0`)
- INTERNAL - For the PRO version when operating without the native screen, 1 - enable internal recirculation (0)
- EXTERNAL - For the PRO version when operating without the native screen, 1 - enable external recirculation (0)

**Notes:**
- Any calibration (e.g., `FORCE_KAMP`/`FORCE_LEVELING`) triggers [CLEAR_NOZZLE](https://github.com/ghzserg/zmod/wiki/Global_en#clear_nozzle).
- `[ZSSH_RELOAD](https://github.com/ghzserg/zmod/wiki/Zmod_en#zssh_reload)` is called during `START_PRINT` to restore SSH if needed.

**Example for Orca with native screen:**
Replace the start G-code with:
```gcode
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single]
M104 S[nozzle_temperature_initial_layer]
```

**Example for Orca without native screen:**
```gcode
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
```

**Layer tracking in Fluidd:**
Add to start G-code:
```gcode
SET_PRINT_STATS_INFO TOTAL_LAYER=[total_layer_count]
```
Add to layer change G-code:
```gcode
SET_PRINT_STATS_INFO CURRENT_LAYER={layer_num + 1}
```

[Bed leveling options](https://github.com/ghzserg/zmod/wiki/FAQ_en#what-options-are-available-for-bed-leveling)

---

#### Global flags (set via [`SAVE_ZMOD_DATA`](https://github.com/ghzserg/zmod/wiki/Global_en#start_print)):
- `PRECLEAR` — pre-nozzle cleaning in `CLEAR_NOZZLE`: `0` = disable, `1` = enable (default: `0`).
- `CLEAR` — nozzle cleaning method (`LINE_PURGE`).
- `PRINT_LEVELING` — enable bed leveling for every print: `0` = disable, `1` = enable (default: `0`).
- `USE_KAMP` — use adaptive bed mesh (KAMP) where possible: `0` = disable, `1` = enable (default: `0`).
- `DISABLE_PRIMING` — disable nozzle priming: `0` = enable, `1` = disable (default: `0`).
- `FORCE_MD5` — verify file MD5 hashes (default: `1`).
  *Use [`addMD5.bat`](https://github.com/ghzserg/zmod/releases/download/R/addMD5.bat) or [`addMD5.sh`](https://github.com/ghzserg/zmod/releases/download/R/addMD5.sh) in post-processing scripts.*
- `DISABLE_SKEW` — disable skew correction: `1` = disable, `0` = load `skew_profile` (default: `1`).
- `AUTO_REBOOT` — auto-reboot after print: `0` = disable, `1` = enable, `2` = firmware restart (default: `0`).
- `CLOSE_DIALOGS` — auto-close dialogs: `0` = disable, `1` = slow, `2` = fast (requires enabling "Local Network Only" on the printer screen).
- `STOP_MOTOR` — disable motors after print: `0` = disable, `1` = enable (default: `1`).
- `MIDI_START` — MIDI file to play on print start (e.g., `"start.mid"`).
- `MIDI_END` — MIDI file to play on print end.

---

#### Bed leveling logic:
1. Load mesh from `MESH` if specified.
2. Skip leveling if `SKIP_LEVELING = True`.
3. Build KAMP mesh if `FORCE_KAMP = True`.
4. Build full mesh if no mesh is loaded or `FORCE_LEVELING = True`.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)

</div>

---
### END_PRINT

Replaces the default end G-code.

#### Global flags (set via [`SAVE_ZMOD_DATA`](https://github.com/ghzserg/zmod/wiki/Global_en#end_print)):
- `AUTO_REBOOT` — auto-reboot after print (same as above).
- `CLOSE_DIALOGS` — auto-close dialogs (same as above).
- `STOP_MOTOR` — disable motors after print (same as above).
- `MIDI_END` — MIDI file to play on print end.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)

</div>

---
### CANCEL

Cancel the current print.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)

</div>

---
### CLEAR_NOZZLE

Nozzle cleaning (as in stock firmware).
Parameters:
- `EXTRUDER_TEMP` — extruder temperature (default: `230`)
- `BED_TEMP` — bed temperature (default: `80`)

*`PRECLEAR` (set via `SAVE_ZMOD_DATA PRECLEAR=1`) enables pre-cleaning. [Learn more](https://github.com/ghzserg/zmod/wiki/Global_en#save_zmod_data).*

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)

</div>

---
### LED_ON

Turn on LED lighting.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)

</div>

---
### LED_OFF

Turn off LED lighting.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)

</div>

---
### LED

Set LED brightness.
- `S` — brightness percentage (default: `50`).

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)

</div>

---
### PAUSE

Pause the print.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)

</div>

---
### RESUME

Resume the print after pausing.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)

</div>

---
### PLAY_MIDI

Play a MIDI file.
- `FILE` — filename (default: `For_Elise.mid`). Files are stored in `mod_data/midi/`.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)

</div>

---
### REBOOT

Reboot the printer.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)

</div>

---
### CLOSE_DIALOGS

Close dialogs on the native screen (slow method).
*May cause printer freezes.*
Controlled by the [`CLOSE_DIALOGS`](https://github.com/ghzserg/zmod/wiki/Global_en#close_dialogs) global parameter.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)

</div>

---
### FAST_CLOSE_DIALOGS

Close dialogs quickly (recommended).
*Enable "Local Network Only" in printer settings: **Settings → WiFi icon → Network Mode → Toggle "Local Network Only"**.*
Controlled by the [`CLOSE_DIALOGS`](https://github.com/ghzserg/zmod/wiki/Global_en#close_dialogs) global parameter.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)

</div>

---
### NEW_SAVE_CONFIG

Trigger `SAVE_CONFIG` without freezing the native screen.
*May take ~1 minute and occasionally cause screen glitches.*

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)

</div>

---
### SHUTDOWN

Power off the printer.

---
<div align="center">

[![Back](https://github.com/ghzserg/zmod/wiki/images/Back.svg)](https://github.com/ghzserg/zmod/wiki/Macros)
[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)
[![Forward](https://github.com/ghzserg/zmod/wiki/images/Forward.svg)](https://github.com/ghzserg/zmod/wiki/Calibrations_en)

</div>

