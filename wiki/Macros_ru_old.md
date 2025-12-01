# Список макросов ZMOD
Макрос - это небольшая программа на языке Klipper/Gcode. 

Он может вызываться:
- Из файла GCODE
- Из консоли Fluidd/Mainsail (нажать английскую букву `C` в fluidd)

*Значение указанное  в скобках - это значение по умолчанию*


- [Список макросов ZMOD](#список-макросов-zmod)
  - [Основное](#основное)
    - [LANG](#lang)
    - [START_PRINT](#start_print)
      - [Алгоритм снятия карты:](#алгоритм-снятия-карты)
    - [END_PRINT](#end_print)
    - [KAMP](#kamp)
    - [AUTO_FULL_BED_LEVEL](#auto_full_bed_level)
    - [CANCEL](#cancel)
    - [CLEAR_NOZZLE](#clear_nozzle)
    - [LED_ON](#led_on)
    - [LED_OFF](#led_off)
    - [LED](#led)
    - [PAUSE](#pause)
    - [RESUME](#resume)
    - [PLAY_MIDI](#play_midi)
    - [REBOOT](#reboot)
    - [CLOSE_DIALOGS](#close_dialogs)
    - [FAST_CLOSE_DIALOGS](#fast_close_dialogs)
    - [NEW_SAVE_CONFIG](#new_save_config)
    - [ZRESTORE](#zrestore)
  - [Калибровки](#калибровки)
    - [BED_LEVEL_SCREWS_TUNE](#bed_level_screws_tune)
    - [LOAD_CELL_TARE](#load_cell_tare)
    - [PID_TUNE_BED](#pid_tune_bed)
    - [PID_TUNE_EXTRUDER](#pid_tune_extruder)
    - [ZSHAPER](#zshaper)
    - [NOZZLE_CONTROL](#nozzle_control)
  - [Пауза на слое](#пауза-на-слое)
    - [SET_PAUSE_NEXT_LAYER](#set_pause_next_layer)
    - [SET_PAUSE_AT_LAYER](#set_pause_at_layer)
  - [Филамент](#филамент)
    - [COLDPULL](#coldpull)
    - [M600](#m600)
    - [COLOR](#color)
  - [Система](#система)
    - [CAMERA_ON](#camera_on)
    - [CAMERA_RESTART](#camera_restart)
    - [CAMERA_OFF](#camera_off)
    - [GET_ZMOD_DATA](#get_zmod_data)
    - [SAVE_ZMOD_DATA](#save_zmod_data)
      - [Параметры используемые при начале печати, построении карты стола \[START_PRINT\]:](#параметры-используемые-при-начале-печати-построении-карты-стола-start_print)
        - [MIDI_START](#midi_start)
        - [PRECLEAR](#preclear)
        - [PRINT_LEVELING](#print_leveling)
        - [USE_KAMP](#use_kamp)
        - [MESH_TEST](#mesh_test)
        - [FORCE_MD5](#force_md5)
        - [DISABLE_SKEW_CORRECT](#disable_skew_correct)
        - [LOAD_ZOFFSET](#load_zoffset)
        - [DISABLE_PRIMING](#disable_priming)
        - [CLEAR](#clear)
      - [Параметры используемые при окончании и отмене печати \[END_PRINT\]:](#параметры-используемые-при-окончании-и-отмене-печати-end_print)
        - [MIDI_END](#midi_end)
        - [CLOSE_DIALOGS](#close_dialogs-1)
        - [STOP_MOTOR](#stop_motor)
        - [AUTO_REBOOT](#auto_reboot)
      - [Общесистемные параметры:](#общесистемные-параметры)
        - [MOTION_SENSOR](#motion_sensor)
        - [FIX_SCV](#fix_scv)
        - [FIX_E0011](#fix_e0011)
        - [FIX_E0017](#fix_e0017)
        - [LED](#led-1)
        - [MIDI_ON](#midi_on)
        - [NEW_SAVE_CONFIG](#new_save_config-1)
        - [USE_SWAP](#use_swap)
        - [CHINA_CLOUD](#china_cloud)
        - [NICE](#nice)
        - [DISPLAY_OFF_TIMEOUT](#display_off_timeout)
        - [PRO_POWEROFF_TIMEOUT](#pro_poweroff_timeout)
        - [SAVE_MOONRAKER](#save_moonraker)
    - [SHUTDOWN](#shutdown)
    - [REMOVE_ZMOD](#remove_zmod)
    - [SKIP_ZMOD](#skip_zmod)
    - [DISPLAY_ON](#display_on)
    - [DISPLAY_OFF](#display_off)
    - [MEM](#mem)
    - [TEST_EMMC](#test_emmc)
    - [CLEAR_EMMC](#clear_emmc)
    - [DATE_GET](#date_get)
    - [DATE_SET](#date_set)
    - [WEB](#web)
    - [SET_TIMEZONE](#set_timezone)
    - [TAR_CONFIG](#tar_config)
    - [RESTORE_TAR_CONFIG](#restore_tar_config)
    - [ZFLASH](#zflash)
    - [STOP_ZMOD](#stop_zmod)
    - [START_ZMOD](#start_zmod)
    - [CHECK_MD5](#check_md5)
    - [UPDATE_MCU](#update_mcu)
    - [CHECK_SYSTEM](#check_system)
    - [ZSSH_ON](#zssh_on)
    - [ZSSH_OFF](#zssh_off)
    - [ZSSH_RESTART](#zssh_restart)
    - [ZSSH_RELOAD](#zssh_reload)
  - [Telegram Bot](#telegram-bot)
    - [Описание](#описание)
    - [Регистрация бота](#регистрация-бота)
    - [Развертывание сервера](#развертывание-сервера)
      - [Установка телеграмм бота одной командой на Debian](#установка-телеграмм-бота-одной-командой-на-debian)
      - [Установка телеграмм бота по шагам](#установка-телеграмм-бота-по-шагам)
      - [Добавление ssh ключей](#добавление-ssh-ключей)
      - [Запуск ZSSH на принтере](#запуск-zssh-на-принтере)

## Основное

### LANG

Задать язык для работы zMod.

- LANG - язык, en - Английский, ru - Русский, de - Немецкий, fr - Французский, it - Итальянский, es - Испанский, zh - Китайский, ja - Японский, ko - Корейский, pt - Португальский

Пример:
```
LANG LANG=en
```


### START_PRINT

Замена родного начального g-code (если используется с экраном, то добавить M140 или M190 Sтемпература_стола и M109 или M104 Sтемпература_экструдера)
- EXTRUDER_TEMP - температура  экструдера (245)
- BED_TEMP - температура  стола (80)
- MESH - имя карты стола, которую подгружать, если не задано, то ничего не подгружается, если не существует то будет создана ("")
- FORCE_LEVELING - принудительно строить карту  стола (False)
- SKIP_LEVELING - не строить карту стола ни при каком условии. Сильнее FORCE_KAMP и FORCE_LEVELING (False)
- FORCE_KAMP - запустить построение адаптивной карты стола (False) *Рекомендуется также поставить `SAVE_ZMOD_DATA CLEAR=LINE_PURGE`, что позволит использовать место для очистки, там где снята карта стола.*
- Z_OFFSET - Установить Z офсет (0.0)
- SKIP_ZOFFSET - Для печати с родного экрана не устанавливать Z offset, т.к. его устанавливает родной экран (True - для родного экрана / False - работа без родного экрана)
- INTERNAL - Для PRO версии при работе без родного экрана, 0 - включить внешний забор воздуха, 1 - включить внутреннюю рециркуляцию (1)

*Любой вызов калибровки FORCE_KAMP или FORCE_LEVELING вызывает [CLEAR_NOZZLE](https://github.com/ghzserg/zmod/wiki/Macros_ru_old#CLEAR_NOZZLE)*

*Во время запуска START_PRINT вызывается [ZSSH_RELOAD](https://github.com/ghzserg/zmod/wiki/Macros_ru_old#zssh_reload), который восстанавливает SSH подключение, если это требуется*

Пример для Orca c родным экраном. Удаляете  стартовый код и ставите то что ниже
```
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single]
M104 S[nozzle_temperature_initial_layer]
```
Пример для Orca без родного экрана
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

#### Это не параметры START_PRINT, это глобальные флаги/параметры, которые ставится через [SAVE_ZMOD_DATA](https://github.com/ghzserg/zmod/wiki/Macros_ru_old#%D0%BF%D0%B0%D1%80%D0%B0%D0%BC%D0%B5%D1%82%D1%80%D1%8B-%D0%B8%D1%81%D0%BF%D0%BE%D0%BB%D1%8C%D0%B7%D1%83%D0%B5%D0%BC%D1%8B%D0%B5-%D0%BF%D1%80%D0%B8-%D0%BD%D0%B0%D1%87%D0%B0%D0%BB%D0%B5-%D0%BF%D0%B5%D1%87%D0%B0%D1%82%D0%B8-%D0%BF%D0%BE%D1%81%D1%82%D1%80%D0%BE%D0%B5%D0%BD%D0%B8%D0%B8-%D0%BA%D0%B0%D1%80%D1%82%D1%8B-%D1%81%D1%82%D0%BE%D0%BB%D0%B0-start_print):
- [PRECLEAR](https://github.com/ghzserg/zmod/wiki/Macros_ru_old#preclear) - использовать пред очистку сопла в [CLEAR_NOZZLE](https://github.com/ghzserg/zmod/wiki/Macros_ru_old#CLEAR_NOZZLE) 0-нет, 1-да (0).
- [CLEAR](https://github.com/ghzserg/zmod/wiki/Macros_ru_old#clear) - Выбрать алгоритм очистки сопла (LINE_PURGE) 
- [PRINT_LEVELING](https://github.com/ghzserg/zmod/wiki/Macros_ru_old#print_leveling) - при каждой печати строить карту стола 0-нет, 1-да (0).
- [USE_KAMP](https://github.com/ghzserg/zmod/wiki/Macros_ru_old#use_kamp) - Где возможно использовать адаптивную карту стола(KAMP), вместо полной карты стола 0-нет, 1-да (0)
- [DISABLE_PRIMING](https://github.com/ghzserg/zmod/wiki/Macros_ru_old#disable_priming) - запретить очистку сопла выдавливанием 0-нет, 1-да (0)
- [FORCE_MD5](https://github.com/ghzserg/zmod/wiki/Macros_ru_old#force_md5) - если 1 (по умолчанию 1) - проверять MD5 сумму файла, при ошибке - удалять файл. *Пропишите в скрипты постобработки вызов [addMD5.bat](https://github.com/ghzserg/zmod/releases/download/R/addMD5.bat) или [addMD5.sh](https://github.com/ghzserg/zmod/releases/download/R/addMD5.sh) для Mac/Linux*(не забудьте  добавить право исполнения на файл `chmod +x addMD5.sh`) он лежит в mod. [Подробнее](https://github.com/ghzserg/zmod/wiki/Macros_ru_old#check_md5)
Его надо скачать к себе  на компьютер, а потом в Orca прописать. Профиль процесса -> Прочее -> Скрипты пост обработки. ```С:\путь_до_файла\addMD5.bat;```
- [DISABLE_SKEW_CORRECT](https://github.com/ghzserg/zmod/wiki/Macros_ru_old#disable_skew_correct) - 1 - запретить SKEW коррекцию, 0 - загрузить профиль `skew_profile`(будет вызван макрос `SKEW_PROFILE LOAD=skew_profile`) (1)
- AUTO_REBOOT - автоматическая перезагрузка принтера после окончания печати 0-нет, 1-да, 2-FIRMWARE_RESTART(только без родного экрана, с экраном REBOOT) (0).
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

### END_PRINT

Замена родного конечного g-code

#### Это не параметры END_PRINT, это глобальные флаги/параметры, которые ставится через [SAVE_ZMOD_DATA](https://github.com/ghzserg/zmod/wiki/Macros_ru_old#%D0%BF%D0%B0%D1%80%D0%B0%D0%BC%D0%B5%D1%82%D1%80%D1%8B-%D0%B8%D1%81%D0%BF%D0%BE%D0%BB%D1%8C%D0%B7%D1%83%D0%B5%D0%BC%D1%8B%D0%B5-%D0%BF%D1%80%D0%B8-%D0%BE%D0%BA%D0%BE%D0%BD%D1%87%D0%B0%D0%BD%D0%B8%D0%B8-%D0%B8-%D0%BE%D1%82%D0%BC%D0%B5%D0%BD%D0%B5-%D0%BF%D0%B5%D1%87%D0%B0%D1%82%D0%B8-end_print)
- AUTO_REBOOT - автоматическая перезагрузка принтера после окончания печати 0-нет, 1-да,2-FIRMWARE_RESTART(только без родного экрана, с экраном REBOOT) (0).
- CLOSE_DIALOGS - автоматически закрывать диалоги по окончанию и отмене печати 0-нет, 1-да медленно, 2-да быстро *Для работы быстрого закрытия диалогов необходимо через меню экрана принтера перейти на вкладку "Настройки" -> "Иконка WiFi" -> "Сетевой режим" -> **включить ползунок** "Только локальные сети"* (0).
- STOP_MOTOR - Автоматически выключать моторы после печати/отмены печати через 25 секунд 0-нет, 1-да (1)
- MIDI_END - играть MIDI при завершении печати ("")

[Оглавление](#список-макросов-zmod)

### KAMP

Адаптивная калибровка стола с очисткой сопла
- EXTRUDER_TEMP - температура  экструдера (240)
- BED_TEMP - температура  стола (80)

Добавлять первой строчкой в Orca
```
KAMP EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
```

Но лучше  использовать [START_PRINT](https://github.com/ghzserg/zmod/wiki/Macros_ru_old#start_print) и [SAVE_ZMOD_DATA](https://github.com/ghzserg/zmod/wiki/Macros_ru_old#%D0%BF%D0%B0%D1%80%D0%B0%D0%BC%D0%B5%D1%82%D1%80%D1%8B-%D0%B8%D1%81%D0%BF%D0%BE%D0%BB%D1%8C%D0%B7%D1%83%D0%B5%D0%BC%D1%8B%D0%B5-%D0%BF%D1%80%D0%B8-%D0%BD%D0%B0%D1%87%D0%B0%D0%BB%D0%B5-%D0%BF%D0%B5%D1%87%D0%B0%D1%82%D0%B8-%D0%BF%D0%BE%D1%81%D1%82%D1%80%D0%BE%D0%B5%D0%BD%D0%B8%D0%B8-%D0%BA%D0%B0%D1%80%D1%82%D1%8B-%D1%81%D1%82%D0%BE%D0%BB%D0%B0-start_print) PRINT_LEVELING=1 USE_KAMP=1

Рекомендуется также поставить `SAVE_ZMOD_DATA CLEAR=LINE_PURGE`, что позволит использовать место для очистки, там где снята карта стола.

[Какие есть варианты снятия карты стола?](https://github.com/ghzserg/zmod/wiki/FAQ#%D0%BA%D0%B0%D0%BA%D0%B8%D0%B5-%D0%B5%D1%81%D1%82%D1%8C-%D0%B2%D0%B0%D1%80%D0%B8%D0%B0%D0%BD%D1%82%D1%8B-%D1%81%D0%BD%D1%8F%D1%82%D0%B8%D1%8F-%D0%BA%D0%B0%D1%80%D1%82%D1%8B-%D1%81%D1%82%D0%BE%D0%BB%D0%B0)

### AUTO_FULL_BED_LEVEL

Калибровка стола с очисткой сопла
- EXTRUDER_TEMP - температура  экструдера (230)
- BED_TEMP - температура  стола (80)
- PROFILE - для какого профиля (auto)

Добавлять первой строчкой в Orca
```
AUTO_FULL_BED_LEVEL EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single]
M104 S[nozzle_temperature_initial_layer]
```

Но лучше  использовать [START_PRINT](https://github.com/ghzserg/zmod/wiki/Macros_ru_old#start_print) и [SAVE_ZMOD_DATA](https://github.com/ghzserg/zmod/wiki/Macros_ru_old#%D0%BF%D0%B0%D1%80%D0%B0%D0%BC%D0%B5%D1%82%D1%80%D1%8B-%D0%B8%D1%81%D0%BF%D0%BE%D0%BB%D1%8C%D0%B7%D1%83%D0%B5%D0%BC%D1%8B%D0%B5-%D0%BF%D1%80%D0%B8-%D0%BD%D0%B0%D1%87%D0%B0%D0%BB%D0%B5-%D0%BF%D0%B5%D1%87%D0%B0%D1%82%D0%B8-%D0%BF%D0%BE%D1%81%D1%82%D1%80%D0%BE%D0%B5%D0%BD%D0%B8%D0%B8-%D0%BA%D0%B0%D1%80%D1%82%D1%8B-%D1%81%D1%82%D0%BE%D0%BB%D0%B0-start_print) PRINT_LEVELING=1

[Какие есть варианты снятия карты стола?](https://github.com/ghzserg/zmod/wiki/FAQ#%D0%BA%D0%B0%D0%BA%D0%B8%D0%B5-%D0%B5%D1%81%D1%82%D1%8C-%D0%B2%D0%B0%D1%80%D0%B8%D0%B0%D0%BD%D1%82%D1%8B-%D1%81%D0%BD%D1%8F%D1%82%D0%B8%D1%8F-%D0%BA%D0%B0%D1%80%D1%82%D1%8B-%D1%81%D1%82%D0%BE%D0%BB%D0%B0)

### CANCEL

Отменить печать

### CLEAR_NOZZLE

Очистка сопла как в родной прошивке
- EXTRUDER_TEMP - температура экструдера (230)
- BED_TEMP - температура стола (80)

*PRECLEAR - использовать пред очистку сопла в [CLEAR_NOZZLE](https://github.com/ghzserg/zmod/wiki/Macros_ru_old#CLEAR_NOZZLE) 0-нет, 1-да (0). Это не параметр CLEAR_NOZZLE, это глобальный флаг, который ставится через `SAVE_ZMOD_DATA PRECLEAR=1`. Подробнее [тут](https://github.com/ghzserg/zmod/wiki/Macros_ru_old#save_zmod_data)*

### LED_ON

Включить подсветку

### LED_OFF

Выключить подсветку

### LED

Включить подсветку на несколько процентов
- S - процент (50)

### PAUSE

Поставить печать на паузу

### RESUME

Восстановить печать после паузы

### PLAY_MIDI

Проиграть MIDI файл
- FILE - имя файла (For_Elise.mid) файлы хранятся в mod_data/midi/

### REBOOT

Перезагрузить принтер

### CLOSE_DIALOGS

Вызывает медленное закрытие диалогов с родного экрана. Используется для закрытия окна по окончанию печати или при отмене печати.

Может приводить к зависанию принтера.

Реализация: @darksimpson

Также управляется через [глобальный параметр CLOSE_DIALOGS](#close_dialogs-1)

### FAST_CLOSE_DIALOGS

Вызывает быстрое закрытие диалогов с родного экрана. Используется для закрытия окна по окончанию печати или при отмене печати.

Работает быстрее, не приводит к зависанию принтера.

*Для работы быстрого закрытия диалогов необходимо через меню экрана принтера перейти на вкладку `Настройки` -> `Иконка WiFi` -> `Сетевой режим` -> **включить ползунок** `Только локальные сети`*.

Также управляется через [глобальный параметр CLOSE_DIALOGS](#close_dialogs-1)

Реализация: @darksimpson

### NEW_SAVE_CONFIG

Вызывает `SAVE_CONFIG` с родного экрана. Можно использовать для перезагрузки клиппера без зависания родного экрана.

Реализация: @darksimpson

Работает около минуты.

Иногда  может приводить к некорректной работе родного экрана

## Калибровки

### BED_LEVEL_SCREWS_TUNE

Калибровка винтов стола ([инструкция](https://www.klipper3d.org/Manual_Level.html#adjusting-bed-leveling-screws-using-the-bed-probe))
- EXTRUDER_TEMP - температура  экструдера (240)
- BED_TEMP - температура  стола (80)

Измеряет расстояние от сопла до винтов и выдает советы как крутить винты. Потом сохраняет температуры, чтобы не разогревать заново, ждёт пока пользователь отрегулирует винты и заново нажмет кнопку калибровки. Если калибровка закончена, то надо пользователю сбросить температуру самостоятельно.

### ZRESTORE 

Восстановить печать после сбоя электричества или ошибки принтера.

Восстановление печати активно, если родной экран отключен, т.к. на родном экране есть встроенная функция восстановления печати.

Чтобы работала функция восстановления **название файла для печати не должно начинаться с цифры**.

### LOAD_CELL_TARE

Cброс веса тензодатчиков. Вызывается при калибровке стола

### PID_TUNE_BED

Калибровка PID стола
- TEMPERATURE - температура стола (80)

После калибровки вызывает `SAVE_CONFIG`, см также [NEW_SAVE_CONFIG](#new_save_config-1)

Если не хотите использовать автоматическое сохранение, используйте:
```
PID_CALIBRATE HEATER=heater_bed TARGET={temperature}
```

### PID_TUNE_EXTRUDER

Калибровка PID экструдера

- TEMPERATURE - температура экструдера (245)
- COOLER - скорость вентилятора 0-255 (255)

Калибровать PID надо на ту температуру, на которой печатаете и с тем уровнем обдува, который используете.

После калибровки вызывает `SAVE_CONFIG`, см также [NEW_SAVE_CONFIG](#new_save_config-1)

Если не хотите использовать автоматическое сохранение, используйте:
```
PID_CALIBRATE HEATER=extruder TARGET={temperature}
```

### ZSHAPER

Калибровка шейперов. 

Изображения шейперов лежат на вкладке "Конфигурация" -> mod_data
- calibration_data_x.png
- calibration_data_y.png

Csv файлы находятся там же. 

[Программа для построения графиков](https://github.com/theycallmek/Klipper-Input-Shaping-Assistant/releases)

### BELTS_SHAPER_CALIBRATION

Выполнение специального теста полуоси для анализа и сравнения профилей частот отдельных ремней на принтерах CoreXY

SPECTROGRAM - 0 - не строить спектрограмму, 1 - строить спектрограмму (1)

Требует 256 мегабайт оперативной памяти и включенный SWAP

### NOZZLE_CONTROL

Контроль отрыва детали или удара сопла о стол.

Аварийное отключение принтера если зафиксировано превышение веса.

WEIGHT - вес в граммах (1500)

Настройка сохраняется и после перезагрузки.

Установите `NOZZLE_CONTROL WEIGHT=0` чтобы отключить эту функцию.

*До первого вызова макроса контроль отключен.*

При работе с родным экраном вызов макроса перезагружает принтер.

При работе без родного экрана перезапускает Klipper, т.к. вносятся изменения в файлы конфигурации.

Все работает в автоматическом режиме, но также доступны следующие макросы, которые можно использовать в Gcode:

- `ZCONTROL_ON` - активировать контроль
- `ZCONTROL_OFF` - деактивировать контроль
- `ZCONTROL_STATUS` - узнать статус функции
- `ZCONTROL_PAUSE` - при сработке вызывать паузу (пауза выполнится, только после освобождения очереди команд, включать не на первых слоях)
- `ZCONTROL_ABORT` - при сработке останавливать Klipper

Если вы хотите включить контроль сопла  на первых слоях, то добавьте через слайсер `ZCONTROL_PAUSE` на том слое, где нужно использовать паузу вместо прерывания работы

## Pro

### AIR_CIRCULATION_INTERNAL

Включить внутреннюю циркуляцию

### AIR_CIRCULATION_EXTERNAL

Включить внешнюю циркуляцию

### AIR_CIRCULATION_STOP

Выключить циркуляцию

## Пауза на слое

Чтобы эти функции работали, нужно в стартовый код добавить:
```
SET_PRINT_STATS_INFO TOTAL_LAYER=[total_layer_count]
```

В код смены слоя добавить:
```
SET_PRINT_STATS_INFO CURRENT_LAYER={layer_num + 1}
```

### SET_PAUSE_NEXT_LAYER

Установить паузу/вызвать макрос на следующем слое
- ENABLE - 0 - выключить, 1 - включить (1)
- MACRO - макрос, для вызова (`PAUSE`)

### SET_PAUSE_AT_LAYER

Включить/Выключить паузу на конкретном номере слоя

- ENABLE - 0 - выключить, 1 - включить (1)
- MACRO - макрос, для вызова (`PAUSE`)
- LAYER - номер слоя (0)

## Филамент

### COLDPULL

Колдпул (очистка сопла) без насилия.
Реализация [этого алгоритма](https://t.me/FF_5M_5M_Pro/2836/447172)

- Выбираете чем чистить (PETG, ABS, NEYLON)
- Следуете инструкциям в консоли FLUIDD. 
- Выдергиваете остаток из сопла

### M600

Пауза и замена филамента

### COLOR

*Только [AD5X](https://github.com/ghzserg/zmod/wiki/AD5X)*

Управление типом пластика, цветом пластика, загрузкой и выгрузкой филамента из цветных катушек.

Работает, только в режиме работы с родным экраном

## Система

### CAMERA_ON

Использовать альтернативную реализацию камеры
- WIDTH - ширина изображения (640)
- HEIGHT - высота изображения (480)
- FPS - кадров в секунду (20)
- VIDEO - устройство видео (video0)
- FS - 1 включить ограничение размера кадря для кривых камер, 0 не включать (0)

*Отключите камеру на экране принтера, и только потом вызывайте макрос*

Потребление оперативной памяти на  стоковой камере:
- 640x480 - 2.9 MiB
- 1280x720 -  7.8 MiB
- 1920x1080 - 18.1 MiB

*Многие камеры с Ali/Ozon/Wildberries всегда потребляют 18 MiB*

- [Что такое альтернативная камера?](https://github.com/ghzserg/zmod/wiki/FAQ#%D1%87%D1%82%D0%BE-%D1%82%D0%B0%D0%BA%D0%BE%D0%B5-%D0%B0%D0%BB%D1%8C%D1%82%D0%B5%D1%80%D0%BD%D0%B0%D1%82%D0%B8%D0%B2%D0%BD%D0%B0%D1%8F-%D0%BA%D0%B0%D0%BC%D0%B5%D1%80%D0%B0)
- [Я установил принтер, а ZMOD спрятал мою камеру! В Orca-FF я ее видел, а теперь она пропала!](https://github.com/ghzserg/zmod/wiki/FAQ#%D1%8F-%D1%83%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%B8%D0%BB-%D0%BF%D1%80%D0%B8%D0%BD%D1%82%D0%B5%D1%80-%D0%B0-zmod-%D1%81%D0%BF%D1%80%D1%8F%D1%82%D0%B0%D0%BB-%D0%BC%D0%BE%D1%8E-%D0%BA%D0%B0%D0%BC%D0%B5%D1%80%D1%83-%D0%B2-orca-ff-%D1%8F-%D0%B5%D0%B5-%D0%B2%D0%B8%D0%B4%D0%B5%D0%BB-%D0%B0-%D1%82%D0%B5%D0%BF%D0%B5%D1%80%D1%8C-%D0%BE%D0%BD%D0%B0-%D0%BF%D1%80%D0%BE%D0%BF%D0%B0%D0%BB%D0%B0)

### CAMERA_OFF

Отключить альтернативную реализацию камеры
- WIDTH - ширина изображения (640)
- HEIGHT - высота изображения (480)
- FPS - кадров в секунду (20)
- VIDEO - устройство видео (video0)

### CAMERA_RESTART

Перезапустить альтернативную реализацию камеры

### GET_ZMOD_DATA

Получить значения глобальных параметров/флагов ZMOD.
После выполнения макроса в консоли будут выведены данные, которые были сохранены ранее и применены в текущий момент

`Fluidd` -> `Макросы` -> `Основное` -> `ПАРАМЕТРЫ ZMOD`

### SAVE_ZMOD_DATA

Сохранить глобальные параметры/флаги ZMOD, применяются при каждой печати.

Этот макрос не надо добавлять в стартовый, конечный код или в файл с gcode. Макрос вызывается из консоли fluidd/mainsail. После выключения принтера  параметры сохраняются в памяти принтера в файл `mod_data/variables.cfg` (**редактировать файл руками нельзя - запорите  работу клиппера или мода**) и каждый раз их вводить не надо.

**Чтобы  отредактировать нужный параметр прейдите `Fluidd` -> `Макросы` -> `Система` -> `СОХРАНИТЬ ПАРАМЕТРЫ ZMOD`**, выбирайте параметр который хотите  поменять, заполняйте  его и нажмите `ОТПРАВИТЬ`. Смотрите  что выведет в консоли  fluidd.

Второй вариант. Написать в консоли Fluidd нужную команду например: `SAVE_ZMOD_DATA CLOSE_DIALOGS=2`

[Прочитать сохраненные параметры](https://github.com/ghzserg/zmod/wiki/Macros_ru_old#get_zmod_data)

#### Параметры используемые при начале печати, построении карты стола [START_PRINT]:

##### MIDI_START

Играть MIDI при запуске печати (""), 0 - для отключения

Пример: `SAVE_ZMOD_DATA MIDI_START=Pain-Shut-your-mouth.mid`

##### PRECLEAR

Использовать пред очистку сопла в CLEAR_NOZZLE 0-нет, 1-да (0)

Пример: `SAVE_ZMOD_DATA PRECLEAR=0`

##### PRINT_LEVELING

При каждой печати строить карту стола (средствами родного экрана, если включен экран) 0-нет, 1-да (0). *Для работы снятия карты стола с родного экрана необходимо, через меню экрана принтера перейти на вкладку "Настройки" -> "Иконка WiFi" -> "Сетевой режим" -> **включить ползунок** "Только локальные сети"*

Пример: `SAVE_ZMOD_DATA PRINT_LEVELING=1`

##### USE_KAMP

Где возможно использовать адаптивную карту стола(KAMP), вместо полной карты стола 0-нет, 1-да (0).

Рекомендуется также поставить `SAVE_ZMOD_DATA CLEAR=LINE_PURGE`, что позволит использовать место для очистки, там где снята карта стола.

*Позволяет использовать KAMP при leveling с родного экрана по сети*

Пример: `SAVE_ZMOD_DATA USE_KAMP=1`

##### MESH_TEST

Тестировать карту стола перед печатью 0-нет, 1-да (1).

Если используется умная очистка из КАМП, то ожидание нагрева не в углу, а рядом с местом очистки

Проба стола берется так:
- Подъем на 5 мм
- Сдвиг по X на 3 мм
- Ретракт
- Проба
- Подъем на 5 мм
- Обратный ретракт

Сама проба делает следующее, вызывает стандартный макрос PROBE, смотрит получившееся значение Z, если это значение попадает в диапазон от минимум карты стола - 0.21мм, до максимум карты стола + 0.21мм, то считается, что загружена корректная карта, иначе выводится предупреждение и печать прекращается.

Стоит понимать, что это очень грубая оценка соответствия реальной карты фактически загруженной. И спасать будет от случаев, когда для толстого стекла загрузили карту PEI и наоборот. 

Не стоит считать, что эта защита вас всегда спасет.

Пример: `SAVE_ZMOD_DATA MESH_TEST=0`

##### FORCE_MD5

Проверять MD5 сумму файла, при ошибке - удалять файл. 0-не проверять, 1 - проверять (1)

*Пропишите в скрипты постобработки вызов [addMD5.bat](https://github.com/ghzserg/zmod/releases/download/R/addMD5.bat) или [addMD5.sh](https://github.com/ghzserg/zmod/releases/download/R/addMD5.sh) для Mac/Linux*(не забудьте  добавить право исполнения на файл `chmod +x addMD5.sh`) он лежит в mod. [Подробнее](https://github.com/ghzserg/zmod/wiki/Macros_ru_old#check_md5)
Его надо скачать к себе  на компьютер, а потом в Orca прописать. Профиль процесса -> Прочее -> Скрипты пост обработки. ```С:\путь_до_файла\addMD5.bat;```

Пример: `SAVE_ZMOD_DATA FORCE_MD5=1`

##### DISABLE_SKEW_CORRECT

1 - запретить SKEW коррекцию, 0 - загрузить профиль `skew_profile`(будет вызван макрос `SKEW_PROFILE LOAD=skew_profile`) (1)

[Подробнее](https://www.klipper3d.org/Skew_Correction.html)

Пример: `SAVE_ZMOD_DATA DISABLE_SKEW_CORRECT=1`

##### LOAD_ZOFFSET

Загружать Z-offset из глобальных параметров, сохраненных ранее через SET_GCODE_OFFSET. 1 - да, 0 -нет (1)

[Как работает Z-Offset](https://github.com/ghzserg/zmod/wiki/FAQ#%D0%BA%D0%B0%D0%BA-%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0%D0%B5%D1%82-z-offset)

Пример: `SAVE_ZMOD_DATA LOAD_ZOFFSET=0`

##### DISABLE_PRIMING

Запретить очистку сопла выдавливанием 0-нет, 1-да (0)

Пример: `SAVE_ZMOD_DATA DISABLE_PRIMING=0`

##### CLEAR

Выбрать алгоритм очистки сопла выдавливанием (LINE_PURGE) 
- _CLEAR1 - как в Orca, _c KAMP может поцарапать стол_
- _CLEAR2 - c группы FF, _c KAMP может поцарапать стол_
- _CLEAR3 - c группы FF вариант 2, _c KAMP может поцарапать стол_
- _CLEAR4 - Код очистки от Шрейдера справа сверху-вниз
- _CLEAR_TRAP - если есть щетка справа сверху-вниз
- LINE_PURGE - очистка KAMP

Можно добавить свой макрос очистки в 'mod_data/user.cfg' и прописать его имя в этом параметре
*бегемот*

Пример: `SAVE_ZMOD_DATA CLEAR=LINE_PURGE`

#### Параметры используемые при окончании и отмене печати [END_PRINT]:

##### MIDI_END

Играть MIDI в конце печати (""), 0 - для отключения

Пример: `SAVE_ZMOD_DATA MIDI_END=Pain-Shut-your-mouth.mid`

##### CLOSE_DIALOGS

Автоматически закрывать диалоги по окончанию и отмене печати 0-нет, 1-да медленно, 2-да быстро 

*Для работы быстрого закрытия диалогов необходимо через меню экрана принтера перейти  на вкладку "Настройки" -> "Иконка WiFi" -> "Сетевой режим" -> **включить ползунок** "Только локальные сети"* (0).

Пример: `SAVE_ZMOD_DATA CLOSE_DIALOGS=2`

##### STOP_MOTOR

Автоматически выключать моторы после печати/отмены печати через 25 секунд 0-нет, 1-да (1)

Пример: `SAVE_ZMOD_DATA STOP_MOTOR=1`

##### AUTO_REBOOT

Автоматическая перезагрузка принтера после окончания печати (0):
- 0 - нет перезагрузки
- 1 - перезагрузка принтера через команду `REBOOT`
- 2 - без родного экрана - перезагрузка прошивки через `FIRMWARE_RESTART`, с экраном перезагрузка принтера через команду `REBOOT`

Пример: `SAVE_ZMOD_DATA AUTO_REBOOT=0`

#### Общесистемные параметры:

##### MOTION_SENSOR

Использовать вместо датчика наличия филамента, [датчик движения филамента](https://aliexpress.ru/item/1005007480443587.html) (0)

- 0 - нет
- 1 - да

При использовании датчика движения филамента, отключите его на родном экране, иначе печать будет останавливаться.

Пример: `SAVE_ZMOD_DATA MOTION_SENSOR=1`

##### FIX_SCV

Исправить некорректный SCV ([square_corner_velocity](https://www.klipper3d.org/Config_Reference.html#printer)) при отрисовке графиков ускорений и расчете 
 шейперов.

- 0 оставляет параметр как в стоке 5
- 1 использовать `square_corner_velocity` из `mod_data/user.cfg` или `printer.base.cfg`

Пример: `SAVE_ZMOD_DATA FIX_SCV=1`

В нашем принтере `square_corner_velocity: 25`, а расчеты графика шейперов и ускорений ведутся для `SCV = 5`.

По большому счету это влияет только на выводимые ускорения и расчетные уровни сглаживания.
`shaper_type_x`, `shaper_freq_x`, `shaper_type_y`, `shaper_freq_y` не меняются.

С другой стороны, если считать корректно - то расчетные ускорения падают примерно в 2 раза.

Поэтому рекомендация, прописать в `mod_data/user.cfg`:
```
[printer]
square_corner_velocity: 9
```

Это уменьшит скорости в поворотах, и в общем улучшит качество печати, за счет небольшого снижения скорости

##### FIX_E0011

**Это экспериментальный параметр**

Причины ошибки E0011 глобальные:
- Хост не ответил за отведенное время (0.025 сек)
- MCU не ответил за определенное время (0.025 сек)

Причины частные:
- Завис Nations MCU mainboard или eboard. `Lost communication with MCU 'mcu'`. Решение: Перезагрузка. Замена мат платы(`mcu`) или платы экструдера('eboard').
- Процессор хоста перегружен (расчет шейперов/ построение графиков)
- EMMC перегружена (работа с git, резервное копирование, загрузка большого файла во время печати и т.д.)
- Нехватка оперативной памяти. Решение: перепайка процессора и увеличения размера памяти до 256 мегабайт
- Битый кабель к экструдеру. Решение: замена/поправка кабеля
- Неконтакт разъема кабеля с платой в голове экструдера. Решение: Замена платы экструдера
- Загрузка данных из SWAP (SWAP находится на EMMC, которая работает со скорость 10 МБ/с, объем данных в SWAP при построении шейперов доходит до 25 мегабайт). Решение: отключение SWAP если у вас 256 мегабайт оперативной памяти `SAVE_ZMOD_DATA USE_SWAP=0`
- Сбой прошивки MCU. Решение: перешивка MCU [через сброс настроек](https://github.com/ghzserg/zmod/wiki/Setup#%D0%B2%D0%BE%D0%B7%D0%B2%D1%80%D0%B0%D1%82-%D0%BF%D1%80%D0%B8%D0%BD%D1%82%D0%B5%D1%80%D0%B0-%D0%BA-%D0%B7%D0%B0%D0%B2%D0%BE%D0%B4%D1%81%D0%BA%D0%B8%D0%BC-%D1%83%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%BA%D0%B0%D0%BC-%D0%BD%D0%B5%D0%BE%D0%B1%D1%85%D0%BE%D0%B4%D0%B8%D0%BC%D0%BE-%D0%B4%D0%BB%D1%8F-%D1%83%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%BA%D0%B8-%D0%BC%D0%BE%D0%B4%D0%B0). Перешивка MCU из мода [UPDATE_MCU](#update_mcu)

Исправить ошибку E0011, а также `Communication timeout during homing`, при изменении параметра принтер перезагрузится. 0-нет, 1-да (0)

- 0 оставляет параметр как в стоке 0.025
- 1 ставит параметр в 0.1

Пример: `SAVE_ZMOD_DATA FIX_E0011=1`

Ошибка «Communication timeout during homing» в может возникать из-за высокой задержки связи между хост-компьютером и микроконтроллерами. Обычно время в пути должно быть постоянно меньше 10 мс. Высокая задержка даже на короткие периоды может привести к сбоям при настройке.

`TRSYNC_TIMEOUT` — это параметр в Klipper, который по умолчанию имеет значение 0.025 секунды. Он позволяет компенсировать задержки в работе системы.

В файле `/opt/klipper/klippy/mcu.py` в стоке параметр `TRSYNC_TIMEOUT = 0.025`, патч меняет значение `TRSYNC_TIMEOUT = 0.1`

Как исправить на стоке:
- Отформатируйте USB в FAT32
- Сохраните на usb flash файл `flashforge_init.sh`:
  - [Для исправления параметра](https://github.com/ghzserg/zmod/blob/main/Native_firmware/e0011/fix/flashforge_init.sh)
  - [Для восстановления параметра как на стоке](https://github.com/ghzserg/zmod/blob/main/Native_firmware/e0011/orig/flashforge_init.sh)
- Выключите принтер
- Вставьте usb flash в принтер
- Включите принтер
- Принтер будет громко пищать
- Дождитесь когда  он перезагрузится
- Вытащите usb flash
- Напечатайте проблемный файл еще раз, ошибка E0011 больше не должна вас беспокоить.

Как исправить на стоке руками:
- Поставить [root](https://github.com/ghzserg/zmod/tree/main/Native_firmware/root)
- Зайти через [winscp](https://winscp.net/eng/download.php) по ssh и отредактировать файл `/opt/klipper/klippy/mcu.py` 
- Найти в файле строчку `TRSYNC_TIMEOUT = 0.025`
- Заменить ее на `TRSYNC_TIMEOUT = 0.1`
- Сохранить файл на принтере
- Перезагрузить принтер

##### FIX_E0017

Исправить ошибку E0017, при изменении параметра  принтер перезагрузится. 0-нет, 1-да (1)

В файле `/opt/klipper/klippy/toolhead.py` в стоке параметр `LOOKAHEAD_FLUSH_TIME = 0.5`, в оригинальном клиппере `LOOKAHEAD_FLUSH_TIME = 0.250`, наше чудо хорошо работает с `LOOKAHEAD_FLUSH_TIME = 0.150`

- 0 ставит параметр как в стоке
- 1 ставит параметр 0.150

Пример: `SAVE_ZMOD_DATA FIX_E0017=1`

Как исправить на стоке:
- Отформатируйте USB в FAT32
- Сохраните на usb flash файл:
  - [Adventurer5M-e0017-4.tgz](https://github.com/ghzserg/zmod/releases/download/R/Adventurer5M-e0017-4.tgz) для FlashForge 5M
  - [Adventurer5MPro-e0017-4.tgz](https://github.com/ghzserg/zmod/releases/download/R/Adventurer5MPro-e0017-4.tgz) для FlashForge 5M Pro
- Выключите принтер
- Вставьте usb flash в принтер
- Включите принтер
- Принтер будет громко пищать
- Дождитесь когда  он перезагрузится
- Вытащите usb flash
- Напечатайте проблемный файл еще раз, ошибка E0017 больше не должна вас беспокоить.

Как исправить на стоке в ручную:
- Поставить [root](https://github.com/ghzserg/zmod/tree/main/Native_firmware/root)
- Зайти через [winscp](https://winscp.net/eng/download.php) по ssh и отредактировать файл `/opt/klipper/klippy/toolhead.py` 
- Найти в файле строчку `LOOKAHEAD_FLUSH_TIME = 0.5`
- Заменить ее на `LOOKAHEAD_FLUSH_TIME = 0.150`
- Сохранить файл на принтере
- Перезагрузить принтер

How to fix E0017 on FlashForge 5M:
- Format USB to FAT32
- Save the file to usb flash:
 - [Adventurer5M-e0017-4.tgz](https://github.com/ghzserg/zmod/releases/download/R/Adventurer5M-e0017-4.tgz) for FlashForge 5M
 - [Adventurer5MPro-e0017-4.tgz](https://github.com/ghzserg/zmod/releases/download/R/Adventurer5MPro-e0017-4.tgz) for FlashForge 5M Pro
- Turn off the printer - Insert the USB flash drive into the printer
- Turn on the printer
- The printer will beep loudly.
- Wait until it reboots
- Remove the USB flash drive
- Print the problematic file again, the E0017 error should no longer bother you.

How to fix E0017 on FlashForge 5M manually:
- Set [root](https://github.com/ghzserg/zmod/tree/main/Native_firmware/root)
- Log in via [winscp](https://winscp.net/eng/download.php) via ssh and edit the file `/opt/klipper/klippy/toolhead.py`
- Find the line `LOOKAHEAD_FLUSH_TIME = 0.5` in the file
- Replace it with `LOOKAHEAD_FLUSH_TIME = 0.150`
- Save the file on the printer
- Restart the printer

##### LED

Яркость LED при включении (50)

Пример: `SAVE_ZMOD_DATA LED=50`

Вызов макроса [LED](#led) меняет это значение.

##### MIDI_ON 

Играть MIDI при включении (""), 0 - для отключения

Пример: `SAVE_ZMOD_DATA MIDI_ON=Pain-Shut-your-mouth.mid`

##### NEW_SAVE_CONFIG

Использовать альтернативный SAVE_CONFIG(вызывает `SAVE_CONFIG` без зависания родного экрана) [NEW_SAVE_CONFIG](#new_save_config) при калибровке PID 0-нет, 1-да (0)

Пример: `SAVE_ZMOD_DATA NEW_SAVE_CONFIG=0`

##### USE_SWAP

Использовать SWAP (1) 
- 0 - нет *Только для перепаянного процессора на 256 мб памяти*
- 1 - да, на EMMC
- 2 - да, по возможности на USB FLASH

Пример: `SAVE_ZMOD_DATA USE_SWAP=1`

##### CHINA_CLOUD

Включить китайские облака 0 - нет, 1 - да (0)

Пример: `SAVE_ZMOD_DATA CHINA_CLOUD=0`

[Отключите китайские облака](https://github.com/ghzserg/zmod/wiki/Recomendations#%D0%BE%D1%82%D0%BA%D0%BB%D1%8E%D1%87%D0%B8%D1%82%D0%B5-%D0%BA%D0%B8%D1%82%D0%B0%D0%B9%D1%81%D0%BA%D0%B8%D0%B5-%D0%BE%D0%B1%D0%BB%D0%B0%D0%BA%D0%B0)

Даже, если у вас все выключено с экрана. Принтер все равно пытается отправлять фото, видео телеметрию на китайские сервера.

Установка этого параметра в 0 частично отключает такие полезные для производителя функции.

**Если китайские облака отключены, то принтер не ищет обновления родной прошивки.**

Если вы хотите обновить родную прошивку, то нужно разрешить использование китайских облаков, `SAVE_ZMOD_DATA CHINA_CLOUD=1`, перезагрузиться и обновить родную прошивку.

Для **отключения** китайских облаков на родной прошивке:
- Отформатируйте флешку в FAT32
- Поместите файл [flashforge_init.sh](https://github.com/ghzserg/zmod/blob/main/Native_firmware/cloud/rem/flashforge_init.sh) на эту флешку
- Выключите принтер
- Вставьте флешку в принтер
- Включите принтер
- Принтер 1 раз перезагрузится
- Извлеките флешку и пользуйтесь стоковой прошивкой

Для **включения** китайских облаков на родной прошивке:
- Отформатируйте флешку в FAT32
- Поместите файл [flashforge_init.sh](https://github.com/ghzserg/zmod/blob/main/Native_firmware/cloud/orig/flashforge_init.sh) на эту флешку
- Выключите принтер
- Вставьте флешку в принтер
- Включите принтер
- Принтер 1 раз перезагрузится
- Извлеките флешку и пользуйтесь стоковой прошивкой

##### NICE

Установить приоритет процесса Klipper, 1 - минимальный приоритет, 40 - максимальный (20).

Пример: `SAVE_ZMOD_DATA NICE=20`

Чем выше приоритет у Klipper, тем больше у него ресурсов, но тем чаще отваливается Moonraker и камера.

Для тех кто знает linux:
```
NICE=20
grep -q "^nice = " /opt/config/mod_data/variables.cfg && NICE=$(grep "^nice = " /opt/config/mod_data/variables.cfg | cut -d "=" -f2| awk '{print $1}')
NICE=$((20-$NICE))
[ $NICE -ge 20 ]  && NICE=19
[ $NICE -lt -20 ] && NICE=-20
renice $NICE $(ps |grep klippy.py| grep -v grep| awk '{print $1}')
```

##### DISPLAY_OFF_TIMEOUT

Устанавливает время в секундах, когда  отключается родной экран при работе без родного экрана. (180)

Учтите, что родной экран должен успеть настроить WiFi, минимальное время 5 секунд.

Пример: `SAVE_ZMOD_DATA DISPLAY_OFF_TIMEOUT=120`

##### PRO_POWEROFF_TIMEOUT

Устанавливает время в минутах, через которое FF5m Pro отключит питание. (0)

Пример: `SAVE_ZMOD_DATA PRO_POWEROFF_TIMEOUT=10`

##### SAVE_MOONRAKER

- 0 - Загружает расположение кнопок макросов из ZMOD (по умолчанию)
- 1 - Разрешает локально сохранять изменения кнопок макросов в Fluidd/Moonraker.

При локальном сохранении макросов, новые макросы попадают в отдельный раздел.

Пример: `SAVE_ZMOD_DATA SAVE_MOONRAKER=1`


### SHUTDOWN

Выключить принтер

### REMOVE_ZMOD

Удалить zMod.

- FULL: 0 - оставить папку `/opt/config/mod_data`, 1 - удалить папку `/opt/config/mod_data` (0)

В папке `/opt/config/mod_data` хранятся настройки `zmod`, `fluidd`, `moonraker`, `mainsail`. 

Она не удаляется по умолчанию, т.к. часто люди по ошибке вызывают макрос `REMOVE_ZMOD`

### SKIP_ZMOD

Перезагрузка в оригинальную систему. Без запуска zMod.

Отключаются файлы конфигурации ZMOD, Moonraker, Fluidd.

Остается работать: 
- Альтернативная камера 
- SSH

### DISPLAY_ON

Включить стандартный экран и перезагрузить принтер.

### DISPLAY_OFF

- GUPPY: 0 - не включать GuppyScreen, 1 - включить GuppyScreen (1)

Выключить стандартный экран. Экономит 13 мегабайт (на старых версиях родной прошивки 20 мегабайт).

GuppyScreen - альтернативная реализация экрана:
- Поддерживает все функции родного экрана, кроме настройки WiFi
- Использует 9 Мб оперативной памяти, против 23 Мб на родном экране
- Не зависает при перезагрузке клипера
- Рекомендуется использовать вместо родного экрана.
- Более качественное восстановление прерванной печати
- Собирается из [форка](https://github.com/ghzserg/guppyscreen_ff5m), который базируется на [оригинальном репозитории](https://github.com/ballaswag/guppyscreen) и другом [форке](https://github.com/consp/guppyscreen/tree/flashforge_ad5m).

**Не отключайте экран, если вы четко не понимаете как работает карта стола, z-offset и макросы START_PRINT и END_PRINT**

*Не нужно включать этот макрос в  g-code.*
После перезагрузки экран будет работать ещё 3 минуты, но он не влияет на z-offset и печать идёт, не через него.

Чтобы изменить время активации альтернативного экрана [используйте глобальные параметры](https://github.com/ghzserg/zmod/wiki/Macros_ru_old#display_off_timeout)

Настройте START_PRINT. Установите нужный z-offset через него или через глобальные параметры.

[Прочитайте эту заметку](https://github.com/ghzserg/zmod/wiki/FAQ#%D1%87%D0%B5%D0%BC-%D0%BE%D1%82%D0%BB%D0%B8%D1%87%D0%B0%D0%B5%D1%82%D1%81%D1%8F-%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0-%D1%81-%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%BE%D0%BC-%D0%B8-%D0%B1%D0%B5%D0%B7-%D1%8D%D0%BA%D1%80%D0%B0%D0%BD%D0%B0)

### MEM

Посмотреть расход памяти

### TEST_EMMC

Записывает SIZE Мб на EMMC и пишет скорость чтения записи.

Выводит процент износа EMMC

- SIZE - сколько мегабайт будет записано (100)
- SYNC - 1 - работа в синхронном режиме. Будет записано и прочитано SIZE мегабайт данных и выведена скорость, 0 - асинхронный режим, в фоне  будет записано SIZE мегабайт данных - служит для фоновой нагрузки EMMC карты памяти. (1)
- FLASH - производить запись: 0 - на EMMC, 1 - на USB FLASH, 2 - в оперативную память (0)
- RANDOM - использовать случайные числа  для записи. 1 - да, 0 - нет (0)

На стоке:
Скачать файл [zfs.sh](https://github.com/ghzserg/zmod_ff5m/blob/1.6/.shell/zfs.sh)
```
chmod +x zfs.sh
./zfs.sh 400 1
```

### CLEAR_EMMC

Очищает EMMC.

- LOG - очищать log фалы, 1 - да, 0 - нет (1)
- ANY - очищать все (gcode, картинки, фото, видео) кроме лог файлов, 1 - да, 0 - нет (0)

### DATE_GET

Посмотреть текущее время

### DATE_SET

Установить дату и время в формате 2024.01.01-00:00:00
- DT - дата 2024.01.01-00:00:00

### WEB

Сменить веб интерфейс fluidd/mainsail

### SET_TIMEZONE

Смена часового пояса
- ZONE - часовая зона (Asia/Yekaterinburg)

### TAR_CONFIG

Сохраняет файлы конфигурации в архив. 

Скачать архив можно в 'Конфигурация' -> 'mod_data' -> config.tar

### RESTORE_TAR_CONFIG

Восстанавливает файлы конфигурации из архива `config.tar`

Загрузить архив нужно в 'Конфигурация' -> 'mod_data' -> `config.tar`

### ZFLASH

Позволяет обновиться с флешки по сети.

Вставьте флешку в принтер, включите  принтер. 

Если вы работаете без родного экрана, то важно, чтобы флешка была вставлена в принтер в момент включения принтера.

Этот макрос посмотрит последний доступный релиз, скачает его на флешку, проверит MD5 сумму архива и после перезагрузки установит его.

### STOP_ZMOD

Выгрузить из памяти moonraker и fluidd/Mainsail. Телеграм бот тоже  перестанет работать

### START_ZMOD

Включить обратно moonraker и fluidd/Mainsail после STOP_ZMOD.

### CHECK_MD5

Рекомендуется использовать [глобальный параметр FORCE_MD5](#force_md5) `SAVE_ZMOD_DATA FORCE_MD5=1`

Проверить MD5 сумму.
- DELETE - удалять битый файл (yes)

```
Остановка печати в случае несоответствия контрольной суммы с возможным удалением дефектного файла.

Автор не несет ответственности за любые ошибки или проблемы, а также за результаты, полученные при использовании этой информации.

Контрольная сумма записывается в начало файла с G-кодом. Если файл не содержит контрольной суммы, проверка файла макросом не осуществляется, и он сразу отправляется на печать.
Результат проверки выводится в консоль.

=========================================
1. На машине с Windows, где установлен слайсер.
  а) Копируем из папки "mod" с принтера файл "addMD5.bat" в удобной место
  б) Добавляем в слайсер скрипт из пункта 1.а, 
     заменяя "disk:\patch\to\file\" на свой путь к данному скрипту: 
    - для OrcaSlicer 
      "Процесс"->"Прочее"->"Скрипты постобработки" 
    - для SuperSlicer и PrusaSlicer
      "Настройки печати"->"Выходные параметры"->"Скрипты постобработки" 
    disk:\patch\to\file\addMD5.bat;
  в) Добавляем в слайсер макрос
    - для OrcaSlicer 
      "Профиль принтера"->"G-код принтера"->"Стартовый G-код принтера"
    - для SuperSlicer и PrusaSlicer
      "Настройки принтера"->"Пользовательский G-код"->"Стартовый G-код"
    * Без удаления файла:
      CHECK_MD5
    * С удалением файла:
      CHECK_MD5 DELETE=true
  г) Если используется макрос START_PRINT, то добавлять CHECK_MD5 в стартовый код нет необходимости. По умолчанию проверка проводится автоматически.
```

### UPDATE_MCU

Обновить MCU в принтере.

Меняет прошивку MCU с Klipper 11 на Klipper 13 и обратно

Klipper 13, в тестовом режиме (по умолчанию отключен). В нем не работает: нагрев экструдера, температура экструдера, весы.

Если не понимаете, как восстановить конфиги и прошивку MCU, не запускайте.

Если что-то пойдет не так, обратно только через фактори.

### CHECK_SYSTEM

Проверить операционную систему принтера на предмет повреждений файлов.

- RESTORE: 0 - не восстанавливать поврежденные файлы, 1 - восстановить поврежденные файлы (0)

Проверяются: 
- Файлы (md5, права)
- Каталоги (права)
- Символические ссылки (корректность указания)

Символические ссылки, права на каталоги и файлы восстанавливаются автоматически.

Время проверки около 10 минут.

Если найдены ошибки - перейдите по [ссылке](https://github.com/ghzserg/zmod/tree/main/stock), там можно скачать не поврежденную копию файла.

### ZSSH_ON

Включить перенаправление SSH
- SSH_SERVER - IP удаленного SSH сервера
- SSH_PORT - порт удаленного SSH сервера
- SSH_USER - имя  пользователя на удаленном сервере
- VIDEO_PORT - порт на удаленном сервере. который будет использоваться для видео (8080)
- MOON_PORT - порт на удаленном сервере. который будет использоваться для moonraker (7125)
- REMOTE_RUN - команда, которую нужно вызывать на удаленном сервере ("NONE"), для перезапуска телеграмм бота. Можно использовать скрипт [ff5m.sh](https://github.com/ghzserg/zmod_ff5m/blob/1.6/telegram/ff5m.sh)(лежит на принтере в папке `mod/telegram/`), записав его вот в таком виде `./ff5m.sh bot1`, где bot1 - каталог в котором  установлен бот.
Скрипт можно установить следующим образом (если вы не устанавливали бот одной командной)
```
su - tbot # сменить пользователя на пользователя под которым запускается сервис бота
wget --cache=off -q -O ff5m.sh https://raw.githubusercontent.com/ghzserg/zmod_ff5m/refs/heads/main/telegram/ff5m.sh
chmod +x ff5m.sh
```

Пример установки, вводить в консоли fluidd/mainsail:
```
ZSSH_ON SSH_SERVER=remote.server.ru SSH_PORT=22 SSH_USER=tbot VIDEO_PORT=8080 MOON_PORT=7125 REMOTE_RUN="./ff5m.sh bot1"
```

[Подробнее про работу телеграмм бота](https://github.com/ghzserg/zmod/wiki/Macros_ru_old#telegram-bot)

SSH запускается через 3 минуты  после  старта  klipper.

Также SSH автоматически перезапускается(если умер) в начале печати в макросе START_PRINT.

### ZSSH_OFF

Выключить SSH клиента

### ZSSH_RESTART

Перезапуск SSH клиента

### ZSSH_RELOAD

Перезапуск SSH клиента, если он не запущен.

Этот макрос вызывается в начале печати в макросе START_PRINT.

## Telegram Bot

### Описание

Суть:
У нас очень медленное  железо и очень мало памяти. Поэтому на железе запускать moonraker-telegram-bot нет смысла. 
Но мы его можем запустить на внешнем сервере.
Для этого нужен любой  сервер (реальный/виртуальный), до которого сможет достучаться принтер по SSH.

Новая версия автоматом создает SSH ключи (они используются для авторизации без паролей).

Ключи лежат тут:
- `‎/mod_data/ssh.pub.txt` - это открытый ключ. Текст из него необходимо поместить на сервере в файл `~/.ssh/authorized_keys`
- ‎`/mod_data/ssh.key` - закрытый ключ. Используется принтером для подключения к серверу.

Сами ключи вам по сути не нужны.
Вам достаточно вызвать макрос [ZSSH_ON](https://github.com/ghzserg/zmod/wiki/Macros_ru_old#zssh_on) передав следующие параметры:
- SSH_SERVER - ip или имя вашего сервера
- SSH_PORT - порт ssh на сервере - обычно 22
- SSH_USER - имя  пользователя на ssh сервере
- VIDEO_PORT - порт который будет использоваться на сервере для приема видеоданных с камеры (8080)
- MOON_PORT - порт который будет использоваться на сервере для приема данных от moonraker (7125).
- REMOTE_RUN - команда, которую нужно вызывать на удаленном сервере

Запуск ssh съедает около 300 килобайт памяти.

**Если принтер и сервер находятся в одной сети, то использовать SSH не обязательно. Читайте файл конфигурации [telegram.conf](https://github.com/ghzserg/zmod_ff5m/blob/1.6/telegram/telegram.conf)**
Файл конфигурации можно скачать с принтера `mod/telegram/`.

### Регистрация бота

Как зарегистрировать свой бот
1. Идете  к https://t.me/BotFather
2. /newbot
3. Вводите любое имя, которое  вам нравится
4. Вводите имя бота  ff5msuper_bot - обязательно _bot  в конце. 
5. Получаете  длинный ID - его нужно будет прописать в настройках бота в параметр bot_token

### Развертывание сервера

#### Установка телеграмм бота одной командой на Debian

Установка телеграмм бота [одной командой](https://github.com/ghzserg/zmod_ff5m/blob/1.6/telegram/telegram.sh) на Debian:

Выполнять под пользователем `root`
```
bash <(wget --cache=off -q -O - https://github.com/ghzserg/zmod_ff5m/raw/refs/heads/1.6/telegram/telegram.sh)
```

Если у вас нет wget
```
apt update && apt install wget -y
```

Этот скрипт:
1. Установит docker
2. Скачает [docker-compose.yml](https://github.com/ghzserg/zmod_ff5m/blob/1.6/telegram/docker-compose.yml) и [telegram.conf](https://github.com/ghzserg/zmod_ff5m/blob/1.6/telegram/telegram.conf). 
3. Создаст пользователя tbot
4. Напишет инструкцию по регистрации телеграмм бота и запросит `bot_token`
5. Напишет инструкцию по получению `chat_id` и запросит `chat_id`
6. Установит [ff5m.sh](https://github.com/ghzserg/zmod_ff5m/blob/1.6/telegram/ff5m.sh)

Добавить ssh ключ нужно будет самостоятельно

#### Установка телеграмм бота по шагам

Берете файл [docker-compose.yml](https://github.com/ghzserg/zmod_ff5m/blob/1.6/telegram/docker-compose.yml) из `mod/telegram/` c принтера.

Устанавливаете docker, далее инструкция для Debian
```
apt update 
apt upgrade -y
apt install docker.io docker-compose docker apparmor -y
```

Создаете  каталог для бота.
```
mkdir bot1
cd bot1
```

Помещаете  туда  [docker-compose.yml](https://github.com/ghzserg/zmod_ff5m/blob/1.6/telegram/docker-compose.yml)

Создаете подкаталоги
```
mkdir config log timelapse_finished timelapse
chmod 777 config log timelapse_finished timelapse
```

В каталог config помещаете [telegram.conf](https://github.com/ghzserg/zmod_ff5m/blob/1.6/telegram/telegram.conf) из [mod/telegram/](https://github.com/ghzserg/zmod_ff5m/blob/1.6/telegram/telegram.conf) и правите его под себя.

Больше информации о настройке бота можно почитать [тут](https://github.com/nlef/moonraker-telegram-bot/wiki)

Из каталога bot1 запускаете
```
docker-compose up -d
```

Добавляете пользователя и даем ему право самому запускать docker-compose
```
useradd tbot
usermod -a -G docker tbot
```

#### Добавление ssh ключей

Заходим под пользователем `tbot` и прописываем ssh ключи:

```
su - tbot
mkdir  .ssh
cat >.ssh/authorized_keys
```

Вводите открытый ключ из файла `mod_data/ssh.pub.txt`. Потом  `Ctrl + d` 

#### Запуск ZSSH на принтере

После этого запускаете на принтере [ZSSH_ON](https://github.com/ghzserg/zmod/wiki/Macros_ru_old#zssh_on) c необходимыми параметрами.

После  каждой перезагрузки ssh, будет запускаться автоматически через 3 минуты.
