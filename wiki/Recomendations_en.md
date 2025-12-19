# Recommendations
## Recommendations to Improve Printer Stability

These recommendations apply to both stock firmware and ZMOD.

| | |
|---|---|
| [Install Latest Firmware & ZMOD Updates](#install-the-latest-stock-firmware-and-zmod-updates) | [Replace Spiral/Auto Z-Hop](#replace-spiralauto-z-hop) |
| [Disable Arc Move Approximation](#disable-arc-move-approximation) | [Disable Built-in Camera](#disable-the-built-in-camera-on-the-printer-screen) |
| [Disable Chinese Cloud Services](#disable-chinese-cloud-services) | [Enable Object Exclusion](#enable-object-exclusion) |
| [Enable Nozzle Collision Detection](#enable-nozzle-collision-detection) | [Enable MD5 Checksum Control](#enable-md5-checksum-control) |
| [Send Files via Octo/Klipper](#send-files-via-octoklipper-for-printing) | [Verify OS File Integrity](#verify-stock-os-file-integrity) |
| [Enable E0017 Error Fix](#enable-fix-for-e0017-error) | [Enable E0011 Error Fix](#enable-fix-for-e0011-error) |

[@zmod_help_bot](http://t.me/zmod_help_bot)

---

### Enable Object Exclusion

Enable object exclusion in Orca:
- `Process Profile` -> `Other` -> `Custom G-code` -> Check `Exclude objects`
- `Process Profile` -> `Other` -> `Custom G-code` -> Check `Label objects`

<img width="285" height="171" alt="image" src="https://github.com/user-attachments/assets/faceef98-2791-4975-bf72-425f4a2b1dfa" />

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#recommendations)

</div>

---

### Install the Latest Stock Firmware and ZMOD Updates

Only the latest version of ZMOD is actively supported.

The developer lacks resources to maintain older versions, so [install the latest stock firmware and ZMOD updates](https://github.com/ghzserg/zmod/wiki/Setup_en).

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#recomendations)

</div>

---

### Replace Spiral/Auto Z-Hop

The printer does not support this feature.

**In Orca:**
`Printer Profile` -> `Extruder 1` -> `Z Hop Type` -> Set to `Normal` or `Slanted`.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#recomendations)

</div>

---

### Disable "Arc Move" Approximation

While the printer supports arc moves, they reduce print quality and may cause errors.

**In Orca:**
`Process Profile` -> `Quality` -> `Precision` -> Uncheck `Arc Move Approximation`.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#recomendations)

</div>

---

### Disable the Built-in Camera on the Printer Screen

The built-in camera consumes excessive memory and offers poor image quality. Use an alternative camera instead.

**On the printer screen:**
`Settings` -> `Camera Tab` -> Disable `Camera` and `Video` toggles.

Then, run the [CAMERA_ON](https://github.com/ghzserg/zmod/wiki/Zmod_en#camera_on) macro.

- [What is an alternative camera?](https://github.com/ghzserg/zmod/wiki/FAQ_en#what-is-an-alternative-camera)
- [I installed ZMOD, and my camera disappeared! It worked in Orca-FF!](https://github.com/ghzserg/zmod/wiki/FAQ_en#i-installed-the-printer-but-zmod-hid-my-camera-in-orca-ff-i-could-see-it-but-now-its-gone)

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#recomendations)

</div>

---

### Disable Chinese Cloud Services

### Lan mode error

These services are unstable and may disconnect intermittently. Reconnection attempts can overload the printer with queued requests, causing errors.

Disabling them also enables faster dialog closure after printing and native bed leveling via the screen.

**On the printer screen:**
1. `Settings` -> `WiFi Tab` -> `Network Mode` -> Enable `Local Network Only`.
2. `Settings` -> `Cloud Tab` -> Disable `FlashCloud` and `Polar3d`.

Instead, you can use:
- [zmod.link](https://github.com/ghzserg/zmod/wiki/Zmod_ru#zlink) - cloud, for managing printers via Fluidd/Mainsail.
- [Telegram bot](https://github.com/ghzserg/zmod/wiki/Macros).

[More about Chinese cloud services](https://github.com/ghzserg/zmod/wiki/Global_en#china_cloud).

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#recomendations)

</div>

---

### Enable [MD5] Checksum Control

Igor Polunovskiy

Add [CHECK_MD5](https://github.com/ghzserg/zmod/wiki/System_en#check_md5) to your workflow.

It is recommended to use the [global parameter FORCE_MD5](https://github.com/ghzserg/zmod/wiki/Global_ru#force_md5) `SAVE_ZMOD_DATA FORCE_MD5=1`

*Add [addMD5.bat](https://github.com/ghzserg/zmod/releases/download/R/addMD5.bat) or
[addMD5.sh](https://github.com/ghzserg/zmod/releases/download/R/addMD5.sh) for Mac/Linux to your post-processing scripts* (don't forget to add executable permissions to the file `chmod +x addMD5.sh`) or
[addMD5.py](https://github.com/ghzserg/zmod/releases/download/R/addMD5.py) it's located in mod. [More details](https://github.com/ghzserg/zmod/wiki/System_ru#check_md5)*

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

[Details](https://github.com/ghzserg/zmod/wiki/System_en#check_md5)

<img width="472" height="549" alt="image" src="https://github.com/user-attachments/assets/b330fa6f-fffd-4b0d-95b0-4e879eabd0d3" />

*hamster*

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#recomendations)

</div>

---

### Send Files via "Octo/Klipper" for Printing

The native FF protocol occasionally transfers corrupted files and lacks metadata support for the Telegram bot.

**In Orca:**
1. Click the WiFi icon next to the printer.
2. Set:
   - **Protocol**: `Octo/Klipper`
   - **Hostname**: `Printer_IP:7125`
   - **Host URL**: `Printer_IP` or `Printer_IP:80`

If using Mainsail, specify only these thumbnail sizes: ```140x110/PNG, 64x64/PNG```

In Orca, `Printer Profile` -> `General Information` -> `Advanced` -> `G-Code Thumbnails`

Note that the native screen will no longer display thumbnails.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#recomendations)

</div>

---

### Enable Fix for E0017 Error

[E0017 Fix](https://github.com/ghzserg/zmod/wiki/Global_en#fix_e0017)

Enabled by default.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#recomendations)

</div>

---

### Enable Fix for E0011 Error

Resolves `E0011` and `Communication timeout during homing` errors.

[E0011 Fix](https://github.com/ghzserg/zmod/wiki/Global_en#fix_e0011)

**Experimental feature** — disabled by default.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#recomendations)

</div>

---

### Verify Stock OS File Integrity

Improper printer shutdowns can corrupt the filesystem, leading to minor or major bugs.

The [CHECK_SYSTEM](https://github.com/ghzserg/zmod/wiki/System_en#check_system) macro checks file MD5 hashes and repairs symbolic links if needed.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#recomendations)

</div>

---

### Enable Nozzle Collision Detection

Disabled by default. Enable using the [NOZZLE_CONTROL](https://github.com/ghzserg/zmod/wiki/Global_en#nozzle_control) macro:

```
NOZZLE_CONTROL WEIGHT=0
```

This halts Klipper if the nozzle scratches the bed or a part detaches. **Highly recommended for users employing nozzle pre-cleaning routines.**

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#recomendations)

</div>

---