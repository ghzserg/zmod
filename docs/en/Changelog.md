# Changelog

- [Version History](#version-history)
    - [Version 1.7.5](#version-175)
    - [Version 1.7.4](#version-174)
    - [Version 1.7.3](#version-173)
    - [Version 1.7.2](#version-172)
    - [Version 1.7.1](#version-171)
    - [Version 1.7.0](#version-170)
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

### Version 1.7.5
28.10.2026

* Z-Mod: 3MF support
* Z-Mod: With 3MF, color mapping is instant — the [preprocessor](/Global/#force_md5) is no longer needed
* Z-Mod: Fast KAMP — enabled automatically and works without slow object exclusion. For 3MF the KAMP data is available instantly, for G-code — after the file is scanned
* C5Pro: Support for up to 100 colors in a file, mapped to 4 extruders
* New macro [PLUGINS](/Global/#plugins) — plugin management menu
* New macro [_USER_PREPARE_PRINT](/Main/#_user_prepare_print) — called before the file is sent to print
* New global parameter [PURGE_ALL_EXTRUDERS](/Global/#purge_all_extruders) — purge all used extruders at print start
* New global parameter [UNUSED_EXTRUDERS_OFF_TIME](/Global/#unused_extruders_off_time) — turn off heating of idle extruders after a set time
* The support Telegram bot [@zmod_help_bot](https://t.me/zmod_help_bot) is now AI-powered
* Fluidd: 3MF support
* Mainsail: 3MF support
* Moonraker: 3MF support
* Bug fixes

**Upstream contributions:**

* Fluidd: prompt action button grouping [#1977](https://github.com/fluidd-core/fluidd/pull/1977)
* Mainsail: HEX colors in the third parameter of macro prompts, together with @function3d [#2687](https://github.com/mainsail-crew/mainsail/pull/2687)
* OrcaSlicer (coming in 2.5.0, currently in beta):
    * Exclude-object outline tolerance is now a user setting [#16503](https://github.com/OrcaSlicer/OrcaSlicer/pull/16503)
    * Tolerance set to 0.2 mm for AD5M/AD5M Pro, AD5X, Creator 5 / 5 Pro — fewer outline points, more objects per plate without "Timer too close" [#16687](https://github.com/OrcaSlicer/OrcaSlicer/pull/16687)
    * Post-processing scripts are applied to G-code packed into .gcode.3mf [#16464](https://github.com/OrcaSlicer/OrcaSlicer/pull/16464)
    * Fixed the first-layer bbox in plate_N.json being shifted on every plate after the first [#16860](https://github.com/OrcaSlicer/OrcaSlicer/pull/16860)

### Version 1.7.4
24.09.2026

* C5Pro: Everything that works on AD5X works here too, except for Klipper 13 
* C5Pro: Added a mode without the native screen 
* C5Pro: Added calibrations: extruders, VFA 
* C5Pro: Printer screen broadcast 
* AD5X: Printer screen broadcast 
* GuppyScreen: Support for multiple extruders


### Version 1.7.3
09.09.2026

* Alpha support for Creator 5 / Creator 5 Pro (no support for headless mode or Klipper 13, not all macros tested)
* AD5M: Support for native firmware 5.1.9
* AD5X: Polling cycle speedup from @ninjamida

### Version 1.7.2
16.08.2026

* Updated Fluidd/Mainsail/Klipper


### Version 1.7.1
14.05.2026

* Updated Fluidd/Mainsail/Klipper
* GuppyScreen config auto-restore if cleared by user
* Klipper protection against OOM-killer
* Console output for `BED_MESH` load/clear events
* `dmesg` logging to config archive
* Fixed Wi-Fi functionality
* `SAVE_CONFIG...` status indicator during saving
* Load cell freeze/stall monitoring
* Bed lowers by 5mm on pause via native screen
* `IP` macro – outputs IP address to console after startup
* Rebranding: `ZMOD` → `Z-Mod`

### Version 1.7.0
15.03.2026

* Updated Fluidd/Mainsail/Klipper
* [NoPoop 2](/AD5X/#slicer-controlled-purge) by @ninjamida
* HelixScreen - alternative screen. (`ENABLE_EXTRA_PLUGINS`, `DISPLAY_OFF HELIX=1`)
* Special thanks to @xyzroe for their great help with this release

### Version 1.6.6
27.01.2026

* Updated Fluidd/Mainsail/Klipper
* Updates for Klipper, Fluidd, Mainsail, and Moonraker are independent of mod updates

### Version 1.6.5
14.01.2026

* Updated Fluidd/Mainsail/Klipper
* Additional camera settings are available
* Automatic Z-Offset tuning

### Version 1.6.4
11.12.2025

* Improved ease of setup and use
* Updated Fluidd/Mainsail/Klipper
* Notify plugin
* IFS crackling noise removed

### Version 1.6.3
25.11.2025 — Z-Mod is one year old!

* [zmod.link](https://zmod.link/link/) | [ZLINK](/Zmod/#zlink) — remote printer access via cloud
* Macro [SCREEN](/System/#screen) — capture a screenshot of the printer’s display
* Macro [LOAD_ZOFFSET_NATIVE](/Calibrations/#load_zoffset_native) — transfer Z-offset settings from the native screen to screenless mode
* [AD5X](/AD5X/): Added global parameter [REMOVE_FILAMENT](/Global/#remove_filament) — unload filament after print completion
* Added [recommended settings plugin](https://github.com/ghzserg/recommend)
* Czech language support added
* MCU version check for Klipper 13 implemented
* [AD5X](/AD5X/): Added leveling button
* [AD5X](/AD5X/): Fixes for Klipper 13
* [AD5X](/AD5X/): Nozzle cleaning improvements
* [AD5X](/AD5X/): Eliminated IFS grinding noise
* ```CAMERA_ON VIDEO=video99``` — test all available cameras
* Update check after print completion
* When performing bed leveling via Fluidd/Mainsail, load cells are zeroed — but the user must manually clean the nozzle and preheat the bed beforehand
* Fixed `PURGE_LINE` — no longer prints over supports
* Fixed collision with frame edge on reprint
* Fixed load cell display — prevents absurd multi-ton readings
* Fixed chamber fan shutdown after print completion
* Fixed remaining time display in GuppyScreen for non-Russian locales

### Version 1.6.2
27.10.2025

* [Plugin Support](/Plugin/)
* [g28_tenz Plugin](https://github.com/ghzserg/g28_tenz) - Z-Axis Parking Using Load Cells
* [bambufy Plugin](https://github.com/function3d/bambufy) - Compatible with Bambu Studio and Orca Slicer, improves prime tower control, provides accurate time and material consumption estimates, reduces waste, supports quick color changes, and offers advanced printing features. From @function3d
* [nopoop Plugin](https://github.com/ghzserg/nopoop) - Maximum Waste Reduction by @ninjamida
* Fluidd: Color Support
* Mainsail: Color Support From @function3d, Fixed 404 Errors After Refreshing
* Guppy: Color Support. Fixed HA Integration.
* Added automatic connection of flash drives when working with Guppy
* Added [WiFi](/Global/#wifi) enabling directly without using the native screen
* [AD5X](/AD5X/): Solved the problem with the trash bin and filament cutting in new revisions
* [AD5X](/AD5X/): Color support when restoring print
* [AD5X](/AD5X/): Ability to create [custom filament types and colors](/AD5X/#7-add-or-remove-filament-types) when working without a native screen
* Updated Klipper and Moonraker
* Added support for ens160.py by @minicx
* Added Portuguese language
* Bug fixes
* Improved compatibility with the latest versions of the native firmware

### Version 1.6.1
06.09.2025

- [AD5X](/AD5X/) - Klipper 13 support. [UPDATE_MCU](/System/#update_mcu)
- [AD5X](/AD5X/) - Temperature sensor in the head
- [AD5X](/AD5X/) - Work without a native screen. IFS works fully, with configurable purge amount
- Minor fixes

### Version 1.6.0
14.08.2025

- AD5M - Klipper 13 support. [UPDATE_MCU](/System/#update_mcu)
- AD5M - Temperature sensor in the head
- Minor fixes

Thanks for MCU support to [@darksimpson](https://github.com/darksimpson)

Thanks for load cell support to [@minicx](https://github.com/loss-and-quick/)

### Version 1.5.4
28.06.2025

- AD5X - sound works
- AD5X - load cells and nozzle collision control work
- AD5X - Telegram bot works
- AD5X - filament presence sensor works
- AD5X - bed PID calibration works
- AD5X - nozzle cleaning during bed mesh probing is restored
- AD5X - the mod operation on firmware 1.0.9, 1.1.0, 1.1.1 has been tested
- AD5X - created a [flash drive that installs screen version 1.0.7 and all other modules version 1.1.1](/Native_FW/)
- AD5X - created a [flash drive for resetting the printer to factory settings](/Native_FW/)
- AD5X - created a [flash drive for activating the mod after updating the native firmware](/Native_FW/)

### Version 1.5.3
03.06.2025

* Fixed Klipper bug [#119](https://github.com/ghzserg/zmod/issues/119), which required avoiding non-Latin characters in object names
* Nozzle control is now enabled when printing from the screen immediately
* Minor cosmetic fixes

### Version 1.5.2
15.05.2025

* Documentation structure update, thanks to @TMTYD
* New RESTORE_TAR_CONFIG macro
* Guppy display fix
* **AD5X** HOME bug fix
* Moonraker update
* Parking acceleration change
* CHINA_CLOUD enabled by default

### Version 1.5.1
23.04.2025

- **AD5X**: support for AD5X-1.0.8-1.0.5-20250418 firmware
- **AD5X**: fix _LINE_PURGE
- **AD5X**: support for updating the MCU IFS
- **AD5X**: fix MESH_TEST
- **AD5X**: fix _SMART_PARK
- **AD5X**: fix driver_fan
- **AD5X**: fix _HOME
- Cosmetic fixes CHECK_MD5
- Return chamber_fan to Moonraker
- Fix object exclusion
- Fix guppyscreen for different languages

### Version 1.5.0
17.04.2025
Interface language support:

- Z-Mod - English, German, French, Italian, Spanish, Chinese, Japanese, Korean
- GuppyScreen - English, German, French, Italian, Spanish

### Version 1.4.3
23.03.2025

- Automatic webcam configuration.
- Notification when switching web interfaces.
- **AD5X**: Fixed fast dialog closing.
- **AD5X**: Fixed parking.
- Fixed screen shutdown issue on newer printer revisions.

### Version 1.4.2
19.03.2025

- Enhanced [nozzle collision detection](/Global/#nozzle_control) with optional pause instead of shutdown. Issue [#23](https://github.com/ghzserg/zmod/issues/23).
- Nozzle control does not work on AD5X, see [#75](https://github.com/ghzserg/zmod/discussions/75#discussion-8196449)
- Improved system check functionality.
- Updated Fluidd color scheme.
- Added global parameter [SAVE_MOONRAKER](/Global/#save_moonraker) for custom macro button layouts.
- **AD5X**: GuppyScreen support.
- **AD5X**: New [COLOR](/Filament/#color) macro for filament type/color management.
- Revised pre-print bed testing with [MESH_TEST](/Global/#mesh_test).
- Fixed:
    - [#13](https://github.com/ghzserg/zmod/issues/13) (Mid-air printing after KAMP).
    - [#14](https://github.com/ghzserg/zmod/issues/14) (Print recovery via stock screen).
    - [#31](https://github.com/ghzserg/zmod/issues/31) (GuppyScreen freezes).
    - [#25](https://github.com/ghzserg/zmod/issues/25) (AD5X bed calibration).
    - [#26](https://github.com/ghzserg/zmod/issues/26) (AD5X belt spectrogram).
    - [#27](https://github.com/ghzserg/zmod/issues/27) (AD5X installer errors).

### Version 1.4.1
09.03.2025

- During Z-Mod installation, the MD5 checksum of the unpacked files is verified. When copying files from the flash drive to the file system, the printer occasionally corrupts files.
- The CHECK_SYSTEM macro now includes system self-check
- The power button now works on the Pro version
- Non-MJPEG cameras can be used
- Alpha support for FF5X:
  Known features:

  - No Entware, so NEW_SAVE_CONFIG and CLOSE_DIALOGS don't work
  - No music playing
  - No bed PID calibration, because the bed is not PID-controlled
  - When activating the camera, specify VIDEO3
  - No load cells, as a result there is no bed protection and no load cell reset.
  - No filament motion sensor accessible from Klipper

### Version 1.4.0
04.03.2025

- Updated Moonraker, Fluidd, Python
- [Print recovery after power loss](/Zmod/#zrestore)
- [Belt spectrogram](/Macros/#belts_shaper_calibration)
- Loaded plate control: checks that the bed mesh roughly matches the currently loaded plate
- Support for the [filament motion sensor](/Global/#motion_sensor)
- GuppyScreen: object exclusion, error output, firmware retraction, PID calibration, weight reset, FF5M Pro support
- Run a macro on the [next layer](/Macros/#set_pause_next_layer) or [on a specific layer](/Macros/#set_pause_at_layer)
- Logging of all native screen messages in Klipper and of the responses to them
- New shaper calibration algorithm; shaper graphs take SCV into account
- MUTE macro - mute sound until reboot
- New parameter - [native screen off timeout](/Global/#display_off_timeout)
- New file `mod_data/power_off.sh` - lets you write code that runs when the printer is turned off
- Smart parking is enabled when KAMP is used
- Fixed removing, disabling and fully removing the mod
- Fixed pre-cleaning
- Fixed nozzle collision control. It works only while printing.
- Fixed moving the print head with buttons in Fluidd/GuppyScreen
- Fixed pause in screenless mode
- Fixed KAMP

### Version 1.3.1

- GuppyScreen improvements: COLDPULL, PID control, firmware retraction, shaper calibration, belt calibration, cosmetic fixes
- Nozzle control now works only while printing
- BELTS_SHAPER_CALIBRATION
- Improved screenless mode
- Improved slow dialog closing and NEW_SAVE_CONFIG

### Version 1.3.0
08.02.2025

- [GuppyScreen](/System/#display_off) support
- Klipper 12, [in test mode](/Macros/#update_mcu) (disabled by default). Not working in it: extruder heating, extruder temperature, load cells.
- SSH client and SSH server `dropbear` replaced with the current version.
- `mjpg_streamer` replaced with a version with Alexander's patch, reducing memory usage by 2-4 times.
- Fixed object exclusion by Igor Polunovskiy (supports are now taken into account).
- Shaper graphs take SCV into account ([square_corner_velocity](https://www.klipper3d.org/Config_Reference.html#printer)) [FIX_SCV](/Global/#fix_scv).
- [CHECK_SYSTEM](/System/#check_system) - added checks of file and directory permissions, link checks and recovery.
- Removed the SOFT_REMOVE macro.
- Updated Moonraker, Fluidd, Mainsail

### Version 1.1.2
03.02.2025

- New macro [CHECK_SYSTEM](/System/#check_system) - check the printer operating system for file corruption.
- New macro [NOZZLE_CONTROL](/Global/#nozzle_control) - emergency shutdown of the printer if a part detaches or the nozzle hits the bed.
- New macro [UPDATE_MCU](/Macros/#update_mcu) - update the printer MCU.
- New global flag [NICE](/Global/#nice) - set the Klipper process priority, 1 - lowest, 40 - highest (20).
- New global flag [FIX_E0011](/Global/#fix_e0011) - fix the E0011 error as well as `Communication timeout during homing`
- Cleaning deleted files from the printer file system speeds up EMMC.
- Lots of small fixes

### Version 1.1.1
24.01.2025

- Fixed an ordering problem when a callback blocks in the button handler [#6440](https://github.com/Klipper3d/klipper/pull/6440), found by [Alexander K](https://github.com/drA1ex) - [LOAD_CELL_TARE](/Macros/#load_cell_tare) now works as intended.
- Removed global parameters: `ALTER_CELL_TARE`, `IGNORE_CELL_TARE`, `CELL_WEIGHT`
- Increased the zsend timeout. Additional messages are shown.
- G28 now homes Z first, then X and Y
- New macro [CAMERA_RESTART](/Macros/#camera_restart) - restart the alternative camera implementation
- Fixed print cancellation code in screenless mode
- EXCLUDE_OBJECT_DEFINE implementation by Igor Polunovskiy
- On a repeated print, the motors are not disabled and the printer does not reboot, even if this is set in the global parameters
- The [TEST_EMMC](/Macros/#test_emmc) macro shows EMMC wear
- Fixed disabling of the Chinese clouds

### Version 1.1.0
15.01.2025

- Updated Moonraker
- Significantly faster Moonraker startup
- Hidden `level_h1`, `level_h2`, `level_h3`, `power_off`, `clear_power_off`, `level_clear`, `check_level_pin_alt`
- Load cell reset in screenless mode uses Igor Polunovskiy's implementation
- Load cell reset now only on a heated bed
- New global parameter `ALTER_CELL_TARE`. Allows working around the load cell reset error.
- New global parameter `CELL_WEIGHT` sets the weight at which load cell calibration is skipped
- New global parameter [CHINA_CLOUD](/Global/#china_cloud) - allows disabling the Chinese clouds
- Rewrote the printer config update
- Cooling fans now work correctly on the Pro version. Default angles are 165/105
- Extruder calibration now sets the cooling fan speed
- Time and timezone in Moonraker now match Klipper time
- The native firmware version is shown on the `System Information` tab.
- The mod is less talkative

### Version 1.0.5
13.01.2025

- Added a parameter to [AUTO_REBOOT](/Global/#auto_reboot) that allows restarting the firmware
- G28 in macros is called only when needed
- The MD5 algorithm has been almost completely rewritten. MD5 verification now works from anywhere and does not require heating the bed or extruder
- Improved the [MEM](/Macros/#mem) macro: now shows the memory of Moonraker, Klipper, the screen and how SWAP is used
- The Klipper process has a higher priority than other processes
- The global parameter [PRINT_LEVELING](/Global/#print_leveling) now also works in screenless mode
- The [BED_LEVEL_SCREWS_TUNE](/Calibrations/#bed_level_screws_tune) macro now uses the temperature correctly
- The [TEST_EMMC](/Macros/#test_emmc) macro can test EMMC, USB flash and RAM.
- Swap can now (but doesn't have to) be placed on a USB flash drive
- Macro [CLEAR_EMMC](/System/#clear_emmc) - clear logs and/or GCODE
- Fix for [E0017](/Global/#fix_e0017)

### Version 1.0.4
05.01.2025

- Support for [firmware retraction](/FAQ/#what-is-firmware-retraction)
- Fix for [E0017](/Global/#fix_e0017)
- Driver cooling fans turn on automatically when the motors are enabled. Solves calibrating shapers without driver cooling on stock.
- New macro [TEST_EMMC](/Macros/#test_emmc) - writes SIZE MB to EMMC and reports the read/write speed.
- New macro [CLEAR_EMMC](/System/#clear_emmc) - clears EMMC.
- Automatic [bot restart when working over SSH](/Macros/#zssh_on)
- [Automatic cleanup](https://github.com/ghzserg/zmod_ff5m/blob/1.4/telegram/docker-compose.yml) of videos older than 10 days in the bot.
- Setting the [required timezone](https://github.com/ghzserg/zmod_ff5m/blob/1.4/telegram/docker-compose.yml) in the bot
- Automatic fallback from KAMP purge [LINE_PURGE](/Global/#clear) to _CLEAR2 if no objects are found
- Fixed [SKIP_ZMOD](/Macros/#skip_zmod)
- Updating Fluidd/Mainsail no longer requires a reboot
- Switching from Fluidd to Mainsail no longer requires a reboot
- Z-Mod reports files that use arcs
- Fixed the `addMD5.sh` script
- Fixed driver cooling control in screenless mode
- The `auto` bed mesh is loaded at printer startup in screenless mode

### Version 1.0.0
23.12.2024

- New update and installation system; almost any update can now be received over the network
- New [CAMERA_ON](/Zmod/#camera_on) parameter, VIDEO - video device (video0)

### Version 0.2.4
21.12.2024

- Z-Mod automatically reports whether an update from a flash drive is needed - now in red
- If bed mesh probing with the native screen is used (PRINT_LEVELING=1), the FORCE_LEVELING, FORCE_KAMP, SKIP_LEVELING, MESH parameters of START_PRINT are ignored
- Pause in the far right corner, even when printing from the screen
- The PRECLEAR parameter now also works when printing with bed mesh probing from the screen
- Changed the installation algorithm: after a successful installation you no longer have to remove the flash drive - the printer reboots and deletes the installation file itself.

### Version 0.2.3
19.12.2024

- Z-Mod automatically reports whether an update from a flash drive is needed
- Improved the [M600](/Macros/#m600) macro - filament change with pause during printing
- Improved MD5 control - a message is now shown if MD5 is not found

### Version 0.2.2
17.12.2024

- New macro [FAST_CLOSE_DIALOGS](/Macros/#fast_close_dialogs) - quickly closes native screen dialogs. Used to close the window at the end of a print or when a print is cancelled. *For fast closing, go to "Settings" -> "WiFi icon" -> "Network Mode" on the printer screen and enable "Local Network Only".* Implementation: @darksimpson
- New macro `LEVELING_PRINT_FILE` - print a file with bed mesh probing from the native screen. *For LEVELING_PRINT_FILE, go to "Settings" -> "WiFi icon" -> "Network Mode" on the printer screen and enable "Local Network Only"*
- New macro [COLDPULL](/Filament/#coldpull) - cold pull (nozzle cleaning) without force. Implementation of [this algorithm](https://t.me/FF_5M_5M_Pro/2836/447172)
- New [SAVE_ZMOD_DATA](/Global/#save_zmod_data) parameters:
    - [PRINT_LEVELING](/Global/#save_zmod_data) - probe the bed mesh with the native screen for every print 0-no, 1-yes (0). *For bed mesh probing from the native screen, go to "Settings" -> "WiFi icon" -> "Network Mode" on the printer screen and enable "Local Network Only"*
    - [USE_KAMP](/Global/#save_zmod_data) - where possible, use an adaptive bed mesh (KAMP) instead of a full bed mesh 0-no, 1-yes (0). *Allows using KAMP when the bed mesh is probed over the network from the native screen*
    - [CLOSE_DIALOGS](/Global/#save_zmod_data) - automatically close dialogs at the end of a print and on cancel 0-no, 1-yes slowly, 2-yes quickly. *For fast closing, go to "Settings" -> "WiFi icon" -> "Network Mode" on the printer screen and enable "Local Network Only"* (0).
    - [USE_SWAP](/Global/#save_zmod_data) - use SWAP 0-no, 1-yes (1). *If your CPU has not been re-soldered, SWAP is mandatory*

### Version 0.2.1.1
10.12.2024

- Asynchronous MIDI playback algorithm
- Installation fix
- Fixed SHUTDOWN from the main menu
- New script [addMD5.sh](https://github.com/ghzserg/zmod_ff5m/blob/1.4/addMD5.sh) - MD5 control for macOS/Linux - thanks to Alexander
- New parameter [STOP_MOTOR](/Global/#save_zmod_data) - automatically disable motors 25 seconds after a print ends/is cancelled.
- New parameter [AUTO_REBOOT](/Global/#save_zmod_data) - automatically restart the printer 1.5 minutes after a print.
- New parameter [PRECLEAR](/Global/#save_zmod_data) - use nozzle pre-cleaning in START_PRINT
- New music: BattleCity, IndianaJones, WeWillRockYou by [@drmax_gc](https://t.me/drmax_gc)

### Version 0.2.1
10.12.2024

- Shaper graphs right from the printer. Macro [ZSHAPER](/Calibrations/#zshaper)
- Fixed an error in screenless mode

### Version 0.2.0
09.12.2024

- Updated Fluidd/Mainsail
- Added mc, opkg, gdb
- Reboot via the Fluidd top menu
- Bug fixes
- Major rework of the [START_PRINT](/Main/#start_print) macro
- Macro [NEW_SAVE_CONFIG](/Macros/#new_save_config) - save changes/restart Klipper without freezing the native screen. Implementation: @darksimpson
- Macro [CLOSE_DIALOGS](/Macros/#close_dialogs) - close windows at the end of a print and on cancel. Implementation: @darksimpson
- Macro [STOP_ZMOD](/Macros/#stop_zmod) - stop Moonraker
- Macro [START_ZMOD](/Macros/#start_zmod) - start Moonraker
- Macro [SAVE_ZMOD_DATA](/Global/#save_zmod_data) - save Z-Mod parameters
    - CLOSE_DIALOGS - automatically close dialogs at the end of a print and on cancel 0-no, 1-yes (0)
    - NEW_SAVE_CONFIG - use the alternative NEW_SAVE_CONFIG for PID calibration 0-no, 1-yes (0)
    - LED - LED brightness at power-on (50)
    - MIDI_ON - play MIDI at power-on ("")
    - MIDI_START - play MIDI at print start ("")
    - MIDI_END - play MIDI at print end ("")

### Version 0.1.8
04.12.2024

- Telegram bot connection support
- Macro [ZSSH_ON](/Macros/#zssh_on) - ZSSH_ON SSH_SERVER SSH_PORT SSH_USER VIDEO_PORT MOON_PORT
- Macro [ZSSH_OFF](/Macros/#zssh_off) - disable the SSH client
- Macro [ZSSH_RESTART](/Macros/#zssh_restart) - restart the SSH client

### Version 0.1.7
03.12.2024

- Many macro fixes
- Macro [STOP_ZMOD](/Macros/#stop_zmod) - temporarily stops Fluidd/Mainsail and Moonraker

### Version 0.1.6
02.12.2024

- Fixed the log location
- Fixed the [LOAD_CELL_TARE](/Macros/#load_cell_tare) macro
- Fixed the extruder and bed PID calibration macro
- Macro [CLEAR_NOZZLE](/Macros/#clear_nozzle) - nozzle cleaning, as in the native firmware
- Macro [KAMP](/Calibrations/#kamp) extruder_temp=[nozzle_temperature_initial_layer] bed_temp=[bed_temperature_initial_layer_single]. Adaptive bed mesh with nozzle cleaning.
- [AUTO_FULL_BED_LEVEL](/Calibrations/#auto_full_bed_level) - macro completely rewritten

### Version 0.1.5
30.11.2024

- Added Mainsail. Switch via the WEB macro
- STOP macro - disables motors, added to the end gcode
- Macro [ZSHAPER](/Calibrations/#zshaper) - shaper calibration and CSV export to /mod_data in the configuration. Further analysis via [Klipper-Input-Shaping-Assistant](https://github.com/theycallmek/Klipper-Input-Shaping-Assistant/releases)
- Macro [LOAD_CELL_TARE](/Macros/#load_cell_tare) - load cell reset
- Fixed bed calibration. You can now set the bed and extruder temperature for calibration. Default 120/80
- Fixed turning the screen off in screenless mode. It turns off after 4 minutes.

### Version 0.1.4
29.11.2024

- Added camera control from the mod. Saves memory and allows working with the camera when the screen is off. The camera resolution can also be changed. (The implementation was inspired by Pavel Mironov)
- Fixed an installer bug that in the previous version could remove [heater_bed] from the configuration files
- New installation images. Made by [@drmax_gc](https://t.me/drmax_gc)
- Macros are sorted into categories and translated into Russian
- Macro [DATE_GET](/Macros/#date_get) - show the current time
- Macro [DATE_SET](/Macros/#date_set) - set the current time
- Macro [CAMERA_ON](/Zmod/#camera_on) - use the alternative camera implementation
- Macro [CAMERA_OFF](/Macros/#camera_off) - disable the alternative camera implementation

### Version 0.1.3
28.11.2024

- Added MIDI playback. Files are stored in mod_data/midi - accessible via the "Configuration" tab. Thanks to [@drmax_gc](https://t.me/drmax_gc)
- Macro [PLAY_MIDI](/Macros/#play_midi). Plays a melody: PLAY_MIDI FILE=Pain-Shut-your-mouth.mid
- Macro `SOFT_REMOVE`. Removes only Z-Mod, keeps audio, md5, root
- Moonraker settings are preserved after an update
- User settings for Klipper moved to mod_data/user.cfg
- User settings for Moonraker moved to mod_data/user.moonraker.conf
- When the screen is turned off, it shows a message that the screen is off. Thanks to @drmax_gc
- Fixed bed calibration via macro. The bed now heats up.
- Fixed bed adjustment via macro. The bed now heats up.

### Version 0.1.1
27.11.2024

- Support for working with the native display turned off. This saves 20 MB of RAM. To enable this mode, call the DISPLAY_OFF macro. Klipper restarts and uses alternative configuration files. It is recommended to probe the bed mesh and save it to the default profile. After a reboot, the screen becomes unavailable after 5 minutes and the bed mesh from the default profile is loaded.
- Macro [MEM](/Macros/#mem) - shows how much memory is used and by which application.
- Macro [DISPLAY_ON](/System/#display_on) - returns the screen to the standard mode, the printer reboots
- Macro [LED](/Macros/#led) - turns the light on at 50%
- Macro [LED_ON](/Macros/#led_on) - turns the light on at 100%
- Macro [LED_OFF](/Macros/#led_off) - turns the light off

### Version 0.0.9-fix
25.11.2024

- Fixed an installation error.

### Version 0.0.9
25.11.2024

- Pause during printing, handled via the native screen
- Resume after pause, handled via the native screen
- Print cancellation, handled via the native screen
- [REBOOT](/Macros/#reboot) - macro to reboot the printer
- [SHUTDOWN](/Macros/#shutdown) - macro to turn off the printer
- [SKIP_ZMOD](/Macros/#skip_zmod) - macro to reboot without starting Moonraker and Fluidd
- [REMOVE_ZMOD](/Macros/#remove_zmod) - macro to remove the mod
- Fixed: "After a pause caused by the filament motion sensor, printing resumes but prints in the air about 3 cm above where it should"
