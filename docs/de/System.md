<h1 align="center">System</h1>

Ein Makro ist ein kleines Programm in der Sprache Klipper/Gcode.

Es kann aufgerufen werden durch:

- Aus der GCODE-Datei
- Von der Fluidd/Mainsail-Konsole (drücken Sie den englischen Buchstaben "C" in Fluidd)

!!! Hinweis
    *Der Wert in Klammern ist der Standardwert.

---

### DISPLAY_ON

Schalten Sie die Standardanzeige ein und starten Sie den Drucker neu.

---

#### DISPLAY_OFF

- GUPPY: 0 - GuppyScreen nicht aktivieren, 1 - GuppyScreen aktivieren (1)

Schaltet den Standardbildschirm aus. Spart 13 Megabyte (20 Megabyte bei älteren Versionen der nativen Firmware).

GuppyScreen ist eine alternative Bildschirm-Implementierung:

- Unterstützt alle Funktionen des nativen Bildschirms mit Ausnahme der WiFi-Einstellungen
- Benötigt 9 MB RAM, verglichen mit 23 MB für den nativen Bildschirm
- Bleibt nicht hängen, wenn der Clipper neu gebootet wird
- Empfohlen für die Verwendung anstelle des nativen Bildschirms.
- Bessere Wiederherstellung von unterbrochenen Druckvorgängen
- Basiert auf [fork](https://github.com/ghzserg/guppyscreen_ff5m), das auf [original repository](https://github.com/ballaswag/guppyscreen) und einem weiteren [fork](https://github.com/consp/guppyscreen/tree/flashforge_ad5m) basiert.

**Deaktivieren Sie den Bildschirm nur, wenn Sie genau verstehen, wie die Tabellenabbildung, der z-Offset und die Makros START_PRINT und END_PRINT funktionieren**

**Dieses Makro muss nicht in den g-code aufgenommen werden.**
Nach dem Neustart funktioniert der Bildschirm noch 3 Minuten lang, aber das hat keinen Einfluss auf den z-Offset, da er nicht durch ihn hindurch druckt.

Um die Aktivierungszeit des alternativen Bildschirms zu ändern [globale Parameter verwenden](/de/Global/#display_off_timeout)

Setzen Sie START_PRINT. Stellen Sie den gewünschten z-Offset über diesen Parameter oder über globale Parameter ein.

[Lesen Sie diesen Hinweis](/de/FAQ/#Was ist der Unterschied zwischen der Arbeit mit einem Bildschirm und ohne einen nativen Bildschirm)

---

### MEM

Speicherverbrauch anzeigen

---

### TEST_EMMC

Schreibt SIZE MB auf die EMMC und gibt die Lese- und Schreibgeschwindigkeit an.

Gibt den prozentualen Verschleiß der EMMC aus

- SIZE - wie viele Megabytes geschrieben werden (100)
- SYNC - 1 - synchroner Betrieb. SIZE Megabytes an Daten werden geschrieben und gelesen und die Geschwindigkeit wird ausgegeben, 0 - asynchroner Modus, SIZE Megabytes an Daten werden im Hintergrund geschrieben - dient als Hintergrundlast für die EMMC-Speicherkarte. (1)
- FLASH - schreiben: 0 - auf EMMC, 1 - auf USB FLASH, 2 - auf RAM (0)
- RANDOM - verwendet Zufallszahlen zum Schreiben. 1 - ja, 0 - nein (0)

Auf dem Lager:
Datei [zfs.sh](https://github.com/ghzserg/z_ff5m/blob/1.6/.shell/zfs.sh) herunterladen
```
chmod +x zfs.sh
./zfs.sh 400 1
```

---

### CLEAR_EMMC

Löscht die EMMC.

- LOG - löscht Logdateien, 1 - ja, 0 - nein (1)
- ANY - löscht alles (gcode, Bilder, Fotos, Videos) außer Logdateien, 1 - ja, 0 - nein (0).

---

### DATE_GET

Anzeige der aktuellen Uhrzeit

---

### DATE_SET

Einstellen von Datum und Uhrzeit im Format 2024.01.01.01-00:00:00:00

- DT - Datum 2024.01.01.01-00:00:00:00

---

### WEB

Web-Interface fluidd/mainsail ändern

Nach der Ausführung des Makros:

- Sie müssen "Strg + F5" oder "Strg + Umschalt + R" oder "Wahl + Befehl + E" drücken.
- Wenn Sie ein Problem in Orca haben, müssen Sie `Strg + F5` oder `Strg + Umschalt + R` oder `Option + Befehl + E` drücken.

Wenn Sie Mainsail verwenden, geben Sie nur diese Miniaturgrößen an: "140x110/PNG, 64x64/PNG".

In Orca, ```Druckerprofil``` -> ```Allgemeine Informationen``` -> ```Erweitert``` -> ```G-Code Thumbnails```.

Beachten Sie, dass der native Bildschirm keine Miniaturbilder mehr anzeigt.

Achtung: Der Autor benutzt Fluidd, Mainsail wird nur von Anwendern getestet. Wenn Sie Probleme mit Mainsail haben, erstellen Sie ein [ticket](/de/Help/)

---

### SET_TIMEZONE

Zeitzone ändern

- ZONE - Zeitzone (Asien/Jekaterinburg)

---

### CHECK_MD5

Igor Polunovskiy

Es wird empfohlen, den [globalen Parameter FORCE_MD5](/de/Global/#force_md5) `SAVE_ZMOD_DATA FORCE_MD5=1` zu verwenden.

MD5-Summe prüfen.

- DELETE - defekte Datei löschen (ja)

1. Sie müssen eine Datei für Ihre Architektur und Ihr Betriebssystem auswählen und auf Ihren Computer herunterladen:

- [zmod_preprocess-windows-amd64.exe](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-windows-amd64.exe) - Windows
- [zmod_preprocess-linux-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-linux-amd64) - Linux. Vergessen Sie nicht, ```chmod +x zmod_preprocess-linux-amd64`'' auszuführen.
- [zmod_preprocess-darwin-arm64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-arm64) - macOS Intel. Vergessen Sie nicht, ```chmod +x zmod_preprocess-darwin-arm64``` auszuführen
- [zmod_preprocess-darwin-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-amd64) - macOS Silicon. Vergessen Sie nicht, ```chmod +x zmod_preprocess-darwin-amd64``` auszuführen
- [zmod-preprocess.py](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.py) - Universal Python. Vergessen Sie nicht, ```chmod +x zmod-preprocess.py``` auszuführen.
- [zmod-preprocess.sh](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.sh) - Linux/MacOS Bash. Vergessen Sie nicht, ```chmod +x zmod-preprocess.sh``` auszuführen.

2. In Orca muessen Sie schreiben. ```Prozessprofil``` -> ```Andere``` -> ```Nachverarbeitungsskripte```.

Hier sind die Optionen, die Sie hinzufügen müssen:

- ```"C:\path_to_file\zmod_preprocess-windows-amd64.exe";```
- ```"C:\python_ordner\python.exe" "C:\Scripts\zmod-preprocess.py";```
- ````"/usr/bin/python3" "/home/user/zmod-preprocess.py";````
- ````"/home/benutzer/zmod-preprocess.py";````
- ````"/home/benutzer/zmod_preprocess-darwin-amd64";````
- ````"/home/benutzer/zmod_preprocess-darwin-arm64";````
- ````"/home/benutzer/zmod_preprocess-linux-amd64";````

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

Wenn du nicht verstehst, wie man [MCU-Konfigurationen und -Firmware wiederherstellt](/de/Native_FW/#installing-full-firmware-on-ad5x), führe es nicht aus.

Wenn etwas schief geht, gehen Sie nur über [factory](/de/Native_FW/) zurück.

---

### RESET_PASSWD

Passwort des Root-Benutzers auf root zurücksetzen

---

### CHECK_SYSTEM

Überprüfen Sie das Betriebssystem des Druckers auf beschädigte Dateien.

- RESTORE: 0 - beschädigte Dateien nicht reparieren, 1 - beschädigte Dateien reparieren (0)

Überprüft:

- Dateien (md5, Berechtigungen)
- Kataloge (Zugriffsrechte)
- Symbolische Links (Korrektheit der Angabe)

Symbolische Links, Rechte auf Verzeichnisse und Dateien werden automatisch wiederhergestellt.

Die Überprüfungszeit beträgt etwa 10 Minuten.

Wenn Fehler gefunden werden - gehen Sie zu [link](https://github.com/ghzserg/zmod/tree/main/stock), dort können Sie eine unbeschädigte Kopie der Datei herunterladen.

---

### BILDSCHIRM

Einen Screenshot des Druckerbildschirms erstellen

Der Screenshot wird unter ```mod_data/screen.jpg``` gespeichert.
