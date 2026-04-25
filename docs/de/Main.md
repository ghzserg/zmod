<h1 align="center">Hauptteil</h1>

Ein Makro ist ein kleines Programm in der Sprache Klipper/Gcode.

Es kann aufgerufen werden durch:

- Aus der GCODE-Datei
- Von der Fluidd/Mainsail-Konsole (drücken Sie den englischen Buchstaben "C" in Fluidd)

!!! info "Hinweis"
    *Der Wert in Klammern ist der Standardwert.

---

### START_PRINT

Ersetzt den standardmäßigen Start-G-Code.
**Für Drucker mit integriertem Bildschirm** fügen Sie `M140`/`M190 S[bed_temp]` und `M109`/`M104 S[nozzle_temp]` hinzu.

- `EXTRUDER_TEMP` - Extrudertemperatur (245)
- `BED_TEMP` - Heizbetttemperatur (80)
- `MESH` - Name des Bettnetzprofils (leer = kein Netz geladen/erstellt).
- `FORCE_LEVELING` - Bettnivellierung erzwingen (Standard: `False`)
- `SKIP_LEVELING` - Die Nivellierung des Bettes wird vollständig übersprungen (überschreibt `FORCE_KAMP`/`FORCE_LEVELING`, Standardwert: `False`).
- `FORCE_KAMP` - Erstelle ein adaptives Bettnetz (KAMP, Standard: `False`).
  *Es wird empfohlen, `SAVE_ZMOD_DATA CLEAR=LINE_PURGE` hinzuzufügen, um Bereinigungsbereiche für KAMP zu verwenden.*

- `Z_OFFSET` - Z-Offset einstellen (0.0)
- `INTERNAL` - Bei der PRO-Version im Betrieb ohne nativen Bildschirm: 1 - Interne Umluft aktivieren (0)
- `EXTERNAL` - Bei der PRO-Version im Betrieb ohne nativen Bildschirm: 1 - Externe Umluft aktivieren (0)

