# Creator5 Pro

1. [Wichtige Hinweise](#wichtige-hinweise)
2. [Wie man eine Datei in Orca vorbereitet](#wie-man-eine-datei-in-orca-vorbereitet)
3. [Wie man das Farbauswahlmenü verwendet](#wie-man-das-farbauswahlmenü-verwendet)
4. [Druckmenü](#druckmenü)
5. [Feineinstellung](#feineinstellung)
6. [Globale Parameter](#globale-parameter)
7. [Eigene Filamenttypen hinzufügen](#eigene-filamenttypen-hinzufügen)
8. [Eigene Farben hinzufügen](#eigene-farben-hinzufügen)
9. [Extruderkalibrierung](#extruderkalibrierung)
10. [VFA-Kalibrierung](#vfa-kalibrierung)
11. [`T_INFO`-Makro](#t_info-makro)
12. [Lüftungsmodi](#lüftungsmodi)

---

## Wichtige Hinweise

- Der Drucker arbeitet immer mit **4 Farben** (T0, T1, T2, T3). Alle vier Slots sind im Auswahlmenü verfügbar.
- Um die Kamera zu aktivieren, muss `CAMERA_ON VIDEO=video67` verwendet werden.
- Klipper kann abstürzen. Lösung: `Prozessprofil` -> `Sonstiges` -> `G-Code ausgeben` -> Haken bei `Objekte ausschließen` entfernen.
- Wenn Sie eine `3mf`-Datei senden, verwenden Sie nur den Modus mit dem Originalbildschirm.
- Wenn Sie eine `gcode`-Datei senden, ist es problematisch, die Farbreihenfolge beim Drucken mit dem Originalbildschirm zu ändern.
- Verwenden Sie anstelle des Makros `CLOSE_DILALOGS` (langes Schließen) immer `FAST_CLOSE_DILAOGS` (schnelles Schließen).
- Das Makro `NEW_SAVE_CONFIG` funktioniert nicht.
- Keine Unterstützung für Klipper 13.

---

## Wie man eine Datei in Orca vorbereitet

[Senden Sie Dateien zum Drucken über Octo/Klipper.](/ru/Recommendations/#отправляйте-файлы-на-печать-через-octoklipper)

---
## COLOR
## Wie man das Farbauswahlmenü verwendet

<img width="881" height="856" alt="image" src="https://github.com/user-attachments/assets/7acd4ccf-3623-4afe-83bf-fcb96f5a416b" />

<img width="554" height="502" alt="{7A4A77A2-1F88-4110-9502-24FA941B9A67}" src="https://github.com/user-attachments/assets/fd77a89c-08d6-4da5-8eac-3017ca563657" />

Wählen Sie nun die Spule aus, mit der Sie arbeiten möchten (z. B. Spule 2):

<img width="559" height="466" alt="{355F6AEF-00B2-4EFE-841E-23516CAC64FA}" src="https://github.com/user-attachments/assets/81084141-88b8-4d65-b583-495796f0d4fa" />

Sie können vier Aktionen ausführen:
- Die Farbe der Spule ändern.
- Den Kunststofftyp ändern (z. B. von PLA auf PETG).
- Diesen Extruder auf den Schlitten setzen.
- Eine neue Spule in den Extruder laden.

**Wie man die Farbe ändert:**
Klicken Sie auf „Farbe ändern“. Wählen Sie eine Farbe aus der Liste. So verstehen der Drucker und der Originalbildschirm Sie am besten.

<img width="560" height="834" alt="{55C179BC-DB74-480D-BA6A-DBDF193794B5}" src="https://github.com/user-attachments/assets/32dfabcf-23c6-4ed8-b606-fa1e0fb01e67" />

Nach der Auswahl kehren Sie zurück, und die Farbe der Spule in der Liste sollte sich geändert haben.

Wenn sich die Farbe nicht geändert hat: Schließen Sie das Fenster mit dem Kreuz und starten Sie das Makro `COLOR` erneut. Manchmal hat der Bildschirm keine Zeit, sich zu aktualisieren.

**Wie man den Typ ändert:**
Klicken Sie auf „Typ ändern“. Wählen Sie einen Typ aus der Liste.

<img width="554" height="830" alt="{07CF6B87-8483-4300-B354-554431CCBE54}" src="https://github.com/user-attachments/assets/31445f6c-18b7-4e26-80fb-4f8306b11d57" />

Wenn sich der Typ nicht geändert hat: Schließen Sie das Fenster mit dem Kreuz und starten Sie das Makro `COLOR` erneut. Manchmal hat der Bildschirm keine Zeit, sich zu aktualisieren.

**Tipp:** Wenn Sie für mehrere Spulen die gleiche Farbe und den gleichen Typ angeben, wechselt der Drucker automatisch zur nächsten Spule, wenn die erste leer ist. Dies wird als „Endlos-Spulen-Modus“ (Infinite Spool) bezeichnet.

---

## PRINT
## Druckmenü

Dieses Fenster öffnet sich automatisch, wenn Sie mit dem Drucken beginnen.

<img width="562" height="593" alt="{A688018F-CB9C-4EFA-9431-AAE9E2DE842E}" src="https://github.com/user-attachments/assets/92cababe-52b1-49aa-aea3-1ad6ddf03cfe" />

**Wie man versteht, was hier steht:**

`Cube.gcode` ist der Name der gedruckten Datei.
`1` ist die erste Farbe aus der Datei. Sie wird mit Filament von Spule 2 (orangefarbenes PETG) gedruckt.
`2` ist die zweite Farbe. Sie wird mit Filament von Spule 4 (graues PLA) gedruckt.
`3` ist die dritte Farbe, gedruckt von Spule 1 (schwarzes PETG).

### Bettnivellierung und AUTO PA

Es gibt zwei wichtige Schaltflächen im Druckmenü:

**Leveling (Bettnivellierung):**
- `Bett nivellieren` – Vor dem Drucken wird automatisch eine Bettnivellierungskarte erstellt.
- `Bett nicht nivellieren` – Es wird eine zuvor gespeicherte Karte verwendet.

**Auto PA (Automatische Pressure-Advance-Einstellung):**
- Wenn die Schaltfläche `Auto PA` aktiv ist (grün), wählt der Drucker **vor Beginn des Drucks** automatisch den optimalen Pressure-Advance-Wert für jeden verwendeten Extruder.
- Der Vorgang dauert einige Minuten, verbessert aber die Qualität von Ecken und feinen Details erheblich.
- Wenn `Auto PA` deaktiviert ist, werden die PA-Werte aus dem Slicer verwendet.

Die automatische Kalibrierung reicht von 0,01 bis 0,04 und ist für viskose Kunststoffe wie PETG nutzlos.

---

## Feineinstellung

Zuerst müssen Sie den Originalbildschirm des Druckers mit dem Makro `DISPLAY_OFF` deaktivieren.

**So finden Sie diese Einstellungen:**
1. Klicken Sie auf den Reiter „Konfiguration“.
2. Suchen und öffnen Sie den Ordner `mod_data`.
3. Suchen und öffnen Sie in diesem Ordner die Datei `filament.json`.

<img width="480" height="826" alt="{F5EAE8D4-1A9F-4E6C-99A1-B609A331E82D}" src="https://github.com/user-attachments/assets/4b7b5f91-b3ff-4c75-824d-4ec06e2ac6de" />

In dieser Datei gibt es für jeden Kunststofftyp (PLA, ABS, PETG usw.) eine Liste von Zahlen. Hier ist, was sie bedeuten:

| Parameter | Standard | Beschreibung |
|---|---|---|
| `temp` | 220 | Temperatur, auf die die Düse zum Filamentwechsel erhitzt wird. Der Wert hängt vom Materialtyp ab. |
| `temp_manual` | 250 | Spültemperatur im manuellen Modus (beim Laden über das Menü). |
| `temp_wait` | 120 | Leerlauftemperatur – die Temperatur, auf die die Düse nach dem Spülen abkühlt. |
| `filament_drop_length` | 50 | **Spüllänge.** Wie viele Millimeter Kunststoff der Drucker in den Mülleimer extrudiert, um die Düse von der alten Farbe zu reinigen. |
| `filament_tube_length` | 295 | Filament-Ladelänge beim Einlegen einer neuen Spule. |

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
| `trash_x` | 275.0 | X-Koordinate des Mülleimers. |
| `trash_y` | 254.0 | Y-Koordinate des Mülleimers. |
| `trash_z` | 10.0 | Z-Koordinate des Mülleimers. |
| `wiper_x` | 266.50 | X-Koordinate der Düsenreinigungsstelle (Wischer). |
| `wiper_y` | 13.80 | Y-Koordinate der Düsenreinigungsstelle. |
| `wiper_z` | 1.0 | Z-Koordinate der Düsenreinigungsstelle. |
| `fan_speed` | 255.0 | Lüftergeschwindigkeit (von 0 bis 255) beim Abkühlen der Düse nach dem Spülen. |

> **Achtung!** Das Ändern von Parametern im erweiterten Bereich kann zu Fehlfunktionen des Druckers, Filamentstaus oder Beschädigungen führen. Ändern Sie diese nur, wenn Sie genau verstehen, wofür jeder Parameter verantwortlich ist und welche Folgen dies haben kann.

---

## Globale Parameter

Damit das Farbauswahlfenster zu Beginn des Drucks nicht angezeigt wird, verwenden Sie den globalen Parameter **SILENT**:
- `0` – Fenster anzeigen (Standard)
- `1` – Fenster nicht anzeigen, zuvor festgelegte Farben verwenden
- `2` – Fenster nicht anzeigen, Zufuhrsystem nicht verwenden

```
SAVE_ZMOD_DATA SILENT=1
```

Um das Scannen von Gcode-Dateien nach Informationen zu Werkzeugen, Farben und Materialien zu aktivieren, verwenden Sie den Parameter **SCAN_FILE_COLORS**. Sie können auch den Wert `2` festlegen, um nur die vom Slicer-Skript vorbereiteten Daten zu überprüfen, ohne die gesamten Dateien zu scannen:
```
SAVE_ZMOD_DATA SCAN_FILE_COLORS=1
```

Um die **automatische Farbzusordnung** aus der Gcode-Datei zu physischen Spulen zu aktivieren, verwenden Sie den Parameter **AUTO_ASSIGN_COLORS**. Damit diese Funktion funktioniert, muss das Dateiscanning aktiviert sein. Die Verwendung des Wertes `30` führt im Silent-Modus zum Abbruch des Drucks, wenn Probleme bei der automatischen Zuweisung auftreten:
```
SAVE_ZMOD_DATA AUTO_ASSIGN_COLORS=30
```

Sie können Ihre eigenen Werte für den Abbruch des Drucks im Silent-Modus konfigurieren, indem Sie die folgenden Zahlen addieren:
- `2` – Mindestens ein Material stimmt nicht überein (z. B. ist in der Gcode-Datei ABS angegeben, aber Sie haben nur PLA geladen)
- `4` – Mindestens eine Farbe stimmt überhaupt nicht überein (normalerweise, weil das Dateiscanning deaktiviert ist)
- `8` – Mindestens eine Farbe stimmt nur schlecht überein
- `16` – Dieselbe physische Spule wurde in der Datei mehr als einem Werkzeugindex zugewiesen

**Wenn das Dateiscanning deaktiviert ist**, weiß der Drucker nicht, wie viele Extruder verwendet werden, und daher wird **Auto PA für alle Spulen ausgeführt**.

---

## Eigene Filamenttypen hinzufügen

Damit diese Einstellungen funktionieren, müssen Sie den Originalbildschirm des Druckers mit dem Makro `DISPLAY_OFF` deaktivieren.

Um einen neuen Filamenttyp hinzuzufügen, fügen Sie in `mod_data/user.cfg` Folgendes hinzu:

```
[zmod_color]
filament_NEWTYPE: 300
```

Wobei `NEWTYPE` durch den gewünschten Filamenttyp (z. B. `HIPS`) ersetzt wird und die Zahl die Extrudertemperatur zum Laden, Entladen und Spülen dieses Filaments ist. Basierend auf diesem Wert werden `temp_manual` (+30) und `temp_wait` (−100) automatisch berechnet.

Um einen Filamenttyp auszublenden, fügen Sie in `mod_data/user.cfg` Folgendes hinzu:

```
[zmod_color]
hide_filament_types: XXX,YYY,ZZZ
```

Wobei `XXX`, `YYY`, `ZZZ` durch die Filamenttypen ersetzt werden, die Sie ausblenden möchten (z. B. `PLA-CF,PETG-CF,SILK`). Dies kann verwendet werden, um Standardtypen oder manuell hinzugefügte Typen auszublenden. Der Filamenttyp wird dabei nicht deaktiviert, sondern nur im Typauswahlmenü ausgeblendet.

---

## Eigene Farben hinzufügen

Damit diese Einstellungen funktionieren, müssen Sie den Originalbildschirm des Druckers mit dem Makro `DISPLAY_OFF` deaktivieren.

Um eine Farbe hinzuzufügen oder umzubenennen, öffnen Sie `mod_data/color/de.json` (ersetzen Sie `de` durch Ihre Sprache) und fügen Sie eine neue Farbe hinzu oder benennen Sie eine vorhandene um.

Damit der Farbname angezeigt wird, muss der Farbname mit einem Unterstrich `_` beginnen.

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
   "46328e": "lila",
   "a03cf7": "helllila",
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

Der Text `_transparent` wird auf den Schaltflächen angezeigt.

---

## Extruderkalibrierung

Die Extruderkalibrierung ermöglicht es dem Drucker, die genaue Position jeder der vier Düsen relativ zueinander zu kennen. Dies ist für einen hochwertigen Mehrfarbendruck erforderlich.

**Wann kalibrieren:**
- Nach dem Austausch oder der Reparatur eines Extruders.
- Wenn Sie feststellen, dass die Farben auf dem Modell nicht übereinstimmen (Verschiebung in X, Y oder Z).

**So starten Sie:**

1. **Entfernen Sie die Druckplatte** vom Bett!
2. Starten Sie das Makro `CALIBRATE_EXTRUDERS` aus dem Menü oder geben Sie es in der Konsole ein:
   ```
   CALIBRATE_EXTRUDERS
   ```
3. Es erscheint ein Bestätigungsfenster. Klicken Sie auf `OK`.

**Was passiert:**
- Der Drucker führt ein Homing (G28) durch.
- Er heizt das Bett auf 65°C.
- Er nimmt nacheinander jeden der 4 Extruder (T0–T3).
- Für jeden Extruder: Er heizt die Düse, führt eine Spülung durch, reinigt sie am Wischer und bestimmt dann mithilfe von Sensoren die genauen X-, Y- und Z-Koordinaten.
- Die Ergebnisse werden automatisch in der Datei `rw/extruder.json` gespeichert.
- Nach Abschluss gibt der Drucker die gefundenen Versätze für jeden Extruder in der Konsole aus.

**Zusätzliche Parameter** (für Fortgeschrittene):

| Parameter | Standard | Beschreibung |
|---|---|---|
| `BED_TEMP` | 65.0 | Betttemperatur während der Kalibrierung |
| `SEARCH` | 14.0 | Suchradius des Sensors (mm) |
| `HOVER` | 0.6 | Schwebenhöhe über dem Punkt |
| `SAFE_Z` | 10.0 | Sichere Z-Höhe |

**Beispiel mit Parametern:**
```
CALIBRATE_EXTRUDERS BED_TEMP=70 SEARCH=12
```

> **Achtung!** Unterbrechen Sie die Kalibrierung nicht. Der Vorgang dauert einige Minuten.

---

## VFA-Kalibrierung

Die VFA-Kalibrierung (Vertical Fine Artifacts) hilft, vertikale Artefakte auf der Druckoberfläche zu reduzieren, die durch Resonanzen der Schrittmotoren verursacht werden.

**So starten Sie:**

Geben Sie in der Konsole ein:
```
CALIBRATE_VFA T=0
```

Wobei `T=0` die Extrudernummer (0–3) ist, die während der Kalibrierung verwendet wird.

**Was passiert:**
- Der Drucker nimmt den angegebenen Extruder.
- Er setzt alle G-Code-Versätze zurück.
- Er bewegt den Kopf in die Mitte des Bettes (X130 Y130).
- Er startet die automatische Resonanzkalibrierung (`STEPPER_RESONANCE_FACTORY_CALIBRATE`).
- Er bringt den Extruder an seinen Platz zurück.
- Er speichert die Konfiguration (`SAVE_CONFIG`).

> **Tipp:** Es wird empfohlen, die VFA-Kalibrierung durchzuführen, wenn sichtbare vertikale Streifen auf der Druckoberfläche auftreten.

---

## `T_INFO`-Makro

Das `T_INFO`-Makro zeigt den aktuellen Zustand aller Extruder und Drucksensoren an.

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
- `home` – der Extruder befindet sich an seinem Platz (in der Parktasche).
- `HEAD` – der Extruder ist am Druckkopf montiert.
- `?` – undefinierter Zustand (Sensoren haben nicht ausgelöst).
- `ERROR (both)` – Fehler: Der Extruder ist gleichzeitig zu Hause und am Kopf (Sensor-Desynchronisation).
- `Door` – Zustand der vorderen Tür (`Close` / `Open`).
- `Top` – Zustand der oberen Abdeckung (`Close` / `Open`).
- `Offset` – aktuelle G-Code-Versätze entlang der X-, Y-, Z-Achsen.

---

## Lüftungsmodi

Der Creator5 Pro ist mit einem Kammerlüftungssystem mit mehreren Lüftern ausgestattet. Die richtige Verwaltung der Lüftung ist entscheidend für die Druckqualität verschiedener Materialien.

**Externe Ansaugung (PLA, TPU):**
Das Makro `AIR_CIRCULATION_EXTERNAL` aktiviert die Kammerabsaugung und die Zufuhr frischer Luft. Dies wird für PLA und TPU benötigt, damit der Kunststoff schnell abkühlt und nicht durch die Kammerwärme erweicht.
```
AIR_CIRCULATION_EXTERNAL
```
| Lüfter | Geschwindigkeit |
|---|---|
| `chamber_fan` (Absaugung) | 0.5 |
| `chamber_cool_fan` (Kühlung) | 0.7 |
| `chamber_heat_fan` (Heizung) | 0.0 |
| `chamber_loop_fan` (Zirkulation) | 0.0 |

**Interne Zirkulation (ABS, ASA):**
Das Makro `AIR_CIRCULATION_INTERNAL` aktiviert die interne Zirkulation und die Kammerheizung. Dies wird für ABS und ASA benötigt, um Delamination und Verzug durch Temperaturschwankungen zu vermeiden.
```
AIR_CIRCULATION_INTERNAL
```
| Lüfter | Geschwindigkeit |
|---|---|
| `chamber_fan` (Absaugung) | 0.0 |
| `chamber_cool_fan` (Kühlung) | 0.0 |
| `chamber_heat_fan` (Heizung) | 0.9 |
| `chamber_loop_fan` (Zirkulation) | 0.3 |

**Lüftung stoppen:**
Das Makro `AIR_CIRCULATION_STOP` schaltet alle Kammerlüfter vollständig aus.
```
AIR_CIRCULATION_STOP
```

### Wo man Lüftungsmakros hinzufügt

> **Empfehlung:** Es ist am besten, Aufrufe von Lüftungsmakros in den **Filament-Code** im Slicer einzufügen. Dies gewährleistet einen automatischen Moduswechsel beim Materialwechsel.

**In OrcaSlicer:**
1. Öffnen Sie die Filamenteinstellungen.
2. Gehen Sie zum Reiter „Filamenteinstellungen“.
3. Fügen Sie im Feld **Filament-Start-G-Code** das erforderliche Makro hinzu:
   - Für PLA: `AIR_CIRCULATION_EXTERNAL`
   - Für ABS: `AIR_CIRCULATION_INTERNAL`
   - Für TPU: `AIR_CIRCULATION_EXTERNAL`

**Beispiel für PLA:**
```gcode
; Filament start gcode
AIR_CIRCULATION_EXTERNAL
```

**Beispiel für ABS:**
```gcode
; Filament start gcode
AIR_CIRCULATION_INTERNAL
```

Auf diese Weise schaltet die Lüftung beim Mehrfarbendruck mit verschiedenen Materialien automatisch in den für jeden Extruder erforderlichen Modus.

## Druckbeschleunigung

In 'mod_data/user.cfg' eintragen

```
[printer]
short_move_limit: False
short_extrude_move_limit: False
```

Diese Einstellung beschleunigt den Druckvorgang erheblich, kann jedoch bei der Option „Fuzzy Skin“ (Rauhe Oberfläche) zu Druckerabstürzen führen.
