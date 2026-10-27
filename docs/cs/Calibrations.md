<h1 align="center">Kalibrace</h1>

Makro je malý program napsaný v jazyce Klipper/Gcode.

Lze jej vyvolat z:

- Souboru GCODE
- Konzoly Fluidd/Mainsail (stiskněte anglické písmeno `C` v Fluiddu)

!!! note
    *Hodnota v závorkách je výchozí hodnota*

---

!!! tip
    [Kalibrace tiskárny pro začátečníky](SetupCalibrations.md#printer-calibration-for-beginners)

---

### BED_LEVEL_SCREWS_TUNE

Kalibrace vyrovnání šroubů podložky ([průvodce](https://www.klipper3d.org/Manual_Level.html#adjusting-bed-leveling-screws-using-the-bed-probe)).
Parametry:

- `EXTRUDER_TEMP` — teplota extrudéru (výchozí: `240`)
- `BED_TEMP` — teplota podložky (výchozí: `80`)

Měří vzdálenost mezi tryskou a šrouby podložky, poskytuje pokyny k nastavení, uchovává teploty, aby se zabránilo opětovnému zahřívání, a čeká na potvrzení uživatele. Uživatelé musí ručně resetovat teploty po dokončení.

---
### LOAD_CELL_TARE

Resetovat váhu čidla zatížení. Používá se během kalibrace podložky.

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

Kalibrujte PID na vaší obvyklé teplotě tisku a s nastaveným chlazením.
Automaticky volá `SAVE_CONFIG` po kalibraci.

Chcete-li vypnout automatické ukládání, použijte:
```gcode
PID_CALIBRATE HEATER=extruder TARGET={temperature}
```

---
### ZSHAPER

Kalibrace Input Shaper.
Výsledky jsou uloženy v:

- `calibration_data_x.png`
- `calibration_data_y.png`
- Soubory CSV

Přečtěte si [fix_scv](Global.md#fix_scv)

[Nástroj vizualizace grafu](https://github.com/theycallmek/Klipper-Input-Shaping-Assistant/releases).

---
### BELTS_SHAPER_CALIBRATION

Analýza frekvence řemenů CoreXY pomocí testu na půl osy.

- `SPECTROGRAM` — `0` = vypnout spektrogram, `1` = zapnout (výchozí: `1`)

**Požadavky:**

- 256 MB RAM
- Povolena SWAP

---
### KAMP

Adaptivní kalibrace sítě podložky s čištěním trysky.
Parametry:

- `EXTRUDER_TEMP` — teplota extrudéru (výchozí: `240`)
- `BED_TEMP` — teplota podložky (výchozí: `80`)

**Použití v Orca:**
Přidejte jako první řádek:
```gcode
KAMP EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
```

**Doporučeno:** Použijte [START_PRINT](Main.md#start_print) s `SAVE_ZMOD_DATA PRINT_LEVELING=1 USE_KAMP=1` a `SAVE_ZMOD_DATA CLEAR=LINE_PURGE` k využití oblastí pro čištění.

[Možnosti vyrovnávání podložky](FAQ.md#jaké-jsou-možnosti-pro-vyrovnávání-podložky)

---
### AUTO_FULL_BED_LEVEL

Plné vyrovnání podložky s čištěním trysky.
Parametry:

- `EXTRUDER_TEMP` — teplota extruderu (výchozí: `230`)
- `BED_TEMP` — teplota podložky (výchozí: `80`)
- `PROFILE` — název profilu meshe (výchozí: `auto`)
- `SAVE` - automaticky ukládat síť podložky (`1`)

**Použití v Orca:**
```gcode
AUTO_FULL_BED_LEVEL EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single]
M104 S[nozzle_temperature_initial_layer] T{single_extruder_multi_material ? 0 : initial_extruder}
```

**Doporučeno:** Použijte [START_PRINT](Main.md#start_print) s `SAVE_ZMOD_DATA PRINT_LEVELING=1`.

Po provedení kalibrace sítě se kalibruje počáteční nula.

[Možnosti vyrovnávání podložky](FAQ.md#jaké-jsou-možnosti-pro-vyrovnávání-podložky)

---

### LOAD_ZOFFSET_NATIVE 

Zkopíruje z-offset z nativní obrazovky do režimu bez obrazovky

[Jak funguje Z-Offset na vaší tiskárně](SetupCalibrations.md#jak-funguje-z-offset-na-vaší-tiskárně)
