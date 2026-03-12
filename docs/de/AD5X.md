### AD5X

1. [Wichtige Merkmale](#1-important-features-ad5x)
2. [Wie man eine Datei in Orca vorbereitet](#2-how-to-prepare-a-file-in-orca-ad5x)
3. [Farbauswahlmenü (`COLOR`)](#3-how-to-use-the-colour-selection-menu-macros-color-ad5x)
4. [Menü Drucken (`PRINT`)](#4-print-menu-macro-print-ad5x)
    - Globale AD5X-Parameter](#global-parameters-ad5x)
5. [Manuelle Angabe der Spule](#5-how-to-manually-indicate-to-the-printer-whis-coil-is-now-filled-ad5x)
6. [Einstellen der Abfallmenge beim Filamentwechsel](#6-how-to-set-the-amount-of-waste-at-filament-change-ad5x)

    - 🔧 [Grundeinstellungen](#most-important-settings-what-to-change-most-often-ad5x)
       - ⚙️ [Erweiterte Einstellungen](#einstellungen-fuer-erweiterte-don't-change-if-you're-not-sure-of-the-result-ad5x)

7. [Fügen Sie Ihre Filamenttypen hinzu](#7-add-your-filament-types-ad5x)
8. [Fügen Sie Ihre Farben hinzu](#8-add-your-colours-ad5x)
9. [Einparken im Korb und Schneiden des Filaments](#9-fix-working-with-basket-and-knife-to-cut-filament-ad5x)

    - Über das Engineering-Menü der nativen Firmware](#customise-the-basket-on-native-firmware-ad5x)
       - Über Flash auf nativer Firmware](/de/Setup/#attention-ad5x)

10. [IFS-Befehle](#10-ifs-commands)
11. [IFS-Firmware wiederherstellen](#11-restore-firmware-ifs)

[Plugins](https://github.com/ghzserg/g28_tenz/blob/main/Plugin_ru.md):

- [bambufy](https://github.com/function3d/bambufy) - Kompatibel mit Bambu Studio, verbessert die Steuerung des Zufuhrturms, bietet eine genaue Zeit- und Materialverbrauchsabschätzung, reduziert Abfall, unterstützt Mainsail,
schnelle Farbwechsel und erweiterte Druckfunktionen.

- [nopoop](https://github.com/ghzserg/nopoop) - Maximiert die Abfallreduzierung von ninjamida
- [lessWaste](https://github.com/Hrybmo/lessWaste/) - Eine Abspaltung von bambufy

---

## **1. Wichtige Merkmale von AD5X**

Unterschiede zum AD5M:

* Keine `Entware`.
* Anstelle des Makros `CLOSE_DILALOGS` (langsames Schließen), **immer** `FAST_CLOSE_DILAOGS` (schnelles Schließen) verwenden.
* Das Makro `NEW_SAVE_CONFIG` funktioniert **nicht**.
* Um die Kamera einzuschalten, müssen Sie ```CAMERA_ON VIDEO=video3``` oder ```CAMERA_ON VIDEO=video0``` oder ```CAMERA_ON VIDEO=video99``` verwenden.
* Klipper kann abstürzen. Lösung `Process Profile` -> `Other` -> `Output G-cod` -> `Model Exclusion` das Häkchen ausschalten.

---

## **2. Wie wird eine Datei in Orca AD5X vorbereitet?

[Dateien zum Drucken über "Octo/Klipper" senden](/de/Recomendations/#Dateien-zum-Drucken-octoklipper-senden).

**Sie müssen unbenutzte Spulen aus der Liste in Orca entfernen.**

**Beispiel:**
Im Drucker befinden sich 4 Spulen (#1, #2, #3, #4). Zum Drucken werden nur die Farben der Spulen Nr. 1 und Nr. 3 benötigt.

* In der Datei werden sie als **T0** (erste Farbe) und **T1** (zweite Farbe) bezeichnet.
* Im Menü müssen Sie für **T0** -> Spool #1 und für **T1** -> Spool #3 auswählen.

---

## **3. Verwendung des Farbauswahlmenüs (Makro "COLOR") AD5X**

<img width="874" height="286" alt="image" src="https://github.com/user-attachments/assets/c0538a17-88a9-4aee-a65c-cff4cc1773d0" />

<img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/b6eb3ddd-ad7d-4cc2-b1b5-9f1aef918b29" />

<img width="563" height="550" alt="image" src="https://github.com/user-attachments/assets/cc0c951f-48c1-469d-8940-90832ad1d3f5" />

<img width="800" height="480" alt="Farbe" src="https://github.com/user-attachments/assets/4145baef-a695-49e6-a914-c12dd3f6b8a4" />

* `Extruder: 1 (PETG/Orange)` - Dies bedeutet, dass der Drucker jetzt mit orangefarbenem PETG-Kunststoff von Spule Nummer 1 gefüllt ist.
* `IFS: True` - Das automatische Filamentzufuhrsystem funktioniert.

**Wählen Sie nun die Spule aus, mit der Sie arbeiten möchten (z. B. Spule 2).**

<img width="568" height="455" alt="image" src="https://github.com/user-attachments/assets/f7ea3ed0-28a5-48d5-99db-eade0a199e99" />

<img width="800" height="480" alt="Bildschirmfoto" src="https://github.com/user-attachments/assets/c42cbefa-a29c-4df0-a62a-d99842c13961" />

Sie können vier Maßnahmen ergreifen:

1.  **Die Farbe** der Spule ändern.
2.  **Ändern Sie die Art** des Kunststoffs (z. B. von PLA zu PETG).
3.  **Laden** Sie dieses Filament in den Drucker.
4.  **Entladen** Sie das Filament aus dem Drucker.

**Wie man die Farbe ändert:**

1.  Drücken Sie "Farbe ändern".
2.  **Wählen Sie eine Farbe aus der Liste aus.** Auf diese Weise wird der Drucker und der native Bildschirm Sie am besten verstehen.
<img width="561" height="823" alt="image" src="https://github.com/user-attachments/assets/8dbff228-dfc0-4705-92f9-d94df80b7a4e" />

<img width="800" height="480" alt="Bildschirmfoto" src="https://github.com/user-attachments/assets/f51f91a2-4131-4ba3-a8a0-3b9519f61f6d" />

3.  Nach der Auswahl gehen Sie zurück und die Farbe der Spule in der Liste **sollte sich ändern**.
<img width="556" height="545" alt="bild" src="https://github.com/user-attachments/assets/f32a9239-44c6-449d-bbf7-5f453f149ef7" />

<img width="800" height="480" alt="Bildschirmfoto" src="https://github.com/user-attachments/assets/4fa7bb58-ee03-4613-ba06-a5af9b2ddfa6" />

**Wenn sich die Farbe nicht ändert:** schließen Sie das Fenster mit einem Kreuz und führen Sie das Makro `COLOR` erneut aus. Manchmal wird der Bildschirm nicht rechtzeitig aktualisiert.

**So ändern Sie den Typ:**

1.  Klicken Sie auf "Typ ändern".
2.  **Wählen Sie einen Typ aus der Liste aus.

<img width="562" height="710" alt="image" src="https://github.com/user-attachments/assets/baf7b807-c4f5-4ab4-8bfd-2fc43bb448cd" />

<img width="800" height="480" alt="Bildschirmfoto" src="https://github.com/user-attachments/assets/2d7b4f12-a8f1-4c99-a555-7c422bd5ffe4" />

**Wenn sich der Typ nicht ändert:** schließen Sie das Fenster mit einem Kreuz und führen Sie das Makro `COLOR` erneut aus. Manchmal wird der Bildschirm nicht rechtzeitig aktualisiert.

**Tipp:**Wenn Sie **die gleiche Farbe und den gleichen Typ** für mehrere Spulen angeben, wechselt der Drucker automatisch zur nächsten Spule, wenn die erste aufgebraucht ist. Dies wird als **"Endlosspulenmodus "** bezeichnet.

---

## **4. Menü "Drucken" (Makro "PRINT") AD5X**

Dieses Fenster öffnet sich **selbst**, wenn Sie den Druckvorgang starten.
<img width="567" height="564" alt="image" src="https://github.com/user-attachments/assets/a046c089-22d3-474e-89b6-89815412d068" />

<img width="800" height="480" alt="Bildschirmfoto" src="https://github.com/user-attachments/assets/f1ad0f49-e2bd-43c8-9301-7c58b9c05c22" />

**Wie ist das zu verstehen:**

* `Cube.gcode` ist der Name der Datei, die gedruckt wird.
* * "T0" ist die erste Farbe aus der Datei. Sie wird mit Filament von **Spule #4** (orangefarbenes PLA) gedruckt.
* T1" ist die zweite Farbe. Sie wird mit dem Filament von **Spule #3** (schwarzes PLA) gedruckt.
* T2" ist die dritte Farbe, sie wird aus der **Spule #2** (grünes PLA) gedruckt.
* T3" ist die vierte Farbe, die ebenfalls von der **Spule #2** (grünes PLA) gedruckt wird.

**Wenn Sie während des Drucks die Farbspule wechseln müssen:**

**Drücken Sie einfach auf das gewünschte T** (z.B. T1) und wählen Sie eine andere Spule aus der Liste.
<img width="553" height="550" alt="image" src="https://github.com/user-attachments/assets/4d831fdb-6ff5-4a0d-ac9e-10154d1c7956" />

<img width="800" height="480" alt="Bildschirmfoto" src="https://github.com/user-attachments/assets/a87d6115-87e4-4cb1-af3e-b194edefb42b" />

### Globale AD5X-Parameter

Verwenden Sie den globalen Parameter [SILENT](/de/Global/#silent), um zu verhindern, dass das Farbauswahlfenster beim Druckstart angezeigt wird.

- 0 - Fenster anzeigen (Standard)
- 1 - Fenster nicht anzeigen, vorher eingestellte Farben verwenden
- 2 - Fenster nicht anzeigen, keine IFS-Farben verwenden

```gcode
SAVE_ZMOD_DATA SILENT=1
```

Verwenden Sie den globalen Parameter [AUTOINSERT](/de/Global/#autoinsert), um das automatische Einsetzen der Stangen im Extruder zu deaktivieren

```gcode
SAVE_ZMOD_DATA AUTOINSERT=0
```

Um das Abladen von Filament in den Papierkorb beim Drucken zu deaktivieren, verwenden Sie den Parameter [USE_TRASH_ON_PRINT](/de/Global/#use_trash_on_print).

- 0 - Es findet kein Auswurf in den Abwurfschacht statt. Der Druckkopf fährt bei Farbwechseln in der ersten Schicht dennoch zum Abwurfschacht, um Blobs zu reduzieren. Falls dies in jeder Schicht passiert, überprüfen Sie bitte Ihren Start- und Schichtwechsel-G-Code!
- 1 - Bei Farbwechseln erfolgt ein Auswurf in den Abwurfschacht. Bei jedem Farbwechsel werden zwei Auswürfe mit der Länge `filament_drop_length` aus der filament.json (plus `filament_drop_length_add`, falls die Materialien unterschiedlich sind) durchgeführt.
- 2 - Nach dem Einziehen der neuen Farbe fährt der Druckkopf zum Abwurfschacht und übergibt von dort aus die Steuerung wieder an den Slicer. Dies sollte nur zusammen mit einem speziell für diesen Modus entwickelten Slicer-Profil verwendet werden.

```gcode
SAVE_ZMOD_DATA USE_TRASH_ON_PRINT=0
```

Um das Filament nach Abschluss des Druckvorgangs zu entfernen, verwenden Sie den Parameter [REMOVE_FILAMENT](/de/Global/#remove_filament).

```gcode
SAVE_ZMOD_DATA REMOVE_FILAMENT=1
```

Mit dem Parameter [ALLOWED_TOOL_COUNT](/Global/#allowed_tool_count) kann die Anzahl der im Farbauswahlfenster angezeigten Werkzeuge eingestellt werden (wenn die Informationen nicht durch das Scannen der Datei ermittelt werden können).

[Siehe Vorverarbeitungseinstellung](https://wiki.zmod.link/de/Recomendations/#enable-md5-checksum-control)

```gcode
SAVE_ZMOD_DATA ALLOWED_TOOL_COUNT=16
```

Mit dem Parameter [SCAN_FILE_COLORS](/Global/#scan_file_colors) können Sie gcode-Dateien nach Werkzeug-, Farb- und Materialinformationen durchsuchen. Sie können den Wert auch auf 2 setzen, um nur die vom Slicer-Skript vorbereiteten Daten zu scannen, ohne die gesamten Dateien zu scannen.

[Siehe Einstellung für die Vorverarbeitung](https://wiki.zmod.link/de/Recomendations/#enable-md5-checksum-control)

```gcode
SAVE_ZMOD_DATA SCAN_FILE_COLORS=1
```

Mit dem Parameter [AUTO_ASSIGN_COLORS](/Global/#auto_assign_colors) können Sie die automatische Zuordnung von Farben aus der Gcode-Datei zu physischen Spulen aktivieren. Das Scannen von Dateien muss aktiviert sein, damit diese Funktion funktioniert. Bei einem Wert von 30 wird der Druck im stillen Modus unterbrochen, wenn es Probleme mit der automatischen Zuweisung gibt.

Sie können Ihre eigenen Werte für die Unterbrechung des Druckvorgangs im stillen Modus konfigurieren, indem Sie die folgenden Zahlen addieren:

* 2 (Mindestens ein Material stimmt nicht überein, z. B. wenn in der gcode-Datei ABS angegeben ist, Sie aber nur PLA geladen haben, oder die Materialdaten nicht geladen werden konnten)
* 4 (Mindestens eine Farbe stimmt überhaupt nicht überein, in der Regel weil das Scannen von Dateien deaktiviert oder fehlgeschlagen ist)
* 8 (Mindestens eine Farbe stimmt nicht gut überein)
* 16 (Dieselbe physische Spule wurde mehr als einem Werkzeugindex in der Datei zugewiesen)

[Siehe Vorverarbeitungseinstellung](https://wiki.zmod.link/de/Recomendations/#enable-md5-checksum-control)

```gcode
SAVE_ZMOD_DATA AUTO_ASSIGN_COLORS=30
```

Wenn der Farbwechselbefehl feststellt, dass die neue Farbe mit einer bereits geladenen Farbe übereinstimmt, wird der Wechselvorgang normalerweise als sinnlos übersprungen. Wenn Sie aus irgendeinem Grund wollen, dass der Farbwechselprozess immer vollständig durchgeführt wird, verwenden Sie den Parameter [ALWAYS_FULL_COLOR_CHANGE](/Global/#always_full_color_change).

```gcode
SAVE_ZMOD_DATA ALWAYS_FULL_COLOR_CHANGE=0
```

## **5. wie man dem Drucker manuell mitteilt, welcher Spool gerade mit AD5X gefüllt ist**

Es kann vorkommen, dass Sie den Spool selbst geändert haben und der Drucker dies nicht bemerkt und die alte Information anzeigt.

Es gibt einen speziellen Befehl, um dies zu beheben.

**Geben Sie einfach diesen Satz in die Konsole ein:**

```
SET_EXTRUDER_SLOT SLOT=1
```

**Was das bedeutet:**

* `SET_EXTRUDER_SLOT` ist ein Befehl, der sagt: "Drucker, speichere die Spule!
* `SLOT=1` ist die Nummer der Spule, die Sie gerade nachgefüllt haben. **Die Nummer kann geändert werden!

**Beispiele:**

* Wenn Sie Filament von Spule Nummer 3 aufgefüllt haben, geben Sie ein: `SET_EXTRUDER_SLOT SLOT=3`.
* Wenn von Spule Nummer 2, geben Sie ein: `SET_EXTRUDER_SLOT SLOT=2`.

Nach diesem Befehl weiß der Drucker, welcher Spool gerade läuft und vermischt die Farben nicht mehr.

## **6. Einstellen der Abfallmenge beim Wechsel des AD5X**-Filaments

Diese Einstellungen werden benötigt, um beim Wechseln der Spulen weniger Kunststoff zu verschwenden. Um sie zu ändern, müssen Sie zunächst **den systemeigenen Bildschirm des Druckers** mit dem Makro `DISPLAY_OFF` deaktivieren.

Im bildschirmlosen Modus sind die Sensoren verfügbar und aktiviert:

- "Kopfschaltersensor" - Vorhandensein von Filament im Extruder
- IFS-Bewegungssensor" - Filamentbewegung im IFS

**Wie Sie diese Einstellungen finden:**

1.  Klicken Sie auf die Registerkarte **"Konfiguration "**.
2.  Suchen Sie den Ordner **"mod_data "** und öffnen Sie ihn.
3.  Suchen und öffnen Sie in diesem Ordner die Datei **`filament.json`**.

[Wo finde ich die Datei](https://github.com/user-attachments/assets/109b0f0a-c87d-4f5c-9333-ebfbb8065b87)

In dieser Datei gibt es eine Liste von Nummern für jede Art von Kunststoff (PLA, ABS, PETG, etc.). Hier ist ihre Bedeutung:

---

#### **Wichtigste Einstellungen (was am häufigsten zu ändern ist) AD5X:**

Damit diese Einstellungen funktionieren, müssen Sie den **eigenen Bildschirm des Druckers** mit dem Makro `DISPLAY_OFF` abschalten.

1.  ** `temp`** - Die Temperatur, auf die sich die Filament-Wechsel-Düse aufheizt. **Der Standardwert hängt von der Materialart ab.
2.  ** `filament_drop_length` - Die Temperatur, auf die die Düse für den Fadenwechsel aufgeheizt wird.

    * **Einfach:** Wie viele Millimeter Plastik der Drucker in den Abfallbehälter drückt, um die Düse von alter Farbe zu **reinigen**. Dies gilt beim Laden von Farben außerhalb des Druckvorgangs oder vor einem Druck, oder beim Farbwechsel, wenn USE_TRASH_ON_PRINT auf 1 gesetzt ist.
        ** **Tipp:** Wenn die Farben beim Wechseln der Spulen gemischt werden, erhöhen Sie diese Zahl. Wenn Sie weniger Abfall wünschen, verringern Sie diesen Wert.

3.  **`Filament_drop_length_add` (Optional zurücksetzen)**

    * **Einfach ausgedrückt:** Wie viel **mehr** Plastik der Drucker in den Müll wirft, wenn Sie nicht nur die Farbe, sondern auch den **Materialtyp** ändern (z. B. von PLA zu PETG). Dies gilt beim Laden von Farben außerhalb des Druckvorgangs oder vor einem Druck, oder beim Farbwechsel, wenn USE_TRASH_ON_PRINT auf 1 gesetzt ist.
        **Warum wird es benötigt:** Verschiedene Materialien lassen sich nicht gut mischen, daher muss die Düse besser gereinigt werden.

4.  **`nozzle_cleaning_length`** - Die Länge (in mm), die das Filament beim Reinigen der Düse aus dem Extruder gezogen wird, wenn die Spule nicht mehr in Gebrauch ist. **Voreinstellung: 60 mm.

5.  **`filament_unload_into_tube`** — Wie viel Filament aus dem 4-in-1-Modul entladen werden soll, wenn der Extruder nicht mehr verwendet wird. **Standard: 70 mm.**

    *   Wenn Sie ein 4-in-1-Modul der neuen Version haben, erhöhen Sie `filament_unload_into_tube` oder im äußersten Fall erhöhen Sie `nozzle_cleaning_length`


---

##### **Erweiterte Einstellungen (nicht ändern, wenn Sie sich des Ergebnisses nicht sicher sind) AD5X:**

Damit diese Einstellungen funktionieren, müssen Sie **den systemeigenen Bildschirm des Druckers** mit dem Makro `DISPLAY_OFF` deaktivieren.

* **`filament_tube_length`** - Die volle Länge des Teflonschlauches vom IFS-Modul zum Extruder. Nützlich für nicht standardisierte Schläuche. **Voreinstellung: 1000 mm.**
* **`Filament_unload_before_cutting`** - Wie viele Millimeter wird das Filament angehoben, **bevor** es geschnitten wird. **Standard: 0 mm.**
* **`filament_unload_after_cutting`** - Wie viele Millimeter wird der Faden **nach** dem Schneiden angehoben, bevor er in den Korb gelegt wird. **Standard: 5 mm.**
* **`filament_unload_after_drop`** - Zieht das Filament nach dem Ablegen in den Korb vor dem Druck wieder nach oben. Wird benötigt, um ein Abtropfen der Düse zu verhindern. **Standard: 3mm.**
* **`filament_extruder_speed`** — Geschwindigkeit (in mm/min), mit der Filament in den Extruder geladen wird. **Standard: 300 mm/min (5 mm/s).**
* **`filament_ifs_speed`** — Geschwindigkeit (in mm/min), mit der das IFS-Modul arbeitet. **Standard: 12000 mm/min (20 mm/s).**
* **`filament_fan_speed`** - Die Gebläsegeschwindigkeit (0 bis 255) beim Ablassen in den Korb. Er bläst um die Düse herum, um den Unterlauf zu kühlen. **Standard: 102**.
* **`Filament_autoinsert_empty_length`** - Wie viele Millimeter Filament werden beim automatischen Einsetzen gezogen, wenn der Extruder leer ist. **Standard: 600 mm.
* **`Filament_autoinsert_full_length`** - Wie viele Millimeter Filament werden beim automatischen Befüllen eingezogen, wenn sich bereits ein anderes Filament im Extruder befunden hat. **Voreinstellung: 550 mm.**
* **`filament_autoinsert_ret_length`** - Wieviele Millimeter Filament werden zurückgezogen, wenn der Sensor im Extruder ausgelöst wird (nur wenn der Extruder leer ist). **Voreinstellung: 90 mm.**
* **`filament_autoinsert_speed`** - Die Geschwindigkeit (in mm/m), mit der das Filament automatisch in den Extruder eingezogen wird. **Standard: 1200 mm/m (20 mm/s).**

**WARNUNG!** Das Ändern der Einstellungen im erweiterten Bereich kann zu fehlerhaftem Betrieb des Druckers, Filamentstaus oder Ausfällen führen. Ändern Sie die Einstellungen nur, wenn Sie genau wissen, wofür die einzelnen Parameter verantwortlich sind und welche Folgen sie haben können.

**Hauptgedanken:** Wenn Sie weniger Abfall haben wollen, beginnen Sie damit, die **`filament_drop_length`** und **`filament_drop_length_add`** Zahlen für Ihren Kunststoff zu reduzieren. Vergessen Sie nicht, die Datei nach den Änderungen zu speichern!

---

#### **Slicer-gesteuerte Reinigung (Purge)**

Es ist möglich, die Reinigung stattdessen vom Slicer steuern zu lassen, indem andere USE_TRASH_ON_PRINT-Einstellungen anstelle des Standardwerts (1) verwendet werden.

##### Nopoop-Modus (`SAVE_ZMOD_DATA USE_TRASH_ON_PRINT=0`)

In diesem Modus wird vom Drucker während des Farbwechsels keine Reinigung durchgeführt. Der Drucker schneidet das Filament ab, kehrt zum Reinigungsturm (Prime Tower) zurück, um das Filament ent- und zu laden, und setzt den Druck dann sofort von dort aus fort.

In der ersten Schicht fährt der Drucker während des Filamentwechsels stattdessen zum Abwurfschacht, kehrt aber danach zum Reinigungsturm zurück, ohne "Poop" (Abfall) zu produzieren.

Um das alte Filament in diesem Modus ordnungsgemäß zu reinigen, wird empfohlen, die Option "Reinigung im Reinigungsturm" (Purge into prime tower) in den Einstellungen von OrcaSlicer zu aktivieren. Diese finden Sie in den Druckereinstellungen unter dem Reiter "Multimaterial". Sie können dann die Einstellung "Flush Volumes" verwenden, um die Reinigungsmengen anzupassen. Wenn Sie den automatisch berechneten Spülmengen einen festen Betrag hinzufügen möchten, können Sie dies tun, indem Sie das "Düsenvolumen" (Nozzle Volume) unter dem Reiter "Allgemein" der Druckereinstellungen festlegen.

Es ist normal, dass Ihr Reinigungsturm bei Verwendung dieser Option erheblich größer als gewöhnlich ist, insbesondere bei geringen Schichthöhen.

Zusätzlich können Sie in diesem Modus Optionen wie "In Infill reinigen" (Purge to infill), "In dieses Objekt reinigen" (Purge to this object) usw. verwenden, um die Menge des in den Reinigungsturm gespülten Abfalls zu reduzieren.

Diese Option wird nur in OrcaSlicer unterstützt; sie kann in Bambu Studio aufgrund des Fehlens von "Reinigung im Reinigungsturm" nicht verwendet werden.

##### Slicer-gesteuerter Poop-Modus (`SAVE_ZMOD_DATA USE_TRASH_ON_PRINT=2`)

In diesem Modus führt der Drucker während des Farbwechsels keine eigene Reinigung durch. Der Drucker schneidet das Filament ab, fährt zum Abwurfschacht und übergibt die Steuerung wieder an den Slicer.

Dieser Modus erfordert eine entsprechende Unterstützung durch das Druckerprofil im Slicer; insbesondere ist ein Filamentwechsel-G-Code erforderlich, der den Abwurf (Pooping) und die anschließende Rückkehr zum Reinigungsturm verwaltet. Verwenden Sie diesen Modus NICHT mit einer G-Code-Datei, die nicht speziell dafür gesliced wurde.

Bei der Verwendung von OrcaSlicer können Optionen wie "In Infill reinigen" in diesem Modus nicht verwendet werden. Dies ist ein Fehler in OrcaSlicer und kann nicht durch zMod behoben werden. In Bambu Studio funktionieren sie korrekt.

##### Druckerprofile

Druckerprofile, die für die Slicer-gesteuerte Reinigung eingerichtet sind, stehen für [OrcaSlicer](https://github.com/ghzserg/zmod_preprocess/tree/main/profiles/orcaslicer) und [Bambu Studio](https://github.com/ghzserg/zmod_preprocess/tree/main/profiles/bambustudio) zur Verfügung. Diese Profile entsprechen weitgehend den Standard-AD5X-Profilen, mit folgenden Ausnahmen:
- Alle benutzerdefinierten zMod-G-Codes hinzugefügt, einschließlich des entsprechenden Filamentwechsel-G-Codes für USE_TRASH_ON_PRINT=2
- "Reinigung im Reinigungsturm" aktiviert (nur OrcaSlicer)
- Automatische Einstellung des korrekten USE_TRASH_ON_PRINT-Wertes zu Beginn des Drucks
- Z-Hop-Typ auf Normal eingestellt
- Düsenvolumen auf 144 eingestellt
- Filament-Entladezeit auf 66s eingestellt für genauere Schätzungen (basierend auf den Standardeinstellungen der filament.json)
- Lüfter-Anlaufzeit auf 1,5s und Kickstart auf 0,5s eingestellt (nur OrcaSlicer)

In OrcaSlicer können Sie zwischen den beiden Modi wechseln, indem Sie die Einstellung "Reinigung im Reinigungsturm" ändern. Wenn diese aktiviert ist, wird der Nopoop-Modus verwendet. Wenn sie deaktiviert ist, wird der Poop-Modus verwendet. Das Profil stellt den korrekten USE_TRASH_ON_PRINT-Wert zu Beginn eines Drucks automatisch für Sie ein.

Bei der Verwendung von Bambu Studio wird nur der Poop-Modus unterstützt.

**Wenn Sie einen Druck mit diesen Profilen im Slicer-gesteuerten Poop-Modus durchführen, stellen Sie sicher, dass Sie Ihre USE_TRASH_ON_PRINT-Einstellung wieder auf 0 oder 1 zurücksetzen, bevor Sie mehrfarbigen G-Code drucken, der nicht mit diesen Profilen gesliced wurde.**

## **7. Fügen Sie Ihre AD5X-Filamenttypen hinzu**

Damit diese Einstellungen funktionieren, müssen Sie **den systemeigenen Bildschirm des Druckers** mit dem Makro `DISPLAY_OFF` deaktivieren.

Um einen neuen Filamenttyp hinzuzufügen, fügen Sie Folgendes in der ```mod_data/user.cfg``` hinzu:
```
[zmod_ifs].
filament_NEWTYPE: 300
```
Dabei wird NEWTYPE durch den gewünschten Filamenttyp (z.B. HIPS) ersetzt und die Zahl ist der Schmelzpunkt des Filaments.

```IFS_PRINT_DEFAULTS``` - gibt die verfügbaren Filamenttypen und deren Schmelztemperaturen aus

---

## **8. Fügen Sie Ihre AD5X-Farben hinzu**

Damit diese Einstellungen funktionieren, müssen Sie **den druckereigenen Bildschirm** mit dem Makro `DISPLAY_OFF` deaktivieren.

Um eine Farbe hinzuzufügen oder umzubenennen, öffnen Sie ```mod_data/color/de.json``` (verwenden Sie Ihre Sprache anstelle von ru):

und fügen Sie eine neue Farbe hinzu oder benennen Sie eine bestehende Farbe um.

Um den Namen einer Farbe anzuzeigen, muss der Farbname mit einem Unterstrich ```_``` beginnen.

Beispiel:
```
{
  "ffffff": "weiß",
  "fffff1": "_transparent",
  "fef043": "hellgelb",
  "dcf478": "hellgrün",
  "0acc38": "green",
  "067749": "dunkelgrün",
  "0c6283": "blau-grün",
  "0de2a0": "türkis",
  "75d9f3": "blau",
  "45a8f9": "blau",
  "2750e0": "dunkelblau",
  "46328e": "lila",
  "a03cf7": "helles Lila",
  "f330f9": "magenta",
  "d4b0dc": "flieder",
  "f95d73": "rosa",
  "f72224": "rot",
  "7c4b00": "braun",
  "f98d33": "orange",
  "fdebd5": "beige",
  "d3c4a3": "hellbraun",
  "af7836": "terracotta",
  "898989": "grau",
  "bcbcbc": "hellgrau",
  "161616": "schwarz"
}
```

Die Aufschrift ```_transparent``` wird auf den Schaltflächen angezeigt

---

## 9. Korrigiert den Betrieb mit dem Korb und dem Filamentschneider AD5X

[Alternative Betriebsanleitung](/de/Setup/#attention-ad5x)

Die Korb- und Messerkoordinaten können bei verschiedenen AD5X-Druckern unterschiedlich sein. Manchmal kann der Unterschied bis zu 4 mm betragen.

Dies ist der Grund dafür:

- Das Filament gelangt möglicherweise nicht in den Korb;
- Das Messer schneidet das Filament nicht;
- Der Druckkopf kann gegen die Wand stoßen.

Um dies zu beheben, müssen Sie:

1. zMod aktualisieren.
2. öffnen Sie die Datei `/rw/Adventurer5M.json`.
3. finden Sie Zeilen wie:
```json
{
	"CutXOffset" : 0.5,
	"CutYOffset" : -0.20000001788139343,
	"xOffset" : 0.0,
	"yOffset" : -0.20000001788139343,
	"zOffset" : 0.0,
	"zProbeOffset" : 0.004999995231628418
},
```
<img width="504" height="241" alt="image" src="https://github.com/user-attachments/assets/8647b1fe-594c-4bb3-91ee-560cfe4a58fd" />

Ersetze **nur** diese Werte:
```json
"CutXOffset": 0.0,
"CutYOffset": 0.0,
"yOffset": 0.0,
```

4. Geben Sie den Befehl: `UPDATE_FF_OFFSET` (damit werden die Einstellungen aktualisiert).
5. Geben Sie dann ein: `_GOTO_TRASH` (dies bringt den Drucker zurück in den Papierkorb).

---

### Einstellung des AD5X-Papierkorbs

[Alternative Anweisungen](/de/Setup/#attention-ad5x)

1. Geben Sie den Befehl `_GOTO_TRASH` ein - der Druckkopf fährt in den Papierkorb.
2. Wenn sich der Mülleimer nicht schließt, bewegen Sie den Druckkopf vorsichtig, bis sich der Mülleimer schließt. Sie müssen den GCODE verwenden: ```G1 Y230.2```.
3. Schauen Sie, welche **Y**-Koordinate Sie jetzt haben.
4. 229 von dieser Zahl subtrahieren. Das Ergebnis ist Ihr "yOffset".

Beispiele:

- Wenn Y = 230,2, dann ist "yOffset = 230,2 - 229 = 1,2".
- Wenn Y = 228,4, dann ist `yOffset = 228,4 - 229 = -0,6`.
- Formel: yAbweichung = Y - 229`.

Schreiben Sie diese Zahl in die Datei `/rw/Adventurer5M.json`. Der Korb ist eingerichtet.

5. Geben Sie den Befehl ein: `UPDATE_FF_OFFSET` (damit werden die Einstellungen aktualisiert).
6. Geben Sie dann ein: `_GOTO_TRASH` (dies bringt den Drucker zurück in den Papierkorb).

---

### Einrichten des AD5X-Messers

[Alternative Version der Anleitung](/de/Setup/#attention-ad5x)

1. Geben Sie den Befehl `_CUT_PRUTOK` ein - der Kopf wird zum Messer fahren.
2. Benutzen Sie den Bildschirm, um den Kopf zu bewegen, bis das Messer ausgelöst wird. Sie müssen GCODE verwenden: ```G1 Y-7.7``` ```G1 X-1.7```.
3. Schau nach, wie deine X- und Y-Koordinaten lauten.
4. Für **Y**:

    - Subtrahiere von **7,5** deine Y-Koordinate modulo deiner Y-Koordinate.
       - Beispiel: Wenn Y = -7,7, dann ist `CutYOffset = 7,5 - 7,7 = -0,2`.
       - Beispiel: Wenn Y = -5,9, dann ist `CutYOffset = 7,5 - 5,9 = 1,6`.
       - Formel: CutYOffset = 7,5 + Y".

5. Für **X**:

    - Subtrahiere deine X-Koordinate modulo deiner X-Koordinate von **2.5**.
       - Beispiel: Wenn X = -1,7, dann ist `CutXOffset = 2,5 - 1,7 = 0,8`.
       - Beispiel: Wenn X = -2,8, dann ist `CutXOffset = 2,5 - 2,8 = -0,3`.
       - Formel: CutXOffset = 2,5 + X".

Schreibe diese Zahlen in die Datei `/rw/Adventurer5M.json`. Das Messer ist eingestellt.

6. Gib den Befehl ein: `UPDATE_FF_OFFSET` (damit werden die Einstellungen aktualisiert).
7. Geben Sie dann ein: `_GOTO_TRASH` (dies bringt den Drucker zurück in den Papierkorb).

Starten Sie den Drucker neu und Sie sind fertig.

---

## Korb-Setup auf nativer AD5X-Firmware

1. Gehen Sie auf die Registerkarte "i" und drücken Sie die Schaltfläche "Status".
   
   <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/08a99d33-c970-4e86-933d-0064b447f5b7" />

2. Gehen Sie zu Registerkarte 6
   
   <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/a0eb4b8f-552b-4e58-86d7-2b47b8b0035c" />

3. Drücken Sie die Taste `Extruder in Abfallbehälterposition bringen` und halten Sie sie 20 Sekunden lang gedrückt.
   <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/81213d65-bf06-4d33-8e4a-eb3aae2782d7" />

4- Stellen Sie die Position des Kopfes im Abfallbehälter so ein, dass er sich schließt. Verwenden Sie die Steuerpfeile, um den Druckkopf gegen den Empfänger zu parken, so dass der Druckkopf genügend Druck auf den Verschlusshebel ausübt, die Düse hinter dem beweglichen Verschluss liegt und der Verschluss selbst mit der Vorderseite des Empfängers bündig ist.
   
   <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/7b506200-0d61-4b88-aaf8-40475e3ad463" />
   
   Drücken Sie die "Set"-Taste

5. Drücken Sie `Move the extruder to cutter stiker position` und halten Sie die Taste für 20 Sekunden gedrückt.
   <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/e61c61c0-f1a1-4535-b9ef-37baa4ab1d8c" />

4- Stellen Sie das Messer ein. Drücken Sie `CutX` - das Messer sollte das Filament schneiden, ohne sich zu verschieben oder anzustoßen.
   
   <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/a0c1939e-dada-48cb-8789-df43999bf99b" />
   
   Drücken Sie die Taste `Set`.

---

## **10. IFS-Befehle**

Damit diese Einstellungen funktionieren, müssen Sie **den druckereigenen Bildschirm** mit dem Makro `DISPLAY_OFF` deaktivieren.

- IFS_F10" - Leiste einfügen
- IFS_F11" - Leiste entfernen
- IFS_F13` - IFS-Status
- `IFS_F15` - Treiber zurücksetzen
- `F18` - Faden überall eindrücken
- `F23` - Stange als eingefügt markieren
- F24` - Faden einklemmen
- F39` - Filament quetschen
- F112` - Filamentzuführung stoppen
- PURGE_PRUTOK_IFS` - Stange vom IFS zum Extruder freigeben
- REMOVE_PRUTOK_IFS` - Entfernt Stange nach Stangennummer
- INSERT_PRUTOK_IFS` - Fügt Stange in IFS nach Stangennummer ein
- SET_CURRENT_PRUTOK` - Gibt dem Klipper an, welcher Stab gerade aktiv ist
- `ANALOG_PRUTOK` - Lädt eine ähnliche Stange
- IFS_MOTION` - Prüfen, ob das Filament angehalten hat oder ausgegangen ist

Parameter des IFS-Moduls:

- debug - Fehlersuche (True, *False*)
- silk_count - ab welchem Versuch auszulesen, dass der Stab im IFS ist (*1*)
- stall_count - ab welchem Versuch auszulesen, dass der Balken angehalten hat (*1*)
- retry_count - wie oft soll der Befehl im Falle eines Fehlers wiederholt werden (*3*)
- filament_NEWFILEMENT - Hinzufügen einer neuen Art von Filament Parameter - Temperatur des Ersatzes dieser Art von Kunststoff.

Eingestellt über `mod_data/user.cfg`:
```
[zmod_ifs].
debug: Wahr
silk_count: 1
stall_count: 1
filament_NEWTYPE: 300
```

## **11. IFS-Firmware wiederherstellen**

Um die IFS-Firmware wiederherzustellen, benötigen Sie ein **ARM J-LINK V9** Programmiergerät.

<img width="800" height="800" alt="image" src="https://github.com/user-attachments/assets/ae91768b-00d8-4e36-a62d-3056a7e117bf" />

<img width="960" height="479" alt="image" src="https://github.com/user-attachments/assets/f623fa41-4bc3-40a4-a434-5d8ad717792b" />

Löten der Drähte an die iFS-Platine

<img width="579" height="774" alt="image" src="https://github.com/user-attachments/assets/cb2b2f72-9eba-4831-8cea-072813b6e0e3" />

Anschließen:

- CLK an SWCK
- DIO an SWIO
- VCC an 3,3
- GND an GND

<img width="346" height="390" src="https://github.com/user-attachments/assets/19438d58-9879-48e5-8acc-bfb21ce4549c" />

- Zielgerät - "Nations N32G455RE".
- Zielschnittstelle: `SWD`
- Geschwindigkeit: `4000`
- Kreuzen Sie das erste Kästchen an.
- Deaktivieren Sie das zweite Kästchen

1. Verbinden Sie
2. Wählen Sie [Flash-Datei](/de/Native_FW/#5x-ifs). **Vergessen Sie nicht, sie zu entpacken**.
3. drücken Sie **F7** und warten Sie, bis das Gerät geflasht ist

## IFS: Sensorfehler: Serieller Kommunikationsfehler: Lesen fehlgeschlagen: Gerät meldet Lesebereitschaft, hat aber keine Daten zurückgegeben (Gerät getrennt oder Mehrfachzugriff auf Port?).

Dieser Fehler tritt auf, wenn der native Bildschirm und der Mod gleichzeitig auf den IFS zugreifen.

Es ist am besten, die Lebensdauer des nativen Bildschirms auf 10 Sekunden zu reduzieren: ```SAVE_ZMOD_DATA DISPLAY_OFF_TIMEOUT=10```.
