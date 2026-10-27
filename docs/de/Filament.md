<h1 align="center">Filament</h1>

Ein Makro ist ein kleines Programm in der Sprache Klipper/Gcode.

Es kann aufgerufen werden:

- aus der G-Code-Datei
- über die Fluidd/Mainsail-Konsole (drücken Sie in Fluidd die lateinische Taste „C“)

!!! info "Hinweis"
    *Der Wert in Klammern ist der Standardwert.*

---

### COLDPULL

Cold Pull (Düsenreinigung) ohne Kraftaufwand.
Implementierung von [diesem Algorithmus](https://t.me/FF_5M_5M_Pro/2836/447172)

- Wählen Sie das zu reinigende Material (PETG, ABS, NYLON).
- Befolgen Sie die Anweisungen in der Fluidd-Konsole.
- Ziehen Sie die Rückstände aus der Düse.

---

### M600

Pause und Filamentwechsel

---

### COLOR

*nur AD5X*

Steuert den Kunststofftyp, die Kunststofffarbe und das Laden und Entladen des Filaments von farbigen Spulen.

Funktioniert nur mit aktiviertem nativen Bildschirm.

---

### SET_PAUSE_NEXT_LAYER

Pause/Makro auf der nächsten Schicht auslösen:

- `ENABLE` — `0` = deaktivieren, `1` = aktivieren (Standard: `1`)
- `MACRO` — aufzurufendes Makro (z. B. `PAUSE`)

---

### SET_PAUSE_AT_LAYER

Pause bei einer bestimmten Schichtnummer aktivieren/deaktivieren:

- `ENABLE` — `0` = deaktivieren, `1` = aktivieren (Standard: `1`)
- `MACRO` — aufzurufendes Makro (z. B. `PAUSE`)
- `LAYER` — Ziel-Schichtnummer (Standard: `0`)

---
!!! warning "Warnung"
    Damit diese Funktionen funktionieren, müssen Sie den Startcode ergänzen:
	
	Maschinen-Start-G-Code:
    ```
    SET_PRINT_STATS_INFO TOTAL_LAYER=[total_layer_count]
    ```
    
	G-Code vor dem Schichtwechsel:
	
    ```
    SET_PRINT_STATS_INFO CURRENT_LAYER={layer_num + 1}
    ```

