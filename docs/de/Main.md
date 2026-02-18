<h1 align="center">Hauptteil</h1>

Ein Makro ist ein kleines Programm in der Sprache Klipper/Gcode.

Es kann aufgerufen werden durch:

- Aus der GCODE-Datei
- Von der Fluidd/Mainsail-Konsole (drücken Sie den englischen Buchstaben "C" in Fluidd)

!!! Hinweis
    *Der Wert in Klammern ist der Standardwert.

---

### START_PRINT

Ersetzen des nativen anfänglichen g-Codes (wenn mit einem Bildschirm verwendet, fügen Sie M140 oder M190 Table_temperature und M109 oder M104 Extruder_temperature hinzu).

- EXTRUDER_TEMP - Extrudertemperatur (245)
- BED_TEMP - Temperatur des Tisches (80)
- MESH - Name der zu ladenden Tabellenkarte, wenn nicht angegeben, wird nichts geladen, wenn sie nicht existiert, wird sie erstellt ("").
- FORCE_LEVELING - zwingt zur Erstellung einer Tabellenkarte (False)
- SKIP_LEVELING - baut unter keiner Bedingung eine Tabellenkarte auf. Stärker als FORCE_KAMP und FORCE_LEVELING (False)
- FORCE_KAMP - Beginnt mit dem Aufbau einer adaptiven Tabellenabbildung (False) *Es wird empfohlen, auch `SAVE_ZMOD_DATA CLEAR=LINE_PURGE` zu setzen, was es Ihnen ermöglicht, den Bereinigungsbereich zu nutzen, in dem die Tabellenabbildung entfernt wird.
- Z_OFFSET - Z-Offset einstellen (0.0)
- INTERNAL - Für die PRO-Version beim Arbeiten im nicht-nativen Bildschirmmodus, 1 - Aktivierung der internen Rückführung (0)
- EXTERNAL - Für die PRO-Version im nicht-nativen Bildschirmmodus, 1 - Aktivierung der externen Rückführung (0).

