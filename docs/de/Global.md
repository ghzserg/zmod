<h1 align="center">Globaler Parameter</h1>

Ein Makro ist ein kleines Programm in der Sprache Klipper/Gcode.

Es kann aufgerufen werden durch:

- Aus der GCODE-Datei
- Von der Fluidd/Mainsail-Konsole (drücken Sie den englischen Buchstaben "C" in Fluidd)

!!! Hinweis
    *Der Wert in Klammern ist der Standardwert.

---

### LANG

Legt die Sprache fest, die zMod verwenden soll.

- LANG - Sprache, en - Englisch, ru - Russisch, de - Deutsch, fr - Französisch, it - Italienisch, es - Spanisch, zh - Chinesisch, ja - Japanisch, ko - Koreanisch, pt - Portugiesisch, cs - Tschechisch, tr - Türkisch

Beispiel:
```
LANG LANG=de
```

---

### SET_TIMEZONE

Zeitzone ändern

- ZONE - Zeitzone (Asien/Jekaterinburg)

---

### NOZZLE_CONTROL

Kontrolle des Abreißens von Teilen oder des Auftreffens der Düse auf dem Tisch.

Notabschaltung des Druckers, wenn ein Übergewicht festgestellt wird.

GEWICHT - Gewicht in Gramm (1500)

Die Einstellung bleibt auch nach einem Neustart erhalten.

Setzen Sie `NOZZLE_CONTROL WEIGHT=0`, um diese Funktion zu deaktivieren.

*Vor dem ersten Makroaufruf ist die Steuerung deaktiviert.

Bei der Arbeit mit dem nativen Bildschirm wird durch den Aufruf des Makros der Drucker neu gestartet.

Bei der Arbeit im nicht-nativen Bildschirmmodus wird Klipper neu gestartet, wenn Änderungen an den Konfigurationsdateien vorgenommen werden.

Alles funktioniert im automatischen Modus, aber die folgenden Makros sind auch verfügbar und können in Gcode verwendet werden:

