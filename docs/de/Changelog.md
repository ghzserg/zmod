# Changelog

??? note "Änderungsprotokolle"

	- [Versionsgeschichte](#änderungsprotokolle-ausführlich)
		- [Version 1.7.5](#version-175)
		- [Version 1.7.4](#version-174)
		- [Version 1.7.3](#version-173)
		- [Version 1.7.2](#version-172)
		- [Version 1.7.1](#version-171)
		- [Version 1.7.0](#version-170)
		- [Version 1.6.6](#version-166)
		- [Version 1.6.5](#version-165)
		- [Version 1.6.4](#version-164)
		- [Version 1.6.3](#version-163)
		- [Version 1.6.2](#version-162)
		- [Version 1.6.1](#version-161)
		- [Version 1.6.0](#version-160)
		- [Version 1.5.4](#version-154)
		- [Version 1.5.3](#version-153)
		- [Version 1.5.2](#version-152)
		- [Version 1.5.1](#version-151)
		- [Version 1.5.0](#version-150)
		- [Version 1.4.3](#version-143)
		- [Version 1.4.2](#version-142)
		- [Version 1.4.1](#version-141)
		- [Version 1.4.0](#version-140)
		- [Version 1.3.1](#version-131)
		- [Version 1.3.0](#version-130)
		- [Version 1.1.2](#version-112)
		- [Version 1.1.1](#version-111)
		- [Version 1.1.0](#version-110)
		- [Version 1.0.5](#version-105)
		- [Version 1.0.4](#version-104)
		- [Version 1.0.0](#version-100)
		- [Version 0.2.4](#version-024)
		- [Version 0.2.3](#version-023)
		- [Version 0.2.2](#version-022)
		- [Version 0.2.1.1](#version-0211)
		- [Version 0.2.1](#version-021)
		- [Version 0.2.0](#version-020)
		- [Version 0.1.8](#version-018)
		- [Version 0.1.7](#version-017)
		- [Version 0.1.6](#version-016)
		- [Version 0.1.5](#version-015)
		- [Version 0.1.4](#version-014)
		- [Version 0.1.3](#version-013)
		- [Version 0.1.1](#version-011)
		- [Version 0.0.9-fix](#version-009-fix)
		- [Version 0.0.9](#version-009)

## Änderungsprotokolle ausführlich

??? note "Version 1.7.5"
	### Version 1.7.5
	28.10.2026

	* Z-Mod: Unterstützung für das 3MF-Format
	* Z-Mod: Beim Drucken von 3MF erfolgt die Farbzuordnung sofort – der [Präprozessor](/de/Global/#force_md5) wird nicht mehr benötigt
	* Z-Mod: Schnelles KAMP – wird automatisch aktiviert und funktioniert ohne den langsamen Objektausschluss. Bei 3MF stehen die KAMP-Daten sofort zur Verfügung, bei G-Code nach dem Scannen der Datei
	* C5Pro: Unterstützung für bis zu 100 Farben in einer Datei mit Zuordnung zu 4 Extrudern
	* Neues Makro [PLUGINS](/de/Global/#plugins) – Menü zur Plugin-Verwaltung
	* Neues Makro [_USER_PREPARE_PRINT](/de/Main/#_user_prepare_print) – wird aufgerufen, bevor die Datei zum Drucken gesendet wird
	* Neuer globaler Parameter [PURGE_ALL_EXTRUDERS](/de/Global/#purge_all_extruders) – Spülen aller verwendeten Extruder beim Druckstart
	* Neuer globaler Parameter [UNUSED_EXTRUDERS_OFF_TIME](/de/Global/#unused_extruders_off_time) – Heizung ungenutzter Extruder nach einer festgelegten Zeit abschalten
	* Der Support-Telegram-Bot [@zmod_help_bot](https://t.me/zmod_help_bot) arbeitet jetzt mit KI
	* Fluidd: Unterstützung für 3MF
	* Mainsail: Unterstützung für 3MF
	* Moonraker: Unterstützung für 3MF
	* Fehlerbehebungen

	**In die Hauptprojekte übernommene Änderungen:**

	* Fluidd: Gruppierung von Aktionsschaltflächen in Prompt-Dialogen [#1977](https://github.com/fluidd-core/fluidd/pull/1977)
	* Mainsail: HEX-Farben im dritten Parameter von Makro-Prompts, gemeinsam mit @function3d [#2687](https://github.com/mainsail-crew/mainsail/pull/2687)
	* OrcaSlicer (kommt in 2.5.0, derzeit in der Beta):
	    * Die Toleranz für die Vereinfachung der Objektausschluss-Konturen ist jetzt eine Benutzereinstellung [#16503](https://github.com/OrcaSlicer/OrcaSlicer/pull/16503)
	    * Toleranz für AD5M/AD5M Pro, AD5X, Creator 5 / 5 Pro auf 0.2 mm gesetzt – weniger Konturpunkte, mehr Objekte auf dem Bett ohne den Fehler „Timer too close“ [#16687](https://github.com/OrcaSlicer/OrcaSlicer/pull/16687)
	    * Nachbearbeitungsskripte werden auf den G-Code in .gcode.3mf angewendet [#16464](https://github.com/OrcaSlicer/OrcaSlicer/pull/16464)
	    * Verschiebung der Bounding Box der ersten Schicht in plate_N.json auf allen Platten außer der ersten behoben [#16860](https://github.com/OrcaSlicer/OrcaSlicer/pull/16860)

??? note "Version 1.7.4"
	### Version 1.7.4
	24.09.2026

	* C5Pro: Alles, was auf dem AD5X läuft, funktioniert auch hier, außer Klipper 13 
	* C5Pro: Modus ohne den Original-Bildschirm hinzugefügt 
	* C5Pro: Kalibrierungen hinzugefügt: Extruder, VFA 
	* C5Pro: Übertragung des Druckerbildschirms 
	* AD5X: Übertragung des Druckerbildschirms 
	* GuppyScreen: Unterstützung für mehrere Extruder


??? note "Version 1.7.3"
	### Version 1.7.3
	09.09.2026

	* Alpha-Unterstützung für Creator 5 / Creator 5 Pro (keine Unterstützung für den Modus ohne nativen Bildschirm und Klipper 13, nicht alle Makros getestet)
	* AD5M: Unterstützung für die native Firmware 5.1.9
	* AD5X: Beschleunigung des Abfragezyklus von @ninjamida

??? note "Version 1.7.2"
	### Version 1.7.2
	16.08.2026

	* Fluidd/Mainsail/Klipper aktualisiert


??? note "Version 1.7.1"
	### Version 1.7.1
	14.05.2026

	* Fluidd/Mainsail/Klipper aktualisiert
	* Automatische Wiederherstellung der GuppyScreen-Konfiguration, wenn der Benutzer sie gelöscht hat
	* Schutz von Klipper vor dem OOM-Killer
	* Konsolenausgabe bei `BED_MESH`-Lade-/Löschvorgängen
	* `dmesg`-Log im Konfigurationsarchiv
	* WLAN-Funktion korrigiert
	* `SAVE_CONFIG...`-Statusanzeige beim Speichern
	* Überwachung auf Hängenbleiben der Wägezellen
	* Druckbett senkt sich bei Pause über den nativen Bildschirm um 5 mm ab
	* Makro `IP` – gibt die IP-Adresse nach dem Start in der Konsole aus
	* Rebranding: `ZMOD` → `Z-Mod`

??? note "Version 1.7.0"
	### Version 1.7.0
	15.03.2026

	* Fluidd/Mainsail/Klipper aktualisiert
	* [NoPoop 2](/de/AD5X/#slicer-gesteuerte-reinigung-purge) von @ninjamida
	* HelixScreen - alternativer Bildschirm. (`ENABLE_EXTRA_PLUGINS`, `DISPLAY_OFF HELIX=1`)
	* Großer Dank für die Unterstützung bei dieser Version geht an @xyzroe

??? note "Version 1.6.6"
	### Version 1.6.6
	27.01.2026
	
	* Fluidd/Mainsail/Klipper aktualisiert
	* Updates von Klipper, Fluidd, Mainsail und Moonraker sind nicht mehr von Mod-Updates abhängig

??? note "Version 1.6.5"
	### Version 1.6.5
	14.01.2026
	
	* Fluidd/Mainsail/Klipper aktualisiert
	* Zusätzliche Kameraeinstellungen sind verfügbar
	* Auto Z-Offset

??? note "Version 1.6.4"
	### Version 1.6.4
	11.12.2025
	
	* Verbesserte Benutzerfreundlichkeit bei der Einrichtung und Bedienung
	* Fluidd/Mainsail/Klipper aktualisiert
	* Plugin für Benachrichtigungen
	* IFS-Knacken behoben

??? note "Version 1.6.3"
	### Version 1.6.3
	25.11.2025 – Z-Mod wird ein Jahr alt!
	
	* [zmod.link](https://zmod.link/link/) [ZLINK](/de/Zmod/#zlink) - Fernverbindung zum Drucker über die Cloud
	* Makro [SCREEN](/de/System/#screen) - einen Screenshot des Druckerbildschirms erstellen
	* Makro [LOAD_ZOFFSET_NATIVE](/de/Calibrations/#load_zoffset_native) - Übertragung der Z-Offset-Einstellungen vom nativen Bildschirm in den Modus ohne nativen Bildschirm
	* [AD5X](/de/AD5X/): Globaler Parameter [REMOVE_FILAMENT](/de/Global/#remove_filament) hinzugefügt - entfernt Filament nach dem Druck
	* Plugin [Empfohlene Einstellungen](https://github.com/ghzserg/recommend) hinzugefügt
	* Tschechische Sprache hinzugefügt
	* MCU-Versionskontrolle für Klipper 13 hinzugefügt
	* [AD5X](/de/AD5X/): Nivellierungsknopf hinzugefügt
	* [AD5X](/de/AD5X/): Korrekturen für Klipper 13
	* [AD5X](/de/AD5X/): Fix für Düsenreinigung
	* [AD5X](/de/AD5X/): IFS-Knacken behoben
	* ```CAMERA_ON VIDEO=video99``` - testet alle verfügbaren Kameras
	* Prüfung auf Updates nach Druckende
	* Beim Messen des Bettnetzes über Fluidd/Mainsail werden die Wägezellen zurückgesetzt. Es ist aber Sache des Benutzers, die Düse zu reinigen und das Bett vorher aufzuwärmen.
	* PURGE_LINE korrigiert: druckt nicht mehr auf Stützen
	* Behoben: Kantenstoß beim erneuten Drucken
	* Behoben: Wägezellen zeigten mehrere Tonnen an
	* Behoben: Deaktivierung des Kammerlüfters nach Abschluss des Druckvorgangs
	* Behoben: Anzeige der Restzeit in Guppy für nicht-russische Sprachen

??? note "Version 1.6.2"
	### Version 1.6.2
	27.10.2025
	
	* [Plugin-Unterstützung](/de/Plugin/)
	* [Plugin g28_tenz](https://github.com/ghzserg/g28_tenz) - Parken der Z-Achse durch Wägezellen
	* [Plugin bambufy](https://github.com/function3d/bambufy) - Kompatibel mit Bambu Studio und Orca Slicer, verbessert die Kontrolle des Reinigungsturms, bietet genaue Zeit- und Materialverbrauchsabschätzung, reduziert Abfall, unterstützt schnelle Farbwechsel und erweiterte Druckfunktionen. Von @function3d.
	* [Plugin nopoop](https://github.com/ghzserg/nopoop) - maximale Abfallreduzierung von @ninjamida
	* Fluidd: Farbunterstützung
	* Mainsail: Farbunterstützung von @function3d, behebt den 404-Fehler nach dem Neuladen der Seite
	* Guppy: Farbunterstützung. HA-Integration behoben.
	* Automatisches Einbinden von USB-Sticks bei der Arbeit mit Guppy hinzugefügt
	* [WiFi](/de/Global/#wifi) kann nun direkt aktiviert werden, ohne den nativen Bildschirm zu benutzen
	* [AD5X](/de/AD5X/): Probleme mit Abfallbehälter und Filamentschneider in neueren Revisionen behoben
	* [AD5X](/de/AD5X/): Farbunterstützung für Druckwiederherstellung
	* [AD5X](/de/AD5X/): Möglichkeit, [eigene Filamenttypen und -farben](/de/AD5X/#7-filamenttypen-hinzufügen-oder-entfernen) zu erstellen, wenn man ohne einen nativen Bildschirm arbeitet
	* Klipper und Moonraker aktualisiert
	* Unterstützung für ens160.py von @minicx hinzugefügt
	* Portugiesische Sprache hinzugefügt
	* Fehlerbehebungen
	* Verbesserte Kompatibilität mit den neuesten Versionen der nativen Firmware

??? note "Version 1.6.1"
	### Version 1.6.1
	06.09.2025
	
	- [AD5X](/de/AD5X/) - Unterstützung für Klipper 13. [UPDATE_MCU](/de/System/#update_mcu)
	- [AD5X](/de/AD5X/) - Temperatursensor im Kopf
	- [AD5X](/de/AD5X/) - Funktioniert ohne nativen Bildschirm. IFS funktioniert vollständig, mit einstellbarer Spülmenge
	- Kleine Korrekturen

??? note "Version 1.6.0"
	### Version 1.6.0
	14.08.2025
	
	- AD5M - Unterstützung für Klipper 13. [UPDATE_MCU](/de/System/#update_mcu)
	- AD5M - Temperatursensor im Kopf
	- Kleine Korrekturen
	
	Dank an [@darksimpson](https://github.com/darksimpson) für die MCU-Unterstützung.
	
	Dank an [@minicx](https://github.com/loss-and-quick/) für die Unterstützung der Wägezellen

??? note "Version 1.5.4"
	### Version 1.5.4
	28.06.2025

	- AD5X - Ton funktioniert
	- AD5X - Wägezellen und Düsenaufprallkontrolle auf das Bett funktionieren
	- AD5X - Telegram-Bot funktioniert
	- AD5X - Filamentsensor funktioniert
	- AD5X - Bett-PID-Kalibrierung funktioniert
	- AD5X - wiederhergestellte Düsenreinigung beim Messen des Bettnetzes
	- AD5X - Mod mit Firmware 1.0.9, 1.1.0, 1.1.1 getestet
	- AD5X - erstellt: [USB-Stick zur Installation des Bildschirms Version 1.0.7 und aller anderen Module Version 1.1.1](/de/Native_FW/)
	- AD5X - erstellt: [USB-Stick zum Zurücksetzen des Druckers auf Werkseinstellungen](/de/Native_FW/)
	- AD5X - erstellt: [USB-Stick zur Aktivierung des Mods nach einem Update der nativen Firmware](/de/Native_FW/)

??? note "Version 1.5.3"
	### Version 1.5.3
	03.06.2025
	
	* Fehler im Klipper [#119](https://github.com/ghzserg/zmod/issues/119) behoben, wegen dem man auf nicht-lateinische Zeichen in Objektnamen verzichten musste
	* Die Düsenkontrolle ist nun auch beim Drucken vom Bildschirm aktiv
	* Kleinere kosmetische Korrekturen

??? note "Version 1.5.2"
	### Version 1.5.2
	15.05.2025
	
	* Aktualisierte Dokumentationsstruktur dank @TMTYD
	* Neues Makro RESTORE_TAR_CONFIG
	* Guppy-Anzeige behoben
	* **AD5X** HOME Fehlerbehebungen
	* Moonraker-Update
	* Beschleunigung beim Parken geändert
	* Chinesische Cloud-Dienste standardmäßig aktiviert

??? note "Version 1.5.1"
	### Version 1.5.1
	23.04.2025

	- **AD5X**: Unterstützung der Firmware AD5X-1.0.8-1.0.5-20250418
	- **AD5X**: Fix _LINE_PURGE
	- **AD5X**: Unterstützung für das Update der IFS-MCU
	- **AD5X**: Fehlerbehebung MESH_TEST
	- **AD5X**: Fehlerbehebung _SMART_PARK
	- **AD5X**: Fehlerbehebung driver_fan
	- **AD5X**: _HOME korrigiert
	- Kosmetische Korrekturen an CHECK_MD5
	- chamber_fan wieder an Moonraker übergeben
	- Objektausschluss korrigiert
	- GuppyScreen für verschiedene Sprachen korrigiert

??? note "Version 1.5.0"
	### Version 1.5.0
	17.04.2025
	Unterstützung für Oberflächensprachen:
	
	- Z-Mod - Englisch, Deutsch, Französisch, Italienisch, Spanisch, Chinesisch, Japanisch, Koreanisch
	- GuppyScreen - Englisch, Deutsch, Französisch, Italienisch, Spanisch

??? note "Version 1.4.3"
	### Version 1.4.3
	23.03.2025
	
	- Automatische Einrichtung der Webkamera
	- Beim Wechsel der Weboberfläche wird eine Meldung mit den nächsten Schritten angezeigt
	- 5X. Fehler beim schnellen Schließen von Dialogen behoben
	- 5X. Parken behoben
	- Problem mit der Bildschirmabschaltung bei neuen Druckerrevisionen behoben

??? note "Version 1.4.2"
	### Version 1.4.2
	19.03.2025
	
	- Verbesserte [Düsenaufprallkontrolle](/de/Global/#nozzle_control): Statt den Drucker abzuschalten, kann nun eine [Pause](/de/Global/#nozzle_control) verwendet werden. Aufgabe [#23](https://github.com/ghzserg/zmod/issues/23)
	- Die Systemprüfungsfunktion wurde verbessert.
	- Das Fluidd-Farbschema wurde geändert.
	- Globaler Parameter [SAVE_MOONRAKER](/de/Global/#save_moonraker) hinzugefügt - ermöglicht eine eigene Anordnung der Makro-Schaltflächen.
	- GuppyScreen funktioniert auf dem AD5X
	- Neues Makro [COLOR](/de/Filament/#color) für den AD5X: Steuerung des Kunststofftyps, der Kunststofffarbe, des Ladens und Entladens des Filaments von farbigen Spulen.
	- Geänderter Algorithmus für den Betttest vor dem Drucken, neuer globaler Parameter [MESH_TEST](/de/Global/#mesh_test) eingeführt
	- Fehler [#13](https://github.com/ghzserg/zmod/issues/13) behoben (Drucken in der Luft nach KAMP)
	- Fehler [#14](https://github.com/ghzserg/zmod/issues/14) behoben (Druckwiederherstellung auf dem nativen Bildschirm)
	- Fehler behoben [#31](https://github.com/ghzserg/zmod/issues/31) (Einfrieren im GuppyScreen)
	- Fehler [#25](https://github.com/ghzserg/zmod/issues/25) behoben (AD5X. Bettkalibrierung funktioniert nicht richtig)
	- Fehler [#26](https://github.com/ghzserg/zmod/issues/26) behoben (AD5X. Kein Riemenspektrogramm)
	- Fehler [#27](https://github.com/ghzserg/zmod/issues/27) behoben (AD5X. Installer-Fehler)

??? note "Version 1.4.1"
	### Version 1.4.1
	09.03.2025
	
	- MD5-Summe der entpackten Dateien wird bei der Installation von Z-Mod überprüft. Der Drucker beschädigt gelegentlich Dateien beim Kopieren vom USB-Stick in das Dateisystem.
	- Das Makro CHECK_SYSTEM enthält jetzt eine Selbstprüfung des Systems
	- Die Schaltfläche zum Herunterfahren funktioniert in der Pro-Version
	- Kameras ohne MJPEG können verwendet werden
	- Alpha-Unterstützung für FF5X:
	Bekannte Besonderheiten:
	
	- Keine Entware, daher funktionieren NEW_SAVE_CONFIG und CLOSE_DIALOGS nicht
	- Spielt keine Musik ab
	- Keine Bett-PID-Kalibrierung, da das Bett nicht über PID geregelt wird
	- Beim Aktivieren der Kamera muss VIDEO3 angegeben werden
	- Keine Wägezellen, daher kein Bettschutz und keine Rückstellung der Wägezellen.
	- Kein Filamentbewegungssensor in Klipper verfügbar

??? note "Version 1.4.0"
	### Version 1.4.0
	04.03.2025
	
	- Moonraker, Fluidd, Python aktualisiert
	- [Druckwiederherstellung nach Stromausfall](/de/Zmod/#zrestore)
	- [Riemen-Spektrogramm erstellen](/de/Macros/#belts_shaper_calibration)
	- Prüfung der eingelegten Platte: prüft, ob das Bettnetz ungefähr mit der aktuell geladenen Platte übereinstimmt
	- Unterstützung für den [Filamentbewegungssensor](/de/Global/#motion_sensor)
	- GuppyScreen: Objektausschluss, Fehlerausgabe, Firmware-Retraktion, PID-Kalibrierung, Reset der Wägezellen, Unterstützung für FF5M Pro
	- Makro in der [nächsten Schicht](/de/Macros/#set_pause_next_layer) oder [in einer bestimmten Schicht](/de/Macros/#set_pause_at_layer) ausführen
	- Protokollierung aller Meldungen des nativen Bildschirms an Klipper und der Antworten darauf
	- Geänderter Algorithmus der Shaper-Kalibrierung; Shaper-Grafiken berücksichtigen SCV
	- Makro MUTE - Ton bis zum Neustart stummschalten
	- Neuer Parameter - [Ausschaltzeit des nativen Bildschirms](/de/Global/#display_off_timeout)
	- Neue Datei `mod_data/power_off.sh` - ermöglicht das Schreiben von Code, der beim Ausschalten des Druckers ausgeführt wird
	- Intelligentes Parken bei Verwendung von KAMP aktiviert
	- Fehler beim Entfernen, Deaktivieren und vollständigen Entfernen des Mods behoben
	- Vorreinigung behoben
	- Kontrolle des Auftreffens der Düse auf das Bett behoben. Funktioniert nur während des Druckens.
	- Druckkopfbewegung mit Tasten in Fluidd/GuppyScreen behoben
	- Pause im Modus ohne nativen Bildschirm behoben
	- KAMP-Betrieb behoben

??? note "Version 1.3.1"
	### Version 1.3.1
	
	- GuppyScreen-Verbesserungen: COLDPULL, PID-Steuerung, Firmware-Retraktion, Shaper-Kalibrierung, Riemenkalibrierung, kosmetische Korrekturen
	- Die Düsenkontrolle funktioniert jetzt nur noch beim Drucken
	- BELTS_SHAPER_CALIBRATION
	- Verbesserte Bedienung ohne nativen Bildschirm
	- Verbesserte Funktion des langsamen Fensterschließens und NEW_SAVE_CONFIG

??? note "Version 1.3.0"
	### Version 1.3.0
	08.02.2025
	
	- Unterstützung für [GuppyScreen](/de/System/#display_off)
	- Klipper 12, [im Testmodus](/de/Macros/#update_mcu) (standardmäßig deaktiviert). Darin funktionieren nicht: Extruderheizung, Extrudertemperatur, Wägezellen.
	- SSH-Client und SSH-Server `dropbear` durch die aktuelle Version ersetzt.
	- `mjpg_streamer` durch die Version mit Alexanders Patch ersetzt, die den Speicherverbrauch um das 2- bis 4-Fache senkt.
	- Ausschluss von Objekten von Igor Polunovskiy behoben (jetzt werden Stützen berücksichtigt).
	- Shaper-Grafiken berücksichtigen SCV ([square_corner_velocity](https://www.klipper3d.org/Config_Reference.html#printer)) [FIX_SCV](/de/Global/#fix_scv).
	- [CHECK_SYSTEM](/de/System/#check_system) - Überprüfung von Datei- und Verzeichnisberechtigungen, Linkprüfung und Wiederherstellung hinzugefügt.
	- Das Makro SOFT_REMOVE wurde entfernt.
	- Moonraker, Fluidd, Mainsail aktualisiert.

??? note "Version 1.1.2"
	### Version 1.1.2
	03.02.2025
	
	- Neues Makro [CHECK_SYSTEM](/de/System/#check_system) - Überprüft das Drucker-Betriebssystem auf beschädigte Dateien.
	- Neues Makro [NOZZLE_CONTROL](/de/Global/#nozzle_control) - Notabschaltung des Druckers, wenn sich ein Teil löst oder die Düse auf das Bett trifft.
	- Neues Makro [UPDATE_MCU](/de/Macros/#update_mcu) - Aktualisierung der MCU im Drucker.
	- Neues globales Flag [NICE](/de/Global/#nice) - Setzt die Klipper-Prozesspriorität, 1 ist die niedrigste Priorität, 40 die höchste (20).
	- Neues globales Flag [FIX_E0011](/de/Global/#fix_e0011) - Behebt den Fehler E0011 sowie `Communication timeout during homing`.
	- Bereinigung gelöschter Dateien im Dateisystem des Druckers beschleunigt die EMMC.
	- Eine Reihe kleinerer Korrekturen

??? note "Version 1.1.1"
	### Version 1.1.1
	24.01.2025
	
	- Problem mit der Reihenfolge behoben, wenn ein Callback im Button-Handler blockiert [#6440](https://github.com/Klipper3d/klipper/pull/6440), gefunden von [Alexander K](https://github.com/drA1ex) - jetzt funktioniert [LOAD_CELL_TARE](/de/Macros/#load_cell_tare) wie es sollte.
	- Entfernte globale Parameter: `ALTER_CELL_TARE`, `IGNORE_CELL_TARE`, `CELL_WEIGHT`.
	- Erhöhtes Timeout für zsend. Zusätzliche Meldungen werden angezeigt.
	- G28 parkt jetzt zuerst Z, dann X und Y
	- Neues Makro [CAMERA_RESTART](/de/Macros/#camera_restart) - Neustart der alternativen Kamera-Implementierung
	- Korrigierter Code zum Abbrechen des Drucks ohne nativen Bildschirm
	- Implementierung von EXCLUDE_OBJECT_DEFINE von Igor Polunovskiy
	- Bei wiederholtem Druck werden die Motoren nicht abgeschaltet und der Drucker wird nicht neu gestartet, auch wenn dies in den globalen Parametern angegeben ist
	- Das Makro [TEST_EMMC](/de/Macros/#test_emmc) zeigt den Verschleiß der EMMC an
	- Deaktivierung der chinesischen Cloud-Dienste behoben

??? note "Version 1.1.0"
	### Version 1.1.0
	15.01.2025
	
	- Moonraker aktualisiert
	- Moonraker startet deutlich schneller
	- Versteckte `level_h1`, `level_h2`, `level_h3`, `power_off`, `clear_power_off`, `level_clear`, `check_level_pin_alt`.
	- Die Implementierung von Igor Polunovskiy wird verwendet, um Wägezellen im Modus ohne nativen Bildschirm zurückzusetzen
	- Zurücksetzen von Wägezellen, jetzt nur bei erwärmtem Bett
	- Neuer globaler Parameter `ALTER_CELL_TARE`. Ermöglicht die Umgehung des Wägezellen-Reset-Fehlers.
	- Neuer globaler Parameter `CELL_WEIGHT` gibt an, bei welchem Gewicht die Wägezellen nicht kalibriert werden sollen
	- Neuer globaler Parameter [CHINA_CLOUD](/de/Global/#china_cloud) - erlaubt es, chinesische Cloud-Dienste zu deaktivieren.
	- Aktualisierung der Druckerkonfiguration neu geschrieben
	- In der Pro-Version arbeiten die Kammerlüfter nun korrekt. Die Standard-Winkel sind 165/105
	- Die Lüfterdrehzahl wird jetzt bei der Extruderkalibrierung eingestellt
	- Zeit und Zeitzone in Moonraker stimmen jetzt mit der Klipperzeit überein
	- Die Registerkarte „Systeminformationen“ zeigt die Version der nativen Firmware an.
	- Der Mod ist weniger gesprächig

??? note "Version 1.0.5"
	### Version 1.0.5
	13.01.2025
	
	- Parameter zum Makro [AUTO_REBOOT](/de/Global/#auto_reboot) hinzugefügt, der einen Neustart der Firmware ermöglicht.
	- G28 in Makros wird nur noch bei Bedarf aufgerufen
	- Der MD5-Algorithmus wurde fast vollständig geändert. Jetzt funktioniert die MD5-Prüfung von überall und erfordert kein Aufheizen des Bettes oder des Extruders.
	- Verbessertes Makro [MEM](/de/Macros/#mem): gibt jetzt den Speicher von Moonraker, Klipper und Bildschirm aus sowie die SWAP-Nutzung

	- Der Klipper-Prozess hat eine höhere Priorität als andere Prozesse
	- Der globale Parameter [PRINT_LEVELING](/de/Global/#print_leveling) funktioniert nun auch im Modus ohne nativen Bildschirm
	- Das Makro [BED_LEVEL_SCREWS_TUNE](/de/Calibrations/#bed_level_screws_tune) verwendet nun die Temperatur korrekt.
	- Das Makro [TEST_EMMC](/de/Macros/#test_emmc) kann EMMC, USB Flash und RAM testen.
	- Swap kann nun auf USB-Flash platziert werden (muss aber nicht)
	- Makro [CLEAR_EMMC](/de/System/#clear_emmc) - löscht Logs und/oder GCODEs
	- Behebung von [E0017](/de/Global/#fix_e0017)

??? note "Version 1.0.4"
	### Version 1.0.4
	05.01.2025
	
	- Unterstützung für [Firmware-Retraktion](/de/FAQ/#was-ist-ein-firmware-rückzug)
	- Fehlerbehebung [E0017](/de/Global/#fix_e0017)
	- Treiberlüfter schalten sich automatisch ein, wenn die Motoren aktiviert werden. Löst das Problem der Shaper-Kalibrierung ohne Treiberkühlung im Stock.
	- Neues Makro [TEST_EMMC](/de/Macros/#test_emmc) - schreibt SIZE MB auf die EMMC und gibt die Lese-/Schreibgeschwindigkeit aus.
	- Neues Makro [CLEAR_EMMC](/de/System/#clear_emmc) - Löscht die EMMC.
	- Automatischer [Bot-Neustart bei Ausführung über SSH](/de/Macros/#zssh_on)
	- [Auto-clean](https://github.com/ghzserg/zmod_ff5m/blob/1.4/telegram/docker-compose.yml) - von Videos im Bot, die älter als 10 Tage sind.
	- Einstellen der [gewünschten Zeitzone](https://github.com/ghzserg/zmod_ff5m/blob/1.4/telegram/docker-compose.yml) im Bot
	- Automatischer Wechsel von KAMP [LINE_PURGE](/de/Global/#clear) zu _CLEAR2, wenn keine Objekte gefunden werden
	- [SKIP_ZMOD](/de/Macros/#skip_zmod) korrigiert
	- Die Aktualisierung von Fluidd/Mainsail erfordert jetzt keinen Neustart mehr
	- Der Wechsel von Fluidd zu Mainsail erfordert jetzt keinen Neustart mehr
	- Z-Mod meldet Dateien, die Bögen verwenden
	- Skript "addMD5.sh" korrigiert
	- Steuerung der Treiberkühlung im Modus ohne nativen Bildschirm korrigiert
	- Im Modus ohne nativen Bildschirm wird beim Start des Druckers das Bettnetz `auto` geladen

??? note "Version 1.0.0"
	### Version 1.0.0
	23.12.2024
	
	- Neues Update- und Installationssystem; jetzt können fast alle Updates über das Netzwerk bezogen werden
	- Neuer Makroparameter [CAMERA_ON](/de/Zmod/#camera_on), VIDEO - Videogerät (video0)

??? note "Version 0.2.4"
	### Version 0.2.4
	21.12.2024
	
	- Z-Mod meldet automatisch, ob ein Update per USB-Stick nötig ist – jetzt in Rot
	- Wenn das Bettnetz über den nativen Bildschirm gemessen wird (PRINT_LEVELING=1), werden die Parameter FORCE_LEVELING, FORCE_KAMP, SKIP_LEVELING, MESH in START_PRINT ignoriert
	- Pause in der hinteren rechten Ecke, auch beim Drucken vom Bildschirm
	- Der Parameter PRECLEAR funktioniert jetzt auch beim Drucken mit Bettnetz-Messung vom Bildschirm
	- Geänderter Installationsablauf: Nach erfolgreicher Installation ist es jetzt nicht mehr notwendig, den USB-Stick zu entfernen - der Drucker startet sich neu und löscht die Installationsdatei.

??? note "Version 0.2.3"
	### Version 0.2.3
	19.12.2024
	
	- Z-Mod meldet automatisch, wenn ein Update per USB-Stick nötig ist.
	- Verbessertes Makro [M600](/de/Filament/#m600) - Filamentwechsel mit Pause während des Drucks.
	- Verbesserte MD5-Kontrolle - zeigt jetzt eine Meldung an, wenn MD5 nicht gefunden wird

??? note "Version 0.2.2"
	### Version 0.2.2
	17.12.2024
	
	- Neues Makro [FAST_CLOSE_DIALOGS](/de/Macros/#fast_close_dialogs) - schnelles Schließen von Dialogen auf dem nativen Bildschirm, am Ende oder beim Abbruch des Drucks. *Damit das schnelle Schließen funktioniert, aktivieren Sie im Menü des Druckerbildschirms unter „Einstellungen“ -> „WLAN-Symbol“ -> „Netzwerkmodus“ den Schieberegler „Nur lokale Netzwerke“.* Implementierung: @darksimpson
	- Neues Makro `LEVELING_PRINT_FILE` - Druckt eine Datei mit Bettnetz-Messung durch den nativen Bildschirm. *Für LEVELING_PRINT_FILE aktivieren Sie im Menü des Druckerbildschirms unter „Einstellungen“ -> „WLAN-Symbol“ -> „Netzwerkmodus“ den Schieberegler „Nur lokale Netzwerke“.*
	- Neues Makro [COLDPULL](/de/Filament/#coldpull) - Cold Pull (Düsenreinigung) ohne Kraftaufwand. Umsetzung [dieses Algorithmus](https://t.me/FF_5M_5M_Pro/2836/447172)
	- Neue Parameter [SAVE_ZMOD_DATA](/de/Global/#save_zmod_data):
	    - [PRINT_LEVELING](/de/Global/#save_zmod_data) - bei jedem Druck das Bettnetz mit dem nativen Bildschirm messen 0-nein, 1-ja (0). *Für die Messung über den nativen Bildschirm aktivieren Sie unter „Einstellungen“ -> „WLAN-Symbol“ -> „Netzwerkmodus“ den Schieberegler „Nur lokale Netzwerke“.*
	    - [USE_KAMP](/de/Global/#save_zmod_data) - wo möglich, adaptives Bettnetz (KAMP) statt des vollständigen verwenden 0-nein, 1-ja (0). *Ermöglicht KAMP, wenn das Bettnetz über das Netzwerk vom nativen Bildschirm gemessen wird.*
	    - [CLOSE_DIALOGS](/de/Global/#save_zmod_data) - Dialoge am Ende und beim Abbruch des Drucks automatisch schließen 0-nein, 1-ja langsam, 2-ja schnell. *Für das schnelle Schließen aktivieren Sie unter „Einstellungen“ -> „WLAN-Symbol“ -> „Netzwerkmodus“ den Schieberegler „Nur lokale Netzwerke“* (0).
	    - [USE_SWAP](/de/Global/#save_zmod_data) - SWAP verwenden 0-nein, 1-ja (1). *Wenn Ihr Prozessor nicht umgelötet ist, ist SWAP zwingend erforderlich.*

??? note "Version 0.2.1.1"
	### Version 0.2.1.1
	10.12.2024
	
	- Asynchroner Algorithmus für die Wiedergabe von MIDI-Dateien
	- Korrektur der Installation
	- SHUTDOWN aus dem Hauptmenü behoben
	- Neues Skript [addMD5.sh](https://github.com/ghzserg/zmod_ff5m/blob/1.4/addMD5.sh) - MD5-Kontrolle für macOS/Linux – danke an Alexander
	- Neuer Parameter [STOP_MOTOR](/de/Global/#save_zmod_data) - schaltet die Motoren 25 Sekunden nach Druckende/-abbruch automatisch ab.
	- Neuer Parameter [AUTO_REBOOT](/de/Global/#save_zmod_data) - automatischer Neustart des Druckers 1,5 Minuten nach dem Druck.
	- Neuer Parameter [PRECLEAR](/de/Global/#save_zmod_data) - verwendet die Düsenvorreinigung in START_PRINT
	- Neue Musik: BattleCity, IndianaJones, WeWillRockYou von [@drmax_gc](https://t.me/drmax_gc)

??? note "Version 0.2.1"
	### Version 0.2.1
	10.12.2024
	
	- Shaper-Grafiken direkt vom Drucker. Makro [ZSHAPER](/de/Calibrations/#zshaper)
	- Fehler beim Arbeiten ohne nativen Bildschirm behoben

??? note "Version 0.2.0"
	### Version 0.2.0
	09.12.2024
	
	- Fluidd/Mainsail aktualisiert
	- mc, opkg, gdb hinzugefügt
	- Neustart über das obere Menü von Fluidd
	- Fehlerbehebungen
	- Große Überarbeitung des Makros [START_PRINT](/de/Main/#start_print)
	- Makro [NEW_SAVE_CONFIG](/de/Macros/#new_save_config) - Änderungen speichern/Klipper neu starten, ohne dass der native Bildschirm einfriert. Implementierung: @darksimpson
	- Makro [CLOSE_DIALOGS](/de/Macros/#close_dialogs) - schließt Fenster, wenn der Druck beendet ist und wenn der Druck abgebrochen wird. Implementierung durch @darksimpson
	- Makro [STOP_ZMOD](/de/Macros/#stop_zmod) - Moonraker abschalten
	- Makro [START_ZMOD](/de/Macros/#start_zmod) - Moonraker einschalten
	- Makro [SAVE_ZMOD_DATA](/de/Global/#save_zmod_data) - Z-Mod-Parameter speichern.
	    - CLOSE_DIALOGS - Dialoge am Ende und beim Abbruch des Drucks automatisch schließen 0-nein, 1-ja (0)
	    - NEW_SAVE_CONFIG - alternatives NEW_SAVE_CONFIG bei der PID-Kalibrierung verwenden 0-nein, 1-ja (0)
	    - LED - LED-Helligkeit beim Einschalten (50)
	    - MIDI_ON - MIDI beim Einschalten abspielen ("")
	    - MIDI_START - MIDI zu Druckbeginn abspielen ("")
	    - MIDI_END - MIDI am Ende des Drucks abspielen ("")

??? note "Version 0.1.8"
	### Version 0.1.8
	04.12.2024
	
	- Unterstützung für die Anbindung eines Telegram-Bots
	- Makro [ZSSH_ON](/de/Macros/#zssh_on) - ZSSH_ON SSH_SERVER SSH_PORT SSH_USER VIDEO_PORT MOON_PORT
	- Makro [ZSSH_OFF](/de/Macros/#zssh_off) - SSH-Client ausschalten
	- Makro [ZSSH_RESTART](/de/Macros/#zssh_restart) - SSH-Client neu starten

??? note "Version 0.1.7"
	### Version 0.1.7
	03.12.2024
	
	- Viele Makrokorrekturen
	- Makro [STOP_ZMOD](/de/Macros/#stop_zmod) - deaktiviert vorübergehend Fluidd/Mainsail und Moonraker

??? note "Version 0.1.6"
	### Version 0.1.6
	02.12.2024
	
	- Speicherort der Logs korrigiert
	- Makro [LOAD_CELL_TARE](/de/Macros/#load_cell_tare) behoben
	- Makro zur Kalibrierung von Extruder und Bett-PID behoben
	- Makro [CLEAR_NOZZLE](/de/Macros/#clear_nozzle) - Düsenreinigung wie in der nativen Firmware
	- Makro [KAMP](/de/Calibrations/#kamp) extruder_temp=[nozzle_temperature_initial_layer] bed_temp=[bed_temperature_initial_layer_single]. Adaptives Bettnetz mit Düsenreinigung.
	- [AUTO_FULL_BED_LEVEL](/de/Calibrations/#auto_full_bed_level) - komplett neu geschriebenes Makro

??? note "Version 0.1.5"
	### Version 0.1.5
	30.11.2024
	
	- Mainsail hinzugefügt. Umschalten über das Makro WEB
	- Makro STOP - schaltet die Motoren aus, wird in den End-G-Code geschrieben.
	- Makro [ZSHAPER](/de/Calibrations/#zshaper) - kalibriert die Shaper und exportiert CSV-Dateien nach /mod_data in der Konfiguration. Weitere Analyse über [Klipper-Input-Shaping-Assistant](https://github.com/theycallmek/Klipper-Input-Shaping-Assistant/releases)
	- Makro [LOAD_CELL_TARE](/de/Macros/#load_cell_tare) - Wägezellen zurücksetzen
	- Bettkalibrierung behoben. Sie können jetzt Bett- und Extrudertemperatur für die Kalibrierung einstellen. Standard 120/80
	- Bildschirmabschaltung im Modus ohne nativen Bildschirm behoben. Er schaltet sich nach 4 Minuten ab.

??? note "Version 0.1.4"
	### Version 0.1.4
	29.11.2024
	
	- Kamerasteuerung über den Mod hinzugefügt. Spart Speicher und ermöglicht die Arbeit mit der Kamera bei ausgeschaltetem Bildschirm. Die Auflösung der Kamera kann geändert werden. (Die Umsetzung wurde von Pavel Mironov inspiriert)
	- Fehler im Installer behoben, der in der letzten Version [heater_bed] aus den Konfigurationsdateien löschen konnte
	- Neue Bilder während der Installation. Erstellt von [@drmax_gc](https://t.me/drmax_gc)
	- Makros nach Kategorien sortiert und ins Russische übersetzt
	- Makro [DATE_GET](/de/Macros/#date_get) - aktuelle Zeit anzeigen
	- Makro [DATE_SET](/de/Macros/#date_set) - aktuelle Zeit setzen
	- Makro [CAMERA_ON](/de/Zmod/#camera_on) - alternative Kamera-Implementierung verwenden
	- Makro [CAMERA_OFF](/de/Macros/#camera_off) - Alternative Kamera-Implementierung deaktivieren

??? note "Version 0.1.3"
	### Version 0.1.3
	28.11.2024
	
	- MIDI-Wiedergabe hinzugefügt. Die Dateien liegen in mod_data/midi – Zugriff über die Registerkarte „Konfiguration“. Dank an [@drmax_gc](https://t.me/drmax_gc)
	- Makro [PLAY_MIDI](/de/Macros/#play_midi). Spielt eine Melodie: PLAY_MIDI FILE=Pain-Shut-your-mouth.mid
	- Makro `SOFT_REMOVE`. Entfernt nur Z-Mod, behält Audio, MD5, root
	- Nach dem Update bleiben die Moonraker-Einstellungen erhalten
	- Benutzereinstellungen für Klipper wurden nach mod_data/user.cfg verschoben.
	- Benutzereinstellungen für Moonraker wurden nach mod_data/user.moonraker.conf verschoben.
	- Beim Ausschalten des Bildschirms wird angezeigt, dass er ausgeschaltet ist. Danke @drmax_gc
	- Fehler bei der Bettkalibrierung per Makro behoben. Das Bett wird jetzt aufgeheizt.
	- Fehler bei der Bettausrichtung per Makro behoben. Das Bett wird jetzt aufgeheizt.

??? note "Version 0.1.1"
	### Version 0.1.1
	27.11.2024
	
	- Unterstützung für den Betrieb mit deaktiviertem nativen Bildschirm. Das spart 20 MB RAM. Um diesen Modus zu aktivieren, müssen Sie das Makro DISPLAY_OFF aufrufen. Klipper startet neu und verwendet alternative Konfigurationsdateien. Es wird empfohlen, das Bettnetz zu messen und im Profil default zu speichern. Nach dem Neustart wird der Bildschirm nach 5 Minuten nicht mehr verfügbar sein und das Bettnetz aus dem Standardprofil wird geladen.
	- Makro [MEM](/de/Macros/#mem) - zeigt an, wie viel Speicher verwendet wird und von welcher Anwendung.
	- Makro [DISPLAY_ON](/de/System/#display_on) - setzt den Bildschirm in den Standardmodus zurück, der Drucker wird neu gestartet
	- Makro [LED](/de/Macros/#led) - schaltet die Beleuchtung auf 50 % ein
	- Makro [LED_ON](/de/Macros/#led_on) - schaltet die Beleuchtung auf 100 % ein
	- Makro [LED_OFF](/de/Macros/#led_off) - schaltet die Beleuchtung aus

??? note "Version 0.0.9-fix"
	### Version 0.0.9-fix
	25.11.2024
	
	- Installationsfehler behoben.

??? note "Version 0.0.9"
	### Version 0.0.9
	25.11.2024

	- Pause während des Drucks, verarbeitet über den nativen Bildschirm
	- Fortsetzen nach einer Pause, verarbeitet über den nativen Bildschirm
	- Druckabbruch, verarbeitet über den nativen Bildschirm
	- [REBOOT](/de/Macros/#reboot) - Makro zum Neustart des Druckers
	- [SHUTDOWN](/de/Macros/#shutdown) - Makro zum Ausschalten des Druckers
	- [SKIP_ZMOD](/de/Macros/#skip_zmod) - Makro für einen Neustart ohne Moonraker und Fluidd
	- [REMOVE_ZMOD](/de/Macros/#remove_zmod) - Makro zum Entfernen des Mods
	- Fehler behoben: „Nach einer Pause durch den Filamentbewegungssensor wird der Druckvorgang wieder aufgenommen, aber der Druck erfolgt in der Luft etwa 3 cm über der Stelle, an der er sein sollte“
