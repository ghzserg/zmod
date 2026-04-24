<h1 align="center">Globaler Parameter</h1>

Ein Makro ist ein kleines Programm in der Sprache Klipper/Gcode.

Es kann aufgerufen werden durch:

- Aus der GCODE-Datei
- Von der Fluidd/Mainsail-Konsole (drücken Sie den englischen Buchstaben "C" in Fluidd)

!!! info "Hinweis"
    *Der Wert in Klammern ist der Standardwert.

---

### LANG

Legt Sie die Sprache fest, die Z-Mod verwenden soll.

- LANG - Sprache: `en - Englisch`, `ru - Russisch`, `de - Deutsch`, `fr - Französisch`, `it - Italienisch`, `es - Spanisch`, `zh - Chinesisch`, `ja - Japanisch`, `ko - Koreanisch`, `pt - Portugiesisch`, `cs - Tschechisch`, `tr - Türkisch`

Beispiel:
```
LANG LANG=de
```

---

### SET_TIMEZONE

Zeitzone ändern:

Man findet die Zeitzone in dem folgenden Ordner `/usr/data/.mod/.zmod/usr/share/zoneinfo`

```
SET_TIMEZONE ZONE=Asia/Yekaterinburg
```

- ZONE - Zeitzone (Asien/Jekaterinburg)
- ZONE - Zeitzone (Europe/Berlin)

---

### NOZZLE_CONTROL

Kollisionsverhinderung der Düse mit dem Druckbett oder Ablösung des Werkstücks.

Notabschaltung bei Überschreitung des eingestellten Gewichtslimits.

- GEWICHT - Gewicht in Gramm (1500)

Einstellungen bleiben nach einem Neustart erhalten.

Setzen Sie `NOZZLE_CONTROL WEIGHT=0`, um diese Funktion zu deaktivieren.

!!! info "INFO"
    *Die Steuerung ist deaktiviert, bis das Makro zum ersten Mal aufgerufen wird.*

Bei Verwendung des nativen Bildschirms startet der Drucker nach der Makroausführung neu.

Ohne den nativen Bildschirm wird Klipper neu gestartet (Konfigurationsdateien werden angepasst).

Funktioniert automatisch; zusätzliche Makros sind für G-Code verfügbar.

- `ZCONTROL_ON` - Steuerung aktivieren
- `ZCONTROL_OFF` - Steuerung deaktivieren
- `ZCONTROL_STATUS` - ermittelt den Status der Funktion
- `ZCONTROL_PAUSE` - Aufruf der Pause beim Auslösen (die Pause wird erst nach Freigabe der Befehlswarteschlange ausgeführt, nicht bei den ersten Schichten).
- `ZCONTROL_ABORT` - stoppt Klipper, wenn ausgelöst
- `ZCONTROL_AUTO` - stoppt Klipper (wenn Höhe z < `ZCONTROL_Z`), oder ruft PAUSE auf, wenn z >= `ZCONTROL_Z`.
- `ZCONTROL_Z Z=10` - setzt die Höhe um Z.
- `SAVE_ZMOD_DATA ZCONTROL_Z=10` - speichert die Höhe um Z. Wenn Sie nicht auf Pause schalten wollen, setzen Sie ```SAVE_ZMOD_DATA ZCONTROL_Z=230```.

Um die Düsensteuerung für die ersten Schichten zu aktivieren, fügen Sie `ZCONTROL_PAUSE` im Slicer an der gewünschten Stelle hinzu.

---

### GET_ZMOD_DATA

Liefert die Werte der globalen Z-Mod-Parameter/Flags.
Nach der Ausführung des Makros zeigt die Konsole die Daten an, die zuvor gespeichert und zum aktuellen Zeitpunkt angewendet wurden.

??? note "FLUIDD"

    `Fluidd` -> `Makros` -> `Haupt` -> `Z-Mod-PARAMETER`.

??? note "MAINSAIL"

    `Mainsail` -> `Dashboard` -> `System` -> `GET ZMOD DATA`

---

### GLOBAL

Vereinfachte Steuerung der globalen Parameter. Nur Parameter, die durch Drücken der Taste geändert werden können, sind verfügbar. Parameter, die eine Nummer, einen Dateinamen usw. erfordern, werden von diesem Makro nicht gesteuert.

**Es wird empfohlen, den Drucker nach dem Ändern von Parametern neu zu starten**

---

### SAVE_ZMOD_DATA

Speichert globale Z-Mod-Parameter/Flags, die bei jedem Druck angewendet werden.

Dieses Makro muss nicht in den Start-, Endcode- oder Gcode-Datei eingefügt werden. Das Makro wird über die Konsole Fluidd/Mainsail aufgerufen. 

Nach dem Ausschalten des Druckers werden die Parameter im Druckerspeicher in der Datei `mod_data/variables.cfg` gespeichert 

