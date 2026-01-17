<h1 align="center">Zmod</h1>

*[Прочитать на русском языке](https://github.com/ghzserg/zmod/wiki/Zmod_ru)*

A macro is a small program written in Klipper/Gcode language.

It can be called from:
- A GCODE file
- The Fluidd/Mainsail console (press the English letter `C` in Fluidd)

> [!NOTE]
> *The value in parentheses is the default value*

[@zmod_help_bot](http://t.me/zmod_help_bot)

---

<table style="width: 100%; table-layout: fixed;" align="center">
<thead><tr>
  <th colspan="4"><p align="center"><strong>🔷 Zmod 🔷</strong></p></th>
</tr></thead>
<tbody>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_en#camera_off">CAMERA_OFF</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_en#camera_on">CAMERA_ON</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_en#camera_restart">CAMERA_RESTART</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_en#zflash">ZFLASH</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_en#tar_config">TAR_CONFIG</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_en#restore_tar_config">RESTORE_TAR_CONFIG</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_en#start_zmod">START_ZMOD</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_en#stop_zmod">STOP_ZMOD</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_en#zssh_off">ZSSH_OFF</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_en#zssh_on">ZSSH_ON</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_en#zssh_reload">ZSSH_RELOAD</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_en#zssh_restart">ZSSH_RESTART</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_en#remove_zmod">REMOVE_ZMOD</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_en#skip_zmod">SKIP_ZMOD</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_en#zrestore">ZRESTORE</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_en#zlink">ZLINK</a></td>
 </tr>
</tbody>
</table>

### CAMERA_ON

Enable alternative camera implementation.
Parameters:
- `WIDTH` — image width (default: `640`)
- `HEIGHT` — image height (default: `480`)
- `FPS` — frames per second (default: `20`)
- `VIDEO` — video device (default: `video0`)
- `FS` — `1` = enable frame size limiter for unstable cameras, `0` = disable (default: `0`)
- `STREAMER` - what streamer to use (auto, mjpg_streamer, ustreamer)
- `FORMAT` - Image format for ustreamer: YUYV, YVYU, UYVY, RGB565, RGB24, BGR24, MJPEG, JPEG; default: MJPEG

*Disable the camera on the printer's screen before calling this macro.*

To enable the camera, use ```CAMERA_ON VIDEO=video0``` or ```CAMERA_ON VIDEO=video3``` or ```CAMERA_ON VIDEO=video99```.

<img width="734" height="221" alt="{D2A001DD-7C89-4AB9-9CB9-741B7007B0B4}" src="https://github.com/user-attachments/assets/e8ddbbd3-ebbf-4b4e-86cc-2a62365a4a88" />

If the camera does not work, then look at the logs `mod_data/log/cam`

RAM usage for stock cameras:
- 640x480: 2.9 MiB
- 1280x720: 7.8 MiB
- 1920x1080: 18.1 MiB

*Many AliExpress/Ozon/Wildberries cameras always consume 18 MiB.*

> [!NOTE]
> - [What is an Alternative Camera?](https://github.com/ghzserg/zmod/wiki/FAQ_en#what-is-an-alternative-camera)
> - [I installed the printer, and ZMOD hid my camera! I saw her in Orca-FF, and now she's gone!](https://github.com/ghzserg/zmod/wiki/FAQ_en#i-installed-the-printer-but-zmod-hid-my-camera-in-orca-ff-i-could-see-it-but-now-its-gone)

`Camera Off Waiting...` - this message is displayed if the camera stream is not yet available. The camera starts after Klipper launches, during the global settings information display.

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

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)

</div>

---
### CAMERA_OFF

Disable alternative camera implementation.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)

</div>

---
### CAMERA_RESTART

Restart the alternative camera implementation.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)

</div>

---
### REMOVE_ZMOD

Uninstall Zmod.
- `FULL`: `0` = keep `/opt/config/mod_data`, `1` = delete `/opt/config/mod_data` (default: `0`)

The `/opt/config/mod_data` directory stores configurations for `zmod`, `fluidd`, `moonraker`, and `mainsail`.
It is not deleted by default to prevent accidental data loss.

Warning! Disable all plugins yourself and switch to the native Klipper.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)

</div>

