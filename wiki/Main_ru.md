<h1 align="center">Main</h1>

*[Read in English](https://github.com/ghzserg/zmod/wiki/Main_en)*

Макрос - это небольшая программа на языке Klipper/Gcode. 

Он может вызываться:
- Из файла GCODE
- Из консоли Fluidd/Mainsail (нажать английскую букву `C` в fluidd)

> [!NOTE]
> *Значение указанное в скобках - это значение по умолчанию*

[@zmod_help_bot](http://t.me/zmod_help_bot)

---

<table style="width: 100%; table-layout: fixed;" align="center">
<thead><tr>
  <th colspan="4"><p align="center"><strong>🔷 Основные параметры 🔷</strong></p></th>
</tr></thead>
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

### START_PRINT

Замена родного начального g-code (если используется с экраном, то добавить M140 или M190 Sтемпература_стола и M109 или M104 Sтемпература_экструдера)
- EXTRUDER_TEMP - температура  экструдера (245)
- BED_TEMP - температура  стола (80)
- MESH - имя карты стола, которую подгружать, если не задано, то ничего не подгружается, если не существует то будет создана ("")
- FORCE_LEVELING - принудительно строить карту  стола (False)
- SKIP_LEVELING - не строить карту стола ни при каком условии. Сильнее FORCE_KAMP и FORCE_LEVELING (False)
- FORCE_KAMP - запустить построение адаптивной карты стола (False) *Рекомендуется также поставить `SAVE_ZMOD_DATA CLEAR=LINE_PURGE`, что позволит использовать место для очистки, там где снята карта стола.*
- Z_OFFSET - Установить Z офсет (0.0)
- INTERNAL - Для PRO версии при работе в режиме без родного экрана, 1 - включить внутреннюю рециркуляцию (0)
- EXTERNAL - Для PRO версии при работе в режиме без родного экрана, 1 - включить внешнюю рециркуляцию (0)

*Любой вызов калибровки FORCE_KAMP или FORCE_LEVELING вызывает [CLEAR_NOZZLE](https://github.com/ghzserg/zmod/wiki/Main_ru#CLEAR_NOZZLE)*

*Во время запуска START_PRINT вызывается [ZSSH_RELOAD](https://github.com/ghzserg/zmod/wiki/Zmod_ru#zssh_reload), который восстанавливает SSH подключение, если это требуется*

Пример для Orca c родным экраном. Удаляете  стартовый код и ставите то что ниже
```
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single]
M104 S[nozzle_temperature_initial_layer]
```
Пример для Orca в режиме без родного экрана
```
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
```

Чтобы корректно считались слои во Fluidd, в стартовый код прописать:
```
SET_PRINT_STATS_INFO TOTAL_LAYER=[total_layer_count]
```

И в код смены слоя добавить:
```
SET_PRINT_STATS_INFO CURRENT_LAYER={layer_num + 1}
```

[Какие есть варианты снятия карты стола?](https://github.com/ghzserg/zmod/wiki/FAQ#%D0%BA%D0%B0%D0%BA%D0%B8%D0%B5-%D0%B5%D1%81%D1%82%D1%8C-%D0%B2%D0%B0%D1%80%D0%B8%D0%B0%D0%BD%D1%82%D1%8B-%D1%81%D0%BD%D1%8F%D1%82%D0%B8%D1%8F-%D0%BA%D0%B0%D1%80%D1%82%D1%8B-%D1%81%D1%82%D0%BE%D0%BB%D0%B0)

*дикобраз*

#### Это не параметры START_PRINT, это глобальные флаги/параметры, которые ставится через [SAVE_ZMOD_DATA](https://github.com/ghzserg/zmod/wiki/Global_ru#start_print):
- [PRECLEAR](https://github.com/ghzserg/zmod/wiki/Global_ru#preclear) - использовать пред очистку сопла в [CLEAR_NOZZLE](https://github.com/ghzserg/zmod/wiki/Main_ru#CLEAR_NOZZLE) 0-нет, 1-да (0).
- [CLEAR](https://github.com/ghzserg/zmod/wiki/Global_ru#clear) - Выбрать алгоритм очистки сопла (LINE_PURGE) 
- [PRINT_LEVELING](https://github.com/ghzserg/zmod/wiki/Global_ru#print_leveling) - при каждой печати строить карту стола 0-нет, 1-да (0).
- [USE_KAMP](https://github.com/ghzserg/zmod/wiki/Global_ru#use_kamp) - Где возможно использовать адаптивную карту стола(KAMP), вместо полной карты стола 0-нет, 1-да (0)
- [DISABLE_PRIMING](https://github.com/ghzserg/zmod/wiki/Global_ru#disable_priming) - запретить очистку сопла выдавливанием 0-нет, 1-да (0)
- [FORCE_MD5](https://github.com/ghzserg/zmod/wiki/Global_ru#force_md5) - если 1 (по умолчанию 1) - проверять MD5 сумму файла, при ошибке - удалять файл. *Пропишите в скрипты постобработки вызов [addMD5.bat](https://github.com/ghzserg/zmod/releases/download/R/addMD5.bat) или [addMD5.sh](https://github.com/ghzserg/zmod/releases/download/R/addMD5.sh) для Mac/Linux*(не забудьте  добавить право исполнения на файл `chmod +x addMD5.sh`) он лежит в mod. [Подробнее](https://github.com/ghzserg/zmod/wiki/System_ru#check_md5)
Его надо скачать к себе  на компьютер, а потом в Orca прописать. Профиль процесса -> Прочее -> Скрипты пост обработки. ```С:\путь_до_файла\addMD5.bat;```
- [DISABLE_SKEW](https://github.com/ghzserg/zmod/wiki/Global_ru#disable_skew) - 1 - запретить SKEW коррекцию, 0 - загрузить профиль `skew_profile`(будет вызван макрос `SKEW_PROFILE LOAD=skew_profile`) (1)
- AUTO_REBOOT - автоматическая перезагрузка принтера после окончания печати 0-нет, 1-да, 2-FIRMWARE_RESTART(только в режиме без родного экрана, с экраном REBOOT) (0).
- CLOSE_DIALOGS - автоматически закрывать диалоги по окончанию и отмене печати 0-нет, 1-да медленно, 2-да быстро *Для работы быстрого закрытия диалогов необходимо через меню экрана принтера перейти на вкладку "Настройки" -> "Иконка WiFi" -> "Сетевой режим" -> **включить ползунок** "Только локальные сети"* (0).
- STOP_MOTOR - Автоматически выключать моторы после печати/отмены печати через 25 секунд 0-нет, 1-да (1).
- MIDI_START - играть MIDI при запуске печати ("")
- MIDI_END - играть MIDI при завершении печати ("")

#### Алгоритм снятия карты:
- Если MESH не пустой, то загружается карта с именем записанном в параметре  MESH
- Если SKIP_LEVELING = True - то карта стола не будет сниматься ни при каких условиях
- В противном  случае,
- Если стоит FORCE_CAMP = True, то снимается KAMP
- В противном случае
- Если не загружена карта  стола (родная голова всегда грузит карту MESH_DATA) или если FORCE_LEVELING = True
- То запускается построение карты  стола, но она  сама не сохраняется

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)

</div>

---

### END_PRINT

Замена родного конечного g-code

#### Это не параметры END_PRINT, это глобальные флаги/параметры, которые ставится через [SAVE_ZMOD_DATA](https://github.com/ghzserg/zmod/wiki/Global_ru#end_print)
- AUTO_REBOOT - автоматическая перезагрузка принтера после окончания печати 0-нет, 1-да,2-FIRMWARE_RESTART(только в режиме без родного экрана, с экраном REBOOT) (0).
- CLOSE_DIALOGS - автоматически закрывать диалоги по окончанию и отмене печати 0-нет, 1-да медленно, 2-да быстро *Для работы быстрого закрытия диалогов необходимо через меню экрана принтера перейти на вкладку "Настройки" -> "Иконка WiFi" -> "Сетевой режим" -> **включить ползунок** "Только локальные сети"* (0).
- STOP_MOTOR - Автоматически выключать моторы после печати/отмены печати через 25 секунд 0-нет, 1-да (1)
- MIDI_END - играть MIDI при завершении печати ("")

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)

</div>

---

### CANCEL

Отменить печать

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)

</div>

---

### CLEAR_NOZZLE

Очистка сопла о стол как в родной прошивке
- EXTRUDER_TEMP - температура экструдера (230)
- BED_TEMP - температура стола (80)

*PRECLEAR - использовать пред очистку сопла в CLEAR_NOZZLE 0-нет, 1-да (0).
Это не параметр CLEAR_NOZZLE, это глобальный флаг, который ставится через `SAVE_ZMOD_DATA PRECLEAR=1`. Подробнее [тут](https://github.com/ghzserg/zmod/wiki/Global_ru#preclear)*

*Переопределение макроса `CLEAR_NOZZLE` в `mod_data/user.cfg` не изменит родную очистку сопла о стол, при вызове непосредственно с родного экрана, т.к. родной экран прекрасно работает и без zMod, а значит не использует макросы zMod*

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)

</div>

---

### LED_ON

Включить подсветку

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)

</div>

---

### LED_OFF

Выключить подсветку

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)

</div>

---

### LED

Включить подсветку на несколько процентов
- S - процент (50)

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)

</div>

---

### PAUSE

Поставить печать на паузу

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)

</div>

---

### RESUME

Восстановить печать после паузы

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)

</div>

---

### PLAY_MIDI

Проиграть MIDI файл
- FILE - имя файла (For_Elise.mid) файлы хранятся в mod_data/midi/

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)

</div>

---

### REBOOT

Перезагрузить принтер

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)

</div>

---

### CLOSE_DIALOGS

Вызывает медленное закрытие диалогов с родного экрана. Используется для закрытия окна по окончанию печати или при отмене печати.

Может приводить к зависанию принтера.

Реализация: @darksimpson

Также управляется через [глобальный параметр CLOSE_DIALOGS](https://github.com/ghzserg/zmod/wiki/Global_ru#close_dialogs)

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)

</div>

---

### FAST_CLOSE_DIALOGS

Вызывает быстрое закрытие диалогов с родного экрана. Используется для закрытия окна по окончанию печати или при отмене печати.

Работает быстрее, не приводит к зависанию принтера.

*Для работы быстрого закрытия диалогов необходимо через меню экрана принтера перейти на вкладку `Настройки` -> `Иконка WiFi` -> `Сетевой режим` -> **включить ползунок** `Только локальные сети`*.

Также управляется через [глобальный параметр CLOSE_DIALOGS](https://github.com/ghzserg/zmod/wiki/Global_ru#close_dialogs)

Реализация: @darksimpson

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)

</div>

---

### NEW_SAVE_CONFIG

Вызывает `SAVE_CONFIG` с родного экрана. Можно использовать для перезагрузки клиппера без зависания родного экрана.

Реализация: @darksimpson

Работает около минуты.

Иногда  может приводить к некорректной работе родного экрана

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)

</div>

---

### SHUTDOWN

Выключить принтер

---
<div align="center">

[![Back](https://github.com/ghzserg/zmod/wiki/images/Back.svg)](https://github.com/ghzserg/zmod/wiki/Macros)
[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#main)
[![Forward](https://github.com/ghzserg/zmod/wiki/images/Forward.svg)](https://github.com/ghzserg/zmod/wiki/Calibrations_ru)

</div>
