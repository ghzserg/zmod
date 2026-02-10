<h1 align="center">ZMOD Macro List</h1>

*[Прочитать на русском языке](https://wiki.zmod.link/ru/Macros/)*

A macro is a small program written in Klipper/Gcode.

It can be called from:
- A GCODE file
- The Fluidd/Mainsail console (press the `C` key in Fluidd).

> [!NOTE]
> *Default values are shown in parentheses.*

[@zmod_help_bot](http://t.me/zmod_help_bot)

---
<p align="center"><strong>🔷 Here is an overwiev table of the different areas and their macros 🔷</strong></p>

***

<h1 align="center"><a href="https://wiki.zmod.link/Main/">Main</a></h1>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center"><a href="https://wiki.zmod.link/Main/#start_print">START_PRINT</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Main/#end_print">END_PRINT</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Main/#close_dialogs">CLOSE_DIALOGS</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Main/#fast_close_dialogs">FAST_CLOSE_DIALOGS</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://wiki.zmod.link/Main/#led">LED</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Main/#led_off">LED_OFF</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Main/#led_on">LED_ON</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Main/#play_midi">PLAY_MIDI</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://wiki.zmod.link/Main/#clear_nozzle">CLEAR_NOZZLE</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Main/#new_save_config">NEW_SAVE_CONFIG</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Main/#cancel">CANCEL</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://wiki.zmod.link/Main/#pause">PAUSE</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Main/#resume">RESUME</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Main/#reboot">REBOOT</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Main/#shutdown">SHUTDOWN</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://wiki.zmod.link/Main/#_user_start_print">_USER_START_PRINT</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Main/#_user_end_print">_USER_END_PRINT</a></td>
  <td align="center"></td>
  <td align="center"></td>
 </tr>
</tbody>
</table>

***
<h1 align="center"><a href="https://wiki.zmod.link/Calibrations/">Calibrations</a></h1>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center"><a href="https://wiki.zmod.link/Calibrations/#pid_tune_bed">PID_TUNE_BED</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Calibrations/#pid_tune_extruder">PID_TUNE_EXTRUDER</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Calibrations/#zshaper">ZSHAPER</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://wiki.zmod.link/Calibrations/#auto_full_bed_level">AUTO_FULL_BED_LEVEL</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Calibrations/#kamp">KAMP</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Calibrations/#load_cell_tare">LOAD_CELL_TARE</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://wiki.zmod.link/Calibrations/#belts_shaper_calibration">BELTS_SHAPER_CALIBRATION</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Calibrations/#bed_level_screws_tune">BED_LEVEL_SCREWS_TUNE</a></td>
 </tr>
</tbody>
</table>

***
<h1 align="center"><a href="https://wiki.zmod.link/Global/">Global parameters</a></h1>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center"><a href="https://wiki.zmod.link/Global/#lang">LANG</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Global/#get_zmod_data">GET_ZMOD_DATA</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Global/#save_zmod_data">SAVE_ZMOD_DATA</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://wiki.zmod.link/Global/#nozzle_control">NOZZLE_CONTROL</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Global/#set_timezone">SET_TIMEZONE</a></td>
 </tr>
</tbody>
</table>

<h2 align="center"><a href="https://wiki.zmod.link/Global/#print-startbed-mapping-parameters-start_print">Start Print</a></h2>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center"><a href="https://wiki.zmod.link/Global/#print_leveling">PRINT_LEVELING</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Global/#force_md5">FORCE_MD5</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Global/#clear">CLEAR</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Global/#use_kamp">USE_KAMP</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://wiki.zmod.link/Global/#midi_start">MIDI_START</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Global/#load_zoffset">LOAD_ZOFFSET</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Global/#mesh_test">MESH_TEST</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Global/#preclear">PRECLEAR</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://wiki.zmod.link/Global/#disable_skew">DISABLE_SKEW</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Global/#disable_priming">DISABLE_PRIMING</a></td>
 </tr>
</tbody>
</table>

<h2 align="center"><a href="https://wiki.zmod.link/Global/#print-endcancel-parametersend_print">End Print</a></h2>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center"><a href="https://wiki.zmod.link/Global/#midi_end">MIDI_END</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Global/#close_dialogs">CLOSE_DIALOGS</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Global/#stop_motor">STOP_MOTOR</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Global/#auto_reboot">AUTO_REBOOT</a></td>
 </tr>
</tbody>
</table>

<h2 align="center"><a href="https://wiki.zmod.link/Global/#system-wide-parameters">System-Wide Parameters</a></h2>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center"><a href="https://wiki.zmod.link/Global/#motion_sensor">MOTION_SENSOR</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Global/#china_cloud">CHINA_CLOUD</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Global/#save_moonraker">SAVE_MOONRAKER</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Global/#led">LED</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://wiki.zmod.link/Global/#fix_scv">FIX_SCV</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Global/#fix_e0011">FIX_E0011</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Global/#fix_e0017">FIX_E0017</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Global/#midi_on">MIDI_ON</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://wiki.zmod.link/Global/#use_swap">USE_SWAP</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Global/#display_off_timeout">DISPLAY_OFF_TIMEOUT</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Global/#new_save_config">NEW_SAVE_CONFIG</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Global/#nice">NICE</a></td>
 </tr>
 <tr>
  <td align="center"></td>
  <td align="center"><a href="https://wiki.zmod.link/Global/#pro_poweroff_timeout">PRO_POWEROFF_TIMEOUT</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Global/#wifi">WIFI</a></td>
  <td align="center"></td>
  <td align="center"></td>
 </tr>
</tbody>
</table>

***
<h1 align="center"><a href="https://wiki.zmod.link/System/">System</a></h1>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center"><a href="https://wiki.zmod.link/System/#check_system">CHECK_SYSTEM</a></td>
  <td align="center"><a href="https://wiki.zmod.link/System/#mem">MEM</a></td>
  <td align="center"><a href="https://wiki.zmod.link/System/#check_md5">CHECK_MD5</a></td>
  <td align="center"><a href="https://wiki.zmod.link/System/#web">WEB</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://wiki.zmod.link/System/#clear_emmc">CLEAR_EMMC</a></td>
  <td align="center"><a href="https://wiki.zmod.link/System/#test_emmc">TEST_EMMC</a></td>
  <td align="center"><a href="https://wiki.zmod.link/System/#display_off">DISPLAY_OFF</a></td>
  <td align="center"><a href="https://wiki.zmod.link/System/#display_on">DISPLAY_ON</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://wiki.zmod.link/System/#date_get">DATE_GET</a></td>
  <td align="center"><a href="https://wiki.zmod.link/System/#date_set">DATE_SET</a></td>
  <td align="center"><a href="https://wiki.zmod.link/System/#update_mcu">UPDATE_MCU</a></td>
  <td align="center"><a href="https://wiki.zmod.link/System/#reset_passwd">RESET_PASSWD</a></td>
 </tr>
 </tbody>
</table>

***
<h1 align="center"><a href="https://wiki.zmod.link/Zmod/">Zmod</a></h1>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center"><a href="https://wiki.zmod.link/Zmod/#camera_off">CAMERA_OFF</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Zmod/#camera_on">CAMERA_ON</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Zmod/#camera_restart">CAMERA_RESTART</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Zmod/#zflash">ZFLASH</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://wiki.zmod.link/Zmod/#tar_config">TAR_CONFIG</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Zmod/#restore_tar_config">RESTORE_TAR_CONFIG</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Zmod/#start_zmod">START_ZMOD</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Zmod/#stop_zmod">STOP_ZMOD</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://wiki.zmod.link/Zmod/#zssh_off">ZSSH_OFF</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Zmod/#zssh_on">ZSSH_ON</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Zmod/#zssh_reload">ZSSH_RELOAD</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Zmod/#zssh_restart">ZSSH_RESTART</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://wiki.zmod.link/Zmod/#remove_zmod">REMOVE_ZMOD</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Zmod/#skip_zmod">SKIP_ZMOD</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Zmod/#zrestore">ZRESTORE</a></td>
 </tr>
</tbody>
</table>

***
<h1 align="center"><a href="https://wiki.zmod.link/Filament/">Filament</a></h1>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center"><a href="https://wiki.zmod.link/Filament/#coldpull">COLDPULL</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Filament/#color) (only AD5X">COLOR</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Filament/#m600">M600</a></td>
 <tr>
 </tr>
  <td align="center"><a href="https://wiki.zmod.link/Filament/#set_pause_at_layer">SET_PAUSE_AT_LAYER</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Filament/#set_pause_next_layer">SET_PAUSE_NEXT_LAYER</a></td>
 </tr>
</tbody>
</table>

***
<h1 align="center"><a href="https://wiki.zmod.link/Telegram/">Telegram Bot</a></h1>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center">Description</td>
  <td align="center">Registration_of_bot</td>
  <td align="center">Deployment of the server</td>
 </tr>
 <tr>
  <td align="center">Installing bot telegrams with one team on Debian</td>
  <td align="center">Installation of bot telegrams by step</td>
  <td align="center">Adding ssh Keys</td>
 </tr>
 <tr>
  <td align="center"></td>
  <td align="center">ZSSH launch on the printer</td>
  <td align="center"></td>
 </tr>
 </tbody>
</table>

***
<h1 align="center"><a href="https://wiki.zmod.link/Pro/">Pro</a></h1>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center"><a href="https://wiki.zmod.link/Pro/#air_circulation_external">AIR_CIRCULATION_EXTERNAL</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Pro/#air_circulation_internal">AIR_CIRCULATION_INTERNAL</a></td>
  <td align="center"><a href="https://wiki.zmod.link/Pro/#air_circulation_stop">AIR_CIRCULATION_STOP</a></td>
 </tr>
</tbody>
</table>

<div align="center">

[![Back](https://github.com/ghzserg/zmod/wiki/images/Back.svg)](https://wiki.zmod.link/FAQ/)
[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod-macro-list)
[![Forward](https://github.com/ghzserg/zmod/wiki/images/Forward.svg)](Main_en#main-macro-list)

</div>

### AIR_CIRCULATION_EXTERNAL
[AIR_CIRCULATION_EXTERNAL](https://wiki.zmod.link/Pro/#air_circulation_external)

### AIR_CIRCULATION_INTERNAL
[AIR_CIRCULATION_INTERNAL](https://wiki.zmod.link/Pro/#air_circulation_internal)

### AIR_CIRCULATION_STOP
[AIR_CIRCULATION_STOP](https://wiki.zmod.link/Pro/#air_circulation_stop)

### AUTO_FULL_BED_LEVEL
[AUTO_FULL_BED_LEVEL](https://wiki.zmod.link/Calibrations/#auto_full_bed_level)

### BED_LEVEL_SCREWS_TUNE
[BED_LEVEL_SCREWS_TUNE](https://wiki.zmod.link/Calibrations/#bed_level_screws_tune)

### BELTS_SHAPER_CALIBRATION
[BELTS_SHAPER_CALIBRATION](https://wiki.zmod.link/Calibrations/#belts_shaper_calibration)

### CAMERA_OFF
[CAMERA_OFF](https://wiki.zmod.link/Zmod/#camera_off)

### CAMERA_ON
[CAMERA_ON](https://wiki.zmod.link/Zmod/#camera_on)

### CAMERA_RESTART
[CAMERA_RESTART](https://wiki.zmod.link/Zmod/#camera_restart)

### CANCEL
[CANCEL](https://wiki.zmod.link/Main/#cancel)

### CHECK_MD5
[CHECK_MD5](https://wiki.zmod.link/System/#check_md5)

### CHECK_SYSTEM
[CHECK_SYSTEM](https://wiki.zmod.link/System/#check_system)

### CLEAR_EMMC
[CLEAR_EMMC](https://wiki.zmod.link/System/#clear_emmc)

### CLEAR_NOZZLE
[CLEAR_NOZZLE](https://wiki.zmod.link/Main/#clear_nozzle)

### CLOSE_DIALOGS
[CLOSE_DIALOGS](https://wiki.zmod.link/Main/#close_dialogs)

### COLDPULL
[COLDPULL](https://wiki.zmod.link/Filament/#coldpull)

### COLOR
[COLOR](https://wiki.zmod.link/Filament/#color)

### DATE_GET
[DATE_GET](https://wiki.zmod.link/System/#date_get)

### DATE_SET
[DATE_SET](https://wiki.zmod.link/System/#date_set)

### DISPLAY_OFF
[DISPLAY_OFF](https://wiki.zmod.link/System/#display_off)

### DISPLAY_ON
[DISPLAY_ON](https://wiki.zmod.link/System/#display_on)

### END_PRINT
[END_PRINT](https://wiki.zmod.link/Main/#end_print)

### FAST_CLOSE_DIALOGS
[FAST_CLOSE_DIALOGS](https://wiki.zmod.link/Main/#fast_close_dialogs)

### GET_ZMOD_DATA
[GET_ZMOD_DATA](https://wiki.zmod.link/Global/#get_zmod_data)

### KAMP
[KAMP](https://wiki.zmod.link/Calibrations/#kamp)

### LANG
[LANG](https://wiki.zmod.link/Global/#lang)

### LED
[LED](https://wiki.zmod.link/Main/#led)

### LED_OFF
[LED_OFF](https://wiki.zmod.link/Main/#led_off)

### LED_ON
[LED_ON](https://wiki.zmod.link/Main/#led_on)

### LOAD_CELL_TARE
[LOAD_CELL_TARE](https://wiki.zmod.link/Calibrations/#load_cell_tare)

### M600
[M600](https://wiki.zmod.link/Filament/#m600)

### MEM
[MEM](https://wiki.zmod.link/System/#mem)

### NEW_SAVE_CONFIG
[NEW_SAVE_CONFIG](https://wiki.zmod.link/Main/#new_save_config)

### NOZZLE_CONTROL
[NOZZLE_CONTROL](https://wiki.zmod.link/Global/#nozzle_control)

### PAUSE
[PAUSE](https://wiki.zmod.link/Main/#pause)

### PID_TUNE_BED
[PID_TUNE_BED](https://wiki.zmod.link/Calibrations/#pid_tune_bed)

### PID_TUNE_EXTRUDER
[PID_TUNE_EXTRUDER](https://wiki.zmod.link/Calibrations/#pid_tune_extruder)

### PLAY_MIDI
[PLAY_MIDI](https://wiki.zmod.link/Main/#play_midi)

### REBOOT
[REBOOT](https://wiki.zmod.link/Main/#reboot)

### REMOVE_ZMOD
[REMOVE_ZMOD](https://wiki.zmod.link/Zmod/#remove_zmod)

### RESTORE_TAR_CONFIG
[RESTORE_TAR_CONFIG](https://wiki.zmod.link/Zmod/#restore_tar_config)

### RESUME
[RESUME](https://wiki.zmod.link/Main/#resume)

### SAVE_ZMOD_DATA
[SAVE_ZMOD_DATA](https://wiki.zmod.link/Global/#save_zmod_data)

### SET_PAUSE_AT_LAYER
[SET_PAUSE_AT_LAYER](https://wiki.zmod.link/Filament/#set_pause_at_layer)

### SET_PAUSE_NEXT_LAYER
[SET_PAUSE_NEXT_LAYER](https://wiki.zmod.link/Filament/#set_pause_next_layer)

### SET_TIMEZONE
[SET_TIMEZONE](https://wiki.zmod.link/Global/#set_timezone)

### SHUTDOWN
[SHUTDOWN](https://wiki.zmod.link/Main/#shutdown)

### SKIP_ZMOD
[SKIP_ZMOD](https://wiki.zmod.link/Zmod/#skip_zmod)

### START_PRINT
[START_PRINT](https://wiki.zmod.link/Main/#start_print)

### START_ZMOD
[START_ZMOD](https://wiki.zmod.link/Zmod/#start_zmod)

### STOP_ZMOD
[STOP_ZMOD](https://wiki.zmod.link/Zmod/#stop_zmod)

### TAR_CONFIG
[TAR_CONFIG](https://wiki.zmod.link/Zmod/#tar_config)

### TEST_EMMC
[TEST_EMMC](https://wiki.zmod.link/System/#test_emmc)

### UPDATE_MCU
[UPDATE_MCU](https://wiki.zmod.link/System/#update_mcu)

### WEB
[WEB](https://wiki.zmod.link/System/#web)

### ZFLASH
[ZFLASH](https://wiki.zmod.link/Zmod/#zflash)

### ZRESTORE
[ZRESTORE](https://wiki.zmod.link/Zmod/#zrestore)

### ZSHAPER
[ZSHAPER](https://wiki.zmod.link/Calibrations/#zshaper)

### ZSSH_OFF
[ZSSH_OFF](https://wiki.zmod.link/Zmod/#zssh_off)

### ZSSH_ON
[ZSSH_ON](https://wiki.zmod.link/Zmod/#zssh_on)

### ZSSH_RELOAD
[ZSSH_RELOAD](https://wiki.zmod.link/Zmod/#zssh_reload)

### ZSSH_RESTART
[ZSSH_RESTART](https://wiki.zmod.link/Zmod/#zssh_restart)

### FIX_E0011
[E0011](https://wiki.zmod.link/Global/#fix_e0017)

### FIX_E0017
[E0017](https://wiki.zmod.link/Global/#fix_e0017)
