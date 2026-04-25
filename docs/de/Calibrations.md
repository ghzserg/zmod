<h1 align="center">Kalibrierungen</h1>

Ein Makro ist ein kleines Programm in der Klipper/Gcode-Sprache.

Es kann aufgerufen werden durch:

- Aus der GCODE-Datei
- Von der Fluidd/Mainsail-Konsole (drücken Sie den englischen Buchstaben "C" in Fluidd)

!!! info "Hinweis"
    *Der Wert in Klammern ist der Standardwert.

---

!!! Tipp
    [Druckerkalibrierung für Anfänger](/de/SetupCalibrations/#drucker-kalibrierung-für-einsteiger)

---

### BED_LEVEL_SCREWS_TUNE

Bettnivellierungsschrauben ([manuell](https://www.klipper3d.org/Manual_Level.html#adjusting-bed-leveling-screws-using-the-bed-probe))

- `EXTRUDER_TEMP` - Extrudertemperatur `(Standard: 240)`
- `BED_TEMP` - Tischtemperatur `(Standard: 80)`

Das Gerät misst den Abstand zwischen Düse und Bettschrauben, gibt Einstellhinweise, speichert die Temperaturen, um ein erneutes Aufheizen zu vermeiden, und wartet auf die Bestätigung des Benutzers. Nach Abschluss des Vorgangs müssen die Temperaturen manuell zurückgesetzt werden.

---

### LOAD_CELL_TARE

Gewicht der Wägezellen zurücksetzen. Wird während der Bettkalibrierung aufgerufen

---

### PID_TUNE_BED

Kalibrierung der Tabelle PID

- `TEMPERATUR` — BED Temperatur (default: `80`)

Nach der Kalibrierung wird `SAVE_CONFIG` aufgerufen, siehe auch [NEW_SAVE_CONFIG](/de/Main/#new_save_config)

Wenn Sie das automatische Speichern nicht nutzen wollen, verwenden Sie:
```
PID_CALIBRATE HEATER=heater_bed TARGET={Temperatur}
```

---

### PID_TUNE_EXTRUDER

Kalibrierung der Extruder-PID

- `TEMPERATUR` – Extrudertemperatur (Standard: `245`)
- `KÜHLER` – Lüfterdrehzahl (0–100, Standard: `100`)

Kalibrieren Sie den PID auf die Temperatur, bei der Sie drucken, und auf die Gebläsestufe, die Sie verwenden.

Nach der Kalibrierung `SAVE_CONFIG` aufrufen, siehe auch [NEW_SAVE_CONFIG](/de/Main/#new_save_config)

Wenn Sie das automatische Speichern nicht nutzen wollen, verwenden Sie:
```
PID_CALIBRATE HEATER=extruder TARGET={Temperatur}
```

---

### ZSHAPER

Kalibrierung des Input Shaper(Ressonanzmessung).

Die Ergebnisse werden gespeichert in `Maschine` -> `mod_data`:

- `calibration_data_x.png`
- `calibration_data_y.png`
- CSV-Dateien

Lesen Sie über [fix_scv](/de/Global/#fix_scv)

[Graphische Software](https://github.com/theycallmek/Klipper-Input-Shaping-Assistant/releases)

---

### BELTS_SHAPER_CALIBRATION

Führt einen speziellen Halbachsentest durch, um die Frequenzprofile der einzelnen Bänder auf CoreXY-Druckern zu analysieren und zu vergleichen

- `SPEKTROGRAMM` — `0` = Spektrogramm deaktivieren, `1` = aktivieren (Standard: `1`)

**Anforderungen:**

- 256 MB RAM
- Swap aktiviert

---

### KAMP

Adaptive Bettnetzkalibrierung mit Düsenreinigung.
Parameter:

- `EXTRUDER_TEMP` – Extrudertemperatur (Standard: `240`)
- `BED_TEMP` – Betttemperatur (Standard: `80`)

Fügen Sie die erste Zeile in Orca hinzu
```
KAMP EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
```

**Empfohlen:** Verwenden Sie [START_PRINT](/de/Main/#start_print) mit `SAVE_ZMOD_DATA PRINT_LEVELING=1 USE_KAMP=1` und `SAVE_ZMOD_DATA CLEAR=LINE_PURGE`, um die Spülbereiche zu nutzen.

[Optionen zur Bettnivellierung](/de/FAQ/#welche-optionen-stehen-für-die-bettnivellierung-zur-verfügung)

---

### AUTO_FULL_BED_LEVEL

Vollständige Bettnivellierung mit Düsenreinigung.
Parameter:

- `EXTRUDER_TEMP` – Extrudertemperatur (Standard: `230`)
- `BED_TEMP` – Betttemperatur (Standard: `80`)
- `PROFILE` – Name des Netzprofils (Standard: `auto`)

Fügen Sie die erste Zeile in Orca ein
```
AUTO_FULL_BED_LEVEL EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single]
M104 S[nozzle_temperature_initial_layer]
```

**Empfohlen:** Verwenden Sie [START_PRINT](/de/Main/#start_print) mit `SAVE_ZMOD_DATA PRINT_LEVELING=1`.

[Optionen zur Bettnivellierung](/de/FAQ/#welche-optionen-stehen-für-die-bettnivellierung-zur-verfügung)

---

### LOAD_ZOFFSET_NATIVE

Übertragen der Z-Offset-Einstellungen vom nativen Bildschirm in den No-Screen-Modus

[Wie funktioniert Z-Offset auf Ihrem Drucker](/de/SetupCalibrations/#wie-funktioniert-z-offset-auf-ihrem-drucker)
