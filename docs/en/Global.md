<h1 align="center">Global param</h1>

A macro is a small program written in Klipper/Gcode.

It can be called from:

- A GCODE file
- The Fluidd/Mainsail console (press the English letter `C` in Fluidd)

!!! note
    *The value in parentheses is the default value*

---

### LANG

Set the language for ZMOD operation.

- LANG - language: en (English), ru (Russian), de (German), fr (French), it (Italian), es (Spanish), zh (Chinese), ja (Japanese), ko (Korean), pt (Portugal), cs (Czech), tr(Turkish)

Example:
```
LANG LANG=en
```

---
### SET_TIMEZONE

Change the timezone.

- ZONE - time zone (Asia/Yekaterinburg)

---
### NOZZLE_CONTROL

Control nozzle collision with the bed or part detachment.

Emergency shutdown if weight exceeds the set limit.

- WEIGHT - weight in grams (1500)

Settings persist after reboot.

Set `NOZZLE_CONTROL WEIGHT=0` to disable this feature.

*Control is disabled until the macro is first called.*

When using the native screen, macro execution reboots the printer.

Without the native screen, restarts Klipper (configuration files are modified).

Works automatically, but additional macros are available for Gcode:

- `ZCONTROL_ON` - enable control
- `ZCONTROL_OFF` - disable control
- `ZCONTROL_STATUS` - check status
- `ZCONTROL_PAUSE` - pause on trigger (only after command queue clears; avoid using on initial layers)
- `ZCONTROL_ABORT` - abort Klipper on trigger
- `ZCONTROL_AUTO` - On trigger, stop Klipper (if Z height < `ZCONTROL_Z`) or call PAUSE if z >= `ZCONTROL_Z`
- `ZCONTROL_Z Z=10` - Set Z height.
- `SAVE_ZMOD_DATA ZCONTROL_Z=10` - Save Z height. If you don't want to enable pause, set ```SAVE_ZMOD_DATA ZCONTROL_Z=230```

To enable nozzle control on initial layers, add `ZCONTROL_PAUSE` in the slicer at the desired layer.

---

### GET_ZMOD_DATA

Retrieve ZMOD global parameters/flags.
After execution, the console displays saved parameters applied at runtime.

`Fluidd` -> `Macros` -> `Main` -> `ZMOD PARAMETERS`

---

### GLOBAL

Simplified management of global parameters. Only parameters that can be changed with a button click are available. Parameters that require entering a number, specifying a file name, etc. are not controlled by this macro.

After changing parameters, it is recommended to restart the printer.

---

### SAVE_ZMOD_DATA

Save ZMOD global parameters/flags (applied during every print).

Do not add this macro to start/end Gcode or Gcode files. Call it from the Fluidd/Mainsail console. Parameters are saved to `mod_data/variables.cfg` after shutdown (**do not edit manually**).

**To edit parameters:**

- Go to `Fluidd` -> `Macros` -> `System` -> `SAVE ZMOD PARAMETERS`, select the parameter, modify it, and click `SEND`.
- Alternatively, enter commands directly in the Fluidd console, e.g., `SAVE_ZMOD_DATA CLOSE_DIALOGS=2`.

Second option. Write the required command in the Fluidd console, for example: `SAVE_ZMOD_DATA CLOSE_DIALOGS=2`

