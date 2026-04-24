<h1 align="center">Zmod</h1>

Ein Makro ist ein kleines Programm in der Sprache Klipper/Gcode.

Es kann aufgerufen werden durch:

- Aus der GCODE-Datei
- Von der Fluidd/Mainsail-Konsole (drücken Sie den englischen Buchstaben "C" in Fluidd)

!!! info "Hinweis"
	*Der Wert in Klammern ist der Standardwert.*

---

### CAMERA_ON

Eine alternative Implementierung der Kamera verwenden

- `BREITE` – Bildbreite (Standard: `640`)
- `HÖHE` – Bildhöhe (Standard: `480`)
- `FPS` – Bilder pro Sekunde (Standard: `20`)
- `VIDEO` – Videogerät (Standard: `video0`)
- `FS` – `1` = Bildgrößenbegrenzer für instabile Kameras aktivieren, `0` = deaktivieren (Standard: `0`)
- `STREAMER` – Zu verwendender Streamer (auto, mjpg_streamer, ustreamer)
- `FORMAT` – Bildformat für ustreamer: YUYV, YVYU, UYVY, RGB565, RGB24, BGR24, MJPEG, JPEG; Standard: MJPEG

*Deaktivieren Sie die Kamera auf dem Druckerbildschirm und rufen Sie erst dann das Makro auf.*

Um die Kamera einzuschalten, verwenden Sie ```CAMERA_ON VIDEO=video0``` oder ```CAMERA_ON VIDEO=video3``` oder ```CAMERA_ON VIDEO=video99```.

<img width="734" height="221" alt="{D2A001DD-7C89-4AB9-9CB9-741B7007B0B4}" src="https://github.com/user-attachments/assets/e8ddbbd3-ebbf-4b4e-86cc-2a62365a4a88" />

Falls die Kamera nicht funktioniert, schauen Sie in den Protokolldateien unter `mod_data/log/cam` nach.

RAM-Verbrauch der Standard-Kamera:

- 640x480 - 2.9 MiB
- 1280x720 - 7.8 MiB
- 1920x1080 - 18.1 MiB

*Viele Kameras von Ali/Ozon/Wildberries verbrauchen immer 18 MiB.

