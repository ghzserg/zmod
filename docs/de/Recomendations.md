## Empfehlungen
## Empfehlungen zur Verbesserung der Druckerstabilität

Die Empfehlungen gelten sowohl für native als auch für ZMOD-Firmware.

---

### Aktivieren Sie den Modellausschluss

Aktivieren Sie den Modellausschluss in Orca:

- `Prozessprofil` -> `Andere` -> `Output G-cod` -> `Modellausschluss`, um das Kontrollkästchen zu aktivieren
- Prozessprofil" -> "Sonstige" -> "Output G-cod" -> "Modelle ausschließen", um das Kontrollkästchen zu aktivieren

<img width="285" height="171" alt="image" src="https://github.com/user-attachments/assets/faceef98-2791-4975-bf72-425f4a2b1dfa" />

---

### Installieren Sie die neueste native Firmware und das ZMOD-Update

Nur die neueste Version des Mods wird unterstützt.

Der Autor hat nicht die Ressourcen, um alle Versionen zu unterstützen, also [installiere die neueste native Firmware und das ZMOD-Update](/de/Setup/).

### Ersetzen Sie Spiral/Automatic Z-Hop.

Der Drucker unterstützt dies nicht.

In Orca. Druckerprofil" -> "Extruder 1" -> "Z-Achsen-Hubtyp". Stellen Sie "Ordinär" oder "Kippen" ein.

---

### Deaktivieren Sie "Bogen_Bewegung" (arc_move).

Der Drucker unterstützt sie, aber sie verringern die Druckqualität und verursachen gelegentlich Druckfehler.

In Orca. `Prozessprofil` -> `Qualität` -> `Präzision` -> `"Arc_move approximation"` das Häkchen entfernen.

---

### Deaktivieren Sie die eingebaute Kamera auf dem Druckerbildschirm.

Sie verbraucht mehr Speicher und die Bildqualität ist schlecht.

Verwenden Sie eine andere Kamera.

Auf dem Bildschirm des Druckers. Einstellungen" -> Registerkarte "Kamera" -> Deaktivieren Sie "Kamera" und "Video".

