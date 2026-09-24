# Creator5 Pro

1. [Important Notes](#important-notes)
2. [How to prepare a file in Orca](#how-to-prepare-a-file-in-orca)
3. [How to use the color selection menu](#how-to-use-the-color-selection-menu)
4. [Print Menu](#print-menu)
5. [Fine-tuning](#fine-tuning)
6. [Global Parameters](#global-parameters)
7. [Add your own filament types](#add-your-own-filament-types)
8. [Add your own colors](#add-your-own-colors)
9. [Extruder Calibration](#extruder-calibration)
10. [VFA Calibration](#vfa-calibration)
11. [`T_INFO` Macro](#t_info-macro)
12. [Ventilation Modes](#ventilation-modes)

---

## Important Notes

- The printer always works with **4 colors** (T0, T1, T2, T3). All four slots are available in the selection menu.
- To enable the camera, you must use `CAMERA_ON VIDEO=video67`.
- Klipper may crash. Solution: `Process Profile` -> `Others` -> `Output G-code` -> Uncheck `Exclude objects`.
- If you are sending a `3mf` file, use only the native screen mode.
- If you are sending a `gcode` file, changing the color order while printing with the native screen is problematic.
- Instead of the `CLOSE_DILALOGS` macro (slow closing), always use `FAST_CLOSE_DILAOGS` (fast closing).
- The `NEW_SAVE_CONFIG` macro does not work.
- No support for Klipper 13.

---

## How to prepare a file in Orca

[Send files to print via Octo/Klipper.](/ru/Recommendations/#send-files-to-print-via-octoklipper)

---
## COLOR
## How to use the color selection menu

<img width="881" height="856" alt="image" src="https://github.com/user-attachments/assets/7acd4ccf-3623-4afe-83bf-fcb96f5a416b" />

<img width="554" height="502" alt="{7A4A77A2-1F88-4110-9502-24FA941B9A67}" src="https://github.com/user-attachments/assets/fd77a89c-08d6-4da5-8eac-3017ca563657" />

Select the spool you want to work with (e.g., spool 2):

<img width="559" height="466" alt="{355F6AEF-00B2-4EFE-841E-23516CAC64FA}" src="https://github.com/user-attachments/assets/81084141-88b8-4d65-b583-495796f0d4fa" />

You can perform four actions:
- Change the spool color.
- Change the plastic type (e.g., from PLA to PETG).
- Place this extruder on the carriage.
- Load a new spool into the extruder.

**How to change the color:**
Click "Change color". Select a color from the list. This is the best way for the printer and the native screen to understand you.

<img width="560" height="834" alt="{55C179BC-DB74-480D-BA6A-DBDF193794B5}" src="https://github.com/user-attachments/assets/32dfabcf-23c6-4ed8-b606-fa1e0fb01e67" />

After selection, you will return to the previous screen, and the spool color in the list should change.

If the color didn't change: close the window with the cross and run the `COLOR` macro again. Sometimes the screen doesn't have time to update.

**How to change the type:**
Click "Change type". Select a type from the list.

<img width="554" height="830" alt="{07CF6B87-8483-4300-B354-554431CCBE54}" src="https://github.com/user-attachments/assets/31445f6c-18b7-4e26-80fb-4f8306b11d57" />

If the type didn't change: close the window with the cross and run the `COLOR` macro again. Sometimes the screen doesn't have time to update.

**Tip:** If you specify the same color and type for multiple spools, the printer will automatically switch to the next spool when the first one runs out. This is called "infinite spool mode".

---

## PRINT
## Print Menu

This window opens automatically when you start printing.

<img width="562" height="593" alt="{A688018F-CB9C-4EFA-9431-AAE9E2DE842E}" src="https://github.com/user-attachments/assets/92cababe-52b1-49aa-aea3-1ad6ddf03cfe" />

**How to understand what is written here:**

`Cube.gcode` is the name of the file being printed.
`1` is the first color from the file. It is printed with filament from spool 2 (orange PETG).
`2` is the second color. It is printed with filament from spool 4 (gray PLA).
`3` is the third color, printed from spool 1 (black PETG).

### Bed Mesh and AUTO PA

There are two important buttons in the print menu:

**Leveling (Bed Mesh):**
- `Generate bed mesh` — automatic bed mesh generation will be performed before printing.
- `Do not generate bed mesh` — a previously saved map will be used.

**Auto PA (Automatic Pressure Advance tuning):**
- If the `Auto PA` button is active (green), **before printing starts**, the printer will automatically select the optimal Pressure Advance value for each used extruder.
- The process takes a few minutes but significantly improves the quality of corners and fine details.
- If `Auto PA` is disabled, PA values from the slicer will be used.

Automatic calibration ranges from 0.01 to 0.04 and is useless for viscous plastics like PETG.

---

## Fine-tuning

First, you need to disable the printer's native screen using the `DISPLAY_OFF` macro.

**How to find these settings:**
1. Click on the "Configuration" tab.
2. Find and open the `mod_data` folder.
3. In this folder, find and open the `filament.json` file.

<img width="480" height="826" alt="{F5EAE8D4-1A9F-4E6C-99A1-B609A331E82D}" src="https://github.com/user-attachments/assets/4b7b5f91-b3ff-4c75-824d-4ec06e2ac6de" />

In this file, for each type of plastic (PLA, ABS, PETG, etc.), there is a list of numbers. Here is what they mean:

| Parameter | Default | Description |
|---|---|---|
| `temp` | 220 | Temperature to which the nozzle is heated for filament change. The value depends on the material type. |
| `temp_manual` | 250 | Purge temperature in manual mode (when loading via the menu). |
| `temp_wait` | 120 | Idle temperature — the temperature the nozzle cools down to after purging. |
| `filament_drop_length` | 50 | **Purge length.** How many millimeters of plastic the printer will extrude into the trash bin to clean the nozzle of the old color. |
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

### Advanced Parameters

| Parameter | Default | Description |
|---|---|---|
| `trash_x` | 275.0 | X coordinate of the trash bin. |
| `trash_y` | 254.0 | Y coordinate of the trash bin. |
| `trash_z` | 10.0 | Z coordinate of the trash bin. |
| `wiper_x` | 266.50 | X coordinate of the nozzle cleaning spot (wiper). |
| `wiper_y` | 13.80 | Y coordinate of the nozzle cleaning spot. |
| `wiper_z` | 1.0 | Z coordinate of the nozzle cleaning spot. |
| `fan_speed` | 255.0 | Fan speed (from 0 to 255) when cooling the nozzle after purging. |

> **Warning!** Changing parameters in the advanced section may lead to incorrect printer operation, filament jams, or breakdowns. Change them only if you fully understand what each parameter is responsible for and what the consequences might be.

---

## Global Parameters

To prevent the color selection window from appearing at the start of printing, use the global parameter **SILENT**:
- `0` — show the window (default)
- `1` — do not show the window, use previously set colors
- `2` — do not show the window, do not use the feeding system

```
SAVE_ZMOD_DATA SILENT=1
```

To enable scanning of gcode files for information about tools, colors, and materials, use the **SCAN_FILE_COLORS** parameter. You can also set the value to `2` to check only the data prepared by the slicer script, without scanning the entire files:
```
SAVE_ZMOD_DATA SCAN_FILE_COLORS=1
```

To enable **automatic color mapping** from the gcode file to physical spools, use the **AUTO_ASSIGN_COLORS** parameter. To make this function work, file scanning must be activated. Using the value `30` will cause the print to abort in silent mode if any issues arise with automatic assignment:
```
SAVE_ZMOD_DATA AUTO_ASSIGN_COLORS=30
```

You can configure your own values for aborting the print in silent mode by adding the following numbers:
- `2` — At least one material does not match (e.g., ABS is specified in the gcode, but you only have PLA loaded)
- `4` — At least one color does not match at all (usually because file scanning is disabled)
- `8` — At least one color matches poorly
- `16` — The same physical spool was assigned to more than one tool index in the file

**If file scanning is disabled**, the printer does not know how many extruders are being used, and therefore **Auto PA will be run for all spools**.

---

## Add your own filament types

For these settings to work, you need to disable the printer's native screen using the `DISPLAY_OFF` macro.

To add a new filament type, add the following to `mod_data/user.cfg`:

```
[zmod_color]
filament_NEWTYPE: 300
```

Where `NEWTYPE` is replaced with your desired filament type (e.g., `HIPS`), and the number is the extruder temperature for loading, unloading, and purging this filament. Based on this value, `temp_manual` (+30) and `temp_wait` (−100) will be calculated automatically.

To hide a filament type, add the following to `mod_data/user.cfg`:

```
[zmod_color]
hide_filament_types: XXX,YYY,ZZZ
```

Where `XXX`, `YYY`, `ZZZ` are replaced with the filament types you want to hide (e.g., `PLA-CF,PETG-CF,SILK`). This can be used to hide default types or types you added manually. The filament type is not disabled, it is only hidden in the type selection menu.

---

## Add your own colors

For these settings to work, you need to disable the printer's native screen using the `DISPLAY_OFF` macro.

To add or rename a color, open `mod_data/color/ru.json` (replace `ru` with your language) and add a new color or rename an existing one.

For the color name to be displayed, the color name must start with an underscore `_`.

**Example:**
```json
{
   "ffffff": "white",
   "fffff1": "_transparent",
   "fef043": "bright_yellow",
   "dcf478": "light_green",
   "0acc38": "green",
   "067749": "dark_green",
   "0c6283": "blue_green",
   "0de2a0": "turquoise",
   "75d9f3": "light_blue",
   "45a8f9": "blue",
   "2750e0": "dark_blue",
   "46328e": "purple",
   "a03cf7": "bright_purple",
   "f330f9": "magenta",
   "d4b0dc": "lilac",
   "f95d73": "pink",
   "f72224": "red",
   "7c4b00": "brown",
   "f98d33": "orange",
   "fdebd5": "beige",
   "d3c4a3": "light_brown",
   "af7836": "terracotta",
   "898989": "gray",
   "bcbcbc": "light_gray",
   "161616": "black"
}
```

The text `_transparent` will be displayed on the buttons.

---

## Extruder Calibration

Extruder calibration allows the printer to know the exact position of each of the four nozzles relative to each other. This is necessary for high-quality multi-color printing.

**When to calibrate:**
- After replacing or repairing an extruder.
- If you notice that colors do not align on the model (X, Y, or Z shift).

**How to run:**

1. **Remove the build plate** from the bed!
2. Run the `CALIBRATE_EXTRUDERS` macro from the menu or enter it in the console:
   ```
   CALIBRATE_EXTRUDERS
   ```
3. A confirmation window will appear. Click `OK`.

**What will happen:**
- The printer will perform homing (G28).
- It will heat the bed to 65°C.
- It will sequentially pick up each of the 4 extruders (T0–T3).
- For each extruder: it will heat the nozzle, perform a purge, clean it on the wiper, and then use sensors to determine the exact X, Y, and Z coordinates.
- The results will be automatically saved to the `rw/extruder.json` file.
- Upon completion, the printer will output the found offsets for each extruder to the console.

**Additional parameters** (for advanced users):

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

> **Warning!** Do not interrupt the calibration. The process takes a few minutes.

---

## VFA Calibration

VFA (Vertical Fine Artifacts) calibration helps reduce vertical artifacts on the print surface caused by stepper motor resonances.

**How to run:**

Enter in the console:
```
CALIBRATE_VFA T=0
```

Where `T=0` is the extruder number (0–3) that will be used during calibration.

**What will happen:**
- The printer will pick up the specified extruder.
- It will reset all G-code offsets.
- It will move the head to the center of the bed (X130 Y130).
- It will run automatic resonance calibration (`STEPPER_RESONANCE_FACTORY_CALIBRATE`).
- It will return the extruder to its place.
- It will save the configuration (`SAVE_CONFIG`).

> **Tip:** It is recommended to perform VFA calibration when visible vertical bands appear on the print surface.

---

## `T_INFO` Macro

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

**How to read it:**
- `home` — the extruder is in its place (in the parking pocket).
- `HEAD` — the extruder is mounted on the print head.
- `?` — undefined state (sensors did not trigger).
- `ERROR (both)` — error: the extruder is simultaneously at home and on the head (sensor desynchronization).
- `Door` — state of the front door (`Close` / `Open`).
- `Top` — state of the top cover (`Close` / `Open`).
- `Offset` — current G-code offsets along the X, Y, Z axes.

---

## Ventilation Modes

The Creator5 Pro is equipped with a chamber ventilation system with multiple fans. Proper ventilation management is critical for the print quality of different materials.

**External intake (PLA, TPU):**
The `AIR_CIRCULATION_EXTERNAL` macro enables chamber exhaust and fresh air intake. This is needed for PLA and TPU so that the plastic cools down quickly and does not soften from the chamber heat.
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
The `AIR_CIRCULATION_INTERNAL` macro enables internal circulation and chamber heating. This is needed for ABS and ASA to avoid delamination and warping from temperature fluctuations.
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

> **Recommendation:** It is best to add ventilation macro calls to the **filament code** in the slicer. This will ensure automatic mode switching when changing materials.

**In OrcaSlicer:**
1. Open filament settings.
2. Go to the "Filament settings" tab.
3. In the **Filament start G-code** field, add the required macro:
   - For PLA: `AIR_CIRCULATION_EXTERNAL`
   - For ABS: `AIR_CIRCULATION_INTERNAL`
   - For TPU: `AIR_CIRCULATION_EXTERNAL`

**Example for PLA:**
```gcode
; Filament start gcode
AIR_CIRCULATION_EXTERNAL
```

**Example for ABS:**
```gcode
; Filament start gcode
AIR_CIRCULATION_INTERNAL
```

Thus, during multi-color printing with different materials, the ventilation will automatically switch to the required mode for each extruder.

## Print Speedup

Add to 'mod_data/user.cfg'

```
[printer]
short_move_limit: False
short_extrude_move_limit: False
```

This setting significantly speeds up printing, but it can lead to printer crashes when printing with a fuzzy skin.
