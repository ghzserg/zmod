<h1 align="center">Main</h1>

A macro is a small program written in Klipper/Gcode language.

It can be called from:

- A GCODE file
- The Fluidd/Mainsail console (press the English letter `C` in Fluidd)

!!! note
    *The value in parentheses is the default value*

---

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

- Any calibration (e.g., `FORCE_KAMP`/`FORCE_LEVELING`) triggers [CLEAR_NOZZLE](/Global/#clear_nozzle).
- `[ZSSH_RELOAD](/Zmod/#zssh_reload)` is called during `START_PRINT` to restore SSH if needed.

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

[Bed leveling options](/FAQ/#what-options-are-available-for-bed-leveling)

---

#### Global flags (set via [`SAVE_ZMOD_DATA`](/Global/#start_print)):

- `PRECLEAR` — pre-nozzle cleaning in `CLEAR_NOZZLE`: `0` = disable, `1` = enable (default: `0`).
- `CLEAR` — nozzle cleaning method (`LINE_PURGE`).
- `PRINT_LEVELING` — enable bed leveling for every print: `0` = disable, `1` = enable (default: `0`).
- `USE_KAMP` — use adaptive bed mesh (KAMP) where possible: `0` = disable, `1` = enable (default: `0`).
- `DISABLE_PRIMING` — disable nozzle priming: `0` = enable, `1` = disable (default: `0`).
- `FORCE_MD5` — verify file MD5 hashes (default: `1`).
    1. Select and download the file for your architecture and operating system:

    - [zmod_preprocess-windows-amd64.exe](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-windows-amd64.exe) - Windows
    - [zmod_preprocess-linux-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-linux-amd64) - Linux. Don't forget to chmod +x zmod_preprocess-linux-amd64
    - [zmod_preprocess-darwin-arm64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-arm64) - MacOS (Intel). Don't forget to run ```chmod +x zmod_preprocess-darwin-arm64```
    - [zmod_preprocess-darwin-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-amd64) - MacOS Silicon. Don't forget to run ```chmod +x zmod_preprocess-darwin-amd64```
    - [zmod-preprocess.py](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.py) - General-Python. Don't forget to run ```chmod +x zmod-preprocess.py```
    - [zmod-preprocess.sh](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.sh) - Linux/MacOS Bash. Don't forget to run ```chmod +x zmod-preprocess.sh```
    
    2. In Orca, you need to specify: `Process Profile` -> `Other` -> `Post Processing Scripts`.
    
    Here are the options for adding:
    
    - ```"С:\path_to_file\zmod_preprocess-windows-amd64.exe";```
    - ```"C:\python_folder\python.exe" "C:\Scripts\zmod-preprocess.py";```
    - ```"/usr/bin/python3" "/home/user/zmod-preprocess.py";```
    - ```"/home/user/zmod-preprocess.py";```
    - ```"/home/user/zmod_preprocess-darwin-amd64";```
    - ```"/home/user/zmod_preprocess-darwin-arm64";```
    - ```"/home/user/zmod_preprocess-linux-amd64";```

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

---
### END_PRINT

Replaces the default end G-code.

#### Global flags (set via [`SAVE_ZMOD_DATA`](/Global/#end_print)):

- `AUTO_REBOOT` — auto-reboot after print (same as above).
- `CLOSE_DIALOGS` — auto-close dialogs (same as above).
- `STOP_MOTOR` — disable motors after print (same as above).
- `MIDI_END` — MIDI file to play on print end.

---
### _USER_START_PRINT

Custom macro for user-defined actions at the start of printing.

This macro is automatically called at the end of the `START_PRINT` macro. Use it to extend the standard print initialization process with custom commands.

**Common use cases:**

- Add custom heating or calibration commands
- Perform additional setup before printing starts
- Enable/disable devices (fans, sensors, etc.)
- Add custom nozzle cleaning or other preparation

**Example override in `mod_data/user.cfg`:**
```gcode
[gcode_macro _USER_START_PRINT]
gcode:
    # Enable additional fan
    SET_PIN PIN=my_fan VALUE=1
    # Some custom command
    G4 P1000  ; pause for 1 second
    # Other custom actions
```

**Note:** By default, this macro is empty and can be overridden by the user according to their needs.

---
### _USER_END_PRINT

Custom macro for user-defined actions at the end of printing.

This macro is automatically called at the end of the `END_PRINT` macro. Use it to extend the standard print completion process with custom commands.

**Common use cases:**

- Perform additional actions after printing completes
- Disable additional devices
- Save statistics or logs
- Run custom cleaning or maintenance routines

**Example override in `mod_data/user.cfg`:**
```gcode
[gcode_macro _USER_END_PRINT]
gcode:
    # Disable additional fan
    SET_PIN PIN=my_fan VALUE=0
    # Send notification
    M118 Print completed!
    # Or other custom commands
```

**Note:** By default, this macro is empty and can be overridden by the user according to their needs.

---
### CANCEL

Cancel the current print.

---
### CLEAR_NOZZLE

Nozzle cleaning (as in stock firmware).
Parameters:

- `EXTRUDER_TEMP` — extruder temperature (default: `230`)
- `BED_TEMP` — bed temperature (default: `80`)

*`PRECLEAR` (set via `SAVE_ZMOD_DATA PRECLEAR=1`) enables pre-cleaning. [Learn more](/Global/#save_zmod_data).*

---
### LED_ON

Turn on LED lighting.

---
### LED_OFF

Turn off LED lighting.

---
### LED

Set LED brightness.

- `S` — brightness percentage (default: `50`).

---
### PAUSE

Pause the print.

---
### RESUME

Resume the print after pausing.

---
### PLAY_MIDI

Play a MIDI file.

- `FILE` — filename (default: `For_Elise.mid`). Files are stored in `mod_data/midi/`.

---
### REBOOT

Reboot the printer.

---
### CLOSE_DIALOGS

Close dialogs on the native screen (slow method).
*May cause printer freezes.*
Controlled by the [`CLOSE_DIALOGS`](/Global/#close_dialogs) global parameter.

---
### FAST_CLOSE_DIALOGS

Close dialogs quickly (recommended).
*Enable "Local Network Only" in printer settings: **Settings → WiFi icon → Network Mode → Toggle "Local Network Only"**.*
Controlled by the [`CLOSE_DIALOGS`](/Global/#close_dialogs) global parameter.

---
### NEW_SAVE_CONFIG

Trigger `SAVE_CONFIG` without freezing the native screen.
*May take ~1 minute and occasionally cause screen glitches.*

---
### SHUTDOWN

Power off the printer.
