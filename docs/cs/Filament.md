<h1 align="center">Vlákno</h1>

Makro je malý program napsaný v jazyce Klipper/Gcode.

Lze jej vyvolat z:

- Souboru GCODE
- Konzoly Fluidd/Mainsail (stiskněte anglické písmeno `C` v Fluiddu)

!!! note
    *Hodnota v závorkách je výchozí hodnota*

---

### COLDPULL

Studený tah (čištění trysky) bez síly.
Implementuje [tento algoritmus](https://t.me/FF_5M_5M_Pro/2836/447172).

- Vyberte čistící materiál (PETG, ABS, NYLON)
- Postupujte podle pokynů v konzole Fluidd
- Odstraňte zbytky z trysky

---
### M600

Pozastavit a změnit vlákno.

---

### COLOR

*Pouze AD5X*

Správa typu vlákna, barvy a načítání/vyklopení z barevných cívek.
Funguje pouze v režimu nativní obrazovky.

---

### SET_PAUSE_NEXT_LAYER

Nastavit pozastavení/spustit makro na další vrstvě:

- `ENABLE` — `0` = vypnout, `1` = zapnout (výchozí: `1`)
- `MACRO` — makro pro volání (např. `PAUSE`)

---
### SET_PAUSE_AT_LAYER

Povolit/zakázat pozastavení v určité vrstvě:

- `ENABLE` — `0` = vypnout, `1` = zapnout (výchozí: `1`)
- `MACRO` — makro pro volání (např. `PAUSE`)
- `LAYER` — číslo cílové vrstvy (výchozí: `0`)

---
!!! warning
    Chcete-li aktivovat tyto funkce, přidejte následující do svého spouštěcího kódu:
    ```
    SET_PRINT_STATS_INFO TOTAL_LAYER=[total_layer_count]
    ```
    
    Přidejte do kódu změny vrstvy:
    ```
    SET_PRINT_STATS_INFO CURRENT_LAYER={layer_num + 1}
    ```