---
### SKIP_ZMOD

Reboot into the original system without Zmod.
Disables Zmod, Moonraker, and Fluidd configurations.

Warning! Disable all plugins yourself and switch to the native Klipper.

Remaining active:
- Alternative camera
- SSH

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)

</div>

---
### TAR_CONFIG

Backup configuration files into an archive.
Download the archive via: **Configuration → mod_data → config.tar.gz**

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)

</div>

---
### RESTORE_TAR_CONFIG

Restore configurations from the `config.tar.gz` archive.
Upload the archive to: **Configuration → mod_data → config.tar.gz**

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)

</div>

---
### ZFLASH

Update firmware via network using a USB drive.

1. Insert the USB drive into the printer and power it on.
2. If using without the native screen, ensure the USB is inserted **before** powering on.
3. This macro checks for the latest release, downloads it to the USB, verifies the MD5 hash, and installs it after reboot.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)

</div>

---

### STOP_ZMOD

Unload guppy, moonraker, and fluidd/Mainsail from memory. The Telegram bot will also stop working.

Parameters:
- GUPPY (0 - do not unload, 1 - unload)
- MOONRAKER (0 - do not unload, 1 - unload)
- HTTP (0 - do not unload, 1 - unload)

Example:
```
STOP_ZMOD GUPPY=1 MOONRAKER=0 HTTP=0
```

If this line is added to the start code, GUPPY will be unloaded from memory after the print starts.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)

</div>

---

### START_ZMOD

Re-enable guppy, moonraker, and fluidd/Mainsail after STOP_ZMOD.

Parameters:
- GUPPY (0 - do not load, 1 - load)
- MOONRAKER (0 - do not load, 1 - load)
- HTTP (0 - do not load, 1 - load)

Example:
```
START_ZMOD GUPPY=1 MOONRAKER=0 HTTP=0
```

If this line is added to the end code, GUPPY will be launched after the print finishes.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)

</div>

---
### ZSSH_ON

Enable SSH tunneling.
Parameters:
- `SSH_SERVER` — remote SSH server IP/hostname
- `SSH_PORT` — SSH port (default: `22`)
- `SSH_USER` — remote server username
- `VIDEO_PORT` — remote server port for video streaming (default: `8080`)
- `MOON_PORT` — remote server port for Moonraker (default: `7125`)
- `REMOTE_enN` — command to execute on the remote server (default: `"NONE"`).
  Example: Use `./ff5m.sh bot1` (located in `mod/telegram/`) to restart the Telegram bot.

**Setup script (if not installed via one-command):**
```bash
su - tbot  # Switch to the bot service user
wget --cache=off -q -O ff5m.sh https://raw.githubusercontent.com/ghzserg/zmod_ff5m/main/telegram/ff5m.sh
chmod +x ff5m.sh
```

**Example usage in Fluidd/Mainsail console:**
```
ZSSH_ON SSH_SERVER=remote.server.ru SSH_PORT=22 SSH_USER=tbot VIDEO_PORT=8080 MOON_PORT=7125 REMOTE_enN="./ff5m.sh bot1"
```

SSH starts 3 minutes after Klipper boots and automatically restarts at the beginning of prints (via `START_PRINT` macro).

[Telegram Bot details](https://github.com/ghzserg/zmod/wiki/Telegram_en)

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)

</div>

---
### ZSSH_OFF

Disable SSH client.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)

</div>

---
### ZSSH_RESTART

Restart the SSH client.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)

</div>

---
### ZSSH_RELOAD

Reload SSH client if not running.
This macro is triggered at the start of prints (via `START_PRINT`).

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)

</div>

---
### ZRESTORE

Resume printing after power loss or printer errors.

**Requirements:**
- Native screen must be disabled (native recovery conflicts with ZRESTORE).
- Printed filename **must not start with a number**.

---
<div align="center">