[View saved parameters](/Global/#get_zmod_data)

---

### Print start/bed mapping parameters [START_PRINT]:

##### MIDI_START

Play MIDI on print start (""), 0 to disable.

Example: `SAVE_ZMOD_DATA MIDI_START=Pain-Shut-your-mouth.mid`

---
##### PRECLEAR

Enable nozzle pre-clearing in CLEAR_NOZZLE: 0 (no), 1 (yes) (0).

Example: `SAVE_ZMOD_DATA PRECLEAR=0`

---
##### PRINT_LEVELING

Build bed mesh before each print (using native screen if enabled): 0 (no), 1 (yes) (0).
*For native screen bed leveling, enable "Local Network Only" via the printer menu: Settings -> WiFi icon -> Network Mode.*

Example: `SAVE_ZMOD_DATA PRINT_LEVELING=1`

---
##### USE_KAMP

Use Adaptive Mesh (KAMP) instead of full bed mesh where possible: 0 (no), 1 (yes) (0).
Recommended to set `SAVE_ZMOD_DATA CLEAR=LINE_PURGE` to align purge location with KAMP mesh.

Example: `SAVE_ZMOD_DATA USE_KAMP=1`

---

##### MESH_TEST

Test the bed mesh before printing:

- 0 - No
- 1 - Test WITHOUT Z-Offset auto-tuning (default)
- 2 - Test WITHOUT Z-Offset auto-tuning, if the mesh doesn't match, run KAMP
- 3 - Test WITH Z-Offset auto-tuning, with nozzle cleaning
- 4 - Test WITH Z-Offset auto-tuning, with nozzle cleaning, if the mesh doesn't match, run KAMP

**Z-Offset Auto-Tuning**

Algorithm for automatic Z-Offset calibration:

1.  **Source data:** The printer's memory stores a bed mesh (typically 25 points) obtained during the last leveling procedure.
2.  **Preparation:**

    *   Nozzle is heated to the working temperature, wiped on the bed, and cooled down to 151°C.

3.  **Measurement point selection:**

    *   The **center** point of the mesh is used.

4.  **Measurement and comparison:**

    *   A new probe measurement is performed at the selected point.
        *   The obtained value is compared with the value saved in the bed mesh.

5.  **Offset correction:**

    *   If the discrepancy is **less than 0.3 mm**, the difference is added to the current Z-Offset value.
        *   If the discrepancy is **greater than or equal to 0.3 mm**, the system considers the saved mesh outdated and, if the settings allow, automatically initiates a bed re-leveling procedure (KAMP).

**Without Z-Offset Auto-Tuning**

Bed mesh validation algorithm:

1.  **Measurement:** A standard probe measurement is performed at the current point.
2.  **Validation:** The obtained Z value is checked for consistency with the loaded mesh.
3.  **Criterion:** The value must be within the range from (mesh minimum - 0.21 mm) to (mesh maximum + 0.21 mm).
4.  **Result:**

    *   **Success:** The mesh is considered correct, printing continues.
        *   **Failure:** A warning is issued and printing stops or, if settings allow, automatically initiates a bed re-leveling procedure (KAMP).

**Notes:**

*   This check is a rough estimate. It is intended to detect critical errors, for example, when a mesh taken for a PEI sheet is loaded for thick glass and vice versa.
*   **Do not rely on this check as absolute protection.**
*   When using smart cleaning (KAMP), the heating wait occurs near the cleaning location, not in the corner of the bed.

Example: `SAVE_ZMOD_DATA MESH_TEST=0`

---

##### FORCE_MD5

Igor Polunovskiy

Verify file MD5 hash and delete on mismatch: 0 (disable), 1 (enable) (1).

*Add [addMD5.bat](https://github.com/ghzserg/FF/releases/download/R/addMD5.bat) or
[addMD5.sh](https://github.com/ghzserg/FF/releases/download/R/addMD5.sh) for Mac/Linux to your post-processing scripts* (don't forget to add executable permissions to the file `chmod +x addMD5.sh`) or
[addMD5.py](https://github.com/ghzserg/FF/releases/download/R/addMD5.py) it's located in mod. [More details](/ru/System/#check_md5)

You can also use [Go binaries built for the main architectures](https://github.com/asd2003ru/addmd5/releases/) from @asd2003ru:

- `addmd5-darwin-amd64` (MacOS Intel). Don't forget to run ```chmod +x addmd5-darwin-amd64```
- `addmd5-darwin-arm64` (MacOS Silicon). Don't forget to run ```chmod +x addmd5-darwin-arm64```
- `addmd5-linux-amd64` (Linux). Don't forget to run ```chmod +x addmd5-linux-amd64```
- `addmd5-windows-amd64.exe` (Windows)

Download it to your computer and then add it to Orca. `Process Profile` -> `Other` -> `Post-Processing Scripts`.

Here are the options for adding:

- ```"С:\path_to_file\addMD5.bat";```
- ```"C:\python_folder\python.exe" "C:\Scripts\add_md5.py";```
- ```"/home/user/addmd5-linux-amd64";```

Example: `SAVE_ZMOD_DATA FORCE_MD5=1`

---
##### DISABLE_SKEW

1 (disable SKEW correction), 0 (load `skew_profile` via `SKEW_PROFILE LOAD=skew_profile`) (1).

[Details](https://www.klipper3d.org/Skew_Correction.html)

Example: `SAVE_ZMOD_DATA DISABLE_SKEW=1`

---
##### LOAD_ZOFFSET

Load Z-offset from global parameters saved via SET_GCODE_OFFSET: 1 (yes), 0 (no) (1).

[How Z-Offset Works](/FAQ/#how-does-z-offset-work)

Example: `SAVE_ZMOD_DATA LOAD_ZOFFSET=0`

---
##### DISABLE_PRIMING

Disable nozzle priming via extrusion: 0 (no), 1 (yes) (0).

Example: `SAVE_ZMOD_DATA DISABLE_PRIMING=0`

---
##### CLEAR

Select nozzle purge algorithm (LINE_PURGE):

- _CLEAR1 - Orca-style (may scratch bed with KAMP)
- _CLEAR2 - FF group style (may scratch bed with KAMP)
- _CLEAR3 - FF group alternative (may scratch bed with KAMP)
- _CLEAR4 - Shreider's code (top-right to bottom-right)
- _CLEAR_TRAP - For brushes (top-right to bottom-right)
- LINE_PURGE - KAMP purge

Custom purge macros can be added to `mod_data/user.cfg`.

Example: `SAVE_ZMOD_DATA CLEAR=LINE_PURGE`

---

### Print end/cancel parameters [END_PRINT]:

##### MIDI_END

Play MIDI on print end (""), 0 to disable.

Example: `SAVE_ZMOD_DATA MIDI_END=Pain-Shut-your-mouth.mid`

---
##### CLOSE_DIALOGS

Automatically close dialogs after print end/cancel: 0 (no), 1 (yes, slow), 2 (yes, fast) (0).
*For fast closing, enable "Local Network Only" via the printer menu.*

Example: `SAVE_ZMOD_DATA CLOSE_DIALOGS=2`

---
##### STOP_MOTOR

Automatically disable motors 25 seconds after print end/cancel: 0 (no), 1 (yes) (1).

Example: `SAVE_ZMOD_DATA STOP_MOTOR=1`

---
##### AUTO_REBOOT

Automatically reboot the printer after printing completes (0):

- 0 - no reboot
- 1 - reboot the printer via the `REBOOT` command
- 2 - without the native screen: reboot the firmware via `FIRMWARE_RESTART`; with the screen: reboot the printer via the `REBOOT` command

Example: `SAVE_ZMOD_DATA AUTO_REBOOT=0`

---

### System-wide parameters:

##### MOTION_SENSOR

Use a [filament motion sensor](https://aliexpress.ru/item/1005007480443587.html) instead of the filament presence sensor (0):

- 0 - no
- 1 - yes

When using the filament motion sensor, disable it on the native screen; otherwise, printing will pause.

Example: `SAVE_ZMOD_DATA MOTION_SENSOR=1`

---

##### SILENT

AD5X only

Do not show the color selection window when starting printing

- 0 - show the window (default)
- 1 - do not show the window, use previously set colors
- 2 - do not show the window, do not use IFS

Example: `SAVE_ZMOD_DATA SILENT=0`

---

##### AUTOINSERT

AD5X Only

Automatically Load Filament

- 0 - Do not automatically load filament
- 1 - Automatically load filament (default)

Example: `SAVE_ZMOD_DATA AUTOINSERT=0`

---

##### USE_TRASH_ON_PRINT

AD5X only

Only when running without the native display

Use trash on color change during printing

- 0 - do not use
- 1 - use (default)

Example: `SAVE_ZMOD_DATA USE_TRASH_ON_PRINT=0`

---

##### REMOVE_FILAMENT

AD5X only

Only when running without the native display

Unload filament after print completion:

- 0 — do not unload (default)
- 1 — unload

Example: `SAVE_ZMOD_DATA REMOVE_FILAMENT=1`

---

##### FIX_SCV

Fix incorrect SCV ([square_corner_velocity](https://www.klipper3d.org/Config_Reference.html#printer)) when rendering acceleration graphs and calculating input shapers.

- 0 - keep the parameter as in stock (5)
- 1 - use `square_corner_velocity` from `mod_data/user.cfg` or `printer.base.cfg`

Example: `SAVE_ZMOD_DATA FIX_SCV=1`

In our printer, `square_corner_velocity: 25`, but shaper graph calculations and accelerations are based on `SCV = 5`.

This primarily affects displayed accelerations and calculated smoothing levels.
`shaper_type_x`, `shaper_freq_x`, `shaper_type_y`, `shaper_freq_y` remain unchanged.

However, with correct calculations, the resulting accelerations drop by approximately half.

Recommendation: add the following to `mod_data/user.cfg`:
```
[printer]
square_corner_velocity: 9
```
This reduces cornering speeds and generally improves print quality with a slight speed trade-off.

---

##### WIFI

On some firmware versions, Wi-Fi occasionally fails to start.

To fix this, connect to a Wi-Fi network via the native screen.

Execute `SAVE_ZMOD_DATA WIFI=1`

Then disable Wi-Fi on the native screen.

- 0 — use Wi-Fi from the native screen
- 1 — use Wi-Fi through zMod

---

##### FIX_E0011

Common causes of E0011 error (Timer too close):

- Host did not respond within the allotted time (0.025 sec)
- MCU did not respond within the allotted time (0.025 sec)

Specific causes:

- Frozen Nations MCU mainboard or eboard. `Lost communication with MCU 'mcu'`. Solution: Reboot. Replace the mainboard (`mcu`) or extruder board (`eboard`).
- Host CPU overload (shaper calculations/graph rendering).
- EMMC overload (git operations, backups, large file uploads during printing, etc.).
- Insufficient RAM. Solution: Re-solder the CPU and upgrade to 256MB RAM.
- Damaged extruder cable. Solution: Replace/fix the cable.
- Loose extruder board cable connection. Solution: Replace the extruder board.
- SWAP data loading (SWAP resides on EMMC, which operates at 10 MB/s; SWAP data during shaper calculations can reach 25MB). Solution: Disable SWAP if you have 256MB RAM via `SAVE_ZMOD_DATA USE_SWAP=0`.
- MCU firmware crash. Solution: Reflash the MCU via [factory reset](/Setup/#restoring-printer-to-factory-settings-required-for-mod-installation) or use the [UPDATE_MCU](/System/#update_mcu) mod.

Fix E0011 and `Communication timeout during homing` errors. Changing this parameter will reboot the printer. 0-no, 1-yes (0):

- 0 - keep the stock parameter (0.025)
- 1 - set the parameter to 0.1

Example: `SAVE_ZMOD_DATA FIX_E0011=1`

This error may also occur:

- Large volume of model exclusions: Solution `Process profile` -> `Other` -> `Output G-cod` -> `Exclude models` uncheck.
- If you disabled swap on FF5M/FF5MPro.

  Run the `MEM` macro and see if there is swap and what size it is.

  Enable swap if it is disabled: ```SAVE_ZMOD_DATA USE_SWAP=1```

- If you are using FF5M/FF5MPro, run a full test. This includes PID calibration, removing the table map, and removing shapers simultaneously.

  It is better to carry out all calibrations [here according to this instructions](/SetupCalibrations/#printer-calibration-for-beginners)

The `Communication timeout during homing` error may occur due to high communication latency between the host and MCUs. Round-trip time should consistently stay below 10ms. Temporary latency spikes can cause homing failures.

`TRSYNC_TIMEOUT` is a Klipper parameter (default: 0.025 sec) that compensates for system delays.

Stock file `/opt/klipper/klippy/mcu.py` sets `TRSYNC_TIMEOUT = 0.025`. The patch changes it to `TRSYNC_TIMEOUT = 0.1`.

**How to fix on stock firmware:**

- Format a USB drive as FAT32.
- Save the `flashforge_init.sh` file to the USB:
    - [Fix parameter Adventurer5M](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-e0011-on.tgz)
      - [Restore stock parameter Adventurer5M](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-e0011-on.tgz)
      - [Fix parameter Adventurer5MPro](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-e0011-on.tgz)
      - [Restore stock parameter Adventurer5MPro](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-e0011-on.tgz)

- Power off the printer.
- Insert the USB into the printer.
- Power on the printer (it will beep loudly).
- Wait for reboot.
- Remove the USB.
- Reprint the problematic file; E0011 should no longer occur.

**Manual fix on stock firmware:**

- Install [root](https://wiki.zmod.link/Native_FW/#root).
- Use [WinSCP](https://winscp.net/eng/download.php) to SSH into the printer.
- Edit `/opt/klipper/klippy/mcu.py`.
- Locate `TRSYNC_TIMEOUT = 0.025` and change it to `TRSYNC_TIMEOUT = 0.1`.
- Save the file and reboot the printer.

---
##### FIX_E0017

Fix E0017 error. Changing this parameter will reboot the printer. 0-no, 1-yes (1):

In the stock file `/opt/klipper/klippy/toolhead.py`, `LOOKAHEAD_FLUSH_TIME = 0.5`. Original Klipper uses `LOOKAHEAD_FLUSH_TIME = 0.250`. Our mod works best with `LOOKAHEAD_FLUSH_TIME = 0.150`.

- 0 - set to stock value
- 1 - set to 0.150

Example: `SAVE_ZMOD_DATA FIX_E0017=1`

**How to fix on stock firmware:**

- Format a USB drive as FAT32.
- Save the appropriate file to the USB:
    - [Adventurer5M-e0017-4.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-e0017-4.tgz) for FlashForge 5M
      - [Adventurer5MPro-e0017-4.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-e0017-4.tgz) for FlashForge 5M Pro

- Power off the printer.
- Insert the USB into the printer.
- Power on the printer (it will beep loudly).
- Wait for reboot.
- Remove the USB.
- Reprint the problematic file; E0017 should no longer occur.

**Manual fix on stock firmware:**

- Install [root](https://wiki.zmod.link/Native_FW/#root).
- Use [WinSCP](https://winscp.net/eng/download.php) to SSH into the printer.
- Edit `/opt/klipper/klippy/toolhead.py`.
- Locate `LOOKAHEAD_FLUSH_TIME = 0.5` and change it to `LOOKAHEAD_FLUSH_TIME = 0.150`.
- Save the file and reboot the printer.

---
##### LED

LED brightness at startup (50).

Example: `SAVE_ZMOD_DATA LED=50`

---
##### MIDI_ON

Play MIDI at startup (""). Use `0` to disable.

Example: `SAVE_ZMOD_DATA MIDI_ON=Pain-Shut-your-mouth.mid`

---
##### NEW_SAVE_CONFIG

Use alternative SAVE_CONFIG (invokes `SAVE_CONFIG` without freezing the native screen). [NEW_SAVE_CONFIG](/Main/#new_save_config) for PID calibration: 0-no, 1-yes (0).

Example: `SAVE_ZMOD_DATA NEW_SAVE_CONFIG=0`

---
##### USE_SWAP

Enable SWAP (1):

- 0 - no (*Only for upgraded 256MB RAM*)
- 1 - yes, on EMMC
- 2 - yes, prefer USB FLASH

Example: `SAVE_ZMOD_DATA USE_SWAP=1`

---
##### CHINA_CLOUD

Enable Chinese cloud services: 0-no, 1-yes (1).

Example: `SAVE_ZMOD_DATA CHINA_CLOUD=0`

[Disable Chinese clouds](/Recomendations/#disable-chinese-cloud-services)

Even if all cloud options are disabled via the screen, the printer still attempts to send photos, videos, and telemetry to Chinese servers.

Setting this parameter to 0 partially disables these "features."

**If Chinese clouds are disabled, the printer will not check for stock firmware updates.**

To update stock firmware, enable Chinese clouds via `SAVE_ZMOD_DATA CHINA_CLOUD=1`, reboot, and proceed with the update.

Instead, you can use:

- [zmod.link](/ru/Zmod/#zlink) - cloud, for managing printers via Fluidd/Mainsail.
- [Telegram bot](/ru/Macros/).

**To disable Chinese clouds on stock firmware:**

- Format a USB drive as FAT32.
- Place [flashforge_init.sh](https://github.com/ghzserg/zmod/blob/main/Native_firmware/cloud/rem/flashforge_init.sh) on the USB.
- Power off the printer.
- Insert the USB into the printer.
- Power on the printer (it will reboot once).
- Remove the USB.

**To enable Chinese clouds on stock firmware:**

- Format a USB drive as FAT32.
- Place [flashforge_init.sh](https://github.com/ghzserg/zmod/blob/main/Native_firmware/cloud/orig/flashforge_init.sh) on the USB.
- Follow the same steps as above.

---
##### NICE

Set Klipper process priority: 1 (lowest) to 40 (highest) (20).

Example: `SAVE_ZMOD_DATA NICE=20`

Higher priority allocates more resources to Klipper but may cause Moonraker and camera disconnections.

For Linux users:
```
NICE=20
grep -q "^nice = " /opt/config/mod_data/variables.cfg && NICE=$(grep "^nice = " /opt/config/mod_data/variables.cfg | cut -d "=" -f2| awk '{print $1}')
NICE=$((20-$NICE))
[ $NICE -ge 20 ]  && NICE=19
[ $NICE -lt -20 ] && NICE=-20
renice $NICE $(ps |grep klippy.py| grep -v grep| awk '{print $1}')
```

---
##### DISPLAY_OFF_TIMEOUT

Set the timeout (in seconds) to turn off the native screen when not in use. Default: 180.

Note: The native screen needs at least 5 seconds to configure WiFi.

Example: `SAVE_ZMOD_DATA DISPLAY_OFF_TIMEOUT=120`

---
##### PRO_POWEROFF_TIMEOUT

Set the timeout (in minutes) for FF5M Pro to auto-power off. Default: 0 (disabled).

Example: `SAVE_ZMOD_DATA PRO_POWEROFF_TIMEOUT=10`

---

##### SAVE_MOONRAKER

- 0 - Load macro button layouts from ZMOD (default).
- 1 - Allow saving macro button changes locally in Fluidd/Moonraker.

Locally saved macros are stored in a separate section.

Example: `SAVE_ZMOD_DATA SAVE_MOONRAKER=1`

---

##### SAVE_FILAMENT_SENSORS

- 0 - Do not save the state of filament sensors after a reboot; they will always be enabled (default)
- 1 - Save the state of the sensors after a reboot. If you disable a sensor, it will also be disabled after a reboot.

Example: `SAVE_ZMOD_DATA SAVE_FILAMENT_SENSORS=1`