!!! info "Hinweis"

	- [Was ist eine alternative Kamera?](/de/FAQ/#was-ist-eine-alternative-kamera)

		- [Ich habe den Drucker installiert, und Z-Mod hat meine Kamera ausgeblendet! Ich konnte sie in Orca-FF sehen, und jetzt ist sie weg!](/de/FAQ/#ich-habe-einen-drucker-installiert-und-z-mod-hat-meine-kamera-versteckt-ich-konnte-sie-in-orca-ff-sehen-aber-jetzt-ist-sie-weg)

`Camera Off Waiting...` - diese Meldung wird angezeigt, wenn der Kamerastream noch nicht verfügbar ist. Die Kamera startet nach dem Start von Klipper - während die Informationen über globale Parameter angezeigt werden

#### Kamera-Einstellung

**Hauptparameter**

| Parameter | Was bedeutet | Normaler Wert |
|----------|------------|------------------|
| WIDTH | Bildbreite | 640 |
| `HEIGHT` | Bildhöhe | 480 |
| `FPS` | Wie viele Bilder pro Sekunde | 20 |
| `VIDEO` | Kameranummer | video0 |
| `FS` | Problemkameras reparieren (1 für ja, 0 für nein) | 0 |
| `STREAMER` | Kameraprogramm | auto |
| `FORMAT` | Bildformat (nur ustreamer) | MJPEG | MJPEG |

**Was ist ein Streamer?**

Ein Streamer ist ein Programm, das ein Bild von einer Kamera aufnimmt und es in einem Browser anzeigt.

**Es sind zwei Optionen verfügbar:**

- **mjpg_streamer** - einfaches Programm, funktioniert nur mit MJPG-Kameras.
- **ustreamer** - leistungsfähiger, benötigt aber mehr Speicher, unterstützt verschiedene Kameras.

Der Parameter `STREAMER=auto` wählt den geeigneten Streamer aus.

**Bildformate (nur für ustreamer)**

Sie können wählen: YUYV, YVYU, UYVY, RGB565, RGB24, BGR24, MJPEG, JPEG.

Standardmäßig wird MJPEG verwendet.

**Befehlsbeispiele**

Einfaches Starten der Kamera video0 über mjpg_streamer:
```
CAMERA_ON VIDEO=video0
```

Starten der Kamera video0 über ustreamer mit Einstellungen:
```
CAMERA_ON VIDEO=video0 STREAMER=ustreamer FORMAT=YUYV WIDTH=640 HEIGHT=480
```

**Wo kann man das Bild sehen?**

In einem Browser öffnen: `http://printer_ip_address:8080`.

Dort können Sie Helligkeit, Kontrast und andere Einstellungen ändern.

**Wenn es Probleme gibt?**

Sie können die Kamera nicht sehen?
Starten Sie:
```
CAMERA_ON VIDEO=video99
```
Das Programm zeigt eine Liste der verfügbaren Kameras an.

**Logs (Fehlerprotokolle)** befinden sich im Ordner: `log/cam/`.

---

### CAMERA_OFF

Alternative Kamera-Implementierung deaktivieren

---

### CAMERA_RESTART

Neustart der alternativen Kamera-Implementierung

---

### REMOVE_ZMOD

Z-Mod entfernen.

- `FULL`: `0` - Ordner `/opt/config/mod_data` belassen, `1` - Ordner `/opt/config/mod_data` löschen (Standard: `0`)

Der Ordner `/opt/config/mod_data` enthält Einstellungen für `zmod`, `fluidd`, `moonraker`, `mainsail`.

!!! warning "Warnung"
	
	Achtung! Deaktivieren Sie alle Plugins und wechseln Sie zum nativen Klipper.

!!! info "Hinweis"
	
	Er wird nicht standardmäßig gelöscht, da Leute oft versehentlich das Makro `REMOVE_ZMOD` aufrufen

---

### SKIP_ZMOD

Neustart zum ursprünglichen System. Ohne Z-Mod auszuführen.

Z-Mod, Moonraker, Fluidd Konfigurationsdateien sind deaktiviert.

Funktioniert weiterhin:

- Alternative Kamera
- SSH

!!! warning "Warnung"
	
	Achtung! Deaktivieren Sie alle Plugins und wechseln Sie zum nativen Klipper.

---

### TAR_CONFIG

Speichert Konfigurationsdateien in einem Archiv.

Laden Sie das Archiv herunter unter **`Maschine` :arrow_right: mod_data :arrow_right: config.tar.gz**

---

### RESTORE_TAR_CONFIG

Stellt Konfigurationsdateien aus dem Archiv `config.tar.gz` wieder her

Laden Sie das Archiv herunter unter **`Maschine` :arrow_right: mod_data :arrow_right: config.tar.gz**

---

### ZFLASH

Firmware-Aktualisierung über das Netzwerk mithilfe eines USB-Sticks.

1. Stecken Sie den USB-Stick in den Drucker und schalten Sie ihn ein.

2. Wenn Sie den Drucker ohne integriertes Display verwenden, stellen Sie sicher, dass der USB-Stick **vor** dem Einschalten eingesteckt ist.

3. Dieses Makro sucht nach der neuesten Firmware-Version, lädt sie auf den USB-Stick herunter, überprüft den MD5-Hash und installiert sie nach dem Neustart.

---

### STOP_ZMOD

Entlade Guppy, Helix, Moonraker und Fluidd/Mainsail aus dem Speicher. Der Telegramm-Bot wird ebenfalls aufhören zu funktionieren.

Parameter:

- SCREEN (0 - nicht entladen, 1 - entladen)
- MOONRAKER (0 - nicht hochladen, 1 - hochladen)
- HTTP (0 - nicht hochladen, 1 - hochladen)

Beispiel:
```
STOP_ZMOD SCREEN=1 MOONRAKER=0 HTTP=0
```

Wenn diese Zeile in den Startcode geschrieben wird, wird GUPPY/HELIX nach dem Druckstart aus dem Speicher entladen

---

### START_ZMOD

Guppy, Helix, Moonraker und Fluidd/Mainsail nach STOP_ZMOD wieder einschalten.

Parameter:

- SCREEN (0 - nicht laden, 1 - entladen)
- MOONRAKER (0 - nicht laden, 1 - entladen)
- HTTP (0 - nicht laden, 1 - entladen)

Beispiel:
```
START_ZMOD SCREEN=1 MOONRAKER=0 HTTP=0
```

Wenn diese Zeile im endgültigen Code enthalten ist, wird GUPPY/HELIX gestartet, nachdem der Druckvorgang beendet ist

---

### ZSSH_ON

SSH-Tunneling aktivieren.
Parameter:

- `SSH_SERVER` – IP-Adresse/Hostname des entfernten SSH-Servers
- `SSH_PORT` – SSH-Port (Standard: `22`)
- `SSH_USER` – Benutzername des entfernten Servers
- `VIDEO_PORT` – Port des entfernten Servers für Videostreaming (Standard: `8080`)
- `MOON_PORT` – Port des entfernten Servers für Moonraker (Standard: `7125`)
- `REMOTE_RUN` – Befehl, der auf dem entfernten Server ausgeführt werden soll (Standard: `"NONE"`).

Beispiel: Verwenden Sie `./ff5m.sh bot1` (im Verzeichnis `mod/telegram/`), um den Telegram-Bot neu zu starten.

**Setup-Skript (falls nicht über OneCommand installiert):**
```bash
su - tbot # Ändern Sie den Benutzer in den Benutzer, unter dem der Bot-Dienst ausgeführt wird.
wget --cache=off -q -O ff5m.sh https://raw.githubusercontent.com/ghzserg/zmod_ff5m/refs/heads/main/telegram/ff5m.sh
chmod +x ff5m.sh
```

Beispielinstallation, geben Sie fluidd/mainsail in der Konsole ein:
```
ZSSH_ON SSH_SERVER=remote.server.ru SSH_PORT=22 SSH_USER=tbot VIDEO_PORT=8080 MOON_PORT=7125 REMOTE_RUN="./ff5m.sh bot1"
```

SSH startet 3 Minuten nach dem Start von Klipper und wird zu Beginn der Druckvorgänge automatisch neu gestartet (über das Makro `START_PRINT`).

[Mehr über Telegram bot](/de/Telegram/)

---

### ZSSH_OFF

SSH-Client ausschalten

---

### ZSSH_RESTART

SSH-Client neu starten

---

### ZSSH_RELOAD

Laden Sie den SSH-Client neu, falls er nicht ausgeführt wird.

Dieses Makro wird beim Start von Druckvorgängen (über `START_PRINT`) ausgelöst.

---

### ZRESTORE

Druckvorgang nach Stromausfall oder Druckerfehlern fortsetzen.

**Voraussetzungen:**

- Der native Bildschirm muss deaktiviert sein (die native Wiederherstellung ist mit ZRESTORE inkompatibel).

- Der Dateiname darf **nicht mit einer Zahl beginnen**.

---

### ZLINK

Verbindung zur Cloud [zmod.link](https://zmod.link/link/)

- Mit der Cloud können Sie Ihren Drucker über Fluidd oder Mainsail von überall aus steuern.
- Der Speicherbedarf des Druckers erhöht sich um 1 MB.
- Die Daten werden vom Drucker verschlüsselt in die Cloud übertragen.
- Der Zugriff auf die Cloud von jedem Ort aus erfolgt ebenfalls verschlüsselt.
- Der Benutzer sieht nur seine Drucker und kann keine Verbindung zu anderen Druckern herstellen.
- Der Zugang zu den Druckern des Benutzers ist durch ein Login und ein Passwort geschützt.

So erhalten Sie das Login und das Passwort:

1. Verbinden Sie sich mit dem Bot [@zmod_help_bot](https://t.me/zmod_help_bot)
2. Geben Sie den Befehl ```cloud``` ein - wenn Sie sich bereits registriert haben, wird Ihnen Ihr Benutzername angezeigt
3. um einen Benutzer mit dem Namen ```test``` zu registrieren, geben Sie ein: ```cloud register test```.
4. Um das Passwort zurückzusetzen, geben Sie ein: ```cloud reset_password```.
5. Um den aktuellen Benutzer zu entfernen, geben Sie ein: ```cloud remove```

Wie man sich mit der Cloud verbindet [zmod.link](https://zmod.link/link/):

1. Gehen Sie zu [zmod.link](https://zmod.link/link//) und geben Sie Ihr Login und Passwort ein
   
   <img width="547" height="615" alt="{264D6782-600F-4700-B9D2-0582F7427FD2}" src="https://github.com/user-attachments/assets/d8d3f51e-4fc7-4e1e-8fa7-dfc07ddbeab2" />

2. Klicken Sie auf die Schaltfläche "Drucker hinzufügen".
   
   <img width="569" height="502" alt="image" src="https://github.com/user-attachments/assets/72346ee6-dde6-4736-80b1-2eb2927bf983" />

3. öffnen Sie den Drucker in der benachbarten Registerkarte und geben Sie in der Konsole des Druckers den Befehl ```ZLINK``` ein
   
   <img width="1563" height="163" alt="{90DC4366-D258-4912-8028-22C589DF4E91}" src="https://github.com/user-attachments/assets/bee350ee-8d99-465c-9621-48788c6f7a9c" />

4. Kopieren Sie den Schlüssel in die Zwischenablage - er ist im Screenshot hervorgehoben
5. Geben Sie den Druckernamen und den Schlüssel ein, den Sie im vorherigen Schritt kopiert haben
   
   Beispiel:

   - `Testdrucker`.
       - `ecdsa-sha2-nistp256 AAAAE2VjZHNhLXNoYTItbmlzdHAyNTYAAAAAIbmlzdHAyNTYAAABBBDxX5XzNDXg+sbTArdiOzFpMtHXzgAhfC2N2ogS4TUsQYV4AD6HfSFL3J4ISNZ2DgesZf35rfH1I/qI2ckQVGlE=`

   
   <img width="557" height="775" alt="{E4FC2206-84BC-4134-92C2-B4253D8F23E5}" src="https://github.com/user-attachments/assets/b6401b71-5827-480d-ba1c-b7114f87177b" />
   
   Klicken Sie auf die Schaltfläche "Drucker hinzufügen".

6. Kopieren Sie den Befehl, den Sie von der Website erhalten haben, und fügen Sie ihn in die Druckerkonsole ein
   
   <img width="558" height="652" alt="{CDC8146F-B9DF-44A1-9C0B-3E6828CD540E}" src="https://github.com/user-attachments/assets/ed92a80f-93cc-41b8-bde1-aa0b2b2c0ecc" />
   
   In dem Beispiel ````zlink p=testprinter u=test m=10006 c=30006```.

   Klicken Sie auf ```I have already pasted the string into the printer```
   
   Der Drucker kann sich dann mit der Cloud verbinden.
   
   Um die Verbindung zu deaktivieren, geben Sie ```ZLINK_OFF``` ein.

7. Sie können nun eine Verbindung zu Fluidd oder Mainsail über das Internet herstellen
   
   <img width="526" height="654" alt="{CA6FC599-6060-4E3B-B525-EBB76D8780A1}" src="https://github.com/user-attachments/assets/0208dbad-8627-4636-b971-cfe0c5d7f8bd" />
   
   Sie müssen nur noch die gewünschte Schaltfläche auswählen.

PS: Die Kamera wird möglicherweise später geladen als die Schnittstelle - das ist normal.

PPS: Wenn etwas nicht funktioniert, aktualisieren Sie die Seite mit Strg + F5 und gehen Sie zu [zmod.link](https://zmod.link/link/).

   <img width="540" height="449" alt="{30D01CA4-3E9E-40EC-BCD1-9A8597DCCFDE}" src="https://github.com/user-attachments/assets/0d48b9be-a9df-4bfd-a38a-6d883ab31e73" />

   <img width="500" height="393" alt="{D03D643F-907C-4A6D-A48E-D881AAC33268}" src="https://github.com/user-attachments/assets/69f9d8d5-67ca-476e-b362-e35abb1d4832" />
