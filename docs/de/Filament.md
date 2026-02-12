<h1 align="center">Filament</h1>

Ein Makro ist ein kleines Programm in der Sprache Klipper/Gcode.

Es kann aufgerufen werden durch:

- Aus der GCODE-Datei
- Von der Fluidd/Mainsail-Konsole (drücken Sie den englischen Buchstaben "C" in Fluidd)

!!! Hinweis
    *Der Wert in Klammern ist der Standardwert.

---

### COLDPULL

Coldpool (Düsenreinigung) ohne Gewalt.
Implementierung von [diesem Algorithmus](https://t.me/FF_5M_5M_Pro/2836/447172)

- Wählen Sie das zu reinigende Material (PETG, ABS, NEYLON).
- Befolgen Sie die Anweisungen in der FLUIDD-Konsole.
- Ziehen Sie die Rückstände aus der Düse

---

### M600

Pause und Filament ersetzen

---

### FARBE

* * nur AD5X * *

Steuert den Kunststofftyp, die Kunststofffarbe und das Laden und Entladen des Filaments von farbigen Spulen.

Funktioniert nur bei Betrieb im nativen Bildschirmmodus

---

### SET_PAUSE_NEXT_LAYER

Pause/Aufrufmakro auf der nächsten Ebene setzen

- ENABLE - 0 - ausschalten, 1 - einschalten (1)
- MACRO - aufzurufendes Makro (`PAUSE`)

---

### SET_PAUSE_AM_LAYER

Aktivieren/Deaktivieren der Pause bei einer bestimmten Ebenennummer

- ENABLE - 0 - ausschalten, 1 - einschalten (1)
- MACRO - aufzurufendes Makro (`PAUSE`)
- LAYER - Ebenennummer (0)

---
!!! Warnung
    Damit diese Funktionen funktionieren, müssen Sie den Startcode ergänzen:
    ```
    SET_PRINT_STATS_INFO TOTAL_LAYER=[total_layer_count]
    ```
    
    Fügen Sie im Code für den Ebenenwechsel Folgendes hinzu:
    ```
    SET_PRINT_STATS_INFO CURRENT_LAYER={schicht_zahl + 1}
    ```

