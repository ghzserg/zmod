<h1 align="center">Calibrations</h1>

A macro is a small program written in Klipper/Gcode language.

It can be called from:

- A GCODE file
- The Fluidd/Mainsail console (press the English letter `C` in Fluidd)

!!! note
    *The value in parentheses is the default value*

---

!!! tip
    [Printer Calibration for Beginners](/SetupCalibrations/#printer-calibration-for-beginners)

---

### BED_LEVEL_SCREWS_TUNE

Bed screw leveling calibration ([guide](https://www.klipper3d.org/Manual_Level.html#adjusting-bed-leveling-screws-using-the-bed-probe)).
Parameters:

- `EXTRUDER_TEMP` — extruder temperature (default: `240`)
- `BED_TEMP` — bed temperature (default: `80`)

Measures the distance between the nozzle and bed screws, provides adjustment instructions, saves temperatures to avoid reheating, and waits for user confirmation. Users must manually reset temperatures after completion.

---
### LOAD_CELL_TARE

Reset load cell weight. Used during bed calibration.

---
### PID_TUNE_BED

Bed PID calibration.

- `TEMPERATURE` — bed temperature (default: `80`)

Automatically calls `SAVE_CONFIG` after calibration. See also [NEW_SAVE_CONFIG](/Main/#new_save_config).

To disable auto-save, use:
```gcode
PID_CALIBRATE HEATER=heater_bed TARGET={temperature}
```

---
### PID_TUNE_EXTRUDER

Extruder PID calibration.
Parameters:

- `TEMPERATURE` — extruder temperature (default: `245`)
- `COOLER` — fan speed (0-100, default: `100`)

Calibrate PID at your printing temperature and cooling settings.
Automatically calls `SAVE_CONFIG` after calibration.

To disable auto-save, use:
```gcode
PID_CALIBRATE HEATER=extruder TARGET={temperature}
```

---
### ZSHAPER

Input shaper calibration.
Results are stored in:

- `calibration_data_x.png`
- `calibration_data_y.png`
- CSV files

Read [fix_scv](/Global/#fix_scv)

[Graph visualization tool](https://github.com/theycallmek/Klipper-Input-Shaping-Assistant/releases).

---
### BELTS_SHAPER_CALIBRATION

CoreXY belt frequency analysis using a half-axis test.

- `SPECTROGRAM` — `0` = disable spectrogram, `1` = enable (default: `1`)

**Requirements:**

- 256 MB RAM
- Enabled SWAP

---
### KAMP

Adaptive bed mesh calibration with nozzle cleaning.
Parameters:

- `EXTRUDER_TEMP` — extruder temperature (default: `240`)
- `BED_TEMP` — bed temperature (default: `80`)

**Usage in Orca:**
Add as the first line:
```gcode
KAMP EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
```

**Recommended:** Use [START_PRINT](/Main/#start_print) with `SAVE_ZMOD_DATA PRINT_LEVELING=1 USE_KAMP=1` and `SAVE_ZMOD_DATA CLEAR=LINE_PURGE` to utilize purge areas.

[Bed leveling options](/FAQ/#what-options-are-available-for-bed-leveling)

---
### AUTO_FULL_BED_LEVEL

Full bed leveling with nozzle cleaning.
Parameters:

- `EXTRUDER_TEMP` — extruder temperature (default: `230`)
- `BED_TEMP` — bed temperature (default: `80`)
- `PROFILE` — mesh profile name (default: `auto`)

**Usage in Orca:**
```gcode
AUTO_FULL_BED_LEVEL EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single]
M104 S[nozzle_temperature_initial_layer]
```

**Recommended:** Use [START_PRINT](/Main/#start_print) with `SAVE_ZMOD_DATA PRINT_LEVELING=1`.

[Bed leveling options](/FAQ/#what-options-are-available-for-bed-leveling)

---

### LOAD_ZOFFSET_NATIVE 

Move the z-offset from the native screen to screenless mode

[How Z-Offset Works on Your Printer](/SetupCalibrations/#how-z-offset-works-on-your-printer)
