<h1 align="center">Filament</h1>

*[Read in English](https://github.com/ghzserg/zmod/wiki/Filament_en)*

Макрос - это небольшая программа на языке Klipper/Gcode. 

Он может вызываться:
- Из файла GCODE
- Из консоли Fluidd/Mainsail (нажать английскую букву `C` в fluidd)

Чтобы эти функции работали, нужно в стартовый код добавить:
```
SET_PRINT_STATS_INFO TOTAL_LAYER=[total_layer_count]
```

В код смены слоя добавить:
```
SET_PRINT_STATS_INFO CURRENT_LAYER={layer_num + 1}
```

> [!NOTE]
> *Значение указанное в скобках - это значение по умолчанию*

[@zmod_help_bot](http://t.me/zmod_help_bot)

---

<table style="width: 100%; table-layout: fixed;" align="center">
<thead><tr>
  <th colspan="3"><p align="center"><strong>🔷 Филамент и пауза 🔷</strong></p></th>
</tr></thead>
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

### COLDPULL

Колдпул (очистка сопла) без насилия.
Реализация [этого алгоритма](https://t.me/FF_5M_5M_Pro/2836/447172)

- Выбираете чем чистить (PETG, ABS, NEYLON)
- Следуете инструкциям в консоли FLUIDD. 
- Выдергиваете остаток из сопла

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#filament)

</div>

---

### M600

Пауза и замена филамента

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#filament)

</div>

---

### COLOR

*Только AD5X*

Управление типом пластика, цветом пластика, загрузкой и выгрузкой филамента из цветных катушек.

Работает, только в режиме работы с родным экраном

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#filament)

</div>

---

### SET_PAUSE_NEXT_LAYER

Установить паузу/вызвать макрос на следующем слое
- ENABLE - 0 - выключить, 1 - включить (1)
- MACRO - макрос, для вызова (`PAUSE`)


<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#filament)

</div>

---

### SET_PAUSE_AT_LAYER

Включить/Выключить паузу на конкретном номере слоя

- ENABLE - 0 - выключить, 1 - включить (1)
- MACRO - макрос, для вызова (`PAUSE`)
- LAYER - номер слоя (0)

---
<div align="center">

[![Back](https://github.com/ghzserg/zmod/wiki/images/Back.svg)](https://github.com/ghzserg/zmod/wiki/Zmod_ru)
[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#filament)
[![Forward](https://github.com/ghzserg/zmod/wiki/images/Forward.svg)](https://github.com/ghzserg/zmod/wiki/Telegram_ru)

</div>
