<h1 align="center">Calibrations</h1>

*[Read in English](https://github.com/ghzserg/zmod/wiki/Calibrations_en)*

[Калибровка принтера для новичков](https://github.com/ghzserg/zmod/wiki/Setup#%D0%BA%D0%B0%D0%BB%D0%B8%D0%B1%D1%80%D0%BE%D0%B2%D0%BA%D0%B0-%D0%BF%D1%80%D0%B8%D0%BD%D1%82%D0%B5%D1%80%D0%B0-%D0%B4%D0%BB%D1%8F-%D0%BD%D0%BE%D0%B2%D0%B8%D1%87%D0%BA%D0%BE%D0%B2)


Макрос - это небольшая программа на языке Klipper/Gcode.

Он может вызываться:
- Из файла GCODE
- Из консоли Fluidd/Mainsail (нажать английскую букву `C` в fluidd)

> [!NOTE]
> *Значение указанное в скобках - это значение по умолчанию*

[@zmod_help_bot](http://t.me/zmod_help_bot)

---

[Калибровка принтера после установки](https://github.com/ghzserg/zmod/wiki/Setup#%D0%BA%D0%B0%D0%BB%D0%B8%D0%B1%D1%80%D0%BE%D0%B2%D0%BA%D0%B0-%D0%BF%D1%80%D0%B8%D0%BD%D1%82%D0%B5%D1%80%D0%B0-%D0%BF%D0%BE%D1%81%D0%BB%D0%B5-%D1%83%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%BA%D0%B8)

<table style="width: 100%; table-layout: fixed;" align="center">
<thead><tr>
  <th colspan="3"><p align="center"><strong>🔷 Калибровка 🔷</strong></p></th>
</tr></thead>
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
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Calibrations_ru#load_zoffset_native">LOAD_ZOFFSET_NATIVE</a></td>
 </tr>
</tbody>
</table>

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#Calibrations)

</div>

---

### BED_LEVEL_SCREWS_TUNE

Калибровка винтов стола ([инструкция](https://www.klipper3d.org/Manual_Level.html#adjusting-bed-leveling-screws-using-the-bed-probe))
- EXTRUDER_TEMP - температура  экструдера (240)
- BED_TEMP - температура  стола (80)

Измеряет расстояние от сопла до винтов и выдает советы как крутить винты. Потом сохраняет температуры, чтобы не разогревать заново, ждёт пока пользователь отрегулирует винты и заново нажмет кнопку калибровки. Если калибровка закончена, то надо пользователю сбросить температуру самостоятельно.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#Calibrations)

</div>

---

### LOAD_CELL_TARE

Cброс веса тензодатчиков. Вызывается при калибровке стола

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#Calibrations)

</div>

---

### PID_TUNE_BED

Калибровка PID стола
- TEMPERATURE - температура стола (80)

После калибровки вызывает `SAVE_CONFIG`, см также [NEW_SAVE_CONFIG](https://github.com/ghzserg/zmod/wiki/Main_ru#new_save_config)

Если не хотите использовать автоматическое сохранение, используйте:
```
PID_CALIBRATE HEATER=heater_bed TARGET={temperature}
```

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#Calibrations)

</div>

---

### PID_TUNE_EXTRUDER

Калибровка PID экструдера

- TEMPERATURE - температура экструдера (245)
- COOLER - скорость вентилятора 0-100 (100)

Калибровать PID надо на ту температуру, на которой печатаете и с тем уровнем обдува, который используете.

После калибровки вызывает `SAVE_CONFIG`, см также [NEW_SAVE_CONFIG](https://github.com/ghzserg/zmod/wiki/Main_ru#new_save_config)

Если не хотите использовать автоматическое сохранение, используйте:
```
PID_CALIBRATE HEATER=extruder TARGET={temperature}
```

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#Calibrations)

</div>

---

### ZSHAPER

Калибровка шейперов. 

Изображения шейперов лежат на вкладке "Конфигурация" -> mod_data
- calibration_data_x.png
- calibration_data_y.png

Csv файлы находятся там же. 

Прочитайте про [fix_scv](https://github.com/ghzserg/zmod/wiki/Global_ru#fix_scv)

[Программа для построения графиков](https://github.com/theycallmek/Klipper-Input-Shaping-Assistant/releases)

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#Calibrations)

</div>

---

### BELTS_SHAPER_CALIBRATION

Выполнение специального теста полуоси для анализа и сравнения профилей частот отдельных ремней на принтерах CoreXY

SPECTROGRAM - 0 - не строить спектрограмму, 1 - строить спектрограмму (1)

Требует 256 мегабайт оперативной памяти и включенный SWAP

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#Calibrations)

</div>

---

### KAMP

Адаптивная калибровка стола с очисткой сопла
- EXTRUDER_TEMP - температура  экструдера (240)
- BED_TEMP - температура  стола (80)

Добавлять первой строчкой в Orca
```
KAMP EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
```

Но лучше использовать [START_PRINT](https://github.com/ghzserg/zmod/wiki/Main_ru#start_print) и [SAVE_ZMOD_DATA](https://github.com/ghzserg/zmod/wiki/Global_ru#start_print) PRINT_LEVELING=1 USE_KAMP=1

Рекомендуется также поставить `SAVE_ZMOD_DATA CLEAR=LINE_PURGE`, что позволит использовать место для очистки, там где снята карта стола.

[Какие есть варианты снятия карты стола?](https://github.com/ghzserg/zmod/wiki/FAQ#%D0%BA%D0%B0%D0%BA%D0%B8%D0%B5-%D0%B5%D1%81%D1%82%D1%8C-%D0%B2%D0%B0%D1%80%D0%B8%D0%B0%D0%BD%D1%82%D1%8B-%D1%81%D0%BD%D1%8F%D1%82%D0%B8%D1%8F-%D0%BA%D0%B0%D1%80%D1%82%D1%8B-%D1%81%D1%82%D0%BE%D0%BB%D0%B0)

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#Calibrations)

</div>

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

Но лучше  использовать [START_PRINT](https://github.com/ghzserg/zmod/wiki/Main_ru#start_print) и [SAVE_ZMOD_DATA](https://github.com/ghzserg/zmod/wiki/Goabal_ru#start_print) PRINT_LEVELING=1

[Какие есть варианты снятия карты стола?](https://github.com/ghzserg/zmod/wiki/FAQ#%D0%BA%D0%B0%D0%BA%D0%B8%D0%B5-%D0%B5%D1%81%D1%82%D1%8C-%D0%B2%D0%B0%D1%80%D0%B8%D0%B0%D0%BD%D1%82%D1%8B-%D1%81%D0%BD%D1%8F%D1%82%D0%B8%D1%8F-%D0%BA%D0%B0%D1%80%D1%82%D1%8B-%D1%81%D1%82%D0%BE%D0%BB%D0%B0)

<div align="center">

[![Back](https://github.com/ghzserg/zmod/wiki/images/Back.svg)](https://github.com/ghzserg/zmod/wiki/Main_ru)
[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#Calibrations)
[![Forward](https://github.com/ghzserg/zmod/wiki/images/Forward.svg)](https://github.com/ghzserg/zmod/wiki/Global_ru)

</div>

---

### LOAD_ZOFFSET_NATIVE

Перенести настройки z-offset с родного экрана в режим без экрана

[Как работает Z-Offset на вашем принтере](https://github.com/ghzserg/zmod/wiki/Setup#%D0%BA%D0%B0%D0%BA-%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0%D0%B5%D1%82-z-offset-%D0%BD%D0%B0-%D0%B2%D0%B0%D1%88%D0%B5%D0%BC-%D0%BF%D1%80%D0%B8%D0%BD%D1%82%D0%B5%D1%80%D0%B5)

<div align="center">

[![Back](https://github.com/ghzserg/zmod/wiki/images/Back.svg)](https://github.com/ghzserg/zmod/wiki/Main_ru)
[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#Calibrations)
[![Forward](https://github.com/ghzserg/zmod/wiki/images/Forward.svg)](https://github.com/ghzserg/zmod/wiki/Global_ru)

</div>

---