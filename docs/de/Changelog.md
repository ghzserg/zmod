# Changelog

- [Versionsgeschichte](#version-history)
    - [Version 1.6.6](#version-166)
      - [Version 1.6.5](#version-165)
      - [Version 1.6.4](#version-164)
      - [Version 1.6.3](#Version-163)
      - [Version 1.6.2](#Version-162)
      - [Version 1.6.1](#Version-161)
      - [Version 1.6.0](#Version-160)
      - [Version 1.5.4](#Version-154)
      - [Version 1.5.3](#Version-153)
      - [Version 1.5.2](#Version-152)
      - [Version 1.5.1](#Version-151)
      - [Version 1.5.0](#Version-150)
      - [Version 1.4.3](#Version-143)
      - [Version 1.4.2](#Version-142)
      - [Version 1.4.1](#Version-141)
      - [Version 1.4.0](#Version-140)
      - [Version 1.3.1](#Version-131)
      - [Version 1.3.0](#Version-130)
      - [Version 1.1.2](#Version-112)
      - [Version 1.1.1](#Version-111)
      - [Version 1.1.0](#Version-110)
      - [Version 1.0.5](#Version-105)
      - [Version 1.0.4](#Version-104)
      - [Version 1.0.0](#Version-100)
      - [Version 0.2.4](#Version-024)
      - [Version 0.2.3](#Version-023)
      - [Version 0.2.2](#version-022)
      - [Version 0.2.1.1](#version-0211)
      - [Version 0.2.1](#version-021)
      - [Version 0.2.0](#version-020)
      - [Version 0.1.8](#version-018)
      - [Version 0.1.7](#version-017)
      - [Version 0.1.6](#version-016)
      - [Version 0.1.5](#Version-015)
      - [Version 0.1.4](#Version-014)
      - [Version 0.1.3](#Version-013)
      - [Version 0.1.1](#Version-011)
      - [Version 0.0.9-fix](#version-009-fix)
      - [Version 0.0.9](#version-009)

## Versionsgeschichte

### Version 1.6.6
27.01.2026

* Aktualisiert Fluidd/Mainsail/Klipper
* Klipper, Fluidd, Mainsail, Moonraker Updates sind nicht von Mod-Updates abhängig

### Version 1.6.5
14.01.2026

* Fluidd/Mainsail/Klipper aktualisiert
* Zusätzliche Kameraeinstellungen sind verfügbar
* Auto Z-Offset

### Version 1.6.4
11.12.2025

* Verbesserte Benutzerfreundlichkeit bei der Einrichtung und Bedienung
* Aktualisierte Fluidd/Mainsail/Klipper
* Plugin für Benachrichtigungen
* IFS-Knistern entfernt

### Version 1.6.3
25.11.2025 - Jahr der Mod

* [zmod.link](https://zmod.link/link/) [ZLINK](/de/Zmod/#zlink) - Fernverbindung zum Drucker über die Cloud
* Makro [SCREEN](/de/System/#screen) - einen Screenshot des Druckerbildschirms erstellen
* Makro [LOAD_ZOFFSET_NATIVE](/Calibrations/#load_zoffset_native) - Übertragung der Z-Offset-Einstellungen vom nativen Bildschirm in den Nicht-Bildschirm-Modus
* [AD5X](/de/AD5X/): Globaler Parameter [REMOVE_FILAMENT](/de/Global/#remove_filament) hinzugefügt - entfernt Filament nach dem Druck
* Plugin [Empfohlene Einstellungen](https://github.com/ghzserg/recommend) hinzugefügt
* Tschechische Sprache hinzugefügt
* MCU-Versionskontrolle für Klipper 13 hinzugefügt
* [AD5X](/de/AD5X/): Nivellierungsknopf hinzugefügt
* [AD5X](/de/AD5X/): Korrekturen für Klipper 13
* [AD5X](/de/AD5X/): Fix für Düsenreinigung
* [AD5X](/de/AD5X/): IFS-Crunch entfernt
* ```CAMERA_ON VIDEO=video99``` - testet alle verfügbaren Kameras
* Prüfen auf Aktualisierungen nach Beendigung des Drucks
* Wenn die Tabelle über Fluidd/Mainsail entfernt wird, werden die Tensils zurückgesetzt. Es ist aber Sache des Benutzers, die Düse zu reinigen und den Tisch vorher aufzuwärmen.
* Fix PURGE_LINE, druckt nicht auf Stützen
* Behobener Kantenstoß beim Nachdrucken
* Behobene Skalen, wenn sie mehrere Tonnen anzeigen
* Behoben: Deaktivierung des Kammerlüfters nach Abschluss des Druckvorgangs
* Behobene Anzeige der verbleibenden Zeit in Guppies für nicht-russische Sprache

### Version 1.6.2
27.10.2025

* [Plugin-Unterstützung](https://github.com/ghzserg/g28_tenz/blob/main/Plugin_ru.md)
* [Plugin g28_tenz](https://github.com/ghzserg/g28_tenz) - Parken der Z-Achse durch Wägezellen
* [Plugin bambufy](https://github.com/function3d/bambufy) - Kompatibel mit Bambu Studio und Orca Slicer, verbessert die Kontrolle des Zuführturms, bietet genaue Zeit- und Materialverbrauchsabschätzung, reduziert Abfall, unterstützt schnelle Farbwechsel und erweiterte Druckfunktionen. Von @function3d.
* [Plugin nopoop](https://github.com/ghzserg/nopoop) - Maximierung der Abfallreduzierung von @ninjamida
* Fluidd: Farbunterstützung
* Mainsail: Colour Support Von @function3d, behebt 404-Fehlerproblem nach Seitenaktualisierung
* Guppy: Farbunterstützung. HA-Integration behoben.
* Automatisches Verbinden von Thumb Drives bei der Arbeit mit Guppy hinzugefügt
* [WiFi](/de/Global/#wifi) kann nun direkt aktiviert werden, ohne den nativen Bildschirm zu benutzen
* [AD5X](/de/AD5X/): Korb- und Filamentabschneideproblem in neueren Revisionen behoben
* [AD5X](/de/AD5X/): Farbunterstützung für Druckwiederherstellung
* [AD5X](/de/AD5X/): Möglichkeit, [eigene Filamenttypen und -farben](/de/AD5X/#7-add-your-own-filament-types) zu erstellen, wenn man ohne einen nativen Bildschirm arbeitet
* Klipper und Monnraker aktualisiert
* Unterstützung für ens160.py von @minicx hinzugefügt
* Portugiesische Sprache hinzugefügt
* Fehlerbehebungen
* Verbesserte Kompatibilität mit den neuesten Versionen der nativen Firmware

### Version 1.6.1
06.09.2025

- [AD5X](/de/AD5X/) - Unterstützung für Klipper 13. [UPDATE_MCU](/de/System/#update_mcu)
- [AD5X](/de/AD5X/) - Kopftemperatursensor
- [AD5X](/de/AD5X/) - Funktioniert ohne eigenen Bildschirm. IFS funktioniert vollständig mit der Einstellung reset amount
- Kleine Korrekturen

### Version 1.6.0
14.08.2025

- AD5M - Unterstützung für Klipper 13. [UPDATE_MCU](/de/System/#update_mcu)
- AD5M - Temperatursensor im Kopf
- Kleine Korrekturen

Dank an [@darksimpson](https://github.com/darksimpson) für die MCU-Unterstützung.

Dank an [@minicx](https://github.com/loss-and-quick/) für die Zehnerunterstützung

### Version 1.5.4
28.06.2025

- AD5X - Ton funktioniert
- AD5X - Wägezellen und Düsenaufprallkontrolle auf dem Tisch funktionieren
- AD5X - Telegramm-Bot funktioniert
- AD5X - Fadensensor funktioniert
- AD5X - PID-Einstellung des Prinetron-Tisches funktioniert
- AD5X - wiederhergestellte Düsenreinigung beim Entfernen der Tischkarte
- AD5X - getestete Mods funktionieren mit Firmware 1.0.9, 1.1.0, 1.1.1
- AD5X - erstellt [Flash-Laufwerk zur Installation des Bildschirms Version 1.0.7 und alle anderen Module Version 1.1.1](/de/Native_FW/)
- AD5x - erstellt [Drucker-Reset-Stick](/de/Native_FW/)
- AD5X - erstellt [Mod-Aktivierungs-Stick, nach nativer Firmware-Aktualisierung](/de/Native_FW/)

### Version 1.5.3
03.06.2025

* Fehler im Klipper [#119](https://github.com/ghzserg/zmod/issues/119) behoben, der die Verwendung von [this](/de/Recomendations/#don't-use-Russian-names-in-object-names) notwendig machte
* Die Düsensteuerung ist nun auch aktiviert, wenn vom Bildschirm aus auf einmal gedruckt wird
* Kleinere kosmetische Korrekturen

### Version 1.5.2
15.05.2025

* Aktualisierte Dokumentationsstruktur dank @TMTYD
* Neues Makro RESTORE_TAR_CONFIG
* Guppy-Anzeige behoben
* **AD5X** HOME Fehlerbehebungen
* Moonraker-Update
* Parkbeschleunigung ändern
* Chinesische Wolken standardmäßig aktiviert

### Version 1.5.1
23.04.2025

- **AD5X**: Unterstützung der Firmware AD5X-1.0.8-1.0.5-20250418
- **AD5X**: Fix _LINE_PURGE
- **AD5X**: Unterstützung für MCU IFS Update
- **AD5X**: Fehlerbehebung MESH_TEST
- **AD5X**: Fehlerbehebung _SMART_PARK
- **AD5X**: Fehlerbehebung driver_fan
- **AD5X**: korrigiert _HOME
- Kosmetische Korrekturen CHECK_MD5
- Rückgabe von chamber_fan an Moonraker
- Fix Objekt-Ausschluss
- Fix guppyscreen für verschiedene Sprachen

### Version 1.5.0
17.04.2025
Unterstützung für Interface-Sprachen:

- ZMOD - Englisch, Deutsch, Französisch, Italienisch, Spanisch, Chinesisch, Japanisch, Japanisch, Koreanisch
- GuppyScreen - Englisch, Deutsch, Französisch, Italienisch, Spanisch

### Version 1.4.3
23.03.2025

- Automatische Einstellung der Webkamera
- Wenn das WEB-Interface gewechselt wird, wird folgende Meldung angezeigt
- 5X. Fehler beim schnellen Schließen von Dialogen behoben
- 5X. Parken behoben
- Problem mit der Bildschirmabschaltung bei neuen Druckerrevisionen behoben

### Version 1.4.2
19.03.2025

- Verbesserte [Düsenaufprallkontrolle](/de/Global/#nozzle_control) Funktionalität, Sie können nun [Pause](/de/Global/#nozzle_control) verwenden, anstatt den Drucker abzuschalten. Aufgabe [#23](https://github.com/ghzserg/zmod/issues/23)
- Die Systemprüfungsfunktion wurde verbessert.
- Das Fluidd-Farbschema wurde geändert.
- Globaler Parameter [SAVE_MOONRAKER](/de/Macros/#save_moonraker) hinzugefügt - erlaubt die Verwendung benutzerdefinierter Makro-Schaltflächen.
- GuppyScreen funktioniert in AD5X
- In AD5X neues Makro [COLOR](/de/Filament/#color) Steuerung des Kunststofftyps, der Kunststofffarbe, des Ladens und Entladens des Filaments von farbigen Spulen.
- Geänderter Algorithmus für den Tabellentest vor dem Drucken, neuer globaler Parameter [MESH_TEST](/de/Macros/#mesh_test) eingeführt
- Fehler [#13](https://github.com/ghzserg/zmod/issues/13) behoben (Drucken in der Luft nach KAMP)
- Fehler [#14](https://github.com/ghzserg/zmod/issues/14) behoben (Drucken auf nativem Bildschirm wiederherstellen)
- Fehler behoben [#31](https://github.com/ghzserg/zmod/issues/27) (Einfrieren im GuppyScreen)
- Fehler [#25](https://github.com/ghzserg/zmod/issues/25) behoben (AD5X. Tabellenkalibrierung funktioniert nicht richtig)
- Fehler [#26](https://github.com/ghzserg/zmod/issues/26) behoben (AD5X. Kein Gürtelspektrogramm)
- Fehler [#27](https://github.com/ghzserg/zmod/issues/27) behoben (AD5X. Installer-Fehler)

### Version 1.4.1
09.03.2025

- MD5-Summe der entpackten Dateien wird bei der Installation von zMod überprüft. Drucker beschädigt periodisch Dateien beim Kopieren von Dateien von einem Flash-Laufwerk in das Dateisystem.
- Das CHECK_SYSTEM-Makro hat eine Selbstüberprüfung des Systems eingeführt
- Die Schaltfläche zum Herunterfahren funktioniert in der Pro-Version
- Möglichkeit, nicht MJPEG-Kameras zu installieren
- Alpha-Unterstützung für FF5X:
  Bekannte Funktionen:

  - Keine Entware, daher funktionieren NEW_SAVE_CONFIG und CLOSE_DIALOGS nicht
      - Spielt keine Musik ab
      - Keine PID-Tabellen-Kalibrierung, da es dort keine PID gibt
      - Beim Aktivieren der Kamera muss VIDEO3 angegeben werden
      - Keine Wägezellen, daher kein Tabellenschutz und keine Rückstellung der Wägezellen.
      - Kein Filament-Bewegungssensor vom Clipper verfügbar

### Version 1.4.0
04.03.2025

- Moonraker, Fluidd, Python aktualisiert
- [Druck bei Stromausfall wiederherstellen](/de/Zmod/#zrestore)
- Gürtel-Spektrogramm erstellen](/de/Macros/#belts_shaper_calibration)
- Überprüfung der geladenen Platte, prüft, ob die Tabelle ungefähr mit der aktuell geladenen Platte übereinstimmt
- Implementierte Arbeit mit [filament motion sensor](/de/Macros/#motion_sensor)
- GuppyScreen: Objektausschluss, Fehlerausgabe, Firmware-Rollback, PID-Kalibrierung, Gewichtsrücksetzung, Arbeit mit FF5M Pro
- Makro auf [nächste Ebene](/de/Macros/#set_pause_next_layer), oder [auf einer bestimmten Ebene](/de/Macros/#set_pause_at_layer) ausführen
- Protokollierung aller nativen Bildschirmmeldungen an Klipper und Antworten auf diese Meldungen
- Geänderter Algorithmus der Shaper-Entfernung, Shaper-Graphen werden unter Berücksichtigung von SCV geplottet
- MUTE-Makro - Stummschaltung vor Neustart
- Neuer Parameter - [Native screen off timeout](/de/System/#display_off_timeout)
- Neue Datei `mod_data/power_off.sh` - ermöglicht das Schreiben von Code, der beim Ausschalten des Druckers ausgeführt wird
- Aktiviertes intelligentes Parken bei Verwendung von KAMP
- Fehler beim Entfernen von Mods, Deaktivieren von Mods und vollständigem Entfernen von Mods behoben
- Vorreinigung behoben
- Kontrolle des Auftreffens der Düse auf dem Tisch behoben. Funktioniert nur während des Druckens.
- Druckkopfbewegung mit Tasten in Fluid/GuppyScreen behoben
- Behobene Pause im nicht-nativen Bildschirmmodus
- KAMP-Betrieb behoben

### Version 1.3.1

- GuppyScreen Verbesserungen: COLDPULL, PID-Steuerung, Firmware-Rückzüge, Shaper-Kalibrierung, Bandkalibrierung, kosmetische Korrekturen
- Die Düsensteuerung funktioniert jetzt nur noch beim Drucken
- RIEMEN_FORMGEBER_KALIBRIERUNG
- Verbesserte Bedienung ohne nativen Bildschirm
- Verbesserte Funktion des langsamen Fensterschließens und NEW_SAVE_CONFIG

### Version 1.3.0
08.02.2025

- Unterstützung [GuppyScreen](/de/System/#display_off)
- Klipper 12, [im Testmodus](/de/Macros/#update_mcu) (standardmäßig deaktiviert). Es funktioniert nicht in ihm: Extruderheizung, Extrudertemperatur, Skalen.
- Ersetzte `dropbear` SSH-Client und SSH-Server mit der aktuellen Version.
- Ersetzte `mjpg_streamer` mit der Version mit Alexander-Patch, reduziert den Speicherverbrauch um 2-4 mal.
- Ausschluss von Objekten von Igor Polunovskiy behoben (jetzt wird die Unterstützung berücksichtigt).
- Shaper-Plotting unter Berücksichtigung von SCV ([square_corner_velocity](https://www.klipper3d.org/Config_Reference.html#printer)) [FIX_SCV](/de/Global/#fix_scv).
- CHECK_SYSTEM](/de/System/#check_system) - Überprüfung von Datei- und Verzeichnisberechtigungen, Linkprüfung und Wiederherstellung hinzugefügt.
- Das Makro SOFT_REMOVE wurde entfernt.
- Moonraker, Fluidd, Mainsail aktualisiert.

### Version 1.1.2
03.02.2025

- Neues Makro [CHECK_SYSTEM](/de/System/#check_system) - Überprüft das Drucker-Betriebssystem auf beschädigte Dateien.
- Neues Makro [NOZZLE_CONTROL](/de/Global/#nozzle_control) - Notabschaltung des Druckers, wenn ein abreißendes Teil oder eine auf den Tisch auftreffende Düse erkannt wird.
- Neues Makro [UPDATE_MCU](/de/Macros/#update_mcu) - Aktualisierung der MCU im Drucker.
- Neues globales Flag [NICE](/de/Macros/#nice) - Setzt die Klipper-Prozesspriorität, 1 ist die niedrigste Priorität, 40 die höchste (20).
- Neues globales Flag [FIX_E0011](/de/System/#fix_e0011) - Behebt den Fehler E0011 sowie `Communication timeout during homing`.
- Säubert das Drucker-Dateisystem von gelöschten Dateien, beschleunigt EMMC.
- Eine Reihe kleinerer Korrekturen

### Version 1.1.1
24.01.2025

- Problem mit der Reihenfolge behoben, wenn der Callback im Button-Handler [#6440](https://github.com/Klipper3d/klipper/pull/6440) von [Alexander K](https://github.com/drA1ex) blockiert ist - jetzt funktioniert [LOAD_CELL_TARE](/de/Macros/#load_cell_tare) wie es sollte.
- Entfernte globale Parameter: `ALTER_CELL_TARE`, `IGNORE_CELL_TARE`, `CELL_WEIGHT`.
- Erhöhtes Timeout für zsend. Zusätzliche Meldungen werden angezeigt.
- G28 parkt jetzt zuerst Z, dann X und Y
- Neues Makro [CAMERA_RESTART](/de/Macros/#camera_restart) - Neustart der alternativen Kamera-Implementierung
- Korrigierter Code zum Abbrechen des Drucks ohne nativen Bildschirm
- Implementierung von EXCLUDE_OBJECT_DEFINE von Igor Polunovskiy
- Bei wiederholtem Druck werden die Motoren nicht abgeschaltet und der Drucker wird nicht neu gestartet, auch wenn dies in den globalen Parametern angegeben ist
- Im Makro [TEST_EMMC](/de/Macros/#test_emmc) wird der Verschleiß der EMMC-Karte angezeigt
- Deaktivierung der chinesischen Wolken behoben

### Version 1.1.0
15.01.2025

- Moonraker aktualisiert
- Moonraker Ladegeschwindigkeit deutlich erhöht
- Versteckte `level_h1`, `level_h2`, `level_h3`, `power_off`, `clear_power_off`, `level_clear`, `check_level_pin_alt`.
- Die Implementierung von Igor Polunovskiy wird verwendet, um Wägezellen im nicht-nativen Bildschirmmodus zurückzusetzen
- Zurücksetzen von Wägezellen, jetzt nur bei erwärmtem Tisch
- Neuer globaler Parameter [ALTER_CELL_TARE](/de/Macros/#alter_cell_tare). Ermöglicht die Umgehung von [Wägezellen-Reset-Fehler](/de/FAQ/#alter_cell_tare error).
- Neuer globaler Parameter [CELL_WEIGHT](/de/Macros/#cell_weight) gibt an, bei welchem Gewicht die Wägezellen nicht kalibriert werden sollen
- Neuer globaler Parameter [CHINA_CLOUD](/de/Global/#china_cloud) - erlaubt es, chinesische Wolken zu deaktivieren.
- Aktualisierung der Druckerkonfiguration neu geschrieben
- In der Pro-Version arbeiten die Gebläse nun korrekt. Die Standard-Winkel sind 165/105
- Die Kühlergeschwindigkeit wird jetzt während der Extruderkalibrierung eingestellt
- Zeit und Zeitzone in Moonraker stimmen jetzt mit der Klipperzeit überein
- Die Registerkarte "Systeminformationen" zeigt die native Firmware-Version an.
- Reduzierte Mod-Gesprächigkeit

### Version 1.0.5
13.01.2025

- Parameter zum Makro [AUTO_REBOOT](/de/Macros/#auto_reboot) hinzugefügt, der einen Neustart der Firmware ermöglicht.
- G28 in Makros wird nur noch bei Bedarf aufgerufen
- Der MD5-Algorithmus wurde fast vollständig geändert. Jetzt funktioniert die MD5-Prüfung von überall und erfordert kein Aufheizen des Tisches oder des Extruders.
- Verbessertes Makro [MEM](/de/Makros/#mem) gibt jetzt den Moonraker-, Klipper- und Shield-Speicher aus und wie SWAP verwendet wird
- Der Klipper-Prozess hat eine höhere Priorität als andere Prozesse
- Der globale Parameter [PRINT_LEVELING](/de/Global/#zshaper) funktioniert nun auch in nicht-nativen Bildschirmen
- Das Makro [BED_LEVEL_SCREWS_TUNE](/de/Calibrations/#bed_level_screws_tune) verwendet nun die Temperatur korrekt.
- Das Makro [TEST_EMMC](/de/Macros/#test_emmc) kann EMMC, USB Flash und RAM testen.
- Swap kann nun auf USB-Flash platziert werden (muss aber nicht)
- Makro [CLEAR_EMMC](/de/System/#clear_emmc) - löscht Logs und/oder GCODEs
- Fehlersuche [E0017](/de/System/#fix_e0017)

### Version 1.0.4
05.01.2025

- Unterstützung [Rollback von Firmware](/de/FAQ/#what-is-rollback-firmware)
- Fehlerbehebung [E0017](/de/System/#fix_e0017)
- Automatisches Einschalten des Treiberblasens, wenn die Motoren eingeschaltet werden. Löst das Problem des Entfernens von Shapern ohne Stock Blowing.
- Neues Makro [TEST_EMMC](/de/Macros/#test_emmc) - Schreibt SIZE MB auf EMMC und die Schreib-Lese-Geschwindigkeit.
- Neues Makro [CLEAR_EMMC](/de/System/#clear_emmc) - Löscht die EMMC.
- Automatischer [Bot-Neustart bei Ausführung über SSH](/de/Macros/#zssh_on)
- [Auto-clean](https://github.com/ghzserg/zmod_ff5m/blob/1.4/telegram/docker-compose.yml) - Videos, die älter als 10 Tage sind, im Bot löschen.
- Setze [gewünschte Zeitzone](https://github.com/ghzserg/zmod_ff5m/blob/1.4/telegram/docker-compose.yml) im Bot
- Automatischer Wechsel von KAMP [LINE_PURGE](/de/Global/#clear) zu _CLEAR2 wenn keine Objekte gefunden
- Korrigierte [SKIP_ZMOD](/de/Macros/#skip_zmod) Operation
- Die Aktualisierung von fluidd/mainsail erfordert jetzt keinen Neustart mehr
- Der Wechsel von fluidd zu mainsail erfordert jetzt keinen Neustart mehr
- Zmod meldet Dateien, wenn darin Bögen verwendet werden
- Skript "adddMD5.sh" korrigiert
- Kühlungssteuerung des Treibers für nicht-native Bildschirmversionen korrigiert
- Automatisches Laden der Schreibtischkarte für nicht-native Bildschirmversionen beim Starten des Druckers

### Version 1.0.0
23.12.2024

- Neues Update- und Installationssystem, jetzt können fast alle Updates über das Netzwerk bezogen werden
- Neuer Makroparameter [CAMERA_ON](/de/Zmod/#camera_on), VIDEO - Videogerät (video0)

### Version 0.2.4
21.12.2024

- ZMOD schreibt automatisch, ob von einem Flash-Laufwerk aktualisiert werden soll - jetzt in roter Farbe
- Wenn die native Entfernung der Bildschirmtabelle verwendet wird (PRINT_LEVELING=1), werden die Parameter FORCE_LEVELING, FORCE_KAMP, SKIP_LEVELING, MESH in START_PRINT ignoriert
- Pause, auch beim Drucken vom Bildschirm in der äußersten rechten Ecke
- PRRECLEAR-Parameter, funktioniert jetzt auch beim Drucken mit Kartenaufbau vom Bildschirm aus
- Geänderter Installationsalgorithmus, nach erfolgreicher Installation ist es jetzt nicht mehr notwendig, den USB-Stick zu entfernen - der Drucker startet sich neu und löscht die Installationsdatei.

### Version 0.2.3
19.12.2024

- ZMOD schreibt automatisch, wenn ein Update von einem USB-Stick notwendig ist.
- Verbessertes Makro [M600](/de/Macros/#m600) - ersetzt Filament durch eine Pause während des Druckens.
- Verbesserte MD5-Kontrolle - zeigt jetzt eine Meldung an, wenn MD5 nicht gefunden wird

### Version 0.2.2
17.12.2024

- Neues Makro [FAST_CLOSE_DIALOGS](/de/Macros/#fast_close_dialogs) - Bewirkt das schnelle Schließen von Dialogen auf dem ursprünglichen Bildschirm. Wird verwendet, um ein Fenster zu schließen, wenn der Druckvorgang beendet ist oder abgebrochen wird. *Damit das schnelle Schließen von Dialogen funktioniert, müssen Sie auf der Registerkarte Einstellungen -> WiFi-Symbol -> Netzwerkmodus -> den Schieberegler "Nur lokale Netzwerke" aktivieren *Implementierung über das Druckerbildschirmmenü: @darksimpson
- Neues Makro [LEVELING_PRINT_FILE](/de/Macros/#leveling_print_file) - Druckt eine Datei mit Table-Map-Plotting vom nativen Bildschirm. *Für LEVELING_PRINT_FILE ist es notwendig, über das Menü des Druckerbildschirms auf die Registerkarte "Einstellungen" -> "WiFi-Symbol" -> "Netzwerkmodus" -> den Schieberegler "Nur lokale Netzwerke "* einzuschalten.
- Neues Makro [COLDPULL](/de/Filament/#coldpull) Coldpull (Düsenreinigung) ohne Gewalt. Implementierung von [dieser Algorithmus](https://t.me/FF_5M_5M_Pro/2836/447172)
- Neue Parameter [SAVE_ZMOD_DATA](/de/Global/#save_zmod_data):
    - [PRINT_LEVELING](/de/Global/#save_zmod_data) - Build Table Map mit nativem Bildschirm bedeutet 0-Nein, 1-Ja (0) bei jedem Druck. *Um die Desktop-Karte vom nativen Bildschirm zu entfernen, gehen Sie auf die Registerkarte "Einstellungen" -> "WiFi-Symbol" -> "Netzwerkmodus" -> schalten Sie den Schieberegler "Nur lokale Netzwerke" über das Menü des Druckerbildschirms ein.
      - USE_KAMP](/de/Global/#save_zmod_data) - ermöglicht die Verwendung der adaptiven Desktopkarte (KAMP) anstelle der vollständigen Desktopkarte 0-nein, 1-ja (0). *Ermöglicht die Verwendung von KAMP, wenn eine Tabellenkarte über das Netzwerk vom nativen Bildschirm übernommen wird.
      - CLOSE_DIALOGS](/de/Global/#save_zmod_data) - schließt Dialoge automatisch, wenn sie fertig sind und wenn der Druck abgebrochen wird 0-nein, 1-ja langsam, 2-ja schnell. *Damit das schnelle Schließen von Dialogen funktioniert, gehen Sie auf die Registerkarte "Einstellungen" -> "WiFi-Symbol" -> "Netzwerkmodus" -> aktivieren Sie den Schieberegler "Nur lokale Netzwerke "* (0) über das Druckerbildschirmmenü.
      - USE_SWAP](/de/Global/#save_zmod_data) - SWAP verwenden 0-nein, 1-ja (1). *Wenn Sie einen nicht gelöteten Prozessor haben, ist SWAP zwingend erforderlich.

#### Version 0.2.1.1
10.12.2024

- Asynchroner Algorithmus für die Wiedergabe von MIDI-Dateien
- Korrektur der Installation
- SHUTDOWN aus dem Hauptmenü behoben
- Neues Skript [addMD5.sh](https://github.com/ghzserg/zmod_ff5m/blob/1.4/addMD5.sh) - md5 Kontrolle für macOS/Linux - danke Alexander
- Neuer Parameter [STOP_MOTOR](/de/Global/#save_zmod_data) - schaltet Motoren nach dem Drucken/Abbrechen nach 25 Sekunden automatisch ab.
- Neuer Parameter [AUTO_REBOOT](/de/Global/#save_zmod_data) - automatischer Neustart des Druckers 1,5 Minuten nach dem Druck.
- Neuer Parameter [PRECLEAR](/de/Global/#save_zmod_data) - verwendet die Düsenvorreinigung in START_PRINT
- Neue Musik: BattleCity, IndianaJones, WeWillRockYou von [@drmax_gc](https://t.me/drmax_gc)

### Version 0.2.1
10.12.2024

- Abrufen eines Shaper-Graphen direkt vom Drucker. Makro [ZSHAPER](/de/Kalibrierungen/#zshaper)
- Fehler beim Arbeiten ohne nativen Bildschirm behoben

### Version 0.2.0
09.12.2024

- Aktualisierung von fluidd/mainsauil
- Hinzufügen von mc, opkg, gdb
- Neustart über fluidd-Topmenü
- Fehlerbehebungen
- Große Überarbeitung des Makros [START_PRINT](/de/Main/#start_print)
- Makro [NEW_SAVE_CONFIG](/de/Macros/#new_save_config) - speichert Änderungen/lädt den Clipper ohne Einfrieren des Bildschirms. @darksimpson's Implementierung
- Makro [CLOSE_DIALOGS](/de/Macros/#close_dialogs) - schließt Fenster, wenn der Druck beendet ist und wenn der Druck abgebrochen wird. Implementierung durch @darksimpson
- Makro [STOP_ZMOD](/de/Macros/#stop_zmod) - Moonraker abschalten
- Makro [START_ZMOD](/de/Macros/#start_zmod) - Moonraker einschalten
- Makro [SAVE_ZMOD_DATA](/de/Global/#save_zmod_data) - ZMOD-Parameter speichern.
    - CLOSE_DIALOGS - Dialoge automatisch schließen, wenn der Druckvorgang beendet ist und abgebrochen wird 0-nein, 1-ja (0)
        - NEW_SAVE_CONFIG - verwendet die Alternative NEW_SAVE_CONFIG bei der PID-Kalibrierung 0-nein, 1-ja (0)
        - LED - LED-Helligkeit beim Einschalten (50)
        - MIDI_ON - spielt MIDI beim Einschalten ("")
        - MIDI_START - MIDI abspielen bei Druckbeginn ("")
        - MIDI_END - Abspielen von MIDI am Ende des Drucks ("")

### Version 0.1.8
04.12.2024

- Unterstützung der Telegram-Bot-Verbindung
- Makro [ZSSH_ON](/de/Macros/#zssh_on) - ZSSH_ON SSH_SERVER SSH_PORT SSH_USER VIDEO_PORT MOON_PORT
- Makro [ZSSH_OFF](/de/Macros/#zssh_off) - SSH-Client ausschalten
- Makro [ZSSH_RESTART](/de/Macros/#zssh_restart) - SSH-Client neu starten

#### Version 0.1.7
03.12.2024

- Viele Makrokorrekturen
- Makro [STOP_ZMOD](/de/Makros/#stop_zmod) - deaktiviert vorübergehend fluidd/mainstaill und moonraker

### Version 0.1.6
02.12.2024

- Speicherort der Logs korrigiert
- Makro [LOAD_CELL_TARE](/de/Macros/#load_cell_tare) behoben
- Makro zur Kalibrierung von Extruder und Tisch-PID behoben
- Makro [CLEAR_NOZZLE](/de/Macros/#CLEAR_NOZZLE) - Düsenreinigung wie in nativer Firmware
- Makros [KAMP](/de/Kalibrierungen/#kamp) extruder_temp=[düse_temperatur_anfängliche_schicht] bed_temp=[bett_temperatur_anfängliche_schicht_single]. Adaptives Tabellenbild mit Düsenreinigung.
- [AUTO_FULL_BED_LEVEL](/de/Kalibrierungen/#auto_full_bed_level) - komplett neu geschriebenes Makro

### Version 0.1.5
30.11.2024

- Großsegel hinzugefügt. Schalten über WEB-Makro
- Makro STOP - schaltet Motoren aus, geschrieben im finalen gcod.
- Makro [ZSHAPER](/de/Kalibrierungen/#zshaper) - kalibriert Shaper und lädt csv-Dateien nach /mod_data in Konfiguration. Weitere Analyse über (https://github.com/theycallmek/Klipper-Input-Shaping-Assistant/releases)
- Makro [LOAD_CELL_TARE](/de/Makros/#load_cell_tare) - Wägezellen zurücksetzen
- Feste Tischkalibrierung. Sie können jetzt Tisch- und Extrudertemperatur für die Kalibrierung einstellen. Standard 120/80
- Bildschirmabschaltung im nicht-nativen Bildschirmmodus behoben. Er schaltet sich nach 4 Minuten ab.

### Version 0.1.4
29.11.2024

- Kamerasteuerung über den Mod hinzugefügt. Erlaubt t Speicher. Und die Arbeit mit der Kamera mit dem Bildschirm aus. Sie können auch die Auflösung der Kamera ändern. (Die Implementierung ist von Pavel Mironov imitiert)
- Fehler im Installer behoben, der in der letzten Version [heater_bed] aus den Konfigurationsdateien löschen konnte
- Geänderte Bilder während der Installation. Implementiert [@drmax_gc](https://t.me/drmax_gc)
- Makros sind kategorisiert und ins Russische übersetzt
- Makro [DATE_GET](/de/Makros/#date_get) - aktuelle Zeit anzeigen
- Makro [DATE_SET](/de/Makros/#date_set) - aktuelle Zeit setzen
- Makro [CAMERA_ON](/de/Zmod/#camera_on) - alternative Kamera-Implementierung verwenden
- Makro [CAMERA_OFF](/de/Macros/#camera_off) - Alternative Kamera-Implementierung deaktivieren

### Version 0.1.3
28.11.2024

- MIDI-Wiedergabe hinzugefügt. Dateien werden in mod_data/midi gespeichert - Zugriff über die Konfigurationsregisterkarte. Dank an [@drmax_gc](https://t.me/drmax_gc)
- Makros [PLAY_MIDI](/de/Makros/#play_midi). Spielt die Melodie PLAY_MIDI FILE=Schmerz-Halt-deinen-Mund.mid
- Makro [SOFT_REMOVE](/de/Makros/#soft_remove). Entfernt nur zMod, lässt audio, md5, root
- Nach dem Update bleiben die Moonraker-Einstellungen erhalten
- Die Benutzereinstellungen für klipper werden nach mod_data/user.cfg verschoben.
- Benutzereinstellungen für moonraker werden nach mod_data/user.moonraker.conf verschoben
- Wenn der Bildschirm ausgeschaltet ist, wird der Text angezeigt, dass der Bildschirm ausgeschaltet ist. Danke @drmax_gc
- Fehler bei der Bettkalibrierung per Makro behoben. Das Bett wärmt sich jetzt auf.
- Fehler bei der Bettkalibrierung per Makro behoben. Das Bett wärmt sich jetzt auf.

### Version 0.1.1
27.11.2024

- Unterstützt den Betrieb mit deaktivierter nativer Anzeige. Dies spart 20 Megabyte RAM. Um diesen Modus zu aktivieren, müssen Sie das Makro DISPLAY_OFF aufrufen. Der Clipper wird neu starten und alternative Konfigurationsdateien verwenden. Es wird empfohlen, die Table Map zu entfernen und mit dem Standardprofil zu speichern. Nach dem Neustart wird der Bildschirm nach 5 Minuten nicht mehr verfügbar sein und die Tabellenkarte aus dem Standardprofil wird geladen.
- Makros [MEM](/de/Makros/#mem) - zeigt an, wie viel Speicher verwendet wird und von welcher Anwendung.
- Makro [DISPLAY_ON](/de/System/#display_on) - setzt den Bildschirm in den Standardmodus zurück, der Drucker wird neu gestartet
- Makro [LED](/de/Makros/#led) - schaltet die Hintergrundbeleuchtung bei 50% ein
- Makro [LED_ON](/de/Makros/#led_on) - schaltet die Hintergrundbeleuchtung auf 100% ein.
- Makro [LED_OFF](/de/Macros/#led_off) - schaltet die Hintergrundbeleuchtung aus

### Version 0.0.9-fix
25.11.2025

- Installationsfehler behoben.

### Version 0.0.9
25.11.2025

- Pause während des Druckens implementiert, wird über den nativen Bildschirm gehandhabt
- Wiederaufnahme des Druckvorgangs nach einer Pause implementiert, wird über den nativen Bildschirm gehandhabt
- Druckabbruch implementiert, wird über den nativen Bildschirm gehandhabt
- REBOOT](/de/Macros/#reboot) - Makro startet den Drucker neu
- SHUTDOWN](/de/Macros/#shutdown) - Makro zum Ausschalten des Druckers
- SKIP_ZMOD](/de/Macros/#skip_zmod) - Makro zum Neustart ohne Moonraker und Fluidd zu starten
- REMOVE_ZMOD](/de/Macros/#remove_zmod) - Makro zum Entfernen von Mods
- Fehler behoben: "Nach einer Pause aufgrund der Aktivierung des Filament-Bewegungssensors wird der Druckvorgang wieder aufgenommen, aber der Druck erfolgt in der Luft etwa 3 Zentimeter über der Stelle, an der er sein sollte".
