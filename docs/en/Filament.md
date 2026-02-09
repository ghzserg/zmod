<h1 align="center">Filament</h1>

A macro is a small program written in Klipper/Gcode language.

It can be called from:

- A GCODE file
- The Fluidd/Mainsail console (press the English letter `C` in Fluidd)

!!! note
    *The value in parentheses is the default value*

---

### COLDPULL

Cold pull (nozzle cleaning) without force.
Implements [this algorithm](https://t.me/FF_5M_5M_Pro/2836/447172).

- Select cleaning material (PETG, ABS, NYLON)
- Follow instructions in the Fluidd console
- Remove residue from the nozzle

---
### M600

Pause and filament change.

---

### COLOR

*AD5X only*

Manage filament type, color, and load/unload from colored spools.
Works only in native screen mode.

---

### SET_PAUSE_NEXT_LAYER

Set pause/trigger a macro on the next layer:

- `ENABLE` — `0` = disable, `1` = enable (default: `1`)
- `MACRO` — macro to call (e.g., `PAUSE`)

---
### SET_PAUSE_AT_LAYER

Enable/disable pause at a specific layer number:

- `ENABLE` — `0` = disable, `1` = enable (default: `1`)
- `MACRO` — macro to call (e.g., `PAUSE`)
- `LAYER` — target layer number (default: `0`)

---
!!! warning
    To enable these features, add the following to your start code:
    ```
    SET_PRINT_STATS_INFO TOTAL_LAYER=[total_layer_count]
    ```
    
    Add this to the layer change code:
    ```
    SET_PRINT_STATS_INFO CURRENT_LAYER={layer_num + 1}
    ```

