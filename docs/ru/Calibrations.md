<h1 align="center">Calibrations</h1>

Макрос - это небольшая программа на языке Klipper/Gcode.

Он может вызываться:

- Из файла GCODE
- Из консоли Fluidd/Mainsail (нажать английскую букву `C` в fluidd)

!!! note
    *Значение указанное в скобках - это значение по умолчанию*

---

!!! tip
    [Калибровка принтера для новичков](/ru/SetupCalibrations/#калибровка-принтера-для-новичков)

---

### BED_LEVEL_SCREWS_TUNE

Калибровка винтов стола ([инструкция](https://www.klipper3d.org/Manual_Level.html#adjusting-bed-leveling-screws-using-the-bed-probe))

- EXTRUDER_TEMP - температура  экструдера (240)
- BED_TEMP - температура  стола (80)

Измеряет расстояние от сопла до винтов и выдает советы как крутить винты. Потом сохраняет температуры, чтобы не разогревать заново, ждёт пока пользователь отрегулирует винты и заново нажмет кнопку калибровки. Если калибровка закончена, то надо пользователю сбросить температуру самостоятельно.

---

### LOAD_CELL_TARE

Cброс веса тензодатчиков. Вызывается при калибровке стола

---

### PID_TUNE_BED

Калибровка PID стола

- TEMPERATURE - температура стола (80)

После калибровки вызывает `SAVE_CONFIG`, см также [NEW_SAVE_CONFIG](/ru/Main/#new_save_config)

Если не хотите использовать автоматическое сохранение, используйте:
```
PID_CALIBRATE HEATER=heater_bed TARGET={temperature}
```

---

### PID_TUNE_EXTRUDER

Калибровка PID экструдера

- TEMPERATURE - температура экструдера (245)
- COOLER - скорость вентилятора 0-100 (100)

Калибровать PID надо на ту температуру, на которой печатаете и с тем уровнем обдува, который используете.

После калибровки вызывает `SAVE_CONFIG`, см также [NEW_SAVE_CONFIG](/ru/Main/#new_save_config)

Если не хотите использовать автоматическое сохранение, используйте:
```
PID_CALIBRATE HEATER=extruder TARGET={temperature}
```

---

### ZSHAPER

Калибровка шейперов. 

Изображения шейперов лежат на вкладке "Конфигурация" -> mod_data

- calibration_data_x.png
- calibration_data_y.png

Csv файлы находятся там же. 

Прочитайте про [fix_scv](/ru/Global/#fix_scv)

[Программа для построения графиков](https://github.com/theycallmek/Klipper-Input-Shaping-Assistant/releases)

---

### BELTS_SHAPER_CALIBRATION

Выполнение специального теста полуоси для анализа и сравнения профилей частот отдельных ремней на принтерах CoreXY

SPECTROGRAM - 0 - не строить спектрограмму, 1 - строить спектрограмму (1)

Требует 256 мегабайт оперативной памяти и включенный SWAP

---

### KAMP

Адаптивная калибровка стола с очисткой сопла

- EXTRUDER_TEMP - температура  экструдера (240)
- BED_TEMP - температура  стола (80)

Добавлять первой строчкой в Orca
```
KAMP EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
```

Но лучше использовать [START_PRINT](/ru/Main/#start_print) и [SAVE_ZMOD_DATA](/ru/Global/#start_print) PRINT_LEVELING=1 USE_KAMP=1

Рекомендуется также поставить `SAVE_ZMOD_DATA CLEAR=LINE_PURGE`, что позволит использовать место для очистки, там где снята карта стола.

[Какие есть варианты снятия карты стола?](/ru/FAQ/#какие-есть-варианты-снятия-карты-стола)

---

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

Но лучше  использовать [START_PRINT](/ru/Main/#start_print) и [SAVE_ZMOD_DATA](/ru/Goabal/#start_print) PRINT_LEVELING=1

[Какие есть варианты снятия карты стола?](/ru/FAQ/#какие-есть-варианты-снятия-карты-стола)

---

### LOAD_ZOFFSET_NATIVE

Перенести настройки z-offset с родного экрана в режим без экрана

[Как работает Z-Offset на вашем принтере](/ru/SetupCalibrations/#как-работает-z-offset-на-вашем-принтере)
