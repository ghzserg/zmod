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

- `GUPPY`: `0` = disable GuppyScreen, `1` = enable GuppyScreen (default: `1`)

Disable the standard screen. Saves 13 MB of RAM (20 MB on older firmware versions).

**GuppyScreen** (alternative screen implementation):

- Supports all native screen features except WiFi configuration.
- Uses 9 MB RAM (vs. 23 MB for the native screen).
- Prevents Klipper freezes during reboots.
- Recommended for non-native screen workflows.
- Better print recovery after interruptions.
- Based on [this fork](https://github.com/ghzserg/guppyscreen_ff5m).

**Warning:**

- Do not disable the screen unless you fully understand bed leveling, Z-offset, and the `START_PRINT`/`END_PRINT` macros.
- The screen remains active for 3 minutes after reboot but does not affect Z-offset or printing.

Adjust activation timing via the [`DISPLAY_OFF_TIMEOUT`](/Global/#display_off_timeout) global parameter.

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

**Stock firmware command:**
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

---
### CHECK_MD5

Igor Polunovskiy

Verify file integrity via MD5 checksum.

- `DELETE` — delete corrupted files: `yes`/`no`.

**Usage:**

1. Select and download the file for your architecture and operating system:

- [zmod_preprocess-windows-amd64.exe](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-windows-amd64.exe) - Windows
- [zmod_preprocess-linux-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-linux-amd64) - Linux. Don't forget to chmod +x zmod_preprocess-linux-amd64
- [zmod_preprocess-darwin-arm64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-arm64) - MacOS (Intel). Don't forget to run ```chmod +x zmod_preprocess-darwin-arm64```
- [zmod_preprocess-darwin-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-amd64) - MacOS Silicon. Don't forget to run ```chmod +x zmod_preprocess-darwin-amd64```
- [zmod-preprocess.py](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.py) - General-Python. Don't forget to run ```chmod +x zmod-preprocess.py```
- [zmod-preprocess.sh](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.sh) - Linux/MacOS Bash. Don't forget to run ```chmod +x zmod-preprocess.sh```

2. In Orca, you need to specify: `Process Profile` -> `Other` -> `Post Processing Scripts`.

Here are the options for adding:

- ```"С:\path_to_file\zmod_preprocess-windows-amd64.exe";```
- ```"C:\python_folder\python.exe" "C:\Scripts\zmod-preprocess.py";```
- ```"/usr/bin/python3" "/home/user/zmod-preprocess.py";```
- ```"/home/user/zmod-preprocess.py";```
- ```"/home/user/zmod_preprocess-darwin-amd64";```
- ```"/home/user/zmod_preprocess-darwin-arm64";```
- ```"/home/user/zmod_preprocess-linux-amd64";```

3. Add `CHECK_MD5` or `CHECK_MD5 DELETE=true` to your start G-code.

**Note:** Enabled by default via [`FORCE_MD5`](/Global/#force_md5).

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

If you don't understand how to [restore the configs and MCU firmware](/Native_FW/#installing-full-firmware-on-ad5x), do not run this command.

If something goes wrong, the only way back is through [factory](/Native_FW/).

---

### RESET_PASSWD

Set ssh root password to root

---
### CHECK_SYSTEM

Diagnose OS file integrity.

- `RESTORE` — `0` = no repair, `1` = repair damaged files (default: `0`).

Checks:

- File permissions/MD5 hashes.
- Directory permissions.
- Symbolic links.

**Recovery:** Download intact files from [here](https://github.com/ghzserg/FF/tree/main/stock).

---

### SCREEN

Get a screenshot of the printer

The photo will be saved in ```mod_data/screen.jpg```
