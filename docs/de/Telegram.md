<h1 align="center">Telegramm-Bot</h1>

| Funktion / Feature | [Notify Plugin](https://github.com/ghzserg/notify/blob/main/Readme.md) | [Moonraker Telegram Bot](/de/Telegram/) |
| :--- | :---: | :---: |
| **Erfordert externen Server** | - | + |
| **Fernsteuerung des Druckers** | - (kann über [zmod.link](https://zmod.link/link/) erfolgen) | + |
| **Zeitraffer erstellen** | - (möglich über [timelapse](https://github.com/ghzserg/timelapse/blob/main/Readme.md) | + |
| **Ereignisinformationen drucken** (Start, Pause, Abbruch, Ende) | + | + |
| **Filamentsensor-Informationen** | + | + |
| **Drucken von Fortschrittsinformationen in Prozent** | + | + |
| **Arbeiten mit mehreren Druckern über einen Bot** | + | - |
| **Informieren durch andere Dienste** | + | - |
| **Splooman** | - | + |

---
!!! info
    Wenn Sie nur Telegram-Benachrichtigungen benötigen, dann [verwenden Sie das Notify-Plugin](https://github.com/ghzserg/notify/blob/main/Readme.md).

## Telegram Bot

### Beschreibung

Grundidee: Unsere Hardware ist sehr langsam und verfügt über begrenzten Speicher. Daher ist es unpraktisch, den Moonraker-Telegram-Bot direkt auf der Hardware auszuführen. Wir können ihn jedoch auf einem externen Server betreiben. Dazu benötigen wir einen beliebigen Server (physisch oder virtuell), den der Drucker per SSH erreichen kann.

Die neue Version generiert automatisch SSH-Schlüssel (für die passwortlose Authentifizierung).

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

**Wenn sich Drucker und der Server im selben Netzwerk befinden, ist die Verwendung von SSH nicht erforderlich. Lesen Sie die [telegram.conf](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/telegram.conf) Konfigurationsdatei** Hier ist eine [Sample-config](https://github.com/nlef/moonraker-telegram-bot/wiki/Sample-config).
Die Konfigurationsdatei kann vom Drucker `mod/telegram/` heruntergeladen werden.

---

### Registrieren Sie den Bot

Wie Sie Ihren Bot registrieren

1. gehen Sie zu [@BotFather](https://t.me/BotFather).
2. `/newbot`.
3. Gib einen beliebigen Namen ein
4. Geben Sie den Namen des Bot ein (muss auf `_bot` enden, z. B. `ff5msuper_bot`)
5. Sie erhalten eine lange ID — tragen Sie diese in den Einstellungen beim Parameter `bot_token` des Bots ein.

---

### Server-Bereitstellung

#### Telegram Bot mit einem Befehl unter Debian installieren

Wenn Sie nur Telegram-Benachrichtigungen benötigen, dann [verwenden Sie das Notify-Plugin](https://github.com/ghzserg/notify/blob/main/Readme.md).

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
2. Laden Sie [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.7/telegram/docker-compose.yml) und [telegram.conf](https://github.com/ghzserg/z_ff5m/blob/1.7/telegram/telegram.conf) herunter. [Beispielkonfiguration](https://github.com/nlef/moonraker-telegram-bot/wiki/Sample-config)
3. Erstellt einen `tbot`-Benutzer
4. Führt Sie durch die Bot-Registrierung und fragt den `bot_token` ab
5. Hilft Ihnen, die `chat_id` zu ermitteln und fragt diese ab
6. Wird [ff5m.sh](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/ff5m.sh) installieren.

Sie müssen den **ssh-Schlüssel** selbst hinzufügen.

---

#### Telegram Bot schrittweise installieren

Wenn Sie nur Benachrichtigungen in Telegram benötigen, dann [verwenden Sie das Notify-Plugin](https://github.com/ghzserg/notify/)

1. Kopieren Sie die [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/docker-compose.yml) aus dem Verzeichnis `mod/telegram/` des Druckers.
2. Installieren Sie Docker (Anleitung für Debian):
```bash
apt update 
apt upgrade -y
apt install docker.io docker-compose docker apparmor -y
```

3. Erstellen Sie ein Verzeichnis für den Bot:
```
mkdir bot1
cd bot1
```

4. Kopieren Sie die [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.7/telegram/docker-compose.yml) in das erstellte Verzeichniss.

5. Erstellen Sie die Unterverzeichnisse:
```
mkdir config log timelapse_finished timelapse
chmod 777 config log timelapse_finished timelapse
```

6. Kopieren Sie die **telegram.conf** aus dem Ordner [mod/telegram/](https://github.com/ghzserg/z_ff5m/blob/1.7/telegram/telegram.conf) in das Konfigurationsverzeichnis und passen Sie es an Ihre Bedürfnisse an.

[Beispiel-Konfig](https://github.com/nlef/moonraker-telegram-bot/wiki/Sample-config)

Weitere Informationen zur Konfiguration des Bots können Sie [hier](https://github.com/nlef/moonraker-telegram-bot/wiki) nachlesen.

7. Starten Sie den Bot:
```
docker-compose up -d
```

8. Erstellen Sie einen Benutzer und vergeben Sie Berechtigungen:
```
useradd tbot
usermod -a -G docker tbot
```

---

#### Hinzufügen von ssh-Schlüsseln

1. Melden Sie sich als Benutzer `tbot` an.
   ```bash
   su - tbot
   ```

2. SSH-Schlüssel hinzufügen:
   ```bash
   mkdir .ssh
   cat >.ssh/authorised_keys
   ```

   Fügen Sie den öffentlichen Schlüssel (Public Key) aus ```mod_data/ssh.pub.txt``` ein und drücken Sie anschließend ```Strg + D```.

---

#### ZSSH auf dem Drucker starten
Führen Sie dann [ZSSH_ON](/de/Zmod/#zssh_on) auf dem Drucker mit den notwendigen Parametern aus.

Nach jedem Neustart wird ssh nach 3 Minuten automatisch gestartet.

#### Spoolman

Bearbeiten Sie die Datei [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.7/telegram/docker-compose.yml)

Hinzufügen:
```yaml
  spoolman:
    image: ghcr.io/donkie/spoolman:latest
    restart: unless-stopped
    volumes:
      - ./spoolman:/home/app/.local/share/spoolman
    ports:
      - "7912:8000"
    environment:
      - TZ=Asia/Yekaterinburg

```

Öffnen Sie den Port in Ihrer Firewall, wenn Sie diese verwenden.
```
iptables -I INPUT -p tcp --dport 7912 -j ACCEPT
```

Erstellen Sie das `spoolman`-Verzeichnis:
```
mkdir spoolman
chmod 777 spoolman
```

Starten Sie Docker neu:
```
docker-compose down && docker-compose up -d
```
oder
```
docker compose down && docker compose up -d
```

Fügen Sie auf dem Drucker in der Datei `mod_data/user.moonraker.conf` Folgendes hinzu:

`external_IP` - die externe IP des Servers, auf dem docker läuft

Der Drucker MUSS Zugriff auf diese IP haben.

```
[spoolman]
server: http://external_IP:7912
sync_rate: 5
```

#### Zeitzone

Bearbeiten Sie die Datei [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.7/telegram/docker-compose.yml)

Geben Sie Ihre Zeitzone an. In der Beispieldatei wird ```TZ=Asia/Yekaterinburg``` angegeben.

```
docker-compose down && docker-compose up -d
```
oder
```
docker compose down && docker compose up -d
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
Geben Sie den öffentlichen Schlüssel aus der Datei im Systemstamm ```mod_data/ssh.pub.txt``` ein. Dann CTRL+D

Starten Sie das System neu
```
sudo reboot
```

---

#### Telegram-Bot-Installation auf Kubernetes via Helm (von aldiserg)

Wenn Ihnen nur Telegram-Benachrichtigungen genügen - dann [verwenden Sie das Notify-Plugin](https://github.com/ghzserg/notify/blob/main/Readme.md)

Laden Sie helm herunter und installieren Sie es auf Ihrem Computer [https://helm.sh/docs/intro/install/](https://helm.sh/docs/intro/install/)

Klonen Sie das Repository mit helm chart
```
git clone https://github.com/aldiserg/zmod_ff5m_tg_bot.git
```

- Änderungen:

    * Ändern Sie `persistence.enabled` auf „false“, wenn Sie keine Zeitraffer speichern möchten.

    * Ändern Sie `persistence.volumes...storageClass`, wenn Sie externen Speicher verwenden.

    * Die Datei `configMapAsFile.data.telegram.conf` ist die Hauptkonfigurationsdatei und sollte um einige Zeilen angepasst werden.
   ```
   [bot]
   server: 3D_printer_host:7125
   bot_token: 1111111111:AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
   chat_id: 111111111

   [Kamera]
   Gastgeber: http://3D_printer_host:8080/?action=stream
   host_snapshot: http://3D_printer_host:8080/?action=snapshot
   ```
Wie man bot_token und chat_id erhält siehe [hier](/de/Telegram/#registrieren-sie-den-bot)

Installation:

Sie müssen sich im Helm-Chart-Ordner befinden, um den Befehl „install“ oder „upgrade“ auszuführen.
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

###### 1. Löschen der gespeicherten Schlüssel auf dem Drucker

Verbinden Sie sich über SSH mit dem Drucker:

``` bash
ssh root@<<IP_drucker> -p 22
```

Standard-Passwort:
```
root
```

Führen Sie als nächstes den Befehle aus:

```bash
cd ~/.ssh
rm -f know*
```

Damit werden die alten gespeicherten Hostschlüssel des Servers entfernt.

------------------------------------------------------------------------

###### 2. Erzeugen Sie das SSH-Schlüsselpaar auf dem Drucker neu (falls erforderlich)

Wenn Sie ein neues Schlüsselpaar erzeugen wollen, müssen Sie die alten Dateien löschen:

```bash
cd ~/mod_data
rm -f ssh.pub.txt ssh.key
```

Nach dem Neustart wird der Dienst automatisch neue Schlüssel erstellen.

Der öffentliche Schlüssel (ssh.pub.txt) muss der Serverdatei ~/.ssh/authorized_keys hinzugefügt werden:
```
    ~/.ssh/authorised_keys
```
für den Benutzer, über den die Verbindung läuft (z.B. `tbot`).

------------------------------------------------------------------------

###### 3. Verbindung testen

Nachdem Sie die Schlüssel auf dem Drucker gelöscht und die Datei authorized_keys auf dem Server aktualisiert haben, führen Sie das ZSSH-Makro auf dem Drucker aus. Die Verbindung sollte nun fehlerfrei hergestellt werden.
