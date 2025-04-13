# FF5M / FF5M Pro / AD5X ZMOD

> [!CAUTION]
> *If you want to install this mod on your AD5M (Pro) / AD5X, be aware that you risk voiding the warranty or damaging the printer. Proceed at your own risk if you wish to try this mod!*
> 
> If you don’t know what this is, don’t understand why a Klipper web interface is needed, or are simply satisfied with the stock firmware, do NOT install this modification. For everyone else – **please read the entire instructions carefully!**
>
> After installing the mod, if you don’t want to delve into details – just print as usual. No additional configuration or changes are required. If you decide to explore further – proceed by reading the documentation.

[На русском](https://github.com/ghzserg/zmod/blob/main/README_ru.md)

Latest version: **1.4.3** can only be installed via USB flash drive or the [ZFLASH](https://github.com/ghzserg/zmod/wiki/Macros_en#zflash) macro.

**Macro [LANG](https://github.com/ghzserg/zmod/wiki/Macros_en#lang) - change language (RU/EN/DE/IT/FR/ES)**

[Download](https://github.com/ghzserg/zmod/releases/).

MD5 checksums:
- AD5X-zmod-1.4.3.tgz `c2cf7ff86171b4412bf1dfae9564815e`
- Adventurer5MPro-zmod-1.4.3.tgz `8aac25b685c4578f25e23ac35ca4020d`
- Adventurer5M-zmod-1.4.3.tgz `8aac25b685c4578f25e23ac35ca4020d`

How to verify:
- Navigate to the folder containing Adventurer5M-zmod-1.4.3.tgz
- Right-click on an empty space -> `Open in Terminal`
- Run:  
  `certutil -hashfile Adventurer5M-zmod-1.4.3.tgz md5`  
  `certutil -hashfile Adventurer5MPro-zmod-1.4.3.tgz md5`  
  `certutil -hashfile AD5X-zmod-1.4.3.tgz md5`
- Ensure the checksums match.

Compatible with clean firmware versions:
- FF5M/FF5MPro: **v2.7.5 or higher** (2.7.5, 2.7.6, 2.7.7, 2.7.8, 2.7.9, 3.1.3, 3.1.4, 3.1.5)
- AD5X: **only v1.0.2**

Clean firmware files are located in the [Stock_Firmware](https://github.com/ghzserg/zmod/tree/main/%D0%A0%D0%BE%D0%B4%D0%BD%D0%B0%D1%8F_%D0%BF%D1%80%D0%BE%D1%88%D0%B8%D0%B2%D0%BA%D0%B0) folder.

## Do NOT install this mod if the following stock firmware fixes suffice

These features are ported to the stock firmware:
0. I want to install Klipper. (Klipper is already in the printer, but there is no web interface)
1. [E0011 error fix](https://github.com/ghzserg/zmod/wiki/Macros_en#fix_e0011)
2. [E0017 error fix](https://github.com/ghzserg/zmod/wiki/Macros_en#fix_e0017)
3. [Disable printer updates/telemetry/Chinese clouds](https://github.com/ghzserg/zmod/wiki/Macros_en#china_cloud)
4. [Factory reset](https://github.com/ghzserg/zmod/wiki/Setup_en#restoring-printer-to-factory-settings-required-for-mod-installation)
5. [Convert FF5M to FF5MPro](https://github.com/ghzserg/zmod/tree/main/%D0%A0%D0%BE%D0%B4%D0%BD%D0%B0%D1%8F_%D0%BF%D1%80%D0%BE%D1%88%D0%B8%D0%B2%D0%BA%D0%B0/5m2Pro)
6. [Convert FF5MPro to FF5M](https://github.com/ghzserg/zmod/tree/main/%D0%A0%D0%BE%D0%B4%D0%BD%D0%B0%D1%8F_%D0%BF%D1%80%D0%BE%D1%88%D0%B8%D0%B2%D0%BA%D0%B0/Pro25M)

## Moonraker and Fluidd/Mainsail/GuppyScreen Support on Stock Klipper
Supported features:
0. Support for the [following languages](https://github.com/ghzserg/zmod/wiki/Macros_en#lang): English, German, French, Italian, Spanish
1. Web interface based on [Fluidd](https://docs.fluidd.xyz/) or [Mainsail](https://docs.mainsail.xyz/) (port 80)
2. File upload and printing via Octoprint/Fluidd/FlashForge/Mainsail/[GuppyScreen](https://github.com/ghzserg/zmod/wiki/Macros_en#display_off)/[Telegram Bot](https://github.com/ghzserg/zmod/wiki/Macros_en#telegram-bot)
3. [Print recovery after power loss](https://github.com/ghzserg/zmod/wiki/Macros_en#zrestore)
4. Adaptive bed mesh with [KAMP](https://github.com/ghzserg/zmod/wiki/Macros_en#kamp)
5. [Bed leveling](https://github.com/ghzserg/zmod/wiki/Macros_en#auto_full_bed_level) at any temperature, optionally triggered at print start
6. [Input Shaper calibration with graphs](https://github.com/ghzserg/zmod/wiki/Macros_en#zshaper), accounting for [SCV](https://github.com/ghzserg/zmod/wiki/Macros_en#fix_scv) ([square_corner_velocity](https://www.klipper3d.org/Config_Reference.html#printer)).
7. [Bed screw adjustment](https://github.com/ghzserg/zmod/wiki/Macros_en#bed_level_screws_tune)
8. PID calibration for [extruder](https://github.com/ghzserg/zmod/wiki/Macros_en#pid_tune_extruder) and [bed](https://github.com/ghzserg/zmod/wiki/Macros_en#pid_tune_bed).
9. [Nozzle cleaning (stock-like)](https://github.com/ghzserg/zmod/wiki/Macros_en#clear_nozzle)
10. Support for both stock and [alternative camera implementation](https://github.com/ghzserg/zmod/wiki/Macros_en#camera_on) (saves memory and allows resolution changes).
11. Moonraker-telegram-bot support on [external hosts](https://github.com/ghzserg/zmod/wiki/Macros_en#telegram-bot)
12. [MIDI file playback](https://github.com/ghzserg/zmod/wiki/Macros_en#play_midi)
13. [MD5 verification](https://github.com/ghzserg/zmod/wiki/Macros_en#check_md5) for network transfers
14. Automatic updates for `Fluidd`/`Mainsail`/`Moonraker` and ZMOD via network
15. [Headless mode (no stock screen)](https://github.com/ghzserg/zmod/wiki/Macros_en#display_off). Saves 20MB RAM.
16. [GuppyScreen](https://github.com/ghzserg/zmod/wiki/Macros_en#display_off) – lightweight screen replacement
17. ROOT access and `mc` support
18. [COLDPULL](https://github.com/ghzserg/zmod/wiki/Macros_en#coldpull) (nozzle cleaning) without force. Based on [this method](https://t.me/FF_5M_5M_Pro/2836/447172).
19. [Entware](https://github.com/ghzserg/zmod/wiki/FAQ_en#entware-in-zmod-how-to-use-it)
20. Fixed [E0011 error](https://github.com/ghzserg/zmod/wiki/Macros_en#fix_e0011)
21. Fixed [E0017 error](https://github.com/ghzserg/zmod/wiki/Macros_en#fix_e0017)
22. [Rollback from firmware](https://github.com/ghzserg/zmod/wiki/FAQ_en#what-is-firmware-retraction)
23. [Automatic print stop on part detachment or nozzle collision](https://github.com/ghzserg/zmod/wiki/Macros_en#nozzle_control).
24. [File/permissions/symlink verification and repair](https://github.com/ghzserg/zmod/wiki/Macros_en#check_system)
25. Stock screen menu functionality remains unchanged

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
- Global mod settings are saved via the [SAVE_ZMOD_DATA](https://github.com/ghzserg/zmod/wiki/Macros_en#save_zmod_data) macro.
- Shutdown scripts are stored in `mod_data/power_off.sh`.
- Power on scripts are stored in `mod_data/power_on.sh`.

## Known Peculiarities:
- During actions like `M109` (extruder heating), `M190` (bed heating), PID calibration, or any gcode-pausing task, the stock screen freezes.
- Restarting Klipper freezes the stock screen (use [NEW_SAVE_CONFIG](https://github.com/ghzserg/zmod/wiki/Macros_en#new_save_config) for restarts).
- After canceling a print, press "OK" on the stock screen (use [CLOSE_DIALOGS](https://github.com/ghzserg/zmod/wiki/Macros_en#close_dialogs) or [FAST_CLOSE_DIALOGS](https://github.com/ghzserg/zmod/wiki/Macros_en#fast_close_dialogs)).
- The stock screen always loads the `DEFAULT_MESH` profile when starting a print and deletes the `Default` profile post-print.

## Screenless Version Notes:
- Remove all start gcode and use [START_PRINT](https://github.com/ghzserg/zmod/wiki/Macros_en#start_print) and [END_PRINT](https://github.com/ghzserg/zmod/wiki/Macros_en#end_print) macros.
- Stock camera disabled; use the alternative via [CAMERA_ON](https://github.com/ghzserg/zmod/wiki/Macros_en#camera_on).
- Manually set [Z_OFFSET](https://github.com/ghzserg/zmod/wiki/Macros_en#%D1%8D%D1%82%D0%BE-%D0%BD%D0%B5-%D0%BF%D0%B0%D1%80%D0%B0%D0%BC%D0%B5%D1%82%D1%80%D1%8B-start_print-%D1%8D%D1%82%D0%BE-%D0%B3%D0%BB%D0%BE%D0%B1%D0%B0%D0%BB%D1%8C%D0%BD%D1%8B%D0%B5-%D1%84%D0%BB%D0%B0%D0%B3%D0%B8%D0%BF%D0%B0%D1%80%D0%B0%D0%BC%D0%B5%D1%82%D1%80%D1%8B-%D0%BA%D0%BE%D1%82%D0%BE%D1%80%D1%8B%D0%B5-%D1%81%D1%82%D0%B0%D0%B2%D0%B8%D1%82%D1%81%D1%8F-%D1%87%D0%B5%D1%80%D0%B5%D0%B7-save_zmod_data) in [START_PRINT](https://github.com/ghzserg/zmod/wiki/Macros_en#start_print) or use [LOAD_ZOFFSET](https://github.com/ghzserg/zmod/wiki/Macros_en#load_zoffset) to load saved offsets.
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

[Donate to support development](https://vtb.paymo.ru/collect-money/?transaction=0efce2b8-c321-4cb1-a6f9-5b7a9d34e34f)
