# [Calibration](#printer-calibration-for-beginners)

## Printer Calibration for Beginners

Generally, you don't need to calibrate anything, but if you want to fine-tune your printer, read on:

If you have completed the initial calibrations:
<img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/c0c63cc4-c4b3-46d4-a3e7-6485d8bf26bb" />

Then you already have:

- Configured z-offset
- A bed mesh ```MESH_DATA``` (taken at 60 degrees) - do not delete it if you use the stock screen, as it loads it for every print
- Extruder PID calibration for 240 degrees

But these settings are quite generic; few people print at a nozzle temperature of 240 degrees and a bed temperature of 60 degrees.

---

### Extruder PID Tuning

**Why is this needed?**
Imagine the extruder is an oven. If the temperature constantly "jumps," your dish (your part) might bake unevenly. PID calibration "teaches" your printer to maintain the exact temperature without fluctuations. This is critical for print quality.

**Important Note Before Starting!**
Calibrate specifically for the conditions you print in:

*   **Temperature:** The one you most often use for your filament (e.g., 210°C for PLA or 255°C for PETG).
*   **Cooling:** The part cooling fan should run at the same power as during normal printing.

**How to Perform the Calibration?**

-   Use the special command (macro) [PID_TUNE_EXTRUDER](/Calibrations/#pid_tune_extruder)

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

-   Use the macro [PID_TUNE_BED](/Calibrations/#pid_tune_bed)

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

---

### Bed Screws Leveling (BED_LEVEL_SCREWS_TUNE)

**Why is this needed?**
Your bed is held by several screws. If they are tightened differently, the bed becomes tilted, and the distance between it and the nozzle becomes uneven. This causes poor adhesion in some areas, and in others, the nozzle might even scrape the model. This calibration helps perfectly level the bed by adjusting its 4 mounting screws.

**How it Works:**

1.  The printer sequentially moves the nozzle to positions above each screw.
2.  It measures the distance to the bed and shows on the screen which screw to turn and in which direction.
3.  You adjust the screws according to the prompts.
4.  The process repeats until the bed is level.

**Configuration Parameters for [BED_LEVEL_SCREWS_TUNE](/Calibrations/#bed_level_screws_tune):**

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

---

### Precise Bed Mesh Leveling (AUTO_FULL_BED_LEVEL)

**Why is this needed?**
Even a perfectly leveled bed can have slight dips or bumps. A bed mesh (or "mesh calibration") is like a "topographic map" of your bed. The printer remembers these irregularities and will slightly move the Z-axis during printing to keep the nozzle at the perfect distance from the surface. This guarantees flawless first-layer adhesion across the entire bed area.

**Why This Specific Command?**
The built-in tools in Fluidd and Mainsail are not suitable for our printers because they:

*   Do not know how to work with the **strain gauge** (which is responsible for precise touch detection).
*   Do not perform **nozzle cleaning** beforehand to remove plastic ooze that could ruin measurement accuracy.

Our macro [AUTO_FULL_BED_LEVEL](/Calibrations/#auto_full_bed_level) accounts for both these features!

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

*   [START_PRINT](/Main/#start_print) - the main start print macro
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

---

### Adaptive Bed Leveling (KAMP)

**Why is this needed?**
[KAMP](/Calibrations/#kamp) is a smart system that builds a bed mesh not over the entire area, but only in the zone where your models are located! This significantly speeds up print preparation, especially on large printers, while retaining all the benefits of a precise bed mesh.

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

Activate this option to make the printer use KAMP wherever possible [SAVE_ZMOD_DATA USE_KAMP=1](/Global/#use_kamp).

```gcode
SAVE_ZMOD_DATA USE_KAMP=1
```

Configure Orca:

- `Process Profile` -> `Other` -> `Custom G-code` -> `Exclude objects` check the box
- `Process Profile` -> `Other` -> `Custom G-code` -> `Label objects` check the box

<img width="285" height="171" alt="image" src="https://github.com/user-attachments/assets/faceef98-2791-4975-bf72-425f4a2b1dfa" />

**2. Enabling Calibration Before Each Print**

If you want the printer to automatically build a bed mesh before starting each job (e.g., when frequently changing plates), activate this function [SAVE_ZMOD_DATA PRINT_LEVELING=1](/Global/#print_leveling).

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

Add this setting to make the printer use the same area for nozzle cleaning where it just took the bed mesh. This saves space and time [SAVE_ZMOD_DATA CLEAR=LINE_PURGE](/Global/#clear).

```gcode
SAVE_ZMOD_DATA CLEAR=LINE_PURGE
```

#### Summary: How to Set Up KAMP for Perfect Printing

To enable smart bed mesh leveling before each print, run the following command once:

```gcode
SAVE_ZMOD_DATA USE_KAMP=1 PRINT_LEVELING=1 CLEAR=LINE_PURGE
```

Now, before each print, the printer will take a bed mesh only where there are objects to print.

---

### How Z-Offset Works on Your Printer

**What is Z-Offset?**
Simply put, it is the **precise distance between the nozzle tip and the bed** at the moment the printer considers them to have "touched." The correct Z-Offset ensures that the first layer of plastic adheres perfectly to the bed – not too low (the nozzle will scrape the bed) and not too high (the plastic won't stick). [Learn more](/FAQ/#how-does-z-offset-work)

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

1.  To make the printer remember the Z-Offset from the web interface and GuppyScreen, you need to activate a special setting once [SAVE_ZMOD_DATA LOAD_ZOFFSET=1](/Global/#load_zoffset):
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

!!! danger
    You cannot use `Z_OFFSET_APPLY_ENDSTOP` on this printer.
    
    You cannot change ```[probe] z_offset: ``` in ```printer.cfg``` or ```printer.base.cfg```.
    
    Because the native screen and the ```START_PRINT``` macro load the offset at the start of printing.

---

### Input Shaper Calibration (Input Shaper)

**What are Input Shapers and Why are They Needed?**
When the printer moves quickly, it can vibrate, like a car at high speed. These vibrations are imprinted on your model as "ringing" or "ghosting" on the walls. Input Shapers are smart algorithms that "predict" and suppress these vibrations, allowing for faster printing without loss of quality.

Your printer has already automatically configured the input shapers during the first calibration, and this is sufficient for most tasks. But if you want to achieve maximum quality or understand how your printer works, you can look at the graphs and choose settings manually.

#### Important Note: The `FIX_SCV` Parameter

**What's the Problem?**
The graph and input shaper calculations in Klipper by default use the value `square_corner_velocity = 5`. But in our printer, this parameter is set to `25`. This discrepancy causes the calculated maximum acceleration values on the graphs to be several times higher than they should be.

**What to Do?**

1.  **Fix the Calculations:** Activate the fix for correct graph display [SAVE_ZMOD_DATA FIX_SCV=1](/Global/#fix_scv).
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

[ZSHAPER](/Calibrations/#zshaper) - this macro makes the printer vibrate at different frequencies, measures the response, and builds graphs to find the ideal input shaper parameters for the X and Y axes.

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

---
