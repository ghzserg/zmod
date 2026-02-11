<h1 align="center">Kalibrierungen</h1>

Ein Makro ist ein kleines Programm in der Klipper/Gcode-Sprache.

Es kann aufgerufen werden durch:

- Aus der GCODE-Datei
- Von der Fluidd/Mainsail-Konsole (drücken Sie den englischen Buchstaben "C" in Fluidd)

!!! Hinweis
    *Der Wert in Klammern ist der Standardwert.

---

!!! Tipp
    [Druckerkalibrierung für Anfänger](/de/SetupCalibrations/#Drucker-Kalibrierung-fuer-Anfänger)

---

### BED_LEVEL_SCREWS_TUNE

Tischschrauben kalibrieren ([manuell](https://www.klipper3d.org/Manual_Level.html#adjusting-bed-leveling-screws-using-the-bed-probe))

- EXTRUDER_TEMP - Extrudertemperatur (240)
- BED_TEMP - Tischtemperatur (80)

Misst den Abstand zwischen der Düse und den Schrauben und gibt Hinweise zum Anziehen der Schrauben. Dann speichert es die Temperaturen, damit es nicht erneut aufheizen muss, wartet darauf, dass der Benutzer die Schnecken einstellt und drückt erneut die Kalibriertaste. Wenn die Kalibrierung beendet ist, muss der Benutzer die Temperatur selbst zurücksetzen.

---

### LOAD_CELL_TARE

Gewicht der Wägezellen zurücksetzen. Wird während der Tabellenkalibrierung aufgerufen

---

### PID_TUNE_BED

Kalibrierung der Tabelle PID

- TEMPERATURE - Temperatur der Tabelle (80)

Nach der Kalibrierung wird `SAVE_CONFIG` aufgerufen, siehe auch [NEW_SAVE_CONFIG](/de/Main/#new_save_config)

Wenn Sie das automatische Speichern nicht nutzen wollen, verwenden Sie:
```
PID_CALIBRATE HEATER=heater_bed TARGET={Temperatur}
```

---

### PID_TUNE_EXTRUDER

Kalibrierung der Extruder-PID

- TEMPERATURE - Temperatur des Extruders (245)
- COOLER - Lüftergeschwindigkeit 0-100 (100)

Kalibrieren Sie den PID auf die Temperatur, bei der Sie drucken, und auf die Gebläsestufe, die Sie verwenden.

Nach der Kalibrierung `SAVE_CONFIG` aufrufen, siehe auch [NEW_SAVE_CONFIG](/de/Main/#new_save_config)

Wenn Sie das automatische Speichern nicht nutzen wollen, verwenden Sie:
```
PID_CALIBRATE HEATER=extruder TARGET={Temperatur}
```

---

### ZSHAPER

Shaper Kalibrierung.

Shaper-Bilder befinden sich auf der Registerkarte "Konfiguration" -> mod_data

- kalibrierung_data_x.png
- kalibrierung_daten_y.png

Die Csv-Dateien befinden sich ebenfalls dort.

Lesen Sie über [fix_scv](/de/Global/#fix_scv)

[Graphische Software](https://github.com/theycallmek/Klipper-Input-Shaping-Assistant/releases)

---

### BELTS_SHAPER_CALIBRATION

Führt einen speziellen Halbachsentest durch, um die Frequenzprofile der einzelnen Bänder auf CoreXY-Druckern zu analysieren und zu vergleichen

SPECTROGRAM - 0 - kein Spektrogramm erstellen, 1 - Spektrogramm erstellen (1)

Erfordert 256 Megabyte RAM und SWAP aktiviert

---

### KAMP

Adaptive Tischkalibrierung mit Düsenreinigung

- EXTRUDER_TEMP - Extrudertemperatur (240)
- BED_TEMP - Tischtemperatur (80)

Fügen Sie die erste Zeile in Orca hinzu
```
KAMP EXTRUDER_TEMP=[Düsentemperatur_Anfangsschicht] BED_TEMP=[Betttemperatur_Anfangsschicht_Einzel]
```

Aber es ist besser, [START_PRINT](/de/Main/#start_print) und [SAVE_ZMOD_DATA](/de/Global/#start_print) zu verwenden PRINT_LEVELING=1 USE_KAMP=1

Es wird auch empfohlen, `SAVE_ZMOD_DATA CLEAR=LINE_PURGE` zu setzen, was es Ihnen ermöglicht, den Aufräumraum zu nutzen, in dem die Tabellenkarte entfernt wird.

[Was sind die Optionen zum Entfernen der Tabellenkarte?](/de/FAQ/#what-are-the-options-for-removing-the-table-card)

---

### AUTO_FULL_BED_LEVEL

Tabellenkalibrierung mit Düsenreinigung

- EXTRUDER_TEMP - Extruder-Temperatur (230)
- BED_TEMP - Tischtemperatur (80)
- PROFILE - für welches Profil (auto)

Fügen Sie die erste Zeile in Orca ein
```
AUTO_FULL_BED_LEVEL EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single]
M104 S[Düsentemperatur_Einstiegsschicht]
```

Es ist jedoch besser, [START_PRINT](/de/Main/#start_print) und [SAVE_ZMOD_DATA](/de/Goabal/#start_print) zu verwenden PRINT_LEVELING=1

[Was sind die Optionen zum Entfernen einer Tabellenkarte?](/de/FAQ/#what-are-the-options-for-removing-a-table-card)

---

### LOAD_ZOFFSET_NATIVE

Übertragen der Z-Offset-Einstellungen vom nativen Bildschirm in den No-Screen-Modus

[Wie Z-Offset auf Ihrem Drucker funktioniert](/de/SetupCalibrations/#wie-z-offset-auf-ihrem-drucker-arbeitet)