Führen Sie dann das Makro [CAMERA_ON](/de/Zmod/#camera_on)

- Was ist eine alternative Kamera?](/de/FAQ/#Was-ist-eine-alternative-Kamera)
- Ich habe einen Drucker installiert und ZMOD hat meine Kamera versteckt! Ich habe sie in Orca-FF gesehen, und jetzt ist sie weg](/de/FAQ/#Ich habe einen Drucker installiert und ZMOD hat meine Kamera in Orca-FF versteckt - ich habe sie gesehen und jetzt ist sie weg).

---

### Chinesische Wolken deaktivieren.

### Lan-Modus-Fehler

Trennen Sie die Verbindung zu den chinesischen Clouds, da diese instabil sind und regelmäßig abreißen.
Sobald die Verbindung wiederhergestellt ist, verstopfen sie den Drucker mit rückständigen Anfragen und verursachen Fehler.

Wenn chinesische Clouds ausgeführt werden, funktioniert das Drucken vom nativen Bildschirm mit Desktop-Entfernung und Schnellschließen von Fenstern nicht.

Auf dem Druckerbildschirm.

Einstellungen" -> Registerkarte "WiFi" -> "Netzwerkmodus" -> "Nur lokale Netzwerke" aktivieren.

Wenn Sie "Chinesische Wolken" deaktivieren, können Sie das "Ok"-Fenster nach dem Drucken schnell schließen und mit dem Algorithmus des ursprünglichen Bildschirms drucken, ohne dass die Tabelle angezeigt wird.

Einstellungen" -> Registerkarte "Wolke" -> Deaktivieren Sie "FlashCloud" und "Polar3d".

Sie können stattdessen verwenden:

- [zmod.link](/de/Zmod/#zlink) - Cloud, für die Verwaltung von Druckern über Fluidd/Mainsail.
- [Telegram bot](/de/Macros/).

[Mehr über chinesische Wolken](/de/Global/#china_cloud).

---

### Aktivieren Sie die [MD5]-Kontrolle.

Igor Polunovskiy

[CHECK_MD5](/de/System/#check_md5)

Es wird empfohlen, den [globalen Parameter FORCE_MD5](/de/Global/#force_md5) `SAVE_ZMOD_DATA FORCE_MD5=1` zu verwenden.

1. Sie müssen eine Datei für Ihre Architektur und Ihr Betriebssystem finden und auf Ihren Computer herunterladen:

- [zmod_preprocess-windows-amd64.exe](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-windows-amd64.exe) - Windows
- [zmod_preprocess-linux-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-linux-amd64) - Linux. Vergessen Sie nicht, ```chmod +x zmod_preprocess-linux-amd64`'' auszuführen.
- [zmod_preprocess-darwin-arm64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-arm64) - macOS Intel. Vergessen Sie nicht, ```chmod +x zmod_preprocess-darwin-arm64``` auszuführen
- [zmod_preprocess-darwin-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-amd64) - macOS Silicon. Vergessen Sie nicht, ```chmod +x zmod_preprocess-darwin-amd64``` auszuführen
- [zmod-preprocess.py](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.py) - Universal Python. Vergessen Sie nicht, ```chmod +x zmod-preprocess.py``` auszuführen.
- [zmod-preprocess.sh](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.sh) - Linux/MacOS Bash. Vergessen Sie nicht, ```chmod +x zmod-preprocess.sh``` auszuführen.

2. In Orca muessen Sie schreiben. ```Prozessprofil``` -> ```Andere``` -> ```Nachverarbeitungsskripte```.

Wenn der Pfad Leerzeichen enthält, sollten Sie den vollständigen Pfad in Anführungszeichen setzen, aber es ist besser, keine Leerzeichen in Ordnern zu verwenden.

Hier sind die Varianten des Hinzufügens:

- ````"C:C:\pfad_zur_datei\zmod_preprocess-windows-amd64.exe";````
- "C:\python_ordner\python.exe" "C:\Scripts\zmod-preprocess.py";```
- ````"/usr/bin/python3" "/home/user/zmod-preprocess.py";````
- ````"/home/benutzer/zmod-preprocess.py";````
- ````"/home/benutzer/zmod_preprocess-darwin-amd64";````
- ````"/home/benutzer/zmod_preprocess-darwin-arm64";````
- ````"/home/benutzer/zmod_preprocess-linux-amd64";````

<img width="476" height="355" alt="image" src="https://github.com/user-attachments/assets/0b59a617-5613-4def-aa01-7fe038898863" />

[Mehr lesen](/de/System/#check_md5)

*hamster

---

### Senden Sie Dateien zum Drucken über "Octo/Klipper".

Das native FF-Protokoll sendet gelegentlich defekte Dateien und erzeugt auch keine Bilder und Metadaten für den Telegram-Bot.

In Orca. Klicken Sie auf das Wifi-Symbol neben dem Drucker:

- Protokoll: `Octo/Klipper`.
- Host-Name: "IP_drucker_name:7125".
- Url-Adresse des Hosts: "IP_drucker" oder "IP_drucker:80".

Wenn Mainsail verwendet wird, dann geben Sie nur diese Miniaturgrößen an: ```140x110/PNG, 64x64/PNG```.

In Orca, ```Druckerprofil``` -> ```Allgemeine Informationen``` -> ```Erweitert``` -> ```G-Code Thumbnails```.

Beachten Sie, dass der native Bildschirm keine Miniaturbilder mehr anzeigt.

---

### Fehlerbehebung E0017 einschalten

[E0017](/de/Global/#fix_e0017)

Es ist bereits standardmäßig aktiviert

---

### Fehlerbehebung E0011 einschalten

Sollte `E0011` und `Communication timeout during homing` beheben.

[E0011](/de/Global/#fix_e0011)

---

### Überprüfen Sie die Korrektheit der nativen Betriebssystemdateien

Da der Drucker in der Firmware nicht korrekt heruntergefahren wurde, kann das Dateisystem beschädigt sein.

Dies führt zu einer Reihe von kleineren oder größeren Fehlern.

Das Makro [CHECK_SYSTEM](/de/System/#check_system) prüft die MD5-Summe der Dateien und zeigt an, welche Dateien beschädigt wurden.

Es prüft auch, ob die symbolischen Links korrekt sind und korrigiert sie automatisch, falls nötig.

---

### Aktivieren Sie die Düsenaufprallkontrolle auf dem Tisch.

Die Steuerung ist standardmäßig deaktiviert.

Aktiviert durch das Makro [NOZZLE_CONTROL](/de/Global/#nozzle_control)

NOZZLE_CONTROL WEIGHT=0`

Die Steuerung schaltet den Klipper ab, wenn die Düse beginnt, die Platte zu zerkratzen oder das Teil vom Tisch fällt.

Es ist besonders empfehlenswert, die Steuerung für diejenigen einzuschalten, die die Düsenvorreinigung verwenden.
