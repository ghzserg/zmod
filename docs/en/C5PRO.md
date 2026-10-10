# Creator5 Pro

## Important features

- The printer always works with **4 colors** (T0, T1, T2, T3). All four slots are available in the selection menu.
- To turn on the camera, use `CAMERA_ON VIDEO=video67`.
- Klipper may crash. Solution: `Process Profile` -> `Other` -> `Output G-code` -> `Exclude models` — uncheck the checkbox.
- Instead of the `CLOSE_DILALOGS` macro (slow closing), always use `FAST_CLOSE_DILAOGS` (fast closing).
- The `NEW_SAVE_CONFIG` macro does not work.
- No support for Klipper 13

---

## How to prepare a file in Orca

- [Send files to print via Octo/Klipper.](/Recommendations/#send-files-to-print-via-octoklipper)
- [Orca Slicer Profiles](https://github.com/ghzserg/zmod_preprocess/tree/main/profiles/Creator_5)
- [It is strongly recommended to enable the preprocessor](/Global/#force_md5)

---
## COLOR
## How to use the color and filament type selection menu

<img width="794" height="900" alt="image" src="https://github.com/user-attachments/assets/e5a72e1c-5274-449d-8a47-1d3f5b649550" />

<img width="554" height="502" alt="{7A4A77A2-1F88-4110-9502-24FA941B9A67}" src="https://github.com/user-attachments/assets/fd77a89c-08d6-4da5-8eac-3017ca563657" />

Select the spool you want to work with (for example, spool 2):

<img width="559" height="466" alt="{355F6AEF-00B2-4EFE-841E-23516CAC64FA}" src="https://github.com/user-attachments/assets/81084141-88b8-4d65-b583-495796f0d4fa" />

You can perform four actions:

- Change the spool color.
- Change the plastic type (PLA, PETG, ABS, ...).
- Pick up this extruder onto the carriage.
- Load new filament into the extruder.

**How to change color:**

Click "Change color". Select a color from the list. This way the printer and the native screen will understand you best.

<img width="844" height="431" alt="{A27DB9D5-1C03-43D0-AF0D-5D2E16E6FFE4}" src="https://github.com/user-attachments/assets/d9a0ab97-3f78-4b51-b1a4-c4c2c4dc2b68" />

After selection you will return back, and the spool color in the list should change.

If the color did not change: close the window with the X and run the `COLOR` macro again. Sometimes the screen does not have time to refresh.

**How to change type:**
Click "Change type". Select a type from the list.

<img width="848" height="511" alt="{95B6566B-4FC0-4811-BC6A-E65B79E3DED7}" src="https://github.com/user-attachments/assets/f4359f48-c998-4e52-a119-e088b38f0a26" />

If the type did not change: close the window with the X and run the `COLOR` macro again. Sometimes the screen does not have time to refresh.

**Tip:** If several spools have the same color and type, the printer will automatically switch to the next spool when the first one runs out. This is called "endless spool mode".

---

## PRINT
## Print menu

This window opens automatically when you start printing, if the `SAVE_ZMOD_DATA SILENT=0` parameter is set by default.

<img width="851" height="582" alt="{8C3C174F-A553-405C-8228-7BC8EB293094}" src="https://github.com/user-attachments/assets/d8089f7d-fcf5-4a47-b664-a27db8b7e9d8" />

**How to understand what is written here:**

- In the left column are tool numbers and colors from the file passed from the slicer.
- In the right column are spool numbers and colors loaded/used on the printer.
- `Cube.gcode` – this is the name of the file being printed.
- `1: PETG ->` – this is the first color from the file (orange PETG). It is printed with filament from spool 3 (orange PETG).
- `2: PLA ->` – this is the second color (gray PLA). It is printed with filament from spool 4 (blue PLA). Because there are no other PLA plastics in the printer.
- `3: PETG ->` – the third color (black PETG), printed from spool 3 (orange PETG). Because there are no other PETG plastics in the printer.
- `4: PETG-CF ->` – the fourth color (blue PETG-CF), printed from spool 1 (black PETG-CF). Because there are no other PETG-CF plastics in the printer.

If the image looks like this

<img width="837" height="571" alt="{013853B5-7E63-4AA0-9C1E-2243920F9FAD}" src="https://github.com/user-attachments/assets/a1bdc9e5-314d-4e69-9a73-5010faf4b233" />

This means that you have disabled the auto color matching option and/or file scanning. You can click the `AUTO_SELECT_COLORS` button or enable it in global parameters:
```
SAVE_ZMOD_DATA SCAN_FILE_COLORS=1 AUTO_ASSIGN_COLORS=1
```

[It is strongly recommended to enable the preprocessor](/Global/#force_md5)

---

### Bed mesh building and AUTO PA

There are two important buttons in the print menu:

**Leveling (Bed mesh):**

- `Probe bed mesh` — before printing, automatic bed mesh building will be performed.
- `Do not probe bed mesh` — the previously saved mesh will be used.

**Auto PA (Automatic Pressure Advance selection):**

- If the `Auto PA` button is active (green), then **before printing** the printer will automatically select the optimal Pressure Advance value for each used extruder.
- The process takes several minutes, but significantly improves the quality of corners and thin elements.
- If `Auto PA` is off, the PA values from the slicer will be used.

Automatic calibration ranges from 0.01 to 0.04 and is useless for viscous plastics such as PETG

---

## Fine tuning

First you need to turn off the native printer screen using the `DISPLAY_OFF` macro.

**How to find these settings:**

1. Click the "Configuration" tab.
2. Find and open the `mod_data` folder.
3. In this folder, find and open the `filament.json` file.

<img width="480" height="826" alt="{F5EAE8D4-1A9F-4E6C-99A1-B609A331E82D}" src="https://github.com/user-attachments/assets/4b7b5f91-b3ff-4c75-824d-4ec06e2ac6de" />

In this file, for each plastic type (PLA, ABS, PETG, etc.) there is a list of numbers. Here is what they mean:

| Parameter | Default | Description |
|---|---|---|
| `temp` | 220 | Temperature to which the nozzle is heated to change filament. The value depends on the material type |
| `temp_manual` | 250 | Purge temperature in manual mode (when loading through the menu). |
| `temp_wait` | 120 | Idle temperature — the nozzle cools down to it after purging. |
| `filament_drop_length` | 50 | **Drop length.** How many millimeters of plastic the printer will extrude into the trash bin to clean the nozzle from the old color. |
| `filament_full_length` | 600 | **Tube length.** How many millimeters of plastic the printer will extrude after the filament runout sensor triggers |
| `filament_tube_length` | 295 | Filament loading length when inserting a new spool. |

**Default temperatures for different materials:**

| Material | `temp` | `temp_manual` | `temp_wait` |
|---|---|---|---|
| PLA | 220 | 250 | 120 |
| PETG | 240 | 270 | 140 |
| PLA-CF | 220 | 250 | 120 |
| PETG-CF | 240 | 270 | 140 |
| ABS | 250 | 280 | 150 |
| ASA | 250 | 280 | 150 |
| SILK | 220 | 250 | 120 |
| PET-CF | 270 | 300 | 170 |
| S-PAHT | 280 | 310 | 180 |
| S-MULTI | 270 | 300 | 170 |
| PA-CF | 270 | 300 | 170 |
| HIPS | 250 | 280 | 150 |
| PVA | 220 | 250 | 120 |
| TPU-90A | 220 | 250 | 120 |
| TPU-95A | 220 | 250 | 120 |
| TPU-64D | 220 | 250 | 120 |

### Advanced parameters

| Parameter | Default | Description |
|---|---|---|
| `trash_x` | 275.0 | X coordinate of the trash bin. |
| `trash_y` | 254.0 | Y coordinate of the trash bin. |
| `trash_z` | 10.0 | Z coordinate of the trash bin. |
| `wiper_x` | 266.50 | X coordinate of the nozzle cleaning place (rubber). |
| `wiper_y` | 13.80 | Y coordinate of the nozzle cleaning place. |
| `wiper_z` | 1.0 | Z coordinate of the nozzle cleaning place. |
| `fan_speed` | 255.0 | Fan speed (from 0 to 255) when cooling the nozzle after purging. |

> **Warning!** Changing parameters in the advanced section may lead to incorrect printer operation, filament jams or breakdowns. Change them only if you fully understand what each parameter is responsible for and what the consequences may be.

---

## Global parameters

To prevent the color selection window from showing at the start of printing, use the global parameter
**SILENT**:
- `0` — show the window (default)
- `1` — do not show the window, use previously set colors
- `2` — do not show the window, on auto-matching failure show the selection menu
```
SAVE_ZMOD_DATA SILENT=1
```

---

To enable scanning of gcode files for information about tools, colors and materials, use the parameter
**SCAN_FILE_COLORS**.
```
SAVE_ZMOD_DATA SCAN_FILE_COLORS=1
```
You can also set the value:
- `0` — disable the parameter
- `1` — full scan of the Gcode file
- `2` — check only the data prepared by the slicer script, without scanning the entire file
**!If file scanning is disabled**, the printer does not know how many extruders are used, so **Auto PA will be run for all spools**

---

To enable **automatic color matching** from the gcode file with physical spools, use the parameter
**AUTO_ASSIGN_COLORS**. For this function to work, file scanning must be enabled.
```
SAVE_ZMOD_DATA AUTO_ASSIGN_COLORS=30
```
You can configure your own values for pausing printing in silent mode by adding the following numbers:
- `1` — printing continues even if auto color assignment failed
- `2` — At least one material does not match (for example, gcode says ABS, but you only have PLA loaded)
- `4` — At least one color does not match at all (usually because file scanning is disabled)
- `8` — At least one color matches poorly
- `16` — The same physical spool was assigned to more than one tool index in the file
For example, using the value `30` will pause printing in silent mode if any problems with automatic assignment occur, and `AUTO_ASSIGN_COLORS=10` (2+8) will pause printing if at least one material does not match + at least one color matches poorly.

---

To automatically turn off heating of unused extruders during multi-color printing, use the parameter **unused_extruders_off_time**. It sets the timeout (in minutes) after which an idle tool will be turned off to avoid filament degradation and idle operation.

```
SAVE_ZMOD_DATA unused_extruders_off_time=5
```

You can set the following values (in minutes):
* `0` — function disabled (extruders do not turn off during idle)
* `5`, `10`, `20`, `40`, `60` — time after which the unused extruder will be turned off

**Important:** For this option to work correctly, **Ooze prevention** must be enabled in the slicer. Without it, the printer cannot correctly handle the temperature modes of idle hotends during filament change.

<img width="375" height="143" alt="{2CA02C09-7658-478E-A2A3-F7A9E9A077F2}" src="https://github.com/user-attachments/assets/6340a479-62a8-4476-93f1-c4054a279618" />

---

## Change the number of attempts to pick up or put back the tool

You need to add to `mod_data/user.cfg`:

```
[zmod_color]
retry: 3
```

Default is 5.

---

## Add your own filament types

For these settings to work, you need to turn off the native printer screen using the `DISPLAY_OFF` macro.

To add a new filament type, add to `mod_data/user.cfg`:

```
[zmod_color]
filament_NEWTYPE: 300
```

Where `NEWTYPE` is replaced with the desired filament type (for example `HIPS`), and the number is the extruder temperature for loading, unloading and purging this filament. Based on this value, `temp_manual` (+30) and `temp_wait` (−100) will be automatically calculated.

To hide a filament type, add to `mod_data/user.cfg`:

```
[zmod_color]
hide_filament_types: XXX,YYY,ZZZ
```

Where `XXX`, `YYY`, `ZZZ` are replaced with the desired filament types (for example `PLA-CF,PETG-CF,SILK`). This can be used to hide default types or types you added manually. The filament type is not disabled, only hidden in the type selection menu.

---

## Add your own colors

For these settings to work, you need to turn off the native printer screen using the `DISPLAY_OFF` macro.

To add or rename a color, open `mod_data/color/ru.json` (use your language instead of `ru`) and add a new color or rename an existing one.

For the color name to be displayed, the color name must start with an underscore `_`.

**Example:**
```json
{
   "ffffff": "white",
   "fffff1": "_transparent",
   "fef043": "bright yellow",
   "dcf478": "light green",
   "0acc38": "green",
   "067749": "dark green",
   "0c6283": "blue-green",
   "0de2a0": "turquoise",
   "75d9f3": "light blue",
   "45a8f9": "blue",
   "2750e0": "dark blue",
   "46328e": "purple",
   "a03cf7": "bright purple",
   "f330f9": "magenta",
   "d4b0dc": "lilac",
   "f95d73": "pink",
   "f72224": "red",
   "7c4b00": "brown",
   "f98d33": "orange",
   "fdebd5": "beige",
   "d3c4a3": "light brown",
   "af7836": "terracotta",
   "898989": "gray",
   "bcbcbc": "light gray",
   "161616": "black"
}
```

The label `_transparent` will be displayed on the buttons.

---

## Extruder calibration

Extruder calibration allows the printer to know the exact position of each of the four nozzles relative to each other. This is necessary for high-quality multi-color printing.

**When to calibrate:**
- After replacing or repairing an extruder.
- If you notice that colors do not align on the model (offset in X, Y or Z).

**How to run:**

1. **Remove the build plate** from the bed!
2. Run the `CALIBRATE_EXTRUDERS` macro from the menu or enter in the console:
   ```
   CALIBRATE_EXTRUDERS
   ```
3. A confirmation window will appear. Click `OK`.

**What will happen:**

- The printer will perform (G28).
- Heat the bed to 65°C.
- Take each of the 4 extruders (T0–T3) in turn.
- For each extruder: heat the nozzle, perform a purge, clean against the rubber, then use sensors to determine the exact X, Y and Z coordinates.
- The results are automatically written to `rw/extruder.json`.
- At the end, the printer will output the found offsets for each extruder to the console.

**Additional parameters** (for advanced):

| Parameter | Default | Description |
|---|---|---|
| `BED_TEMP` | 65.0 | Bed temperature during calibration |
| `SEARCH` | 14.0 | Sensor search radius (mm) |
| `HOVER` | 0.6 | Hover height above the point |
| `SAFE_Z` | 10.0 | Safe Z height |

**Example with parameters:**

```
CALIBRATE_EXTRUDERS BED_TEMP=70 SEARCH=12
```

> **Warning!** Do not interrupt calibration. The process takes several minutes.

---

## VFA calibration

VFA (Vertical Fine Artifacts) calibration allows reducing vertical artifacts on the print surface caused by stepper motor resonances.

**How to run:**

Enter in the console:
```
CALIBRATE_VFA T=0
```

Where `T=0` is the extruder number (0–3) that will be used during calibration.

**What will happen:**

- The printer will take the specified extruder.
- Reset all G-code offsets.
- Move the head to the bed center (X130 Y130).
- Run automatic resonance calibration (`STEPPER_RESONANCE_FACTORY_CALIBRATE`).
- Return the extruder to its place.
- Save the configuration (`SAVE_CONFIG`).

> **Tip:** It is recommended to perform VFA calibration when visible vertical stripes appear on the print surface.

---

## `T_INFO` macro

The `T_INFO` macro shows the current state of all extruders and printer sensors.

**How to run:**
```
T_INFO
```

**What will be output to the console:**

```
// T0: home
// T1: HEAD
// T2: home
// T3: home
// Door: Close
// Top: Close
// Offset: X=0.000 Y=0.000 Z=0.061 (0.000)
```

**How to read:**

- `home` — the extruder is in its place (in the parking pocket).
- `HEAD` — the extruder is installed on the print head.
- `?` — undefined state (sensors did not trigger).
- `ERROR (both)` — error: the extruder is both home and on the head (sensor desync).
- `Door` — front door state (`Close` / `Open`).
- `Top` — top cover state (`Close` / `Open`).
- `Offset` — current G-code offsets along the X, Y, Z axes.

---

## Ventilation modes

Creator5 Pro is equipped with a chamber ventilation system with several fans. Proper ventilation control is critically important for the print quality of different materials.

**External intake (PLA, TPU):**

The `AIR_CIRCULATION_EXTERNAL` macro turns on chamber exhaust and fresh air supply. It is needed for PLA and TPU so the plastic cools quickly and does not soften from chamber heat.
```
AIR_CIRCULATION_EXTERNAL
```
| Fan | Speed |
|---|---|
| `chamber_fan` (exhaust) | 0.5 |
| `chamber_cool_fan` (cooling) | 0.7 |
| `chamber_heat_fan` (heating) | 0.0 |
| `chamber_loop_fan` (circulation) | 0.0 |

**Internal circulation (ABS, ASA):**

The `AIR_CIRCULATION_INTERNAL` macro turns on internal circulation and chamber heating. It is needed for ABS and ASA to avoid delamination and warping from temperature changes.
```
AIR_CIRCULATION_INTERNAL
```
| Fan | Speed |
|---|---|
| `chamber_fan` (exhaust) | 0.0 |
| `chamber_cool_fan` (cooling) | 0.0 |
| `chamber_heat_fan` (heating) | 0.9 |
| `chamber_loop_fan` (circulation) | 0.3 |

**Stopping ventilation:**
The `AIR_CIRCULATION_STOP` macro completely turns off all chamber fans.
```
AIR_CIRCULATION_STOP
```

### Where to add ventilation macros

> **Recommendation:** It is best to add ventilation macro calls to the **filament code** in the slicer. This will ensure automatic mode switching when the material changes.

**In OrcaSlicer:**

1. Open filament settings.
2. Go to the "Filament Settings" tab.
3. In the **Filament start G-code** field, add the needed macro:
   - For PLA: `AIR_CIRCULATION_EXTERNAL`
   - For ABS: `AIR_CIRCULATION_INTERNAL`
   - For TPU: `AIR_CIRCULATION_EXTERNAL`

**Example for PLA:**
```
; Filament start gcode
AIR_CIRCULATION_EXTERNAL
```

**Example for ABS:**
```
; Filament start gcode
AIR_CIRCULATION_INTERNAL
```

Thus, during multi-color printing with different materials, ventilation will automatically switch to the required mode for each extruder.

---

## Print acceleration

Add to 'mod_data/user.cfg'

```
[printer]
short_move_limit: False
short_extrude_move_limit: False
```

This setting significantly speeds up printing, but can cause printer crashes when printing with fuzzy skin.

---

## Disabling fast head return and preheating

Add to 'mod_data/user.cfg'

```
[virtual_sdcard]
enable_speed_return: False
enable_preheat: False
```

- **enable_speed_return**: False — Disables forced return of the head to the model at 600 mm/s, removing the risk of strong kinematic impacts and breaking the hotend against printed parts (prime tower). Safe return trajectory control is fully passed to OrcaSlicer.
- **enable_preheat**: False — Disables background scanning of Klipper files, unloading the CPU. The built-in function accelerated heating when using more than two nozzles in a short period, since the printer cannot heat more than two nozzles simultaneously. Predictive heating is calculated more accurately on the OrcaSlicer side.

---

## Disabling the open door notification

To remove notifications about an open cover or door in mode without the native screen

Add to 'mod_data/user.cfg'

```
[gcode_button topDoor]
press_gcode:
release_gcode:

[gcode_button frontDoor]
press_gcode:
release_gcode:
```
