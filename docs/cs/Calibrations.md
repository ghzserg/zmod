<h1 align="center">Kalibrace</h1>

Makro je malý program napsaný v jazyce Klipper/Gcode.

Lze ho vyvolat:

- ze souboru G-code
- z konzole Fluidd/Mainsail (ve Fluiddu stiskněte latinské písmeno `C`)

!!! note
    *Hodnota v závorkách je výchozí hodnota*

---

!!! tip
    [Kalibrace tiskárny pro začátečníky](SetupCalibrations.md#printer-calibration-for-beginners)

---

### BED_LEVEL_SCREWS_TUNE

Vyrovnání podložky pomocí šroubů ([návod](https://www.klipper3d.org/Manual_Level.html#adjusting-bed-leveling-screws-using-the-bed-probe)).
Parametry:

- `EXTRUDER_TEMP` — teplota extruderu (výchozí: `240`)
- `BED_TEMP` — teplota podložky (výchozí: `80`)

Měří vzdálenost mezi tryskou a šrouby podložky, dává pokyny k nastavení, drží teploty, aby nebylo nutné znovu ohřívat, a čeká na potvrzení uživatele. Po dokončení je třeba teploty ručně vynulovat.

---
### LOAD_CELL_TARE

Vynuluje váhu tenzometrů. Používá se při kalibraci podložky.

---
### PID_TUNE_BED

Kalibrace PID podložky.

- `TEMPERATURE` — teplota podložky (výchozí: `80`)

Automaticky volá `SAVE_CONFIG` po kalibraci. Viz také [NEW_SAVE_CONFIG](Main.md#new_save_config).

Chcete-li vypnout automatické ukládání, použijte:
```gcode
PID_CALIBRATE HEATER=heater_bed TARGET={temperature}
```

---
### PID_TUNE_EXTRUDER

Kalibrace PID extruderu.
Parametry:

- `TEMPERATURE` — teplota extruderu (výchozí: `245`)
- `COOLER` — otáčky ventilátoru (0-100, výchozí: `100`)

Kalibrujte PID při teplotě, při které tisknete, a s chlazením, které používáte.
Automaticky volá `SAVE_CONFIG` po kalibraci.

Chcete-li vypnout automatické ukládání, použijte:
```gcode
PID_CALIBRATE HEATER=extruder TARGET={temperature}
```

---
### ZSHAPER

Kalibrace Input Shaperu.
Výsledky se ukládají na kartě „Konfigurace“ -> `mod_data`:

- `calibration_data_x.png`
- `calibration_data_y.png`
- Soubory CSV

Přečtěte si o [FIX_SCV](Global.md#fix_scv)

[Program pro zobrazení grafů](https://github.com/theycallmek/Klipper-Input-Shaping-Assistant/releases).

---
### BELTS_SHAPER_CALIBRATION

Speciální test po diagonále pro analýzu a porovnání frekvenčních profilů řemenů u tiskáren CoreXY.

- `SPECTROGRAM` — `0` = vypnout spektrogram, `1` = zapnout (výchozí: `1`)

**Požadavky:**

- 256 MB RAM
- Zapnutý SWAP

---
### KAMP

Adaptivní kalibrace sítě podložky s čištěním trysky.
Parametry:

- `EXTRUDER_TEMP` — teplota extruderu (výchozí: `240`)
- `BED_TEMP` — teplota podložky (výchozí: `80`)

**Použití v Orca:**
Přidejte jako první řádek:
```gcode
KAMP EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
```

**Doporučeno:** Použijte [START_PRINT](Main.md#start_print) s `SAVE_ZMOD_DATA PRINT_LEVELING=1 USE_KAMP=1` a `SAVE_ZMOD_DATA CLEAR=LINE_PURGE`, aby čištění probíhalo v měřené oblasti.

[Možnosti vyrovnávání podložky](FAQ.md#jaké-jsou-možnosti-pro-vyrovnávání-podložky)

---
### AUTO_FULL_BED_LEVEL

Plné vyrovnání podložky s čištěním trysky.
Parametry:

- `EXTRUDER_TEMP` — teplota extruderu (výchozí: `230`)
- `BED_TEMP` — teplota podložky (výchozí: `80`)
- `PROFILE` — název profilu sítě (výchozí: `auto`)
- `SAVE` — automaticky uložit síť podložky (výchozí: `1`)

**Použití v Orca:**
```gcode
AUTO_FULL_BED_LEVEL EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single]
M104 S[nozzle_temperature_initial_layer] T{single_extruder_multi_material ? 0 : initial_extruder}
```

**Doporučeno:** Použijte [START_PRINT](Main.md#start_print) s `SAVE_ZMOD_DATA PRINT_LEVELING=1`.

Při kalibraci sítě se kalibruje i nulový bod.

[Možnosti vyrovnávání podložky](FAQ.md#jaké-jsou-možnosti-pro-vyrovnávání-podložky)

---

### LOAD_ZOFFSET_NATIVE 

Zkopíruje Z-offset z nativní obrazovky do režimu bez nativní obrazovky. _Pro Creator 5 / Creator 5 Pro není potřeba._

[Jak funguje Z-Offset na vaší tiskárně](SetupCalibrations.md#jak-funguje-z-offset-na-vaší-tiskárně)