!!! info "INFO"
    **die Datei nicht von Hand editieren - Sie bringen Klipper oder den ZMod** durcheinander
    und müssen nicht jedes Mal neu eingegeben werden.

**Um den gewünschten Parameter zu bearbeiten:**

??? note "FLUIDD"

    `Fluidd` -> `Makros` -> `System` -> `SAVE Z-Mod PARAMETERS`

??? note "MAINSAIL"

    `Mainsail` -> `Dashboard` -> `System` -> `SAVE ZMOD DATA`
    
wähle den Parameter aus, den Sie ändern wollen, trage ihn ein und drücken `SENDEN`. Sehen Sie, was in der Konsole angezeigt wird.

Zweite Möglichkeit. Schreiben Sie in die Konsole den gewünschten Befehl, zum Beispiel: `SAVE_ZMOD_DATA CLOSE_DIALOGS=2`.

[Gespeicherte Parameter anzeigen](/de/Global/#get_zmod_data)

---

### Parameter des Menüs zur Auswahl der Druckfarbe ###

**Die Parameter des Farbauswahlmenüs gelten ausschließlich für den AD5X.**

##### ALLOWED_TOOL_COUNT

Die Anzahl der Werkzeuge, die im Farbauswahlmenü angezeigt werden. Dies bezieht sich auf die Befehle T0, T1 usw. in der gcode-Datei, nicht auf die physischen Spulen in Ihrem IFS.

Wenn Z-Mod die Datei erfolgreich nach verwendeten Instrumenten durchsucht, wird dieser Wert überschrieben und es werden nur die in der Datei verwendeten Instrumente angezeigt.

Diese Einstellung kann nicht verwendet werden, wenn der native Bildschirm aktiviert ist.

[Siehe Einstellung für die Vorverarbeitung](/de/Recomendations/#aktivieren-sie-die-md5-kontrolle)

Beispiel: `SAVE_ZMOD_DATA ALLOWED_TOOL_COUNT=4`.

##### SCAN_FILE_COLORS

Ermöglicht das Scannen von Gcode-Dateien, um die verwendeten Werkzeugwechselbefehle (T0, T1 usw.) und die ihnen im Slicer zugewiesenen Farben und Materialien zu ermitteln: 0 (aus), 1 (an), 2 (schaltet das vollständige Scannen aus, sucht aber nach vom Slicer-Skript vorbereiteten Daten).

[Siehe Einstellung für die Vorverarbeitung](/de/Recomendations/#aktivieren-sie-die-md5-kontrolle)

Beispiel: `SAVE_ZMOD_DATA SCAN_FILE_COLORS=0`.

##### COLOUR_MENU_1_BASED

Legt fest, welche Bezeichnungen im Farbauswahlmenü angezeigt werden sollen: beginnend mit 0 (T0, T1, etc) oder beginnend mit 1 (Farbe 1, Farbe 2, etc). Dies ändert nur die Namen der Schaltflächen und dient nur der Bequemlichkeit: 0 (von Null), 1 (von Eins).

Beispiel: `SAVE_ZMOD_DATA COLOUR_MENU_1_BASED=1`.

##### AUTO_ASSIGN_COLORS

Legt fest, ob beim Druckstart die automatische Zuordnung von Werkzeugwechselbefehlen (T0, T1 usw.) zum im IFS geladenen Filament versucht werden soll. Sofern der Silent-Modus nicht aktiviert ist, wird das Farbauswahlmenü weiterhin angezeigt. Diese Einstellung betrifft nur die Standardauswahl: 

- 0 (deaktivieren), 
- 1 (aktivieren).

Diese Einstellung gilt auch für Drucke, die im Silent-Modus gestartet werden. Sie können die automatische Materialzuordnung so konfigurieren, dass der Druckvorgang bei bestimmten Fehlern abgebrochen wird: 

- 2 (Abbruch, wenn Materialien nicht zugeordnet werden können; Farbabweichungen sind zulässig), 
- 30 (Abbruch bei allen Problemen).

Für benutzerdefinierte Werte bei Fehlerbedingungen im stillen Modus addieren Sie die folgenden Werte, um die richtige Einstellung zu ermitteln:

- 2 (Mindestens ein Material kann nicht zugeordnet werden; z. B. ist in der G-Code-Datei ABS angegeben, aber nur PLA geladen; oder die Materialdaten konnten nicht geladen werden).
- 4 (Mindestens eine Farbe kann nicht zugeordnet werden, üblicherweise aufgrund eines deaktivierten oder fehlgeschlagenen Dateiscans).
- 8 (Mindestens eine Farbe stimmt möglicherweise nicht überein).
- 16 (Mindestens eine physische Spule wurde in der Datei mehreren Werkzeugindizes zugeordnet).

[Siehe Vorverarbeitungseinstellung](/de/Recomendations/#aktivieren-sie-die-md5-kontrolle)

Beispiel: `SAVE_ZMOD_DATA AUTO_ASSIGN_COLORS=0`.

### Parameter für den Start des Druckvorgangs und die Erstellung einer Bettkarte [START_PRINT]:

##### MIDI_START

MIDI abspielen bei Druckbeginn (""), 0 zum Ausschalten

Beispiel: `SAVE_ZMOD_DATA MIDI_START=Pain-Shut-your-mouth.mid`.

---

##### PRECLEAR

Düsenvorreinigung in CLEAR_NOZZLE verwenden 0-(nein), 1-(ja)

Beispiel: `SAVE_ZMOD_DATA PRECLEAR=0`.

---

##### PRINT_LEVELING

Erstellen Sie bei jedem Druck ein Bettnetz (über den nativen Bildschirm, wenn dieser aktiviert ist) 

- 0-(nein), 
- 1-(ja) . 

*Um die Bettnetz-Karte vom nativen Bildschirm zu entfernen, gehen Sie zu `Einstellungen` :arrow_right: `WiFi-Symbol` :arrow_right: `Netzwerkmodus` :arrow_right: **aktivieren Sie den Schieberegler** `Nur lokale Netzwerke `* über das Menü des Druckerbildschirms.

Beispiel: `SAVE_ZMOD_DATA PRINT_LEVELING=1`.

---

##### USE_KAMP

Verwenden Sie nach Möglichkeit adaptives Mesh (KAMP) anstelle von vollständigem Bett-Mesh: 

- 0-(nein), 
- 1-(ja) .

Es wird empfohlen, `SAVE_ZMOD_DATA CLEAR=LINE_PURGE` zu setzen, um die Spülposition mit dem KAMP-Mesh abzustimmen.

*Ermöglicht die Verwendung von KAMP beim Leveln vom nativen Bildschirm über das Netzwerk*.

Beispiel: `SAVE_ZMOD_DATA USE_KAMP=1`.

---

##### MESH_TEST

Testen Sie das Bettnetz vor dem Drucken.:

- 0 - keine
- 1 - Test OHNE automatische Z-Offset-Auswahl (standardmäßig)
- 2 - Test OHNE automatische Z-Offset-Auswahl, bei falscher Zuordnung KAMP starten
- 3 - Test mit AUTO Z-Offset-Auswahl, mit Düsenreinigung
- 4 - Testen Sie mit automatischer Z-Offset-Anpassung und Düsenreinigung. Falls das Bettnetz nicht übereinstimmt, führen Sie KAMP aus.

**Automatische Auswahl des Z-Offsets**

Algorithmus zur automatischen Z-Offset-Kalibrierung:

1. **Quelldaten:** Der Druckerspeicher speichert ein Bettnetz (typischerweise 25 Punkte), das beim letzten Nivellierungsvorgang erstellt wurde.

2. **Vorbereitung:**

	* Die Düse wird auf Betriebstemperatur erhitzt, über das Druckbett geführt und auf 151 °C abgekühlt.

3. **Messpunktauswahl:**

	* Der **Mittelpunkt** des Netzes wird verwendet.

4. **Messung und Vergleich:**

	* Am ausgewählten Punkt wird eine neue Messung durchgeführt.

		* Der ermittelte Wert wird mit dem im Bettnetz gespeicherten Wert verglichen.

5. **Offset-Korrektur:**

	* Beträgt die Abweichung **weniger als 0,3 mm**, wird die Differenz zum aktuellen Z-Offset-Wert addiert.

		* Beträgt die Abweichung **größer oder gleich 0,3 mm**, betrachtet das System das gespeicherte Netz als veraltet und leitet, sofern die Einstellungen dies zulassen, automatisch eine Bettnivellierung (KAMP) ein.

**Kein automatischer Z-Offset**

Algorithmus zur Validierung des Druckbettnetzes:

1. **Messung:** An der aktuellen Position wird eine Standard-Sondenmessung durchgeführt.

2. **Validierung:** Der ermittelte Z-Wert wird auf Übereinstimmung mit dem geladenen Netz geprüft.

3. **Kriterium:** Der Wert muss im Bereich von (Netzminimum - 0,21 mm) bis (Netzmaximum + 0,21 mm) liegen.

4. **Ergebnis:**
	* **Erfolg:** Das Netz wird als korrekt betrachtet, der Druckvorgang wird fortgesetzt.

		* **Fehler:** Es wird eine Warnung ausgegeben und der Druckvorgang wird gestoppt oder, falls die Einstellungen dies zulassen, automatisch eine Bettnivellierung (KAMP) eingeleitet.

**Hinweise:**

* Diese Prüfung ist eine grobe Schätzung. Sie dient dazu, kritische Fehler zu erkennen, z. B. wenn ein für eine PEI-Folie erstelltes Netz für dickes Glas geladen wird und umgekehrt.

* **Diese Prüfung bietet keinen absoluten Schutz.**
* Bei Verwendung der intelligenten Reinigung (KAMP) erfolgt die Heizwartezeit in der Nähe des Reinigungsbereichs, nicht in einer Ecke des Bettes.

Beispiel: `SAVE_ZMOD_DATA MESH_TEST=0`

---

##### FORCE_MD5

Igor Polunovskiy

Überprüft die MD5-Summe der Datei, löscht die Datei im Falle eines Fehlers.

- 0-nicht prüfen,
- 1-prüfen 

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

Beispiel: `SAVE_ZMOD_DATA FORCE_MD5=1`.

---

##### DISABLE_SKEW

- 1 - SKEW-Korrektur deaktivieren, 
- 0 - Profil `skew_profile` laden (das Makro `SKEW_PROFILE LOAD=skew_profile` wird aufgerufen)

[Mehr lesen](https://www.klipper3d.org/Skew_Correction.html)

Beispiel: `SAVE_ZMOD_DATA DISABLE_SKEW=1`.

---

##### LOAD_ZOFFSET

Laden des Z-Offsets aus den zuvor über SET_GCODE_OFFSET gespeicherten globalen Parametern.

- 1 - ja,
- 0 - nein

[Wie funktioniert Z-Offset](/de/FAQ/#so-funktioniert-der-z-offset)

Beispiel: `SAVE_ZMOD_DATA LOAD_ZOFFSET=0`.

---

##### DISABLE_PRIMING

Düsenreinigung über Extrusion deaktivieren:

- 0-no,
- 1-yes

Beispiel: `SAVE_ZMOD_DATA DISABLE_PRIMING=0`.

---

##### CLEAR

Auswahl des Algorithmus zur Reinigung der Düsenextrusion (LINE_PURGE)

- _CLEAR1 – Orca-Stil (kann das Druckbett mit KAMP beschädigen)
- _CLEAR2 – FF-Gruppenstil (kann das Druckbett mit KAMP beschädigen)
- _CLEAR3 – Alternative zur FF-Gruppe (kann das Druckbett mit KAMP beschädigen)
- _CLEAR4 – Shreider-Code (von oben rechts nach unten rechts)
- _CLEAR_TRAP – Für Pinsel (von oben rechts nach unten rechts)
- LINE_PURGE – KAMP-Reinigung

Wenn Sie `KAMP` verwenden, wird die Reinigung zwangsweise auf `LINE_PURGE` gesetzt (anstelle von _CLEAR1, _CLEAR2, _CLEAR3, _CLEAR4).

Wenn Sie `LINE_PURGE` verwenden, aber die Objektpartitionierung in Orca nicht aktiviert haben, dann wird `_CLEAR2` erzwungen

Du kannst dein Aufräum-Makro zu `mod_data/user.cfg` hinzufügen und es mit diesem Parameter benennen.

*behemoth*

Beispiel: `SAVE_ZMOD_DATA CLEAR=LINE_PURGE`.

*5M/5MPro: Dies ist kein Ersatz für das native clean(CLEAR_NOZZLE), bei dem die Düse in der Mitte von oben in den Tisch stößt und dann das Plastik gegen den Tisch schabt. Dies ist eine Reinigung der Düse kurz vor dem Druck.

---

### Druckende und Abbruchoptionen [END_PRINT]:

##### MIDI_END

MIDI am Ende des Drucks abspielen (""), 0 für deaktivieren

Beispiel: `SAVE_ZMOD_DATA MIDI_END=Pain-Shut-your-mouth.mid`.

---

##### CLOSE_DIALOGS

Dialoge automatisch schließen, wenn der Druckvorgang beendet ist und abgebrochen wird 

- 0 - nein,
- 1 - ja langsam,
- 2 - ja schnell

*Um Dialoge schnell zu schließen,  gehen Sie im Menü des Druckerbildschirms zu `Einstellungen` :arrow_right: `WiFi-Symbol` :arrow_right: `Netzwerkmodus` :arrow_right: **aktivieren Sie den Schieberegler** `Nur lokale Netzwerke `* über das Menü des Druckerbildschirms.

Beispiel: `SAVE_ZMOD_DATA CLOSE_DIALOGS=2`.

---

##### STOP_MOTOR

Automatisches Abschalten der Motoren nach dem Drucken/Abbrechen nach 25 Sekunden 

- 0-nein,
- 1-ja 

Beispiel: `SAVE_ZMOD_DATA STOP_MOTOR=1`.

---

##### AUTO_REBOOT

Automatischer Neustart des Druckers nach Beendigung des Druckvorgangs (0):

- 0 - kein Neustart
- 1 - Neustart des Druckers über den Befehl `REBOOT`
- 2 - im Modus ohne eigenen Bildschirm - Neustart der Firmware über `FIRMWARE_RESTART`, mit Bildschirm - Neustart des Druckers über den Befehl `REBOOT`.

Beispiel: `SAVE_ZMOD_DATA AUTO_REBOOT=0`.

---

### Systemparameter:

##### MOTION_SENSOR

Verwenden Sie einen [Filamentbewegungssensor](https://de.aliexpress.com/item/1005006119360974.html) anstelle des Filamentpräsenzsensors.

- 0 - nein
- 1 - ja

Wenn Sie den Filament-Bewegungssensor verwenden, deaktivieren Sie ihn auf dem systemeigenen Bildschirm, da sonst der Druckvorgang abgebrochen wird.

Wenn der Filamentsensor im nicht-nativen Bildschirmmodus verwendet wird, wird der folgende Satz angezeigt, wenn er ausgelöst wird: `Out of filament`. Es wird in 30 Sekunden eine Pause eingelegt".

Beispiel: `SAVE_ZMOD_DATA MOTION_SENSOR=1`.

---

##### SILENT

Nur AD5X.

Das Farbauswahlfenster wird bei Druckbeginn nicht angezeigt

- 0 - Fenster anzeigen (Standard)
- 1 - Fenster nicht anzeigen, vorher eingestellte Farben verwenden
- 2 - Fenster nicht anzeigen, IFS nicht verwenden

Beispiel: `SAVE_ZMOD_DATA SILENT=0`

---

##### AUTOINSERT

Nur AD5X.

Filament automatisch laden

- 0 - Filament nicht automatisch laden
- 1 - Filament automatisch laden (Standard)

Beispiel: `SAVE_ZMOD_DATA AUTOINSERT=0`

---

##### ALWAYS_FULL_COLOR_CHANGE

Nur AD5X

Legt fest, ob der Farbwechselvorgang übersprungen werden soll, wenn die vorherige und die nachfolgende Farbe derselben physikalischen Spule zugeordnet sind.

- 0 - Überspringen des Prozesses
- 1 - den Vorgang nicht überspringen

Beispiel: `SAVE_ZMOD_DATA ALWAYS_FULL_COLOR_CHANGE=0`

---

##### USE_TRASH_ON_PRINT

Nur AD5X

Nur bei Betrieb im nicht-nativen Bildschirmmodus

Verwenden Sie beim Drucken den Mülleimer für den Farbwechsel.

- 0 - kein Auswurf im Abwurfschacht
- 1 - Auswurf im Abwurfschacht (Standard)
- 2 - nach dem Farbwechsel zum Abwurfschacht fahren, aber nicht auswerfen

Beispiel: `SAVE_ZMOD_DATA USE_TRASH_ON_PRINT=0`

---

##### REMOVE_FILAMENT

Nur AD5X.

Nur bei Betrieb im nicht-nativen Bildschirmmodus

Entfernen Sie das Filament nach Abschluss des Druckvorgangs

- 0 - nicht auswerfen (Standard)
- 1 - auswerfen

Beispiel: `SAVE_ZMOD_DATA REMOVE_FILAMENT=1`

---

##### FIX_SCV

Korrigiert den fehlerhaften SCV-Wert ([square_corner_velocity](https://www.klipper3d.org/Config_Reference.html#printer)) beim Rendern von Beschleunigungsgraphen und Berechnen von Input Shapers.

- 0 belässt den Parameter wie in Stock 5
- 1 verwendet `quare_corner_velocity` aus `mod_data/user.cfg` oder `printer.base.cfg`

Beispiel: `SAVE_ZMOD_DATA FIX_SCV=1`.

In unserem Drucker ist `quare_corner_velocity: 25`, und die Berechnungen des Shaper- und Beschleunigungsgraphen werden für `SCV = 5` durchgeführt.

Im Großen und Ganzen wirkt sich dies nur auf die Ausgabebeschleunigungen und die berechneten Glättungsstufen aus.
Die Werte `shaper_type_x`, `shaper_freq_x`, `shaper_type_y`, `shaper_freq_y` werden nicht verändert.

Andererseits sinken die berechneten Beschleunigungen um einen Faktor von etwa 2, wenn die Berechnung korrekt ist.

Daher die Empfehlung, in `mod_data/user.cfg` zu schreiben:
```
[printer]
square_corner_velocity: 9
```

Dies reduziert die Geschwindigkeit in den Ecken und verbessert generell die Druckqualität, allerdings auf Kosten einer geringfügigen Geschwindigkeitsreduzierung.

!!! tip "Empfohlens Plugin aktivieren"
	
	Oder das Plugin [Recommend](/de/Plugin/#plugins-in-z-mod) aktivieren.

---

##### WIFI

Bei einigen Firmware-Versionen kann es gelegentlich vorkommen, dass WLAN nicht startet.

Um dies zu beheben, verbinden Sie sich über den nativen Bildschirm mit einem WLAN-Netzwerk.

Führen Sie `SAVE_ZMOD_DATA WIFI=1` aus.

Deaktivieren Sie anschließend WLAN auf dem nativen Bildschirm.

- 0 – WLAN über den nativen Bildschirm verwenden
- 1 – WLAN über Z-Mod verwenden

---

##### FIX_E0011

Häufige Ursachen für den Fehler E0011 (Timer zu kurz):

- Der Host hat nicht innerhalb der vorgegebenen Zeit (0,025 Sek.) reagiert.

- Die MCU hat nicht innerhalb der vorgegebenen Zeit (0,025 Sek.) reagiert.

Spezifische Ursachen:

- Eingefrorenes Nations-MCU-Mainboard oder -eboard. „Kommunikationsverlust mit MCU 'mcu'“. Lösung: Neustart. Mainboard (`mcu`) oder Extruderplatine (`eboard`) austauschen.

- Überlastung der Host-CPU (Shaper-Berechnungen/Grafikdarstellung).

- Überlastung des EMMC (Git-Operationen, Backups, Uploads großer Dateien während des Druckvorgangs usw.).

- Unzureichender Arbeitsspeicher. Lösung: CPU nachlöten und auf 256 MB Arbeitsspeicher aufrüsten.

- Beschädigtes Extruderkabel. Lösung: Kabel austauschen/reparieren.

- Lose Kabelverbindung der Extruderplatine. Lösung: Extruderplatine austauschen.

- Laden von SWAP-Daten (SWAP befindet sich auf dem EMMC-Speicher, der mit 10 MB/s arbeitet; die SWAP-Daten können während der Shaper-Berechnungen bis zu 25 MB groß sein). Lösung: Deaktivieren Sie SWAP, wenn Sie über 256 MB RAM verfügen, mit `SAVE_ZMOD_DATA USE_SWAP=0`.

- Absturz der MCU-Firmware. Lösung: Flashen Sie die MCU neu, indem Sie sie auf Werkseinstellungen zurücksetzen (z. B. über [Werkseinstellungen](/de/Setup/#drucker-auf-werkseinstellungen-zurücksetzen-erforderlich-für-die-installation-des-mods)) oder das Modul [UPDATE_MCU](/de/System/#update_mcu) verwenden.

Beheben Sie die Fehler E0011 und `Kommunikations-Timeout während des Homing`. Durch Ändern dieses Parameters wird der Drucker neu gestartet. 0 – Nein, 1 – Ja (0):

– 0 – Standardparameter (0,025) beibehalten
– 1 – Parameter auf 0,1 setzen

Beispiel: `SAVE_ZMOD_DATA FIX_E0011=1`

Dieser Fehler kann auch auftreten:

– Große Anzahl ausgeschlossener Modelle: Lösung `Prozessprofil` :arrow_right: `Sonstige` :arrow_right: `Ausgabe-G-Code` :arrow_right `Modelle ausschließen` deaktivieren.

– Wenn Sie den Swap-Speicher in FF5M/FF5MPro deaktiviert haben.

Führen Sie das Makro `MEM` aus und prüfen Sie, ob Swap-Speicher vorhanden ist und wie groß dieser ist.

Aktivieren Sie den Swap-Speicher, falls er deaktiviert ist: ```SAVE_ZMOD_DATA USE_SWAP=1```

– Wenn Sie FF5M/FF5MPro verwenden, führen Sie einen vollständigen Test durch. Dieser umfasst die PID-Kalibrierung, das Entfernen der Tabellenzuordnung und das gleichzeitige Entfernen der Shaper.

Es empfiehlt sich, alle Kalibrierungen [hier gemäß dieser Anleitung](/de/SetupCalibrations/#drucker-kalibrierung-für-einsteiger) durchzuführen.

Der Fehler `Kommunikations-Timeout beim Homing` kann aufgrund einer hohen Kommunikationslatenz zwischen Host und Mikrocontrollern auftreten. Die Round-Trip-Zeit sollte konstant unter 10 ms liegen. Kurzzeitige Latenzspitzen können zu Homing-Fehlern führen.

`TRSYNC_TIMEOUT` ist ein Klipper-Parameter (Standardwert: 0,025 s), der Systemverzögerungen kompensiert.

Die Standarddatei `/opt/klipper/klipper/mcu.py` setzt `TRSYNC_TIMEOUT = 0,025`. Der Patch ändert diesen Wert auf `TRSYNC_TIMEOUT = 0,1`.

**So beheben Sie das Problem mit der Standard-Firmware:**

- Formatieren Sie einen USB-Stick als FAT32.

- Speichern Sie die Datei `flashforge_init.sh` auf dem USB-Stick:

- [Parameter Adventurer5M korrigieren](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-e0011-on.tgz)

- [Standardparameter Adventurer5M wiederherstellen](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-e0011-on.tgz)

- [Parameter Adventurer5MPro korrigieren](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-e0011-on.tgz)

- [Standardparameter Adventurer5MPro wiederherstellen](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-e0011-on.tgz)

- Schalten Sie den Drucker aus.
- Stecken Sie den USB-Stick in den Drucker.

- Schalten Sie den Drucker ein (er piept laut).

- Warten Sie, bis er neu gestartet ist.

- Entfernen Sie den USB-Stick.

- Drucken Sie die problematische Datei erneut; der Fehler E0011 sollte nun nicht mehr auftreten.

**Manuelle Behebung mit der Standard-Firmware:**

- Installieren Sie [root](/de/Native_FW/#root).

- Stellen Sie mit [WinSCP](https://winscp.net/eng/download.php) eine SSH-Verbindung zum Drucker her.

- Bearbeiten Sie die Datei `/opt/klipper/klipper/mcu.py`.

- Suchen Sie nach `TRSYNC_TIMEOUT = 0.025` und ändern Sie den Wert in `TRSYNC_TIMEOUT = 0.1`.

- Speichern Sie die Datei und starten Sie den Drucker neu.

!!! tip "Empfohlens Plugin aktivieren"
	
	Oder das Plugin [Recommend](/de/Plugin/#plugins-in-z-mod) aktivieren.

---

##### FIX_E0017

E0017-Fehler beheben. Durch Ändern dieses Parameters wird der Drucker neu gestartet. 0 - Nein, 1 - Ja (1):

In der Originaldatei `/opt/klipper/klipper/toolhead.py` ist `LOOKAHEAD_FLUSH_TIME = 0.5` gesetzt. Der Original-Klipper verwendet `LOOKAHEAD_FLUSH_TIME = 0.250`. Unsere Modifikation funktioniert am besten mit `LOOKAHEAD_FLUSH_TIME = 0.150`.

- 0 - Originalwert
- 1 - 0.150

Beispiel: `SAVE_ZMOD_DATA FIX_E0017=1`

**So beheben Sie den Fehler mit der Original-Firmware:**

- Formatieren Sie einen USB-Stick als FAT32.

- Speichern Sie die entsprechende Datei auf dem USB-Stick:

- [Adventurer5M-e0017-4.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-e0017-4.tgz) für FlashForge 5M

- [Adventurer5MPro-e0017-4.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-e0017-4.tgz) für FlashForge 5M Pro

- Schalten Sie den Drucker aus.

- Stecken Sie den USB-Stick in den Drucker.

- Schalten Sie den Drucker ein (er piept laut).

- Warten Sie, bis er neu gestartet ist.

- Entfernen Sie den USB-Stick.

- Drucken Sie die problematische Datei erneut; der Fehler E0017 sollte nun nicht mehr auftreten.

**Manuelle Reparatur der Standard-Firmware:**

- Installieren Sie [root](/de/Native_FW/#root).

- Stellen Sie mit [WinSCP](https://winscp.net/eng/download.php) eine SSH-Verbindung zum Drucker her.

- Bearbeiten Sie die Datei `/opt/klipper/klipper/toolhead.py`.

- Suchen Sie nach `LOOKAHEAD_FLUSH_TIME = 0.5` und ändern Sie den Wert in `LOOKAHEAD_FLUSH_TIME = 0.150`.

- Speichern Sie die Datei und starten Sie den Drucker neu.

!!! tip "Empfohlens Plugin aktivieren"
	
	Oder das Plugin [Recommend](/de/Plugin/#plugins-in-z-mod) aktivieren.

---

##### LED

LED-Helligkeit im eingeschalteten Zustand (50)

Beispiel: `SAVE_ZMOD_DATA LED=50`

---

##### MIDI_ON

Spielt MIDI, wenn es eingeschaltet ist (""), 0 zum Ausschalten

Beispiel: `SAVE_ZMOD_DATA MIDI_ON=Pain-Shut-your-mouth.mid`.

---

##### NEW_SAVE_CONFIG

Alternative SAVE_CONFIG verwenden (ruft `SAVE_CONFIG` auf, ohne den nativen Bildschirm aufzuhängen) [NEW_SAVE_CONFIG](/de/Main/#new_save_config) beim Kalibrieren von PID 0-nein, 1-ja (0)

Beispiel: `SAVE_ZMOD_DATA NEW_SAVE_CONFIG=0`.

---

##### USE_SWAP

SWAP aktivieren (1):

- 0 – Nein (*Nur für aufgerüsteten 256-MB-RAM*)
- 1 – Ja, auf EMMC
- 2 – Ja, USB-Flash bevorzugen

Beispiel: `SAVE_ZMOD_DATA USE_SWAP=1`.

---

##### CHINA_CLOUD

Chinesische Wolken einschalten 0 - nein, 1 - ja (1)

Beispiel: `SAVE_ZMOD_DATA CHINA_CLOUD=0`.

[Chinesische Cloud-Dienste deaktivieren](/de/Recomendations/#chinesische-cloud-dienste-deaktivieren)

Selbst wenn alle Cloud-Optionen über den Bildschirm deaktiviert sind, versucht der Drucker weiterhin, Fotos, Videos und Telemetriedaten an chinesische Server zu senden.

Durch Setzen dieses Parameters auf 0 werden diese Funktionen teilweise deaktiviert.

**Wenn chinesische Cloud-Dienste deaktiviert sind, sucht der Drucker nicht nach Firmware-Updates.**

Um die Firmware zu aktualisieren, aktivieren Sie die chinesischen Cloud-Dienste über `SAVE_ZMOD_DATA CHINA_CLOUD=1`, starten Sie den Drucker neu und führen Sie das Update durch.

Stattdessen können Sie verwenden:

- [zmod.link](/de/Zmod/#zlink) - Cloud, für die Verwaltung von Druckern über Fluidd/Mainsail.
- [Telegram bot](/de/Telegram/#telegram-bot).

So **deaktivieren** Sie chinesische Cloud-Dienste auf der Standard-Firmware:

- Formatieren Sie das Flash-Laufwerk auf FAT32
- Legen Sie die Datei [flashforge_init.sh](https://github.com/ghzserg/zmod/blob/main/Native_firmware/cloud/rem/flashforge_init.sh) auf diesem Flash-Laufwerk ab.
- Schalten Sie den Drucker aus
- Stecken Sie den USB-Stick in den Drucker
- Schalten Sie den Drucker ein
- Der Drucker wird 1 Mal neu gestartet
- Entfernen Sie den USB-Stick und verwenden Sie die Standard-Firmware

So **aktivieren** Sie chinesische Cloud-Dienste auf der Standard-Firmware:

- Formatieren Sie das Flash-Laufwerk auf FAT32
- Legen Sie die Datei [flashforge_init.sh](https://github.com/ghzserg/zmod/blob/main/Native_firmware/cloud/orig/flashforge_init.sh) auf dem Flash-Laufwerk ab.
- Schalten Sie den Drucker aus
- Stecken Sie den USB-Stick in den Drucker
- Schalten Sie den Drucker ein
- Der Drucker wird 1 Mal neu gestartet
- Entfernen Sie den USB-Stick und verwenden Sie die Standard-Firmware

---

##### NICE

Legen Sie die Priorität des Klipper-Prozesses fest.

- 1 ist die niedrigste Priorität,
- 40 ist die höchste Priorität (20).

Beispiel: `SAVE_ZMOD_DATA NICE=20`.

Je höher die Priorität von Klipper, desto mehr Ressourcen hat er, aber desto häufiger stürzen Moonraker und Kamera ab.

Für diejenigen, die Linux kennen:
```
NICE=20
grep -q "^nice = " /opt/config/mod_data/variables.cfg && NICE=$(grep "^nice = " /opt/config/mod_data/variables.cfg | cut -d "=" -f2| awk '{print $1}')
NICE=$((20-$NICE))
[ $NICE -ge 20 ] && NICE=19
[ $NICE -lt -20 ] && NICE=-20.
renice $NICE $(ps |grep klippy.py| grep -v grep| awk '{print $1}')
```

---

##### DISPLAY_OFF_TIMEOUT

Legen Sie die Timeout-Dauer (in Sekunden) fest, nach der sich der Bildschirm bei Nichtgebrauch automatisch ausschaltet. Standardwert: 180.

Hinweis: Der Bildschirm benötigt mindestens 5 Sekunden, um WLAN zu konfigurieren.

Beispiel: `SAVE_ZMOD_DATA DISPLAY_OFF_TIMEOUT=120`

---

##### PRO_POWEROFF_TIMEOUT

Legen Sie die Zeit (in Minuten) fest, nach der sich FF5M(AD5X) Pro automatisch ausschaltet. Standardwert: 0 (deaktiviert).

Beispiel: `SAVE_ZMOD_DATA PRO_POWEROFF_TIMEOUT=10`

---

##### SAVE_MOONRAKER

- 0 - Lädt die Positionen der Makrotasten aus Z-Mod (Standard)
- 1 - Ermöglicht das lokale Speichern von Makrotastenänderungen in Fluidd/Moonraker.

Wenn Makros lokal gespeichert werden, werden neue Makros in einem separaten Abschnitt abgelegt.

Beispiel: `SAVE_ZMOD_DATA SAVE_MOONRAKER=1`.

---

##### SAVE_FILAMENT_SENSORS

- 0 - Den Zustand der Filamentsensoren nach dem Neuladen nicht speichern, sie werden immer aktiviert sein (Standard)
- 1 - Zustand der Sensoren nach einem Neustart speichern. Wenn Sie einen Sensor deaktivieren, wird er auch nach dem Neustart deaktiviert.

Beispiel: `SAVE_ZMOD_DATA SAVE_FILAMENT_SENSORS=1`.