- ZCONTROL_ON" - Steuerung aktivieren
- ZCONTROL_OFF" - Steuerung deaktivieren
- ZCONTROL_STATUS` - ermittelt den Status der Funktion
- `ZCONTROL_PAUSE` - Aufruf der Pause beim Auslösen (die Pause wird erst nach Freigabe der Befehlswarteschlange ausgeführt, nicht bei den ersten Schichten).
- ZCONTROL_ABORT` - stoppt Klipper, wenn ausgelöst
- `ZCONTROL_AUTO` - stoppt Klipper (wenn Höhe z < `ZCONTROL_Z`), oder ruft PAUSE auf, wenn z >= `ZCONTROL_Z`.
- `ZCONTROL_Z Z=10` - setzt die Höhe um Z.
- SAVE_ZMOD_DATA ZCONTROL_Z=10` - speichert die Höhe um Z. Wenn Sie nicht auf Pause schalten wollen, setzen Sie ```SAVE_ZMOD_DATA ZCONTROL_Z=230```.

Wenn Sie die Düsensteuerung auf den ersten Schichten aktivieren wollen, dann fügen Sie ```ZCONTROL_PAUSE``` durch den Slicer auf der Schicht hinzu, auf der Sie die Pause anstelle der Unterbrechung verwenden wollen

---

### GET_ZMOD_DATA

Liefert die Werte der globalen ZMOD-Parameter/Flags.
Nach der Ausführung des Makros zeigt die Konsole die Daten an, die zuvor gespeichert und zum aktuellen Zeitpunkt angewendet wurden

Fluidd" -> "Makros" -> "Haupt" -> "ZMOD-PARAMETER".

---

### GLOBAL

Vereinfachte Steuerung der globalen Parameter. Nur Parameter, die durch Drücken der Taste geändert werden können, sind verfügbar. Parameter, die eine Nummer, einen Dateinamen usw. erfordern, werden von diesem Makro nicht gesteuert.

Es wird empfohlen, den Drucker nach dem Ändern von Parametern neu zu starten

---

### SAVE_ZMOD_DATA

Speichert globale ZMOD-Parameter/Flags, die bei jedem Druck angewendet werden.

Dieses Makro muss nicht in die Start-, Endcode- oder Gcode-Datei eingefügt werden. Das Makro wird über die Konsole fluidd/mainsail aufgerufen. Nach dem Ausschalten des Druckers werden die Parameter im Druckerspeicher in der Datei `mod_data/variables.cfg` gespeichert (**die Datei nicht von Hand editieren - Sie bringen den Clipper oder Mod** durcheinander) und müssen nicht jedes Mal neu eingegeben werden.

**Um den gewünschten Parameter zu bearbeiten, gehe zu `Fluidd` -> `Makros` -> `System` -> `SAVE ZMOD PARAMETERS`**, wähle den Parameter aus, den du ändern willst, trage ihn ein und drücke `SEND`. Sehen Sie, was in der Fluidd-Konsole angezeigt wird.

Zweite Möglichkeit. Schreiben Sie in die Fluidd-Konsole den gewünschten Befehl, zum Beispiel: `SAVE_ZMOD_DATA CLOSE_DIALOGS=2`.

[Gespeicherte Parameter anzeigen](/de/Global/#get_zmod_data)

---

#### Menüparameter für die Farbauswahl drucken ###

**Alle Optionen des Farbauswahlmenüs gelten nur für das AD5X.**

##### ERLAUBTE_WERKZEUG_ANZAHL

Die Anzahl der Werkzeuge, die im Farbauswahlmenü angezeigt werden. Dies bezieht sich auf die Befehle T0, T1 usw. in der gcode-Datei, nicht auf die physischen Spulen in Ihrem IFS.

Wenn zMod die Datei erfolgreich nach verwendeten Instrumenten durchsucht, wird dieser Wert überschrieben und es werden nur die in der Datei verwendeten Instrumente angezeigt.

Diese Einstellung kann nicht verwendet werden, wenn der native Bildschirm aktiviert ist.

[Siehe Einstellung für die Vorverarbeitung](https://wiki.zmod.link/de/Recomendations/#enable-md5-checksum-control)

Beispiel: `SAVE_ZMOD_DATA ALLOWED_TOOL_COUNT=4`.

##### SCAN_FILE_COLORS

Ermöglicht das Scannen von Gcode-Dateien, um die verwendeten Werkzeugwechselbefehle (T0, T1 usw.) und die ihnen im Slicer zugewiesenen Farben und Materialien zu ermitteln: 0 (aus), 1 (an), 2 (schaltet das vollständige Scannen aus, sucht aber nach vom Slicer-Skript vorbereiteten Daten).

[Siehe Einstellung für die Vorverarbeitung](https://wiki.zmod.link/de/Recomendations/#enable-md5-checksum-control)

Beispiel: `SAVE_ZMOD_DATA SCAN_FILE_COLORS=0`.

##### COLOUR_MENU_1_BASED

Legt fest, welche Bezeichnungen im Farbauswahlmenü angezeigt werden sollen: beginnend mit 0 (T0, T1, etc) oder beginnend mit 1 (Farbe 1, Farbe 2, etc). Dies ändert nur die Namen der Schaltflächen und dient nur der Bequemlichkeit: 0 (von Null), 1 (von Eins).

Beispiel: `SAVE_ZMOD_DATA COLOUR_MENU_1_BASED=1`.

##### AUTO_ASSIGN_COLORS

Legt fest, ob versucht werden soll, Werkzeugwechselbefehle (T0, T1 usw.) automatisch dem physischen Filament zuzuordnen, das in Ihrem IFS geladen ist, wenn Sie den Druckvorgang starten. Wenn Sie den stillen Modus nicht aktiviert haben, wird das Farbauswahlmenü trotzdem angezeigt; diese Einstellung wirkt sich nur auf die Standardauswahl aus: 0 (aus), 1 (ein).

Diese Einstellung gilt auch für Aufträge, die im stillen Modus ausgeführt werden. Sie können einstellen, dass der Druck unterbrochen wird, wenn bestimmte automatische Zuordnungsfehler auftreten: 2 (Unterbrechung, wenn ein Material nicht übereinstimmt, aber Farbabweichungen zulassen), 30 (Unterbrechung bei allen Problemen).

Um benutzerdefinierte Werte für Fehlerbedingungen im stillen Modus einzustellen, addieren Sie die folgenden Werte, um die gewünschte Einstellung zu erhalten:

* 2 (Mindestens ein Material stimmt nicht überein, z. B. wenn in der Gcode-Datei ABS angegeben ist, Sie aber nur PLA geladen haben, oder die Materialdaten nicht geladen werden konnten)
* 4 (Mindestens eine Farbe stimmt überhaupt nicht überein, in der Regel weil die Scandateien deaktiviert oder fehlerhaft sind)
* 8 (Mindestens eine Farbe stimmt nicht gut überein)
* 16 (Dieselbe physische Spule wurde mehr als einem Werkzeugindex in der Datei zugewiesen)

[Siehe Vorverarbeitungseinstellung](https://wiki.zmod.link/de/Recomendations/#enable-md5-checksum-control)

Beispiel: `SAVE_ZMOD_DATA AUTO_ASSIGN_COLORS=0`.

### Parameter für den Start des Drucks, Aufbau der Tabellenkarte [START_PRINT]:

##### MIDI_START

MIDI abspielen bei Druckbeginn (""), 0 zum Ausschalten

Beispiel: `SAVE_ZMOD_DATA MIDI_START=Schmerz-Halt-deinen-Mund.mid`.

---

##### PRECLEAR

Düsenvorreinigung in CLEAR_NOZZLE verwenden 0-nein, 1-ja (0)

Beispiel: `SAVE_ZMOD_DATA PRECLEAR=0`.

---

##### PRINT_LEVELING

Erstellen Sie bei jedem Druck eine Tischkarte (über den nativen Bildschirm, wenn dieser aktiviert ist) 0-nein, 1-ja (0). *Um die Desktop-Karte vom nativen Bildschirm zu entfernen, gehen Sie zu "Einstellungen" -> "WiFi-Symbol" -> "Netzwerkmodus" -> **aktivieren Sie den Schieberegler** "Nur lokale Netzwerke "* über das Menü des Druckerbildschirms.

Beispiel: `SAVE_ZMOD_DATA PRINT_LEVELING=1`.

---

##### USE_KAMP

Wenn es möglich ist, eine adaptive Tabellenkarte (KAMP) anstelle einer vollständigen Tabellenkarte zu verwenden 0-nein, 1-ja (0).

Es wird auch empfohlen, `SAVE_ZMOD_DATA CLEAR=LINE_PURGE` zu setzen, was es ermöglicht, den Bereinigungsraum zu verwenden, in dem die Tabellenkarte entfernt wird.

*Ermöglicht die Verwendung von KAMP beim Leveln vom nativen Bildschirm über das Netzwerk.

Beispiel: `SAVE_ZMOD_DATA USE_KAMP=1`.

---

##### MESH_TEST

Testen Sie die Tabellenkarte vor dem Drucken:

- 0 - keine
- 1 - Test OHNE automatische Z-Offset-Auswahl (standardmäßig)
- 2 - Test OHNE automatische Z-Offset-Auswahl, bei falscher Zuordnung KAMP starten
- 3 - Test mit AUTO Z-Offset-Auswahl, mit Düsenreinigung
- 4 - Test mit AUTO Z-Offset-Auswahl, mit Düsenreinigung, bei Kennfeldfehlern, KAMP starten

**Automatische Auswahl des Z-Offsets**

Algorithmus zur automatischen Kalibrierung des Z-Achsen-Offsets (Z-Offset):

1.  **Quelldaten:** Im Druckerspeicher ist die Tabellenkarte (in der Regel 25 Punkte) des letzten Ausrichtungsvorgangs gespeichert.
2.  **Vorbereitung:**

    * Düse auf Betriebstemperatur erwärmt, gegen den Tisch gereinigt und auf 151°C abgekühlt.

3.  **Wählen Sie den Messpunkt:**

    * Der **mittlere** Punkt der Karte wird verwendet.

4.  **Messung und Vergleich:**

    * Eine neue Sondenmessung (PROBE) wird an dem ausgewählten Punkt durchgeführt.
        * Der erhaltene Wert wird mit dem in der Tabellenkarte gespeicherten Wert verglichen.

5.  **Anpassung des Offsets:**

    * Ist die Differenz **kleiner als 0,3 mm**, wird die Differenz zum aktuellen Z-Offset-Wert addiert.
        * Ist die Differenz **größer oder gleich 0,3 mm**, betrachtet das System die gespeicherte Karte als irrelevant und startet bei aktivierten Einstellungen automatisch das Verfahren zur Neuausrichtung der Tabelle (KAMP).

**Kein automatischer Z-Offset**

Algorithmus für die Überprüfung der Tabellenkarte:

1.  **Messung:** Eine Standard-Sondenmessung (PROBE) wird am aktuellen Punkt durchgeführt.
2.  **Validierung:** Der resultierende Z-Wert wird mit der geladenen Karte verglichen.
3.  **Kriterium:** Der Wert muss zwischen (Karte Minimum - 0,21 mm) und (Karte Maximum + 0,21 mm) liegen.
4.  **Ergebnis:**

    **Erfolg:** Die Karte wird als korrekt angesehen, der Druck wird fortgesetzt.
        * Fehler:** ** Es wird eine Warnung angezeigt und der Druckvorgang wird gestoppt oder, falls die Einstellungen aktiviert sind, wird automatisch das Verfahren zur Neuausrichtung der Tabelle (KAMP) gestartet.

**Hinweise:**

* Die Prüfung ist eine grobe Schätzung. Sie ist dazu gedacht, kritische Fehler zu erkennen, z.B. wenn eine Karte, die für dickes Glas genommen wurde, für eine PEI-Platte geladen wird und umgekehrt.
* ** ** Verlassen Sie sich nicht auf diese Prüfung als absolute Sicherheit.
* Bei Verwendung der intelligenten Reinigung (KAMP) befindet sich die Wärmewarte in der Nähe des Reinigungsbereichs und nicht in der Ecke des Tisches.

Beispiel: `SAVE_ZMOD_DATA MESH_TEST=0`.

---

##### FORCE_MD5

Igor Polunovskiy

Überprüft die MD5-Summe der Datei, löscht die Datei im Falle eines Fehlers. 0-nicht prüfen, 1-prüfen (1)

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
- ````"/home/benutzer/zmod-preprocess.py";````
- ````"/home/benutzer/zmod_preprocess-darwin-amd64";````
- ````"/home/benutzer/zmod_preprocess-darwin-arm64";````
- ````"/home/benutzer/zmod_preprocess-linux-amd64";````

Beispiel: `SAVE_ZMOD_DATA FORCE_MD5=1`.

---

##### DISABLE_SKEW

1 - SKEW-Korrektur deaktivieren, 0 - Profil `skew_profile` laden (das Makro `SKEW_PROFILE LOAD=skew_profile` wird aufgerufen) (1)

[Mehr lesen](https://www.klipper3d.org/Skew_Correction.html)

Beispiel: `SAVE_ZMOD_DATA DISABLE_SKEW=1`.

---

##### LOAD_ZOFFSET

Laden des Z-Offsets aus den zuvor über SET_GCODE_OFFSET gespeicherten globalen Parametern. 1 - ja, 0 - nein (1)

[Wie funktioniert Z-Offset](/de/FAQ/#wie-z-offset-arbeitet)

Beispiel: `SAVE_ZMOD_DATA LOAD_ZOFFSET=0`.

---

##### DISABLE_PRIMING

Deaktivieren der Düsenreinigung durch Zusammendrücken 0-no, 1-yes (0)

Beispiel: `SAVE_ZMOD_DATA DISABLE_PRIMING=0`.

---

##### CLEAR

Auswahl des Algorithmus zur Reinigung der Düsenextrusion (LINE_PURGE)

- _CLEAR1 - wie in Orca
- CLEAR2 - aus FF-Gruppe
- CLEAR3 - aus der FF-Gruppe Variante 2
- CLEAR4 - Schrader-Reinigungscode von rechts oben nach unten
- CLEAR_TRAP - wenn es eine rechte Seitenbürste von oben nach unten gibt
- LINE_PURGE - Reinigung KAMP

Wenn Sie `KAMP` verwenden, wird die Reinigung zwangsweise auf `LINE_PURGE` gesetzt (anstelle von _CLEAR1, _CLEAR2, _CLEAR3, _CLEAR4).

Wenn Sie `LINE_PURGE` verwenden, aber die Objektpartitionierung in Orca nicht aktiviert haben, dann wird `_CLEAR2` erzwungen

Du kannst dein Aufräum-Makro zu 'mod_data/user.cfg' hinzufügen und es mit diesem Parameter benennen
*behemoth

Beispiel: `SAVE_ZMOD_DATA CLEAR=LINE_PURGE`.

*5M/5MPro: Dies ist kein Ersatz für das native clean(CLEAR_NOZZLE), bei dem die Düse in der Mitte von oben in den Tisch stößt und dann das Plastik gegen den Tisch schabt. Dies ist eine Reinigung der Düse kurz vor dem Druck.

---

### Druckende und Abbruchoptionen [END_PRINT]:

##### MIDI_END

MIDI am Ende des Drucks abspielen (""), 0 für deaktivieren

Beispiel: `SAVE_ZMOD_DATA MIDI_END=Schmerz-Halt-deinen-Mund.mid`.

---

##### CLOSE_DIALOGS

Dialoge automatisch schließen, wenn der Druckvorgang beendet ist und abgebrochen wird 0-nein, 1-ja langsam, 2-ja schnell

*Um Dialoge schnell zu schließen, gehen Sie im Menü des Druckerbildschirms zu "Einstellungen" -> "WiFi-Symbol" -> "Netzwerkmodus" -> **Schalten Sie den Schieberegler** "Nur lokales Netzwerk "* (0) ein.

Beispiel: `SAVE_ZMOD_DATA CLOSE_DIALOGS=2`.

---

##### STOP_MOTOR

Automatisches Abschalten der Motoren nach dem Drucken/Abbrechen nach 25 Sekunden 0-nein, 1-ja (1)

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

Verwendung anstelle des Glühfadensensors, [Glühfaden-Bewegungssensor](https://aliexpress.ru/item/1005007480443587.html) (0)

- 0 - nein
- 1 - ja

Wenn Sie den Filament-Bewegungssensor verwenden, deaktivieren Sie ihn auf dem systemeigenen Bildschirm, da sonst der Druckvorgang abgebrochen wird.

Wenn der Filamentsensor im nicht-nativen Bildschirmmodus verwendet wird, wird der folgende Satz angezeigt, wenn er ausgelöst wird: "Out of filament. Es wird in 30 Sekunden eine Pause eingelegt".

Beispiel: `SAVE_ZMOD_DATA MOTION_SENSOR=1`.

---

##### STILLE

Nur AD5X.

Das Farbauswahlfenster wird bei Druckbeginn nicht angezeigt

- 0 - Fenster anzeigen (Standard)
- 1 - Fenster nicht anzeigen, vorher eingestellte Farben verwenden
- 2 - Fenster nicht anzeigen, IFS nicht verwenden

Beispiel: `SAVE_ZMOD_DATA SILENT=0`

---

##### AUTOINSERT

Nur AD5X.

Balken automatisch laden

- 0 - Balken nicht automatisch laden
- 1 - Balken automatisch laden (Standard)

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

Bei Farbwechsel während des Drucks Bin-Reset verwenden

- 0 - nicht verwenden
- 1 - verwenden (Standard)

Beispiel: `SAVE_ZMOD_DATA USE_TRASH_ON_PRINT=0`

---

##### REMOVE_FILAMENT

Nur AD5X.

Nur bei Betrieb im nicht-nativen Bildschirmmodus

Entfernen Sie den Balken nach Abschluss des Druckvorgangs

- 0 - nicht auswerfen (Standard)
- 1 - auswerfen

Beispiel: `SAVE_ZMOD_DATA REMOVE_FILAMENT=1`

---

##### FIX_SCV

Behebt falsche SCV ([square_corner_velocity](https://www.klipper3d.org/Config_Reference.html#printer)) beim Rendern von Beschleunigungsgraphen und bei der Berechnung von Shapern.
 Shaper.

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

---

##### WIFI

Bei einigen Firmwares startet das Wi-Fi gelegentlich nicht.

Um dies zu beheben. Sie müssen eine Verbindung zum Wi-Fi-Netzwerk über den nativen Bildschirm herstellen.

Rufen Sie `SAVE_ZMOD_DATA WIFI=1` auf.

Deaktivieren des WLANs auf dem nativen Bildschirm

- 0 WiFi über den nativen Bildschirm verwenden
- 1 WiFi über zMod verwenden

---

##### FIX_E0011

Die Ursachen des Fehlers E0011 sind global (Timer zu nah):

- Host hat nicht in der vorgesehenen Zeit geantwortet (0,025 sec)
- MCU hat nicht innerhalb der vorgesehenen Zeit (0,025 sec) geantwortet

Private Ursachen:

- Nationen MCU-Hauptplatine oder E-Platine hängt. Kommunikation mit MCU 'mcu' verloren. Lösung: Neustart. Ersetzen Sie die Hauptplatine (`mcu`) oder die Extruderplatine ('eboard').
- Host-Prozessor ist überlastet (Shaper-Berechnung/Plotting)
- EMMC ist überlastet (Arbeit mit Git, Backups, Laden großer Dateien während des Druckens, usw.)
- RAM-Knappheit. Lösung: den Prozessor neu anlöten und den Speicher auf 256 Megabyte aufstocken
- Gebrochenes Kabel zum Extruder. Lösung: Ersetzen/Korrigieren des Kabels
- Der Kabelstecker hat keinen Kontakt mit der Extruderkopf-Platine. Lösung: Ersetzen Sie die Extruderplatine
- Herunterladen von Daten aus dem SWAP (SWAP befindet sich auf EMMC, das mit 10 MB/s läuft, die Datenmenge im SWAP beträgt bis zu 25 Megabyte, wenn Shaper gebaut werden). Lösung: SWAP deaktivieren, wenn Sie 256 MB RAM haben `SAVE_ZMOD_DATA USE_SWAP=0`.
- MCU-Firmware-Fehler. Lösung: MCU neu flashen [über Reset](/de/Setup/#return-printer-to-factory-settings-needed-for-mod installation). MCU neu flashen von mod [UPDATE_MCU](/de/System/#update_mcu)

Behebt den Fehler E0011 sowie `Communication timeout during homing`, eine Änderung des Parameters führt zu einem Neustart des Druckers. 0-Nein, 1-Ja (0)

- 0 belässt den Parameter auf dem Standardwert 0,025
- 1 setzt den Parameter auf 0,1

Beispiel: `SAVE_ZMOD_DATA FIX_E0011=1`.

Der Fehler kann auch auftreten:

- Große Anzahl von Modellausschlüssen: Lösung `Prozessprofil` -> `Andere` -> `Output G-cod` -> `Model Exclusion` das Häkchen ausschalten.
- Wenn Sie Swap auf FF5M/FF5MPro deaktiviert haben.
  
  Führen Sie das Makro `MEM` aus und sehen Sie nach, ob ein Swap vorhanden ist und wie groß er ist.
  
  Aktivieren Sie SWAP, wenn es deaktiviert ist ```SAVE_ZMOD_DATA USE_SWAP=1```.

- Wenn Sie FF5M/FF5MPro verwenden, machen Sie einen vollständigen Test. Nämlich die PID-Kalibrierung, das Entfernen der Table Map und das Entfernen des Shapers zur gleichen Zeit.
  
  Alle Kalibrierungen werden am besten [nach diesen Anweisungen] durchgeführt (/de/SetupCalibrations/#calibrate-printer-for-beginners)

Der Fehler "Kommunikations-Timeout während der Referenzfahrt" kann aufgrund einer hohen Kommunikationslatenz zwischen dem Host-Computer und den Mikrocontrollern auftreten. Normalerweise sollte die Fahrzeit konstant unter 10 ms liegen. Eine auch nur kurzzeitig hohe Verzögerung kann zu Fehlfunktionen bei der Einrichtung führen.

TRSYNC_TIMEOUT" ist ein Parameter in Klipper, der standardmäßig auf 0,025 Sekunden eingestellt ist. Er ermöglicht es Ihnen, Verzögerungen im Systembetrieb auszugleichen.

Die Datei `/opt/klipper/klippy/mcu.py` hat `TRSYNC_TIMEOUT = 0.025` in der Standarddatei, der Patch ändert den Wert auf `TRSYNC_TIMEOUT = 0.1`.

Wie man das in der Bestandsdatei korrigiert:

- Formatieren Sie den USB-Stick auf FAT32
- Speichern Sie die Datei `flashforge_init.sh` auf dem USB-Flash:
    - [Um den Adventurer5M-Parameter zu reparieren](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-e0011-on.tgz)
      - Wiederherstellen der Adventurer5M-Lagerparameter](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-e0011-off.tgz)
      - Um Adventurer5MPro zu reparieren](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-e0011-on.tgz)
      - So stellen Sie die Adventurer5MPro-Lagerparameter wieder her](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-e0011-off.tgz)

- Schalten Sie den Drucker aus
- Stecken Sie den USB-Flash in den Drucker
- Schalten Sie den Drucker ein
- Der Drucker gibt einen lauten Piepton ab.
- Warten Sie, bis er neu gestartet ist.
- Entfernen Sie den USB-Flash
- Drucken Sie die problematische Datei erneut, der Fehler E0011 sollte Sie nicht mehr stören.

So beheben Sie den Fehler manuell auf dem Lager:

- Installieren Sie [root](https://github.com/ghzserg/zmod/tree/main/Native_firmware/root)
- Gehe zu [winscp](https://winscp.net/eng/download.php) über ssh und editiere die Datei `/opt/klipper/klippy/mcu.py`.
- Suchen Sie die Zeile `TRSYNC_TIMEOUT = 0.025` in der Datei.
- Ersetzen Sie sie durch `TRSYNC_TIMEOUT = 0.1`.
- Speichern Sie die Datei auf dem Drucker.
- Starten Sie den Drucker neu

---

##### FIX_E0017

Behebt den Fehler E0017, wenn Sie den Parameter ändern, wird der Drucker neu gestartet. 0-Nein, 1-Ja (1)

In der Datei `/opt/klipper/klippy/toolhead.py` steht im Stack der Parameter `LOOKAHEAD_FLUSH_TIME = 0.5`, im Original-Clipper `LOOKAHEAD_FLUSH_TIME = 0.250`, unser Wunder funktioniert gut mit `LOOKAHEAD_FLUSH_TIME = 0.150`.

- 0 setzt den Parameter auf Lager
- 1 setzt den Parameter auf 0.150

Beispiel: `SAVE_ZMOD_DATA FIX_E0017=1`.

Wie auf dem Lager zu beheben:

- Formatieren Sie den USB-Stick auf FAT32
- Speichern Sie in der USB-Flash-Datei:
    - [Adventurer5M-e0017-4.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-e0017-4.tgz) für FlashForge 5M
      - [Adventurer5MPro-e0017-4.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-e0017-4.tgz) für FlashForge 5M Pro

- Schalten Sie den Drucker aus
- Stecken Sie den USB-Flash in den Drucker
- Schalten Sie den Drucker ein
- Der Drucker gibt einen lauten Piepton von sich.
- Warten Sie, bis er neu gestartet ist.
- Entfernen Sie den USB-Flash
- Drucken Sie die problematische Datei erneut, der Fehler E0017 sollte Sie nicht mehr stören.

So beheben Sie den Fehler manuell auf dem Gerät:

- Installieren Sie [root](https://github.com/ghzserg/zmod/tree/main/Native_firmware/root)
- Melden Sie sich über [winscp](https://winscp.net/eng/download.php) per ssh an und bearbeiten Sie die Datei `/opt/klipper/klippy/toolhead.py`.
- Suchen Sie die Zeile `LOOKAHEAD_FLUSH_TIME = 0.5` in der Datei.
- Ersetzen Sie sie durch `LOOKAHEAD_FLUSH_TIME = 0.150`.
- Speichern Sie die Datei auf dem Drucker.
- Starten Sie den Drucker neu

---

##### LED

LED-Helligkeit im eingeschalteten Zustand (50)

Beispiel: `SAVE_ZMOD_DATA LED=50`

---

##### MIDI_ON

Spielt MIDI, wenn es eingeschaltet ist (""), 0 zum Ausschalten

Beispiel: `SAVE_ZMOD_DATA MIDI_ON=Schmerz-Halt-deinen-Mund.mid`.

---

##### NEW_SAVE_CONFIG

Alternative SAVE_CONFIG verwenden (ruft `SAVE_CONFIG` auf, ohne den nativen Bildschirm aufzuhängen) [NEW_SAVE_CONFIG](/de/Main/#new_save_config) beim Kalibrieren von PID 0-nein, 1-ja (0)

Beispiel: `SAVE_ZMOD_DATA NEW_SAVE_CONFIG=0`.

---

##### USE_SWAP

SWAP verwenden (1)

- 0 - nein *Nur für aufgelöste Prozessoren mit 256 MB Speicher*
- 1 - ja, auf EMMC
- 2 - ja, wenn möglich auf USB FLASH

Beispiel: `SAVE_ZMOD_DATA USE_SWAP=1`.

---

##### CHINA_CLOUD

Chinesische Wolken einschalten 0 - nein, 1 - ja (1)

Beispiel: `SAVE_ZMOD_DATA CHINA_CLOUD=0`.

[Chinesische Wolken deaktivieren](/de/Recomendations/#disable-china-clouds)

Auch wenn Sie alles auf dem Bildschirm ausgeschaltet haben. Der Drucker versucht immer noch, Foto- und Videotelemetrie an chinesische Server zu senden.

Wenn Sie diesen Parameter auf 0 setzen, werden solche nützlichen Funktionen für den Hersteller teilweise deaktiviert.

**Wenn chinesische Wolken deaktiviert sind, sucht der Drucker nicht nach nativen Firmware-Updates.**

Stattdessen können Sie verwenden:

- [zmod.link](/de/Zmod/#zlink) - Cloud, für die Verwaltung von Druckern über Fluidd/Mainsail.
- [Telegram bot](/de/Macros/).

Wenn Sie die native Firmware aktualisieren möchten, müssen Sie die chinesische Cloud aktivieren, `SAVE_ZMOD_DATA CHINA_CLOUD=1`, neu starten und die native Firmware aktualisieren.

So **deaktivieren** Sie chinesische Wolken auf der nativen Firmware:

- Formatieren Sie das Flash-Laufwerk auf FAT32
- Legen Sie die Datei [flashforge_init.sh](https://github.com/ghzserg/zmod/blob/main/Native_firmware/cloud/rem/flashforge_init.sh) auf diesem Flash-Laufwerk ab.
- Schalten Sie den Drucker aus
- Stecken Sie den USB-Stick in den Drucker
- Schalten Sie den Drucker ein
- Der Drucker wird 1 Mal neu gestartet
- Entfernen Sie den USB-Stick und verwenden Sie die Standard-Firmware

So **aktivieren** Sie chinesische Wolken mit der Standard-Firmware:

- Formatieren Sie das Flash-Laufwerk auf FAT32
- Legen Sie die Datei [flashforge_init.sh](https://github.com/ghzserg/zmod/blob/main/Native_firmware/cloud/orig/flashforge_init.sh) auf dem Flash-Laufwerk ab.
- Schalten Sie den Drucker aus
- Stecken Sie den USB-Stick in den Drucker
- Schalten Sie den Drucker ein
- Der Drucker wird 1 Mal neu gestartet
- Entfernen Sie den USB-Stick und verwenden Sie die Standard-Firmware

---

##### NICE

Legen Sie die Priorität des Klipper-Prozesses fest. 1 ist die niedrigste Priorität, 40 ist die höchste Priorität (20).

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

Legt die Zeit in Sekunden fest, nach der der native Bildschirm ausgeschaltet wird, wenn er im nicht-nativen Bildschirmmodus betrieben wird. (180)

Beachten Sie, dass der native Bildschirm Zeit haben muss, um WiFi zu konfigurieren; die Mindestzeit beträgt 5 Sekunden.

Beispiel: `SAVE_ZMOD_DATA DISPLAY_OFF_TIMEOUT=120`.

---

##### PRO_POWEROFF_TIMEOUT

Legt die Zeit in Minuten fest, nach der der FF5m Pro abgeschaltet wird. (0)

Beispiel: `SAVE_ZMOD_DATA PRO_POWEROFF_TIMEOUT=10`.

---

##### SAVE_MOONRAKER

- 0 - Lädt die Positionen der Makrotasten aus ZMOD (Standard)
- 1 - Ermöglicht das lokale Speichern von Makrotastenänderungen in Fluidd/Moonraker.

Wenn Makros lokal gespeichert werden, werden neue Makros in einem separaten Abschnitt abgelegt.

Beispiel: `SAVE_ZMOD_DATA SAVE_MOONRAKER=1`.

---

##### SAVE_FILAMENT_SENSORS

- 0 - Den Zustand der Filamentsensoren nach dem Neuladen nicht speichern, sie werden immer aktiviert sein (Standard)
- 1 - Zustand der Sensoren nach einem Neustart speichern. Wenn Sie einen Sensor deaktivieren, wird er auch nach dem Neustart deaktiviert.

Beispiel: `SAVE_ZMOD_DATA SAVE_FILAMENT_SENSORS=1`.
