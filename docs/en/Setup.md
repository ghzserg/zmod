# [Setup](#installing-the-mod)

---

## Restoring Printer to Factory Settings (Required for Mod Installation)

0. [Uninstall KlipperMod](https://github.com/xblax/flashforge_ad5m_klipper_mod/blob/master/docs/UNINSTALL.md) if previously installed.
1. Reset the printer to default settings.
2. Format a USB drive to FAT/FAT16/FAT32.
3. Copy the appropriate file from the [Native firmware](/Native_FW/) to the USB root directory:

    - [Adventurer5M-3.1.9-2.2.3-20250807-Factory.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-3.1.9-2.2.3-20250807-Factory.tgz) for FF5M
       - [Adventurer5MPro-3.1.3-2.2.3-20250107-Factory.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-3.1.3-2.2.3-20250107-Factory.tgz) for FF5m**Pro** версии 
       - [AD5X-1.1.6-1.1.0-3.0.6-20250722.tgz](https://github.com/ghzserg/FF/releases/download/R/AD5X-1.1.6-1.1.0-3.0.6-20250722.tgz) for AD5X

4. Power off the printer.
5. Insert the usb drive into printer usb port.
6. Power on the printer.
7. Wait for the stock firmware installation to complete.
8. Configure Wi-Fi or Lan *new beaver*
9. Install the latest printer updates.

---

## Installing the Mod

[Video](https://www.youtube.com/watch?v=2sfb2OtY7wM)

1. **[Restore the printer to factory settings](/Setup/#restoring-printer-to-factory-settings-required-for-mod-installation).**  [AD5X Warning](/Setup/#ad5x-warning)
2. Format a USB drive to FAT/FAT16/FAT32.
3. Copy the [mod file](https://github.com/ghzserg/zmod/releases/) to the USB root directory:

    - For FF5M: Adventurer5M-**zmod**-*.tgz
       - For FF5M Pro: Adventurer5MPro-**zmod**-\*.tgz
       - For [AD5X](/AD5X/): AD5X-**zmod**-*.tgz

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
    
    If the web interface doesn't open, the stock firmware has disabled the mod. To enable it, copy the file [AD5X-ENABLE-zmod.tgz](https://github.com/ghzserg/FF/releases/download/R/AD5X-ENABLE-zmod.tgz) to a USB flash drive and [activate the mod](/ru/R//#ad5x-enable-zmodtgz).

12. Translate the mod into your language.

    <img width="564" height="583" alt="{8E14F84D-E8D1-4129-B192-AA335243A3D9}" src="https://github.com/user-attachments/assets/e6dd3f8a-3cc3-4a05-b5fb-ad8ba372ede6" />
    
    Or type in the console: ```LANG LANG=en```
    
    <img width="881" height="502" alt="image" src="https://github.com/user-attachments/assets/cf3f797d-80e0-4864-85b4-cd28886590f4" />

13. Configure the mod

    <img width="558" height="219" alt="{B34D2AF2-F2A6-433D-B9F8-86A83389D5A7}" src="https://github.com/user-attachments/assets/a79ec692-a284-4cb8-a0ad-3be10f33d813" />
    
    This shows parameters used at print start, print end, and global settings. It is recommended to just review the settings — do not change them unless necessary. The description for each parameter can be [found here](/Global/).

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

18. [Send Files via "Octo/Klipper" for Printing](/Recomendations/#send-files-via-octoklipper-for-printing)

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

20. [Enable MD5 verification](/Recomendations/#enable-md5-checksum-control)

    <img width="307" height="131" alt="image" src="https://github.com/user-attachments/assets/c90c096e-ff42-4479-b094-9d57261e7f36" />

21. [Read the recommendations](/Recomendations/)
22. [Read the FAQ](/FAQ/)

### AD5X Warning

[@Khamai](https://t.me/Khamai)

After installing the Native Firmware, the print head may not be correctly positioned against the filament receiver (the receiver shutter may not be fully closed, filament may be pushed onto the table, etc.).

[Via the engineering menu on the stock firmware](/AD5X/#setting-up-the-basket-on-the-ad5x-stock-firmware)

If you encounter this issue, you need to calibrate the print head position using the following algorithm:

1. Download the [Set.XY.Offset.zip](https://github.com/ghzserg/FF/releases/download/R/Set.XY.Offset.zip) archive and unzip it to the root of a flash drive.
2. Insert the flash drive into the turned-off printer and turn it on.
3. The calibration interface will appear on the printer screen. Press Reset.
4. Use the control arrows to position the print head against the receiver so that the print head presses the shutter lever firmly, the nozzle is behind the movable shutter, and the shutter itself is flush with the front surface of the receiver.
5. Press the Set button to confirm the calibration result.
6. Remove the flash drive and reboot the printer.

---

## Updating the Mod

If the mod displays ("Update ZMOD via USB"), you must update via USB, even if recently updated.

**Updating via USB preserves all data.**

**Simplest method:** Use the [ZFLASH](/Zmod/#zflash) macro. Insert the USB drive, reboot the printer, and run `ZFLASH`. The macro will:

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

---

## Removing or Temporarily Disabling the Mod

- **[SKIP_ZMOD](/Zmod/#skip_zmod)**: Reboots without starting Moonraker/Fluidd.
- **[REMOVE_ZMOD](/Zmod/#remove_zmod)**: Fully uninstalls the mod.

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

---

## Updating Stock Firmware

1. Disable all active plugins except `recommend`, `timelapse`, and `notify`:
   ```DISABLE_PLUGIN name=plugin_name```

2. If you are using **Klipper 13**, run ```UPDATE_MCU``` *before* updating the stock firmware. This prevents version mismatch issues between the MCU and Klipper.
3. Enable Chinese cloud services (if you wish to update via the stock touchscreen):
   ```SAVE_ZMOD_DATA CHINA_CLOUD=1```

**For [AD5X](/ru/AD5X/), [zMod activation](/Native_FW/) is required via `AD5X-ENABLE-zmod.tgz` from a USB drive—after updating the stock firmware.**

---

## Support Mod Development

BTC `17wXTd9BqYp1K3zCLTxVyGLEXUDjf7XNLL`

---

## Boot Recovery

*Guide by [@darksimpson](https://t.me/darksimpson), [Alexander](https://github.com/DrA1ex), [@Ikaros413](https://t.me/Ikaros413), [@SoloMen88](https://t.me/SoloMen88)*

**Symptoms:** Printer freezes on boot screen and is unreachable via LAN.

![](../images/ff.jpg)

Try restoring the firmware by installing a full firmware:

- [FF5M](/Native_FW/#installing-full-firmware-on-ff5m)
- [AD5X](/Native_FW/#installing-full-firmware-on-ad5x)

**Steps:**

1. **Unplug the printer.**
2. Prepare a **3.3V UART/USB converter** (ensure jumper is set to 3.3V).

![](../images/ch340.jpg)

3. Open the printer’s rear panel.
4. Connect to the UART pins (RX, TX, GND — **do NOT connect 3.3V**).

![](../images/connect.jpg)

**WARNING:** 5V input will damage the motherboard!

5. Connect the converter crosswise:

    - Converter RX → Printer TX
       - Converter TX → Printer RX
       - Converter GND → Printer GND

![](../images/connect_photo.jpg)

6. Identify the new COM port in your OS.

![](../images/port.jpg)

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
