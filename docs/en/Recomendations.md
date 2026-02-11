# Recommendations
## Recommendations to Improve Printer Stability

These recommendations apply to both stock firmware and ZMOD.

---

### Enable Object Exclusion

Enable object exclusion in Orca:

- `Process Profile` -> `Other` -> `Custom G-code` -> Check `Exclude objects`
- `Process Profile` -> `Other` -> `Custom G-code` -> Check `Label objects`

<img width="285" height="171" alt="image" src="https://github.com/user-attachments/assets/faceef98-2791-4975-bf72-425f4a2b1dfa" />

---

### Install the Latest Stock Firmware and ZMOD Updates

Only the latest version of ZMOD is actively supported.

The developer lacks resources to maintain older versions, so [install the latest stock firmware and ZMOD updates](/Setup/).

---

### Replace Spiral/Auto Z-Hop

The printer does not support this feature.

**In Orca:**
`Printer Profile` -> `Extruder 1` -> `Z Hop Type` -> Set to `Normal` or `Slanted`.

---

### Disable "Arc Move" Approximation

While the printer supports arc moves, they reduce print quality and may cause errors.

**In Orca:**
`Process Profile` -> `Quality` -> `Precision` -> Uncheck `Arc Move Approximation`.

---

### Disable the Built-in Camera on the Printer Screen

The built-in camera consumes excessive memory and offers poor image quality. Use an alternative camera instead.

**On the printer screen:**
`Settings` -> `Camera Tab` -> Disable `Camera` and `Video` toggles.

Then, run the [CAMERA_ON](/Zmod/#camera_on) macro.

- [What is an alternative camera?](/FAQ/#what-is-an-alternative-camera)
- [I installed ZMOD, and my camera disappeared! It worked in Orca-FF!](/FAQ/#i-installed-the-printer-but-zmod-hid-my-camera-in-orca-ff-i-could-see-it-but-now-its-gone)

---

### Disable Chinese Cloud Services

### Lan mode error

These services are unstable and may disconnect intermittently. Reconnection attempts can overload the printer with queued requests, causing errors.

Disabling them also enables faster dialog closure after printing and native bed leveling via the screen.

**On the printer screen:**

1. `Settings` -> `WiFi Tab` -> `Network Mode` -> Enable `Local Network Only`.
2. `Settings` -> `Cloud Tab` -> Disable `FlashCloud` and `Polar3d`.

Instead, you can use:

- [zmod.link](/ru/Zmod/#zlink) - cloud, for managing printers via Fluidd/Mainsail.
- [Telegram bot](/ru/Macros/).

[More about Chinese cloud services](/Global/#china_cloud).

---

### Enable [MD5] Checksum Control

Igor Polunovskiy

Add [CHECK_MD5](/System/#check_md5) to your workflow.

It is recommended to use the [global parameter FORCE_MD5](/ru/Global/#force_md5) `SAVE_ZMOD_DATA FORCE_MD5=1`

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

[Details](/System/#check_md5)

<img width="476" height="355" alt="image" src="https://github.com/user-attachments/assets/0b59a617-5613-4def-aa01-7fe038898863" />

*hamster*

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

---

### Enable Fix for E0017 Error

[E0017 Fix](/Global/#fix_e0017)

Enabled by default.

---

### Enable Fix for E0011 Error

Resolves `E0011` and `Communication timeout during homing` errors.

[E0011 Fix](/Global/#fix_e0011)

**Experimental feature** — disabled by default.

---

### Verify Stock OS File Integrity

Improper printer shutdowns can corrupt the filesystem, leading to minor or major bugs.

The [CHECK_SYSTEM](/System/#check_system) macro checks file MD5 hashes and repairs symbolic links if needed.

---

### Enable Nozzle Collision Detection

Disabled by default. Enable using the [NOZZLE_CONTROL](/Global/#nozzle_control) macro:

```
NOZZLE_CONTROL WEIGHT=0
```

This halts Klipper if the nozzle scratches the bed or a part detaches. **Highly recommended for users employing nozzle pre-cleaning routines.**
