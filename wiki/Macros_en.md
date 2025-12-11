<h1 align="center">ZMOD Macro List</h1>

*[Прочитать на русском языке](https://github.com/ghzserg/zmod/wiki/Macros)*

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

<h1 align="center"><a href="Main_en">Main</a></h1>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#start_print">START_PRINT</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#end_print">END_PRINT</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#close_dialogs">CLOSE_DIALOGS</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#fast_close_dialogs">FAST_CLOSE_DIALOGS</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#led">LED</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#led_off">LED_OFF</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#led_on">LED_ON</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#play_midi">PLAY_MIDI</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#clear_nozzle">CLEAR_NOZZLE</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#new_save_config">NEW_SAVE_CONFIG</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#cancel">CANCEL</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#pause">PAUSE</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#resume">RESUME</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#reboot">REBOOT</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_en#shutdown">SHUTDOWN</a></td>
 </tr>
</tbody>
</table>

***
<h1 align="center"><a href="Calibrations_en">Calibrations</a></h1>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Calibrations_en#pid_tune_bed">PID_TUNE_BED</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Calibrations_en#pid_tune_extruder">PID_TUNE_EXTRUDER</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Calibrations_en#zshaper">ZSHAPER</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Calibrations_en#auto_full_bed_level">AUTO_FULL_BED_LEVEL</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Calibrations_en#kamp">KAMP</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Calibrations_en#load_cell_tare">LOAD_CELL_TARE</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Calibrations_en#belts_shaper_calibration">BELTS_SHAPER_CALIBRATION</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Calibrations_en#bed_level_screws_tune">BED_LEVEL_SCREWS_TUNE</a></td>
 </tr>
</tbody>
</table>

***
<h1 align="center"><a href="Global_en">Global parameters</a></h1>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#lang">LANG</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#get_zmod_data">GET_ZMOD_DATA</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#save_zmod_data">SAVE_ZMOD_DATA</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#nozzle_control">NOZZLE_CONTROL</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#set_timezone">SET_TIMEZONE</a></td>
 </tr>
</tbody>
</table>

<h2 align="center"><a href="Global_en#start_print">Start Print</a></h2>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#print_leveling">PRINT_LEVELING</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#force_md5">FORCE_MD5</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#clear">CLEAR</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#use_kamp">USE_KAMP</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#midi_start">MIDI_START</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#load_zoffset">LOAD_ZOFFSET</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#mesh_test">MESH_TEST</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#preclear">PRECLEAR</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#disable_skew">DISABLE_SKEW</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#disable_priming">DISABLE_PRIMING</a></td>
 </tr>
</tbody>
</table>

<h2 align="center"><a href="Global_en#end_print">End Print</a></h2>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#midi_end">MIDI_END</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#close_dialogs">CLOSE_DIALOGS</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#stop_motor">STOP_MOTOR</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#auto_reboot">AUTO_REBOOT</a></td>
 </tr>
</tbody>
</table>

<h2 align="center"><a href="Global_en#system">System-Wide Parameters</a></h2>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#motion_sensor">MOTION_SENSOR</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#china_cloud">CHINA_CLOUD</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#save_moonraker">SAVE_MOONRAKER</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#led">LED</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#fix_scv">FIX_SCV</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#fix_e0011">FIX_E0011</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#fix_e0017">FIX_E0017</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#midi_on">MIDI_ON</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#use_swap">USE_SWAP</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#display_off_timeout">DISPLAY_OFF_TIMEOUT</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#new_save_config">NEW_SAVE_CONFIG</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#nice">NICE</a></td>
 </tr>
 <tr>
  <td align="center"></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#pro_poweroff_timeout">PRO_POWEROFF_TIMEOUT</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_en#wifi">WIFI</a></td>
  <td align="center"></td>
  <td align="center"></td>
 </tr>
</tbody>
</table>

***
<h1 align="center"><a href="System_en">System</a></h1>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_en#check_system">CHECK_SYSTEM</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_en#mem">MEM</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_en#check_md5">CHECK_MD5</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_en#web">WEB</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_en#clear_emmc">CLEAR_EMMC</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_en#test_emmc">TEST_EMMC</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_en#display_off">DISPLAY_OFF</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_en#display_on">DISPLAY_ON</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_en#date_get">DATE_GET</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_en#date_set">DATE_SET</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_en#update_mcu">UPDATE_MCU</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_en#reset_passwd">RESET_PASSWD</a></td>
 </tr>
 </tbody>
</table>

***
<h1 align="center"><a href="Zmod_en">Zmod</a></h1>
<table style="width: 100%; table-layout: fixed;" align="center">
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
 </tr>
</tbody>
</table>

***
<h1 align="center"><a href="Filament_en">Filament</a></h1>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Filament_en#coldpull">COLDPULL</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Filament_en#color) (only AD5X">COLOR</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Filament_en#m600">M600</a></td>
 <tr>
 </tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Filament_en#set_pause_at_layer">SET_PAUSE_AT_LAYER</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Filament_en#set_pause_next_layer">SET_PAUSE_NEXT_LAYER</a></td>
 </tr>
</tbody>
</table>

***
<h1 align="center"><a href="Telegram_en">Telegram Bot</a></h1>
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
<h1 align="center"><a href="Pro_en">Pro</a></h1>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Pro_en#air_circulation_external">AIR_CIRCULATION_EXTERNAL</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Pro_en#air_circulation_internal">AIR_CIRCULATION_INTERNAL</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Pro_en#air_circulation_stop">AIR_CIRCULATION_STOP</a></td>
 </tr>
</tbody>
</table>

<div align="center">

[![Back](https://github.com/ghzserg/zmod/wiki/images/Back.svg)](https://github.com/ghzserg/zmod/wiki/FAQ_en)
[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#zmod-macro-list)
[![Forward](https://github.com/ghzserg/zmod/wiki/images/Forward.svg)](Main_en#main-macro-list)

</div>

### AIR_CIRCULATION_EXTERNAL
[AIR_CIRCULATION_EXTERNAL](https://github.com/ghzserg/zmod/wiki/Pro_en#air_circulation_external)

### AIR_CIRCULATION_INTERNAL
[AIR_CIRCULATION_INTERNAL](https://github.com/ghzserg/zmod/wiki/Pro_en#air_circulation_internal)

### AIR_CIRCULATION_STOP
[AIR_CIRCULATION_STOP](https://github.com/ghzserg/zmod/wiki/Pro_en#air_circulation_stop)

### AUTO_FULL_BED_LEVEL
[AUTO_FULL_BED_LEVEL](https://github.com/ghzserg/zmod/wiki/Calibrations_en#auto_full_bed_level)

### BED_LEVEL_SCREWS_TUNE
[BED_LEVEL_SCREWS_TUNE](https://github.com/ghzserg/zmod/wiki/Calibrations_en#bed_level_screws_tune)

### BELTS_SHAPER_CALIBRATION
[BELTS_SHAPER_CALIBRATION](https://github.com/ghzserg/zmod/wiki/Calibrations_en#belts_shaper_calibration)

### CAMERA_OFF
[CAMERA_OFF](https://github.com/ghzserg/zmod/wiki/Zmod_en#camera_off)

### CAMERA_ON
[CAMERA_ON](https://github.com/ghzserg/zmod/wiki/Zmod_en#camera_on)

### CAMERA_RESTART
[CAMERA_RESTART](https://github.com/ghzserg/zmod/wiki/Zmod_en#camera_restart)

### CANCEL
[CANCEL](https://github.com/ghzserg/zmod/wiki/Main_en#cancel)

### CHECK_MD5
[CHECK_MD5](https://github.com/ghzserg/zmod/wiki/System_en#check_md5)

### CHECK_SYSTEM
[CHECK_SYSTEM](https://github.com/ghzserg/zmod/wiki/System_en#check_system)

### CLEAR_EMMC
[CLEAR_EMMC](https://github.com/ghzserg/zmod/wiki/System_en#clear_emmc)

### CLEAR_NOZZLE
[CLEAR_NOZZLE](https://github.com/ghzserg/zmod/wiki/Main_en#clear_nozzle)

### CLOSE_DIALOGS
[CLOSE_DIALOGS](https://github.com/ghzserg/zmod/wiki/Main_en#close_dialogs)

### COLDPULL
[COLDPULL](https://github.com/ghzserg/zmod/wiki/Filament_en#coldpull)

### COLOR
[COLOR](https://github.com/ghzserg/zmod/wiki/Filament_en#color)

### DATE_GET
[DATE_GET](https://github.com/ghzserg/zmod/wiki/System_en#date_get)

### DATE_SET
[DATE_SET](https://github.com/ghzserg/zmod/wiki/System_en#date_set)

### DISPLAY_OFF
[DISPLAY_OFF](https://github.com/ghzserg/zmod/wiki/System_en#display_off)

### DISPLAY_ON
[DISPLAY_ON](https://github.com/ghzserg/zmod/wiki/System_en#display_on)

### END_PRINT
[END_PRINT](https://github.com/ghzserg/zmod/wiki/Main_en#end_print)

### FAST_CLOSE_DIALOGS
[FAST_CLOSE_DIALOGS](https://github.com/ghzserg/zmod/wiki/Main_en#fast_close_dialogs)

### GET_ZMOD_DATA
[GET_ZMOD_DATA](https://github.com/ghzserg/zmod/wiki/Global_en#get_zmod_data)

### KAMP
[KAMP](https://github.com/ghzserg/zmod/wiki/Calibrations_en#kamp)

### LANG
[LANG](https://github.com/ghzserg/zmod/wiki/Global_en#lang)

### LED
[LED](https://github.com/ghzserg/zmod/wiki/Main_en#led)

### LED_OFF
[LED_OFF](https://github.com/ghzserg/zmod/wiki/Main_en#led_off)

### LED_ON
[LED_ON](https://github.com/ghzserg/zmod/wiki/Main_en#led_on)

### LOAD_CELL_TARE
[LOAD_CELL_TARE](https://github.com/ghzserg/zmod/wiki/Calibrations_en#load_cell_tare)

### M600
[M600](https://github.com/ghzserg/zmod/wiki/Filament_en#m600)

### MEM
[MEM](https://github.com/ghzserg/zmod/wiki/System_en#mem)

### NEW_SAVE_CONFIG
[NEW_SAVE_CONFIG](https://github.com/ghzserg/zmod/wiki/Main_en#new_save_config)

### NOZZLE_CONTROL
[NOZZLE_CONTROL](https://github.com/ghzserg/zmod/wiki/Global_en#nozzle_control)

### PAUSE
[PAUSE](https://github.com/ghzserg/zmod/wiki/Main_en#pause)

### PID_TUNE_BED
[PID_TUNE_BED](https://github.com/ghzserg/zmod/wiki/Calibrations_en#pid_tune_bed)

### PID_TUNE_EXTRUDER
[PID_TUNE_EXTRUDER](https://github.com/ghzserg/zmod/wiki/Calibrations_en#pid_tune_extruder)

### PLAY_MIDI
[PLAY_MIDI](https://github.com/ghzserg/zmod/wiki/Main_en#play_midi)

### REBOOT
[REBOOT](https://github.com/ghzserg/zmod/wiki/Main_en#reboot)

### REMOVE_ZMOD
[REMOVE_ZMOD](https://github.com/ghzserg/zmod/wiki/Zmod_en#remove_zmod)

### RESTORE_TAR_CONFIG
[RESTORE_TAR_CONFIG](https://github.com/ghzserg/zmod/wiki/Zmod_en#restore_tar_config)

### RESUME
[RESUME](https://github.com/ghzserg/zmod/wiki/Main_en#resume)

### SAVE_ZMOD_DATA
[SAVE_ZMOD_DATA](https://github.com/ghzserg/zmod/wiki/Global_en#save_zmod_data)

### SET_PAUSE_AT_LAYER
[SET_PAUSE_AT_LAYER](https://github.com/ghzserg/zmod/wiki/Filament_en#set_pause_at_layer)

### SET_PAUSE_NEXT_LAYER
[SET_PAUSE_NEXT_LAYER](https://github.com/ghzserg/zmod/wiki/Filament_en#set_pause_next_layer)

### SET_TIMEZONE
[SET_TIMEZONE](https://github.com/ghzserg/zmod/wiki/Global_en#set_timezone)

### SHUTDOWN
[SHUTDOWN](https://github.com/ghzserg/zmod/wiki/Main_en#shutdown)

### SKIP_ZMOD
[SKIP_ZMOD](https://github.com/ghzserg/zmod/wiki/Zmod_en#skip_zmod)

### START_PRINT
[START_PRINT](https://github.com/ghzserg/zmod/wiki/Main_en#start_print)

### START_ZMOD
[START_ZMOD](https://github.com/ghzserg/zmod/wiki/Zmod_en#start_zmod)

### STOP_ZMOD
[STOP_ZMOD](https://github.com/ghzserg/zmod/wiki/Zmod_en#stop_zmod)

### TAR_CONFIG
[TAR_CONFIG](https://github.com/ghzserg/zmod/wiki/Zmod_en#tar_config)

### TEST_EMMC
[TEST_EMMC](https://github.com/ghzserg/zmod/wiki/System_en#test_emmc)

### UPDATE_MCU
[UPDATE_MCU](https://github.com/ghzserg/zmod/wiki/System_en#update_mcu)

### WEB
[WEB](https://github.com/ghzserg/zmod/wiki/System_en#web)

### ZFLASH
[ZFLASH](https://github.com/ghzserg/zmod/wiki/Zmod_en#zflash)

### ZRESTORE
[ZRESTORE](https://github.com/ghzserg/zmod/wiki/Zmod_en#zrestore)

### ZSHAPER
[ZSHAPER](https://github.com/ghzserg/zmod/wiki/Calibrations_en#zshaper)

### ZSSH_OFF
[ZSSH_OFF](https://github.com/ghzserg/zmod/wiki/Zmod_en#zssh_off)

### ZSSH_ON
[ZSSH_ON](https://github.com/ghzserg/zmod/wiki/Zmod_en#zssh_on)

### ZSSH_RELOAD
[ZSSH_RELOAD](https://github.com/ghzserg/zmod/wiki/Zmod_en#zssh_reload)

### ZSSH_RESTART
[ZSSH_RESTART](https://github.com/ghzserg/zmod/wiki/Zmod_en#zssh_restart)

### FIX_E0011
[E0011](https://github.com/ghzserg/zmod/wiki/Global_en#fix_e0017)

### FIX_E0017
[E0017](https://github.com/ghzserg/zmod/wiki/Global_en#fix_e0017)