!!! info "Info"
    *Jeder Aufruf der Kalibrierung (`FORCE_KAMP` oder `FORCE_LEVELING`) löst [CLEAR_NOZZLE](/de/Main/#clear_nozzle) aus.*

    *`[ZSSH_RELOAD](/de/Zmod/#zssh_reload)` wird während `START_PRINT` aufgerufen, um SSH bei Bedarf wiederherzustellen.*

**Beispiel für Orca mit nativem Bildschirm.** Entferne den Startcode und füge den folgenden ein.
```
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single]
M104 S[Düsentemperatur_Einstiegsschicht]
```
**Beispiel für Orca im nicht-nativen Bildschirmmodus**
```
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
```

**Um die Schichten in Fluidd korrekt zu zählen**, schreiben Sie in den Startcode:
```
SET_PRINT_STATS_INFO TOTAL_LAYER=[total_layer_count]
```

**Und fügen Sie in den Layer Change Code ein:**
```
SET_PRINT_STATS_INFO CURRENT_LAYER={layer_num + 1}
```

[Bettnivellierung Optionen](/de/FAQ/#welche-optionen-stehen-für-die-bettnivellierung-zur-verfügung)

#### Dies sind keine START_PRINT-Parameter, sondern globale Flags/Parameter, die über [SAVE_ZMOD_DATA](/de/Global/#parameter-für-den-start-des-drucks-aufbau-der-tabellenkarte-start_print) gesetzt werden:

- [PRECLEAR](/de/Global/#preclear) - Verwendung der Düsenvorreinigung in [CLEAR_NOZZLE](/de/Main/#clear_nozzle) `0` = deaktivieren, `1` = aktivieren (Standard: `0`).
- [CLEAR](/de/Global/#clear) - Düsenreinigungsalgorithmus auswählen (LINE_PURGE)
- [PRINT_LEVELING](/de/Global/#print_leveling) - Bettnivellierung für jeden Druck aktivieren `0` = deaktivieren, `1` = aktivieren (Standard: `0`).
- USE_KAMP](/de/Global/#use_kamp) - Wenn es möglich ist, eine adaptive Tabellenkarte (KAMP) anstelle einer vollständigen Tabellenkarte zu verwenden `0` = deaktivieren, `1` = aktivieren (Standard: `0`)
- [DISABLE_PRIMING](/de/Global/#disable_priming) - Deaktiviert die Düsenreinigung `0` = deaktivieren, `1` = aktivieren (Standard: `0`)
- [FORCE_MD5](/de/Global/#force_md5) - MD5-Hashes der Datei überprüfen (Standard: `1`).

??? info "Download: Wählen Sie die passende Datei für Ihr System"

    1. Sie müssen eine Datei für Ihre Architektur und Ihr Betriebssystem auswählen und auf Ihren Computer herunterladen:
        * [zmod_preprocess-windows-amd64.exe](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-windows-amd64.exe) - **Windows**
        * [zmod_preprocess-linux-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-linux-amd64) - **Linux** Vergessen Sie nicht, `chmod +x                           zmod_preprocess-linux-amd64` auszuführen.
        * [zmod_preprocess-darwin-arm64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-arm64) - **macOS Intel** Vergessen Sie nicht, `chmod +x                  zmod_preprocess-darwin-arm64` auszuführen.
        * [zmod_preprocess-darwin-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-amd64) - **macOS Silicon** Vergessen Sie nicht, `chmod +x                zmod_preprocess-darwin-amd64` auszuführen.
        * [zmod-preprocess.py](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.py) - **Universal Python** Vergessen Sie nicht, `chmod +x zmod-preprocess.py`             auszuführen.
        * [zmod-preprocess.sh](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.sh) - **Linux/MacOS Bash** Vergessen Sie nicht, `chmod +x zmod-preprocess.sh`             auszuführen.
     
??? tip "2. Konfiguration in Orca"
    In Orca müssen Sie den Pfad zum Skript an folgender Stelle angeben:
    `Prozessprofil` :arrow_right: `Andere` :arrow_right: `Nachverarbeitungsskripte`.

    **Hier sind die Optionen, die Sie hinzufügen müssen (je nach System):**

    * **Windows (Executable):**
        ```text
        "C:\path_to_file\zmod_preprocess-windows-amd64.exe";
        ```

    * **Windows (Python Skript):**
        ```text
        "C:\python_ordner\python.exe" "C:\Scripts\zmod-preprocess.py";
        ```

    * **Linux/macOS (Python):**
        ```text
        "/usr/bin/python3" "/home/user/zmod-preprocess.py";
        ```

    * **Linux/macOS (Direkter Pfad):**
        ```text
        "/home/benutzer/zmod-preprocess.py";
        ```

    * **Binärdateien (Linux/macOS):**
        * `/home/benutzer/zmod_preprocess-darwin-amd64`;
        * `/home/benutzer/zmod_preprocess-darwin-arm64`;
        * `/home/benutzer/zmod_preprocess-linux-amd64`;

- [DISABLE_SKEW](/de/Global/#disable_skew) - 1 - SKEW-Korrektur deaktivieren, 0 - Profil `skew_profile` laden (Makro `SKEW_PROFILE LOAD=skew_profile` wird aufgerufen) (1)
- `AUTO_REBOOT` - automatischer Neustart nach dem Drucken: `0` = deaktivieren, `1` = aktivieren, `2` = Firmware-Neustart (Standard: `0`)
- `CLOSE_DIALOGS` - Automatisches Schließen von Dialogen: `0` = deaktivieren, `1` = langsam, `2` = schnell (erfordert die Aktivierung von "Nur lokales Netzwerk" auf dem Druckerbildschirm)
*Für ein schnelles Schließen der Dialoge muss man zu `Einstellungen` -> `WiFi-Symbol` -> `Netzwerkmodus` -> **den Schieberegler** `Nur lokale Netzwerke` aktivieren (0).*

- `STOP_MOTOR` - Automatisches Abschalten der Motoren nach dem Drucken/Abbrechen nach 25 Sekunden `0` = deaktivieren, `1` = aktivieren (Standard: `1`).
- `MIDI_START` - MIDI abspielen, wenn der Druck beginnt (z.B. "start.mid")
- `MIDI_END` - MIDI abspielen, wenn der Druck beendet ist ("")

---

#### Bettnivellierungslogik:

1. Falls angegeben, wird ein Netz aus `MESH` geladen.
2. Die Nivellierung wird übersprungen, wenn `SKIP_LEVELING = True`.
3. Falls `FORCE_KAMP = True`, wird ein KAMP-Netz erstellt.
4. Falls kein Netz geladen ist oder `FORCE_LEVELING = True`, wird ein vollständiges Netz erstellt.

---

### END_PRINT

Ersetzen des nativen End-G-Codes

#### Dies sind keine END_PRINT-Parameter, sondern globale Flags/Parameter, die über [SAVE_ZMOD_DATA](/de/Global/#druckende-und-abbruchoptionen-end_print) gesetzt werden.

- `AUTO_REBOOT` – Automatischer Neustart nach dem Drucken (wie oben).
- `CLOSE_DIALOGS` – Automatisches Schließen von Dialogen (wie oben).
- `STOP_MOTOR` – Motoren nach dem Drucken deaktivieren (wie oben).
- `MIDI_END` – MIDI-Datei, die nach dem Drucken abgespielt wird.

---

### _USER_START_PRINT

Benutzerdefiniertes Makro für benutzerdefinierte Aktionen zu Beginn des Druckvorgangs.

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
    # Zusätzlichen Lüfter aktivieren
    SET_PIN PIN=my_fan VALUE=1
    # Ein benutzerdefinierter Befehl
    G4 P1000  ; pause for 1 second
    # Andere benutzerdefinierte Aktionen
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
    # Zusätzlichen Lüfter deaktivieren
    SET_PIN PIN=my_fan VALUE=0
    # Benachrichtigung senden
    M118 Druckvorgang abgeschlossen!
    # Oder andere benutzerdefinierte Befehle
```

**Hinweis:** Standardmäßig ist das Makro leer und kann vom Benutzer nach seinen Bedürfnissen überschrieben werden.

---

### ABBRUCH

Drucken abbrechen

---

### CLEAR_NOZZLE

Düsenreinigung (wie in der Standard-Firmware).
Parameter:

- `EXTRUDER_TEMP` – Extrudertemperatur (Standard: `230`)

- `BED_TEMP` – Betttemperatur (Standard: `80`)

*`PRECLEAR` (einstellbar über `SAVE_ZMOD_DATA PRECLEAR=1`) aktiviert die Vorreinigung. [Mehr erfahren](/de/Global/#save_zmod_data).*

*Das Verfeinern des `CLEAR_NOZZLE`-Macros in `mod_data/user.cfg` wird die native Düsenbereinigung auf dem BED nicht verändern, wenn sie direkt vom nativen Bildschirm aufgerufen wird, da der native Bildschirm ohne Z-Mod funktioniert und daher keine Z-Mod-Makros verwendet*.

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

- `FILE` - Dateiname (Standard: `For_Elise.mid`) Dateien werden in mod_data/midi/ gespeichert

---

### REBOOT

Den Drucker neu starten

---

### CLOSE_DIALOGS

Bewirkt das langsame Schließen von Dialogen auf dem ursprünglichen Bildschirm. Wird verwendet, um das Fenster zu schließen, wenn der Druckvorgang beendet ist oder abgebrochen wird.

Kann zum Aufhängen des Druckers führen.

Implementierung: @darksimpson.

Auch gesteuert über [CLOSE_DIALOGS](/de/Global/#close_dialogs)

---

### FAST_CLOSE_DIALOGS

Bewirkt das schnelle Schließen von Dialogen auf dem ursprünglichen Bildschirm. Wird verwendet, um ein Fenster zu schließen, wenn der Druckvorgang beendet ist oder abgebrochen wird.

Läuft schneller und führt nicht zum Aufhängen des Druckers.

*Um Dialoge schnell zu schließen, gehen Sie über das Menü des Druckerbildschirms zu `Einstellungen` -> `WLAN-Symbol``-> `Netzwerkmodus` -> **Schalten Sie den Schieberegler** `Nur lokale Netzwerke` ein.

Wird auch über den [CLOSE_DIALOGS](/de/Global/#close_dialogs) gesteuert.

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
