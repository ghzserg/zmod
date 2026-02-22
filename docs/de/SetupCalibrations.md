# [Kalibrierung](#drucker-kalibrierung-für-einsteiger)

### Drucker-Kalibrierung für Einsteiger

Im Allgemeinen brauchen Sie nichts zu kalibrieren, aber wenn Sie Ihren Drucker besser einrichten wollen, lesen Sie weiter:

Wenn Sie die Einsteigerkalibrierungen durchlaufen haben:
<img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/c0c63cc4-c4b3-46d4-a3e7-6485d8bf26bb" />

Dann haben Sie das bereits:

- Ein z-Offset ist eingerichtet
- Es gibt eine ```MESH_DATA```-Tabelle (aufgenommen bei 60 Grad) - Sie können sie nicht löschen, wenn Sie den nativen Bildschirm verwenden, da sie bei jedem Druckvorgang geladen wird
- Es gibt eine Extruder-PID-Kalibrierung bei 240 Grad

Aber diese Einstellungen sind ziemlich allgemein, nicht viele Leute drucken bei 240 Grad Düsentemperatur und 60 Grad Tischtemperatur.

---

### Extruder PID-Einstellung

**Warum ist dies notwendig?**
Stellen Sie sich einen Extruder wie einen Backofen vor. Wenn die Temperatur darin ständig "springt", wird das Gericht (Ihr Teil) möglicherweise nicht gleichmäßig gebacken. Durch die PID-Kalibrierung "lernt" Ihr Drucker, die richtige Temperatur ohne Sprünge zu halten. Dies ist entscheidend für die Qualität des Drucks.

**Ein wichtiger Punkt, bevor Sie beginnen!**
Kalibrieren Sie für die genauen Bedingungen, unter denen Sie drucken:

* **Temperatur:** Die Temperatur, die Sie am häufigsten für Ihren Kunststoff verwenden (z.B. 210°C für PLA oder 255°C für PETG).
* **Kühlung:** Die Kühlung sollte mit der gleichen Leistung wie beim normalen Druck arbeiten.

**Wie wird die Kalibrierung durchgeführt?**

