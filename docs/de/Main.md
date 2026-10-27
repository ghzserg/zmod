<h1 align="center">Hauptteil</h1>

Ein Makro ist ein kleines Programm in der Sprache Klipper/Gcode.

Es kann aufgerufen werden:

- aus der G-Code-Datei
- über die Fluidd/Mainsail-Konsole (drücken Sie in Fluidd die lateinische Taste „C“)

!!! info "Hinweis"
    *Der Wert in Klammern ist der Standardwert.

---

### START_PRINT

Ersetzt den standardmäßigen Start-G-Code.
**Für Drucker mit integriertem Bildschirm** fügen Sie `M140`/`M190 S[bed_temp]` und `M109`/`M104 S[nozzle_temp]` hinzu.

- `EXTRUDER_TEMP` - Extrudertemperatur (245)
- `BED_TEMP` - Heizbetttemperatur (80)
- `MESH` - Name des zu ladenden Bettnetzprofils (leer = kein Netz wird geladen; existiert das Profil nicht, wird es erstellt).
- `FORCE_LEVELING` - Bettnivellierung erzwingen (Standard: `False`)
- `SKIP_LEVELING` - Die Nivellierung des Bettes wird vollständig übersprungen (überschreibt `FORCE_KAMP`/`FORCE_LEVELING`, Standardwert: `False`).
- `FORCE_KAMP` - Adaptives Bettnetz erstellen (KAMP, Standard: `False`).
  *Es wird empfohlen, `SAVE_ZMOD_DATA CLEAR=LINE_PURGE` hinzuzufügen, damit die Reinigung im KAMP-Bereich erfolgt.*

- `Z_OFFSET` - Z-Offset einstellen (0.0)
- `INTERNAL` - Bei der PRO-Version im Betrieb ohne nativen Bildschirm: 1 - interne Luftumwälzung aktivieren (0)
- `EXTERNAL` - Bei der PRO-Version im Betrieb ohne nativen Bildschirm: 1 - externe Luftzirkulation aktivieren (0)

