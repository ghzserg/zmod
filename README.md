# FF5M / FF5M Pro / AD5X ZMOD

> [!CAUTION]
> *If you want to install this mod on your AD5M (Pro) / AD5X, be aware that you risk voiding the warranty or damaging the printer. Proceed at your own risk if you wish to try this mod!*
> 
> If you don’t know what this is, don’t understand why a Klipper web interface is needed, or are simply satisfied with the stock firmware, do NOT install this modification. For everyone else – **please read the entire instructions carefully!**
>
> After installing the mod, if you don’t want to delve into details – just print as usual. No additional configuration or changes are required. If you decide to explore further – proceed by reading the documentation.

[На русском](https://github.com/ghzserg/zmod/blob/main/README_ru.md)

Latest version: **1.5.3** can only be installed via USB flash drive or the [ZFLASH](https://github.com/ghzserg/zmod/wiki/Zmod_en#zflash) macro.

**Macro [LANG](https://github.com/ghzserg/zmod/wiki/Global_en#lang) - change language (RU/EN/DE/IT/FR/ES/ZH/JA/KO)**

- [Download](https://github.com/ghzserg/zmod/releases/)
- [Install](https://github.com/ghzserg/zmod/wiki/Setup_en#installing-the-mod)

MD5:
- AD5X-zmod-1.5.2.tgz `75c7ec15f7706553deae0b404d1d8bca`
- Adventurer5MPro-zmod-1.5.3.tgz `34c5c4aab95ab72e1d694a1336be240c`
- Adventurer5M-zmod-1.5.3.tgz `34c5c4aab95ab72e1d694a1336be240c`

How to verify:
- Navigate to the folder containing Adventurer5M-zmod-1.5.3.tgz
- Right-click on an empty space -> `Open in Terminal`
- Run:  
  `certutil -hashfile Adventurer5M-zmod-1.5.3.tgz md5`  
  `certutil -hashfile Adventurer5MPro-zmod-1.5.3.tgz md5`  
  `certutil -hashfile AD5X-zmod-1.5.3.tgz md5`
- Ensure the checksums match.

Compatible with clean firmware versions:
- FF5M/FF5MPro: v2.7.5 or higher (2.7.5, 2.7.6, 2.7.7, 2.7.8, 2.7.9, 3.1.3, **3.1.4**, 3.1.5)
- AD5X: only (**1.0.2**, 1.0.7, 1.0.8)

Clean firmware files are located in the [Native firmware](https://github.com/ghzserg/zmod/releases/tag/R) folder.

## Do NOT install this mod if the following stock firmware fixes suffice

These features are ported to the stock firmware:
1. I want to install Klipper. (Klipper is already in the printer, but there is no web interface)
2. [Install root](https://github.com/ghzserg/zmod/tree/main/Native_firmware/root)
3. [E0011 error fix](https://github.com/ghzserg/zmod/wiki/Global_en#fix_e0011)
4. [E0017 error fix](https://github.com/ghzserg/zmod/wiki/Global_en#fix_e0017)
5. [Disable printer updates/telemetry/Chinese clouds](https://github.com/ghzserg/zmod/wiki/Global_en#china_cloud)
6. [Factory reset](https://github.com/ghzserg/zmod/wiki/Setup_en#restoring-printer-to-factory-settings-required-for-mod-installation)
7. [Convert FF5M to FF5MPro](https://github.com/ghzserg/zmod/tree/main/Native_firmware/5m2Pro)
8. [Convert FF5MPro to FF5M](https://github.com/ghzserg/zmod/tree/main/Native_firmware/Pro25M)

## Moonraker and Fluidd/Mainsail/GuppyScreen Support on Stock Klipper
Supported features:
1. Support for [the following languages](https://github.com/ghzserg/zmod/wiki/Global_en#lang): English, German, French, Italian, Spanish, Chinese, Japanese, Korean
2. Web interface based on [Fluidd](https://docs.fluidd.xyz/) or [Mainsail](https://docs.mainsail.xyz/) (port 80)
3. File upload and printing via Octoprint/Fluidd/FlashForge/Mainsail/[GuppyScreen](https://github.com/ghzserg/zmod/wiki/System_en#display_off)/[Telegram Bot](https://github.com/ghzserg/zmod/wiki/Telegram_en)
4. [Print recovery after power loss](https://github.com/ghzserg/zmod/wiki/Zmod_en#zrestore)
5. Adaptive bed mesh with [KAMP](https://github.com/ghzserg/zmod/wiki/Calibrations_en#kamp)
6. [Bed leveling](https://github.com/ghzserg/zmod/wiki/Calibrations_en#auto_full_bed_level) at any temperature, optionally triggered at print start
7. [Input Shaper calibration with graphs](https://github.com/ghzserg/zmod/wiki/Calibrations_en#zshaper), accounting for [SCV](https://github.com/ghzserg/zmod/wiki/Global_en#fix_scv) ([square_corner_velocity](https://www.klipper3d.org/Config_Reference.html#printer)).
8. [Bed screw adjustment](https://github.com/ghzserg/zmod/wiki/Calibrations_en#bed_level_screws_tune)
9. PID calibration for [extruder](https://github.com/ghzserg/zmod/wiki/Calibrations_en#pid_tune_extruder) and [bed](https://github.com/ghzserg/zmod/wiki/Calibrations_en#pid_tune_bed).
10. [Nozzle cleaning (stock-like)](https://github.com/ghzserg/zmod/wiki/Main_en#clear_nozzle)
11. Support for both stock and [alternative camera implementation](https://github.com/ghzserg/zmod/wiki/Zmod_en#camera_on) (saves memory and allows resolution changes).
12. Moonraker-telegram-bot support on [external hosts](https://github.com/ghzserg/zmod/wiki/Telegram_en)
13. [MIDI file playback](https://github.com/ghzserg/zmod/wiki/Main_en#play_midi)
14. [MD5 verification](https://github.com/ghzserg/zmod/wiki/System_en#check_md5) for network transfers
15. Automatic updates for `Fluidd`/`Mainsail`/`Moonraker` and ZMOD via network
16. [Headless mode (no stock screen)](https://github.com/ghzserg/zmod/wiki/System_en#display_off). Saves 20MB RAM.
17. [GuppyScreen](https://github.com/ghzserg/zmod/wiki/System_en#display_off) – lightweight screen replacement
18. ROOT access and `mc` support
19. [COLDPULL](https://github.com/ghzserg/zmod/wiki/Filament_en#coldpull) (nozzle cleaning) without force. Based on [this method](https://t.me/FF_5M_5M_Pro/2836/447172).
21. [Entware](https://github.com/ghzserg/zmod/wiki/FAQ_en#entware-in-zmod-how-to-use-it)
22. Fixed [E0011 error](https://github.com/ghzserg/zmod/wiki/Global_en#fix_e0011)
23. Fixed [E0017 error](https://github.com/ghzserg/zmod/wiki/Global_en#fix_e0017)
24. [Rollback from firmware](https://github.com/ghzserg/zmod/wiki/FAQ_en#what-is-firmware-retraction)
25. [Automatic print stop on part detachment or nozzle collision](https://github.com/ghzserg/zmod/wiki/Global_en#nozzle_control).
26. [File/permissions/symlink verification and repair](https://github.com/ghzserg/zmod/wiki/System_en#check_system)
27. Stock screen menu functionality remains unchanged

## Version History
[Changelog](https://github.com/ghzserg/zmod/wiki/Changelog_en)

## FAQ

[Must-read](https://github.com/ghzserg/zmod/wiki/FAQ_en)

## Printer Stability Recommendations

[Read if encountering issues](https://github.com/ghzserg/zmod/wiki/Recomendations_en)

## Macro List

All features are accessed via macros.

[Macro List](https://github.com/ghzserg/zmod/wiki/Macros_en)

## Configuration Storage
Access the **mod_data** folder via Fluidd web interface:  
`Configuration` → `Configuration Files` → `mod_data`

- Custom Klipper settings go into `mod_data/user.cfg`, which can override/supplement `printer_base.cfg`.
- Custom Moonraker settings go into `mod_data/user.moonraker.cfg`.
- Custom MIDI files are stored in `mod_data/midi/`.
- Global mod settings are saved via the [SAVE_ZMOD_DATA](https://github.com/ghzserg/zmod/wiki/Global_en#save_zmod_data) macro.
- Shutdown scripts are stored in `mod_data/power_off.sh`.
- Power on scripts are stored in `mod_data/power_on.sh`.

## Known Peculiarities:
- During actions like `M109` (extruder heating), `M190` (bed heating), PID calibration, or any gcode-pausing task, the stock screen freezes.
- Restarting Klipper freezes the stock screen (use [NEW_SAVE_CONFIG](https://github.com/ghzserg/zmod/wiki/Main_en#new_save_config) for restarts).
- After canceling a print, press "OK" on the stock screen (use [CLOSE_DIALOGS](https://github.com/ghzserg/zmod/wiki/Main_en#close_dialogs) or [FAST_CLOSE_DIALOGS](https://github.com/ghzserg/zmod/wiki/Main_en#fast_close_dialogs)).
- The stock screen always loads the `DEFAULT_MESH` profile when starting a print and deletes the `Default` profile post-print.

## Screenless Version Notes:
- Remove all start gcode and use [START_PRINT](https://github.com/ghzserg/zmod/wiki/Main_en#start_print) and [END_PRINT](https://github.com/ghzserg/zmod/wiki/Main_en#end_print) macros.
- Stock camera disabled; use the alternative via [CAMERA_ON](https://github.com/https://github.com/ghzserg/zmod/wiki/Zmod_en#camera_on).
- Manually set [Z_OFFSET] in [START_PRINT](https://github.com/ghzserg/zmod/wiki/Main_en#start_print) or use [LOAD_ZOFFSET](https://github.com/ghzserg/zmod/wiki/Global_en#load_zoffset) to load saved offsets.
- Bed mesh `auto` loads automatically on startup.
- FlashForge protocol is unsupported (handled by the screen). Use "Octo/Klipper":  
  - Protocol: `Octo/Klipper`  
  - Hostname: `printer_IP:7125`  
  - URL: `printer_IP`

## Credits

- Root access based on [@darksimpson](https://t.me/darksimpson)'s work. Login: `root`, password: `root`. [Link](https://t.me/c/2000598629/12695/186253)
- Beeper (M300) implementation by [@drmax_gc](https://t.me/drmax_gc). [Link](https://t.me/FF_5M_5M_Pro/1/333800)
- MD5 verification by Igor Polunovskiy. [Link](https://t.me/FF_5M_5M_Pro/12695/272417)
- [GuppyScreen](https://github.com/ballaswag/guppyscreen)

This mod builds upon [KlipperMod](https://github.com/xblax/flashforge_ad5m_klipper_mod/) but is not a direct continuation and is incompatible with it.

## Installation/Update/Removal

[Installation/Update/Removal Guide](https://github.com/ghzserg/zmod/wiki/Setup_en)

## Support Development

BTC: 17wXTd9BqYp1K3zCLTxVyGLEXUDjf7XNLL
