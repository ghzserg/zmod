<h1 align="center">Telegramm-Bot</h1>

| Funktion / Feature | [Notify Plugin](https://github.com/ghzserg/notify/blob/main/Readme_ru.md) | [Moonraker Telegram Bot](/de/Telegram/) | [Moonraker Telegram Bot](/de/Telegram/) |
| :--- | :---: | :---: |
| **Erfordert externen Server** | - | + |
| **Fernsteuerung des Druckers** | - (kann über [zmod.link](https://zmod.link/link/) erfolgen) | + | |
| **Zeitraffer erstellen** | - (möglich über [timelapse](https://github.com/ghzserg/timelapse/blob/main/Readme_ru.md) | + | |
| **Ereignisinformationen drucken** (Start, Pause, Abbruch, Ende) | + | + | | + |
| **Filamentsensor-Informationen** | + | + | + | | |
| **Drucken von Fortschrittsinformationen in Prozent** | + | + | + | | |
| **Arbeiten mit mehreren Druckern über einen Bot** | + | | - | |
| **Informieren durch andere Dienste** | + | | - | |
| **Splooman** | | - | + |

---

Wenn Sie nur Telegram-Benachrichtigungen benötigen, dann [verwenden Sie das Notify-Plugin](https://github.com/ghzserg/notify/blob/main/Readme_ru.md).

## Telegram Bot

### Beschreibung

Wenn Ihnen nur Telegram-Benachrichtigungen genügen - dann [verwenden Sie das Notify-Plugin](https://github.com/ghzserg/notify/blob/main/Readme_ru.md)

Das Wesentliche:
Wir haben sehr langsame Eisen und sehr wenig Speicher. Es macht also keinen Sinn, moonraker-telegram-bot auf der Hardware laufen zu lassen.
Aber wir können ihn auf einem externen Server laufen lassen.
Zu diesem Zweck benötigen wir einen beliebigen Server (real/virtuell), auf den der Drucker über SSH zugreifen kann.

Die neue Version erzeugt automatisch SSH-Schlüssel (sie werden zur Autorisierung ohne Passwörter verwendet).

Die Schlüssel können hier gefunden werden:

- `/mod_data/ssh.pub.txt` - dies ist ein öffentlicher Schlüssel. Der Text dieses Schlüssels sollte auf dem Server in der Datei `~/.ssh/authorised_keys` abgelegt werden
- `/mod_data/ssh.key` ist der private Schlüssel. Er wird vom Drucker verwendet, um sich mit dem Server zu verbinden.

Sie brauchen die Schlüssel selbst nicht.
Sie müssen nur das Makro [ZSSH_ON](/de/Zmod/#zssh_on) mit den folgenden Parametern aufrufen:

- SSH_SERVER - IP oder Name des Servers
- SSH_PORT - ssh-Port des Servers - normalerweise 22
- SSH_USER - Benutzername auf dem ssh-Server
- VIDEO_PORT - Port, der auf dem Server verwendet wird, um Videodaten von der Kamera zu empfangen (8080)
- MOON_PORT - Port, der auf dem Server verwendet wird, um Daten von moonraker zu empfangen (7125).
- REMOTE_RUN - Befehl, der auf dem Remote-Server aufgerufen werden soll

Die Ausführung von ssh verbraucht etwa 300 Kilobyte Speicherplatz.

**Wenn sich Drucker und Server im selben Netzwerk befinden, ist die Verwendung von SSH nicht erforderlich. Lesen Sie die Konfigurationsdatei [telegram.conf](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/telegram.conf)** [Sample-config](https://github.com/nlef/moonraker-telegram-bot/wiki/Sample-config).
Die Konfigurationsdatei kann vom Drucker `mod/telegram/` heruntergeladen werden.

---

### Registrieren Sie den Bot

Wie Sie Ihren Bot registrieren

1. gehen Sie zu [@BotFather](https://t.me/BotFather).
2. `/Neuer Bot`.
3. Gib einen beliebigen Namen ein
4. Geben Sie den Bot-Namen ff5msuper_bot ein - achten Sie darauf, dass am Ende _bot steht.
5. Geben Sie eine lange ID ein - diese muss in den Bot-Einstellungen im Parameter bot_token eingetragen werden

---

### Server-Bereitstellung

#### Telegram Bot mit einem Befehl unter Debian installieren

Wenn Sie nur Telegram-Benachrichtigungen benötigen, dann [verwenden Sie das Notify-Plugin](https://github.com/ghzserg/notify/blob/main/Readme_ru.md).

Installieren Sie Telegram bot [mit einem Befehl](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/telegram.sh) unter Debian:

Unter dem Benutzer `root` ausführen
```
bash <(wget --cache=off -q -O - https://github.com/ghzserg/zmod_ff5m/raw/refs/heads/1.6/telegram/telegram.sh)
```

Wenn Sie wget nicht haben
```
apt update && apt install wget -y
```

Dieses Skript:

1. Docker installieren
2. Laden Sie [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/docker-compose.yml) und [telegram.conf](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/telegram.conf) herunter. [Beispielkonfiguration](https://github.com/nlef/moonraker-telegram-bot/wiki/Sample-config)
3. Legt den Benutzer tbot an
4. Schreibt Anweisungen zur Registrierung des Telegram-Bots und fordert `bot_token` an
5. Schreibt Anweisungen, um `chat_id` zu erhalten und fordert `chat_id` an
6. Wird [ff5m.sh] installieren (https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/ff5m.sh)

Sie müssen den ssh-Schlüssel selbst hinzufügen

---

#### Telegram Bot schrittweise installieren

Wenn Sie nur Benachrichtigungen in Telegram benötigen - dann [verwenden Sie das Notify-Plugin](https://github.com/ghzserg/notify/blob/main/Readme_ru.md)

Nehmen Sie die Datei [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/docker-compose.yml) aus `mod/telegram/` c printer.

Installieren Sie docker, dann folgen Sie den Anweisungen für Debian
```
apt update
apt upgrade -y
apt install docker.io docker-compose docker apparmor -y
```

Erstellen Sie ein Verzeichnis für den Bot.
```
mkdir bot1
cd bot1
```

Legen Sie [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/docker-compose.yml) dort ab.

Unterverzeichnisse erstellen
```
mkdir config log timelapse_finished timelapse
chmod 777 config log timelapse_finished timelapse
```

Legen Sie [telegram.conf](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/telegram.conf) aus [mod/telegram/](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/telegram.conf) in das Konfigurationsverzeichnis und passen Sie es an Ihre Bedürfnisse an.

[Beispiel-Konfig](https://github.com/nlef/moonraker-telegram-bot/wiki/Sample-config)

Weitere Informationen zur Konfiguration des Bots können Sie [hier](https://github.com/nlef/moonraker-telegram-bot/wiki) nachlesen.

Führen Sie im Verzeichnis bot1 Folgendes aus
```
docker-compose up -d
```

Fügen Sie einen Benutzer hinzu und geben Sie ihm das Recht, docker-compose selbst auszuführen.
```
useradd tbot
usermod -a -G docker tbot
```

---

#### Hinzufügen von ssh-Schlüsseln

1. Melden Sie sich als Benutzer `tbot` an.
   `bash
   su - tbot
   ```

2. Ssh-Schlüssel schreiben:
   ```bash
   mkdir .ssh
   cat >.ssh/authorised_keys
   ```

   Geben Sie den öffentlichen Schlüssel aus der Datei ```mod_data/ssh.pub.txt``` ein. Dann ```Strg + d```

---

#### ZSSH auf dem Drucker starten
Führen Sie dann [ZSSH_ON](/de/Zmod/#zssh_on) auf dem Drucker mit den notwendigen Parametern aus.

Nach jedem Neustart wird ssh nach 3 Minuten automatisch gestartet.

#### ZeitZone

Bearbeiten Sie die Datei [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/docker-compose.yml)

Geben Sie Ihre Zeitzone an. In der Beispieldatei wird ```TZ=Asia/Yekaterinburg``` angegeben.

``` ```docker-compose down && docker-compose up -d```` oder ````docker compose down && docker compose up -d````

#### Spoolman

Bearbeiten Sie die Datei [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/docker-compose.yml)

Hinzufügen:
```
  spoolman:
    image: ghcr.io/donkie/spoolman:latest
    Neustart: wenn nicht gestoppt
    Volumes:
      - ./spoolman:/home/app/.local/share/spoolman
    Ports:
      - "7912:8000"
    Umgebung:
      - TZ=Asien/Jekaterinburg

```

Öffnen Sie den Port in Ihrer Firewall, wenn Sie diese verwenden.
````iptables -I INPUT -p tcp --dport 7912 -j ACCEPT```

Erstellen Sie einen `spoolman` Ordner.
```
mkdir spoolman
chmod 777 spoolman
```

Starten Sie Docker neu:
``````docker-compose down && docker-compose up -d```` oder ````docker compose down && docker compose up -d````

Auf dem Drucker schreiben Sie in ```mod_data/user.moonraker.conf```

`external_IP` - die externe IP des Servers, auf dem docker läuft

Der Drucker MUSS Zugriff auf diese IP haben.

```
[spoolman]
Server: http://external_IP:7912
sync_rate: 5
```

---

#### Installation und Konfiguration für armbian (von noyhay)

Wenn Ihnen nur Telegram-Benachrichtigungen genügen - dann [verwenden Sie das Notify-Plugin](https://github.com/ghzserg/notify/blob/main/Readme_ru.md)

Laden Sie Debian Minimal/IOT-Images mit Armbian von [https://www.armbian.com/download/](https://www.armbian.com/download/)

Installieren Sie Armbian auf der sdcard mit balenaEtcher von [https://etcher.balena.io/](https://etcher.balena.io/).

Starten Sie das System, erstellen Sie ein root-Passwort und einen neuen Benutzer

Von nun an machen wir alles unter dem Benutzer root
```
su - root
```

Richten Sie Wi-Fi ein, falls Sie es nach dem Anlegen eines neuen Benutzers noch nicht eingerichtet haben
```
sudo armbian-config
```

Aktualisieren Sie das System
```
sudo apt update && sudo apt upgrade -y
```

Apparmor Linux Kernel Sicherheitsmodul installieren
```
sudo apt install -y apparmor apparmor-utils
```

Installieren Sie den Telegram-Bot
```
bash <(wget --cache=off -q -O - https://github.com/ghzserg/zmod_ff5m/raw/refs/heads/1.6/telegram/telegram.sh)
```

Hinzufügen von ssh-Schlüsseln:
Einloggen vom Benutzer root zum Benutzer tbot
```
su - tbot
```

Schreibe ssh-Schlüssel:
```
mkdir -p .ssh
cat >.ssh/authorised_keys
```
Geben Sie den öffentlichen Schlüssel aus der Datei im Systemstamm mod_data/ssh.pub.txt ein. Dann CTRL+D

Starten Sie das System neu
``````sudo reboot```

---

#### Installation des Telegram-Bots über helm in Kubernetes (von aldiserg)

Wenn Ihnen nur Telegram-Benachrichtigungen genügen - dann [verwenden Sie das Notify-Plugin](https://github.com/ghzserg/notify/blob/main/Readme_ru.md)

Laden Sie helm herunter und installieren Sie es auf Ihrem Computer [https://helm.sh/docs/intro/install/](https://helm.sh/docs/intro/install/)

Klonen Sie das Repository mit helm chart
```
git clone https://github.com/aldiserg/zmod_ff5m_tg_bot.git
```
Ändern:

1. persistence.enabled auf false ändern, wenn Sie nicht vorhaben, Zeitraffer für eine lange Zeit zu speichern

2. persistence.volumes...storageClass, wenn wir einen externen Speicher für Zeitraffer verwenden wollen

2. configMapAsFile.data.telegram.conf - unsere Hauptkonfiguration, hier müssen wir die Felder ändern:
   ```
   [bot]
   server: 3D_printer_host:7125
   bot_token: 1111111111:AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
   chat_id: 111111111

   [Kamera]
   Gastgeber: http://3D_printer_host:8080/?action=stream
   host_snapshot: http://3D_printer_host:8080/?action=snapshot
   ```
Wie man bot_token und chat_id erhält siehe [hier](/de/Telegram/#register-bot)

Installation:

Die Befehle müssen aus dem Verzeichnis ausgeführt werden, in dem sich die Karte befindet
```
helm upgrade --install zmod_ff5m_tg_bot ./ -n default -f values.yaml
```
---

#### Lösung eines Problems bei der Verbindung des Druckers mit dem Server über SSH

Nach einer Neuinstallation des Betriebssystems auf dem Server wurden die **SSH-Hostschlüssel** geändert und der Drucker verweigert die Verbindung mit einer Fehlermeldung:
```
ssh-ed25519 host key mismatch ...
```

##### Lösung

###### 1. Löschen der gespeicherten Tasten auf dem Drucker

Verbinden Sie sich über SSH mit dem Drucker:

```` bash
ssh root@<<IP_drucker> -p 22
```

Standard-Passwort:
```
    root
```

Führen Sie als nächstes die Befehle aus:

```` bash
cd ~/.ssh
rm -f wissen
```

Damit werden die alten gespeicherten Hostschlüssel des Servers entfernt.

------------------------------------------------------------------------

###### 2. Erzeugen Sie das SSH-Schlüsselpaar auf dem Drucker neu (falls erforderlich)

Wenn Sie ein neues Schlüsselpaar erzeugen wollen, müssen Sie die alten Dateien löschen:

```` bash
cd ~/mod_data
rm -f ssh.pub.txt ssh.key
```

Nach dem Neustart wird der Dienst automatisch neue Schlüssel erstellen.

Der oeffentliche Schluessel (`ssh.pub.txt`) muss in einer Datei auf dem Server zurueckgelegt werden:
```
    ~/.ssh/authorised_keys
```
für den Benutzer, über den die Verbindung läuft (z.B. `tbot`).

------------------------------------------------------------------------

###### 3. Prüfen der Verbindung

Nach dem Löschen der Schlüssel auf dem Drucker und dem Aktualisieren der `authorised_keys` auf dem
Server --- führen Sie das ZSSH-Makro auf dem Drucker aus.
Die Verbindung sollte nun ohne Fehler aufgebaut werden.
