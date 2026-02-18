# Plugins in zMod

Jeder Benutzer kann sein eigenes Plugin erstellen und mit **zmod** verbinden.

In zMod enthaltene Plugins:

1. [Recommend](https://github.com/ghzserg/recommend/blob/main/Readme_ru.md) - Einstellungen, deren Verwendung unmittelbar nach der Installation der Mod empfohlen wird
2. [G28_tenz](https://github.com/ghzserg/g28_tenz/blob/main/Readme_ru.md) - Parken der Z-Achse durch Wägezellen
4. [Nopoop](https://github.com/ghzserg/nopoop/blob/master/Readme_ru.md) - Maximierung der Abfallreduzierung von ninjamida.
5. [Zeitraffer](https://github.com/ghzserg/timelapse/blob/main/Readme_ru.md) - Moonraker Zeitraffer
6. [Notify](https://github.com/ghzserg/notify/blob/main/Readme_ru.md) - Erhalten Sie Benachrichtigungen auf Telegram und über 100 anderen Diensten.

Externe Plugins, die nicht vom Autor von zMod entwickelt wurden.

1. [Bambufy](https://github.com/function3d/bambufy/blob/master/README_ru.md) - Kompatibel mit Bambu Studio, verbessert die Kontrolle des Futterturms, bietet genaue Zeit- und Materialverbrauchsschätzungen, reduziert Abfall, unterstützt Mainsail, schnelle Farbwechsel und erweiterte Druckfunktionen. KANN NICHT MIT DEM NATIVEN BILDSCHIRM VERWENDET WERDEN.
2. [lessWaste](https://github.com/Hrybmo/lessWaste/blob/master/README_ru.md) ist eine Abspaltung von BamBufy

Um das Repository für externe Plugins zu aktivieren, die nicht vom zMod-Autor entwickelt wurden, führen Sie den Befehl `ENABLE_EXTRA_PLUGINS` aus.

---

## Plugin verwalten

**Plugin aktivieren:**
```gcode
ENABLE_PLUGIN name=g28_tenz
```
- wird das Plugin herunterladen und Klipper bei Erfolg neu starten.

**Plugin deaktivieren:**
````gcode
DISABLE_PLUGIN name=g28_tenz
```

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

`ini
[update_manager led_effect].
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
ln -s /opt/config/mod_data/plugins/klipper-led_effect/src/led_effect.py /usr/prog/klipper/klippy/extras/led_effect.py
```

Ersetzen Sie mit:

- `klipper-led_effect` in Ihrem Plugin-Ordner
- `led_effect.py` in den Modulnamen (kann je nach Plugin unterschiedlich sein)

**Schritt 4: Klipper neu laden**

Nachdem Sie den symbolischen Link erstellt haben, müssen Sie Klipper über die Fluidd/Mainsail-Weboberfläche neu laden, indem Sie auf die Schaltfläche reload klicken.

### Wichtige Hinweise

> **Modul muss mit der Klipper-Version kompatibel sein**
> Stellen Sie sicher, dass die Plugin-Version mit der installierten Klipper-Version kompatibel ist.

---

## Erstellen Sie Ihr eigenes Plugin

Plugin-Beispiel: https://github.com/ghzserg/g28_tenz
(Alle Beispiele unten verwenden den Namen `g28_tenz` - ersetzen Sie ihn durch den Namen Ihres Plugins).

---

### Hinzufügen eines Plugins

In der Datei
```mod_data/user.moonraker.conf```.
fügen Sie einen Abschnitt hinzu:

```ini
[update_manager g28_tenz].
Typ: git_repo
Kanal: dev
Pfad: /root/printer_data/config/mod_data/plugins/g28_tenz
Herkunft: https://github.com/ghzserg/g28_tenz.git
is_system_service: Falsch
primary_branch: main
```

- **Pfad zum Plugin**: `/root/printer_data/config/mod_data/plugins/g28_tenz`.
- **Quelle**: `https://github.com/ghzserg/g28_tenz.git`.

> Stabile Plugins können in der zmod-Lieferung enthalten sein, werden aber von ihren Autoren aktualisiert und verwaltet.

---

### Installationsskript

Nach dem Aufruf von `ENABLE_PLUGIN` wird automatisch die Datei `install.sh` aufgerufen.

Nach dem Aufruf von `DISABLE_PLUGIN`, wird automatisch die Datei `uninstall.sh` aufgerufen.

### Einsprachiges Plugin
Muss die Datei enthalten:
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

Alle Zeilen der Ausgabe müssen escaped werden, z.B.:
````gcode
RESPOND PREFIX="info" MSG="===Schneiden des Fadens==="
```

---

#### Übersetzung

Übersetzungen werden im Verzeichnis `translate/` in Dateien der Form `de.csv` gespeichert:

`csv
Schneiden des Fadens;Faden schneiden
```

Format:
```
Englische Phrase;Übersetzung in die gewünschte Sprache
```

Um Sprachdateien zu erzeugen, führen Sie aus:
````bash
./Make.sh
```
Das Skript erstellt die erforderlichen Verzeichnisse und `.cfg`-Dateien.
