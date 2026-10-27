<h1 align="center">Filament</h1>

Makro je malý program napsaný v jazyce Klipper/Gcode.

Lze ho vyvolat:

- ze souboru G-code
- z konzole Fluidd/Mainsail (ve Fluiddu stiskněte latinské písmeno `C`)

!!! note
    *Hodnota v závorkách je výchozí hodnota*

---

### COLDPULL

Cold pull (čištění trysky) bez použití síly.
Implementace [tohoto algoritmu](https://t.me/FF_5M_5M_Pro/2836/447172).

- Vyberte čisticí materiál (PETG, ABS, NYLON).
- Postupujte podle pokynů v konzoli Fluidd.
- Vytáhněte zbytky z trysky.

---
### M600

Pozastavení a výměna filamentu.

---

### COLOR

*Pouze AD5X*

Správa typu a barvy filamentu a jeho zavádění/vysouvání z barevných cívek.
Funguje pouze se zapnutou nativní obrazovkou.

---

### SET_PAUSE_NEXT_LAYER

Pozastavení/spuštění makra v další vrstvě:

- `ENABLE` — `0` = vypnout, `1` = zapnout (výchozí: `1`)
- `MACRO` — makro, které se má zavolat (např. `PAUSE`)

---
### SET_PAUSE_AT_LAYER

Zapnutí/vypnutí pozastavení v určité vrstvě:

- `ENABLE` — `0` = vypnout, `1` = zapnout (výchozí: `1`)
- `MACRO` — makro, které se má zavolat (např. `PAUSE`)
- `LAYER` — číslo cílové vrstvy (výchozí: `0`)

---
!!! warning
    Aby tyto funkce fungovaly, doplňte startovací kód:
    ```
    SET_PRINT_STATS_INFO TOTAL_LAYER=[total_layer_count]
    ```
    
    Do G-code pro změnu vrstvy přidejte:
    ```
    SET_PRINT_STATS_INFO CURRENT_LAYER={layer_num + 1}
    ```
