<h1 align="center">Filament</h1>

*[Прочитать на русском языке](https://github.com/ghzserg/zmod/wiki/Filament_ru)*

A macro is a small program written in Klipper/Gcode language.

It can be called from:
- A GCODE file
- The Fluidd/Mainsail console (press the English letter `C` in Fluidd)

To enable these features, add the following to your start code:
```
SET_PRINT_STATS_INFO TOTAL_LAYER=[total_layer_count]
```

Add this to the layer change code:
```
SET_PRINT_STATS_INFO CURRENT_LAYER={layer_num + 1}
```

> [!NOTE]
> *The value in parentheses is the default value*

[@zmod_help_bot](http://t.me/zmod_help_bot)


---

<table style="width: 100%; table-layout: fixed;" align="center">
<thead><tr>
  <th colspan="3"><p align="center"><strong>🔷 Filament & Pause 🔷</strong></p></th>
</tr></thead>
<tbody>
 <tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Filament_en#coldpull">COLDPULL</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Filament_en#color">COLOR (AD5X only)</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Filament_en#m600">M600</a></td>
 <tr>
 </tr>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Filament_en#set_pause_at_layer">SET_PAUSE_AT_LAYER</a></td>
  <td align="center"><a href="https://github.com/ghzserg/zmod/wiki/Filament_en#set_pause_next_layer">SET_PAUSE_NEXT_LAYER</a></td>
 </tr>
</tbody>
</table>

### COLDPULL

Cold pull (nozzle cleaning) without force.
Implements [this algorithm](https://t.me/FF_5M_5M_Pro/2836/447172).

- Select cleaning material (PETG, ABS, NYLON)
- Follow instructions in the Fluidd console
- Remove residue from the nozzle

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#filament)

</div>

---
### M600

Pause and filament change.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#filament)

</div>

---

### COLOR

*AD5X only*

Manage filament type, color, and load/unload from colored spools.
Works only in native screen mode.

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#filament)

</div>

---
### SET_PAUSE_NEXT_LAYER

Set pause/trigger a macro on the next layer:
- `ENABLE` — `0` = disable, `1` = enable (default: `1`)
- `MACRO` — macro to call (e.g., `PAUSE`)

<div align="center">

[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#filament)

</div>

---
### SET_PAUSE_AT_LAYER

Enable/disable pause at a specific layer number:
- `ENABLE` — `0` = disable, `1` = enable (default: `1`)
- `MACRO` — macro to call (e.g., `PAUSE`)
- `LAYER` — target layer number (default: `0`)

---
<div align="center">

[![Back](https://github.com/ghzserg/zmod/wiki/images/Back.svg)](https://github.com/ghzserg/zmod/wiki/Zmod_en)
[![Top](https://github.com/ghzserg/zmod/wiki/images/Top.svg)](#filament)
[![Forward](https://github.com/ghzserg/zmod/wiki/images/Forward.svg)](https://github.com/ghzserg/zmod/wiki/Telegram_en)

</div>
