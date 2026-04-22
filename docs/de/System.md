<h1 align="center">System</h1>

Ein Makro ist ein kleines Programm in der Sprache Klipper/Gcode.

Es kann aufgerufen werden durch:

- Aus der GCODE-Datei
- Von der Fluidd/Mainsail-Konsole (drücken Sie den englischen Buchstaben `C` in Fluidd)

!!! Hinweis
    *Der Wert in Klammern ist der Standardwert*.

---

### DISPLAY_ON

Schalten Sie die Standardanzeige ein und starten Sie den Drucker neu.

---

#### DISPLAY_OFF

- `GUPPY`: `0` = GuppyScreen deaktivieren, `1` = GuppyScreen aktivieren (Standard: `1`)

- `Helix`: `0` = HelixScreen deaktivieren, `1` = HelixScreen aktivieren (Standard: `0`) + `ENABLE_EXTRA_PLUGINS`

Schaltet den Standardbildschirm aus. Spart 13 Megabyte (20 Megabyte bei älteren Versionen der nativen Firmware).

GuppyScreen ist eine alternative Bildschirm-Implementierung:

- Unterstützt alle Funktionen des nativen Bildschirms mit Ausnahme der WiFi-Einstellungen
- Benötigt 9 MB RAM, verglichen mit 23 MB für den nativen Bildschirm
- Bleibt nicht hängen, wenn der Klipper neu gebootet wird
- Empfohlen für die Verwendung anstelle des nativen Bildschirms.
- Bessere Wiederherstellung von unterbrochenen Druckvorgängen
- Basiert auf [fork](https://github.com/ghzserg/guppyscreen_ff5m), das auf [original repository](https://github.com/ballaswag/guppyscreen) und einem weiteren [fork](https://github.com/consp/guppyscreen/tree/flashforge_ad5m) basiert.

**[HelixScreen](https://github.com/prestonbrown/helixscreen)** ist eine alternative Bildschirm-Implementierung

!!! warning "Warnung:"

	- Deaktivieren Sie den Bildschirm nur, wenn Sie die Bettnivellierung, den Z-Offset und die Makros `START_PRINT`/`END_PRINT` vollständig verstehen.

	- Der Bildschirm bleibt nach einem Neustart 3 Minuten lang aktiv, hat aber keinen Einfluss auf den Z-Offset oder den Druckvorgang.

Die Aktivierungszeit kann über den globalen Parameter [`DISPLAY_OFF_TIMEOUT`](/de/Global/#display_off_timeout) angepasst werden.

Konfigurieren Sie START_PRINT. Legen Sie den gewünschten Z-Offset entweder über diese Funktion oder über die globalen Parameter fest.

[Lesen Sie diesen Hinweis](/de/FAQ/#was-ist-der-unterschied-zwischen-der-arbeit-mit-und-ohne-nativen-bildschirm)

---

### MEM

Speicherverbrauch anzeigen

---

### TEST_EMMC

Schreibt SIZE MB auf die EMMC und gibt die Lese- und Schreibgeschwindigkeit an.

EMMC-Leistung und Verschleiß prüfen.
Parameter:

- `SIZE` – Datengröße in MB (Standard: `100`).

- `SYNC` – `1` = synchroner Modus (Geschwindigkeitsmessung), `0` = asynchrones Schreiben im Hintergrund (Standard: `1`).

- `FLASH` – Zielspeicher: `0` = EMMC, `1` = USB-Flash, `2` = RAM (Standard: `0`).

- `RANDOM` – Zufallsdaten verwenden: `1` = Ja, `0` = Nein (Standard: `0`).

**Befehl für die Standard-Firmware:**

Auf dem Lager:
Datei [zfs.sh](https://github.com/ghzserg/z_ff5m/blob/1.6/.shell/zfs.sh) herunterladen
```bash
chmod +x zfs.sh
./zfs.sh 400 1
```

---

### CLEAR_EMMC

EMMC-Speicher löschen.
Parameter:

- `LOG` – Protokolldateien löschen: `1` = Ja, `0` = Nein (Standard: `1`).

- `ANY` – Alle Dateien löschen (G-Code, Bilder, Videos): `1` = Ja, `0` = Nein (Standard: `0`).

---

### DATE_GET

Anzeige der aktuellen Uhrzeit

---

### DATE_SET

Systemdatum und -zeit einstellen.

- `DT` — Datum/Uhrzeit im Format `YYYY.MM.DD-HH:MM:SS`.

---

### WEB

Wechseln Sie zwischen den Web-Oberflächen von Fluidd und Mainsail.

Nach Ausführung des Makros:

- Drücken Sie Strg + F5 oder Strg + Umschalt + R oder Option + Befehl + E.

- Falls in Orca ein Problem auftritt, drücken Sie Strg + F5 oder Strg + Umschalt + R oder Option + Befehl + E.

Bei Verwendung von Mainsail geben Sie bitte nur die folgenden Miniaturansichtsgrößen an: 140x110/PNG, 64x64/PNG.

In Orca, `Druckerprofil` :arrow_right: `Allgemeine Informationen` :arrow_right: `Erweitert` :arrow_right: `G-Code Thumbnails`.

Beachten Sie, dass der native Bildschirm keine Miniaturbilder mehr anzeigt.

!!! info "Achtung:" 

	Der Autor benutzt Fluidd, Mainsail wird nur von Anwendern getestet. Wenn Sie Probleme mit Mainsail haben, erstellen Sie ein [ticket](/de/Help/)

---

### SET_TIMEZONE

Zeitzone ändern:

Man findet die Zeitzone in dem folgenden Ordner `/usr/data/.mod/.zmod/usr/share/zoneinfo`

```
SET_TIMEZONE ZONE=Asia/Yekaterinburg
```

- ZONE - Zeitzone (Asien/Jekaterinburg)
- ZONE - Zeitzone (Europe/Berlin)

---

### CHECK_MD5

Igor Polunovskiy

Es wird empfohlen, den [globalen Parameter FORCE_MD5](/de/Global/#force_md5) `SAVE_ZMOD_DATA FORCE_MD5=1` zu verwenden.

MD5-Summe prüfen.

- `DELETE` — beschädigte Dateien löschen: `yes`/`no`.

??? info "Download: Wählen Sie die passende Datei für Ihr System"

    1. Sie müssen eine Datei für Ihre Architektur und Ihr Betriebssystem auswählen und auf Ihren Computer herunterladen:
        * [zmod_preprocess-windows-amd64.exe](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-windows-amd64.exe) - **Windows**
        * [zmod_preprocess-linux-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-linux-amd64) - **Linux** Vergessen Sie nicht, `chmod +x                           zmod_preprocess-linux-amd64` auszuführen.
        * [zmod_preprocess-darwin-arm64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-arm64) - **macOS Intel** Vergessen Sie nicht, `chmod +x                  zmod_preprocess-darwin-arm64` auszuführen.
        * [zmod_preprocess-darwin-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-amd64) - **macOS Silicon** Vergessen Sie nicht, `chmod +x                zmod_preprocess-darwin-amd64` auszuführen.
        * [zmod-preprocess.py](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.py) - **Universal Python** Vergessen Sie nicht, `chmod +x zmod-preprocess.py`             auszuführen.
        * [zmod-preprocess.sh](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.sh) - **Linux/MacOS Bash** Vergessen Sie nicht, `chmod +x zmod-preprocess.sh`             auszuführen.
     
??? tip "2. Konfiguration in Orca"
    In Orca müssen Sie den Pfad zum Skript an folgender Stelle angeben:
    `Prozessprofil` :arrow_right: `Andere` :arrow_right: `Nachverarbeitungsskripte`.

    **Hier sind die Optionen, die Sie hinzufügen müssen (je nach System):**

    * **Windows (Executable):**
        ```text
        "C:\path_to_file\zmod_preprocess-windows-amd64.exe";
        ```

    * **Windows (Python Skript):**
        ```text
        "C:\python_ordner\python.exe" "C:\Scripts\zmod-preprocess.py";
        ```

    * **Linux/macOS (Python):**
        ```text
        "/usr/bin/python3" "/home/user/zmod-preprocess.py";
        ```

    * **Linux/macOS (Direkter Pfad):**
        ```text
        "/home/benutzer/zmod-preprocess.py";
        ```

    * **Binärdateien (Linux/macOS):**
        * `/home/benutzer/zmod_preprocess-darwin-amd64`;
        * `/home/benutzer/zmod_preprocess-darwin-arm64`;
        * `/home/benutzer/zmod_preprocess-linux-amd64`;

Die Quelldateien sind hier zu finden: [https://github.com/ghzserg/zmod_preprocess](https://github.com/ghzserg/zmod_preprocess)

```
Stoppt den Druck im Falle einer Prüfsummenabweichung mit möglicher Löschung der fehlerhaften Datei.

Der Autor ist nicht verantwortlich für Fehler oder Probleme oder für die Ergebnisse, die durch die Verwendung dieser Informationen erzielt werden.

Die Prüfsumme wird an den Anfang der G-Code-Datei geschrieben. Wenn die Datei keine Prüfsumme enthält, prüft das Makro die Datei nicht und sie wird sofort an den Drucker geschickt.
Das Ergebnis der Prüfung wird auf der Konsole ausgegeben.

=========================================
1. Auf einem Windows-Rechner, auf dem der Slicer installiert ist.
  a) Laden Sie https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-windows-amd64.exe herunter.
  b) Fügen Sie das Skript aus Punkt 1.a. in den Slicer ein,
     Ersetzen Sie "disk:\patch\to\file\" durch Ihren Pfad zum Skript:
    - Für OrcaSlicer
      "Prozess"->"Andere"->"Nachbearbeitungsskripte".
    - Für SuperSlicer und PrusaSlicer
      "Druckeinstellungen"->"Ausgabeoptionen"->"Nachbearbeitungsskripte".
    disk:\patch\to\file\zmod_preprocess-windows-amd64.exe;
  c) Fügen Sie ein Makro für den Slicer hinzu
    - für OrcaSlicer.
      "Druckerprofil"->"Drucker G-Code"->"Drucker Start G-Code".
    - für SuperSlicer und PrusaSlicer
      "Druckereinstellungen"->"Benutzerdefinierter G-Code"->"G-Code starten".
    * Ohne die Datei zu löschen:
      CHECK_MD5
    * Mit Dateilöschung:
      CHECK_MD5 DELETE=true
  d) Wenn das START_PRINT-Makro verwendet wird, ist es nicht erforderlich, CHECK_MD5 zum Startcode hinzuzufügen. Standardmaessig wird die Pruefung automatisch durchgefuehrt.
```

---

### UPDATE_MCU

Aktualisiert die MCU im Drucker.

Ändert die MCU-Firmware von der nativen Klipper-Version (11 für FF5M/FF5MPRO, 12 für AD5X) auf Klipper 13 und wieder zurück

Klipper 13 (standardmäßig deaktiviert).

Parameter FORCE:

- 11 - Firmware Klipper 11 laden - FF5M
- 12 - Firmware Klipper 12 laden - AD5X
- 13 - Klipper 13-Firmware laden

Ändert die Firmware auf die gegenüberliegende Firmware ohne Parameter.

Beispiel: `UPDATE_MCU FORCE=13` erzwingt das Laden der Klipper 13-Firmware

Wenn du nicht verstehst, wie man [MCU-Konfigurationen und -Firmware wiederherstellt](/de/Native_FW/#installation-der-vollständigen-firmware-auf-dem-ad5x), führe es nicht aus.

Wenn etwas schief geht, gehen Sie nur über [factory](/de/Native_FW/) zurück.

---

### RESET_PASSWD

Passwort des Root-Benutzers auf root zurücksetzen

---

### CHECK_SYSTEM

Diagnose der Systemdateiintegrität.

- `RESTORE` — `0` = keine Reparatur, `1` = beschädigte Dateien reparieren (Standard: `0`).

Prüfverfahren:

- Dateiberechtigungen/MD5-Hashes.

- Verzeichnisberechtigungen.

- Symbolische Links.

**Wiederherstellung:** Laden Sie intakte Dateien von [hier](https://github.com/ghzserg/FF/tree/main/stock) herunter.

---

### BILDSCHIRM

Erstellen Sie einen Screenshot des Druckers.

Das Foto wird unter ```mod_data/screen.jpg``` gespeichert.
