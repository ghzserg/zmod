# [Setup](#installing-the-mod)

[@zmod_help_bot](http://t.me/zmod_help_bot)

| | |
|---|---|
| [Restoring Printer to Factory Settings](#restoring-printer-to-factory-settings-required-for-mod-installation) | [Installing the Mod](#installing-the-mod) |
| [Updating the Mod](#updating-the-mod) | [How to Update Stock Firmware](#updating-stock-firmware) |
| [Removing - Temporarily Disabling the Mod](#removing-or-temporarily-disabling-the-mod) | [Boot Recovery](#boot-recovery) |
| [Support Mod Development](#support-mod-development) | - |

## [Calibration](#printer-calibration-for-beginners)

| | |
|---|---|
| [Extruder PID Tuning](#extruder-pid-tuning) | [Bed PID Tuning](#bed-pid-tuning) |
| [Bed Screws Leveling](#bed-screws-leveling-bed_level_screws_tune) | [Precise Bed Mesh Leveling](#precise-bed-mesh-leveling-auto_full_bed_level) |
| [Adaptive Bed Leveling](#adaptive-bed-leveling-kamp) | [How Z-Offset Works](#how-z-offset-works-on-your-printer) |
| [Input Shaper Calibration](#input-shaper-calibration-input-shaper) | |


---

## Restoring Printer to Factory Settings (Required for Mod Installation)

0. [Uninstall KlipperMod](https://github.com/xblax/flashforge_ad5m_klipper_mod/blob/master/docs/UNINSTALL.md) if previously installed.
1. Reset the printer to default settings.
2. Format a USB drive to FAT/FAT16/FAT32.
3. Copy the appropriate file from the [Native firmware](https://github.com/ghzserg/zmod/wiki/R) to the USB root directory:
   - [Adventurer5M-3.1.9-2.2.3-20250807-Factory.tgz](https://github.com/ghzserg/zmod/releases/download/R/Adventurer5M-3.1.9-2.2.3-20250807-Factory.tgz) for FF5M
   - [Adventurer5MPro-3.1.3-2.2.3-20250107-Factory.tgz](https://github.com/ghzserg/zmod/releases/download/R/Adventurer5MPro-3.1.3-2.2.3-20250107-Factory.tgz) for FF5m**Pro** версии 
   - [AD5X-1.1.6-1.1.0-3.0.6-20250722.tgz](https://github.com/ghzserg/zmod/releases/download/R/AD5X-1.1.6-1.1.0-3.0.6-20250722.tgz) for AD5X
4. Power off the printer.
5. Insert the usb drive into printer usb port.
6. Power on the printer.
7. Wait for the stock firmware installation to complete.
8. Configure Wi-Fi or Lan *new beaver*
9. Install the latest printer updates.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#setup)

</div>

---

## Installing the Mod

[Video](https://www.youtube.com/watch?v=2sfb2OtY7wM)

1. **[Restore the printer to factory settings](https://github.com/ghzserg/zmod/wiki/Setup_en#restoring-printer-to-factory-settings-required-for-mod-installation).**  [AD5X Warning](https://github.com/ghzserg/zmod/wiki/Setup_en#ad5x-warning)
2. Format a USB drive to FAT/FAT16/FAT32.
3. Copy the [mod file](https://github.com/ghzserg/zmod/releases/) to the USB root directory:
   - For FF5M: Adventurer5M-**zmod**-*.tgz
   - For FF5M Pro: Adventurer5MPro-**zmod**-\*.tgz
   - For [AD5X](https://github.com/ghzserg/zmod/wiki/AD5X_en): AD5X-**zmod**-*.tgz
4. Power off the printer.
5. Insert the USB drive.
6. Power on the printer.
7. Wait for the mod installation to complete.

   <img width="800" height="480" alt="install" src="https://github.com/user-attachments/assets/9d6b9ad7-e9ec-4bc2-bd8f-54c945b5add5" />
   
   <img width="800" height="480" alt="screenshot" src="https://github.com/user-attachments/assets/19d66329-72f9-4e92-aba6-35b7820ce9a0" />
   
   Installation on the AD5X can take up to 40 minutes
8. Remove the USB drive.
9. Power the printer.
10. **Open the printer's IP address in the browser**
    <img width="800" height="480" alt="main" src="https://github.com/user-attachments/assets/a0466fa8-03e8-458d-8cc5-c1efb8f565ac" />
    <img width="800" height="480" alt="ip" src="https://github.com/user-attachments/assets/1d7dd5fa-86f4-4b1a-bd42-364619b20229" />
    
    If the web interface doesn't open, the stock firmware has disabled the mod. To enable it, copy the file [AD5X-ENABLE-zmod.tgz](https://github.com/ghzserg/zmod/releases/download/R/AD5X-ENABLE-zmod.tgz) to a USB flash drive and [activate the mod](https://github.com/ghzserg/zmod/wiki/R/#ad5x-enable-zmodtgz).
12. Translate the mod into your language.

    <img width="564" height="583" alt="{8E14F84D-E8D1-4129-B192-AA335243A3D9}" src="https://github.com/user-attachments/assets/e6dd3f8a-3cc3-4a05-b5fb-ad8ba372ede6" />
    
    Or type in the console: ```LANG LANG=en```
    
    <img width="881" height="502" alt="image" src="https://github.com/user-attachments/assets/cf3f797d-80e0-4864-85b4-cd28886590f4" />

13. Configure the mod

    <img width="558" height="219" alt="{B34D2AF2-F2A6-433D-B9F8-86A83389D5A7}" src="https://github.com/user-attachments/assets/a79ec692-a284-4cb8-a0ad-3be10f33d813" />
    
    This shows parameters used at print start, print end, and global settings. It is recommended to just review the settings — do not change them unless necessary. The description for each parameter can be [found here](https://github.com/ghzserg/zmod/wiki/Global_en).

    <img width="561" height="443" alt="{623507C1-D3AB-4FEF-9A92-E949A85DCB49}" src="https://github.com/user-attachments/assets/3a8028bf-b078-4edc-827b-07e9d49c52f9" />

    You must proceed to the last screen and press `Ok` or `Reboot`. If you skip this, the window will appear on every boot.

    <img width="564" height="228" alt="{BCEBDCCC-0703-46F3-8B7B-3BC58E78F27A}" src="https://github.com/user-attachments/assets/72d386a4-18ba-40a9-8f85-a6109a4e4c57" />

    To display this window again later, type in the console: `GLOBAL`

14. Go to `Settings` → `Firmware Updates`  
15. Click `Check for Updates`, and wait until the check completes  
16. Click **Update** and update all components.

    <img width="1239" height="535" alt="image" src="https://github.com/user-attachments/assets/b42c4ce9-1c0a-45c0-a20c-36919a27d648" />

    If many errors appear — this is normal. Plugins are not part of the firmware and are downloaded separately. Click `Check for Updates` again, then restore and update each module individually. The printer will reboot during the process.

    <img width="671" height="844" alt="image" src="https://github.com/user-attachments/assets/d6fe3ad0-64be-4c07-8f5e-53647a6bd6ee" />

17. Enable the [recommendations plugin](https://github.com/ghzserg/recommend/blob/main/Readme.md)

    <img width="560" height="224" alt="{E27E192D-3FC2-49AC-BEAF-F7B574FFEF45}" src="https://github.com/user-attachments/assets/dade8a2e-fc67-4df5-aad4-85cc5cd81d66" />

    Or enter in the console: ```ENABLE_PLUGIN name=recommend```

    <img width="864" height="87" alt="image" src="https://github.com/user-attachments/assets/ca96c67f-cc58-4655-8fdf-9554d1a489a3" />

18. [Send Files via "Octo/Klipper" for Printing](https://github.com/ghzserg/zmod/wiki/Recomendations_en#send-files-via-octoklipper-for-printing)

    You **need to switch to the Octo/Klipper protocol**:
    - Protocol: `Octo/Klipper`
    - Hostname: `Printer_IP:7125`
    - Host URL: `Printer_IP` or `Printer_IP:80`
    
    <img width="673" height="467" alt="image" src="https://github.com/user-attachments/assets/70d5da64-0604-44e5-9102-887b758b5cf0" />
    <img width="473" height="395" alt="image" src="https://github.com/user-attachments/assets/ca4c5330-dc88-4372-a3c8-51527ae76146" />
19. The entire start code should be replaced with this:
    ```
    START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
    M190 S[bed_temperature_initial_layer_single]
    M104 S[nozzle_temperature_initial_layer]
    SET_PRINT_STATS_INFO TOTAL_LAYER=[total_layer_count]
    ```
    
    ```START_PRINT EXTRUDER_TEMP=... BED_TEMP=...``` should be written on one line
    
    The end code should be this:

    ```END_PRINT```
    
    <img width="612" height="443" alt="image" src="https://github.com/user-attachments/assets/0dfd8840-c183-4d33-92aa-46f882b8c32c" /> 
    
    Code for before changing the layer to this one:

    ```SET_PRINT_STATS_INFO CURRENT_LAYER={layer_num + 1}``` 
    
    <img width="449" height="153" alt="image" src="https://github.com/user-attachments/assets/705fb49e-2c6b-451b-9b99-9d8d1f0e80f8" />
20. [Enable MD5 verification](https://github.com/ghzserg/zmod/wiki/Recomendations_en#enable-md5-checksum-control)

    <img width="307" height="131" alt="image" src="https://github.com/user-attachments/assets/c90c096e-ff42-4479-b094-9d57261e7f36" />
21. [Read the recommendations](https://github.com/ghzserg/zmod/wiki/Recomendations_en)
22. [Read the FAQ](https://github.com/ghzserg/zmod/wiki/FAQ_en)

### AD5X Warning

[@Khamai](https://t.me/Khamai)

After installing the Native Firmware, the print head may not be correctly positioned against the filament receiver (the receiver shutter may not be fully closed, filament may be pushed onto the table, etc.).

[Via the engineering menu on the stock firmware](https://github.com/ghzserg/zmod/wiki/AD5X_en#setting-up-the-basket-on-the-ad5x-stock-firmware)

If you encounter this issue, you need to calibrate the print head position using the following algorithm:
1. Download the [Set.XY.Offset.zip](https://github.com/ghzserg/zmod/releases/download/R/Set.XY.Offset.zip) archive and unzip it to the root of a flash drive.
2. Insert the flash drive into the turned-off printer and turn it on.
3. The calibration interface will appear on the printer screen. Press Reset.
4. Use the control arrows to position the print head against the receiver so that the print head presses the shutter lever firmly, the nozzle is behind the movable shutter, and the shutter itself is flush with the front surface of the receiver.
5. Press the Set button to confirm the calibration result.
6. Remove the flash drive and reboot the printer.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#setup)

</div>

---

## Printer Calibration for Beginners

| | |
|---|---|
| [Extruder PID Tuning](#extruder-pid-tuning) | [Bed PID Tuning](#bed-pid-tuning) |
| [Bed Screws Leveling](#bed-screws-leveling-bed_level_screws_tune) | [Precise Bed Mesh Leveling](#precise-bed-mesh-leveling-auto_full_bed_level) |
| [Adaptive Bed Leveling](#adaptive-bed-leveling-kamp) | [How Z-Offset Works](#how-z-offset-works-on-your-printer) |
| [Input Shaper Calibration](#input-shaper-calibration-input-shaper) | |

Generally, you don't need to calibrate anything, but if you want to fine-tune your printer, read on:

If you have completed the initial calibrations:
<img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/c0c63cc4-c4b3-46d4-a3e7-6485d8bf26bb" />

Then you already have:
- Configured z-offset
- A bed mesh ```MESH_DATA``` (taken at 60 degrees) - do not delete it if you use the stock screen, as it loads it for every print
- Extruder PID calibration for 240 degrees

But these settings are quite generic; few people print at a nozzle temperature of 240 degrees and a bed temperature of 60 degrees.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#calibration)

</div>

---

### Extruder PID Tuning

**Why is this needed?**
Imagine the extruder is an oven. If the temperature constantly "jumps," your dish (your part) might bake unevenly. PID calibration "teaches" your printer to maintain the exact temperature without fluctuations. This is critical for print quality.

**Important Note Before Starting!**
Calibrate specifically for the conditions you print in:
*   **Temperature:** The one you most often use for your filament (e.g., 210°C for PLA or 255°C for PETG).
*   **Cooling:** The part cooling fan should run at the same power as during normal printing.

**How to Perform the Calibration?**

-   Use the special command (macro) [PID_TUNE_EXTRUDER](https://github.com/ghzserg/zmod/wiki/Calibrations_en#pid_tune_extruder)

-   You can enter it manually in the console or press a button in the interface if available:
    <img width="283" height="265" alt="image" src="https://github.com/user-attachments/assets/20b8a3c8-4726-44b0-b986-34881d95cb18" />

-   The command itself looks like this (this is an example!):
    ```gcode
    PID_TUNE_EXTRUDER TEMPERATURE=255 COOLER=80
    ```
    **What this means:**
    *   `TEMPERATURE=255` — calibration is performed for 255°C. Set your desired temperature.
    *   `COOLER=80` — the part cooling fan runs at 80% power.

-   **After Completion:**
    *   The printer will automatically save the new settings.
    *   **Be sure to reboot the printer!** This is needed to update the system data and prevent freezes.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#calibration)

</div>

---

### Bed PID Tuning

**Why is this needed?**
Your printer's bed, like the extruder, must accurately maintain its temperature. If it fluctuates, it can lead to first-layer adhesion issues or even warping (curling) of the part at the edges. Bed PID calibration teaches it to reach and hold the target temperature quickly and stably without overshooting.

**Recommendation for AD5X**

Open the `printer.cfg` file and set in the ```heater_bed``` section:
```
[heater_bed]
max_power: 0.6
```
This allows the bed to heat up faster and the PID will tune correctly.
After changing and saving the parameter, you need to reboot the printer.

Or you can enable the recommendation plugin and it will automatically correct this file: ```ENABLE_PLUGIN NAME=recommend```

**Important Note Before Starting!**
The same rule applies here as with the extruder: calibrate for the temperature you plan to use most often (e.g., 60°C for PLA or 110°C for ABS).

**How to Perform the Calibration?**

-   Use the macro [PID_TUNE_BED](https://github.com/ghzserg/zmod/wiki/Calibrations_en#pid_tune_bed)

-   You can also enter it in the console or call it via a button in the interface (often located next to the extruder calibration button):

    <img width="227" height="192" alt="image" src="https://github.com/user-attachments/assets/77dd8332-1912-41df-a94e-469ebfa2f895" />

-   The command for the bed is even simpler:
    ```gcode
    PID_TUNE_BED TEMPERATURE=80
    ```
    **What this means:**
    *   `TEMPERATURE=80` — calibration is performed for a bed temperature of 80°C. Set your desired temperature.

-   **After Completion:**
    *   The new settings are automatically saved.
    *   **Don't forget to reboot the printer!** This completes the process of applying the new parameters.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#calibration)

</div>

---

### Bed Screws Leveling (BED_LEVEL_SCREWS_TUNE)

**Why is this needed?**
Your bed is held by several screws. If they are tightened differently, the bed becomes tilted, and the distance between it and the nozzle becomes uneven. This causes poor adhesion in some areas, and in others, the nozzle might even scrape the model. This calibration helps perfectly level the bed by adjusting its 4 mounting screws.

**How it Works:**
1.  The printer sequentially moves the nozzle to positions above each screw.
2.  It measures the distance to the bed and shows on the screen which screw to turn and in which direction.
3.  You adjust the screws according to the prompts.
4.  The process repeats until the bed is level.

**Configuration Parameters for [BED_LEVEL_SCREWS_TUNE](https://github.com/ghzserg/zmod/wiki/Calibrations_en#bed_level_screws_tune):**

*   `EXTRUDER_TEMP=130` — extruder temperature. Needed so that the nozzle's thermal expansion doesn't distort the measurements. Set a temperature where the filament doesn't ooze from the nozzle.
*   `BED_TEMP=80` — bed temperature. The bed also expands when heated, so calibration should be done at the temperature you print at.

Before calibration, clean the nozzle, otherwise the measurements will be incorrect!

**Calibration Process:**

-   Enter the command in the console or press the button:

    <img width="344" height="310" alt="image" src="https://github.com/user-attachments/assets/6757eb4e-53b7-4b08-903f-75491b4daace" />


    ```gcode
    BED_LEVEL_SCREWS_TUNE EXTRUDER_TEMP=130 BED_TEMP=80
    ```

-   **Important:**
    *   The printer will heat the extruder and bed to the specified temperatures.
    *   It will start the procedure and show you which screw and how much to adjust (e.g., "clockwise" or "counter-clockwise").

    <img width="621" height="394" alt="image" src="https://github.com/user-attachments/assets/f930f4ac-e907-4c83-bc1d-3d5a4e06fe3b" />

-   After the first pass, the printer will wait for you to perform the adjustments. When all screws are adjusted, **press the repeat button** for the printer to check the result. Repeat until the readings are perfect.

-   **Completion:**
    *   When you finish and exit the calibration mode, the printer will **NOT reset** the temperatures automatically.
    *   **Be sure to manually set the extruder and bed temperatures to zero via the control menu!**
    *   **The bed mesh and z-offset will become invalid**. Start the leveling calibration from the **stock screen**.

    <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/2d17f77f-a98b-450d-a7e5-72a0a37e47de" />

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#calibration)

</div>

---

### Precise Bed Mesh Leveling (AUTO_FULL_BED_LEVEL)

**Why is this needed?**
Even a perfectly leveled bed can have slight dips or bumps. A bed mesh (or "mesh calibration") is like a "topographic map" of your bed. The printer remembers these irregularities and will slightly move the Z-axis during printing to keep the nozzle at the perfect distance from the surface. This guarantees flawless first-layer adhesion across the entire bed area.

**Why This Specific Command?**
The built-in tools in Fluidd and Mainsail are not suitable for our printers because they:
*   Do not know how to work with the **strain gauge** (which is responsible for precise touch detection).
*   Do not perform **nozzle cleaning** beforehand to remove plastic ooze that could ruin measurement accuracy.

Our macro [AUTO_FULL_BED_LEVEL](https://github.com/ghzserg/zmod/wiki/Calibrations_en#auto_full_bed_level) accounts for both these features!

**Important Settings:**
The mesh must be built under the same conditions you print in – on a heated bed and hot extruder, as metal expands slightly with heat. A bed mesh taken at 60 degrees is drastically different from one taken at 110 degrees.

*   `EXTRUDER_TEMP=255` — extruder temperature. The plastic in the nozzle must be melted so it can be cleaned before measurement. Set your desired temperature.
*   `BED_TEMP=80` — bed temperature. Specify the one you use for printing. Set your desired temperature.
*   `PROFILE=auto` — the profile name under which the mesh will be saved. It's better to name it by the bed temperature, e.g., `80`.

**Example Command:**
```gcode
AUTO_FULL_BED_LEVEL EXTRUDER_TEMP=255 BED_TEMP=80 PROFILE=80
```

<img width="302" height="342" alt="image" src="https://github.com/user-attachments/assets/643b7bbc-992d-40cb-9404-1fed185ad0ea" />

In this example, we are building a mesh for printing on an 80°C bed and saving it under the name `80`.

#### How to Use the Saved Mesh in Printing?

To make the printer automatically load the required mesh at the start of each print, add the following lines to the **Start G-code** in your slicer (OrcaSlicer):

```gcode
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single] MESH=80
M190 S[bed_temperature_initial_layer_single] ; Wait for bed to heat
M104 S[nozzle_temperature_initial_layer] ; Set nozzle temperature
```

**What happens here:**
*   [START_PRINT](https://github.com/ghzserg/zmod/wiki/Main_en#start_print) - the main start print macro
*   The line `START_PRINT... MESH=80` tells the printer: "Start the print and load the bed mesh named `80`".
*   `[nozzle_temperature_initial_layer]` and `[bed_temperature_initial_layer_single]` are variables from the slicer that will automatically substitute your set temperatures for the first layer.
*   The main thing is to ensure that the `MESH=` parameter points to the same profile name (in our example, `80`) that you used in `AUTO_FULL_BED_LEVEL`.

Even better, create several meshes for each temperature 60, 70, 80, 90, 100, 110 and use the following start code:
```gcode
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single] MESH=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single] ; Wait for bed to heat
M104 S[nozzle_temperature_initial_layer] ; Set nozzle temperature
```

In this case, the bed mesh corresponding to the bed temperature will be loaded.

**Final Procedure:**
1.  Build the bed mesh using the `AUTO_FULL_BED_LEVEL` macro for your printing temperature.
2.  Add the `START_PRINT` command with the `MESH=...` parameter pointing to your profile name to the slicer's start code.
3.  Now, for every print, the printer will automatically use the correct irregularity map!

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#calibration)

</div>

---

### Adaptive Bed Leveling (KAMP)

**Why is this needed?**
[KAMP](https://github.com/ghzserg/zmod/wiki/Calibrations_en#kamp) is a smart system that builds a bed mesh not over the entire area, but only in the zone where your models are located! This significantly speeds up print preparation, especially on large printers, while retaining all the benefits of a precise bed mesh.

**How it Works:**
1.  Before starting a print, KAMP analyzes the location of all objects on the bed.
2.  Instead of building a full grid, it measures the bed height only in the required area.
3.  This saves time without sacrificing print quality.
4.  The mesh becomes denser, hence more accurate.

**Important Feature of the Process:**
When using KAMP (and full calibration too), the printer follows a smart scheme to ensure maximum accuracy:
1.  The nozzle **heats to printing temperature**.
2.  **Nozzle cleaning** occurs to remove oozing plastic.
3.  The nozzle **cools down to 120°C**. This is necessary so that during measurements, no molten plastic drips from the clean nozzle, which could distort the results.
4.  **Bed mesh measurement** takes place with a cold and clean nozzle.
5.  After measurements, the nozzle **heats up again to printing temperature** to start printing.

#### KAMP Configuration

**When to Use KAMP?**
In most cases, there is no need to build a bed mesh before every print. The exception is if you use **removable plates with different thicknesses** (e.g., PEI sheet and glass), as they may have different heights.

**1. Enabling Adaptive Calibration (KAMP)**

Activate this option to make the printer use KAMP wherever possible [SAVE_ZMOD_DATA USE_KAMP=1](https://github.com/ghzserg/zmod/wiki/Global_en#use_kamp).

```gcode
SAVE_ZMOD_DATA USE_KAMP=1
```

Configure Orca:
- `Process Profile` -> `Other` -> `Custom G-code` -> `Exclude objects` check the box
- `Process Profile` -> `Other` -> `Custom G-code` -> `Label objects` check the box

<img width="285" height="171" alt="image" src="https://github.com/user-attachments/assets/faceef98-2791-4975-bf72-425f4a2b1dfa" />


**2. Enabling Calibration Before Each Print**

If you want the printer to automatically build a bed mesh before starting each job (e.g., when frequently changing plates), activate this function [SAVE_ZMOD_DATA PRINT_LEVELING=1](https://github.com/ghzserg/zmod/wiki/Global_en#print_leveling).

```gcode
SAVE_ZMOD_DATA PRINT_LEVELING=1
```

You can use a start code like this:
```gcode
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single] ; Wait for bed to heat
M104 S[nozzle_temperature_initial_layer] ; Set nozzle temperature
```

**Important for stock screen operation:** To initiate bed mesh leveling from the printer's stock screen, you must go to the screen menu:
`Settings` → `WiFi Icon` → `Network Mode` → enable the `Local Networks Only` toggle.

**3. Smart Purge Before Print**

Add this setting to make the printer use the same area for nozzle cleaning where it just took the bed mesh. This saves space and time [SAVE_ZMOD_DATA CLEAR=LINE_PURGE](https://github.com/ghzserg/zmod/wiki/Global_en#clear).

```gcode
SAVE_ZMOD_DATA CLEAR=LINE_PURGE
```

#### Summary: How to Set Up KAMP for Perfect Printing

To enable smart bed mesh leveling before each print, run the following command once:

```gcode
SAVE_ZMOD_DATA USE_KAMP=1 PRINT_LEVELING=1 CLEAR=LINE_PURGE
```

Now, before each print, the printer will take a bed mesh only where there are objects to print.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#calibration)

</div>

---

### How Z-Offset Works on Your Printer

**What is Z-Offset?**
Simply put, it is the **precise distance between the nozzle tip and the bed** at the moment the printer considers them to have "touched." The correct Z-Offset ensures that the first layer of plastic adheres perfectly to the bed – not too low (the nozzle will scrape the bed) and not too high (the plastic won't stick). [Learn more](https://github.com/ghzserg/zmod/wiki/FAQ#%D0%BA%D0%B0%D0%BA-%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0%D0%B5%D1%82-z-offset)

**The Most Important Rule:**
On our printer, **Z-Offset is ONLY relevant DURING printing**. The values you see on the screen or in the interface BEFORE or AFTER printing are for reference only and do not reflect the actual situation.

#### Adjusting Z-Offset from the Stock Printer Screen

The stock screen is the primary tool for Z-Offset adjustment. It automatically manages the offset, and its settings are saved reliably.

**To make the printer select the offset automatically, you need to start building the table map from the native screen.**

<img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/81cb7bdd-e8c4-4d2f-a5b4-38e12fe72241" />


**How to Adjust:**

1.  Adjustment is possible **only during printing**.
2.  Press the **bottom right square** on the touch screen.
    
    <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/ae62aced-07af-489f-99b1-ce91cd55027d" />

3.  Then press the **"pencil" icon** to edit the Z-Offset value.
    
    <img width="800" height="474" alt="image" src="https://github.com/user-attachments/assets/7d185d47-6c60-4d57-8901-923971a9ee7f" />

4.  Make changes based on the first layer quality.

**Important to Know:**
*   For the AD5M printer, the stock screen always adds a fixed value of **0.025 mm** to your setting.
*   Therefore, the Z-Offset you see in the Fluidd or Mainsail interface will always be **0.025 mm MORE** than the value you set on the printer screen. This is normal!

**Second important rule:**
**The Z-Offset for native and non-native screens is different; each has its own unique setting. Use ```LOAD_ZOFFSET_NATIVE``` to copy the Z-Offset from the native screen to non-native screen mode.

#### Adjusting Z-Offset via Fluidd / Mainsail / GuppyScreen when operating *without the stock screen*

**How it Works:**

1.  To make the printer remember the Z-Offset from the web interface and GuppyScreen, you need to activate a special setting once [SAVE_ZMOD_DATA LOAD_ZOFFSET=1](https://github.com/ghzserg/zmod/wiki/Global_en#load_zoffset):
    ```gcode
    SAVE_ZMOD_DATA LOAD_ZOFFSET=1
    ```
    *This command tells the system: "Load the Z-Offset from the saved settings, don't reset it."*

2.  After enabling this option, you can adjust the Z-Offset directly during printing in Fluidd/Mainsail or via the adjustment panel in GuppyScreen.

    <img width="418" height="73" alt="image" src="https://github.com/user-attachments/assets/96d644b3-9c52-44d1-9a7c-18ccbac61796" />

    <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/0f282f39-dec1-4488-9317-4e1395747277" />
3.  If you want to transfer z-offset from native screen to non-native screen mode, call the macro ```LOAD_ZOFFSET_NATIVE``` it will read the z-offset value from the native screen and apply it to non-native screen mode.

**Key Advantages:**
*   **Automatically saved.** Regardless of the adjustment method (screen or web interface), the Z-Offset value is automatically saved and automatically applied on the next print.
*   **No manual commands required.** You do NOT need to use the `Z_OFFSET_APPLY_PROBE` or `Z_OFFSET_APPLY_ENDSTOP` commands. Everything happens "under the hood."

#### About Z-Offset in Simple Terms:

*   **Adjust Z-Offset only during the first layer printing.**
*   **When working with the stock screen — adjust z-offset on it.**
*   **When working without the stock screen**, first execute the command ```SAVE_ZMOD_DATA LOAD_ZOFFSET=1```.
*   The system will save everything itself. You have nothing to worry about.

> [!CAUTION]
> You cannot use `Z_OFFSET_APPLY_ENDSTOP` on this printer.
>
> You cannot change ```[probe] z_offset: ``` in ```printer.cfg``` or ```printer.base.cfg```.
>
> Because the native screen and the ```START_PRINT``` macro load the offset at the start of printing.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#calibration)

</div>

---

### Input Shaper Calibration (Input Shaper)

**What are Input Shapers and Why are They Needed?**
When the printer moves quickly, it can vibrate, like a car at high speed. These vibrations are imprinted on your model as "ringing" or "ghosting" on the walls. Input Shapers are smart algorithms that "predict" and suppress these vibrations, allowing for faster printing without loss of quality.

Your printer has already automatically configured the input shapers during the first calibration, and this is sufficient for most tasks. But if you want to achieve maximum quality or understand how your printer works, you can look at the graphs and choose settings manually.

#### Important Note: The `FIX_SCV` Parameter

**What's the Problem?**
The graph and input shaper calculations in Klipper by default use the value `square_corner_velocity = 5`. But in our printer, this parameter is set to `25`. This discrepancy causes the calculated maximum acceleration values on the graphs to be several times higher than they should be.

**What to Do?**
1.  **Fix the Calculations:** Activate the fix for correct graph display [SAVE_ZMOD_DATA FIX_SCV=1](https://github.com/ghzserg/zmod/wiki/Global_en#fix_scv).
    ```gcode
    SAVE_ZMOD_DATA FIX_SCV=1
    ```

2.  **Improve Print Quality (Recommended):** Add the following line to the `mod_data/user.cfg` file:
    ```ini
    [printer]
    square_corner_velocity: 9
    ```
    *   **What does this do?** The printer will slightly reduce speed on sharp corners. This will marginally increase print time but significantly reduce vibrations and improve corner clarity.

You can simplify things. Enter ENABLE_PLUGIN name=recommend into the console. This command will enable the recommendations plugin, which already has FIX_SCV enabled and square_corner_velocity: 9 set.

Don't forget to restart your printer!

#### How to Use the `ZSHAPER` Macro

[ZSHAPER](https://github.com/ghzserg/zmod/wiki/Calibrations_en#zshaper) - this macro makes the printer vibrate at different frequencies, measures the response, and builds graphs to find the ideal input shaper parameters for the X and Y axes.

**Specifics for Printers with Low Memory (AD5M, AD5MPro):**
To avoid overloading the system, **calibrate the axes separately**.

*   `ZSHAPER` — calibrates both axes (X and Y).
*   `ZSHAPER X=1 Y=0` — calibrates only the X axis (faster and less load).
*   `ZSHAPER Y=1 X=0` — calibrates only the Y axis.

**Example Usage and Output:**
1.  Enter the command in the console to calibrate the Y axis:
    ```gcode
    ZSHAPER Y=1 X=0
    ```

2.  After the measurements are completed, you will get a report similar to this:
    ```
    // Recommended shaper is zv @ 53.2 Hz
    // Fitted shaper 'zv' frequency = 53.2 Hz (vibrations = 0.9%, smoothing ~= 0.074)
    // To avoid too much smoothing with 'zv', suggested max_accel <= 10200 mm/sec^2
    // Fitted shaper 'mzv' frequency = 54.2 Hz (vibrations = 0.0%, smoothing ~= 0.080)
    // To avoid too much smoothing with 'mzv', suggested max_accel <= 8700 mm/sec^2
    ```
    *   The system recommends the `zv` shaper because it has the least smoothing.
    *   But the `mzv` shaper completely suppresses vibrations (`0.0%`), although it requires slightly lower acceleration.

#### How to Interpret the Results and Make a Decision

**Where to View the Graphs?**
After executing `ZSHAPER`, graphs and CSV files will appear on the **"Configuration" -> mod_data** tab in your web interface (Fluidd/Mainsail).

<img width="996" height="596" alt="image" src="https://github.com/user-attachments/assets/7e1dbdf8-5de5-4ce6-8f4a-2c37b320b8b3" />

**Detailed Guide on Reading Graphs:** [https://github.com/Tombraider2006/klipperFB6/blob/main/accel_graph/readme.md](https://github.com/Tombraider2006/klipperFB6/blob/main/accel_graph/readme.md)

**Option 1: Accept the Automatic Setting**

If you are satisfied with everything, simply press the **`SAVE CONFIG & RESTART`** button in the web interface, and the printer will automatically write the recommended parameters.

<img width="324" height="68" alt="image" src="https://github.com/user-attachments/assets/9c76d5f7-0021-4e03-b495-6736f49dc1c9" />

<img width="745" height="389" alt="image" src="https://github.com/user-attachments/assets/b5b55e95-52af-4ee0-b34e-5bc6077d8d10" />

**Option 2: Manual Configuration**

In the example above, the `mzv` shaper seemed better because it completely eliminates vibrations. To use it, you need to manually add the settings to the `printer.cfg` file (in the `[input_shaper]` section):

```ini
[input_shaper]
shaper_type_y = mzv   ; Selected shaper type for Y axis
shaper_freq_y = 54.2  ; Resonant frequency for Y axis
```

**And Don't Forget About Acceleration!**
Since the selected `mzv` shaper allows using acceleration no more than 8700 mm/s², this value must be written to the `mod_data/user.cfg` file:

```ini
[printer]
max_accel: 8700 ; Maximum acceleration for X and Y axes
```

#### Quick Action Algorithm for Input Shaper Calibration:
1.  Execute `SAVE_ZMOD_DATA FIX_SCV=1` for correct calculations.
2.  Add `square_corner_velocity: 9` to `mod_data/user.cfg` for better quality.
3.  Start calibration for the desired axis, e.g., `ZSHAPER Y=1`.
4.  Study the graphs and console output.
5.  Either press `SAVE CONFIG`, or manually write your preferred `shaper_type` and `shaper_freq` to `printer.cfg`, and also `max_accel` to `mod_data/user.cfg`.
6.  Reboot the printer.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#calibration)

</div>

---

## Updating the Mod

If the mod displays ("Update ZMOD via USB"), you must update via USB, even if recently updated.

**Updating via USB preserves all data.**

**Simplest method:** Use the [ZFLASH](https://github.com/ghzserg/zmod/wiki/Zmod_en#zflash) macro. Insert the USB drive, reboot the printer, and run `ZFLASH`. The macro will:
- Check for the latest version.
- Download the latest release for your printer model.
- Verify checksums.
- Reboot the printer.
- Automatically install the update (keep the USB drive inserted for future updates).

After installation:
1. Go to Fluidd/Mainsail → `Settings` → `Software Update`.
2. Click `Check Updates` and install the latest ZMOD updates.

<img width="1239" height="535" alt="image" src="https://github.com/user-attachments/assets/b42c4ce9-1c0a-45c0-a20c-36919a27d648" />

If it shows a lot of errors, that's normal.

Plugins aren't included in the firmware and are downloaded separately.

Click `Check for updates`. Then restore and update all modules one by one. The printer will reboot during this process.

<img width="671" height="223" alt="image" src="https://github.com/user-attachments/assets/5744dc8e-ba58-4359-b78a-652be846ca07" />

**Version Compatibility:**
- The OS version (under `System` → `Distribution`) must match the first two digits of the ZMOD version (`Settings` → `Updates` → `ffm5/zmod`).
- **Mismatched versions cause instability.**

**Manual USB Update:**
1. Format a USB drive to FAT/FAT16/FAT32.
2. Copy the [mod file](https://github.com/ghzserg/zmod/releases/) to the USB root.
3. Power off the printer.
4. Insert the USB drive.
5. Power on the printer.
6. Wait for the reboot and installation.
7. Remove the USB drive.
8. Power cycle the printer.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#setup)

</div>

---

## Removing or Temporarily Disabling the Mod

- **[SKIP_ZMOD](https://github.com/ghzserg/zmod/wiki/Zmod_en#skip_zmod)**: Reboots without starting Moonraker/Fluidd.
- **[REMOVE_ZMOD](https://github.com/ghzserg/zmod/wiki/Zmod_en#remove_zmod)**: Fully uninstalls the mod.

**Recommended method:** Use the `REMOVE_ZMOD` macro. Use USB removal only if macros are unavailable.

Attention!
- If you are using Klipper 13, you must run ```UPDATE_MCU```. This will prevent the MCU and Klipper from being different versions.
- If you have enabled plugins, you must first disable them using ```DISABLE_PLUGIN name=g28_tenz```

**USB Removal:**
1. Format a USB drive to FAT/FAT16/FAT32.
2. Copy [flashforge_init.sh](https://github.com/ghzserg/zmod/blob/main/Native_firmware/rem_zmod/flashforge_init.sh) to the USB root.
3. Power off the printer.
4. Insert the USB drive.
5. Power on the printer.
6. Wait for three reboots.
7. Remove the USB drive.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#setup)

</div>

---

## Updating Stock Firmware

1. Disable all active plugins except `recommend`, `timelapse`, and `notify`:
   ```DISABLE_PLUGIN name=plugin_name```
2. If you are using **Klipper 13**, run ```UPDATE_MCU``` *before* updating the stock firmware. This prevents version mismatch issues between the MCU and Klipper.
3. Enable Chinese cloud services (if you wish to update via the stock touchscreen):
   ```SAVE_ZMOD_DATA CHINA_CLOUD=1```

**For [AD5X](https://github.com/ghzserg/zmod/wiki/AD5X), [zMod activation](https://github.com/ghzserg/zmod/wiki/R) is required via `AD5X-ENABLE-zmod.tgz` from a USB drive—after updating the stock firmware.**

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#setup)

</div>

---

## Support Mod Development

BTC `17wXTd9BqYp1K3zCLTxVyGLEXUDjf7XNLL`

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#setup)

</div>

---

## Boot Recovery

*Guide by [@darksimpson](https://t.me/darksimpson), [Alexander](https://github.com/DrA1ex), [@Ikaros413](https://t.me/Ikaros413), [@SoloMen88](https://t.me/SoloMen88)*

**Symptoms:** Printer freezes on boot screen and is unreachable via LAN.

[[/images/ff.jpg]]

Try restoring the firmware by installing a full firmware:
- [FF5M](https://github.com/ghzserg/zmod/wiki/R#installing-full-firmware-on-ff5m)
- [AD5X](https://github.com/ghzserg/zmod/wiki/R#installing-full-firmware-on-ad5x)

**Steps:**
1. **Unplug the printer.**
2. Prepare a **3.3V UART/USB converter** (ensure jumper is set to 3.3V).

[[/images/ch340.jpg]]

3. Open the printer’s rear panel.
4. Connect to the UART pins (RX, TX, GND — **do NOT connect 3.3V**).

[[/images/connect.jpg]]

**WARNING:** 5V input will damage the motherboard!

5. Connect the converter crosswise:
   - Converter RX → Printer TX
   - Converter TX → Printer RX
   - Converter GND → Printer GND

[[/images/connect_photo.jpg]]

6. Identify the new COM port in your OS.

[[/images/port.jpg]]

7. Open PuTTY:
   - **Connection type**: Serial
   - **Speed**: 115200
   - **COM port**: (e.g., COM6)

8. Power on the printer.
9. When `Hit any key to stop autoboot` appears, press **Enter**.

10. In U-Boot, run:
    ```
    setenv init /bin/sh
    boot
    ```

11. After Linux boots, remount the filesystem as writable:
    ```
    mount -t proc proc /proc
    mount -o remount,rw /
    ```

12. Fix corrupted files (e.g., delete faulty scripts):
    ```
    rm -f /etc/init.d/S01bad_script
    rm -f /opt/config/mod/.shell/S98camera
    ```

13. Save changes and reboot:
    ```
    sync
    reboot
    ```

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#setup)

</div>

---
