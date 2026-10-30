<h1 align="center">System</h1>

A macro is a small program written in Klipper/Gcode language.

It can be called from:

- A GCODE file
- The Fluidd/Mainsail console (press the English letter `C` in Fluidd)

!!! note
    *The value in parentheses is the default value*

---

### DISPLAY_ON

Enable the standard screen and reboot the printer.

---
### DISPLAY_OFF

Disable the standard screen and reboot the printer. Saves 13 MB of RAM (20 MB on older firmware versions).

Use the button with a parameter selector in the "Macros" list, or a console command:

- `DISPLAY_OFF GUPPY=1 HELIX=0` — enables GuppyScreen.
- `DISPLAY_OFF GUPPY=0 HELIX=1` — enables [HelixScreen](https://github.com/prestonbrown/helixscreen) + `PLUGINS`.

**GuppyScreen** (alternative screen implementation):

- Supports all native screen features except WiFi configuration.
- Uses 9 MB RAM (vs. 23 MB for the native screen).
- Does not freeze when Klipper restarts.
- Includes extra features, such as a list of all macros, including your own.
- Recommended for screenless workflows.
- Better print recovery after interruptions.
- Based on [this fork](https://github.com/ghzserg/guppyscreen_ff5m), which is built on the [original repository](https://github.com/ballaswag/guppyscreen) and another [fork](https://github.com/consp/guppyscreen/tree/flashforge_ad5m).

**[HelixScreen](https://github.com/prestonbrown/helixscreen)** (alternative screen implementation)

**Warning:**

- Do not disable the screen unless you fully understand bed leveling, Z-offset, and the `START_PRINT`/`END_PRINT` macros.
- Do not add this macro to your start G-code.
- After a reboot the native screen keeps running for another 10 seconds, but it does not affect Z-offset because printing does not go through it.

Adjust activation timing via the [`DISPLAY_OFF_TIMEOUT`](/Global/#display_off_timeout) global parameter.

Configure `START_PRINT` and set the required Z-offset via its parameters or via global parameters.

[Learn more about screen modes](/FAQ/#whats-the-difference-between-using-the-screen-and-without-the-native-screen).

---
### MEM

View memory usage.

---
### TEST_EMMC

Test EMMC performance and wear level.
Parameters:

- `SIZE` — data size to write in MB (default: `100`).
- `SYNC` — `1` = synchronous mode (measure speed), `0` = asynchronous background write (default: `1`).
- `FLASH` — target storage: `0` = EMMC, `1` = USB flash, `2` = RAM (default: `0`).
- `RANDOM` — use random data: `1` = yes, `0` = no (default: `0`).

**On stock firmware:** download [zfs.sh](https://github.com/ghzserg/z_ff5m/blob/1.7/.shell/zfs.sh) and run:
```bash
./zfs.sh 400 1
```

---
### CLEAR_EMMC

Clear EMMC storage.
Parameters:

- `LOG` — clear log files: `1` = yes, `0` = no (default: `1`).
- `ANY` — clear all files (G-code, images, videos): `1` = yes, `0` = no (default: `0`).

---
### DATE_GET

Display current system time.

---
### DATE_SET

Set system date and time.

- `DT` — date/time in `YYYY.MM.DD-HH:MM:SS` format.

---
### WEB

Switch between Fluidd and Mainsail web interfaces.

After running the macro:

- Press Ctrl + F5 or Ctrl + Shift + R or Option + Command + E
- If you have a problem in Orca, press Ctrl + F5 or Ctrl + Shift + R or Option + Command + E

If using Mainsail, specify only these thumbnail sizes: ```140x110/PNG, 64x64/PNG```

In Orca, `Printer Profile` -> `General Information` -> `Advanced` -> `G-Code Thumbnails`

Note that the native screen will no longer display thumbnails.

Attention! The author uses Fluidd; Mainsail is user-tested only. If you have any issues with Mainsail, please create a [ticket](/Help/)

---
### SET_TIMEZONE

Set timezone.

- `ZONE` — timezone identifier (default: `Asia/Yekaterinburg`).

Example: `SET_TIMEZONE ZONE=Europe/Moscow`. Run `SET_TIMEZONE` without parameters to list the available zones.

The timezone lets [GuppyScreen](/System/#display_off) calculate when the print will finish.

---
### CHECK_MD5

Igor Polunovskiy

> Note: Only applies when sending G-code. Not required for 3MF.

It is recommended to use the [global parameter FORCE_MD5](/Global/#force_md5) `SAVE_ZMOD_DATA FORCE_MD5=1`

Verify file integrity via MD5 checksum.

- `DELETE` — delete corrupted files: `yes`/`no` (default: `yes`).

**Usage:**

1. Select and download the file for your architecture and operating system:

- [zmod_preprocess-windows-amd64.exe](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-windows-amd64.exe) - Windows
- [zmod_preprocess-linux-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-linux-amd64) - Linux. Don't forget to run ```chmod +x zmod_preprocess-linux-amd64```
- [zmod_preprocess-darwin-arm64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-arm64) - macOS Apple Silicon. Don't forget to run ```chmod +x zmod_preprocess-darwin-arm64```
- [zmod_preprocess-darwin-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-amd64) - macOS Intel. Don't forget to run ```chmod +x zmod_preprocess-darwin-amd64```
- [zmod-preprocess.py](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.py) - Universal Python. Don't forget to run ```chmod +x zmod-preprocess.py```
- [zmod-preprocess.sh](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.sh) - Linux/MacOS Bash. Don't forget to run ```chmod +x zmod-preprocess.sh```

2. In Orca, you need to specify: `Process Profile` -> `Other` -> `Post Processing Scripts`.

Here are the options for adding:

- ```"C:\path_to_file\zmod_preprocess-windows-amd64.exe";```
- ```"C:\python_folder\python.exe" "C:\Scripts\zmod-preprocess.py";```
- ```"/usr/bin/python3" "/home/user/zmod-preprocess.py";```
- ```"/home/user/zmod-preprocess.py";```
- ```"/home/user/zmod_preprocess-darwin-amd64";```
- ```"/home/user/zmod_preprocess-darwin-arm64";```
- ```"/home/user/zmod_preprocess-linux-amd64";```

3. Add `CHECK_MD5` or `CHECK_MD5 DELETE=true` to your start G-code. If you use the `START_PRINT` macro, this is not necessary — the check runs automatically.

**Note:** Enabled by default via [`FORCE_MD5`](/Global/#force_md5).

Source code: [https://github.com/ghzserg/zmod_preprocess](https://github.com/ghzserg/zmod_preprocess)

```
Stops printing if the checksum does not match, optionally deleting the corrupted file.

The author is not responsible for any errors or problems, or for any results obtained using this information.

The checksum is written at the beginning of the G-code file. If the file contains no checksum, the macro does not check it and the file is sent straight to printing.
The result of the check is printed to the console.

=========================================
1. On the Windows machine where the slicer is installed:
  a) Download https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-windows-amd64.exe
  b) Add the script from step 1.a to the slicer,
     replacing "disk:\patch\to\file\" with your path to the script:
    - for OrcaSlicer
      "Process"->"Others"->"Post-processing Scripts"
    - for SuperSlicer and PrusaSlicer
      "Print Settings"->"Output options"->"Post-processing scripts"
    disk:\patch\to\file\zmod_preprocess-windows-amd64.exe;
  c) Add the macro to the slicer
    - for OrcaSlicer
      "Printer Settings"->"Machine G-code"->"Machine start G-code"
    - for SuperSlicer and PrusaSlicer
      "Printer Settings"->"Custom G-code"->"Start G-code"
    * Without deleting the file:
      CHECK_MD5
    * With deleting the file:
      CHECK_MD5 DELETE=true
  d) If the START_PRINT macro is used, there is no need to add CHECK_MD5 to the start code. The check runs automatically by default.
```

---
### UPDATE_MCU

Updates the printer's MCU.

Changes the MCU firmware from the native Klipper version (11 for FF5M/FF5MPRO, 12 for AD5X) to Klipper 13 and back.

Klipper 13 (disabled by default).

FORCE parameter:

- 11 - load Klipper 11 firmware - FF5M
- 12 - load Klipper 12 firmware - AD5X
- 13 - load Klipper 13 firmware

Without parameters, changes the firmware to the opposite version.

Example: `UPDATE_MCU FORCE=13` forces the download of Klipper 13 firmware.

If you don't understand how to [restore the native Klipper from a USB flash drive](/Native_FW/#fix_klipper), do not run this command.
Before updating Klipper, review the [changes in new versions](https://www.klipper3d.org/Releases.html); the stock configuration files need no edits.

If something goes wrong, the only way back is through [factory](/Native_FW/).

After running the macro:

1. Wait for the melody to play (it plays even if sound was muted on the native screen)
2. Power off the printer
3. **Wait 10 seconds**
4. Power the printer back on

---

### RESET_PASSWD

Reset the SSH `root` password to `root`.

---
### CHECK_SYSTEM

Diagnose OS file integrity.

- `RESTORE` — `0` = no repair, `1` = repair damaged files (default: `0`).

Checks:

- File permissions/MD5 hashes.
- Directory permissions.
- Symbolic links.

Symbolic links and file/directory permissions are restored automatically.

The check takes about 10 minutes.

**Recovery:** Download intact files from [here](https://github.com/ghzserg/FF/tree/main/stock).

If the console is unavailable, connect to the printer via SSH:

`/usr/data/zmod/zmod/.shell/zcheckmd5.sh`

---

### SCREEN

Get a screenshot of the printer screen.

The screenshot will be saved to ```mod_data/screen.jpg```
