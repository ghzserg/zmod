<h1 align="center">Calibrations</h1>

*[Прочитать на русском языке](https://github.com/ghzserg/zmod/wiki/Calibrations_ru)*

[Printer Calibration for Beginners](https://github.com/ghzserg/zmod/wiki/Setup_en#printer-calibration-for-beginners)

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
  <th colspan="3"><p align="center"><strong>🔷 Calibrations 🔷</strong></p></th>
</tr></thead>
<tbody>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Calibrations_en#pid_tune_bed">PID_TUNE_BED</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Calibrations_en#pid_tune_extruder">PID_TUNE_EXTRUDER</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Calibrations_en#zshaper">ZSHAPER</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Calibrations_en#auto_full_bed_level">AUTO_FULL_BED_LEVEL</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Calibrations_en#kamp">KAMP</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Calibrations_en#load_cell_tare">LOAD_CELL_TARE</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Calibrations_en#belts_shaper_calibration">BELTS_SHAPER_CALIBRATION</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Calibrations_en#bed_level_screws_tune">BED_LEVEL_SCREWS_TUNE</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Calibrations_en#load_zoffset_native">LOAD_ZOFFSET_NATIVE </a></td>
 </tr>
</tbody>
</table>

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#Calibrations)

</div>

---
### BED_LEVEL_SCREWS_TUNE

Bed screw leveling calibration ([guide](https://www.klipper3d.org/Manual_Level.html#adjusting-bed-leveling-screws-using-the-bed-probe)).
Parameters:
- `EXTRUDER_TEMP` — extruder temperature (default: `240`)
- `BED_TEMP` — bed temperature (default: `80`)

Measures the distance between the nozzle and bed screws, provides adjustment instructions, saves temperatures to avoid reheating, and waits for user confirmation. Users must manually reset temperatures after completion.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#Calibrations)

</div>

---
### LOAD_CELL_TARE

Reset load cell weight. Used during bed calibration.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#Calibrations)

</div>

---
### PID_TUNE_BED

Bed PID calibration.
- `TEMPERATURE` — bed temperature (default: `80`)

Automatically calls `SAVE_CONFIG` after calibration. See also [NEW_SAVE_CONFIG](https://github.com/ghzserg/zmod/wiki/Main_en#new_save_config).

To disable auto-save, use:
```gcode
PID_CALIBRATE HEATER=heater_bed TARGET={temperature}
```

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#Calibrations)

</div>

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

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#Calibrations)

</div>

---
### ZSHAPER

Input shaper calibration.
Results are stored in:
- `calibration_data_x.png`
- `calibration_data_y.png`
- CSV files

Read [fix_scv](https://github.com/ghzserg/zmod/wiki/Global_en#fix_scv)

[Graph visualization tool](https://github.com/theycallmek/Klipper-Input-Shaping-Assistant/releases).

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#Calibrations)

</div>

---
### BELTS_SHAPER_CALIBRATION

CoreXY belt frequency analysis using a half-axis test.
- `SPECTROGRAM` — `0` = disable spectrogram, `1` = enable (default: `1`)

**Requirements:**
- 256 MB RAM
- Enabled SWAP

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#Calibrations)

</div>

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

**Recommended:** Use [START_PRINT](https://github.com/ghzserg/zmod/wiki/Main_en#start_print) with `SAVE_ZMOD_DATA PRINT_LEVELING=1 USE_KAMP=1` and `SAVE_ZMOD_DATA CLEAR=LINE_PURGE` to utilize purge areas.

[Bed leveling options](https://github.com/ghzserg/zmod/wiki/FAQ_en#what-options-are-available-for-bed-leveling)

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#Calibrations)

</div>

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

**Recommended:** Use [START_PRINT](https://github.com/ghzserg/zmod/wiki/Main_en#start_print) with `SAVE_ZMOD_DATA PRINT_LEVELING=1`.

[Bed leveling options](https://github.com/ghzserg/zmod/wiki/FAQ_en#what-options-are-available-for-bed-leveling)

---
<div align="center">

[![Back](https://github.com/ghzserg/zmod/wiki/images/Back.svg)](https://github.com/ghzserg/zmod/wiki/Main_en)
[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#Calibrations)
[![Forward](https://github.com/ghzserg/zmod/wiki/images/Forward.svg)](https://github.com/ghzserg/zmod/wiki/Global_en)

</div>

---

### LOAD_ZOFFSET_NATIVE 

Move the z-offset from the native screen to screenless mode

[How Z-Offset Works on Your Printer](https://github.com/ghzserg/zmod/wiki/Setup_en#how-z-offset-works-on-your-printer)


<div align="center">

[![Back](https://github.com/ghzserg/zmod/wiki/images/Back.svg)](https://github.com/ghzserg/zmod/wiki/Main_en)
[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#Calibrations)
[![Forward](https://github.com/ghzserg/zmod/wiki/images/Forward.svg)](https://github.com/ghzserg/zmod/wiki/Global_en)

</div>

---

