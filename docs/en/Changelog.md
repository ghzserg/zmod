# Changelog

- [Version History](#version-history)
    - [Version 1.6.6](#version-166)
      - [Version 1.6.5](#version-165)
      - [Version 1.6.4](#version-164)
      - [Version 1.6.3](#version-163)
      - [Version 1.6.2](#version-162)
      - [Version 1.6.1](#version-161)
      - [Version 1.6.0](#version-160)
      - [Version 1.5.4](#version-154)
      - [Version 1.5.3](#version-153)
      - [Version 1.5.2](#version-152)
      - [Version 1.5.1](#version-151)
      - [Version 1.5.0](#version-150)
      - [Version 1.4.3](#version-143)
      - [Version 1.4.2](#version-142)
      - [Version 1.4.1](#version-141)
      - [Version 1.4.0](#version-140)
      - [Version 1.3.1](#version-131)
      - [Version 1.3.0](#version-130)
      - [Version 1.1.2](#version-112)
      - [Version 1.1.1](#version-111)
      - [Version 1.1.0](#version-110)
      - [Version 1.0.5](#version-105)
      - [Version 1.0.4](#version-104)
      - [Version 1.0.0](#version-100)
      - [Version 0.2.4](#version-024)
      - [Version 0.2.3](#version-023)
      - [Version 0.2.2](#version-022)
      - [Version 0.2.1.1](#version-0211)
      - [Version 0.2.1](#version-021)
      - [Version 0.2.0](#version-020)
      - [Version 0.1.8](#version-018)
      - [Version 0.1.7](#version-017)
      - [Version 0.1.6](#version-016)
      - [Version 0.1.5](#version-015)
      - [Version 0.1.4](#version-014)
      - [Version 0.1.3](#version-013)
      - [Version 0.1.1](#version-011)
      - [Version 0.0.9-fix](#version-009-fix)
      - [Version 0.0.9](#version-009)

---

## Version History

### Version 1.6.6
27.01.2026

* Updated Fluidd/Mainsail/Klipper
* Updates for Klipper, Fluidd, Mainsail, and Moonraker are independent of mod updates

### Version 1.6.5
14.01.2026

* Updated Fluidd/ Mainsail / Clipper
* Additional camera settings are available
* Automatic Z offset selection

### Version 1.6.4
11.12.2025

* Improved ease of setup and use
* Update Fluidd/Mainsail/Klipper
* Plugin notify
* IFS crackling noise removed

### Version 1.6.3
**25.11.2025 — ZMOD’s Birthday!**

* [zmod.link](https://zmod.link/link/) | [ZLINK](/ru/Zmod/#zlink) — remote printer access via cloud
* Macro [SCREEN](/ru/System/#screen) — capture a screenshot of the printer’s display
* Macro [LOAD_ZOFFSET_NATIVE](/Calibrations/#load_zoffset_native) — transfer Z-offset settings from the native screen to screenless mode
* [AD5X](/ru/AD5X/): Added global parameter [REMOVE_FILAMENT](/ru/Global/#remove_filament) — unload filament after print completion
* Added [recommended settings plugin](https://github.com/ghzserg/recommend)
* Czech language support added
* MCU version check for Klipper 13 implemented
* [AD5X](/ru/AD5X/): Added leveling button
* [AD5X](/ru/AD5X/): Fixes for Klipper 13
* [AD5X](/ru/AD5X/): Nozzle cleaning improvements
* [AD5X](/ru/AD5X/): Eliminated IFS grinding noise
* ```CAMERA_ON VIDEO=video99``` — test all available cameras
* Update check after print completion
* When performing bed leveling via Fluidd/Mainsail, load cells are zeroed — but the user must manually clean the nozzle and preheat the bed beforehand
* Fixed `PURGE_LINE` — no longer prints over supports
* Fixed collision with frame edge on reprint
* Fixed load cell display — prevents absurd multi-ton readings
* Fixed chamber fan shutdown after print completion
* Fixed remaining time display in GuppyScreen for non-Russian locales

### Version 1.6.2

* [Plugin Support](https://wiki.zmod.link/Plugin/)
* [g28_tenz Plugin](https://github.com/ghzserg/g28_tenz) - Z-Axis Parking Using Load Cells
* [bambufy Plugin](https://github.com/function3d/bambufy) - Compatible with Bambu Studio and Orca Slicer, improves turret control, provides accurate time and material consumption estimates, reduces waste, supports quick color changes, and offers advanced printing features. From @function3d
* [nopoop Plugin](https://github.com/ghzserg/nopoop) - Maximum Waste Reduction by @ninjamida
* Fluidd: Color Support
* Mainsail: Color Support From @function3d, Fixed 404 Errors After Refreshing
* Guppy: Color Support. Fixed HA Integration.
* Added automatic connection of flash drives when working with Guppy
* Added [WiFi](/Global/#wifi) enabling directly without using the native screen
* [AD5X](/AD5X/): Solved the problem with the trash bin and filament cutting in new revisions
* [AD5X](/AD5X/): Color support when restoring print
* [AD5X](/AD5X/): Ability to create [custom filament types and colors](/AD5X/#7-add-custom-filament-types) when working without a native screen
* Updated Klipper and Monnraker
* Added support for ens160.py by @minicx
* Added Portuguese language
* Bug fixes
* Improved compatibility with the latest versions of the native firmware

### Version 1.6.1

- [AD5X ](/AD5X/) - Klipper 13 support. [UPDATE_MCU](/System/#update_mcu)
- [AD5X ](/AD5X/) - Temperature sensor in the head
- [AD5X](/AD5X/) - Work without a native screen. IFS works fully with the reset quantity setting
- Minor fixes

### Version 1.6.0

- AD5M - Klipper 13 support. [UPDATE_MCU](/ru/System/#update_mcu)
- AD5M - Temperature sensor in the head
- Minor fixes

Thanks for mcu support [@darksimpson](https://github.com/darksimpson)

Thanks for tenz support [@minicx](https://github.com/loss-and-quick/)

### Version 1.5.4

- AD5X - sound works
- AD5X - strain gauges and nozzle impact control on the table work
- AD5X - telegram bot works
- AD5X - filament presence sensor works
- AD5X - printer table PID installation works
- AD5X - nozzle cleaning is restored when removing the table card
- AD5X - the mod operation on firmware 1.0.9, 1.1.0, 1.1.1 has been tested
- AD5X - a [flash drive installing the screen version 1.0.7, and all other modules version 1.1.1] has been created (/Native_FW/)
- AD5x - a [flash drive for resetting the printer to factory settings] has been created (/Native_FW/)
- AD5X - a [flash drive for activating the mod has been created, after updating the native firmware](/Native_FW/)

### Version 1.5.3

* Fixed Klipper bug [#119](https://github.com/ghzserg/zmod/issues/119), which required using [this](/Recomendations/#avoid-using-russian-characters-in-filenames)
* Nozzle control is now enabled when printing from the screen immediately
* Minor cosmetic fixes

### Version 1.5.2

* Documentation structure update thanks to @TMTYD
* New RESTORE_TAR_CONFIG macro
* Guppy display fix
* **AD5X** HOME bug fix
* Moonraker update
* Parking acceleration change
* Default enabled CHINA_CLOUD

### Version 1.5.1

- **AD5X**: support for AD5X-1.0.8-1.0.5-20250418 firmware
- **AD5X**: fix _LINE_PURGE
- **AD5X**: support for updating the MCU IFS
- **AD5X**: fix MESH_TEST
- **AD5X**: fix _SMART_PARK
- **AD5X**: fix driver_fan
- **AD5X**: fix _HOME
- Cosmetic fixes CHECK_MD5
- Return chamber_fan to moonraker
- Fix object exclusion
- Fix guppyscreen for different languages

### Version 1.5.0
Interface language support:

- ZMOD - English, German, French, Italian, Spanish, Chinese, Japanese, Korean
- GuppyScreen - English, German, French, Italian, Spanish

### Version 1.4.3

- Automatic webcam configuration.
- Notification when switching web interfaces.
- **AD5X**: Fixed fast dialog closing.
- **AD5X**: Fixed parking.
- Fixed screen shutdown issue on newer printer revisions.

### Version 1.4.2

- Enhanced [nozzle collision detection](/Global/#nozzle_control) with optional pause instead of shutdown. Issue [#23](https://github.com/ghzserg/zmod/issues/23).
!!! note
    
- Nozzle Control does not work on AD5X see here[#75](https://github.com/ghzserg/zmod/discussions/75#discussion-8196449)
- Improved system check functionality.
- Updated Fluidd color scheme.
- Added global parameter [SAVE_MOONRAKER](/Macros/#save_moonraker) for custom macro button layouts.
- **AD5X**: GuppyScreen support.
- **AD5X**: New [COLOR](/Filament/#color) macro for filament type/color management.
- Revised pre-print bed testing with [MESH_TEST](/Macros/#mesh_test).
- Fixed:
- [#13](https://github.com/ghzserg/zmod/issues/13) (Mid-air printing after KAMP).
- [#14](https://github.com/ghzserg/zmod/issues/14) (Print recovery via stock screen).
- [#31](https://github.com/ghzserg/zmod/issues/27) (GuppyScreen freezes).
- [#25](https://github.com/ghzserg/zmod/issues/25) (AD5X bed calibration).
- [#26](https://github.com/ghzserg/zmod/issues/26) (AD5X belt spectrogram).
- [#27](https://github.com/ghzserg/zmod/issues/27) (AD5X installer errors).

### Version 1.4.1

- MD5 checks for files during installation.
- **Pro Version**: Fixed power button functionality.
- Support for non-MJPEG cameras.
- Alpha support for FF5X:
Known features:

- No Entware, so NEW_SAVE_CONFIG and CLOSE_DIALOGS don't work
- No music playing
- No table PID calibration, because there is no PID
- When activating the camera, specify VIDEO3
- No strain gauges, as a result there is no table protection and strain gauge reset.
- No filament motion sensor accessible from the klipper

### Version 1.4.0

- Updated Moonraker, Fluidd, Python.
- [Power-loss recovery](/Zmod/#zrestore).
- [Belt spectrogram analysis](/Macros/#belts_shaper_calibration).
- Bed load detection.
- [Filament motion sensor](/Macros/#motion_sensor) integration.
- **GuppyScreen**: Object exclusion, error logging, PID tuning, belt calibration.
- Layer-triggered macros: [next layer](/Macros/#set_pause_next_layer) or [specific layer](/Macros/#set_pause_at_layer).
- Native screen message logging.
- Shaper calibration with [SCV adjustment](https://www.klipper3d.org/Config_Reference.html#printer).
- [MUTE](/Macros/#mute) macro for temporary sound disable.
- [Display timeout](/System/#display_off_timeout) setting.
- `power_off.sh` script for shutdown tasks.
- KAMP smart parking.
- Fixed:
- Mod removal/disable issues.
- Nozzle collision detection (active only during prints).
- Fluidd/GuppyScreen head movement controls.
- Pause functionality in headless mode.
- KAMP stability.

### Version 1.3.1

- **GuppyScreen**: COLDPULL, PID control, firmware retraction, calibration workflows.
- Nozzle collision detection limited to active prints.
- Improved headless mode stability.
- Faster dialog closing with [NEW_SAVE_CONFIG](/Macros/#new_save_config).

### Version 1.3.0

- [GuppyScreen](/System/#display_off) integration.
- Experimental Klipper v12 support (disabled by default).
- Updated SSH tools (`dropbear`).
- Memory-optimized `mjpg_streamer`.
- Object exclusion fixes (supports included).
- [FIX_SCV](/Global/#fix_scv) for shaper graphs.
- [CHECK_SYSTEM](/System/#check_system) file permission checks.
- Removed [SOFT_REMOVE](/Macros/#soft_remove).

### Version 1.1.2

- [CHECK_SYSTEM](/System/#check_system) for OS integrity checks.
- [NOZZLE_CONTROL](/Global/#nozzle_control) emergency shutdown.
- [UPDATE_MCU](/Macros/#update_mcu) firmware updater.
- Process priority tuning via [NICE](/Macros/#nice).
- Experimental [FIX_E0011](/Global/#fix_e0011) for homing errors.
- EMMC optimization.

### Version 1.1.1

- Fixed [LOAD_CELL_TARE](/Macros/#load_cell_tare) by Alexander K.
- Removed deprecated parameters.
- Z-axis parking sequence.
- [CAMERA_RESTART](/Macros/#camera_restart) macro.
- Print cancellation fixes.
- Igor Polunovskiy's EXCLUDE_OBJECT_DEFINE.
- Motor persistence during repeated prints.
- [TEST_EMMC](/Macros/#test_emmc) wear reporting.

### Version 1.1.0

- Moonraker update.
- Faster Moonraker startup.
- Hidden deprecated macros.
- Heated bed requirement for load cell reset.
- New parameters:
- [ALTER_CELL_TARE](/Macros/#alter_cell_tare) for sensor errors.
- [CELL_WEIGHT](/Macros/#cell_weight) calibration threshold.
- [CHINA_CLOUD](/Global/#china_cloud) toggle.
- Pro version fan fixes.
- Timezone synchronization.

### Version 1.0.5

- [AUTO_REBOOT](/Macros/#auto_reboot) firmware restart option.
- Optimized G28 usage.
- Universal [MD5 checks](/System/#check_md5).
- [MEM](/Macros/#mem) memory monitoring.
- Klipper process prioritization.
- [BED_LEVEL_SCREWS_TUNE](/Calibrations/#bed_level_screws_tune) temperature handling.
- [E0017 fix](/Global/#fix_e0017).

### Version 1.0.4

- [Firmware retraction](/FAQ/#what-is-firmware-retraction).
- Driver fan auto-activation.
- [TEST_EMMC](/Macros/#test_emmc) speed tests.
- [CLEAR_EMMC](/System/#clear_emmc) log cleanup.
- Telegram bot auto-cleanup.
- [LINE_PURGE](/Global/#clear) fallback.

### Version 1.0.0

- Network-based updates.
- [CAMERA_ON](/Zmod/#camera_on) device selection.

### Version 0.2.4

- USB update notifications.
- Screen-leveling priority.
- Pause button positioning.
- Installer auto-reboot.

### Version 0.2.3

- [M600](/Macros/#m600) filament change.
- MD5 validation warnings.

### Version 0.2.2

- [FAST_CLOSE_DIALOGS](/Macros/#fast_close_dialogs).
- [LEVELING_PRINT_FILE](/Macros/#leveling_print_file) native bed leveling.
- [COLDPULL](/Filament/#coldpull) nozzle cleaning.
- [SAVE_ZMOD_DATA](/Global/#save_zmod_data) parameters:
- `PRINT_LEVELING`: Native bed leveling.
- `USE_KAMP`: Adaptive mesh.
- `CLOSE_DIALOGS`: Auto-close dialogs.
- `USE_SWAP`: Memory management.

### Version 0.2.1.1

- Async MIDI playback.
- [STOP_MOTOR](/Global/#save_zmod_data) post-print.
- [AUTO_REBOOT](/Global/#save_zmod_data) timer.
- [PRECLEAR](/Global/#save_zmod_data) nozzle purge.

### Version 0.2.1

- [ZSHAPER](/Calibrations/#zshaper) calibration.
- Headless mode fixes.

### Version 0.2.0

- Fluidd/Mainsail update.
- [NEW_SAVE_CONFIG](/Macros/#new_save_config) non-freezing saves.
- [SAVE_ZMOD_DATA](/Global/#save_zmod_data) parameters:
- LED brightness.
- MIDI triggers.

### Version 0.1.8

- Telegram bot integration.
- SSH management macros.

### Version 0.1.7

- Macro stability fixes.
- [STOP_ZMOD](/Macros/#stop_zmod) service control.

### Version 0.1.6

- [KAMP](/Calibrations/#kamp) adaptive meshing.
- PID calibration fixes.

### Version 0.1.5

- [ZSHAPER](/Calibrations/#zshaper) CSV export.
- Temperature-aware bed calibration.

### Version 0.1.4

- Camera memory optimization.
- [CAMERA_ON](/Zmod/#camera_on) resolution control.

### Version 0.1.3

- MIDI playback support.
- User config separation.

### Version 0.1.1

- Headless mode ([DISPLAY_OFF](/System/#display_off)).
- [MEM](/Macros/#mem) resource monitor.

### Version 0.0.9-fix

- Installer fixes.

### Version 0.0.9

- Initial pause/resume/cancel support.
- [REBOOT](/Macros/#reboot)/[SHUTDOWN](/Macros/#shutdown) macros.
