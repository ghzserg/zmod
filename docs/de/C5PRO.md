# Creator5
# Creator5 Pro

!!! note
    Dieses Dokument ist für Creator 5 und Creator 5 Pro relevant

## Wichtige Besonderheiten

- Der Drucker arbeitet immer mit **4 Farben** (T0, T1, T2, T3). Alle vier Slots sind im Auswahlmenü verfügbar.
- Um die Kamera einzuschalten, muss `CAMERA_ON VIDEO=video67` verwendet werden.
- Klipper kann abstürzen. Lösung: `Prozessprofil` -> `Sonstiges` -> `G-Code-Ausgabe` -> Häkchen bei `Objekte ausschließen` entfernen.
- Statt des Makros `CLOSE_DIALOGS` (langsames Schließen) immer `FAST_CLOSE_DIALOGS` (schnelles Schließen) verwenden.
- Das Makro `NEW_SAVE_CONFIG` funktioniert nicht.
- Keine Unterstützung für Klipper 13; Mitarbeit ist willkommen.

---

## Wie man eine Datei in Orca vorbereitet

- [Dateien über Octo/Klipper zum Drucken senden.](/de/Recommendations/#senden-sie-dateien-zum-drucken-über-octoklipper)
- [Profile für Orca Slicer](https://github.com/ghzserg/zmod_preprocess/tree/main/profiles/Creator_5)
- [Es wird dringend empfohlen, den Präprozessor zu aktivieren](/de/Global/#force_md5)

---
## COLOR
## Wie man das Menü zur Auswahl von Farbe und Filamenttyp verwendet

<img width="900" height="900" alt="ColorWeb" src="https://github.com/user-attachments/assets/93be6d16-8c78-48b5-b1ca-6068e1e7e538" />

<img width="794" height="900" alt="image" src="https://github.com/user-attachments/assets/e5a72e1c-5274-449d-8a47-1d3f5b649550" />

<img width="554" height="502" alt="{7A4A77A2-1F88-4110-9502-24FA941B9A67}" src="https://github.com/user-attachments/assets/fd77a89c-08d6-4da5-8eac-3017ca563657" />

Wählen Sie die Spule aus, mit der Sie arbeiten möchten (zum Beispiel Spule 2):

<img width="559" height="466" alt="{355F6AEF-00B2-4EFE-841E-23516CAC64FA}" src="https://github.com/user-attachments/assets/81084141-88b8-4d65-b583-495796f0d4fa" />

Sie können fünf Aktionen ausführen:

- Farbe der Spule ändern.
- Kunststofftyp ändern (PLA, PETG, ABS, ...).
- Diesen Extruder auf den Schlitten aufnehmen.
- Neues Filament in den Extruder laden.
- Diesen Extruder vom Schlitten abnehmen.

**Wie man die Farbe ändert:**

Klicken Sie auf „Farbe ändern“. Wählen Sie eine Farbe aus der Liste. So erkennen der Drucker und der native Bildschirm die Farbe am besten.

<img width="844" height="431" alt="{A27DB9D5-1C03-43D0-AF0D-5D2E16E6FFE4}" src="https://github.com/user-attachments/assets/d9a0ab97-3f78-4b51-b1a4-c4c2c4dc2b68" />

Nach der Auswahl kehren Sie zurück, und die Farbe der Spule in der Liste ändert sich.

Wenn sich die Farbe nicht geändert hat: Schließen Sie das Fenster mit dem X und starten Sie das Makro `COLOR` erneut. Manchmal schafft es der Bildschirm nicht, sich zu aktualisieren.

**Wie man den Typ ändert:**
Klicken Sie auf „Typ ändern“. Wählen Sie einen Typ aus der Liste. Die Typen können für den Modus ohne nativen Bildschirm angepasst werden.

<img width="848" height="511" alt="{95B6566B-4FC0-4811-BC6A-E65B79E3DED7}" src="https://github.com/user-attachments/assets/f4359f48-c998-4e52-a119-e088b38f0a26" />

Wenn sich der Typ nicht geändert hat: Schließen Sie das Fenster mit dem X und starten Sie das Makro `COLOR` erneut. Manchmal schafft es der Bildschirm nicht, sich zu aktualisieren.

**Tipp:** Wenn für mehrere Spulen dieselbe Farbe und derselbe Typ angegeben sind, wechselt der Drucker automatisch zur nächsten Spule, wenn die erste leer ist. Das nennt man „Endlosspulenmodus“.

---

## PRINT
## Druckmenü

Dieses Fenster öffnet sich automatisch, wenn Sie mit dem Drucken beginnen, sofern der Parameter `SAVE_ZMOD_DATA SILENT=0` (Standard) gesetzt ist.

<img width="851" height="582" alt="{8C3C174F-A553-405C-8228-7BC8EB293094}" src="https://github.com/user-attachments/assets/d8089f7d-fcf5-4a47-b664-a27db8b7e9d8" />

**Was hier angezeigt wird:**

- In der linken Spalte stehen Werkzeugnummern und Farben aus der Datei, die vom Slicer übergeben wurden.
- In der rechten Spalte stehen Spulennummern und Farben, die am Drucker geladen/verwendet werden.
- `Cube.gcode` – das ist der Name der Datei, die gedruckt wird.
- `1: PETG ->` – das ist die erste Farbe aus der Datei (oranges PETG). Sie wird mit Filament von Spule 3 gedruckt (oranges PETG).
- `2: PLA ->` – das ist die zweite Farbe (graues PLA). Sie wird mit Filament von Spule 4 gedruckt (blaues PLA), da sich keine anderen PLA-Kunststoffe im Drucker befinden.
- `3: PETG ->` – die dritte Farbe (schwarzes PETG), gedruckt von Spule 3 (oranges PETG), da sich keine anderen PETG-Kunststoffe im Drucker befinden.
- `4: PETG-CF ->` – die vierte Farbe (blaues PETG-CF), gedruckt von Spule 1 (schwarzes PETG-CF), da sich keine anderen PETG-CF-Kunststoffe im Drucker befinden.

Wenn das Bild so aussieht:

<img width="837" height="571" alt="{013853B5-7E63-4AA0-9C1E-2243920F9FAD}" src="https://github.com/user-attachments/assets/a1bdc9e5-314d-4e69-9a73-5010faf4b233" />

bedeutet das, dass Sie die Option zur automatischen Farbzuordnung und/oder das Scannen von Dateien deaktiviert haben. Sie können auf die Schaltfläche `AUTO_SELECT_COLORS` klicken oder sie in den globalen Parametern aktivieren:
```
SAVE_ZMOD_DATA SCAN_FILE_COLORS=1 AUTO_ASSIGN_COLORS=1
```

[Es wird dringend empfohlen, den Präprozessor zu aktivieren](/de/Global/#force_md5)

---

### Erstellung des Bettnetzes und AUTO PA

Im Druckmenü gibt es zwei wichtige Schaltflächen:

**Leveling (Bettnetz):**

- `Bettnetz messen` — vor dem Drucken wird automatisch ein Bettnetz erstellt.
- `Bettnetz nicht messen` — das zuvor gespeicherte Netz wird verwendet.

**Auto PA (automatische Ermittlung von Pressure Advance):**

- Wenn die Schaltfläche `Auto PA` aktiv (grün) ist, ermittelt der Drucker **vor Druckbeginn** automatisch den optimalen Pressure-Advance-Wert für jeden verwendeten Extruder.
- Der Prozess dauert einige Minuten, verbessert aber die Qualität von Ecken und dünnen Elementen deutlich.
- Wenn `Auto PA` ausgeschaltet ist, werden die PA-Werte aus dem Slicer verwendet.

!!! note
    Die automatische Kalibrierung reicht von 0.01 bis 0.04 und ist für zähflüssige Kunststoffe wie PETG nutzlos.


**Alle Extruder ohne Auto PA spülen.** Standardmäßig wird beim Druckstart nur der erste Extruder gespült. Damit alle verwendeten Extruder gespült werden, aktivieren Sie den globalen Parameter [PURGE_ALL_EXTRUDERS](/de/Global/#purge_all_extruders): `SAVE_ZMOD_DATA PURGE_ALL_EXTRUDERS=1`

---

## Feineinstellung

Funktioniert nicht mit dem Werksbildschirm, daher müssen Sie zuerst [den nativen Druckerbildschirm ausschalten](/de/System/#display_off) – mit dem Makro `DISPLAY_OFF`.

**Wie man diese Einstellungen findet:**

1. Klicken Sie auf die Registerkarte „Konfiguration“.
2. Suchen und öffnen Sie den Ordner `mod_data`.
3. Suchen und öffnen Sie in diesem Ordner die Datei `filament.json`.

<img width="480" height="826" alt="{F5EAE8D4-1A9F-4E6C-99A1-B609A331E82D}" src="https://github.com/user-attachments/assets/4b7b5f91-b3ff-4c75-824d-4ec06e2ac6de" />

In dieser Datei gibt es für jeden Kunststofftyp (PLA, ABS, PETG usw.) eine Liste von Zahlen. Hier ist, was sie bedeuten:

| Parameter | Standard | Beschreibung |
|---|---|---|
| `temp` | 220 | Temperatur, auf die die Düse zum Filamentwechsel erhitzt wird. Der Wert hängt vom Materialtyp ab. |
| `temp_manual` | 250 | Spültemperatur im manuellen Modus (beim Laden über das Menü). |
| `temp_wait` | 120 | Leerlauftemperatur — auf diese kühlt die Düse nach dem Spülen ab. |
| `filament_drop_length` | 50 | **Abfalllänge.** Wie viele Millimeter Kunststoff der Drucker vor Druckbeginn in den Abfallbehälter extrudiert; `0` deaktiviert die Fahrt zum Abfallbehälter. |
| `filament_full_length` | 600 | **Schlauchlänge.** Wie viele Millimeter Kunststoff der Drucker nach dem Auslösen des Filament-Endsensors extrudiert. |
| `filament_tube_length` | 295 | Ladelänge des Filaments beim Einsetzen einer neuen Spule. |

**Standardtemperaturen für verschiedene Materialien:**

| Material | `temp` | `temp_manual` | `temp_wait` |
|---|---|---|---|
| PLA | 220 | 250 | 120 |
| PETG | 240 | 270 | 140 |
| PLA-CF | 220 | 250 | 120 |
| PETG-CF | 240 | 270 | 140 |
| ABS | 250 | 280 | 150 |
| ASA | 250 | 280 | 150 |
| SILK | 220 | 250 | 120 |
| PET-CF | 270 | 300 | 170 |
| S-PAHT | 280 | 310 | 180 |
| S-MULTI | 270 | 300 | 170 |
| PA-CF | 270 | 300 | 170 |
| HIPS | 250 | 280 | 150 |
| PVA | 220 | 250 | 120 |
| TPU-90A | 220 | 250 | 120 |
| TPU-95A | 220 | 250 | 120 |
| TPU-64D | 220 | 250 | 120 |

### Erweiterte Parameter

| Parameter | Standard | Beschreibung |
|---|---|---|
| `trash_x` | 275.0 | X-Koordinate des Abfallbehälters. |
| `trash_y` | 254.0 | Y-Koordinate des Abfallbehälters. |
| `trash_z` | 10.0 | Z-Koordinate des Abfallbehälters. |
| `wiper_x` | 266.50 | X-Koordinate der Düsenreinigung (Gummiwischer). |
| `wiper_y` | 13.80 | Y-Koordinate der Düsenreinigung. |
| `wiper_z` | 1.0 | Z-Koordinate der Düsenreinigung. |
| `fan_speed` | 255.0 | Lüftergeschwindigkeit (von 0 bis 255) beim Abkühlen der Düse nach dem Spülen. |

> **Achtung!** Das Ändern von Parametern im erweiterten Bereich kann zu fehlerhaftem Druckerbetrieb, Filamentstaus oder Schäden führen. Ändern Sie sie nur, wenn Sie vollständig verstehen, wofür jeder Parameter verantwortlich ist und welche Folgen möglich sind.

---

## Globale Parameter

Ob das Fenster zur Farbauswahl beim Druckstart angezeigt wird, legt der globale Parameter fest:
**SILENT**:
- `0` — Fenster anzeigen (Standard)
- `1` — Fenster nicht anzeigen, zuvor festgelegte Farben verwenden
- `2` — Fenster nicht anzeigen, bei fehlgeschlagener automatischer Zuordnung das Auswahlmenü anzeigen
```
SAVE_ZMOD_DATA SILENT=1
```

---

Um das Scannen von G-Code-Dateien auf Informationen über Werkzeuge, Farben und Materialien zu aktivieren, verwenden Sie den Parameter
**SCAN_FILE_COLORS**.
```
SAVE_ZMOD_DATA SCAN_FILE_COLORS=1
```
Mögliche Werte:
- `0` — Parameter deaktivieren
- `1` — vollständiges Scannen der G-Code-Datei
- `2` — nur die vom Slicer-Skript vorbereiteten Daten prüfen, ohne die gesamte Datei zu scannen
**!Wenn das Scannen von Dateien deaktiviert ist**, weiß der Drucker nicht, wie viele Extruder verwendet werden, und deshalb wird **Auto PA für alle Spulen ausgeführt**

!!! note
    Für 3MF-Dateien werden die automatische Zuordnung und das Scannen automatisch aktiviert

---

Um die **automatische Farbzuordnung** aus der G-Code-Datei zu physischen Spulen zu aktivieren, verwenden Sie den Parameter
**AUTO_ASSIGN_COLORS**. Damit diese Funktion funktioniert, muss das Scannen von Dateien aktiviert sein.
```
SAVE_ZMOD_DATA AUTO_ASSIGN_COLORS=30
```
Sie können eigene Werte für den Druckabbruch im leisen Modus konfigurieren, indem Sie die folgenden Zahlen addieren:
- `1` — der Druck wird fortgesetzt, auch wenn die automatische Farbzuordnung fehlgeschlagen ist
- `2` — Mindestens ein Material stimmt nicht überein (zum Beispiel ist im G-Code ABS angegeben, aber Sie haben nur PLA geladen)
- `4` — Mindestens eine Farbe stimmt überhaupt nicht überein (normalerweise weil das Scannen von Dateien deaktiviert ist)
- `8` — Mindestens eine Farbe stimmt schlecht überein
- `16` — Dieselbe physische Spule wurde mehr als einem Werkzeugindex in der Datei zugewiesen
Zum Beispiel führt die Verwendung des Werts `30` zum Abbruch des Drucks im leisen Modus, wenn Probleme mit der automatischen Zuordnung auftreten, und `AUTO_ASSIGN_COLORS=6` (2+4) bricht den Druck ab, wenn mindestens ein Material nicht übereinstimmt + mindestens eine Farbe überhaupt nicht übereinstimmt.

!!! note
    Für 3MF-Dateien werden die automatische Zuordnung und das Scannen automatisch aktiviert

---

Um die Heizung ungenutzter Extruder beim Mehrfarbdruck automatisch auszuschalten, verwenden Sie den Parameter **unused_extruders_off_time**. Er legt die Wartezeit (in Minuten) fest, nach der ein ungenutztes Werkzeug ausgeschaltet wird, um eine Zersetzung des Filaments und unnötiges Heizen zu vermeiden.

```
SAVE_ZMOD_DATA unused_extruders_off_time=5
```

Sie können die folgenden Werte festlegen (in Minuten):
* `0` — Funktion deaktiviert (Extruder werden während des Leerlaufs nicht ausgeschaltet)
* `5`, `10`, `20`, `40`, `60` — Zeit, nach der der ungenutzte Extruder ausgeschaltet wird

**Wichtig:** Damit diese Option korrekt funktioniert, muss im Slicer die Funktion **Ooze prevention** (Verhinderung des Auslaufens von Kunststoff) aktiviert sein (`Druckeinstellungen` > `Multimaterial` > `Ooze prevention`). Ohne sie kann der Drucker die Temperaturen der ungenutzten Hotends während des Filamentwechsels nicht korrekt verarbeiten.

<img width="375" height="143" alt="{2CA02C09-7658-478E-A2A3-F7A9E9A077F2}" src="https://github.com/user-attachments/assets/6340a479-62a8-4476-93f1-c4054a279618" />

---

## Anzahl der Versuche ändern, das Werkzeug aufzunehmen oder abzulegen

Öffnen Sie in der Fluidd-Weboberfläche über „Konfiguration“ in der linken Spalte die Datei `mod_data/user.cfg` und fügen Sie hinzu:

```
[zmod_color]
retry: 3
```

Standard ist 5. `[Abschnitte]` und Makros in dieser Datei werden bei Firmware-Updates nicht verändert.

---

## Eigene Filamenttypen hinzufügen

Damit diese Einstellungen funktionieren, müssen Sie den nativen Druckerbildschirm mit dem Makro `DISPLAY_OFF` ausschalten.

Um einen neuen Filamenttyp hinzuzufügen, fügen Sie in `mod_data/user.cfg` hinzu:

```
[zmod_color]
filament_NEWTYPE: 300
```

Wobei `NEWTYPE` durch den gewünschten Filamenttyp ersetzt wird (zum Beispiel `HIPS`), und die Zahl ist die Extrudertemperatur zum Laden, Entladen und Spülen dieses Filaments. Auf Basis dieses Werts werden `temp_manual` (+30) und `temp_wait` (−100) automatisch berechnet.

Um einen Filamenttyp auszublenden, fügen Sie in `mod_data/user.cfg` hinzu:

```
[zmod_color]
hide_filament_types: XXX,YYY,ZZZ
```

Wobei `XXX`, `YYY`, `ZZZ` durch die gewünschten Filamenttypen ersetzt werden (zum Beispiel `PLA-CF,PETG-CF,SILK`). Dies kann verwendet werden, um Standardtypen oder manuell hinzugefügte Typen auszublenden. Der Filamenttyp wird dabei nicht deaktiviert, sondern nur im Menü zur Typauswahl ausgeblendet.

---

## Eigene Farben hinzufügen

Damit diese Einstellungen funktionieren, müssen Sie den nativen Druckerbildschirm mit dem Makro `DISPLAY_OFF` ausschalten.

Um eine Farbe hinzuzufügen oder umzubenennen, öffnen Sie `mod_data/color/de.json` (verwenden Sie Ihre Sprache anstelle von `de`) und fügen Sie eine neue Farbe hinzu oder benennen Sie eine vorhandene um.

Damit der Farbname auf den Schaltflächen angezeigt wird, muss er mit einem Unterstrich `_` beginnen.

**Beispiel:**
```json
{
   "ffffff": "weiß",
   "fffff1": "_transparent",
   "fef043": "hellgelb",
   "dcf478": "hellgrün",
   "0acc38": "grün",
   "067749": "dunkelgrün",
   "0c6283": "blaugrün",
   "0de2a0": "türkis",
   "75d9f3": "hellblau",
   "45a8f9": "blau",
   "2750e0": "dunkelblau",
   "46328e": "violett",
   "a03cf7": "hellviolett",
   "f330f9": "magenta",
   "d4b0dc": "flieder",
   "f95d73": "rosa",
   "f72224": "rot",
   "7c4b00": "braun",
   "f98d33": "orange",
   "fdebd5": "beige",
   "d3c4a3": "hellbraun",
   "af7836": "terrakotta",
   "898989": "grau",
   "bcbcbc": "hellgrau",
   "161616": "schwarz"
}
```

Die Beschriftung `_transparent` wird auf den Schaltflächen angezeigt.

---

## Extruderkalibrierung

Durch die Extruderkalibrierung kennt der Drucker die genaue Position der vier Düsen zueinander. Dies ist für hochwertigen Mehrfarbdruck erforderlich.

**Wann kalibrieren:**
- Nach dem Austausch oder der Reparatur eines Extruders.
- Wenn Sie bemerken, dass die Farben am Modell nicht übereinstimmen (Versatz in X, Y oder Z).

**So starten Sie:**

1. **Nehmen Sie die Druckplatte** vom Bett!
2. Starten Sie das Makro `CALIBRATE_EXTRUDERS` aus dem Menü oder geben Sie in der Konsole ein:
   ```
   CALIBRATE_EXTRUDERS
   ```
3. Ein Bestätigungsfenster erscheint. Klicken Sie auf `OK`.

**Was passiert:**

- Der Drucker führt eine Referenzfahrt (G28) aus.
- Heizt das Bett auf 65 °C.
- Nimmt nacheinander jeden der 4 Extruder auf (T0–T3).
- Für jeden Extruder: heizt die Düse, spült, reinigt sie am Gummiwischer und bestimmt dann mit Sensoren die genauen X-, Y- und Z-Koordinaten.
- Die Ergebnisse werden automatisch in die Datei `rw/extruder.json` geschrieben.
- Am Ende gibt der Drucker die gefundenen Offsets für jeden Extruder in der Konsole aus.

**Zusätzliche Parameter** (für Fortgeschrittene):

| Parameter | Standard | Beschreibung |
|---|---|---|
| `BED_TEMP` | 65.0 | Betttemperatur während der Kalibrierung |
| `SEARCH` | 14.0 | Suchradius des Sensors (mm) |
| `HOVER` | 0.6 | Höhe über dem Messpunkt |
| `SAFE_Z` | 10.0 | Sichere Z-Höhe |

**Beispiel mit Parametern:**

```
CALIBRATE_EXTRUDERS BED_TEMP=70 SEARCH=12
```

> **Achtung!** Unterbrechen Sie die Kalibrierung nicht. Der Prozess dauert einige Minuten.

---

## VFA-Kalibrierung

Die VFA-Kalibrierung (Vertical Fine Artifacts) ermöglicht es, vertikale Artefakte auf der Druckoberfläche zu reduzieren, die durch Resonanzen der Schrittmotoren verursacht werden.

**So starten Sie:**

Geben Sie in der Konsole ein:
```
CALIBRATE_VFA T=0
```

Wobei `T=0` die Extrudernummer (0–3) ist, die während der Kalibrierung verwendet wird.

**Was passiert:**

- Der Drucker nimmt den angegebenen Extruder auf.
- Setzt alle G-Code-Offsets zurück.
- Bewegt den Kopf in die Bettmitte (X130 Y130).
- Startet die automatische Resonanzkalibrierung (`STEPPER_RESONANCE_FACTORY_CALIBRATE`).
- Legt den Extruder wieder ab.
- Speichert die Konfiguration (`SAVE_CONFIG`).

> **Tipp:** Es wird empfohlen, die VFA-Kalibrierung durchzuführen, wenn sichtbare vertikale Streifen auf der Druckoberfläche auftreten.

---

## Makro `T_INFO`

Das Makro `T_INFO` zeigt den aktuellen Zustand aller Extruder und Druckersensoren an.

**So starten Sie:**
```
T_INFO
```

**Was in der Konsole ausgegeben wird:**

```
// T0: home
// T1: HEAD
// T2: home
// T3: home
// Door: Close
// Top: Close
// Offset: X=0.000 Y=0.000 Z=0.061 (0.000)
```

**Wie man es liest:**

- `home` — der Extruder ist an seinem Platz (in der Parktasche).
- `HEAD` — der Extruder ist am Druckkopf installiert.
- `?` — unbestimmter Zustand (Sensoren haben nicht ausgelöst).
- `ERROR (both)` — Fehler: Der Extruder wird gleichzeitig als geparkt und am Kopf erkannt (Sensoren nicht synchron).
- `Door` — Zustand der vorderen Tür (`Close` / `Open`).
- `Top` — Zustand der oberen Abdeckung (`Close` / `Open`).
- `Offset` — aktuelle G-Code-Offsets entlang der X-, Y-, Z-Achsen.

---

## Ventilationsmodi

Der Creator 5 Pro ist mit einem Kammer-Ventilationssystem mit mehreren Lüftern ausgestattet. Die richtige Steuerung der Ventilation ist entscheidend für die Druckqualität verschiedener Materialien.

**Externe Belüftung (PLA, TPU):**

Das Makro `AIR_CIRCULATION_EXTERNAL` schaltet die Kammerabsaugung und die Frischluftzufuhr ein. Es wird für PLA und TPU benötigt, damit der Kunststoff schnell abkühlt und durch die Kammerwärme nicht weich wird.
```
AIR_CIRCULATION_EXTERNAL
```
| Lüfter | Geschwindigkeit |
|---|---|
| `chamber_fan` (Absaugung) | 0.5 |
| `chamber_cool_fan` (Kühlung) | 0.7 |
| `chamber_heat_fan` (Heizung) | 0.0 |
| `chamber_loop_fan` (Zirkulation) | 0.0 |

**Interne Umwälzung (ABS, ASA):**

Das Makro `AIR_CIRCULATION_INTERNAL` schaltet die interne Umwälzung und die Kammerheizung ein. Es wird für ABS und ASA benötigt, um Schichtablösung und Verzug durch Temperaturschwankungen zu vermeiden.
```
AIR_CIRCULATION_INTERNAL
```
| Lüfter | Geschwindigkeit |
|---|---|
| `chamber_fan` (Absaugung) | 0.0 |
| `chamber_cool_fan` (Kühlung) | 0.0 |
| `chamber_heat_fan` (Heizung) | 0.9 |
| `chamber_loop_fan` (Zirkulation) | 0.3 |

**Ventilation stoppen:**
Das Makro `AIR_CIRCULATION_STOP` schaltet alle Kammerlüfter vollständig aus.
```
AIR_CIRCULATION_STOP
```

### Wo Ventilationsmakros hinzugefügt werden

> **Empfehlung:** Am besten fügen Sie die Aufrufe der Ventilationsmakros in den **Filamentcode** im Slicer ein. So wird der Modus beim Materialwechsel automatisch umgeschaltet.

**In OrcaSlicer:**

1. Öffnen Sie die Filament-Einstellungen.
2. Gehen Sie zur Registerkarte „Filament-Einstellungen“.
3. Fügen Sie im Feld **Start-G-Code des Filaments** das benötigte Makro hinzu:
   - Für PLA: `AIR_CIRCULATION_EXTERNAL`
   - Für ABS: `AIR_CIRCULATION_INTERNAL`
   - Für TPU: `AIR_CIRCULATION_EXTERNAL`

**Beispiel für PLA:**
```
; Filament start gcode
AIR_CIRCULATION_EXTERNAL
```

**Beispiel für ABS:**
```
; Filament start gcode
AIR_CIRCULATION_INTERNAL
```

So wird beim Mehrfarbdruck mit unterschiedlichen Materialien die Ventilation für jeden Extruder automatisch in den passenden Modus geschaltet.

---

## Druckbeschleunigung

Um die Verlangsamung der Firmware bei kurzen Perimetern zu deaktivieren, öffnen Sie die Fluidd-Weboberfläche -> linke Spalte -> Registerkarte `Konfiguration` -> `mod_data`/`user.cfg` und fügen Sie drei Zeilen hinzu:

```
[printer]
short_move_limit: False
short_extrude_move_limit: False
```

Ab der Werksfirmware 1.9.9 beschleunigt diese Einstellung den Druck erheblich, kann aber beim Drucken mit Fuzzy Skin zu Abstürzen des Druckers führen.

---

## Schnelle Rückkehr des Kopfes und Vorheizen deaktivieren

Fügen Sie in `mod_data/user.cfg` hinzu:

```
[virtual_sdcard]
enable_speed_return: False
enable_preheat: False
```

- **enable_speed_return**:
    - `enable_speed_return: False` — der Kopf kehrt aus dem Bereich der Hotend-Aufnahme mit der im Slicer festgelegten Geschwindigkeit und Bahn zum Modell zurück.
    - `enable_speed_return: True` — der Kopf kehrt aus dem Bereich der Hotend-Aufnahme mit 600 mm/s auf einer von der Druckerfirmware gewählten Bahn zum Modell zurück (Kollisionen mit den Kanten des Prime Towers sind möglich).
- **enable_preheat**:
    - `enable_preheat: False` — deaktiviert das vorausschauende Hintergrund-Scannen der G-Code-Datei während des Drucks und entlastet CPU und Speicher. Das vorausschauende Heizen wird von OrcaSlicer genauer berechnet.
    - `enable_preheat: True` — nutzt das vorausschauende Hintergrund-Scannen der G-Code-Datei zum Vorheizen der nächsten Düse. Beschleunigt das Heizen, wenn mehr als zwei Düsen in kurzer Zeit verwendet werden, da der Drucker nicht mehr als zwei Düsen gleichzeitig heizen kann.

---

## Benachrichtigung über eine geöffnete Tür deaktivieren

Um Benachrichtigungen über eine geöffnete Abdeckung oder Tür im Modus ohne nativen Bildschirm zu entfernen:

Fügen Sie in `mod_data/user.cfg` hinzu:

```
[gcode_button topDoor]
press_gcode:
release_gcode:

[gcode_button frontDoor]
press_gcode:
release_gcode:
```