- Verwenden Sie den speziellen Befehl (Makro) [PID_TUNE_EXTRUDER](/de/Calibrations/#pid_tune_extruder)

- Sie können es manuell in der Konsole eingeben oder auf die Schaltfläche in der Schnittstelle klicken, wenn Sie sie haben:

  <img width="283" height="265" alt="image" src="https://github.com/user-attachments/assets/20b8a3c8-4726-44b0-b986-34881d95cb18" />

- Der Befehl selbst sieht wie folgt aus (dies ist ein Beispiel!):

```gcode
PID_TUNE_EXTRUDER TEMPERATURE=255 COOLER=80
```
    **Was das bedeutet:**

    * * ```TEMPERATURE=255``` - die Kalibrierung wird für eine Temperatur von 255°C durchgeführt. Stellen Sie die von Ihnen gewünschte Temperatur ein.
        * ```COOLER=80``` - die Kühlung erfolgt mit 80% Leistung.

- **Wenn Sie fertig sind:**
  *  **Der Drucker speichert die neuen Einstellungen selbständig.**
        * **Starten Sie den Drucker unbedingt neu!** Dies ist erforderlich, um die Systemdaten zu aktualisieren und Abstürze zu verhindern.

---

### Tabelle PID-Einstellung

**Warum brauche ich das?**

Das Heizbett Ihres Druckers muss, wie der Extruder und die Temperatur genau halten. Wenn er schwankt, kann es zu Problemen mit dem Anhaften der ersten Schicht oder sogar zum Verziehen (Ablösen) des Teils an den Kanten kommen. Durch die PID-Kalibrierung Ihres Heizbett lernen Sie, dass er schnell und konstant die richtige Temperatur erreicht, ohne zu überhitzen.

Empfehlung für AD5X

Öffnen Sie die Datei `printer.cfg` und setzen Sie den Abschnitt ```heater_bed``` auf:
```
[heater_bed].
max_power: 0.6
```
Dadurch heizt sich das Heizbett schneller auf und der PID wird korrekt eingestellt.
Nachdem Sie den Parameter geändert und gespeichert haben, **müssen Sie den Drucker neu starten.**

Sie können auch das Empfehlungs-Plugin aktivieren, das diese Datei selbst korrigiert: ````ENABLE_PLUGIN NAME=Empfehlung```.

**Ein wichtiger Punkt, bevor Sie beginnen!**
Hier gilt die gleiche Regel wie beim Extruder: Kalibrieren Sie die Temperatur, die Sie beim Drucken am häufigsten verwenden werden (z.B. 60°C für PLA oder 110°C für ABS).

**Wie kalibriert man?**

- Verwenden Sie das Makro [PID_TUNE_BED](/de/Calibrations/#pid_tune_bed)

- Es kann auch in die Konsole eingegeben oder über eine Schaltfläche in der Benutzeroberfläche aufgerufen werden (oft neben der Schaltfläche zum Kalibrieren des Extruders):

    <img width="227" height="192" alt="image" src="https://github.com/user-attachments/assets/77dd8332-1912-41df-a94e-469ebfa2f895" />

- Der Befehl für die Tabelle sieht noch einfacher aus:
    ```gcode
    PID_TUNE_BED TEMPERATURE=80
    ```
    **Was das bedeutet:**

    * ```TEMPERATURE=80``` - die Kalibrierung wird für das Heizbett von 80°C durchgeführt. Stellen Sie die gewünschte Temperatur ein.

- **Wenn Sie fertig sind:**
    * Die neuen Einstellungen werden automatisch gespeichert.
        * **Vergessen Sie nicht, den Drucker neu zu starten**, damit die neuen Einstellungen vollständig übernommen werden.

---

### Kalibrierung der Heizbett (BED_LEVEL_SCREWS_TUNE)

**Warum macht man das?**

Das Heizbett wird von mehreren Schrauben zusammengehalten. Wenn diese nicht gleichmäßig verschraubt sind, wird das Heizbett falsch ausgerichtet und der Abstand zwischen dem Heizbett (Druckbett) und der Düse wird ungleichmäßig. Dies führt dazu, dass der Kunststoff schlecht haftet und die Düse das Modell trifft. Diese Kalibrierung hilft dabei, das Heizbett perfekt auszurichten, indem die 4 Schrauben, die ihn festhalten, eingestellt werden können.

**Wie funktioniert sie?**

1.  Der Drucker bringt die Düse nacheinander in die Positionen über jeder Schraube.
2.  misst den Abstand zum Druckbett und zeigt auf dem Bildschirm an, welche Schraube in welche Richtung zu drehen ist.
3.  Sie stellen die Schrauben ein, indem Sie den Aufforderungen folgen.
4.  Der Vorgang wird so lange wiederholt, bis der Tisch waagerecht ist.

**Tuning-Parameter [BED_LEVEL_SCREWS_TUNE](/de/Calibrations/#bed_level_screws_tune):**

* `EXTRUDER_TEMP=130` - Extrudertemperatur. Wird benötigt, damit die thermische Ausdehnung der Düse die Messungen nicht verfälscht. Stellen Sie die Temperatur ein, bei der der Kunststoff noch nicht aus der Düse austritt.
* `BED_TEMP=80` - Temperatur des Heizbett. Das Heizbett dehnt sich auch bei Erwärmung aus, daher sollte die Kalibrierung bei der Temperatur durchgeführt werden, bei der Sie drucken.

Vor der Kalibrierung müssen Sie die Düse reinigen, da sonst die Messungen nicht korrekt sind!

**Kalibrierungsvorgang:**

- Geben Sie einen Befehl in der Konsole ein oder drücken Sie die Taste:

    <img width="344" height="310" alt="image" src="https://github.com/user-attachments/assets/6757eb4e-53b7-4b08-903f-75491b4daace" />

```gcode
BED_LEVEL_SCREWS_TUNE EXTRUDER_TEMP=130 BED_TEMP=80
```

- **Wichtig:**
    * Der Drucker heizt den Extruder und das Heizbett auf die eingestellten Temperaturen auf.
        * Er startet den Vorgang und zeigt Ihnen an, welche Schraube Sie um wie viel Grad drehen müssen (z.B. "clockwise" für im Uhrzeigersinn, "counter-clockwise" für gegen den Uhrzeigersinn).

    <img width="621" height="394" alt="image" src="https://github.com/user-attachments/assets/f930f4ac-e907-4c83-bc1d-3d5a4e06fe3b" />

- Nach dem ersten Durchgang wartet der Drucker, bis Sie die Einstellung vorgenommen haben. Wenn alle Schrauben angezogen sind, **drücken Sie die Wiederholungstaste**, damit der Drucker das Ergebnis prüft. Wiederholen Sie den Vorgang, bis das Ergebnis perfekt ist.

- **Abschluss des Auftrags:**
  *   Wenn Sie den Kalibrierungsmodus beenden und verlassen, setzt der Drucker die Temperatur **NICHT automatisch zurück.**
  *    **Selbsteinstellung der Extruder- und Tischtemperaturen auf Null über das Steuerungsmenü!**
  *    **Das Bettgitter und der Z-Offset werden ungültig.** Starten Sie die Nivellierungskalibrierung **vom Standardbildschirm** aus.

    <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/2d17f77f-a98b-450d-a7e5-72a0a37e47de" />

---

### Präzise Bettnetznivellierung (AUTO_FULL_BED_LEVEL)

**Warum ist dies notwendig?**
Selbst ein perfektes nivelliertes Druckbett kann kleine Vertiefungen oder Unebenheiten aufweisen. Ein Bettnetz (oder "Netzkalibrierung") ist wie eine "Höhenkarte" Ihres Druckbettes. Der Drucker merkt sich diese Unregelmäßigkeiten und verschiebt die Z-Achse während des Drucks leicht, damit die Düse immer den perfekten Abstand zur Oberfläche hat. Dadurch wird sichergestellt, dass die erste Schicht auf dem gesamten Druckbett einwandfrei haftet.

**Warum dieser Befehl?**
Die eingebauten Werkzeuge Fluidd und Mainsail sind für unsere Drucker nicht geeignet, weil sie:

* Sie können nicht mit dem **Berührungssensor** arbeiten (der bei uns für die genaue Berührungserkennung zuständig ist).
* Sie **reinigen die Düse** nicht, bevor Sie beginnen, um alle Kunststofftropfen zu entfernen, die die Genauigkeit der Messungen ruinieren können.

Unser Makro [AUTO_FULL_BED_LEVEL](/de/Macros/#auto_full_bed_level) berücksichtigt diese beiden Eigenschaften!

**Wichtige Einstellungen:**
Die Karte muss unter denselben Bedingungen erstellt werden, unter denen Sie auch drucken - ein erwärmtes Druckbett und ein heißer Extruder, da sich das Metall durch die Temperatur leicht ausdehnt. Eine Bettnetzkarte, die bei 60 Grad gedruckt wird, unterscheidet sich drastisch von einer Bettnetzkarte, die bei 110 Grad gedruckt wird.

* `EXTRUDER_TEMP=255` - Extrudertemperatur. Der Kunststoff in der Düse sollte geschmolzen sein, damit er vor der Messung gereinigt werden kann. Stellen Sie die von Ihnen gewünschte Temperatur ein.
* `BED_TEMP=80` - Heizbetttemperatur. Geben Sie die Temperatur an, die Sie für den Druck verwenden. Stellen Sie die gewünschte Temperatur ein.
* `PROFILE=auto` - Name des Profils, unter dem die Karte gespeichert werden soll. Es ist besser, es nach der Tabellentemperatur zu benennen, zum Beispiel `80`.

**Beispielbefehl:**

```gcode
AUTO_FULL_BED_LEVEL EXTRUDER_TEMP=255 BED_TEMP=80 PROFILE=80
```

<img width="302" height="342" alt="image" src="https://github.com/user-attachments/assets/0fa6cdd8-2098-48e3-8281-8587fb153b0f" />

In diesem Beispiel erstellen wir eine Karte zum Drucken auf einem 80°C-Tisch und speichern sie unter dem Namen `80`.

#### Wie kann ich die gespeicherte Karte beim Drucken verwenden?

Damit der Drucker zu Beginn jedes Druckvorgangs automatisch das richtige Kennfeld lädt, fügen Sie die folgenden Zeilen in den **Start G-Code* Ihres OrcaSlicer ein:

```gcode
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single] MESH=80
M190 S[bed_temperature_initial_layer_single] ; Warten auf Aufwärmen der Tabelle
M104 S[nozzle_temperature_initial_layer] ; Düsentemperatur einstellen
```

**Was ist hier los:**

* [START_PRINT](/de/Main/#start_print) ist das grundlegende Startmakro
* Die Zeile `START_PRINT... MESH=80` weist den Drucker an: „Starte den Druckvorgang und lade das Bettnetz mit der Bezeichnung `80`.“
* `[nozzle_temperature_initial_layer]` und `[bed_temperature_initial_layer_single]` sind Variablen des Slicers, die automatisch die von Ihnen eingestellten Temperaturen für die erste Schicht ersetzen.
* Das Wichtigste ist, dass der Parameter `MESH=` auf denselben Profilnamen (in unserem Beispiel `80`) zeigt, den Sie in `AUTO_FULL_BED_LEVEL` verwendet haben.

Noch besser: Erstellen Sie mehrere Netze für jede Temperatur (60, 70, 80, 90, 100, 110) und verwenden Sie den folgenden Startcode:

```gcode
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single] MESH=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single] ; Warten auf Aufwärmen des Tisches
M104 S[nozzle_temperature_initial_layer] ; Düsentemperatur einstellen
```

In diesem Fall wird die Bettnetzkarte geladen, die der Temperatur der Tabelle entspricht.

> [!NOTE]
> Wenn es keine gespeicherte Bettnetzkarte für den eingestellten Wert im Slicer gibt (z.B. 77 Grad eingestellt), entfernt der Algorithmus die Bettnetzkarte und bietet an, sie am Ende des Drucks unter dem Namen 77 zu speichern.

**Gesamte Reihenfolge der Operationen:**

1.  Erstellen Sie eine Bettnetzkarte mit dem Makro `AUTO_FULL_BED_LEVEL` für Ihre Drucktemperatur.
2.  Fügen Sie den Befehl `START_PRINT` zum Startcode des Slicers hinzu, wobei der Parameter `MESH=...` auf Ihren Profilnamen verweist.
3.  Der Drucker verwendet nun für jeden Druckvorgang automatisch die korrekte Bettnetzkarte!

---

### Adaptive Tabellenkalibrierung (KAMP)

**Warum wird es benötigt?**
[KAMP](/de/Calibrations/#kamp) ist ein intelligentes System, das ein Druckbettnetz nicht über die gesamte Fläche, sondern nur in dem Bereich aufbaut, in dem sich Ihre Modelle befinden! Dies beschleunigt die Druckvorbereitung erheblich, insbesondere bei großen Druckern, und erhält gleichzeitig alle Vorteile eines präzisen Druckbettnetzes.

**Wie funktioniert es?**

1.  Vor Druckbeginn analysiert KAMP die Lage aller Objekte auf dem Druckbett.
2.  Anstatt ein komplettes Raster zu erstellen, misst er die Höhe des Druckbettes nur im gewünschten Bereich.
3.  Das spart Zeit, ohne die Druckqualität zu beeinträchtigen.
4.  Die Karte wird dichter und damit genauer.

> [!IMPORTANT]
> **Ein wichtiges Merkmal des Verfahrens:**
> 
> Bei der Verwendung von KAMP (und auch bei der vollständigen Kalibrierung) verhält sich der Drucker auf intelligente Weise, um maximale Genauigkeit zu gewährleisten:

1.  Die Düse wird **auf Drucktemperatur** erhitzt.
2.  Es erfolgt eine **Reinigung der Düse** von auslaufendem Kunststoff.
3.  Die Düse **kühlt auf 120°C** ab. Damit soll verhindert werden, dass geschmolzener Kunststoff während der Messungen aus der sauberen Düse tropft, was die Ergebnisse verfälschen könnte.
4.  Die Messung des **Bettnetz** erfolgt mit einer **kalten und sauberen Düse.**
5.  Nach der Messung wird die Düse **auf Drucktemperatur** aufgeheizt, um mit dem Druck zu beginnen.

#### KAMP einrichten

**Wann sollte man KAMP verwenden?**

In den meisten Fällen ist es nicht notwendig, vor jedem Druck ein Bettnetz zu erstellen. Die Ausnahme ist, wenn Sie **Druckplatten mit unterschiedlichen Dicken** (z.B. PEI-Platte und Glas) verwenden, da diese unterschiedliche Höhen haben können.

**1. Aktivieren der adaptiven Kalibrierung (KAMP)**

Aktivieren Sie diese Option, damit der Drucker nach Möglichkeit KAMP verwendet [SAVE_ZMOD_DATA USE_KAMP=1](/de/Global/#use_kamp).

```gcode
SAVE_ZMOD_DATA USE_KAMP=1
```

Orca anpassen:

- ```Prozessprofil``` -> ```Sonstiges``` -> ```G-Code Ausgabe``` -> ```Objekte beschriften``` das Häkchen setzen
- ```Prozessprofil``` -> ```Sonstiges``` -> ```G-Code Ausgabe``` -> ```Objekte ausschließen``` aktivieren Sie das Kontrollkästchen

<img width="285" height="171" alt="image" src="https://github.com/user-attachments/assets/faceef98-2791-4975-bf72-425f4a2b1dfa" />

**2. Aktivieren Sie die Kalibrierung vor jedem Druck**

Wenn Sie möchten, dass der Drucker vor jedem Druckauftrag automatisch eine Bettnetzkarte erstellt (z.B. bei häufigem Plattenwechsel), aktivieren Sie diese Funktion [SAVE_ZMOD_DATA PRINT_LEVELING=1](/de/Global/#print_leveling).

```gcode
SAVE_ZMOD_DATA PRINT_LEVELING=1
```

Der Startcode kann wie folgt verwendet werden:

```gcode
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single] ; Warten auf Aufwärmen des Tisches
M104 S[nozzle_temperature_initial_layer] ; Düsentemperatur einstellen
```

> [!IMPORTANT]
> **Wichtig für die Arbeit vom systemeigenen Bildschirm aus:**
> 
> Um die Bettnivellierung über den Standardbildschirm des Druckers zu starten, müssen Sie das Bildschirmmenü aufrufen:
> ```Einstellungen``` → ```Wifi-Symbol``` → ```Netzwerkmodus``` → den Schieberegler ```Nur lokale Netzwerke``` aktivieren.

**3. Intelligente Reinigung vor dem Drucken**

Fügen Sie diese Einstellung hinzu, damit der Drucker für die Düsenreinigung denselben Bereich verwendet, in dem er zuvor das Druckbettnetz erstellt hat. Dies spart Platz und Zeit. [SAVE_ZMOD_DATA CLEAR=LINE_PURGE](/de/Global/#clear).

```gcode
SAVE_ZMOD_DATA CLEAR=LINE_PURGE
```

#### Fazit: Wie man KAMP für den perfekten Druck einrichtet

Um die intelligente Bettnivellierung vor jedem Druckvorgang zu aktivieren, führen Sie folgenden Befehl einmalig aus:

```gcode
SAVE_ZMOD_DATA USE_KAMP=1 PRINT_LEVELING=1 CLEAR=LINE_PURGE
```

Vor jedem Druckvorgang nimmt der Drucker nun nur dort ein Bettnetz auf, wo Objekte gedruckt werden sollen.

---

### Wie funktioniert Z-Offset auf Ihrem Drucker?

**Was ist Z-Offset?**

Einfach ausgedrückt handelt es sich um den **exakten Abstand zwischen der Düsenspitze und dem Druckbett** in dem Moment, in dem der Drucker denkt, dass sie sich "berühren". Ein korrekter Z-Offset gewährleistet, dass die erste Kunststoffschicht perfekt auf dem Druckbett haftet - nicht zu niedrig (die Düse berührt ddas Druckbett) und nicht zu hoch (der Kunststoff haftet nicht). [Mehr lesen](/de/FAQ/#so-funktioniert-z-offset)

**Wichtigste Regel:**

Bei unserem Drucker ist der **Z-Offset NUR während des Drucks** relevant. Die Werte, die Sie auf dem Bildschirm oder in der Schnittstelle VOR oder NACH dem Druck sehen, dienen nur als Referenz und spiegeln nicht das tatsächliche Bild wieder.

#### Anpassen des Z-Offsets vom nativen Bildschirm des Druckers

Der systemeigene Bildschirm ist das wichtigste Werkzeug zur Einstellung des Z-Offsets. Er steuert automatisch den Offset und seine Einstellungen werden sicher gespeichert.

**Damit der Drucker den Z-Offset automatisch einstellt, müssen Sie die Nivellierung über den systemeigenen Bildschirm ausführen.**

<img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/7e5f1ba4-832e-493b-94be-14aadf67ad4e" />

**Anpassen:**

1.  Die Einstellung ist **nur während des Drucks** möglich.
2.  Drücken Sie auf dem Touchscreen auf das **untere rechte Quadrat**.
    
    <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/ae62aced-07af-489f-99b1-ce91cd55027d" />

3.  Klicken Sie dann auf das **Bleistiftsymbol**, um den Z-Offset-Wert zu bearbeiten.
    
    <img width="800" height="474" alt="image" src="https://github.com/user-attachments/assets/7d185d47-6c60-4d57-8901-923971a9ee7f" />

4.  Änderungen basierend auf der Qualität der ersten Schicht vornehmen.

> [!IMPORTANT]
> **Wichtig zu wissen:**
>
> * Für den AD5M-Drucker wird auf dem nativen Bildschirm immer ein fester Wert von **0,025mm** zu Ihrem Wert hinzugefügt.
> * Der Z-Offset, den Sie im Fluidd- oder Mainsail-Interface sehen, wird also immer **0,025mm MEHR** sein als der Wert, den Sie auf dem Druckerbildschirm eingestellt haben. Das ist normal!

**Zweite wichtige Regel:**

**Der Z-Offset ist für native und nicht-native Bildschirme unterschiedlich,** jeder hat seine eigene Einstellung. Verwenden Sie ```LOAD_ZOFFSET_NATIVE```, um den Z-Offset vom nativen Bildschirm in den nicht-nativen Bildschirmmodus zu kopieren.

#### Einstellen des Z-Offsets über Fluidd / Mainsail / GuppyScreen beim Arbeiten **im nicht-nativen Bildschirmmodus**

**Wie es funktioniert:**

1.  Damit sich der Drucker den Z-Offset aus dem Webinterface und GuppyScreen merkt, muss einmalig die spezielle Einstellung [SAVE_ZMOD_DATA LOAD_ZOFFSET=1](/de/Global/#load_zoffset) aktiviert werden:
   
```gcode
SAVE_ZMOD_DATA LOAD_ZOFFSET=1
```
*Dieser Befehl weist das System an, den Z-Offset aus den gespeicherten Einstellungen zu laden und nicht auf Null zu setzen.*

2.  Sobald diese Option aktiviert ist, können Sie den Z-Offset direkt während des Drucks in Fluidd/Mainsail oder über das Einstellungsfeld in GuppyScreen anpassen.

    <img width="418" height="73" alt="image" src="https://github.com/user-attachments/assets/96d644b3-9c52-44d1-9a7c-18ccbac61796" />

    <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/0f282f39-dec1-4488-9317-4e1395747277" />

Wenn Sie den Z-Offset vom nativen Bildschirm in den nicht-nativen Modus übertragen wollen, rufen Sie das Makro ```LOAD_ZOFFSET_NATIVE``` auf, es liest den Z-Offset-Wert vom nativen Bildschirm und wendet ihn auf den nicht-nativen Bildschirm-Modus an.

**Wichtigste Vorteile:**

* **Automatische Speicherung.** Unabhängig von der Anpassungsmethode (Bildschirm oder Webinterface) wird der z-Offset-Wert automatisch gespeichert und beim nächsten Druckvorgang automatisch angewendet.
* **Es sind keine manuellen Befehle erforderlich.** Sie müssen NICHT die Befehle `Z_OFFSET_APPLY_PROBE` oder `Z_OFFSET_APPLY_ENDSTOP` verwenden. Die gesamte Arbeit findet "unter der Motorhaube" statt.

#### Über Z-Offset in einfachen Worten:

* **Z-Offset nur beim Drucken der ersten Ebene einstellen.**
* **Wenn Sie mit dem nativen Bildschirm arbeiten, passen Sie den Z-Offset auf dem nativen Bildschirm an.**
* **Wenn Sie im nicht-nativen Bildschirmmodus arbeiten**, führen Sie zuerst den Befehl ```SAVE_ZMOD_DATA LOAD_ZOFFSET=1``` aus.
* Das System wird alles von selbst speichern. Sie brauchen sich um nichts zu kümmern.

> [!WARNING]
> 
>   Sie können `Z_OFFSET_APPLY_ENDSTOP` auf diesem Drucker nicht verwenden.
>    
>   Und Sie können es nicht ändern ```[probe] z_offset: ``` in ```printer.cfg``` oder ```printer.base.cfg```.
>    
>   Denn der native Bildschirm und das ```START_PRINT```-Makro laden den Offset zu Beginn des Drucks.

---

### Input Shaper Kalibrierung

**Was sind Shaper und warum werden sie benötigt?**

Wenn sich der Drucker schnell bewegt, kann er wie eine Maschine mit hoher Geschwindigkeit vibrieren. Diese Vibrationen werden auf Ihrem Modell als "Wellen" oder "Ghosting" an den Wänden abgebildet. Shaper sind clevere Algorithmen, die diese Vibrationen "vorhersagen" und unterdrücken, so dass Sie schneller drucken können, ohne an Qualität zu verlieren.

Ihr Drucker hat bei der ersten Kalibrierung bereits automatisch Shaper eingestellt, und das reicht für die meisten Aufgaben aus. Wenn Sie jedoch die Qualität maximieren oder die Funktionsweise Ihres Druckers besser verstehen möchten, können Sie sich die Diagramme ansehen und manuelle Einstellungen vornehmen.

> [!IMPORTANT]
> #### Wichtig: Der Parameter `FIX_SCV`

**Wo liegt das Problem?**

Graph- und Shaper-Berechnungen in Klipper verwenden den Standardwert "square_corner_velocity = 5". In unserem Drucker ist der Wert dieses Parameters jedoch mit "25" angegeben. Diese Diskrepanz führt dazu, dass die berechneten Werte der maximalen Beschleunigung auf den Diagrammen um ein Vielfaches überschätzt werden.

**Was ist zu tun?**

1.  **Korrektur der Berechnungen:** Aktivieren Sie den Fix, um die Diagramme korrekt anzuzeigen [SAVE_ZMOD_DATA FIX_SCV=1](/de/Global/#fix_scv).

```gcode
SAVE_ZMOD_DATA FIX_SCV=1
```

2.  **Verbesserung der Druckqualität (empfohlen):** Fügen Sie die folgende Zeile in die Datei ```mod_data/user.cfg``` ein:

```ini
[printer].
square_corner_velocity: 9
```

  * **Was bewirkt dies?** Der Drucker wird in scharfen Ecken leicht verlangsamt. Dies erhöht die Druckzeit geringfügig, reduziert aber die Vibrationen und verbessert die Eckenschärfe.

Sie können die Sache vereinfachen. Geben Sie in der Konsole ```ENABLE_PLUGIN name=recommend``` ein. Dieser Befehl aktiviert das Empfehlungs-Plugin, für das ```FIX_SCV``` bereits aktiviert und ```square_corner_velocity: 9``` gesetzt ist.

Vergessen Sie nicht, den Drucker neu zu starten!

#### Wie man das Makro `ZSHAPER` benutzt

[ZSHAPER](/de/Calibrations/#zshaper) - dieses Makro lässt den Drucker bei verschiedenen Frequenzen vibrieren, misst die Reaktion und zeichnet die idealen Shaper-Parameter für die X- und Y-Achse auf.

**Funktion für Drucker mit geringem Speicherplatz (AD5M, AD5MPro):**

Um eine Überlastung des Systems zu vermeiden, **müssen die Achsen einzeln kalibriert werden**.

* `ZSHAPER` - kalibriert beide Achsen (X und Y).
* `ZSHAPER X=1 Y=0` - kalibriert nur die X-Achse (schneller und weniger belastend).
* `ZSHAPER Y=1 X=0` - kalibriert nur die Y-Achse.

**Anwendungsbeispiel und Ausgabe:**

1.  Geben Sie den Befehl zur Kalibrierung der Y-Achse in die Konsole ein:

```gcode
ZSHAPER Y=1 X=0
```

2.  Sobald die Messungen abgeschlossen sind, erhalten Sie einen Bericht wie diesen:

```
// Empfohlener Shaper ist zv @ 53,2 Hz
// Angepasster Shaper 'zv' Frequenz = 53,2 Hz (Schwingungen = 0,9%, Glättung ~= 0,074)
// Um eine zu starke Glättung mit 'zv' zu vermeiden, wird max_accel <= 10200 mm/sec^2 vorgeschlagen
// Angepasste Shaper 'mzv' Frequenz = 54.2 Hz (Vibrationen = 0.0%, Glättung ~= 0.080)
// Um eine zu starke Glättung mit 'mzv' zu vermeiden, wird max_accel <= 8700 mm/sec^2 vorgeschlagen
```

    * Das System empfiehlt den Shaper `zv`, weil er die geringste Glättung (`smoothing`) aufweist.
        * Der Shaper `mzv` hingegen unterdrückt die Vibrationen vollständig (`0.0%`), obwohl er etwas weniger Beschleunigung benötigt.

#### Wie man die Ergebnisse interpretiert und eine Entscheidung trifft

**Wo kann man die Graphen sehen?**

Nach dem Ausführen von `ZSHAPER` erscheinen die Graphen und CSV-Dateien in der Registerkarte **"Konfiguration" -> mod_data** in Ihrem Webinterface (Fluidd/Mainsail).

<img width="996" height="596" alt="image" src="https://github.com/user-attachments/assets/7e1dbdf8-5de5-4ce6-8f4a-2c37b320b8b3" />

**Ausführliche Anleitung zum Lesen von Karten:** [https://github.com/Tombraider2006/klipperFB6/blob/main/accel_graph/readme.md](https://github.com/Tombraider2006/klipperFB6/blob/main/accel_graph/readme.md)

**Option 1: Automatische Einstellung akzeptieren**

Wenn Sie mit allem zufrieden sind, klicken Sie einfach auf die Schaltfläche **"KONFIG. SPEICHERN & NEU STARTEN "** in der Webschnittstelle, und der Drucker wird die empfohlenen Einstellungen selbständig speichern.

<img width="324" height="68" alt="image" src="https://github.com/user-attachments/assets/9c76d5f7-0021-4e03-b495-6736f49dc1c9" />

<img width="745" height="389" alt="image" src="https://github.com/user-attachments/assets/b5b55e95-52af-4ee0-b34e-5bc6077d8d10" />

**Option 2: Manuelle Anpassung**

Im obigen Beispiel erwies sich der `mzv` Shaper als besser, da er Vibrationen vollständig eliminiert. Um ihn zu verwenden, müssen Sie die Einstellungen manuell zur `printer.cfg` Datei hinzufügen (im Abschnitt `[input_shaper]`):

```ini
[input_shaper].
shaper_type_y = mzv ; Ausgewählter Shaper-Typ für die Y-Achse
shaper_freq_y = 54.2 ; Resonanzfrequenz für die Y-Achse
```

**Und vergessen Sie nicht die Beschleunigung!**
Da der gewählte Shaper `mzv` eine Beschleunigung von nicht mehr als 8700 mm/s² erlaubt, sollte dieser Wert in die Datei `mod_data/user.cfg` geschrieben werden:

```ini
[printer].
max_accel: 8700 ; Maximale Beschleunigung fuer X und Y Achsen
```

#### Kurzer Algorithmus der Aktionen für die Shaper-Kalibrierung:

1.  Ausführen von `SAVE_ZMOD_DATA FIX_SCV=1` für korrekte Berechnungen.
2.  Hinzufügen von `square_corner_velocity: 9` zu `mod_data/user.cfg` für bessere Qualität.
3.  Führen Sie die Kalibrierung der gewünschten Achse durch, z.B. `ZSHAPER Y=1`.
4. prüfen Sie die Graphen und die Konsolenausgabe.
5.  Drücken Sie entweder `SAVE CONFIG`, oder schreiben Sie manuell die gewünschten Werte für `shaper_type` und `shaper_freq` in `printer.cfg` und `max_accel` in `mod_data/user.cfg`.
6.  Starten Sie den Drucker neu.