*Jeder Aufruf der Kalibrierung FORCE_KAMP oder FORCE_LEVELING verursacht [CLEAR_NOZZLE](/de/Main/#CLEAR_NOZZLE)*

*Während des Starts von START_PRINT wird [ZSSH_RELOAD](/de/Zmod/#zssh_reload) aufgerufen, was die SSH-Verbindung wiederherstellt, falls erforderlich*

Beispiel für Orca mit nativem Bildschirm. Entferne den Startcode und füge den folgenden ein.
```
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single]
M104 S[Düsentemperatur_Einstiegsschicht]
```
Beispiel für Orca im nicht-nativen Bildschirmmodus
```
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
```

Um die Schichten in Fluidd korrekt zu zählen, schreiben Sie in den Startcode:
```
SET_PRINT_STATS_INFO TOTAL_LAYER=[total_layer_count]
```

Und fügen Sie in den Layer Change Code ein:
```
SET_PRINT_STATS_INFO CURRENT_LAYER={schicht_zahl + 1}
```

[Was sind die Optionen zum Entfernen einer Tabellenkarte?](/de/FAQ/#what-are-the-options-for-removing-a-table-card)

# Stachelschwein #

#### Dies sind keine START_PRINT-Parameter, sondern globale Flags/Parameter, die über [SAVE_ZMOD_DATA](/de/Global/#start_print) gesetzt werden:

- [PRECLEAR](/de/Global/#preclear) - Verwendung der Düsenvorreinigung in [CLEAR_NOZZLE](/de/Main/#CLEAR_NOZZLE) 0-nein, 1-ja (0).
- [CLEAR](/de/Global/#clear) - Düsenreinigungsalgorithmus auswählen (LINE_PURGE)
- PRINT_LEVELING](/de/Global/#print_leveling) - Tabellenabbildung bei jedem Druck 0-Nein, 1-Ja (0).
- USE_KAMP](/de/Global/#use_kamp) - Wenn es möglich ist, eine adaptive Tabellenkarte (KAMP) anstelle einer vollständigen Tabellenkarte zu verwenden 0-nein, 1-ja (0)
- DISABLE_PRIMING](/de/Global/#disable_priming) - Deaktiviert die Düsenreinigung durch Extrusion 0-nein, 1-ja (0)
- FORCE_MD5](/de/Global/#force_md5) - wenn 1 (Standard ist 1) - MD5-Summe der Datei prüfen, bei Fehler - Datei löschen.
    1. Sie müssen eine Datei für Ihre Architektur und Ihr Betriebssystem auswählen und auf Ihren Computer herunterladen:

    - [zmod_preprocess-windows-amd64.exe](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-windows-amd64.exe) - Windows
    - [zmod_preprocess-linux-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-linux-amd64) - Linux. Vergessen Sie nicht, ```chmod +x zmod_preprocess-linux-amd64`'' auszuführen.
    - [zmod_preprocess-darwin-arm64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-arm64) - macOS Intel. Vergessen Sie nicht, ```chmod +x zmod_preprocess-darwin-arm64``` auszuführen
    - [zmod_preprocess-darwin-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-amd64) - macOS Silicon. Vergessen Sie nicht, ```chmod +x zmod_preprocess-darwin-amd64``` auszuführen
    - [zmod-preprocess.py](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.py) - Universal Python. Vergessen Sie nicht, ```chmod +x zmod-preprocess.py``` auszuführen.
    - [zmod-preprocess.sh](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.sh) - Linux/MacOS Bash. Vergessen Sie nicht, ```chmod +x zmod-preprocess.sh``` auszuführen.

    2. In Orca muessen Sie schreiben. ```Prozessprofil``` -> ```Andere``` -> ```Nachverarbeitungsskripte```.

    Hier sind die Optionen, die Sie hinzufügen müssen:

    - ```"C:\path_to_file\zmod_preprocess-windows-amd64.exe";```
    - ```"C:\python_ordner\python.exe" "C:\Scripts\zmod-preprocess.py";```
    - ````"/usr/bin/python3" "/home/user/zmod-preprocess.py";````
    - ```"/home/benutzer/zmod-preprocess.py";````
    - ````"/home/benutzer/zmod_preprocess-darwin-amd64";````
    - ````"/home/benutzer/zmod_preprocess-darwin-arm64";````
    - ````"/home/benutzer/zmod_preprocess-linux-amd64";````

- DISABLE_SKEW](/de/Global/#disable_skew) - 1 - SKEW-Korrektur deaktivieren, 0 - Profil `skew_profile` laden (Makro `SKEW_PROFILE LOAD=skew_profile` wird aufgerufen) (1)
- AUTO_REBOOT - automatischer Neustart des Druckers nach Beendigung des Druckvorgangs 0-nein, 1-ja, 2-FIRMWARE_RESTART (nur im Modus ohne eigenen Bildschirm, mit REBOOT-Bildschirm) (0).
- CLOSE_DIALOGS - schließt Dialoge automatisch, wenn der Druckvorgang beendet und abgebrochen wird 0-nein, 1-ja langsam, 2-ja schnell *Für ein schnelles Schließen der Dialoge muss man zu "Einstellungen" -> "WiFi-Symbol" -> "Netzwerkmodus" -> **den Schieberegler** "Nur lokale Netzwerke "* aktivieren (0).
- STOP_MOTOR - Automatisches Abschalten der Motoren nach dem Drucken/Abbrechen nach 25 Sekunden 0-nein, 1-ja (1).
- MIDI_START - MIDI abspielen, wenn der Druck beginnt ("")
- MIDI_END - MIDI abspielen, wenn der Druck beendet ist ("")

#### Algorithmus zum Einziehen der Karte:

- Wenn MESH nicht leer ist, wird die Karte mit dem Namen, der im Parameter MESH angegeben ist, geladen
- Wenn SKIP_LEVELING = True - wird die Tischkarte unter keinen Umständen entnommen
- Andernfalls,
- Wenn FORCE_CAMP = True, dann wird KAMP entfernt.
- Andernfalls
- Wenn die Tabellenkarte nicht geladen ist (der native Kopf lädt immer die MESH_DATA-Karte) oder wenn FORCE_LEVELING = True ist, dann wird der Aufbau der Tabellenkarte gestartet.
- Der Aufbau der Table Map wird gestartet, aber nicht gespeichert.

---

### END_PRINT

Ersetzen des nativen End-G-Codes

#### Dies sind keine END_PRINT-Parameter, sondern globale Flags/Parameter, die über [SAVE_ZMOD_DATA](/de/Global/#end_print) gesetzt werden.

- AUTO_REBOOT - automatischer Neustart des Druckers nach Beendigung des Druckvorgangs 0-nein, 1-ja,2-FIRMWARE_RESTART(nur im Modus ohne eigenen Bildschirm, mit REBOOT-Bildschirm) (0).
- CLOSE_DIALOGS - schließt automatisch die Dialoge, wenn der Druckvorgang beendet und abgebrochen wird 0-nein, 1-ja langsam, 2-ja schnell *Für ein schnelles Schließen der Dialoge muss man zu "Einstellungen" -> "WiFi-Symbol" -> "Netzwerkmodus" -> **den Schieberegler** "Nur lokale Netzwerke "* aktivieren (0).
- STOP_MOTOR - Automatisches Abschalten der Motoren nach dem Druck/Abbruch nach 25 Sekunden 0-nein, 1-ja (1)
- MIDI_END - MIDI abspielen, wenn der Druckvorgang abgeschlossen ist ("")

---

### _USER_START_PRINT

Benutzermakro zum Hinzufügen eigener Aktionen zu Beginn des Druckvorgangs.

Dieses Makro wird automatisch am Ende des Makros `START_PRINT` aufgerufen. Wird verwendet, um den Standard-Druckinitialisierungsprozess mit eigenen Befehlen zu erweitern.

**Wo zu verwenden:**

- Fügen Sie Ihre eigenen Heiz- oder Kalibrierungsbefehle hinzu
- Vornahme zusätzlicher Einstellungen vor Druckbeginn
- Aktivieren/Deaktivieren von Geräten (Lüfter, Sensoren usw.)
- Hinzufügen von benutzerdefinierten Düsenreinigungen oder anderen vorbereitenden Operationen

**Beispiel für die Überschreibung in `mod_data/user.cfg`:**
```gcode
[gcode_macro _USER_START_PRINT].
gcode:
    # Aktiviere den optionalen Lüfter
    SET_PIN PIN=mein_lüfter WERT=1
    # Irgendein Befehl von dir
    G4 P1000 ; Pause 1 Sekunde
    # Irgendeine andere Aktion
```

**Anmerkung:** Das Makro ist standardmäßig leer und kann vom Benutzer nach seinen Bedürfnissen überschrieben werden.

---

### _USER_END_PRINT

Benutzermakro zum Hinzufügen eigener Aktionen am Ende des Druckvorgangs.

Dieses Makro wird automatisch am Ende des Makros `END_PRINT` aufgerufen. Wird verwendet, um den Standarddruckvorgang mit eigenen Befehlen zu erweitern.

**Wo zu verwenden:**

- Ausführen zusätzlicher Aktionen am Ende des Druckvorgangs
- Zusätzliche Geräte ausschalten
- Speichern von Statistiken oder Protokollen
- Benutzerdefinierte Reinigung oder Wartung des Druckers durchführen

**Beispiel für eine Überschreibung in `mod_data/user.cfg`:**
```gcode
[gcode_macro _USER_END_PRINT].
gcode:
    # Schalte den optionalen Lüfter aus
    SET_PIN PIN=mein_lüfter VALUE=0
    # Benachrichtigung senden
    M118 Druck abgeschlossen!
    # Oder einer deiner anderen Befehle
```

**Hinweis:** Standardmäßig ist das Makro leer und kann vom Benutzer nach seinen Bedürfnissen überschrieben werden.

---

### ABBRUCH

Drucken abbrechen

---

### CLEAR_NOZZLE

Löschen der Düse auf dem Tisch wie in nativer Firmware

- EXTRUDER_TEMP - Extrudertemperatur (230)
- BED_TEMP - Tischtemperatur (80)

*PRECLEAR - Düsenvorreinigung in CLEAR_NOZZLE verwenden 0-nein, 1-ja (0).
Dies ist kein CLEAR_NOZZLE-Parameter, es ist ein globales Flag, das über `SAVE_ZMOD_DATA PRECLEAR=1` gesetzt wird. Lesen Sie mehr [hier](/de/Global/#preclear)*

*Das Verfeinern des `CLEAR_NOZZLE`-Makros in `mod_data/user.cfg` wird die native Düsenbereinigung auf der Tabelle nicht verändern, wenn sie direkt vom nativen Bildschirm aufgerufen wird, da der native Bildschirm ohne zMod funktioniert und daher keine zMod-Makros verwendet*.

---

### LED_ON

Schaltet die Hintergrundbeleuchtung ein

---

### LED_OFF

Hintergrundbeleuchtung ausschalten

---

### LED

Einschalten der Hintergrundbeleuchtung um ein paar Prozent

- S - Prozent (50)

---

### PAUSE

Druck unterbrechen

---

### FORTSETZEN

Wiederaufnahme des Drucks nach einer Unterbrechung

---

### PLAY_MIDI

MIDI-Datei abspielen

- FILE - Dateiname (For_Elise.mid) Dateien werden in mod_data/midi/ gespeichert

---

### REBOOT

Den Drucker neu starten

---

### CLOSE_DIALOGS

Bewirkt das langsame Schließen von Dialogen auf dem ursprünglichen Bildschirm. Wird verwendet, um das Fenster zu schließen, wenn der Druckvorgang beendet ist oder abgebrochen wird.

Kann zum Aufhängen des Druckers führen.

Implementierung: @darksimpson.

Auch gesteuert über [globalen Parameter CLOSE_DIALOGS](/de/Global/#close_dialogs)

---

### FAST_CLOSE_DIALOGS

Bewirkt das schnelle Schließen von Dialogen auf dem ursprünglichen Bildschirm. Wird verwendet, um ein Fenster zu schließen, wenn der Druckvorgang beendet ist oder abgebrochen wird.

Läuft schneller und führt nicht zum Aufhängen des Druckers.

*Um Dialoge schnell zu schließen, gehen Sie über das Menü des Druckerbildschirms zu "Einstellungen" -> "WLAN-Symbol" -> "Netzwerkmodus" -> **Schalten Sie den Schieberegler** "Nur lokale Netzwerke" ein.

Wird auch über den [globalen Parameter CLOSE_DIALOGS](/de/Global/#close_dialogs) gesteuert.

Implementierung: @darksimpson.

---

### NEW_SAVE_CONFIG

Ruft `SAVE_CONFIG` vom nativen Bildschirm aus auf. Kann verwendet werden, um den Clipper neu zu starten, ohne den nativen Bildschirm aufzuhängen.

Implementierung: @darksimpson.

Funktioniert für etwa eine Minute.

Kann manchmal dazu führen, dass der native Bildschirm nicht richtig funktioniert

---

### SHUTDOWN

Den Drucker ausschalten
