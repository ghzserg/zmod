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

Kalibrace vyrovnání šroubů stolu ([průvodce](https://www.klipper3d.org/Manual_Level.html#adjusting-bed-leveling-screws-using-the-bed-probe)).
Parametry:

- `EXTRUDER_TEMP` — teplota extrudéru (výchozí: `240`)
- `BED_TEMP` — teplota lůžka (výchozí: `80`)

Měří vzdálenost mezi tryskou a šrouby stolu, poskytuje pokyny k nastavení, uchovává teploty, aby se zabránilo opětovnému zahřívání, a čeká na potvrzení uživatele. Uživatelé musí ručně resetovat teploty po dokončení.

---
### LOAD_CELL_TARE

Resetovat váhu čidla zatížení. Používá se během kalibrace stolu.

---
### PID_TUNE_BED

Kalibrace PID stolu.

- `TEMPERATURE` — teplota stolu (výchozí: `80`)

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

Adaptivní kalibrace mesh stolu s čištěním trysky.
Parametry:

- `EXTRUDER_TEMP` — teplota extrudéru (výchozí: `240`)
- `BED_TEMP` — teplota stolu (výchozí: `80`)

**Použití v Orca:**
Přidejte jako první řádek:
```gcode
KAMP EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
```

**Doporučeno:** Použijte [START_PRINT](Main.md#start_print) s `SAVE_ZMOD_DATA PRINT_LEVELING=1 USE_KAMP=1` a `SAVE_ZMOD_DATA CLEAR=LINE_PURGE` k využití oblastí pro čištění.

[Možnosti vyrovnávání stolu](FAQ.md#what-options-are-available-for-bed-leveling)

---
### AUTO_FULL_BED_LEVEL

Plné vyrovnání stolu s čištěním trysky.
Parametry:

- `EXTRUDER_TEMP` — teplota extruderu (výchozí: `230`)
- `BED_TEMP` — teplota stolu (výchozí: `80`)
- `PROFILE` — název profilu meshe (výchozí: `auto`)

**Použití v Orca:**
```gcode
AUTO_FULL_BED_LEVEL EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single]
M104 S[nozzle_temperature_initial_layer]
```

**Doporučeno:** Použijte [START_PRINT](Main.md#start_print) s `SAVE_ZMOD_DATA PRINT_LEVELING=1`.

[Možnosti vyrovnávání stolu](FAQ.md#what-options-are-available-for-bed-leveling)

---

### LOAD_ZOFFSET_NATIVE 

Zkopíruje z-offset z nativní obrazovky do režimu bez obrazovky

[Jak funguje Z-Offset na vaší tiskárně](SetupCalibrations.md#how-z-offset-works-on-your-printer)
