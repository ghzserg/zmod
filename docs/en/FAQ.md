# FAQ
## Frequently Asked Questions

!!! note
    Installed the mod.
    
    Don't want to figure anything out - print as you did before.
    
    No need to configure or change anything anywhere.
    
    Decided you're ready to move forward - proceed by reading the documentation.

---

## Configuration Storage

Access the **mod_data** folder via Fluidd web interface:
`Configuration` → `Configuration Files` → `mod_data`

- Custom Klipper settings go into `mod_data/user.cfg`, which can override/supplement `printer_base.cfg` and zMod files.
- Custom Moonraker settings go into `mod_data/user.moonraker.conf`.
- Custom MIDI files are stored in `mod_data/midi/`.
- Global mod settings are saved via the [SAVE_ZMOD_DATA](/Global/#save_zmod_data) macro.
- Shutdown scripts are stored in `mod_data/power_off.sh`.
- Power on scripts are stored in `mod_data/power_on.sh`.

**You cannot make changes to zmod and plugin files**, as this will break the update system.

Any function can be overridden in `mod_data/user.cfg` or `printer.cfg`

---

## Known Peculiarities:

- During actions like `M109` (extruder heating), `M190` (bed heating), PID calibration, or any gcode-pausing task, the stock screen freezes.
- Restarting Klipper freezes the stock screen (use [NEW_SAVE_CONFIG](/Main/#new_save_config) for restarts).
- After canceling a print, press "OK" on the stock screen (use [CLOSE_DIALOGS](/Main/#close_dialogs) or [FAST_CLOSE_DIALOGS](/Main/#f
ast_close_dialogs)).

- The stock screen always loads the `DEFAULT_MESH` profile when starting a print and deletes the `Default` profile post-print.

---

## Screenless Version Notes:

- Remove all start gcode and use [START_PRINT](/Main/#start_print) and [END_PRINT](/Main/#end_print) macros.
- Stock camera disabled; use the alternative via [CAMERA_ON](https://github.com//Zmod/#camera_on).
- Manually set [Z_OFFSET] in [START_PRINT](/Main/#start_print) or use [LOAD_ZOFFSET](/Global/#load_zoffset) to load saved offsets.
- If you want to transfer z-offset from native screen to non-native screen mode, call the macro ```LOAD_ZOFFSET_NATIVE``` it will read the z-offset value from the native screen and apply it to non-native screen mode.
- Bed mesh `auto` loads automatically on startup.
- FlashForge protocol is unsupported (handled by the screen). Use "Octo/Klipper":
    - Protocol: `Octo/Klipper`
      - Hostname: `printer_IP:7125`
      - URL: `printer_IP` or `printer_IP:80`

---

### How is ZMOD different from KlipperMod/native firmware?

Differences between KlipperMod and ZMOD:

- KlipperMod uses pure Klipper with minimal Flashforge 5m (pro)-specific changes.
- ZMOD uses the standard Klipper from the native firmware, as well as Klipper 13.
- KlipperMod uses KlipperScreen as a printer screen.
- ZMOD uses the native screen or GuppyScreen instead of KlipperScreen.
- KlipperMod uses Moonraker-timelapse.
- ZMOD uses moonraker-telegram-bot on an EXTERNAL host with timelapse support and plugin timelapse

Different philosophies:

- KlipperMod is essentially an alternative firmware implementation.
- ZMOD has minimal intervention in the native firmware. All native firmware features are preserved.

This is why ZMOD won't include G17, G18, G19 - even though it's simple. There won't be updates to native Klipper, no renaming or changes to standard macros, settings, pin names, etc.

ZMOD is NOT based on KlipperMod and is NOT its evolution. However, ZMOD uses some macros and scripts from KlipperMod and incorporates some of its developments. Don't expect ZMOD to behave similarly to KlipperMod.

**ZMOD is binary incompatible with KlipperMod.**

#### What's in KlipperMod but not in ZMOD:

*   [KlipperScreen](https://klipperscreen.readthedocs.io/en/latest/) - screen for the printer. In ZMOD, native screen or GuppyScreen is used instead of KlipperScreen
*   [Moonraker-timelapse](https://github.com/mainsail-crew/moonraker-timelapse) - ZMOD uses Telegram bot and [plugin Timelapse](https://github.com/ghzserg/timelapse/)
*   Network configuration via iwd/wpa_supplicant (in case of guppyscreen) - in ZMOD network configuration is done through the native screen, network startup is possible even without the native screen

#### What's in ZMOD but not in KlipperMod:

*   [AD5X](/ru/AD5X/) support
*   Support for [the following languages](/Global/#lang): English, German, French, Italian, Spanish, Chinese, Japanese, Korean, Portugal, Russsian
*   Native screen support
*   [Print recovery after power loss](/Zmod/#zrestore)
*   [Shaper calibration with graphs](/Calibrations/#zshaper) considering [SCV](/Global/#fix_scv) ([square_corner_velocity](https://www.klipper3d.org/Config_Reference.html#printer))
*   [File/permission/symlink check and repair for the native filesystem](/System/#check_system)
*   Automatic updates for `Fluidd`/`Mainsail`/`Moonraker` and ZMOD over the network
*   [Entware](/FAQ/#entware-in-zmod-how-to-use-it)
*   Fixed [E0017 error](/Global/#fix_e0017)
*   Additionally, GuppyScreen supports: PID calibration, damper control, firmware rollback, nozzle cleaning, strain gauge reset, screw adjustment, ColdPull, enhanced bed leveling
*   Fixed driver cooling fans operation. They automatically turn on when motors are running. On native firmware - only during printing.
*   Adaptive bed leveling [KAMP](/Calibrations/#kamp)
*   PID calibration for [extruder](/Calibrations/#pid_tune_extruder) and [bed](/Calibrations/#pid_tune_bed), including via GuppyScreen
*   Implemented [COLDPULL](/Filament/#coldpull) (nozzle cleaning) without force. Implementation of [this algorithm](https://t.me/FF_5M_5M_Pro/2836/447172)

#### What's in ZMOD but not in native firmware:

- Moonraker/Fluidd/Mainsail support
- Klipper 13 support
- Telegram bot support
- All features listed in the comparison with KlipperMod
- [The native firmware sends a lot of data to Chinese servers](https://github.com/FlashForge/Orca-Flashforge/issues/26), this can be avoided by using zmod with GuppyScreen

---

### What is a MACRO? How to Run, Download, and Use It

A macro is a small program written in Klipper/Gcode.

It can be called:

- From a GCODE file
- From the Fluidd/Mainsail console
*hedgehog*

[List of macros](/Macros/)

---

### I'm using the screen version. I send a file to print, but the screen shows temperature 0 0 and printing doesn't start.

Add these two lines at the very beginning of the start code:
```
M190 S[bed_temperature_initial_layer_single]
M104 S[nozzle_temperature_initial_layer]
```

Without these lines, the printer screen doesn't know the target temperatures for the nozzle and bed.
*hippopotamus*

---

### Do I need to change anything in the start code?

If using the native screen, no changes are needed.

For operation without the native screen/Guppy (also recommended with the screen), replace the entire start code with:
```
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single]
M104 S[nozzle_temperature_initial_layer]
SET_PRINT_STATS_INFO TOTAL_LAYER=[total_layer_count]
```

```START_PRINT EXTRUDER_TEMP=... BED_TEMP=...``` should be written on one line

And the end code with:
```
END_PRINT
```

For correct layer counting in Fluidd, add to the before layer change code:
```
SET_PRINT_STATS_INFO CURRENT_LAYER={layer_num + 1}
```

To enable auto-leveling for every print, enter once in Fluidd/Mainsail console:
```
SAVE_ZMOD_DATA CLOSE_DIALOGS=2 PRINT_LEVELING=1 USE_KAMP=1
```
Via the printer screen menu: `Settings` -> `WiFi icon` -> `Network Mode` -> enable `Local Networks Only`.

Read the documentation for [START_PRINT](/Main/#start_print) and [SAVE_ZMOD_DATA](/Global/#save_zmod_data) to utilize advanced ZMOD features.

For firmware retraction, read [the documentation](/FAQ/#what-is-firmware-retraction) and add to `Filament Profile` -> `Advanced` -> `Filament Start G-code`:
```
SET_RETRACTION RETRACT_LENGTH=[filament_retraction_length]
```

*raccoon*

---

### How does Z-Offset work?

When using the screen, the mod doesn't interfere with z-offset. The z-offset saved on the screen is used.

The offset for native and non-native screens is not the same, and each has its own unique behavior and is configured separately.

Use ```LOAD_ZOFFSET_NATIVE``` to copy the Z-offset from native screens to non-native screens.

Z-offset adjustments via Fluidd/Mainsail/GuppyScreen only affect until reboot. Changing it without understanding nozzle movement is not recommended.

Any `SET_GCODE_OFFSET` call (automatically triggered when adjusting Z-offset from Fluid/Mainsail/GuppyScreen) saves the current z-offset to the mod's global parameters. This saved value is used only if the [LOAD_ZOFFSET](/Global/#load_zoffset) global parameter is enabled (disabled by default; enable with `SAVE_ZMOD_DATA LOAD_ZOFFSET=1`), native screen isn't used, and the [START_PRINT](/Main/#start_print) macro is utilized.

Z-offset can also be set via [START_PRINT](/Main/#start_print) parameters:

- Z_OFFSET - Set Z offset (0.0)

### What options are available for bed leveling?

To enable auto-leveling for every print, enter once in Fluidd/Mainsail console:
```
SAVE_ZMOD_DATA CLOSE_DIALOGS=2 PRINT_LEVELING=1 USE_KAMP=1
```

The native screen always uses:

- `MESH_DATA` by default
- `DEFAULT` if `leveling` is checked (bed leveling before print). `DEFAULT` is deleted after printing.

Without the native screen, the `auto` mesh is auto-loaded on startup.

To use another mesh, disable auto-leveling (`SAVE_ZMOD_DATA PRINT_LEVELING=0`):

- Specify via the `MESH` parameter in [START_PRINT](/Main/#start_print). E.g., `START_PRINT MESH=my_80_degree_mesh`
- Load via `BED_MESH_PROFILE LOAD=my_80_degree_mesh` in filament profile. Ensure consistency between profile and `START_PRINT`, or disable nozzle cleaning in `START_PRINT`.
- Pre-level using [AUTO_FULL_BED_LEVEL](/Calibrations/#auto_full_bed_level). E.g., `AUTO_FULL_BED_LEVEL EXTRUDER_TEMP=230 BED_TEMP=80 PROFILE=my_80_degree_mesh`

#### Via global parameters
Use `PRINT_LEVELING` and `USE_KAMP` parameters. Enable with:
```
SAVE_ZMOD_DATA PRINT_LEVELING=1
SAVE_ZMOD_DATA USE_KAMP=1
```

---

#### By modifying the start code and START_PRINT macro
Examples:

!!! warning
    The parameter FORCE_LEVELING or FORCE_KAMP is not a separate macro, but a parameter of the Start Print Macro.

- Full leveling:
  ```
  START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single] FORCE_LEVELING=True
  ```

- Adaptive leveling:
  ```
  START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single] FORCE_KAMP=True
  ```

---

#### Via macros and buttons in Fluidd
Use:

- [AUTO_FULL_BED_LEVEL](/Calibrations/#auto_full_bed_level) (Fluidd button `BED LEVELING`)
- [KAMP](/Calibrations/#kamp)
- Standard Klipper macros (**not recommended**)

---

### Why are animal names periodically mentioned in the documentation?

Documentation is often unread, though 90% of questions are answered here. To verify if someone actually read it, animal names are hidden in the text. If directed here, read the docs and mention the animal related to your question:

- [FAQ](/FAQ/)
- [Recommendations](/Recomendations/)
- [Setup/Update/Uninstall](/Setup/)
- [Macros](/Macros/)
- [Known Issues](#known-peculiarities)

---

### What's the difference between using the screen and without the native screen?

The printer can operate in two modes:

- With the native screen - in this case, almost all operating logic is controlled by the native screen, and many features cannot be changed.
- Without the native screen - in this case, all features are controlled by zMod.
This doesn't mean you need to turn off the screen or replace it with a different one.
In the mode without the native screen, you can use the alternative software screen GuppyScreen or turn off the screen completely, so it will turn off.

!!! warning
    Do not disable the screen unless you fully understand bed leveling, z-offset, and START_PRINT/END_PRINT macros

**Disabling the screen saves RAM but changes print management (start/pause/resume/cancel/recovery). Modify start/end G-code accordingly.** *elk*

Without the screen, Z-offset from the screen isn't applied. Use [START_PRINT](/Main/#start_print) parameters or global settings. [Details](/FAQ/#how-does-z-offset-work)

Read [features of screenless operation](#screenless-version-notes).

---

### What is an alternative camera?

The native camera, which is turned on from the screen, has a number of disadvantages.

- High RAM consumption
- Low image quality
- Only one connection to the camera. Having opened it in the orc, you will no longer see it in the browser
- Periodic image dumps

The alternative camera, allows you to change the resolution, fps, allow multiple connections, does not overcompress the image, is easily restarted and is configured with a [macro](/Zmod/#camera_on). *hare*

- Disable the native camera on the printer screen.
- Call the macro [CAMERA_ON](/Zmod/#camera_on)

Read: [I installed a printer, and ZMOD hid my camera!](/FAQ/#i-installed-the-printer-but-zmod-hid-my-camera-in-orca-ff-i-could-see-it-but-now-its-gone)

#### Camera Setup

**Basic Parameters**

| Parameter | Description | Default Value |
|---|---|---|
| `WIDTH` | Image width | 640 |
| `HEIGHT` | Image height | 480 |
| `FPS` | Frames per second | 20 |
| `VIDEO` | Camera device | video0 |
| `FS` | Fix problematic cameras (1 – yes, 0 – no) | 0 |
| `STREAMER` | Program for handling the camera stream | auto |
| `FORMAT` | Image format (for ustreamer only) | MJPEG |

**What is a Streamer?**

A streamer is a program that takes the image from the camera and displays it in a browser.

**Two options are available:**

- **mjpg_streamer** – a simple program, works only with MJPG cameras
- **ustreamer** – more powerful but uses more memory; supports various cameras

The `STREAMER=auto` parameter will automatically choose the suitable streamer.

**Image Formats (for ustreamer only)**

You can choose: YUYV, YVYU, UYVY, RGB565, RGB24, BGR24, MJPEG, JPEG.

The default is MJPEG.

**Command Examples**

Simple start of camera video0 via mjpg_streamer:
```
CAMERA_ON VIDEO=video0
```

Start camera video0 via ustreamer with custom settings:
```
CAMERA_ON VIDEO=video0 STREAMER=ustreamer FORMAT=YUYV WIDTH=640 HEIGHT=480
```

**Where to View the Image?**

Open in your browser: `http://printer_ip_address:8080`

There you can adjust brightness, contrast, and other settings.

**Troubleshooting**

Camera not detected?
Run:
```
CAMERA_ON VIDEO=video99
```
The program will show a list of available cameras.

**Logs (error records)** are located in the folder: `log/cam/`

---

#### I installed the printer, but ZMOD hid my camera! In Orca-FF I could see it, but now it's gone!

In Fluidd: `Settings` -> `Cameras`. Create a new camera with:

- Stream URL: `http://your_IP:8080/?action=stream`
- Snapshot URL: `http://your_IP:8080/?action=snapshot`

In versions up than `1.4.3`, you can also specify:

- Stream type: `MJPEG stream`
- Stream URL: `/webcam/?action=stream`
- Snapshot URL: `/webcam/?action=snapshot`

For advanced features, use [alternative camera](/Zmod/#camera_on). *mole*

Assign a static IP to the printer on your router.

---

#### I have 2 cameras / how to disable/turn the camera

If you do not have a camera, or you are not satisfied with the settings of the automatic camera, then you need to open a file through Fluidd / Mainsal `mod_data/user.moonraker.conf`
`Settings`
And write:

To disable the camera:
```
[webcam video]
    enabled: false
```

To turn the camera:
```
 [webcam video]
    rotation: 90
```

---

### Cannot Update MCU

After rebooting, the following error appears:
```
!! Cannot update MCU 'eboard' config as it is shutdown
```

Rebooting the printer is an abnormal operating mode.

This is why, when installing the original firmware, you are asked to power off the printer and turn it back on.

During a reboot, power is not removed from the MCU, meaning the program stored in the MCU continues running. This program attempts to communicate with Klipper, which is unavailable during the reboot, causing the MCU to freeze or disconnect.

In this case, you have one option:

- Execute `FIRMWARE_RESTART` — this will freeze the original screen.
- Power off the printer and turn it back on.

The difference between `REBOOT` and `FIRMWARE_RESTART` is that `REBOOT` restarts Linux and Klipper on the motherboard, while `FIRMWARE_RESTART` partially restarts Klipper and fully restarts the MCU.

---

### I Switched the Web Interface, and Now Nothing Works

If you switched the interface using the [WEB](/System/#web) macro *выхухоль*:

1. Press `Ctrl + F5` or `Ctrl + Shift + R` or `Option + Command + E`
2. If the issue persists in Orca, press `Ctrl + F5` or `Ctrl + Shift + R` or `Option + Command + E` again. *fox*
3. For other browsers, clear the cache and cookies, then navigate to the printer’s IP without additional characters:
   `http://PRINTER_IP/`

4. If still unresolved, try another browser (Firefox, Chrome, Yandex, Opera, etc.).

---

### I Access the Printer via Orca/Browser and See "Welcome to Moonraker"

ZMOD uses the following ports:

- `7125` — Moonraker
- `8080` — Camera
- `80` — Fluidd/Mainsail

To access the printer, enter its IP address **without specifying a port**. *кролик*

[How to configure in Orca](/Recomendations/#send-files-via-octoklipper-for-printing)

---

### What is Firmware Retraction?

In ZMOD, Fluidd/Mainsail has sliders to adjust firmware retraction speed and distance. These do not affect prints unless the G-code file is sliced with firmware retraction enabled.

Firmware retraction allows adjusting retraction during printing without reslicing.

Instead of commands like `G1 E-.5 F2100`, use `G10` for retraction and `G11` for unretraction.

**To enable in Orca:**
`Printer Settings` -> `General` -> `Advanced` -> Enable `Use Firmware Retraction`.

**To modify default retraction settings:**
Edit `user.cfg` in Fluidd (`Configuration` -> `mod_data` -> `user.cfg`):
```
[firmware_retraction]
retract_length: 0.9
retract_speed: 35
unretract_extra_length: 0
unretract_speed: 35
```

**`SET_RETRACTION` parameters (configure per filament):**

- `RETRACT_LENGTH`: Filament retract/unretract distance.
- `RETRACT_SPEED`: Retraction speed.
- `UNRETRACT_SPEED`: Unretraction speed (often lower).
- `UNRETRACT_EXTRA_LENGTH`: Extra filament length during unretraction.

**Example in Orca:**
`Filament Profile` -> `Override Parameters` -> `Retraction` -> `Length`
`Filament Profile` -> `Advanced` -> `Start G-code`:
```
SET_RETRACTION RETRACT_LENGTH=[filament_retraction_length]
```

Use `GET_RETRACTION` to view current settings.

---

### After installing ZMOD, my screen is dead and not responding to touches.

- [Install the latest native firmware and ZMOD updates](/Recomendations/#install-latest-native-firmware-and-zmod-updates)
- Read [known peculiarities](#known-peculiarities) *bison*
- You might have disabled the screen. Enable it with the [DISPLAY_ON](/System/#display_on) macro

---

### I have installed the latest version, and the developer says you need to update.

- Make sure you put the latest version from a flash drive

- **Go to the web interface**.
```
Settings-> Software updates-> Press Check for update
```

- Update all components *tree climber*
- Reboot the printer

<img width="1239" height="535" alt="image" src="https://github.com/user-attachments/assets/b42c4ce9-1c0a-45c0-a20c-36919a27d648" />

---

### I want to remove ZMOD - I have to recalib?

No - all settings are saved

---

### Entware in ZMOD: How to Use It

**Warning! There is no Entware in [AD5X](/ru/AD5X/)**

1. SSH into the printer (`root`:`root`, port `22`).
2. Run:
   ```export PATH="$PATH:/opt/bin/:/opt/sbin/"```

3. Now you can use `mc` or `opkg`:

    - Update package database: `opkg update`
       - Install a package: `opkg install mc`

**Entware directories:**

- `/opt/bin`, `/opt/sbin`, `/opt/etc`, `/opt/home`, `/opt/lib`, `/opt/libexec`, `/opt/root`, `/opt/share`, `/opt/tmp`, `/opt/usr`, `/opt/var`

---

### Known features

[Known features](https://github.com/ghzserg/zmod#known-peculiarities)

---

### AD5X Specifics

#### AD5X

[AD5X](/ru/AD5X/)

---

### Help
### How to Contact Support

1. [Update ZMOD to the latest version and all plugins](/Setup/#updating-the-mod).
2. Translate the mod into Russian ```LANG LANG=ru``` or English ```LANG LANG=en```
3. Describe the issue clearly (screenshots, photos, text).
4. Run [CLEAR_EMMC](/System/#clear_emmc) to clear logs.
5. **Power off the printer.**
6. Power it back on.
7. Reproduce the issue.
8. Run [TAR_CONFIG](/Zmod/#tar_config) to save logs.
9. Submit the issue with `config.tar.gz` and description.
10. [Open a GitHub issue](https://github.com/ghzserg/zmod/issues).

---

### How to change the boot logo

The logo is located in the folder ```mod_data/logo```.

Logo requirements:

- Size: 800×480, 24-bit color depth  
- AD5M: BMP format. File name: ```bootlogo.bmp```  
- AD5X: JPG format. File name: ```logo.jpeg```

Upload your logo to the folder ```mod_data/logo```.

Reboot the printer twice.

Removing the mod will restore the original logo. If this doesn't happen on the AD5M:

- Install the mod
- Upload the [boot.bmp](https://github.com/ghzserg/FF/releases/download/R/boot.bmp) file to the `mod_data/logo` folder
- Restart the printer

---

### No trigger on probe after full movement

This error usually occurs if the z-axis isn't raised enough during measurement.

This can be fixed programmatically as follows:

Add to ```mod_data/user.cfg```
```
[bed_mesh]
horizontal_move_z: 5
```

Hardware - all screws must be adjusted and the bed must not be warped.

---

### WeightValue

WeightValue is the value on the load cells in grams. It is displayed in degrees, as it is implemented through the temperature sensor interface. Therefore, Fluidd and Mainsail display degrees.

What is this sensor for?

 It can be used to measure zoffset via the [g28_tenz](https://github.com/ghzserg/g28_tenz) plugin

- You can stop printing if the nozzle hits the part or the part is torn off. [NOZZLE_CONTROL](/ru/Global/#nozzle_control)
- Without resetting it, the table map will be measured incorrectly.

---

### MCU Protocol error

Here are some errors that depend on the MCU:

- MCU Protocol error
- Unknown temperature sensor flashforge_loadcell
- Required MCU command
- flashforge_loadcell: Required MCU command 'flashforge_loadcell_h1' is not available

The essence of all these errors is that the Klipper version does not match the MCU version.

You can view the MCU version in the System tab.

<img width="700" height="396" alt="{9CCFD772-CCDB-42ED-B952-DA15231DCF68}" src="https://github.com/user-attachments/assets/80e6a573-b372-4620-a7bc-7cbf020bc874" />

<img width="438" height="277" alt="{52EC8847-ACAB-461D-A9FA-633CDAF180CC}" src="https://github.com/user-attachments/assets/9bba3ff2-9a0e-4aa6-8327-f93fd1b46c3a" />

For example, you are running Klipper 13, but the MCU used is from Klipper 11 or 12.

Or vice versa. You're running native Klipper, but you've loaded an MCU for Klipper 13.

If your MCU version starts with ```?-20230317_182329-ubuntu20-virtual-machine```, then you've loaded an MCU for Klipper 12 (AD5X) or Klipper 11 (Ad5M/Ad5mPro).

Accordingly, zMod needs to load native Klipper.

- Go to ```mod_data/variables.cfg``` and delete the line ```klipper13 = 1```.
- Save the file
- Turn the printer off and on (do not reboot!)

<img width="422" height="570" alt="image" src="https://github.com/user-attachments/assets/821eb1c7-8cba-4a22-951f-852b1cb6c8ef" />

If this isn't the case and Klipper is working, run ```UPDATE_MCU FORCE=13``` - this command will install the latest MCU version.

If all else fails and **Klipper isn't working**:

- Switch to the native Klipper as described above.
- [Install the native Factory firmware](/Native_FW/#how-to-install-native-firmware), which will install the native MCU.

---

### Filament has run out or stopped

Filament runout or jam detected

For AD5M, you need to calibrate the sensor steps by trial and error. Enter this in `mod_data/user.cfg`

Increase this number. The standard 8 is sufficient for some, but some sensors only work correctly at 17.
```
[filament_motion_sensor e0_sensor]
detection_length: 8
```

Filament jam detected (IFS)

For AD5X, the IFS motion sensor step count must be calibrated manually. Add the following to `mod_data/user.cfg`:

```
[zmod_ifs_motion_sensor ifs_motion_sensor]
detection_length: 8
```

Increase this value—some printers work fine with the default `10`, while others require up to `17` for stable IFS operation.

Additionally, filament stoppage in IFS may be caused by:

- Extruder is loaded with spool 1, but spool 2 is being pulled out — use [`SET_EXTRUDER_SLOT`](/AD5X/#5-how-to-manually-tell-the-printer-which-spool-is-loaded) to sync the extruder’s current slot.
- New filament is being inserted, while old filament remains inside the extruder.
- The 4-in-1 modules and their tubes have different lengths, requiring adjustment of `filament_unload_into_tube` in `mod_data/filament.json`. Set it to **70 or higher**.
  ➜ [More details](/AD5X/#basic-parameters-most-frequently-adjusted)

The issue may also stem from the **inability to unlock the filament in the IFS channel**.

Mechanical causes include:

- Plastic shavings stuck on the pinch roller shaft.
- Spring disengaged from the IFS channel lever.

Solution: Remove debris, disassemble the mechanism, and reinstall components correctly.

After repairs, test printing and filament lock/unlock behavior using the [IFS commands](/AD5X/#10-ifs-commands).

---

### Before each print, the printer measures the center of the bed.

Before printing, the printer:

- heats the bed and nozzle.
- cleans the nozzle.
- Cools the nozzle
- **Measures the bed center** (Starting manual Z probe. Use TESTZ to adjust position)
- Heats the nozzle
- Starts printing

This is a feature of the native firmware starting with version:

- **1.1.8** AD5X
- **3.2.4** AD5M/AD5MPro

Solution:

- [Roll back the native firmware](/Native_FW/) to version **1.1.7** for AD5X, **3.2.3** for FF5M/FF5MPro
- [Disable the native display](/System/#display_off)

---

### E0120

This is a Klipper error.

Most often it is corrected by the following simple actions:

- Turn off the power of the printer
- Wait 10 seconds
- Power on the printer

To see what exactly is the error:

- Open Fluidd/Mainsail
- Go to the console and read the error text
- Open the Telegram bot [@zmod_help_bot](http://t.me/zmod_help_bot) and enter the error text or look up the description in the documentation yourself

If you can't fix it, [you need to create a ticket](/Help/).

[Native configs](https://github.com/ghzserg/zmod/tree/main/Native_firmware/config/)

