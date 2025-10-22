# FF5M / FF5M Pro / AD5X ZMOD

> [!CAUTION]
> *If you want to install this mod on your AD5M (Pro) / [AD5X](https://github.com/ghzserg/zmod/wiki/AD5X_en), be aware that you risk voiding the warranty or damaging the printer. Proceed at your own risk if you wish to try this mod!*
> 
> If you don’t know what this is, don’t understand why a Klipper web interface is needed, or are simply satisfied with the stock firmware, do NOT install this modification. For everyone else – **please read the entire instructions carefully!**
>
> After installing the mod, if you don’t want to delve into details – just print as usual. No additional configuration or changes are required. If you decide to explore further – proceed by reading the [documentation](https://ghzserg.github.io/).

[На русском](https://github.com/ghzserg/zmod/blob/main/README_ru.md)

Latest version: **1.6.1** can only be installed via USB flash drive or the [ZFLASH](https://github.com/ghzserg/zmod/wiki/Zmod_en#zflash) macro.

[https://ghzserg.github.io/](https://ghzserg.github.io/)

**Macro [LANG](https://github.com/ghzserg/zmod/wiki/Global_en#lang) - change language (RU/EN/DE/IT/FR/ES/ZH/JA/KO)**

- [Download](https://github.com/ghzserg/zmod/releases/)
- [Install](https://github.com/ghzserg/zmod/wiki/Setup_en#installing-the-mod)

MD5:
- AD5X-zmod-1.6.1.tgz `c662819771eb9c0f8e00cd0e1a09c847`
- Adventurer5MPro-zmod-1.6.1.tgz `ed617b7455e915d7e0d717cbe296ddf6`
- Adventurer5M-zmod-1.6.1.tgz `ed617b7455e915d7e0d717cbe296ddf6`

How to verify:
- Navigate to the folder containing Adventurer5M-zmod-1.6.1.tgz
- Right-click on an empty space -> `Open in Terminal`
- Run:
  `certutil -hashfile Adventurer5M-zmod-1.6.1.tgz md5`
  `certutil -hashfile Adventurer5MPro-zmod-1.6.1.tgz md5`
  `certutil -hashfile AD5X-zmod-1.6.1.tgz md5`
- Ensure the checksums match.

Compatible with clean firmware versions:
- FF5M/FF5MPro: v2.7.5 or higher (2.7.5, 2.7.6, 2.7.7, 2.7.8, 2.7.9, 3.1.3, **3.1.4**, 3.1.5, 3.1.9, 3.2.3)
- [AD5X](https://github.com/ghzserg/zmod/wiki/AD5X_en): only (1.0.2, 1.0.7, 1.0.8, 1.0.9, 1.1.1, 1.1.6, **1.1.7**)

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

## Plugins
zMod support [Pluggins](https://github.com/ghzserg/g28_tenz/blob/main/Plugin_en.md)

## Moonraker and Fluidd/Mainsail/GuppyScreen Support on Stock Klipper
Supported features:
1. Klipper 13, zMod 1.6.0+. [UPDATE_MCU](https://github.com/ghzserg/zmod/wiki/System_en#update_mcu)
2. Support for [the following languages](https://github.com/ghzserg/zmod/wiki/Global_en#lang): English, German, French, Italian, Spanish, Chinese, Japanese, Korean
3. Web interface based on [Fluidd](https://docs.fluidd.xyz/) or [Mainsail](https://docs.mainsail.xyz/) (port 80)
4. File upload and printing via Octoprint/Fluidd/FlashForge/Mainsail/[GuppyScreen](https://github.com/ghzserg/zmod/wiki/System_en#display_off)/[Telegram Bot](https://github.com/ghzserg/zmod/wiki/Telegram_en)
5. [Print recovery after power loss](https://github.com/ghzserg/zmod/wiki/Zmod_en#zrestore)
6. Adaptive bed mesh with [KAMP](https://github.com/ghzserg/zmod/wiki/Calibrations_en#kamp)
7. [Bed leveling](https://github.com/ghzserg/zmod/wiki/Calibrations_en#auto_full_bed_level) at any temperature, optionally triggered at print start
8. [Input Shaper calibration with graphs](https://github.com/ghzserg/zmod/wiki/Calibrations_en#zshaper), accounting for [SCV](https://github.com/ghzserg/zmod/wiki/Global_en#fix_scv) ([square_corner_velocity](https://www.klipper3d.org/Config_Reference.html#printer)).
9. [Bed screw adjustment](https://github.com/ghzserg/zmod/wiki/Calibrations_en#bed_level_screws_tune)
10. PID calibration for [extruder](https://github.com/ghzserg/zmod/wiki/Calibrations_en#pid_tune_extruder) and [bed](https://github.com/ghzserg/zmod/wiki/Calibrations_en#pid_tune_bed).
11. [Nozzle cleaning (stock-like)](https://github.com/ghzserg/zmod/wiki/Main_en#clear_nozzle)
12. Support for both stock and [alternative camera implementation](https://github.com/ghzserg/zmod/wiki/Zmod_en#camera_on) (saves memory and allows resolution changes).
13. Moonraker-telegram-bot support on [external hosts](https://github.com/ghzserg/zmod/wiki/Telegram_en)
14. [MIDI file playback](https://github.com/ghzserg/zmod/wiki/Main_en#play_midi)
15. [MD5 verification](https://github.com/ghzserg/zmod/wiki/System_en#check_md5) for network transfers
16. Automatic updates for `Fluidd`/`Mainsail`/`Moonraker` and ZMOD via network
17. [Headless mode (no stock screen)](https://github.com/ghzserg/zmod/wiki/System_en#display_off). Saves 20MB RAM.
18. [GuppyScreen](https://github.com/ghzserg/zmod/wiki/System_en#display_off) – lightweight screen replacement
19. ROOT access and `mc` support
20. [COLDPULL](https://github.com/ghzserg/zmod/wiki/Filament_en#coldpull) (nozzle cleaning) without force. Based on [this method](https://t.me/FF_5M_5M_Pro/2836/447172).
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

- Custom Klipper settings go into `mod_data/user.cfg`, which can override/supplement `printer_base.cfg` and zMod files.
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

The mod uses the developments of [KlipperMod](https://github.com/xblax/flashforge_ad5m_klipper_mod/), but is not its development or continuation, and is not compatible with it either in macro syntax or binary.

## Installation/Update/Removal

[Installation/Update/Removal Guide](https://github.com/ghzserg/zmod/wiki/Setup_en)

## Support Development

Since people have been asking, I accept donations but please remember that I work on zMod for fun and not for the money. I will not accept donations to work on specific bugs or features.

[Sponsor](https://github.com/ghzserg/zmod/wiki/Sponsor)

BTC: `17wXTd9BqYp1K3zCLTxVyGLEXUDjf7XNLL`