[![Back](https://github.com/ghzserg/zmod/wiki/images/Back.svg)](https://github.com/ghzserg/zmod/wiki/System_en)
[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)
[![Forward](https://github.com/ghzserg/zmod/wiki/images/Forward.svg)](https://github.com/ghzserg/zmod/wiki/Filament_en)

</div>

---
### ZLINK

Connect to the cloud [zmod.link](https://zmod.link)

- The cloud allows you to manage the printer via Fluidd or Mainsail from anywhere.
- Memory usage on the printer increases by 1 MB.
- Data is transmitted from the printer to the cloud using encryption.
- Access to the cloud from anywhere also uses encryption.
- The user only sees their own printers and cannot connect to others.
- Access to user printers is protected by login and password

How to get login and password:
1. Connect to the bot [@zmod_help_bot](https://t.me/zmod_help_bot)
2. Enter the command ```cloud``` - if you have registered before, it will tell you your login
3. To register a user with the name `test`, enter: ```cloud register test```
4. To reset the password, enter: ```cloud reset_password```

How to connect to the cloud [zmod.link](https://zmod.link):
1. Go to the website [zmod.link](https://zmod.link/) and enter your login and password

   <img width="547" height="615" alt="{264D6782-600F-4700-B9D2-0582F7427FD2}" src="https://github.com/user-attachments/assets/d8d3f51e-4fc7-4e1e-8fa7-dfc07ddbeab2" />
2. Click the "Add Printer" button

   <img width="569" height="502" alt="image" src="https://github.com/user-attachments/assets/72346ee6-dde6-4736-80b1-2eb2927bf983" />
3. Open the printer in a separate tab and in the printer console, enter the command ```ZLINK```

   <img width="1563" height="163" alt="{90DC4366-D258-4912-8028-22C589DF4E91}" src="https://github.com/user-attachments/assets/bee350ee-8d99-465c-9621-48788c6f7a9c" />
4. Copy the key to the clipboard - it is highlighted in the screenshot
5. Enter the printer name and the key you copied in the previous step

   Example:
   - `testprinter`
   - `ecdsa-sha2-nistp256 AAAAE2VjZHNhLXNoYTItbmlzdHAyNTYAAAAIbmlzdHAyNTYAAABBBDxX5XzNDXg+sbTArdiOzFpMtHXzgAhfC2N2ogS4TUsQYV4AD6HfSFL3J4ISNZ2DgesZf35rfH1I/qI2ckQVGlE=`

   <img width="557" height="775" alt="{E4FC2206-84BC-4134-92C2-B4253D8F23E5}" src="https://github.com/user-attachments/assets/b6401b71-5827-480d-ba1c-b7114f87177b" />

   Click the "Add Printer" button
6. Copy the command provided by the website and paste it into the printer console

   <img width="558" height="652" alt="{CDC8146F-B9DF-44A1-9C0B-3E6828CD540E}" src="https://github.com/user-attachments/assets/ed92a80f-93cc-41b8-bde1-aa0b2b2c0ecc" />

   In the example: ```zlink p=testprinter u=test m=10006 c=30006```

   Click the ```I have already pasted the string into the printer``` button

   After this, the printer will be able to connect to the cloud.

   To disable the connection, enter ```ZLINK_OFF```

7. Now you have the ability to connect to Fluidd or Mainsail via the internet

   <img width="526" height="654" alt="{CA6FC599-6060-4E3B-B525-EBB76D8780A1}" src="https://github.com/user-attachments/assets/0208dbad-8627-4636-b971-cfe0c5d7f8bd" />

   Just select the desired button.

PS: The camera may load later than the interface - this is normal

PPS: If something is not working correctly, refresh the page with Ctrl + F5 and go to [zmod.link](https://zmod.link)

   <img width="540" height="449" alt="{30D01CA4-3E9E-40EC-BCD1-9A8597DCCFDE}" src="https://github.com/user-attachments/assets/0d48b9be-a9df-4bfd-a38a-6d883ab31e73" />

   <img width="500" height="393" alt="{D03D643F-907C-4A6D-A48E-D881AAC33268}" src="https://github.com/user-attachments/assets/69f9d8d5-67ca-476e-b362-e35abb1d4832" />

---
<div align="center">

[![Back](https://github.com/ghzserg/zmod/wiki/images/Back.svg)](https://github.com/ghzserg/zmod/wiki/System_en)
[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod)
[![Forward](https://github.com/ghzserg/zmod/wiki/images/Forward.svg)](https://github.com/ghzserg/zmod/wiki/Filament_en)

</div>
