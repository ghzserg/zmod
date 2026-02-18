## FAQ
## Häufig gestellte Fragen

> Ich habe einen Mod installiert.
>
> Sie wollen nichts verstehen - drucken Sie, wie Sie es getan haben.
>
> Sie müssen nichts anpassen oder ändern.
>
> Wenn Sie beschließen, dass Sie weitergehen wollen, lesen Sie die Dokumentation.

### Wie sich ZMOD von KlipperMod/nativer Firmware unterscheidet

   Der Unterschied zwischen KlipperMod und ZMOD:

  - KlipperMod verwendet reinen Klipper mit einem Minimum an flashforge 5m(pro) spezifischen Änderungen
      - ZMOD verwendet den Standard Klipper aus der nativen Firmware sowie Klipper 13.
      - KlipperMod verwendet KlipperScreen als Bildschirm für den Drucker.
      - ZMOD verwendet den nativen Bildschirm oder GuppyScreen anstelle von KlipperScreen
      - KlipperMod verwendet moonraker-Timelapse
      - ZMOD verwendet moonraker-telegram-bot auf einem EXTERNEN Host, der Timelapse oder [TimeLapse plugin](https://github.com/ghzserg/timelapse/) unterstützt.

Unterschiedliche Philosophie.

* KlipperMod ist im Wesentlichen eine alternative Firmware-Implementierung.
* ZMOD ist ein minimaler Eingriff in die native Firmware. Alle Funktionen der nativen Firmware werden beibehalten.

Deshalb wird es keine G17, G18, G19 in ZMOD geben - obwohl das einfach ist. Es wird keine Updates für den nativen Clipper geben, keine Umbenennung oder Änderung von Standardmakros, Einstellungen, Pin-Namen usw.

ZMOD basiert NICHT auf KlipperMod und ist auch keine Weiterentwicklung davon. Das heißt, ZMOD verwendet einige Makros und Skripte von KlipperMod, und nutzt auch Entwicklungen von KlipperMod. Aber Sie sollten von ZMOD kein ähnliches Verhalten wie von KlipperMod erwarten.

**ZMOD ist binär inkompatibel mit KlipperMod.**

#### Was ist in KlipperMod und was ist nicht in ZMOD:

- [KlipperScreen](https://klipperscreen.readthedocs.io/en/latest/) - Bildschirm für Drucker. In ZMOD ist es statt des KlipperScreen ein nativer Bildschirm oder GuppyScreen
- [Moonraker-Timelapse](https://github.com/mainsail-crew/moonraker-timelapse) - ZMOD verwendet Telegram-Bot oder [TimeLapse-Plugin](https://github.com/ghzserg/timelapse/).
- Netzwerkeinrichtung über iwd/wpa_supplicant (im Falle von guppyscreen) - im zMod erfolgt die Netzwerkeinrichtung über den nativen Bildschirm, der Netzwerkstart ist auch im nicht-nativen Bildschirm-Modus möglich

#### Was ist in ZMOD und was ist nicht in KlipperMod:

- Unterstützung [AD5X](/ru/AD5X/)
- Unterstützung für [die folgenden Sprachen](/ru/Global/#lang): Englisch, Deutsch, Französisch, Italienisch, Spanisch, Chinesisch, Japanisch, Koreanisch.
- Native Bildschirmfunktion
- [Stromausfall Druckwiederherstellung](/de/Zmod/#zrestore)
- [Shaper-Entfernung mit Diagrammerstellung](/ru/Kalibrierungen/#zshaper) unter Berücksichtigung von [SCV](/ru/Global/#fix_scv) ([square_corner_velocity](https://www.klipper3d.org/Config_Reference.html#printer)).
- [Überprüfung und Wiederherstellung nativer Dateisystemdateien/Rechte/symbolischer Links](/ru/System/#check_system)
- Automatische Aktualisierung von `Fluidd`/`Mainsail`/`Moonraker` und ZMOD über das Netzwerk
- Entware](/de/FAQ/#-zmod-entware-entware--how-to-use-it)
- Fehler behoben [E0017](/de/System/#fix_e0017)
- Zusätzlich unterstützt GuppyScreen: PID-Kalibrierung, Klappensteuerung, Rollback von Firmware, Düsenreinigung, Wägezellen-Reset, Schneckenjustierung, ColdPull, finalisierte Tabellenkarte
- Fester Betrieb von Treibergebläsen. Sie werden automatisch eingeschaltet, wenn die Motoren laufen. Bei nativer Firmware - nur beim Drucken.
- Entfernung der adaptiven Tabellenkarte [KAMP](/de/Kalibrierungen/#kamp)
- PID-Kalibrierung von [extruder](/ru/Kalibrierungen/#pid_tune_extruder) und [table](/ru/Kalibrierungen/#pid_tune_bed) einschließlich über GuppyScreen.
- Implementierung von [COLDPULL/coldpull](/ru/Filament/#coldpull) (Düsenreinigung) ohne Gewalt. Verwirklichung von [dieser Algorithmus](https://t.me/FF_5M_5M_Pro/2836/447172)

---

#### Was ist in ZMOD und was ist nicht in nativer Firmware:

- Moonraker/Fluidd/Mainsail-Unterstützung
- Telegram-Bot-Unterstützung
- Klipper 13-Unterstützung
- Alle Funktionen, die im Vergleich zu KlipperMod aufgeführt sind.
- Die native Firmware sendet eine Menge Daten an chinesische Server (https://github.com/FlashForge/Orca-Flashforge/issues/26), dies kann durch die Verwendung von zmod mit GuppyScreen vermieden werden.

---

## Speichern von Einstellungen

Zugriff auf den Ordner **mod_data** über die fluidd-Weboberfläche.

Konfiguration" -> "Konfigurationsdateien" -> "mod_data".

- Benutzerdefinierte Klipper-Einstellungen sollten in die Datei `mod_data/user.cfg` eingetragen werden, Einstellungen, die in diese Datei geschrieben werden, können Einstellungen aus `printer_base.cfg` und zMod-Dateien ersetzen/hinzufügen.
- Benutzerdefinierte Moonraker-Einstellungen müssen in die Datei `mod_data/user.moonraker.conf` eingetragen werden.
- Benutzerdefinierte Melodien werden in `mod_data/midi/` gespeichert.
- Globale Mod-Einstellungen werden mit dem Makro [SAVE_ZMOD_DATA](/de/Global/#save_zmod_data) gespeichert *nyuhler*
- Der Code, der ausgeführt werden soll, wenn der Drucker ausgeschaltet wird, wird hier gespeichert: `mod_data/power_off.sh`.
- Der Code, der beim Einschalten des Druckers ausgeführt werden soll, wird hier gespeichert: `mod_data/power_on.sh`.

**Die zmod- und Plugin-Dateien dürfen nicht verändert werden**, da dies das Aktualisierungssystem stört.

Jede Funktion kann in `mod_data/user.cfg` oder `printer.cfg` überschrieben werden.

---

## Bekannte Funktionen:

- Wenn der Drucker eine Aktion "M109" (Aufwärmen des Extruders), "M190" (Aufwärmen des Tisches), PID-Kalibrierung - im Grunde jede Aktion, die eine Pause von gcod verursacht - ausführt, dann friert der native Bildschirm ein
- Wenn der Klipper neu gestartet wird (nach dem Speichern von Table Map, PID, Shaper, etc.), friert der native Bildschirm ein (benutzen Sie den Neustart über [NEW_SAVE_CONFIG](/ru/Main/#new_save_config).
- Nachdem der Druck abgebrochen wurde, muss der native Bildschirm auf Ok klicken (verwenden Sie das Makro [CLOSE_DIALOGS](/ru/Main/#close_dialogs) oder [FAST_CLOSE_DIALOGS](https://github.com/ghzserg
/zmod/wiki/Main_de/Main_de#fast_close_dialogs))

- Der native Bildschirm lädt immer das `DEFAULT_MESH`-Profil, wenn der Druck geladen wird, und löscht immer das `Default`-Profil, wenn der Druck beendet ist

---

## Merkmale der Version ohne nativen Bildschirm

- Es ist notwendig, den gesamten Start-Gcode zu entfernen und [START_PRINT](/ru/Main/#start_print) zu schreiben, und im letzten [END_PRINT](/ru/Main/#end_print)
- Wenn die Kamera nicht funktioniert, müssen Sie eine andere Kamera über das Makro [CAMERA_ON](/ru/Zmod/#camera_on) starten.
- Gegebenenfalls ist es notwendig, den Parameter `Z_OFFSET` manuell in das Makro [START_PRINT](/ru/Main/#start_print) zu schreiben oder den globalen Parameter [LOAD_ZOFFSET](/ru/Global/#load_zoffset) zu verwenden, der den Z-Offset aus den globalen Parametern lädt, die zuvor über SET_GCODE_OFFSET gespeichert wurden. *crot.
- Wenn Sie den Z-Offset vom nativen Bildschirmmodus in den nicht-nativen Bildschirmmodus übertragen wollen, rufen Sie das Makro ```LOAD_ZOFFSET_NATIVE``` auf. Es liest den Z-Offset-Wert vom nativen Bildschirm und wendet ihn auf den nicht-nativen Bildschirmmodus an.
- Der Drucker lädt automatisch die `auto` desk map, wenn der Drucker eingeschaltet wird.
- Das Senden über das FlashForge-Protokoll funktioniert nicht, da es über den Bildschirm abgewickelt wird.
  Sie müssen auf das Octo/Klipper-Protokoll umschalten:

  - Protokoll: `Octo/Klipper`.
      - Hostname: "IP-Druckername:7125".
      - Url-Adresse des Hosts: `IP_printer` oder `IP_printer:80`.

---

### Was ist der Unterschied zwischen der Arbeit mit und ohne nativen Bildschirm

Der Drucker kann in zwei Modi betrieben werden:

- Mit nativem Bildschirm - in diesem Fall wird fast die gesamte Logik über den nativen Bildschirm gesteuert und viele Dinge können nicht geändert werden.
- Ohne nativen Bildschirm - in diesem Fall werden alle Funktionen vom zMod gesteuert.
Das bedeutet nicht, dass Sie den Bildschirm hardwaremäßig deaktivieren oder ihn durch einen anderen ersetzen müssen.
Im nicht-nativen Bildschirmmodus können Sie den alternativen Software-Bildschirm von GuppyScreen verwenden oder den Bildschirm ganz ausschalten und er wird ausgeschaltet.

**Deaktivieren Sie den Bildschirm nicht, wenn Sie nicht genau wissen, wie die Tabellenzuordnung, der Z-Offset und die Makros START_PRINT und END_PRINT funktionieren**

Unser Drucker hat 128 Megabyte Arbeitsspeicher, von denen die Hälfte vom System belegt wird und 13 Megabyte (20 in älteren Versionen der nativen Firmware) von der nativen Bildschirmsteuerung belegt werden.

Wenn wir den nativen Bildschirm deaktivieren (/ru/System/#display_off), sparen wir Speicher.

Aber in diesem Fall arbeiten die eingebauten Druckwerkzeuge anders (Druck starten, anhalten, wiederherstellen, abbrechen, Druck beenden, Dateien zum Druck senden, Wiederherstellung nach Stromausfall).

Deshalb ist es notwendig, den Start- und End-G-Code zu ändern. *war.

Außerdem setzt der Drucker bei Betrieb im nicht-nativen Bildschirmmodus den auf dem Bildschirm aufgezeichneten Z-Offset nicht und muss als Parameter an [START_PRINT](/ru/Main/#start_print) oder über globale Parameter übergeben werden. [Mehr lesen](/de/FAQ/#how-z-offset-works)

Lesen Sie [features of the non-native screen version](#features-of-the-native-screen version).

Und wechseln Sie zum Octo/Klipper-Protokoll

---

### Ich verwende die Bildschirmoption. Ich sende eine Datei zum Drucken und der Bildschirm zeigt eine Temperatur von 0 0 0 und keinen Druck an.

Fügen Sie 2 Zeilen zum Startcode ganz am Anfang des Codes hinzu
```
M190 S[bed_temperature_initial_layer_single]
M104 S[Düsentemperatur_Anfang_Schicht]
```

Ohne diese Zeilen weiß der Druckerbildschirm nicht, auf welche Temperatur die Düse und der Tisch erwärmt werden sollen.
*```

---

#### Nach der Installation von ZMOD ist mein Bildschirm tot und reagiert nicht mehr auf Tastendrucke.

- Installieren Sie das letzte Update der nativen Firmware und ZMOD](/de/Recomendations/#install-last-update-native-firmware-and-zmod)
- Lesen Sie [Betriebsfunktionen](#known-features)
- Möglicherweise haben Sie den Bildschirm ausgeschaltet. Schalten Sie ihn mit dem Makro [DISPLAY_ON](/de/System/#display_on) ein.

---

#### Müssen Sie etwas am Startcode ändern?

Wenn Sie mit dem nativen Bildschirm arbeiten, brauchen Sie nichts zu ändern.

Wenn Sie im nicht-nativen Bildschirm/Guppy-Modus arbeiten (und es wird auch empfohlen, wenn Sie mit einem Bildschirm arbeiten), ersetzen Sie den gesamten Startcode:
```
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single]
M104 S[düse_temperatur_anfangsschicht]
SET_PRINT_STATS_INFO TOTAL_LAYER=[total_layer_count]
```

````START_PRINT EXTRUDER_TEMP= BED_TEMP=`````` sollte in eine Zeile geschrieben werden

Und der endgültige Code ist auf:
```
END_PRINT
```

Damit die Ebenen in Fluidd richtig gezählt werden, schreiben Sie den Code vor dem Wechsel der Ebene ein:
```
SET_PRINT_STATS_INFO AKTUELLE_SCHICHT={Schicht_Zahl + 1}
```

Wenn Sie die automatische Kalibrierung bei jedem Druckvorgang aktivieren wollen, geben Sie Fluidd/Mainsail 1 mal in die Konsole ein
```
SAVE_ZMOD_DATA CLOSE_DIALOGS=2 PRINT_LEVELING=1 USE_KAMP=1
```
Gehen Sie im Bildschirmmenü des Druckers zu "Einstellungen" -> "WLAN-Symbol" -> "Netzwerkmodus" -> aktivieren Sie den Schieberegler "Nur lokale Netzwerke".

Lesen Sie die Dokumentation zu [START_PRINT](/de/Main/#start_print) und [SAVE_ZMOD_DATA](/de/Global/#save_zmod_data), damit Sie die erweiterten und nützlichen Funktionen von ZMOD nutzen können

Wenn Sie Rollback von der Firmware verwenden wollen, lesen Sie [documentation](/ru/FAQ/#what-is-rollback-from-firmware) und fügen Sie
Balkenprofil" -> "Erweitert" -> "G-Code-Balken starten".
```
SET_RETRACTION RETRACT_LENGTH=[filament_retraction_length]
```

*Waschbär

---

### So funktioniert Z-Offset

Lesen Sie den Artikel "[Wie Z-Offset auf unserem Drucker funktioniert](/de/SetupCalibrations/#wie-z-offset-auf-Ihrem-Drucker-arbeitet)".

Der Mod stört den Z-Offset in keiner Weise bei der Arbeit mit dem Bildschirm.

Offset bei der Arbeit mit dem nativen Bildschirm und bei der Arbeit im nicht-nativen Bildschirmmodus sind nicht dasselbe, und jeder führt sein eigenes Leben und wird separat konfiguriert.

Verwenden Sie ```LOAD_ZOFFSET_NATIVE```, um den z-Offset vom nativen Bildschirm in den nicht-nativen Bildschirm-Modus zu kopieren.

Es wird der auf dem Bildschirm gespeicherte z-Offset verwendet.

Der Z-Offset von Fluidd/Mainsail/GuppyScreen wirkt **nur bis zum Neustart** und sollte nicht verändert werden, ohne zu wissen, wohin sich die Düse bewegt.

Jeder Aufruf von `SET_GCODE_OFFSET` (der automatisch aufgerufen wird, wenn man den Z-Offset von Fluid/Mainsail/GuppyScreen ändert) speichert den aktuellen Z-Offset in den globalen Parametern des Mods. Aber dieser gespeicherte Wert wird nur verwendet, wenn der globale Parameter [LOAD_ZOFFSET](/ru/Global/#load_zoffset) angegeben ist (der standardmäßig deaktiviert ist, um `SAVE_ZMOD_DATA LOAD_ZOFFSET=1` zu aktivieren), der native Bildschirm nicht verwendet wird und das Makro [START_PRINT](/ru/Main/#start_print) verwendet wird.

Sie können auch die Parameter [START_PRINT](/ru/Main/#start_print) verwenden, um den Z-Offset zu setzen

- Z_OFFSET - Einstellung des Z-Offsets (0.0)

#### Welche Optionen gibt es zum Entfernen der Tabellenabbildung?

Wenn Sie die automatische Kalibrierung bei jedem Druckvorgang aktivieren wollen, geben Sie fluidd/mainsail 1 mal in die Konsole ein:
```
SAVE_ZMOD_DATA CLOSE_DIALOGS=2 PRINT_LEVELING=1 USE_KAMP=1
```

Der native Bildschirm verwendet Karten (immer, es ist nicht fixiert, auch wenn man es nicht muss):

- ```MESH_DATA``` - Voreinstellung
- `DEFAULT` - wenn `Leveling` (Aufbau der Tabellenkarte vor dem Druck) angekreuzt ist, und nach dem Druck wird die `DEFAULT` Karte immer gelöscht.

Bei der Arbeit im nicht-nativen Bildschirmmodus wird die Karte verwendet:

- `auto` - sie wird automatisch geladen, wenn der Drucker eingeschaltet wird.

Wenn Sie beim Drucken eine andere Karte verwenden wollen (z.B. `moya_karta_na_80_gradusov`), dann:

- Schalten Sie die automatische Kalibrierung in den globalen Parametern aus.

  ````SAVE_ZMOD_DATA PRINT_LEVELING=0````

- Erfassen Sie die Tabellenkarte im Voraus über das Makro [AUTO_FULL_BED_LEVEL](/de/FAQ/#chores-macros-and-buttons-in-fluidd).
 
  ````AUTO_FULL_BED_LEVEL EXTRUDER_TEMP=230 BED_TEMP=80 PROFILE=moya_karta_na_80_gradusov```''

Wählen Sie eine der beiden Optionen:

- Geben Sie den Namen der Tabellenkarte im Parameter `MESH` für das Makro [START_PRINT](/ru/Main/#start_print) an.
 
  ``` ```START_PRINT MESH=moya_karta_na_80_gradusov```''

- oder laden Sie die Tabellenkarte an einer beliebigen Stelle (z.B. im Barprofil) mit dem Befehl
 
  ```BED_MESH_PROFILE LOAD=moya_karta_na_80_gradusov```

  Stellen Sie sicher, dass Sie dieselbe Karte im Balkenprofil und in `START_PRINT` verwenden, oder deaktivieren Sie die Düsenreinigung in `START_PRINT`, indem Sie es über das Balkenprofil ausführen.

---

#### Über globale Parameter

Ich empfehle die Verwendung globaler Parameter, die einmal konfiguriert und bei jedem Druckvorgang verwendet werden. In diesem Fall ist es nicht notwendig, den Start- und End-G-Code zu ändern.

Parameter `PRINT_LEVELING`:

- Entfernt die Tabellenabbildung bei jedem Druckvorgang
- Wenn Sie mit dem Bildschirm arbeiten, wird die Tabellenkarte vom nativen Bildschirm entfernt, so wie es der Fall wäre, wenn Sie eine Datei auf dem Bildschirm ausgewählt und das Kontrollkästchen `LEVELING` angeklickt hätten. Wenn der Parameter 1 "SAVE_ZMOD_DATA PRINT_LEVELING=1" lautet, geht der Drucker beim Senden von Dateien über Orca/Fluidd/Mainsail davon aus, dass Sie die zu druckende Datei am Originalbildschirm ausgewählt und das Kontrollkästchen "Ausrichtung" aktiviert haben. Jedes Mal, wenn Sie in diesem Fall drucken, wird der Tabellenplan erfasst.
- Wenn Sie im nicht-nativen Bildschirmmodus arbeiten und das Makro [START_PRINT](/ru/Main/#start_print) im anfänglichen G-Code verwenden, wird der Tabellenplan ebenfalls bei jedem Druckvorgang gelöscht

  Um diese Funktion zu aktivieren, müssen Sie einmal das Makro [SAVE_ZMOD_DATA](/ru/Global/#save_zmod_data), den Parameter [PRINT_LEVELING](/ru/Global/#zshaper)

  ```SAVE_ZMOD_DATA PRINT_LEVELING=1``` *(muss in der Fluidd/Mainsail Konsole eingegeben werden)*. In diesem Fall wird die Karte bei jedem Druck entfernt.

  *Um die Desktop-Karte vom nativen Bildschirm zu entfernen, gehen Sie zu ```Einstellungen``` -> ```Wifi-Symbol``` -> ```Netzwerkmodus``` -> schalten Sie den Schieberegler ```Nur lokale Netzwerke``` über das Menü des Druckerbildschirms ein.

  *Wenn diese Option aktiviert ist, werden alle START_PRINT-Parameter, die sich auf die Erstellung/Verwendung einer Schreibtischkarte beziehen, ignoriert (FORCE_LEVELING, FORCE_KAMP, SKIP_LEVELING, MESH).

Parameter `USE_KAMP`:

- Adaptive table map removal (KAMP) kann aktiviert werden, dann wird nicht die gesamte Tabelle entfernt, sondern nur die Teile mit druckbaren Modellen.
  **Automatisches Table-Map-Skimming wird nicht ausgelöst!**. Dieser Parameter legt fest, dass bei Aufruf des Table Map Skimming stattdessen KAMP ausgeführt werden soll.

  Um diese Funktion zu aktivieren, müssen Sie das Makro [SAVE_ZMOD_DATA](/ru/Global/#save_zmod_data) einmal konfigurieren, Parameter [USE_KAMP](/ru/Global/#zshaper)

  ```SAVE_ZMOD_DATA USE_KAMP=1``` *(muss in der Fluidd/Mainsail Konsole eingegeben werden)*. In diesem Fall wird die adaptive Tabellenkarte verwendet, wo immer dies möglich ist, auch wenn die Tabellenkarte mit dem nativen Bildschirm über das Netzwerk erfasst wird.

---

#### Durch Änderung des Startcodes und des Makros START_PRINT

Wenn Sie die globalen Parameter *(SAVE_ZMOD_DATA PRINT_LEVELING=0)* nicht verwenden wollen, stehen Ihnen die folgenden Parameter des Makros [START_PRINT](/ru/Main/#start_print), das im Start-G-Code geschrieben wird, zur Verfügung.

- FORCE_LEVELING - erzwingt den Aufbau einer Tabellenkarte, True - aufbauen, False - nicht aufbauen (False)
- FORCE_KAMP - Start des Aufbaus der adaptiven Tabellenkarte, True - ja, False - nein (False).
- SKIP_LEVELING - unter keiner Bedingung die Tabellenkarte aufbauen. Stärker als FORCE_KAMP und FORCE_LEVELING (False)
- MESH - Name der zu ladenden Table Map, wenn nicht angegeben, wird nichts geladen, wenn sie nicht existiert, wird sie erstellt ("").

Beispiele:

Entfernen einer kompletten Table Map:
```
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single] FORCE_LEVELING=True
M190 S[bed_temperature_initial_layer_single]
M104 S[Düsentemperatur_Einstiegsschicht]
```

Entfernen der Karte der adaptiven Tabelle
```
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single] FORCE_KAMP=True
M190 S[bed_temperature_initial_layer_single]
M104 S[düse_temperatur_einzel_schicht]
```

Algorithmus zum Entfernen der Tabellenkarte im Makro [START_PRINT](/ru/Main/#start_print):

1. Wenn MESH nicht leer ist, wird die Karte mit dem im Parameter MESH angegebenen Namen geladen
2. Wenn SKIP_LEVELING = True - wird die Tabellenkarte unter keinen Umständen entfernt
3. Andernfalls, wenn `FORCE_CAMP=True` gesetzt ist, wird KAMP entfernt.
4. Andernfalls, wenn die Tabellenkarte nicht geladen ist (der native Kopf lädt immer die `MESH_DATA` Karte) oder wenn `FORCE_LEVELING=True`, wird der Aufbau der Tabellenkarte gestartet, aber sie wird nicht selbst gespeichert

---

#### Über Makros und Schaltflächen in Fluidd

Wenn Sie das Makro `START_PRINT` und die globalen Parameter nicht verwenden wollen, stehen Ihnen die folgenden Makros zur Verfügung:

- [AUTO_FULL_BED_LEVEL](/ru/Calibrations/#auto_full_bed_level) - Tischkartenentnahme mit Düsenreinigung bei einer bestimmten Tisch- und Extrudertemperatur. *Deaktiviert die Heizung nach der Kartenentnahme.

   Das gleiche Makro kann mit der Schaltfläche Fluidd/Mainsail aufgerufen werden, es heißt `TABLE CALIBRATION`. Nachdem Sie die Tischkarte bei einer bestimmten Temperatur entnommen haben, können Sie die Schaltfläche "Parameter speichern" drücken, und die Tischkarte wird in der Datei "printer.cfg" gespeichert.

   Sie kann auch in den Start-G-Code geschrieben werden:
   ```
   AUTO_FULL_BED_LEVEL EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
   M190 S[bed_temperature_initial_layer_single]
   M104 S[Düsentemperatur_Einstiegsschicht]
   ```

- [KAMP](/de/Kalibrierungen/#kamp) - Adaptive Tabellenkalibrierung mit Düsenreinigung
  ```` KAMP EXTRUDER_TEMP=[düse_temperatur_anfangs_schicht] BED_TEMP=[bett_temperatur_anfangs_schicht_einzeln]````

- BED_MESH_CALIBRATE - Entfernung der Tabellenkarte durch das Standard-Klipper-Makro. **Es wird nicht empfohlen, es zu verwenden**, da keine Düsenreinigung durchgeführt wird, so dass die Ergebnisse falsch sein werden. **Adaptive Table Map von Orca, überhaupt nicht empfohlen**, da sie die Punktentfernung nicht zufällig vornimmt, was bedeutet, dass die Düse beim Drucken identischer Modelle jedes Mal an denselben Punkten misst, was zum Auftreten von Mikrolöchern und infolgedessen zu einer falschen Table Map führt.

---

#### Verwendung von Standard-KLIPPER-Befehlen

Um mit MESH zu arbeiten, gibt es Standard-KLIPPER-Makros:

- [BED_MESH_CALIBRATE](https://www.klipper3d.org/G-Codes.html#bed_mesh_calibrate) - Tabellenabbildung entfernen
- [BED_MESH_OUTPUT](https://www.klipper3d.org/G-Codes.html#bed_mesh_output) - Tabellenabbildung ausgeben
- [BED_MESH_PROFILE](https://www.klipper3d.org/G-Codes.html#bed_mesh_profile) - Tabellenabbildung laden, löschen, speichern

Wenn Sie ein Kennfeld über KLIPPER-Befehle in das Stangenprofil laden, stellen Sie sicher, dass Sie dasselbe Kennfeld in `START_PRINT` und dem Stangenprofil verwenden, oder deaktivieren Sie die Düsenreinigung in START_PRINT und führen Sie sie separat über das Stangenprofil aus.

Es wird dringend empfohlen, die Optionen für die Düsenreinigung zu lesen:

- [CLEAR_NOZZLE](/de/Global/#clear_nozzle) - Düsenreinigung wie in nativer Firmware
- Parameter [PRECLEAR](/ru/Global/#preclear) - Zusätzliche Düsenreinigung, wenn die Tischkarte entfernt wird.
- Parameter [CLEAR](/ru/Global/#clear) - vier Algorithmen (Sie können Ihre eigenen hinzufügen) für die zeilenweise Düsenreinigung vor dem Druck.

---

#### Warum tauchen in der Dokumentation immer wieder Tiernamen auf?

Niemand mag/will die Dokumentation lesen, obwohl 90% der Fragen in ihr gelöst und beschrieben werden.

Diejenigen, die sie nicht lesen, sagen auch gerne, dass sie alles gelesen haben.

Deshalb habe ich die Namen der Tiere *opossum* in den Text gestreut und werde sie fragen, wenn sie eine andere Frage aus der Dokumentation stellen. Wenn Sie das Tier, das für Ihre Frage im Text versteckt war, nicht nennen konnten, dann haben Sie die Dokumentation nicht gelesen.

Wenn Sie hierher verwiesen wurden. Lesen Sie die Dokumentation und nennen Sie das Tier, das auf Ihrer Frage steht, und Sie werden auf jeden Fall Hilfe bekommen:

- [Häufig gestellte Fragen](/de/FAQ/)
- [Tipps zur Verbesserung der Druckerstabilität](/de/Recomendations/)
- [Mod installieren/verbessern/deinstallieren](/ru/Setup/)
- [Makro-Liste](/ru/Makros/)
- Speichereinstellungen](#storage-settings)
- Bekannte Funktionen](#known-features)

---

### Ich möchte ZMOD löschen - muss ich alles neu kalibrieren?

Nein - alle Einstellungen bleiben erhalten

### Was ist eine alternative Kamera?
 
Die native Kamera, die über den Bildschirm eingeschaltet wird, hat eine Reihe von Nachteilen.

- Hoher RAM-Verbrauch
- Schlechte Bildqualität
- Nur eine Verbindung zur Kamera. Sobald Sie sie in Ork öffnen, wird sie im Browser nicht mehr angezeigt
- Regelmäßige Bildaussetzer

Alternative Kamera, erlaubt die Änderung der Auflösung, fps, erlaubt mehrere Verbindungen, komprimiert das Bild nicht, einfaches Neustarten und Anpassen [macro](/ru/Zmod/#camera_on). *zayats*.

- Deaktiviert die native Kamera auf dem Druckerbildschirm.
- Rufen Sie das Makro [CAMERA_ON](/ru/Zmod/#camera_on)

Lesen: [Ich habe einen Drucker installiert und ZMOD hat meine Kamera versteckt!](#I-installed-a-printer-and-zmod-hid-my-camera-in-orca-ff-I-see-it-and-now-it's-gone).

#### Kamera-Einrichtung

**Haupteinstellungen**

| Parameter | Was bedeutet | Normaler Wert |
|----------|------------|------------------|
| WIDTH | Bildbreite | 640 |
| `HÖHE` | Bildhöhe | 480 |
| `FPS` | Wie viele Bilder pro Sekunde | 20 |
| `VIDEO` | Kameranummer | video0 |
| `FS` | Problemkameras reparieren (1 für ja, 0 für nein) | 0 |
| `STREAMER` | Kameraprogramm | auto |
| `FORMAT` | Bildformat (nur ustreamer) | MJPEG | MJPEG |

**Was ist ein Streamer?**

Ein Streamer ist ein Programm, das ein Bild von einer Kamera aufnimmt und es in einem Browser anzeigt.

**Es sind zwei Optionen verfügbar:**

- **mjpg_streamer** - einfaches Programm, funktioniert nur mit MJPG-Kameras.
- **ustreamer** - leistungsfähiger, benötigt aber mehr Speicher, unterstützt verschiedene Kameras.

Der Parameter "STREAMER=auto" wählt den geeigneten Streamer aus.

**Bildformate (nur für ustreamer)**

Sie können wählen: YUYV, YVYU, UYVY, RGB565, RGB24, BGR24, MJPEG, JPEG.

Standardmäßig wird MJPEG verwendet.

**Befehlsbeispiele**

Einfaches Starten der Kamera video0 über mjpg_streamer:
```
CAMERA_ON VIDEO=video0
```

Starten der Kamera video0 über ustreamer mit Einstellungen:
```
CAMERA_ON VIDEO=video0 STREAMER=ustreamer FORMAT=YUYV WIDTH=640 HEIGHT=480
```

**Wo kann man das Bild sehen?**

In einem Browser öffnen: `http://ip_адрес_принтера:8080`.

Dort können Sie Helligkeit, Kontrast und andere Einstellungen ändern.

**Wenn es Probleme gibt**

Sie können die Kamera nicht sehen?
Starten Sie:
```
CAMERA_ON VIDEO=video99
```
Das Programm zeigt eine Liste der verfügbaren Kameras an.

**Logs (Fehlerprotokolle)** befinden sich im Ordner: `log/cam/`.

---

### Ich habe einen Drucker installiert und ZMOD hat meine Kamera versteckt! Ich konnte sie in Orca-FF sehen, aber jetzt ist sie weg!
 
In der Weboberfläche (fluidd) gehen Sie zu "Einstellungen" -> "Videokameras".

Dort gibt es bereits eine Videokamera, `Sample_Settings_Camera`. Gehen Sie zu ihr und sehen Sie sich die Einstellungen an.

**Erstellen Sie eine neue Kamera** mit ähnlichen Einstellungen wie die Kamera "Beispiel_Einstellungen_Kamera":

- Streamtyp: `MJPEG-Stream`.
- Stream-URL: `http://your_IP:8080/?action=stream`.
- Schnappschuss-URL: `http://your_IP:8080/?action=snapshot`
- your_IP - ersetzen Sie durch die IP-Adresse Ihres Druckers.

In Versionen, die älter sind als `1.4.3`, können Sie auch angeben:

- Streamtyp: `MJPEG-Stream`.
- Stream-URL: `/webcam/?action=stream`.
- Schnappschuss-URL: `/webcam/?action=snapshot`.

Wenn Sie die Auflösung und die Bildrate anpassen, die Kamera des Telegram-Bots verwenden, den RAM-Verbrauch reduzieren oder parallele Verbindungen erlauben wollen, müssen Sie [alternative Kamera](/ru/Zmod/#camera_on) verwenden. *Kroot

Legen Sie auf dem Router eine *statische IP-Adresse für den Drucker* fest, sonst ändert sie sich und die Kamera stürzt ab.

---

### Ich habe 2 Kameras / wie kann ich die Kamera deaktivieren/umkehren

Wenn Sie keine Kamera haben, oder die automatischen Kameraeinstellungen Ihnen nicht zusagen, müssen Sie die Datei `mod_data/user.moonraker.conf` über Fluidd/Mainsail öffnen

Und hineinschreiben:

Um die Kamera zu deaktivieren:
```
[webcam video]
aktiviert: false
```

Um die Kamera zu drehen:
```
[webcam video]
Drehen: 90
```

---

### Ich habe die neueste Version installiert und der Entwickler sagt, dass ich ein Upgrade durchführen soll.

- Vergewissern Sie sich, dass Sie die neueste Version vom Flash-Laufwerk installiert haben
- Rufen Sie die Webschnittstelle auf. Einstellungen" -> "Software-Updates" -> Klicken Sie auf "Nach Update suchen".
- Aktualisieren Sie alle Komponenten von *treeflyer*.
- Starten Sie den Drucker neu

<img width="1239" height="535" alt="image" src="https://github.com/user-attachments/assets/b42c4ce9-1c0a-45c0-a20c-36919a27d648" />

---

### Kann MCU nicht aktualisieren

Nach einem Neustart erscheint ein Fehler
```
!! MCU 'eboard' Konfiguration kann nicht aktualisiert werden, da sie heruntergefahren ist
```

Neustart des Druckers im abnormalen Betriebsmodus.

Aus diesem Grund werden Sie aufgefordert, das Gerät aus- und wieder einzuschalten, wenn Sie die native Firmware installieren.

Beim Neustart wird die MCU nicht von der Stromversorgung getrennt, was bedeutet, dass das in die MCU geschriebene Programm weiterläuft. Dieses Programm versucht, den Clipper zu kontaktieren, der während des Neustarts nicht verfügbar ist, und führt dazu, dass die MCU einfriert oder sich abschaltet.

In diesem Fall müssen Sie sich für eine Option entscheiden:

- Rufen Sie `FIRMWARE_RESTART` auf, in diesem Fall bleibt der native Bildschirm hängen.
- Schalten Sie den Drucker aus und schalten Sie

Der Unterschied zwischen `REBOOT` und `FIRMWARE_RESTART` ist, dass `REBOOT` Linux und damit auch Klipper auf dem Motherboard neu startet, `FIRMWARE_RESTART` startet Klipper teilweise neu und startet die MCU komplett neu

---

### Was ist MACROS? Wie man es ausführt, herunterlädt und benutzt.

Ein Makro ist ein kleines Programm in der Klipper/Gcode-Sprache.

Es kann aufgerufen werden:

- Aus einer GCODE-Datei
- Von der Fluidd/Mainstaill-Konsole aus
*Igel

[Makro-Liste](/de/Makros/)

---

### Ich gehe über Orca/Browser zum Drucker und sehe Welcome to Moonraker

Welche Ports verwendet ZMOD?

- 7125" - dort befindet sich Moonraker.
- 8080" - dort befindet sich die Kamera.
- 80" - dort arbeitet Fluidd/Mainsail.

Um auf den Drucker zuzugreifen, geben Sie einfach die Drucker-IP ein, **ohne die Portnummer anzugeben**. *Hase

[Wie man in Orca konfiguriert](/de/Recomendations/#send-files-to-print-octoklipper)

#### Ich habe das Webinterface umgestellt und jetzt funktioniert nichts mehr.

Wenn du das Interface mit dem Makro [WEB](/ru/System/#web) umschaltest *whoosh*

Das erste, was zu tun ist, ist `Strg + F5` oder `Strg + Umschalt + R` oder `Option + Befehl + E` zu drücken.

Wenn Sie ein Problem in Orca haben, müssen Sie `Strg + F5` oder `Strg + Umschalt + R` oder `Option + Befehl + E` drücken *fox*

Wenn Sie einen anderen Browser verwenden, müssen Sie den Cache und die Cookies löschen und die IP-Adresse des Druckers ohne zusätzliche Zeichen in der Adressleiste aufrufen.

http://ИП_ПРИНТЕРА/".

Wenn dies nicht hilft, verwenden Sie einen anderen Browser: Firefox, Chrome, Yandex, Opera, etc.

---

### ZMOD enthält Entware - wie benutzt man es?

**WARNUNG! Es gibt keine Entware** in [AD5X](/ru/AD5X/)

Sie müssen sich per SSH mit dem Drucker verbinden (`root`:`root` port `22`)

Führen Sie den Befehl
`
export PATH="$PATH:/opt/bin/:/opt/sbin/"
`

Sie können dann `mc` oder `opkg` ausführen

- Aktualisieren der Paketdatenbank: `opkg update`
- Installieren eines Pakets: `opkg install mc`

Kataloge, die von entware erstellt und verwendet werden:

- /opt/bin
- /opt/etc
- /opt/home
- /opt/lib
- /opt/libexec
- /opt/Wurzel
- /opt/sbin
- /opt/share
- /opt/tmp
- /opt/usr
- /opt/var

---

### Was ist ein Rollback von der Firmware?

Im ZMOD in Fluidd/Mainsail gibt es Schieberegler, um die Geschwindigkeit und den Umfang des Rollbacks von der Firmware zu steuern.

Sie wirken sich nicht auf den Druck aus, wenn die G-Code-Datei ohne Verwendung von Rollback-Parametern aus der Firmware gesliced wird.

Mit dem Firmware-Rollback können Sie den Rollback-Wert während des Drucks ändern, ohne die gesamte Datei neu schneiden zu müssen.

Anstelle von umständlichen Rollback-Befehlen wie "G1 E-.5 F2100" wird jetzt das kurze "G10" für den Rückzug verwendet, und anstelle von "G1 E.5 F2100" wird "G11" für den umgekehrten Rückzug verwendet.

Um das Rollback aus der Firmware zu nutzen, muss in Orca.

Druckereinstellungen" -> "Allgemeine Informationen" -> "Erweitert" -> "Firmware-Rollback" das Kontrollkästchen anklicken.

Wenn Sie die Standard-Rollback-Einstellungen in der Firmware ändern möchten:

Über Fluidd. Konfiguration` -> `mod_data` -> `user.cfg`
```
[firmware_retraction].
retract_length: 0.9
einziehen_Geschwindigkeit: 35
unretract_extra_length: 0
untract_speed: 35
```

SET_RETRACTION" wird normalerweise als Teil der Slicer-Konfiguration für jedes Filament gesetzt, da verschiedene Filamente unterschiedliche Parametereinstellungen erfordern:
SET_RETRACTION [RETRACT_LENGTH=<mm>] [RETRACT_SPEED=<mm/s>] [UNRETRACT_EXTRA_LENGTH=<mm>] [UNRETRACT_SPEED=<mm/s>]: Setzt die Parameter für den Rückzug.

- RETRACT_LENGTH ist die Länge des Gewindes für Rückzüge und Retraktionen.
- RETRACT_SPEED - Geschwindigkeit für den Rückzug.
- UNRETRACT_SPEED - die Rückzugsgeschwindigkeit wird durch UNRETRACT_SPEED gesteuert und ist nicht besonders kritisch, obwohl sie oft niedriger ist als RETRACT_SPEED.
- UNRETRACT_EXTRA_LENGTH - in manchen Fällen ist es nützlich, beim Zurückziehen eine kleine zusätzliche Länge hinzuzufügen.

Beispiel für die Einstellung von RETRACTION bei Orca:

Balkenprofil" -> "Parameterüberschreibung" -> "RETRACT" -> "Länge".

Balkenprofil -> `Zusätzlich` -> `Start G-Code des Balkens`
```
SET_RETRACTION RETRACT_LENGTH=[filament_retraction_length]
```

```GET_RETRACTION```: fragt die aktuellen Parameter ab, die beim Rollback verwendet werden und zeigt sie auf dem Terminal an.

Retract Substitutionsvariante von [@minicx](https://github.com/loss-and-quick/)
```
SET_RETRACTION RETRACT_LENGTH={if not is_nil(filament_retraction_length[current_extruder])}[filament_retraction_length[current_extruder]]{else}[retraction_length]{endif} RETRACT_SPEED={if not is_nil(filament_retraction_speed[current_extruder])}[filament_retraction_speed[current_extruder]]{else}[retraction_speed]{endif}
```

---

### AD5X

[AD5X](/ru/AD5X/)

---

### Hilfe

### Wie kontaktiere ich den Entwickler-Support?

[Anleitung verschoben](/ru/Help/)

---

### Wie man das Bootlogo ändert

Das Logo befindet sich im Ordner ```mod_data/logo```.

Logo Anforderungen:

- Größe 800x480 Farbtiefe 24 Bits
- AD5M: BMP-Format. Dateiname: ```bootlogo.bmp```.
- AD5X: JPG-Format. Dateiname: ```Logo.jpeg```.

Laden Sie Ihr Logo in den Ordner ```mod_data/logo``` hoch.

Starten Sie den Drucker 2 mal neu.

Wenn Sie die Mod löschen, wird das ursprüngliche Logo wiederhergestellt. Wenn dies beim AD5M nicht geschehen ist:

- Sie müssen die Mod installieren
- Laden Sie die Datei [boot.bmp](https://github.com/ghzserg/FF/releases/download/R/boot.bmp) in den Ordner "mod_data/logo" hoch.
- Starten Sie den Drucker neu

---

### Kein Auslöser an der Sonde nach voller Bewegung

Der Fehler tritt vor allem dann auf, wenn der Hub der Z-Achse während der Antastung nicht ausreicht.

Er kann programmatisch wie folgt behoben werden:

Geben Sie in ```mod_data/user.cfg``` ein.
```
[bed_mesh]
horizontal_move_z: 5
```

Hardware - alle Schrauben sollten eingestellt sein und der Tisch sollte keinen Versatz aufweisen.

---

### GewichtWert

WeightValue ist der Wert auf den Wägezellen in Gramm. Er wird in Grad angezeigt, da er über die Temperatursensor-Schnittstelle implementiert ist. Daher zeigen Fluidd und Mainsail Grad an.

Warum brauchen Sie diesen Sensor?

- Er kann verwendet werden, um den Z-Offset über das [g28_tenz](https://github.com/ghzserg/g28_tenz) Plugin zu messen.
- Sie können den Druck stoppen, wenn die Düse ein Teil trifft oder ein Teil abgerissen wird. [NOZZLE_CONTROL](/de/Global/#nozzle_control)
- Ohne Zurücksetzen ist die Messung der Tischkarte nicht korrekt.

---

### MCU Protokollfehler

Hier sind einige Fehler, die von der MCU abhängen:

- MCU-Protokoll-Fehler
- Unbekannter Temperatursensor flashforge_loadcell
- Erforderlicher MCU-Befehl
- flashforge_loadcell: Erforderlicher MCU-Befehl 'flashforge_loadcell_h1' ist nicht verfügbar

Die Essenz all dieser Fehler ist, dass die Klipper-Version nicht mit der MCU-Version übereinstimmt.

Sie können die MCU-Version auf der Registerkarte `System` einsehen.

<img width="700" height="396" alt="{9CCFD772-CCDB-42ED-B952-DA15231DCF68}" src="https://github.com/user-attachments/assets/80e6a573-b372-4620-a7bc-7cbf020bc874" />

<img width="438" height="277" alt="{52EC8847-ACAB-461D-A9FA-633CDAF180CC}" src="https://github.com/user-attachments/assets/9bba3ff2-9a0e-4aa6-8327-f93fd1b46c3a" />

Du hast z.B. Klipper 13 laufen und verwendest die MCU von Klipper 11 oder 12.

Oder andersherum. Du hast einen nativen Klipper laufen - aber du hast die MCU für Klipper 13 geladen.

Wenn deine MCU-Version mit ```?-20230317_182329-ubuntu20-virtual-machine``` beginnt, bedeutet dies, dass du die MCU für Klipper 12 (AD5X) oder Klipper 11 (Ad5M/Ad5mPro) geladen hast.

Sie brauchen also zMod, um native Klipper zu laden.

- Gehen Sie zu ```mod_data/variables.cfg``` und löschen Sie die Zeile ```klipper13 = 1```.
- Speichern Sie die Datei
- Schalten Sie den Drucker aus und schalten Sie ihn wieder ein (nicht neu starten!).

<img width="422" height="570" alt="image" src="https://github.com/user-attachments/assets/6a96aa9d-7d07-4bf7-8039-042d28f4a87f" />

Wenn dies nicht der Fall ist und Klipper läuft, dann führen Sie ```UPDATE_MCU FORCE=13``` aus - dieser Befehl installiert die aktuelle MCU-Version

Wenn nichts hilft und **Klipper nicht funktioniert**:

- Wechsle zu nativem Klipper wie oben beschrieben.
- Installiere die native Werks-Firmware](/de/Native_FW/#how-to-install-native-firmware), was die native MCU installieren wird.

---

#### Das Filament ist ausgegangen oder wurde gestoppt

Beim AD5M müssen Sie die Sensorstufen nach Auswahl kalibrieren. Schreiben Sie in `mod_data/user.cfg`.

Erhöhen Sie diese Zahl. Einige Leute sind mit dem Standard `8` zufrieden, und einige Sensoren arbeiten nur bei `17` korrekt.
```
[filament_motion_sensor e0_sensor].
Erkennung_Länge: 8
```

Der Faden (IFS) ist stehen geblieben.

Für AD5X müssen Sie die Schritte des IFS-Sensors durch Auswahl kalibrieren. Schreiben Sie in `mod_data/user.cfg`.

Erhöhen Sie diese Zahl. Einige Leute sind mit dem Standardwert `10` zufrieden, und einige IFS arbeiten nur bei `17` korrekt.
```
[zmod_ifs_motion_sensor ifs_motion_sensor].
detektion_länge: 8
```

Auch das Anhalten des Fadens in IFS kann damit zusammenhängen:

- Es ist ein Stab 1 im Extruder, und ein Stab 2 wird herausgezogen. Verwenden Sie [SET_EXTRUDER_SLOT](/de/AD5X/#5-how-to-manually-indicate-to-the-printer-which-coil-is-now-filled-ad5x).
- In den Extruder ist ein Stab eingesetzt, in dem sich aber bereits der alte Stab befindet
- Die 4-in-1-Module und die Schläuche zu ihnen haben unterschiedliche Längen, daher müssen Sie den Parameter ```filament_unload_into_tube``` in ```mod_data/filament.json``` anpassen, indem Sie ihn auf 70 oder mehr setzen. [Mehr lesen](/de/AD5X/#wichtigste-einstellungen-was-man-oft-ändern-muss-ad5x)

Das Problem kann auch dadurch verursacht werden, dass der Balken im IFS-Kanal nicht entsperrt werden kann.

Die Gründe dafür sind rein mechanisch:

- Eindringen von Kunststoffspänen auf die Klemmwelle
- Abrutschen der Feder vom Kanalhebel.

Es ist notwendig, die Späne zu entfernen, die Teile zu demontieren und wieder einzubauen.

Testen Sie anschließend den Druck und die Verriegelung/Entriegelung der Stange über [IFS-Befehle](/ru/AD5X/#10-ifs-commands).

---

### Misst die Tabelle vor jedem Druckauftrag zentriert

Vor dem Drucken misst der Drucker:

- heizt er den Tisch und die Düse auf.
- reinigt die Düse.
- kühlt die Düse
- ** misst die Mitte des Tisches** (Start des manuellen Z-Tasters. Verwenden Sie TESTZ, um die Position einzustellen)
- heizt die Düse
- startet den Druck

Dies ist eine Funktion der **nativen Firmware** ab der Version **native Firmware**:

- 1.1.8 AD5X
- 3.2.4 AD5M/AD5MPro

Lösung:

- [Native Firmware zurücksetzen](/ru/Native_FW/) auf Version **1.1.7.7** für AD5X, **3.2.3.3** für FF5M/FF5MPro
- [Native Anzeige deaktivieren](/ru/System/#display_off)

---

### E0120

Dies ist ein Klipper-Fehler.

Er wird meist durch die folgenden einfachen Maßnahmen behoben:

- Schalten Sie den Drucker aus
- 10 Sekunden warten
- Schalten Sie den Drucker wieder ein

Um zu sehen, was genau der Fehler ist:

- öffnen Sie Fluidd/Mainsail
- gehen Sie auf die Konsole und lesen Sie den Fehlertext
- Öffnen Sie den Telegram-Bot [@zmod_help_bot](http://t.me/zmod_help_bot) und geben Sie den Fehlertext ein oder suchen Sie selbst in der Dokumentation nach der Beschreibung.

Wenn Sie den Fehler nicht beheben können, [müssen Sie ein Ticket erstellen](/ru/Help/).

[Einheimische Konfigurationen](https://github.com/ghzserg/zmod/tree/main/Native_firmware/config/)

