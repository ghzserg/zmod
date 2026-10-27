<h1 align="center">System</h1>

Ein Makro ist ein kleines Programm in der Sprache Klipper/Gcode.

Es kann aufgerufen werden:

- aus der G-Code-Datei
- über die Fluidd/Mainsail-Konsole (drücken Sie in Fluidd die lateinische Taste „C“)

!!! info "Hinweis"
    *Der Wert in Klammern ist der Standardwert*.

---

### DISPLAY_ON

Schaltet den Standardbildschirm ein und startet den Drucker neu.

---

### DISPLAY_OFF

Schaltet den Standardbildschirm aus und startet den Drucker neu. Spart 13 MB RAM (20 MB bei älteren Versionen der nativen Firmware).

Verwenden Sie die Schaltfläche mit Parameterauswahl in der Liste „Makros“ oder einen Konsolenbefehl:

- `DISPLAY_OFF GUPPY=1 HELIX=0` — aktiviert GuppyScreen.
- `DISPLAY_OFF GUPPY=0 HELIX=1` — aktiviert [HelixScreen](https://github.com/prestonbrown/helixscreen) + `PLUGINS`.

GuppyScreen ist eine alternative Bildschirm-Implementierung:

- Unterstützt alle Funktionen des nativen Bildschirms mit Ausnahme der WLAN-Einstellungen
- Benötigt 9 MB RAM, verglichen mit 23 MB für den nativen Bildschirm
- Bleibt nicht hängen, wenn Klipper neu gestartet wird
- Bietet zusätzliche Funktionen, z. B. eine Liste aller Makros einschließlich Ihrer eigenen
- Empfohlen als Ersatz für den nativen Bildschirm
- Bessere Wiederherstellung von unterbrochenen Druckvorgängen
- Basiert auf einem [Fork](https://github.com/ghzserg/guppyscreen_ff5m), der auf dem [Original-Repository](https://github.com/ballaswag/guppyscreen) und einem weiteren [Fork](https://github.com/consp/guppyscreen/tree/flashforge_ad5m) basiert.

**[HelixScreen](https://github.com/prestonbrown/helixscreen)** ist eine weitere alternative Bildschirm-Implementierung.

!!! warning "Warnung:"

	- Deaktivieren Sie den Bildschirm nur, wenn Sie die Bettnivellierung, den Z-Offset und die Makros `START_PRINT`/`END_PRINT` vollständig verstehen.

	- Fügen Sie dieses Makro nicht in den Start-G-Code ein.
	- Nach einem Neustart läuft der native Bildschirm noch 10 Sekunden weiter, hat aber keinen Einfluss auf den Z-Offset, da der Druck nicht über ihn läuft.

Die Aktivierungszeit kann über den globalen Parameter [`DISPLAY_OFF_TIMEOUT`](/de/Global/#display_off_timeout) angepasst werden.

Konfigurieren Sie `START_PRINT` und legen Sie den gewünschten Z-Offset über dessen Parameter oder über die globalen Parameter fest.

[Lesen Sie diesen Hinweis](/de/FAQ/#was-ist-der-unterschied-zwischen-der-arbeit-mit-und-ohne-nativen-bildschirm)

---

### MEM

Zeigt den Speicherverbrauch an.

---

### TEST_EMMC

Schreibt SIZE MB auf die EMMC und gibt die Lese- und Schreibgeschwindigkeit aus.

EMMC-Leistung und Verschleiß prüfen.
Parameter:

- `SIZE` – Datengröße in MB (Standard: `100`).

- `SYNC` – `1` = synchroner Modus (Geschwindigkeitsmessung), `0` = asynchrones Schreiben im Hintergrund (Standard: `1`).

- `FLASH` – Zielspeicher: `0` = EMMC, `1` = USB-Flash, `2` = RAM (Standard: `0`).

- `RANDOM` – Zufallsdaten verwenden: `1` = Ja, `0` = Nein (Standard: `0`).

**Auf der Standard-Firmware:**

Laden Sie die Datei [zfs.sh](https://github.com/ghzserg/z_ff5m/blob/1.7/.shell/zfs.sh) herunterladen
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

Aktuelle Uhrzeit anzeigen

---

### DATE_SET

Systemdatum und -zeit einstellen.

- `DT` — Datum/Uhrzeit im Format `YYYY.MM.DD-HH:MM:SS`.

---

### WEB

Wechselt zwischen den Weboberflächen Fluidd und Mainsail.

Nach Ausführung des Makros:

- Drücken Sie im Browser Strg + F5, Strg + Umschalt + R oder Option + Befehl + E.

- Wenn das Problem in Orca weiterhin besteht, drücken Sie dort erneut Strg + F5, Strg + Umschalt + R oder Option + Befehl + E.

Bei Verwendung von Mainsail geben Sie nur die folgenden Miniaturgrößen an: 140x110/PNG, 64x64/PNG.

In Orca: `Druckerprofil` :arrow_right: `Allgemeine Informationen` :arrow_right: `Erweitert` :arrow_right: `G-Code Thumbnails`.

Beachten Sie, dass der native Bildschirm dann keine Miniaturbilder mehr anzeigt.

!!! info "Achtung:" 

	Der Autor benutzt Fluidd, Mainsail wird nur von Anwendern getestet. Wenn Sie Probleme mit Mainsail haben, erstellen Sie ein [Ticket](/de/Help/)

---

### SET_TIMEZONE

Zeitzone ändern:

Die Zeitzonen finden Sie im Ordner `/usr/data/.mod/.zmod/usr/share/zoneinfo`

```
SET_TIMEZONE ZONE=Asia/Yekaterinburg
```

- ZONE - Zeitzone (Standard: `Asia/Yekaterinburg`)

Beispiel: `SET_TIMEZONE ZONE=Europe/Berlin`. Ohne Parameter zeigt `SET_TIMEZONE` die Liste der verfügbaren Zonen an.

Die Zeitzone ermöglicht es [GuppyScreen](/de/System/#display_off), das Ende des Drucks zu berechnen.

---

### CHECK_MD5

Igor Polunovskiy

> Hinweis: Nur beim Senden von G-Code. Für 3MF nicht erforderlich.

Es wird empfohlen, den [globalen Parameter FORCE_MD5](/de/Global/#force_md5) `SAVE_ZMOD_DATA FORCE_MD5=1` zu verwenden.

MD5-Summe prüfen.

- `DELETE` — beschädigte Dateien löschen: `yes`/`no` (Standard: `yes`).

??? info "Download: Wählen Sie die passende Datei für Ihr System"

    1. Sie müssen eine Datei für Ihre Architektur und Ihr Betriebssystem auswählen und auf Ihren Computer herunterladen:
        * [zmod_preprocess-windows-amd64.exe](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-windows-amd64.exe) - **Windows**
        * [zmod_preprocess-linux-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-linux-amd64) - **Linux** Vergessen Sie nicht, `chmod +x zmod_preprocess-linux-amd64` auszuführen.
        * [zmod_preprocess-darwin-arm64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-arm64) - **macOS Apple Silicon** Vergessen Sie nicht, `chmod +x zmod_preprocess-darwin-arm64` auszuführen.
        * [zmod_preprocess-darwin-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-amd64) - **macOS Intel** Vergessen Sie nicht, `chmod +x zmod_preprocess-darwin-amd64` auszuführen.
        * [zmod-preprocess.py](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.py) - **Universal Python** Vergessen Sie nicht, `chmod +x zmod-preprocess.py` auszuführen.
        * [zmod-preprocess.sh](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.sh) - **Linux/macOS Bash** Vergessen Sie nicht, `chmod +x zmod-preprocess.sh` auszuführen.
     
??? tip "2. Konfiguration in Orca"
    In Orca müssen Sie den Pfad zum Skript an folgender Stelle angeben:
    `Prozessprofil` :arrow_right: `Sonstiges` :arrow_right: `Nachbearbeitungsskripte`.

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

Wechselt die MCU-Firmware von der nativen Klipper-Version (11 für FF5M/FF5MPRO, 12 für AD5X) auf Klipper 13 und zurück.

Klipper 13 ist standardmäßig deaktiviert.

Parameter FORCE:

- 11 - Firmware für Klipper 11 laden - FF5M
- 12 - Firmware für Klipper 12 laden - AD5X
- 13 - Firmware für Klipper 13 laden

Ohne Parameter wird auf die jeweils andere Firmware gewechselt.

Beispiel: `UPDATE_MCU FORCE=13` erzwingt das Laden der Firmware für Klipper 13

Wenn Sie nicht wissen, wie Sie [den nativen Klipper per USB-Stick wiederherstellen](/de/Native_FW/#fix_klipper), führen Sie es nicht aus.
Sehen Sie sich vor dem Klipper-Update die [Änderungen in den neuen Versionen](https://www.klipper3d.org/Releases.html) an; die Standardkonfigurationsdateien müssen nicht angepasst werden.

Wenn etwas schiefgeht, führt der einzige Weg zurück über die [Factory-Firmware](/de/Native_FW/).

Nach dem Ausführen des Makros:

1. Warten Sie auf die Melodie (sie wird auch dann abgespielt, wenn der Ton auf dem nativen Bildschirm stummgeschaltet wurde)
2. Schalten Sie den Drucker aus
3. **Warten Sie 10 Sekunden**
4. Schalten Sie den Drucker wieder ein

---

### RESET_PASSWD

Setzt das SSH-Passwort des Benutzers `root` auf `root` zurück.

---

### CHECK_SYSTEM

Diagnose der Systemdateiintegrität.

- `RESTORE` — `0` = keine Reparatur, `1` = beschädigte Dateien reparieren (Standard: `0`).

Geprüft werden:

- Dateiberechtigungen/MD5-Hashes.

- Verzeichnisberechtigungen.

- Symbolische Links.

Symbolische Links sowie Datei- und Verzeichnisrechte werden automatisch wiederhergestellt.

Die Prüfung dauert etwa 10 Minuten.

**Wiederherstellung:** Laden Sie intakte Dateien [hier](https://github.com/ghzserg/FF/tree/main/stock) herunter.

Wenn die Konsole nicht verfügbar ist, verbinden Sie sich über SSH mit dem Drucker:

`/usr/data/zmod/zmod/.shell/zcheckmd5.sh`

---

### SCREEN

Erstellen Sie einen Screenshot des Druckerbildschirms.

Der Screenshot wird unter ```mod_data/screen.jpg``` gespeichert.
