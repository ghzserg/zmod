# Plugins in Z-Mod

Jeder Benutzer kann sein eigenes Plugin erstellen und mit **Z-Mod** verbinden.

In Z-Mod enthaltene Plugins:

1. [Recommend](https://github.com/ghzserg/recommend/blob/main/Readme.md) - Einstellungen, deren Verwendung unmittelbar nach der Installation des Mods empfohlen wird
2. [G28_tenz](https://github.com/ghzserg/g28_tenz/blob/main/Readme.md) - Parken der Z-Achse durch Wägezellen
3. [Nopoop](https://github.com/ghzserg/nopoop/blob/master/Readme.md) - maximale Abfallreduzierung von ninjamida.
4. [TimeLapse](https://github.com/ghzserg/timelapse/blob/main/Readme.md) - Moonraker Timelapse
5. [Notify](https://github.com/ghzserg/notify/blob/main/Readme.md) - Benachrichtigungen in Telegram und mehr als 100 anderen Diensten.

Externe Plugins, die nicht vom Autor von Z-Mod entwickelt wurden:

1. [Bambufy](https://github.com/function3d/bambufy/blob/master/README.md) - kompatibel mit Bambu Studio, verbessert die Kontrolle des Reinigungsturms, bietet genaue Zeit- und Materialverbrauchsschätzungen, reduziert Abfall, unterstützt Mainsail, schnelle Farbwechsel und erweiterte Druckfunktionen. KANN NICHT MIT DEM NATIVEN BILDSCHIRM VERWENDET WERDEN.
2. [lessWaste](https://github.com/Hrybmo/lessWaste/blob/master/README.md) - ein Fork von Bambufy
3. [Dryer](https://github.com/pantata/dryer) - Filamenttrocknung auf dem Heizbett
4. [IFS Jacker](https://github.com/ninjamida/ifs_jacker_plugin) – Plugin zur Unterstützung des [IFS Jacker Hardware-Mods](https://github.com/ninjamida/ifs-jacker). Es ermöglicht die automatische Erkennung der verfügbaren Kanalanzahl sowie die Klipper-Integration für Lüfter, LEDs und Sensoren, die über einen IFS Jacker verbunden sind.
5. [HelixScreen](https://github.com/prestonbrown/helixscreen) – eine alternative Bildschirmimplementierung
6. [QuickSwap](https://github.com/ninjamida/quickswap-5x) - Plugin für schnelleren Farbwechsel auf dem AD5X
7. [Flook32](https://github.com/ghzserg/flook32_plugin) - Plugin zum Anschließen des Trockners [Flook32](https://github.com/schreider/flook32) [En](https://github.com/ghzserg/flook32)
8. [Print Buddy](https://github.com/catduckgnaf/print-buddy) - Meldet andere AD5X-IFS-Slots mit derselben Farbe und demselben Material. Wechselt kein Filament.
9. [Zmod AFC Lite](https://github.com/DIEHARDave/zmod_afclite) - Zeigt die IFS-Slots des AD5X oder die Werkzeugköpfe des Creator 5 als AFC-Lanes in den AFC-Panels von Mainsail und Fluidd, mit Laden/Entladen, Farbe, Material und Spoolman-Spulen.

Um das Repository für externe Plugins zu aktivieren, führen Sie den Befehl `PLUGINS` aus.

---

## Plugin verwalten

**Plugin aktivieren:**
```gcode
ENABLE_PLUGIN name=g28_tenz
```

- lädt das Plugin herunter und startet Klipper bei Erfolg neu.

**Plugin deaktivieren:**
```gcode
DISABLE_PLUGIN name=g28_tenz
```

---

## PLUGINS

Zeigt das Menü zur Plugin-Verwaltung an.

<img width="849" height="838" alt="{9D0BE78C-816B-4F22-B3F1-8FC678AD8977}" src="https://github.com/user-attachments/assets/a23b06e2-abe3-4ff0-93c7-079d2d057e1b" />

In diesem Menü können Sie zusätzliche Plugins aktivieren, deaktivieren und vollständig entfernen.

- Linke Spalte (Aktivierung): Klicken Sie, um das Plugin zu aktivieren oder zu deaktivieren.
    - Grüne Schaltfläche — das Plugin ist aktiv.
    - Graue Schaltfläche — das Plugin ist deaktiviert.
- Rechte Spalte (Updates): aktiviert oder deaktiviert automatische Updates über Moonraker.
    - UPDATE: ON — Updates sind aktiviert.
    - UPDATE: OFF — Updates sind deaktiviert.

**So entfernen Sie ein Plugin vollständig:**

Wenn Sie ein Plugin nicht mehr benötigen, schalten Sie beide Schaltflächen auf Grau (deaktivieren Sie das Plugin selbst und seine Updates), drücken Sie SAVE (MOONRAKER RESTART) und starten Sie den Drucker anschließend neu. Das System löscht seinen Ordner automatisch aus `mod_data/plugins/`.

---

## Klassische Klipper-Plugins mit Python-Modulen installieren

Klassische Klipper-Plugins, die mit Python-Modulen arbeiten (z.B. [klipper-led_effect](https://github.com/julianschill/klipper-led_effect)), erfordern einen speziellen Installationsprozess mit der Erstellung eines symbolischen Links zum Klipper-Modul.

#### Beispiel: Installation von led_effect

`led_effect` ist ein Plugin zur Steuerung von WS2812 RGB LED-Streifen über Klipper.

**Schritt 1: Klonen des Repositorys**

Führen Sie diese Befehle in einer chroot-Umgebung aus:

```bash
# Für FF5M:
chroot /data/.mod/.zmod/
# Für FF5X:
chroot /usr/data/.mod/.zmod/

# Gleich für alle Modelle:
cd /opt/config/mod_data/plugins/
git clone https://github.com/julianschill/klipper-led_effect.git
```

**Schritt 2: Hinzufügen eines Eintrags zur Moonraker-Konfiguration**

Fügen Sie in der Datei `mod_data/user.moonraker.conf` den folgenden Abschnitt hinzu:

```ini
[update_manager led_effect]
Typ: git_repo
Kanal: stable
Pfad: /opt/config/mod_data/plugins/klipper-led_effect
Herkunft: https://github.com/julianschill/klipper-led_effect.git
is_system_service: Falsch
primärer_Zweig: master
```

**Schritt 3: Erstellen eines symbolischen Links auf das Klipper-Modul**

Erstellen Sie einen symbolischen Link, um das Modul mit Klipper zu verbinden:

```bash
exit
# Native Klipper
ln -s /opt/config/mod_data/plugins/klipper-led_effect/src/led_effect.py /usr/prog/klipper/klippy/extras/led_effect.py
# Klipper 13
ln -s /opt/config/mod_data/plugins/klipper-led_effect/src/led_effect.py /usr/data/zmod/klipper/klippy/extras/led_effect.py
```

Ersetzen Sie dabei:

- `klipper-led_effect` durch Ihren Plugin-Ordner
- `led_effect.py` durch den Modulnamen (kann je nach Plugin unterschiedlich sein)

**Schritt 4: Klipper neu laden**

Nachdem Sie den symbolischen Link erstellt haben, müssen Sie Klipper über die Fluidd/Mainsail-Weboberfläche neu laden, indem Sie auf die Schaltfläche „Reload“ klicken.

!!! info "**Wichtige Hinweise**"
    **Das Modul muss mit der Klipper-Version kompatibel sein**
    Stellen Sie sicher, dass die Plugin-Version mit der installierten Klipper-Version kompatibel ist.

---

## Erstellen Sie Ihr eigenes Plugin

Plugin-Beispiel: https://github.com/ghzserg/g28_tenz
(Alle Beispiele unten verwenden den Namen `g28_tenz` – ersetzen Sie ihn durch den Namen Ihres Plugins.)

---

### Hinzufügen eines Plugins

Fügen Sie in der Datei `mod_data/user.moonraker.conf` einen Abschnitt hinzu:

```ini
[update_manager g28_tenz]
type: git_repo
channel: dev
path: /root/printer_data/config/mod_data/plugins/g28_tenz
origin: https://github.com/ghzserg/g28_tenz.git
is_system_service: False
primary_branch: main
```

- **Pfad zum Plugin**: `/root/printer_data/config/mod_data/plugins/g28_tenz`
- **Quelle**: `https://github.com/ghzserg/g28_tenz.git`

!!! info
    Stabile Plugins können im Lieferumfang von Z-Mod enthalten sein, werden aber von ihren Autoren aktualisiert und verwaltet.

---

### Installationsskript

Nach dem Aufruf von `ENABLE_PLUGIN` wird automatisch die Datei `install.sh` aufgerufen.

Nach dem Aufruf von `DISABLE_PLUGIN` wird automatisch die Datei `uninstall.sh` aufgerufen.

### Update-Skript

Wenn der Update-Manager das Plugin aktualisiert, wird `update.sh` automatisch ausgeführt, sofern die Datei existiert.

### Einsprachiges Plugin
Es muss die Datei enthalten:
```
g28_tenz.cfg
```
Sie enthält alle Funktionen.

### Mehrsprachiges Plugin
Die Dateien sind in Unterverzeichnissen nach Sprachen geordnet:
```
en/g28_tenz.cfg
ru/g28_tenz.cfg
de/g28_tenz.cfg
...
```

Alle Ausgabezeilen müssen maskiert werden, z. B.:
```gcode
RESPOND PREFIX="info" MSG="===Schneiden des Fadens==="
```

---

#### Übersetzung

Übersetzungen werden im Verzeichnis `translate/` in Dateien der Form `de.csv` gespeichert:

```csv
Cutting the filament;Schneiden des Filaments
```

Format:
```
Englische Phrase;Übersetzung in die gewünschte Sprache
```

Um Sprachdateien zu erzeugen, führen Sie aus:
```bash
./Make.sh
```
Das Skript erstellt die erforderlichen Verzeichnisse und `.cfg`-Dateien.