!!! info "Info"
    *Jeder Aufruf der Kalibrierung (`FORCE_KAMP` oder `FORCE_LEVELING`) löst [CLEAR_NOZZLE](/de/Main/#clear_nozzle) aus.*

    *[`ZSSH_RELOAD`](/de/Zmod/#zssh_reload) wird während `START_PRINT` aufgerufen, um SSH bei Bedarf wiederherzustellen.*

**Beispiel für Orca mit nativem Bildschirm.** Löschen Sie den Startcode und fügen Sie Folgendes ein:
```
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
{single_extruder_multi_material ? "; T0" : "T" + initial_extruder}
M190 S[bed_temperature_initial_layer_single]
M104 S[nozzle_temperature_initial_layer] T{single_extruder_multi_material ? 0 : initial_extruder} T{single_extruder_multi_material ? 0 : initial_extruder}
```
**Beispiel für Orca im Modus ohne nativen Bildschirm:**
```
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
{single_extruder_multi_material ? "; T0" : "T" + initial_extruder}
```

**Um die Schichten in Fluidd korrekt zu zählen**, schreiben Sie in den Startcode:
```
SET_PRINT_STATS_INFO TOTAL_LAYER=[total_layer_count]
```

**Und fügen Sie in den G-Code für den Schichtwechsel ein:**
```
SET_PRINT_STATS_INFO CURRENT_LAYER={layer_num + 1}
```

[Optionen der Bettnivellierung](/de/FAQ/#welche-optionen-stehen-für-die-bettnivellierung-zur-verfügung)

#### Dies sind keine START_PRINT-Parameter, sondern globale Flags/Parameter, die über [SAVE_ZMOD_DATA](/de/Global/#parameter-für-den-start-des-druckvorgangs-und-die-erstellung-einer-bettkarte-start_print) gesetzt werden:

- [PRECLEAR](/de/Global/#preclear) - Düsenvorreinigung in [CLEAR_NOZZLE] verwenden(/de/Main/#clear_nozzle) `0` = deaktivieren, `1` = aktivieren (Standard: `0`).
- [CLEAR](/de/Global/#clear) - Düsenreinigungsalgorithmus auswählen (LINE_PURGE)
- [PRINT_LEVELING](/de/Global/#print_leveling) - Bettnetz bei jedem Druck messen `0` = deaktivieren, `1` = aktivieren (Standard: `0`).
- [USE_KAMP](/de/Global/#use_kamp) - Wo möglich, ein adaptives Bettnetz (KAMP) anstelle des vollständigen Bettnetzes verwenden `0` = deaktivieren, `1` = aktivieren (Standard: `0`)
- [DISABLE_PRIMING](/de/Global/#disable_priming) - Deaktiviert das Vorextrudieren (Priming) der Düse `0` = deaktivieren, `1` = aktivieren (Standard: `0`)
- [FORCE_MD5](/de/Global/#force_md5) - MD5-Hashes der Datei überprüfen und die Datei bei Fehler löschen (Standard: `1`).
    > Hinweis: Nur beim Senden von G-Code. Für 3MF nicht erforderlich.


??? info "Download: Wählen Sie die passende Datei für Ihr System"

    1. Sie müssen eine Datei für Ihre Architektur und Ihr Betriebssystem auswählen und auf Ihren Computer herunterladen:
        * [zmod_preprocess-windows-amd64.exe](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-windows-amd64.exe) - **Windows**
        * [zmod_preprocess-linux-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-linux-amd64) - **Linux** Vergessen Sie nicht, `chmod +x zmod_preprocess-linux-amd64` auszuführen.
        * [zmod_preprocess-darwin-arm64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-arm64) - **macOS Apple Silicon** Vergessen Sie nicht, `chmod +x zmod_preprocess-darwin-arm64` auszuführen.
        * [zmod_preprocess-darwin-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-amd64) - **macOS Intel** Vergessen Sie nicht, `chmod +x zmod_preprocess-darwin-amd64` auszuführen.
        * [zmod-preprocess.py](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.py) - **Universal Python** Vergessen Sie nicht, `chmod +x zmod-preprocess.py` auszuführen.
        * [zmod-preprocess.sh](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.sh) - **Linux/macOS Bash** Vergessen Sie nicht, `chmod +x zmod-preprocess.sh` auszuführen.
     
??? tip "2. Konfiguration in Orca"
    In Orca müssen Sie den Pfad zum Skript an folgender Stelle angeben:
    `Prozessprofil` :arrow_right: `Sonstiges` :arrow_right: `Nachbearbeitungsskripte`.

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
- `AUTO_REBOOT` - automatischer Neustart nach dem Drucken: `0` = deaktivieren, `1` = aktivieren, `2` = `FIRMWARE_RESTART` (nur im Modus ohne nativen Bildschirm; mit nativem Bildschirm — `REBOOT`) (Standard: `0`)
- `CLOSE_DIALOGS` - Automatisches Schließen von Dialogen: `0` = deaktivieren, `1` = langsam, `2` = schnell (erfordert die Aktivierung von "Nur lokales Netzwerk" auf dem Druckerbildschirm)
*Für ein schnelles Schließen der Dialoge gehen Sie zu `Einstellungen` -> `WLAN-Symbol` -> `Netzwerkmodus` und aktivieren **den Schieberegler** `Nur lokale Netzwerke` (0).*

- `STOP_MOTOR` - Automatisches Abschalten der Motoren nach dem Drucken/Abbrechen nach 25 Sekunden `0` = deaktivieren, `1` = aktivieren (Standard: `1`).
- `MIDI_START` - MIDI abspielen, wenn der Druck beginnt (z. B. "start.mid")
- `MIDI_END` - MIDI abspielen, wenn der Druck beendet ist ("")

---

#### Bettnivellierungslogik:

1. Falls angegeben, wird ein Netz aus `MESH` geladen.
2. Die Nivellierung wird übersprungen, wenn `SKIP_LEVELING = True`.
3. Falls `FORCE_KAMP = True`, wird ein KAMP-Netz erstellt.
4. Andernfalls wird ein vollständiges Netz erstellt, falls kein Netz geladen ist (der native Bildschirm lädt immer `MESH_DATA`) oder `FORCE_LEVELING = True`. Das Netz selbst wird nicht gespeichert.

---

### END_PRINT

Ersatz für den nativen End-G-Code

#### Dies sind keine END_PRINT-Parameter, sondern globale Flags/Parameter, die über [SAVE_ZMOD_DATA](/de/Global/#parameter-für-druckende-und-abbruch-end_print) gesetzt werden:

- `AUTO_REBOOT` – Automatischer Neustart nach dem Drucken (wie oben).
- `CLOSE_DIALOGS` – Automatisches Schließen von Dialogen (wie oben).
- `STOP_MOTOR` – Motoren nach dem Drucken deaktivieren (wie oben).
- `MIDI_END` – MIDI-Datei, die nach dem Drucken abgespielt wird.

---

### _USER_PREPARE_PRINT

Benutzerdefiniertes Makro, das aufgerufen wird, bevor die Datei zum Drucken gesendet wird.

Ermöglicht es, eigene Makros und Befehle einzufügen, bevor der Druck der Datei beginnt, also noch vor der Ausführung von `START_PRINT`.

**Beispiel für das Überschreiben in `mod_data/user.cfg`:**
```gcode
[gcode_macro _USER_PREPARE_PRINT]
gcode:
    # Ihre Makros und Befehle
    RESPOND MSG="Druck wird vorbereitet"
```

**Hinweis:** Standardmäßig ist das Makro leer und kann vom Benutzer nach Bedarf überschrieben werden.

---

### _USER_START_PRINT

Benutzermakro für eigene Aktionen zu Beginn des Druckvorgangs.

Dieses Makro wird automatisch am Ende des Makros `START_PRINT` aufgerufen. Damit können Sie die Standard-Druckvorbereitung um eigene Befehle erweitern.

**Einsatzbeispiele:**

- Eigene Heiz- oder Kalibrierungsbefehle hinzufügen
- Zusätzliche Einstellungen vor Druckbeginn vornehmen
- Geräte ein-/ausschalten (Lüfter, Sensoren usw.)
- Eigene Düsenreinigung oder andere Vorbereitungen hinzufügen

**Beispiel für das Überschreiben in `mod_data/user.cfg`:**
```gcode
[gcode_macro _USER_START_PRINT].
gcode:
    # Zusätzlichen Lüfter aktivieren
    SET_PIN PIN=my_fan VALUE=1
    # Ein benutzerdefinierter Befehl
    G4 P1000  ; pause for 1 second
    # Andere benutzerdefinierte Aktionen
```

**Hinweis:** Standardmäßig ist das Makro leer und kann vom Benutzer nach Bedarf überschrieben werden.

---

### _USER_END_PRINT

Benutzermakro zum Hinzufügen eigener Aktionen am Ende des Druckvorgangs.

Dieses Makro wird automatisch am Ende des Makros `END_PRINT` aufgerufen. Damit können Sie den Abschluss des Drucks um eigene Befehle erweitern.

**Einsatzbeispiele:**

- Zusätzliche Aktionen am Ende des Drucks ausführen
- Zusätzliche Geräte ausschalten
- Statistiken oder Protokolle speichern
- Eigene Reinigung oder Wartung des Druckers durchführen

**Beispiel für das Überschreiben in `mod_data/user.cfg`:**
```gcode
[gcode_macro _USER_END_PRINT].
gcode:
    # Zusätzlichen Lüfter deaktivieren
    SET_PIN PIN=my_fan VALUE=0
    # Benachrichtigung senden
    M118 Druckvorgang abgeschlossen!
    # Oder andere benutzerdefinierte Befehle
```

**Hinweis:** Standardmäßig ist das Makro leer und kann vom Benutzer nach Bedarf überschrieben werden.

---

### CANCEL

Druck abbrechen

---

### CLEAR_NOZZLE

Düsenreinigung (wie in der Standard-Firmware).
Parameter:

- `EXTRUDER_TEMP` – Extrudertemperatur (Standard: `230`)

- `BED_TEMP` – Betttemperatur (Standard: `80`)

*`PRECLEAR` ist kein Parameter von `CLEAR_NOZZLE`, sondern ein globales Flag, das über `SAVE_ZMOD_DATA PRECLEAR=1` gesetzt wird; es aktiviert die Vorreinigung. [Mehr erfahren](/de/Global/#preclear).*

*Das Überschreiben des Makros `CLEAR_NOZZLE` in `mod_data/user.cfg` ändert die native Düsenreinigung nicht, wenn sie direkt vom nativen Bildschirm aufgerufen wird: Der native Bildschirm arbeitet ohne Z-Mod und verwendet daher keine Z-Mod-Makros.*

---

### LED_ON

Beleuchtung einschalten

---

### LED_OFF

Beleuchtung ausschalten

---

### LED

Beleuchtung auf einen bestimmten Prozentsatz einschalten

- S - Prozent (50)

---

### PAUSE

Druck unterbrechen

---

### RESUME

Druck nach einer Pause fortsetzen

---

### PLAY_MIDI

MIDI-Datei abspielen

- `FILE` - Dateiname (Standard: `For_Elise.mid`). Die Dateien befinden sich in `mod_data/midi/`

---

### REBOOT

Den Drucker neu starten

---

### CLOSE_DIALOGS

Schließt Dialoge auf dem nativen Bildschirm (langsame Methode). Wird verwendet, um das Fenster am Ende oder beim Abbruch des Drucks zu schließen.

Kann den Drucker zum Einfrieren bringen.

Implementierung: @darksimpson.

Auch gesteuert über [CLOSE_DIALOGS](/de/Global/#close_dialogs)

---

### FAST_CLOSE_DIALOGS

Schließt Dialoge auf dem nativen Bildschirm (schnelle Methode). Wird verwendet, um das Fenster am Ende oder beim Abbruch des Drucks zu schließen.

Arbeitet schneller und lässt den Drucker nicht einfrieren.

*Um Dialoge schnell zu schließen, gehen Sie über das Menü des Druckerbildschirms zu `Einstellungen` -> `WLAN-Symbol` -> `Netzwerkmodus` und aktivieren Sie **den Schieberegler** `Nur lokale Netzwerke`.*

Wird auch über [CLOSE_DIALOGS](/de/Global/#close_dialogs) gesteuert.

Implementierung: @darksimpson.

---

### NEW_SAVE_CONFIG

Führt `SAVE_CONFIG` aus, ohne den nativen Bildschirm einfrieren zu lassen. Kann auch verwendet werden, um Klipper neu zu starten, ohne dass der native Bildschirm hängt.

Implementierung: @darksimpson.

Dauert etwa eine Minute.

Kann gelegentlich Darstellungsfehler auf dem nativen Bildschirm verursachen.

---

### SHUTDOWN

Den Drucker ausschalten
