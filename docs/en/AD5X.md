### AD5X

1. [Key Features](#1-key-features)
2. [File Preparation in Orca](#2-how-to-prepare-a-file-in-orca)
3. [Color Selection (`COLOR`)](#3-how-to-use-the-color-selection-menu-macro-color)
4. [Print Menu (`PRINT`)](#4-print-menu-macro-print)
    - [AD5X Global Parameters](#ad5x-global-parameters)
5. [Manual Spool Selection](#5-how-to-manually-tell-the-printer-which-spool-is-loaded)
6. [Waste Filament Configuration](#6-how-to-configure-waste-filament-during-filament-change)

    - 🔧 [Basic Parameters](#basic-parameters-most-frequently-adjusted)
       - ⚙️ [Advanced Parameters](#advanced-parameters-do-not-adjust-if-unsure-of-the-result)

7. [Add custom filament types](#7-add-custom-filament-types)
8. [Add custom colors](#8-add-custom-colors)
9. [Fixing Trash Bin and Filament Cutting Knife Operation](#9-fixing-trash-bin-and-filament-cutting-knife-operation)

    - [Via the engineering menu on the stock firmware](#setting-up-the-basket-on-the-ad5x-stock-firmware)
       - [Via a flash drive on the stock firmware](/Setup/#ad5x-warning)

10. [IFS commands](#10-ifs-commands)
11. [IFS Firmware Recovery](#11-ifs-firmware-recovery)

### [Plugins](https://github.com/ghzserg/g28_tenz/blob/main/Plugin_en.md)

- [**bambufy**](https://github.com/function3d/bambufy) - Bambu Studio compatibility, better prime towers, accurate estimates, waste reduction
- [**nopoop**](https://github.com/ghzserg/nopoop) - Maximum waste reduction by ninjamida
- [lessWaste](https://github.com/Hrybmo/lessWaste/) - форк bambufy

---

## **1. Key Features**

Differences from AD5M:

*   No `Entware` support
*   **Always use** `FAST_CLOSE_DIALOGS` (fast closing) instead of `CLOSE_DIALOGS` (slow closing).
*   The `NEW_SAVE_CONFIG` macro **does not work**.
*   To enable the camera, use ```CAMERA_ON VIDEO=video3``` or ```CAMERA_ON VIDEO=video0``` or ```CAMERA_ON VIDEO=video99```.
*   Klipper may crash. Solution: 'Process Profile' -> 'Other' -> 'Output G-code' -> 'Exclude Models', uncheck.

---

## **2. How to Prepare a File in Orca**

[Send Files via "Octo/Klipper" for Printing](/Recomendations/#send-files-via-octoklipper-for-printing)

**You must remove unused spools from the list in Orca.**

**Example:**
The printer has 4 spools (№1, №2, №3, №4). Only spools №1 and №3 are needed for printing.

*   In the file, they will be named **T0** (first color) and **T1** (second color).
*   In the menu, you’ll need to select:
    - **T0** → spool №1
      - **T1** → spool №3

---

## **3. How to Use the Color Selection Menu (Macro `COLOR`)**

<img width="874" height="286" alt="image" src="https://github.com/user-attachments/assets/c0538a17-88a9-4aee-a65c-cff4cc1773d0" />

<img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/b6eb3ddd-ad7d-4cc2-b1b5-9f1aef918b29" />

<img width="563" height="550" alt="image" src="https://github.com/user-attachments/assets/cc0c951f-48c1-469d-8940-90832ad1d3f5" />

<img width="800" height="480" alt="color" src="https://github.com/user-attachments/assets/4145baef-a695-49e6-a914-c12dd3f6b8a4" />

*   `Extruder: 1 (PETG/Orange)` – This means the printer is currently loaded with orange PETG filament from spool №1.
*   `IFS: True` – The automatic filament feeding system is active.

**Now select the spool you want to work with (e.g., spool 2):**

<img width="568" height="455" alt="image" src="https://github.com/user-attachments/assets/f7ea3ed0-28a5-48d5-99db-eade0a199e99" />

<img width="800" height="480" alt="screenshot" src="https://github.com/user-attachments/assets/c42cbefa-a29c-4df0-a62a-d99842c13961" />

You can perform four actions:

1.  **Change the color** of the spool.
2.  **Change the material type** (e.g., from PLA to PETG).
3.  **Load** this filament into the printer.
4.  **Unload** filament from the printer.

**How to change color:**

1.  Click "Change Color".
2.  **Select a color from the list.** This ensures the printer and native screen understand your selection.
<img width="561" height="823" alt="image" src="https://github.com/user-attachments/assets/8dbff228-dfc0-4705-92f9-d94df80b7a4e" />

<img width="800" height="480" alt="screenshot" src="https://github.com/user-attachments/assets/f51f91a2-4131-4ba3-a8a0-3b9519f61f6d" />

3.  After selection, you’ll return to the menu, and the spool’s color **should update**.
<img width="556" height="545" alt="image" src="https://github.com/user-attachments/assets/f32a9239-44c6-449d-bbf7-5f453f149ef7" />

<img width="800" height="480" alt="screenshot" src="https://github.com/user-attachments/assets/4fa7bb58-ee03-4613-ba06-a5af9b2ddfa6" />

**If the color doesn’t change:** Close the window with the "X" button and restart the `COLOR` macro. Sometimes the screen doesn’t refresh immediately.

**How to change material type:**

1.  Click "Change Type".
2.  **Select a material type from the list.**
<img width="562" height="710" alt="image" src="https://github.com/user-attachments/assets/baf7b807-c4f5-4ab4-8bfd-2fc43bb448cd" />

<img width="800" height="480" alt="screenshot" src="https://github.com/user-attachments/assets/2d7b4f12-a8f1-4c99-a555-7c422bd5ffe4" />

**If the type doesn’t change:** Close the window with the "X" button and restart the `COLOR` macro. Sometimes the screen doesn’t refresh immediately.

**Tip:** If multiple spools are assigned the **same color and material type**, the printer will automatically switch to the next spool when the current one runs out. This is called **"infinite spool mode"**.

---

## **4. Print Menu (Macro `PRINT`)**

This window opens **automatically** when you start printing.
<img width="567" height="564" alt="image" src="https://github.com/user-attachments/assets/a046c089-22d3-474e-89b6-89815412d068" />

<img width="800" height="480" alt="screenshot" src="https://github.com/user-attachments/assets/f1ad0f49-e2bd-43c8-9301-7c58b9c05c22" />

**How to interpret the display:**

*   `Cube.gcode` – The name of the file being printed.
*   `T0` – The first color in the file. Printed using **spool №4** (orange PLA).
*   `T1` – The second color. Printed using **spool №3** (black PLA).
*   `T2` – The third color. Printed using **spool №2** (green PLA).
*   `T3` – The fourth color. Also printed using **spool №2** (green PLA).

**To change the spool for a color during printing:**

*   Simply **click the target T** (e.g., T1) and select another spool from the list.
<img width="553" height="550" alt="image" src="https://github.com/user-attachments/assets/4d831fdb-6ff5-4a0d-ac9e-10154d1c7956" />

<img width="800" height="480" alt="screenshot" src="https://github.com/user-attachments/assets/a87d6115-87e4-4cb1-af3e-b194edefb42b" />

---

### AD5X Global Parameters

To prevent the color selection dialog from appearing at the start of a print, use the global parameter [SILENT](/Global/#silent):

- 0 – show dialog (default)
- 1 – do not show dialog, use previously set colors
- 2 – do not show dialog, do not use IFS

```gcode
SAVE_ZMOD_DATA SILENT=1
```

To disable automatic filament insertion into the extruder, use the global parameter [AUTOINSERT](/Global/#autoinsert):

```gcode
SAVE_ZMOD_DATA AUTOINSERT=0
```

To disable dumping of filament into the trash when printing, use the [USE_TRASH_ON_PRINT](/Global/#use_trash_on_print) parameter.

```gcode
SAVE_ZMOD_DATA USE_TRASH_ON_PRINT=0
```

To unload the filament after printing is complete, use the [REMOVE_FILAMENT](/Global/#remove_filament) parameter.

```gcode
SAVE_ZMOD_DATA REMOVE_FILAMENT=1
```

To set how many tools are shown in the color selection window (if file cannot be scanned for this info), use the [ALLOWED_TOOL_COUNT](/Global/#allowed_tool_count) parameter.

[See preprocessing](https://wiki.zmod.link/Recomendations/#enable-md5-checksum-control)

```gcode
SAVE_ZMOD_DATA ALLOWED_TOOL_COUNT=16
```

To enable scanning gcode files for tool, color and material info, use the [SCAN_FILE_COLORS](/Global/#scan_file_colors) parameter. You can also set this to 2 to check for data prepared by the slicer script, but not attempt to scan entire files.

[See preprocessing](https://wiki.zmod.link/Recomendations/#enable-md5-checksum-control)

```gcode
SAVE_ZMOD_DATA SCAN_FILE_COLORS=1
```

To attempt automatic mapping of colors in the gcode file to physical spools, use the [AUTO_ASSIGN_COLORS](/Global/#auto_assign_colors) parameter. You must enable file scanning for this to be useful. Using a value of 30 will abort silent mode prints if there is any issue with the auto-assignment. 

You can create custom values for when to abort in silent mode by adding together the following values:

* 2 (At least one material cannot be matched; eg. the gcode file specifies ABS, but you only have PLA loaded; or material data could not be loaded)
* 4 (At least one color cannot be matched at all, usually due to file scanning being disabled or failing)
* 8 (At least one color is potentially a poor match)
* 16 (At least one physical spool has been assigned to more than one tool index in the file)

[See preprocessing](https://wiki.zmod.link/Recomendations/#enable-md5-checksum-control)

```gcode
SAVE_ZMOD_DATA AUTO_ASSIGN_COLORS=30
```

When a color change command is encountered, if it indicates a switch to the already-loaded color, usually the change process would be skipped as it is pointless. If for some reason you wish to enable the full color change process, use the [ALWAYS_FULL_COLOR_CHANGE](/Global/#always_full_color_change) parameter.

```gcode
SAVE_ZMOD_DATA ALWAYS_FULL_COLOR_CHANGE=0
```


---

## **5. How to Manually Tell the Printer Which Spool Is Loaded**

Sometimes you manually change the spool, but the printer doesn’t recognize it and displays outdated information.

To fix this, use a dedicated command.

**Type this phrase in the console:**

```gcode
SET_EXTRUDER_SLOT SLOT=1
```

**What this means:**

*   `SET_EXTRUDER_SLOT` – Command telling the printer: "Remember this spool!"
*   `SLOT=1` – The spool number you just loaded. **You can change this number!**

**Examples:**

*   If you loaded filament from spool №3: `SET_EXTRUDER_SLOT SLOT=3`
*   If from spool №2: `SET_EXTRUDER_SLOT SLOT=2`

After this command, the printer will know which spool is active and won’t mix up colors.

---

## **6. How to Configure Waste Filament During Filament Change**

These settings help reduce plastic waste when switching spools. To adjust them, first **disable the printer’s native screen** using the `DISPLAY_OFF` macro.

In screen-off mode, these sensors are enabled:

- `Head Switch Sensor` – Detects filament presence in the extruder
- `Ifs Motion Sensor` – Monitors filament movement in IFS


**How to find these settings:**

1.  Open the **"Configuration"** tab.
2.  Navigate to the **`mod_data`** folder.
3.  Open the **`filament.json`** file.

![File Location](https://github.com/user-attachments/assets/109b0f0a-c87d-4f5c-9333-ebfbb8065b87)

In this file, each material type (PLA, ABS, PETG, etc.) has a list of values. Here’s what they mean:

---

#### **Basic Parameters (Most Frequently Adjusted):**

For these settings to work, you need to **disable the printer's native display** using the `DISPLAY_OFF` macro.

1.  **`temp`** — Nozzle temperature for filament change. **Default value depends on material type.**
2.  **`filament_drop_length` (Purge Length)**

    *   **In simple terms:** How many millimeters of filament the printer will purge into the waste bin to **clean the nozzle** from the previous color.
        *   **Tip:** Increase this value if colors mix during spool changes. Decrease it to reduce waste.

3.  **`filament_drop_length_add` (Additional Purge)**

    *   **In simple terms:** Extra purge length when switching **material types** (e.g., PLA to PETG), not just colors.
        *   **Why it’s needed:** Different materials don’t mix well, so deeper nozzle cleaning is required.

4.  **`nozzle_cleaning_length`** — The length (in mm) of filament pulled out of the extruder when cleaning the nozzle when the spool is no longer in use. **Default: 60 mm.**

5.  **`filament_unload_into_tube`** — How much filament to unload from the 4-in-1 module when the extruder is no longer used. **Default: 70 mm.**

    *   If you have a new version 4-in-1 module, increase `filament_unload_into_tube` or as a last resort increase `nozzle_cleaning_length`

---

##### **Advanced Parameters (Do Not Adjust If Unsure of the Result):**

For these settings to work, you need to **disable the printer's native display** using the `DISPLAY_OFF` macro.

*   **`filament_tube_length`** — Total PTFE tube length from IFS module to extruder. Useful for non-standard tubes. **Default: 1000 mm.**
*   **`filament_unload_before_cutting`** — Filament lift distance **before** cutting. **Default: 0 mm.**
*   **`filament_unload_after_cutting`** — Filament lift distance **after** cutting, before moving to the waste bin. **Default: 5 mm.**
*   **`filament_unload_after_drop`** — Retraction distance after purging to prevent oozing. **Default: 3 mm.**
*   **`filament_extruder_speed`** — Speed (in mm/min) at which filament is loaded into the extruder. **Default: 300 mm/min (5 mm/s).**
*   **`filament_ifs_speed`** — Speed (in mm/min) at which the IFS module operates. **Default: 12000 mm/min (20 mm/s).**
*   **`filament_fan_speed`** — Fan speed (0–255) during purging to cool oozing. **Default: 102.**
*   **`filament_autoinsert_empty_length`** — Filament length pulled when auto-loading into an empty extruder. **Default: 600 mm.**
*   **`filament_autoinsert_full_length`** — Filament length pulled when replacing existing filament. **Default: 550 mm.**
*   **`filament_autoinsert_ret_length`** — Retraction distance after extruder sensor triggers (empty extruder only). **Default: 90 mm.**
*   **`filament_autoinsert_speed`** — Auto-insertion speed (mm/min). **Default: 1200 mm/min (20 mm/s).**

**Warning!** Modifying advanced parameters may cause printer malfunctions, filament jams, or hardware damage. Adjust only if you fully understand each parameter’s purpose and potential consequences.

**Key takeaway:** To reduce waste, start by decreasing **`filament_drop_length`** and **`filament_drop_length_add`** for your material. Don’t forget to save the file after changes!

## **7. Add custom filament types**

For these settings to work, you need to **disable the printer's native display** using the `DISPLAY_OFF` macro.

To add a new filament type, add the following to ```mod_data/user.cfg```:
```
[zmod_ifs]
filament_NEWTYPE: 300
```
Where NEWTYPE is replaced with the desired filament type (e.g., HIPS), and the number is the melting point of this filament.

```IFS_PRINT_DEFAULTS``` - displays available filament types and their melting points

---

## **8. Add custom colors**

For these settings to work, you need to **disable the printer's native display** using the `DISPLAY_OFF` macro.

To add or rename a color, open ```mod_data/colors/en.cfg``` (use your language instead of en):

Add a new color or rename an existing one.

To display the color name, the color name must begin with an underscore ```_```

Example:
```
{
"ffffff": "white",
"fffff1": "_transparent",
"fef043": "bright yellow",
"dcf478": "light green",
"0acc38": "green",
"067749": "dark green",
"0c6283": "blue-green",
"0de2a0": "turquoise",
"75d9f3": "cyan",
"45a8f9": "blue",
"2750e0": "dark blue",
"46328e": "violet",
"a03cf7": "bright violet",
"f330f9": "purple",
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

The text ```_transparent``` will be displayed on buttons.

---

## 9. Fixing Trash Bin and Filament Cutting Knife Operation

[Alternative version of the instructions](/Setup/#ad5x-warning)

Different AD5X printers may have different coordinates for the trash bin and knife. Sometimes the difference can reach up to 4 mm.

Because of this:

- Filament may not reach the trash bin;
- Knife does not cut the filament;
- Printer head may hit the wall.

To fix this, you need to:

1. Update zMod.
2. Open the file `/rw/Adventurer5M.json`.
3. Find these lines:
```json
{
        "CutXOffset" : 0.5,
        "CutYOffset" : -0.20000001788139343,
        "xOffset" : 0.0,
        "yOffset" : -0.20000001788139343,
        "zOffset" : 0.0,
        "zProbeOffset" : 0.004999995231628418
},
```
<img width="504" height="241" alt="image" src="https://github.com/user-attachments/assets/8647b1fe-594c-4bb3-91ee-560cfe4a58fd  " />

Replace **only** these values:
```json
"CutXOffset": 0.0,
"CutYOffset": 0.0,
"yOffset": 0.0,
```

4. Enter the command: `UPDATE_FF_OFFSET` (this will update the settings).
5. Then enter: `_GOTO_TRASH` (this will move to the trash bin).

---

### Trash Bin Calibration

[Alternative version of the instructions](/Setup/#ad5x-warning)

1. Enter the command `_GOTO_TRASH` — the printer head will move to the trash bin.
2. If the bin doesn't close. Сarefully move the head until the bin closes. You need use GCODE: ```G1 Y230.2```
3. Check what **Y** coordinate you now have.
4. Subtract 229 from this number. The result will be your `yOffset`.

Examples:

- If Y = 230.2, then `yOffset = 230.2 - 229 = 1.2`
- If Y = 228.4, then `yOffset = 228.4 - 229 = -0.6`
- Formula: `yOffset = Y - 229`

Write this number to the file `/rw/Adventurer5M.json`. The bin is calibrated.

5. Enter the command: `UPDATE_FF_OFFSET` (this will update the settings).
6. Then enter: `_GOTO_TRASH` (this will move to the trash bin).

---

### Knife Calibration

[Alternative version of the instructions](/Setup/#ad5x-warning)

1. Enter the command `_CUT_PRUTOK` — the head will move to the knife.
2. You need use GCODE: ```G1 Y-7.7``` ```G1 X-1.7```, move the head until the knife activates.
3. Check what X and Y coordinates you have.
4. For **Y**:

    - Subtract your Y-coordinate from **7.5** by absolute value.
       - Example: if Y = -7.7, then `CutYOffset = 7.5 - 7.7 = -0.2`
       - Example: if Y = -5.9, then `CutYOffset = 7.5 - 5.9 = 1.6`
       - Formula: `CutYOffset = 7.5 + Y`

5. For **X**:

    - Subtract your X-coordinate from **2.5** by absolute value.
       - Example: if X = -1.7, then `CutXOffset = 2.5 - 1.7 = 0.8`
       - Example: if X = -2.8, then `CutXOffset = 2.5 - 2.8 = -0.3`
       - Formula: `CutXOffset = 2.5 + X`

Write these numbers to the file `/rw/Adventurer5M.json`. The knife is calibrated.

6. Enter the command: `UPDATE_FF_OFFSET` (this will update the settings).
7. Then enter: `_GOTO_TRASH` (this will move to the trash bin).

Restart the printer — everything is ready.

---

## Setting up the basket on the AD5X stock firmware

1. Go to the "i" tab and press the `Status` button
   
   <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/08a99d33-c970-4e86-933d-0064b447f5b7" />
   
2. Go to the 6th tab
   
   <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/a0eb4b8f-552b-4e58-86d7-2b47b8b0035c" />
   
3. Press and hold `Move the extruder to waste tray position` for 20 seconds
   <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/81213d65-bf06-4d33-8e4a-eb3aae2782d7" />
   
4. Adjust the head position in the waste tray so that it closes. Using the control arrows, park the print head at the receiver in such a way that the print head sufficiently presses the shutter lever, the nozzle is behind the moving shutter, and the shutter itself is flush with the front surface of the receiver.
   
   <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/7b506200-0d61-4b88-aaf8-40475e3ad463" />
   
   Press the `Set` button.
   
5. Press and hold `Move the extruder to cutter striker position` for 20 seconds
   <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/e61c61c0-f1a1-4535-b9ef-37baa4ab1d8c" />
   
6. Adjust the cutter. Press `CutX` — the cutter should cut the filament without slipping or striking.
   
   <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/a0c1939e-dada-48cb-8789-df43999bf99b" />
   
   Press the `Set` button.

---

## **10. IFS commands**

For these settings to work, you need to **disable the printer's native display** using the `DISPLAY_OFF` macro.

- `IFS_F10` - Insert filament
- `IFS_F11` - Remove filament
- `IFS_F13` - IFS state
- `IFS_F15` - Reset driver
- `F18` - Filament purge everywhere
- `F23` - Mark filament as inserted
- `F24` - Filament clamp
- `F39` - Filament purge
- `F112` - Stop filament feed
- `PURGE_PRUTOK_IFS` - Purge filament from IFS to the extruder
- `REMOVE_PRUTOK_IFS` - Removes filament by filament number
- `INSERT_PRUTOK_IFS` - Insert filament into IFS by filament number
- `SET_CURRENT_PRUTOK` - Tell klipper which filament is currently active
- `ANALOG_PRUTOK` - Load an analog rod
- `IFS_MOTION` - Check if the filament has stopped or run out

IFS module parameters:

- debug - debugging (True, *False*)
- silk_count - number of attempts to read a rod into IFS (*1*)
- stall_count - number of attempts to count a rod as stopped (*1*)
- retry_count - number of times to retry the command on error (*3*)
- filament_NEWFILEMENT - Add a new filament type. Parameter - replacement temperature for this type of plastic.

Set via `mod_data/user.cfg`:
```
[zmod_ifs]
debug: True
silk_count: 1
stall_count: 1
filament_NEWTYPE: 300
```

## **11. IFS Firmware Recovery**

To recover the IFS firmware, you need an **ARM J-LINK V9** programmer.

<img width="800" height="800" alt="image" src="https://github.com/user-attachments/assets/ae91768b-00d8-4e36-a62d-3056a7e117bf" />

<img width="960" height="479" alt="image" src="https://github.com/user-attachments/assets/f623fa41-4bc3-40a4-a434-5d8ad717792b" />

Solder wires to the iFS board.

<img width="579" height="774" alt="image" src="https://github.com/user-attachments/assets/cb2b2f72-9eba-4831-8cea-072813b6e0e3" />

Connect:

- CLK to SWCK
- DIO to SWIO
- VCC to 3.3
- GND to GND

<img width="346" height="390" src="https://github.com/user-attachments/assets/19438d58-9879-48e5-8acc-bfb21ce4549c" />

- Target Device - `Nations N32G455RE`
- Target interface: `SWD`
- Speed: `4000`
- Check the first checkbox.
- Uncheck the second checkbox.

1. Connect.
2. Select the [firmware file](/Native_FW/#5x-ifs). **Don't forget to extract it**.
3. Press **F7** and wait for the device to be flashed.

## IFS: sensor error: Serial communication error: read failed: device reports readiness to read but returned no data (device disconnected or multiple access on port?)

This error occurs when the native display and the mod access the IFS simultaneously.

It's best to reduce the native display lifetime to 10 seconds: ```SAVE_ZMOD_DATA DISPLAY_OFF_TIMEOUT=10```
