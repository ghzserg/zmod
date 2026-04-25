<h1 align="center">Filament</h1>

Ein Makro ist ein kleines Programm in der Sprache Klipper/Gcode.

Es kann aufgerufen werden durch:

- Aus der GCODE-Datei
- Von der Fluidd/Mainsail-Konsole (drücken Sie den englischen Buchstaben "C" in Fluidd)

!!! info "Hinweis"
    *Der Wert in Klammern ist der Standardwert.*

---

### COLDPULL

Kaltes Ziehen (Düsenreinigung) ohne Kraftaufwand.
Implementierung von [diesem Algorithmus](https://t.me/FF_5M_5M_Pro/2836/447172)

- Wählen Sie das zu reinigende Material (PETG, ABS, NEYLON).
- Befolgen Sie die Anweisungen in der FLUIDD-Konsole.
- Ziehen Sie die Rückstände aus der Düse

---

### M600

Pause und Filament ersetzen

---

### COLOR

*nur AD5X*

Steuert den Kunststofftyp, die Kunststofffarbe und das Laden und Entladen des Filaments von farbigen Spulen.

Funktioniert nur bei Betrieb im nativen Bildschirmmodus

---

### SET_PAUSE_NEXT_LAYER

Makro auf der nächsten Ebene pausieren/auslösen:

- `ENABLE` — `0` = deaktivieren, `1` = aktivieren (Standard: `1`)
- `MACRO` — aufzurufendes Makro (z. B. `PAUSE`)

---

### SET_PAUSE_AT_LAYER

Pause bei einer bestimmten Layernummer aktivieren/deaktivieren:

- `ENABLE` — `0` = deaktivieren, `1` = aktivieren (Standard: `1`)
- `MACRO` — aufzurufendes Makro (z. B. `PAUSE`)
- `LAYER` — Ziel-Layernummer (Standard: `0`)

---
!!! warning "Warnung"
    Damit diese Funktionen funktionieren, müssen Sie den Startcode ergänzen:
	
	Maschinen Start G-Code:
    ```
    SET_PRINT_STATS_INFO TOTAL_LAYER=[total_layer_count]
    ```
    
	G-Code vor dem Schichtwechsel:
	
    ```
    SET_PRINT_STATS_INFO CURRENT_LAYER={layer_num + 1}
    ```

