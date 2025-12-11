# Список макросов ZMOD

*[Read in English](https://github.com/ghzserg/zmod/wiki/Macros_en)*

Макрос - это небольшая программа на языке Klipper/Gcode. 

Он может вызываться:
- Из файла GCODE
- Из консоли Fluidd/Mainsail (нажать английскую букву `C` в fluidd)

> [!NOTE]
> *Значение указанное в скобках - это значение по умолчанию*

[@zmod_help_bot](http://t.me/zmod_help_bot)

---
<p align="center"><strong>🔷 Обзорная таблица макросов 🔷</strong></p>

***

<h1 align="center"><a href="Main_ru">Основные</a></h1>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_ru#start_print">START_PRINT</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_ru#end_print">END_PRINT</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_ru#close_dialogs">CLOSE_DIALOGS</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_ru#fast_close_dialogs">FAST_CLOSE_DIALOGS</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_ru#led">LED</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_ru#led_off">LED_OFF</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_ru#led_on">LED_ON</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_ru#play_midi">PLAY_MIDI</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_ru#clear_nozzle">CLEAR_NOZZLE</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_ru#new_save_config">NEW_SAVE_CONFIG</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_ru#cancel">CANCEL</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_ru#pause">PAUSE</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_ru#resume">RESUME</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_ru#reboot">REBOOT</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Main_ru#shutdown">SHUTDOWN</a></td>
 </tr>
</tbody>
</table>

***
<h1 align="center"><a href="Calibrations_ru">Калибровка</a></h1>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Calibrations_ru#pid_tune_bed">PID_TUNE_BED</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Calibrations_ru#pid_tune_extruder">PID_TUNE_EXTRUDER</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Calibrations_ru#zshaper">ZSHAPER</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Calibrations_ru#auto_full_bed_level">AUTO_FULL_BED_LEVEL</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Calibrations_ru#kamp">KAMP</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Calibrations_ru#load_cell_tare">LOAD_CELL_TARE</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Calibrations_ru#belts_shaper_calibration">BELTS_SHAPER_CALIBRATION</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Calibrations_ru#bed_level_screws_tune">BED_LEVEL_SCREWS_TUNE</a></td>
 </tr>
</tbody>
</table>

***
<h1 align="center"><a href="Global_ru">Глобальные параметры</a></h1>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#lang">LANG</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#get_zmod_data">GET_ZMOD_DATA</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#save_zmod_data">SAVE_ZMOD_DATA</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#nozzle_control">NOZZLE_CONTROL</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#set_timezone">SET_TIMEZONE</a></td>
 </tr>
</tbody>
</table>

<h2 align="center"><a href="Global_ru#start_print">Параметры начала печати [START_PRINT]</a></h2>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#print_leveling">PRINT_LEVELING</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#force_md5">FORCE_MD5</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#clear">CLEAR</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#use_kamp">USE_KAMP</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#midi_start">MIDI_START</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#load_zoffset">LOAD_ZOFFSET</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#mesh_test">MESH_TEST</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#preclear">PRECLEAR</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#disable_skew">DISABLE_SKEW</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#disable_priming">DISABLE_PRIMING</a></td>
 </tr>
</tbody>
</table>

<h2 align="center"><a href="Global_ru#end_print">Параметры окончания печати [END_PRINT]</a></h2>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#midi_end">MIDI_END</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#close_dialogs">CLOSE_DIALOGS</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#stop_motor">STOP_MOTOR</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#auto_reboot">AUTO_REBOOT</a></td>
 </tr>
</tbody>
</table>

<h2 align="center"><a href="Global_ru#system">Системные параметры</a></h2>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#motion_sensor">MOTION_SENSOR</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#china_cloud">CHINA_CLOUD</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#save_moonraker">SAVE_MOONRAKER</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#led">LED</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#fix_scv">FIX_SCV</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#fix_e0011">FIX_E0011</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#fix_e0017">FIX_E0017</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#midi_on">MIDI_ON</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#use_swap">USE_SWAP</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#display_off_timeout">DISPLAY_OFF_TIMEOUT</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#new_save_config">NEW_SAVE_CONFIG</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#nice">NICE</a></td>
 </tr>
 <tr>
  <td align="center"></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#pro_poweroff_timeout">PRO_POWEROFF_TIMEOUT</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Global_ru#wifi">WIFI</a></td>
  <td align="center"></td>
 </tr>
</tbody>
</table>

***
<h1 align="center"><a href="System_ru">Системные макросы</a></h1>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_ru#check_system">CHECK_SYSTEM</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_ru#mem">MEM</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_ru#check_md5">CHECK_MD5</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_ru#web">WEB</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_ru#clear_emmc">CLEAR_EMMC</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_ru#test_emmc">TEST_EMMC</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_ru#display_off">DISPLAY_OFF</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_ru#display_on">DISPLAY_ON</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_ru#date_get">DATE_GET</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_ru#date_set">DATE_SET</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_ru#update_mcu">UPDATE_MCU</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/System_ru#reset_passwd">RESET_PASSWD</a></td>
 </tr>
 </tbody>
</table>

***
<h1 align="center"><a href="Zmod_ru">Zmod</a></h1>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#camera_off">CAMERA_OFF</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#camera_on">CAMERA_ON</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#camera_restart">CAMERA_RESTART</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#zflash">ZFLASH</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#tar_config">TAR_CONFIG</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#restore_tar_config">RESTORE_TAR_CONFIG</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#start_zmod">START_ZMOD</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#stop_zmod">STOP_ZMOD</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#zssh_off">ZSSH_OFF</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#zssh_on">ZSSH_ON</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#zssh_reload">ZSSH_RELOAD</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#zssh_restart">ZSSH_RESTART</a></td>
 </tr>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#remove_zmod">REMOVE_ZMOD</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#skip_zmod">SKIP_ZMOD</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Zmod_ru#zrestore">ZRESTORE</a></td>
 </tr>
</tbody>
</table>

***
<h1 align="center"><a href="Filament_ru">Филамент и пауза</a></h1>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Filament_ru#coldpull">COLDPULL</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Filament_ru#color) (only AD5X">COLOR</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Filament_ru#m600">M600</a></td>
 <tr>
 </tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Filament_ru#set_pause_at_layer">SET_PAUSE_AT_LAYER</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Filament_ru#set_pause_next_layer">SET_PAUSE_NEXT_LAYER</a></td>
 </tr>
</tbody>
</table>

***
<h1 align="center"><a href="Telegram_ru">Telegram Bot</a></h1>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center">Описание</td>
  <td align="center">Регистрация бота</td>
  <td align="center">Установка на сервер</td>
 </tr>
 <tr>
  <td align="center">Установка бота телеграмм одной командой на Debian</td>
  <td align="center">Установка бота телеграмм пошагово</td>
  <td align="center">Добавление ключей ssh</td>
 </tr>
 <tr>
  <td align="center"></td>
  <td align="center">Запуск ZSSH на принтере</td>
  <td align="center"></td>
 </tr>
 </tbody>
</table>

***
<h1 align="center"><a href="Pro_ru">Pro</a></h1>
<table style="width: 100%; table-layout: fixed;" align="center">
<tbody>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Pro_ru#air_circulation_external">AIR_CIRCULATION_EXTERNAL</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Pro_ru#air_circulation_internal">AIR_CIRCULATION_INTERNAL</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Pro_ru#air_circulation_stop">AIR_CIRCULATION_STOP</a></td>
 </tr>
</tbody>
</table>

<div align="center">

[![Back](https://github.com/ghzserg/zmod/wiki/images/Back.svg)](https://github.com/ghzserg/zmod/wiki/FAQ)
[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](https://github.com/ghzserg/zmod/wiki/Macros#%D1%81%D0%BF%D0%B8%D1%81%D0%BE%D0%BA-%D0%BC%D0%B0%D0%BA%D1%80%D0%BE%D1%81%D0%BE%D0%B2-zmod)
[![Forward](https://github.com/ghzserg/zmod/wiki/images/Forward.svg)](Main_ru#main-macro-list)

</div>

### AIR_CIRCULATION_EXTERNAL
[AIR_CIRCULATION_EXTERNAL](https://github.com/ghzserg/zmod/wiki/Pro_ru#air_circulation_external)

### AIR_CIRCULATION_INTERNAL
[AIR_CIRCULATION_INTERNAL](https://github.com/ghzserg/zmod/wiki/Pro_ru#air_circulation_internal)

### AIR_CIRCULATION_STOP
[AIR_CIRCULATION_STOP](https://github.com/ghzserg/zmod/wiki/Pro_ru#air_circulation_stop)

### AUTO_FULL_BED_LEVEL
[AUTO_FULL_BED_LEVEL](https://github.com/ghzserg/zmod/wiki/Calibrations_ru#auto_full_bed_level)

### BED_LEVEL_SCREWS_TUNE
[BED_LEVEL_SCREWS_TUNE](https://github.com/ghzserg/zmod/wiki/Calibrations_ru#bed_level_screws_tune)

### BELTS_SHAPER_CALIBRATION
[BELTS_SHAPER_CALIBRATION](https://github.com/ghzserg/zmod/wiki/Calibrations_ru#belts_shaper_calibration)

### CAMERA_OFF
[CAMERA_OFF](https://github.com/ghzserg/zmod/wiki/Zmod_ru#camera_off)

### CAMERA_ON
[CAMERA_ON](https://github.com/ghzserg/zmod/wiki/Zmod_ru#camera_on)

### CAMERA_RESTART
[CAMERA_RESTART](https://github.com/ghzserg/zmod/wiki/Zmod_ru#camera_restart)

### CANCEL
[CANCEL](https://github.com/ghzserg/zmod/wiki/Main_ru#cancel)

### CHECK_MD5
[CHECK_MD5](https://github.com/ghzserg/zmod/wiki/System_ru#check_md5)

### CHECK_SYSTEM
[CHECK_SYSTEM](https://github.com/ghzserg/zmod/wiki/System_ru#check_system)

### CLEAR_EMMC
[CLEAR_EMMC](https://github.com/ghzserg/zmod/wiki/System_ru#clear_emmc)

### CLEAR_NOZZLE
[CLEAR_NOZZLE](https://github.com/ghzserg/zmod/wiki/Main_ru#clear_nozzle)

### CLOSE_DIALOGS
[CLOSE_DIALOGS](https://github.com/ghzserg/zmod/wiki/Main_ru#close_dialogs)

### COLDPULL
[COLDPULL](https://github.com/ghzserg/zmod/wiki/Filament_ru#coldpull)

### COLOR
[COLOR](https://github.com/ghzserg/zmod/wiki/Filament_ru#color)

### DATE_GET
[DATE_GET](https://github.com/ghzserg/zmod/wiki/System_ru#date_get)

### DATE_SET
[DATE_SET](https://github.com/ghzserg/zmod/wiki/System_ru#date_set)

### DISPLAY_OFF
[DISPLAY_OFF](https://github.com/ghzserg/zmod/wiki/System_ru#display_off)

### DISPLAY_ON
[DISPLAY_ON](https://github.com/ghzserg/zmod/wiki/System_ru#display_on)

### END_PRINT
[END_PRINT](https://github.com/ghzserg/zmod/wiki/Main_ru#end_print)

### FAST_CLOSE_DIALOGS
[FAST_CLOSE_DIALOGS](https://github.com/ghzserg/zmod/wiki/Main_ru#fast_close_dialogs)

### GET_ZMOD_DATA
[GET_ZMOD_DATA](https://github.com/ghzserg/zmod/wiki/Global_ru#get_zmod_data)

### KAMP
[KAMP](https://github.com/ghzserg/zmod/wiki/Calibrations_ru#kamp)

### LANG
[LANG](https://github.com/ghzserg/zmod/wiki/Global_ru#lang)

### LED
[LED](https://github.com/ghzserg/zmod/wiki/Main_ru#led)

### LED_OFF
[LED_OFF](https://github.com/ghzserg/zmod/wiki/Main_ru#led_off)

### LED_ON
[LED_ON](https://github.com/ghzserg/zmod/wiki/Main_ru#led_on)

### LOAD_CELL_TARE
[LOAD_CELL_TARE](https://github.com/ghzserg/zmod/wiki/Calibrations_ru#load_cell_tare)

### M600
[M600](https://github.com/ghzserg/zmod/wiki/Filament_ru#m600)

### MEM
[MEM](https://github.com/ghzserg/zmod/wiki/System_ru#mem)

### NEW_SAVE_CONFIG
[NEW_SAVE_CONFIG](https://github.com/ghzserg/zmod/wiki/Main_ru#new_save_config)

### NOZZLE_CONTROL
[NOZZLE_CONTROL](https://github.com/ghzserg/zmod/wiki/Global_ru#nozzle_control)

### PAUSE
[PAUSE](https://github.com/ghzserg/zmod/wiki/Main_ru#pause)

### PID_TUNE_BED
[PID_TUNE_BED](https://github.com/ghzserg/zmod/wiki/Calibrations_ru#pid_tune_bed)

### PID_TUNE_EXTRUDER
[PID_TUNE_EXTRUDER](https://github.com/ghzserg/zmod/wiki/Calibrations_ru#pid_tune_extruder)

### PLAY_MIDI
[PLAY_MIDI](https://github.com/ghzserg/zmod/wiki/Main_ru#play_midi)

### REBOOT
[REBOOT](https://github.com/ghzserg/zmod/wiki/Main_ru#reboot)

### REMOVE_ZMOD
[REMOVE_ZMOD](https://github.com/ghzserg/zmod/wiki/Zmod_ru#remove_zmod)

### RESTORE_TAR_CONFIG
[RESTORE_TAR_CONFIG](https://github.com/ghzserg/zmod/wiki/Zmod_ru#restore_tar_config)

### RESUME
[RESUME](https://github.com/ghzserg/zmod/wiki/Main_ru#resume)

### SAVE_ZMOD_DATA
[SAVE_ZMOD_DATA](https://github.com/ghzserg/zmod/wiki/Global_ru#save_zmod_data)

### SET_PAUSE_AT_LAYER
[SET_PAUSE_AT_LAYER](https://github.com/ghzserg/zmod/wiki/Filament_ru#set_pause_at_layer)

### SET_PAUSE_NEXT_LAYER
[SET_PAUSE_NEXT_LAYER](https://github.com/ghzserg/zmod/wiki/Filament_ru#set_pause_next_layer)

### SET_TIMEZONE
[SET_TIMEZONE](https://github.com/ghzserg/zmod/wiki/Global_ru#set_timezone)

### SHUTDOWN
[SHUTDOWN](https://github.com/ghzserg/zmod/wiki/Main_ru#shutdown)

### SKIP_ZMOD
[SKIP_ZMOD](https://github.com/ghzserg/zmod/wiki/Zmod_ru#skip_zmod)

### START_PRINT
[START_PRINT](https://github.com/ghzserg/zmod/wiki/Main_ru#start_print)

### START_ZMOD
[START_ZMOD](https://github.com/ghzserg/zmod/wiki/Zmod_ru#start_zmod)

### STOP_ZMOD
[STOP_ZMOD](https://github.com/ghzserg/zmod/wiki/Zmod_ru#stop_zmod)

### TAR_CONFIG
[TAR_CONFIG](https://github.com/ghzserg/zmod/wiki/Zmod_ru#tar_config)

### TEST_EMMC
[TEST_EMMC](https://github.com/ghzserg/zmod/wiki/System_ru#test_emmc)

### UPDATE_MCU
[UPDATE_MCU](https://github.com/ghzserg/zmod/wiki/System_ru#update_mcu)

### WEB
[WEB](https://github.com/ghzserg/zmod/wiki/System_ru#web)

### ZFLASH
[ZFLASH](https://github.com/ghzserg/zmod/wiki/Zmod_ru#zflash)

### ZRESTORE
[ZRESTORE](https://github.com/ghzserg/zmod/wiki/Zmod_ru#zrestore)

### ZSHAPER
[ZSHAPER](https://github.com/ghzserg/zmod/wiki/Calibrations_ru#zshaper)

### ZSSH_OFF
[ZSSH_OFF](https://github.com/ghzserg/zmod/wiki/Zmod_ru#zssh_off)

### ZSSH_ON
[ZSSH_ON](https://github.com/ghzserg/zmod/wiki/Zmod_ru#zssh_on)

### ZSSH_RELOAD
[ZSSH_RELOAD](https://github.com/ghzserg/zmod/wiki/Zmod_ru#zssh_reload)

### ZSSH_RESTART
[ZSSH_RESTART](https://github.com/ghzserg/zmod/wiki/Zmod_ru#zssh_restart)

### FIX_E0011
[E0011](https://github.com/ghzserg/zmod/wiki/Global_ru#fix_e0017)

### FIX_E0017
[E0017](https://github.com/ghzserg/zmod/wiki/Global_ru#fix_e0017)

