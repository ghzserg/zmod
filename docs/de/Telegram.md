<h1 align="center">Telegram-Bot</h1>

| Funktion | [Notify Plugin](https://github.com/ghzserg/notify/blob/main/Readme.md) | [Moonraker Telegram Bot](/de/Telegram/) |
| :--- | :---: | :---: |
| **Benötigt einen externen Server** | - | + |
| **Fernsteuerung des Druckers** | - (kann über [zmod.link](https://zmod.link/link/) erfolgen) | + |
| **Zeitraffer erstellen** | - (möglich über [timelapse](https://github.com/ghzserg/timelapse/blob/main/Readme.md)) | + |
| **Informationen zu Druckereignissen** (Start, Pause, Abbruch, Ende) | + | + |
| **Filamentsensor-Informationen** | + | + |
| **Druckfortschritt in Prozent** | + | + |
| **Mehrere Drucker über einen Bot** | + | - |
| **Benachrichtigung über andere Dienste** | + | - |
| **Spoolman** | - | + |

---
!!! info
    Wenn Sie nur Telegram-Benachrichtigungen benötigen, dann [verwenden Sie das Notify-Plugin](https://github.com/ghzserg/notify/blob/main/Readme.md).

## Telegram-Bot

### Beschreibung

Grundidee: Unser Drucker ist sehr langsam und verfügt über begrenzten Speicher. Daher ist es unpraktisch, den Moonraker-Telegram-Bot direkt auf dem Drucker auszuführen. Wir können ihn jedoch auf einem externen Server betreiben. Dazu benötigen wir einen beliebigen Server (physisch oder virtuell), den der Drucker per SSH erreichen kann.

Die neue Version generiert automatisch SSH-Schlüssel (für die passwortlose Authentifizierung).

Die Schlüssel befinden sich hier:

- `/mod_data/ssh.pub.txt` - dies ist ein öffentlicher Schlüssel. Der Text dieses Schlüssels sollte auf dem Server in der Datei `~/.ssh/authorized_keys` abgelegt werden.
- `/mod_data/ssh.key` ist der private Schlüssel. Er wird vom Drucker verwendet, um sich mit dem Server zu verbinden.

Sie brauchen die Schlüssel selbst nicht.
Sie müssen nur das Makro [ZSSH_ON](/de/Zmod/#zssh_on) mit den folgenden Parametern aufrufen:

- SSH_SERVER - IP oder Name des Servers
- SSH_PORT - SSH-Port des Servers, normalerweise 22
- SSH_USER - Benutzername auf dem SSH-Server
- VIDEO_PORT - Port, der auf dem Server verwendet wird, um Videodaten von der Kamera zu empfangen (8080)
- MOON_PORT - Port, der auf dem Server verwendet wird, um Daten von Moonraker zu empfangen (7125)
- REMOTE_RUN - Befehl, der auf dem Remote-Server aufgerufen werden soll

SSH verbraucht etwa 300 KB Arbeitsspeicher.

**Wenn sich Drucker und Server im selben Netzwerk befinden, ist SSH nicht erforderlich. Sehen Sie sich die Konfigurationsdatei [telegram.conf](https://github.com/ghzserg/z_ff5m/blob/1.7/telegram/telegram.conf) an.** Hier ist eine [Beispielkonfiguration](https://github.com/nlef/moonraker-telegram-bot/wiki/Sample-config).
Die Konfigurationsdatei kann vom Drucker aus `mod/telegram/` heruntergeladen werden.

---

### Registrieren Sie den Bot

So registrieren Sie Ihren Bot:

1. Gehen Sie zu [@BotFather](https://t.me/BotFather).
2. `/newbot`.
3. Geben Sie einen beliebigen Namen ein
4. Geben Sie den Benutzernamen des Bots ein (muss auf `_bot` enden, z. B. `ff5msuper_bot`)
5. Sie erhalten eine lange ID — tragen Sie diese in den Bot-Einstellungen beim Parameter `bot_token` ein.

---

### Server-Bereitstellung

#### Telegram-Bot mit einem Befehl unter Debian installieren

Wenn Sie nur Telegram-Benachrichtigungen benötigen, dann [verwenden Sie das Notify-Plugin](https://github.com/ghzserg/notify/blob/main/Readme.md).

Installieren Sie den Telegram-Bot [mit einem Befehl](https://github.com/ghzserg/z_ff5m/blob/1.7/telegram/telegram.sh) unter Debian:

Als Benutzer `root` ausführen:
```bash
wget --cache=off -q -O - https://github.com/ghzserg/zmod_ff5m/raw/refs/heads/1.7/telegram/telegram.sh
```

Wenn Sie kein wget haben:
```bash
apt update && apt install wget -y
```

Dieses Skript:

1. Installiert Docker
2. Lädt [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.7/telegram/docker-compose.yml) und [telegram.conf](https://github.com/ghzserg/z_ff5m/blob/1.7/telegram/telegram.conf) herunter. [Beispielkonfiguration](https://github.com/nlef/moonraker-telegram-bot/wiki/Sample-config)
3. Erstellt einen `tbot`-Benutzer
4. Führt Sie durch die Bot-Registrierung und fragt den `bot_token` ab
5. Hilft Ihnen, die `chat_id` zu ermitteln und fragt diese ab
6. Installiert [ff5m.sh](https://github.com/ghzserg/z_ff5m/blob/1.7/telegram/ff5m.sh)

Den **SSH-Schlüssel** müssen Sie selbst hinzufügen.

---

#### Telegram-Bot Schritt für Schritt installieren

Wenn Sie nur Benachrichtigungen in Telegram benötigen, dann [verwenden Sie das Notify-Plugin](https://github.com/ghzserg/notify/).

1. Kopieren Sie die [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.7/telegram/docker-compose.yml) aus dem Verzeichnis `mod/telegram/` des Druckers.
2. Installieren Sie Docker (Anleitung für Debian):
```bash
apt update 
apt upgrade -y
apt install docker.io docker-compose docker apparmor -y
```

3. Erstellen Sie ein Verzeichnis für den Bot:
```bash
mkdir bot1
cd bot1
```

4. Kopieren Sie die [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.7/telegram/docker-compose.yml) in das erstellte Verzeichnis.

5. Erstellen Sie die Unterverzeichnisse:
```bash
mkdir config log timelapse_finished timelapse
chmod 777 config log timelapse_finished timelapse
```

6. Kopieren Sie die **telegram.conf** aus dem Ordner [mod/telegram/](https://github.com/ghzserg/z_ff5m/blob/1.7/telegram/telegram.conf) in das Konfigurationsverzeichnis und passen Sie sie an Ihre Bedürfnisse an.

[Beispielkonfiguration](https://github.com/nlef/moonraker-telegram-bot/wiki/Sample-config)

Weitere Informationen zur Konfiguration des Bots finden Sie [hier](https://github.com/nlef/moonraker-telegram-bot/wiki) nachlesen.

7. Starten Sie den Bot:
```bash
docker-compose up -d
```

8. Erstellen Sie einen Benutzer und vergeben Sie Berechtigungen:
```bash
useradd tbot
usermod -a -G docker tbot
```

---

#### SSH-Schlüssel hinzufügen

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

Nach jedem Neustart wird SSH nach 3 Minuten automatisch gestartet.

#### Spoolman

Bearbeiten Sie die Datei [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.7/telegram/docker-compose.yml)

Fügen Sie hinzu:
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
```bash
iptables -I INPUT -p tcp --dport 7912 -j ACCEPT
```

Erstellen Sie das `spoolman`-Verzeichnis:
```bash
mkdir spoolman
chmod 777 spoolman
```

Starten Sie Docker neu:
```bash
docker-compose down && docker-compose up -d
```
oder
```bash
docker compose down && docker compose up -d
```

Fügen Sie auf dem Drucker in der Datei `mod_data/user.moonraker.conf` Folgendes hinzu:

`external_IP` - die externe IP des Servers, auf dem Docker läuft

Der Drucker MUSS Zugriff auf diese IP haben.

```
[spoolman]
server: http://external_IP:7912
sync_rate: 5
```

#### Zeitzone

Bearbeiten Sie die Datei [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.7/telegram/docker-compose.yml)

Geben Sie Ihre Zeitzone an. In der Beispieldatei wird ```TZ=Asia/Yekaterinburg``` angegeben.

```bash
docker-compose down && docker-compose up -d
```
oder
```bash
docker compose down && docker compose up -d
```

---

#### Installation und Konfiguration für Armbian (von noyhay)

Wenn Ihnen Telegram-Benachrichtigungen genügen, dann [verwenden Sie das Notify-Plugin](https://github.com/ghzserg/notify/blob/main/Readme_ru.md)

Laden Sie ein Debian-Minimal/IOT-Image mit Armbian von [https://www.armbian.com/download/](https://www.armbian.com/download/)

Schreiben Sie Armbian mit balenaEtcher von [https://etcher.balena.io/](https://etcher.balena.io/) auf die SD-Karte.

Starten Sie das System, legen Sie ein root-Passwort und einen neuen Benutzer an.

Ab jetzt erfolgt alles als Benutzer root.
```bash
su - root
```

Richten Sie WLAN ein, falls Sie es nach dem Anlegen des Benutzers noch nicht getan haben.
```bash
sudo armbian-config
```

Aktualisieren Sie das System:
```bash
sudo apt update && sudo apt upgrade -y
```

Installieren Sie das Linux-Kernel-Sicherheitsmodul AppArmor:
```bash
sudo apt install -y apparmor apparmor-utils
```

Installieren Sie den Telegram-Bot:
```bash 
wget --cache=off -q -O - https://github.com/ghzserg/zmod_ff5m/raw/refs/heads/1.7/telegram/telegram.sh
```

SSH-Schlüssel hinzufügen:

- Wechseln Sie vom Benutzer root zum Benutzer tbot:
```bash
su - tbot
```

SSH-Schlüssel eintragen:
```bash
mkdir -p .ssh
cat >.ssh/authorised_keys
```
Fügen Sie den öffentlichen Schlüssel aus der Datei `mod_data/ssh.pub.txt` ein. Dann `Strg + D`.

Starten Sie das System neu:
```
sudo reboot
```

---

#### Telegram-Bot-Installation auf Kubernetes via Helm (von aldiserg)

Wenn Ihnen Telegram-Benachrichtigungen genügen, dann [verwenden Sie das Notify-Plugin](https://github.com/ghzserg/notify/blob/main/Readme.md)

Laden Sie Helm herunter und installieren Sie es auf Ihrem Computer: [https://helm.sh/docs/intro/install/](https://helm.sh/docs/intro/install/)

Klonen Sie das Repository mit dem Helm-Chart:
```bash
git clone https://github.com/aldiserg/zmod_ff5m_tg_bot.git
```

- Änderungen:

    * Ändern Sie `persistence.enabled` auf „false“, wenn Sie keine Zeitraffer speichern möchten.

    * Ändern Sie `persistence.volumes...storageClass`, wenn Sie externen Speicher verwenden.

    * Die Datei `configMapAsFile.data.telegram.conf` ist die Hauptkonfigurationsdatei und darin müssen einige Zeilen angepasst werden.
   ```
   [bot]
   server: 3D_printer_host:7125
   bot_token: 1111111111:AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
   chat_id: 111111111

   [Kamera]
   Gastgeber: http://3D_printer_host:8080/?action=stream
   host_snapshot: http://3D_printer_host:8080/?action=snapshot
   ```
Wie Sie bot_token und chat_id erhalten, sehen Sie [hier](/de/Telegram/#registrieren-sie-den-bot)

Installation:

Führen Sie die Befehle „install“ bzw. „upgrade“ im Ordner des Helm-Charts aus.
```bash
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

Standardpasswort:
```bash
root
```

Führen Sie anschließend die folgenden Befehle aus:

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

Der öffentliche Schlüssel (`ssh.pub.txt`) muss auf dem Server zur Datei `~/.ssh/authorized_keys` hinzugefügt werden:
```bash
~/.ssh/authorised_keys
```
für den Benutzer, über den die Verbindung läuft (z. B. `tbot`).

------------------------------------------------------------------------

###### 3. Verbindung testen

Nachdem Sie die Schlüssel auf dem Drucker gelöscht und die Datei `authorized_keys` auf dem Server aktualisiert haben, führen Sie das Makro ZSSH_ON auf dem Drucker aus. Die Verbindung sollte nun fehlerfrei hergestellt werden.

#### Alternative zum Bot

Da es in letzter Zeit gelegentlich zu Ausfällen bei Telegram kommt, gibt es eine Alternative: Zeitrafferaufnahmen auf einem separaten Server erstellen (dem Server, der zuvor für den Telegram-Bot verwendet wurde).

Ein Beispiel finden Sie im Repository [printer_timelapse](https://github.com/seligor/printer_timelapse). Mit wenigen Anpassungen lässt es sich mit [web-timelapse](https://github.com/seligor/web-timelapse) kombinieren. So erhalten Sie ähnliche Funktionen ohne einen Messenger.

Der Hauptablauf: Der Drucker wird daraufhin überwacht, ob ein Druck beginnt. Während des Drucks werden Screenshots aufgenommen. Nach Abschluss des Drucks wird daraus ein Video mit Vorschaubild erstellt. Mehrere Drucker werden unterstützt.

