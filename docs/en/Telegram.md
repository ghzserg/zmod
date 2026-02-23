<h1 align="center">Telegram Bot</h1>

| Feature / Capability | [Notify Plugin](https://github.com/ghzserg/notify/) | [Moonraker Telegram Bot](/Telegram/) |
| :--- | :---: | :---: |
| **Requires external server** | – | + |
| **Remote printer control** | – (possible via [zmod.link](https://zmod.link/link/)) | + |
| **Timelapse creation** | – (possible via [timelapse](https://github.com/ghzserg/timelapse/)) | + |
| **Print event notifications** (start, pause, cancel, finish) | + | + |
| **Filament sensor notifications** | + | + |
| **Print progress percentage** | + | + |
| **Multiple printers via a single bot** | + | – |
| **Notifications via other services** | + | – |
| **Splooman** | - | + |

---

If you only need notifications in Telegram, then [use the Notify plugin](https://github.com/ghzserg/notify/)

## Telegram Bot
### Description

If you only need notifications in Telegram, then [use the Notify plugin](https://github.com/ghzserg/notify/)

Core Idea:
Our hardware is very slow and has limited memory. Therefore, running the moonraker-telegram-bot directly on the hardware is impractical.
However, we can run it on an external server. This requires any server (physical/virtual) that the printer can reach via SSH.

The new version automatically generates SSH keys (used for passwordless authentication).

Key locations:

- `‎/mod_data/ssh.pub.txt` — public key. Copy its contents to the server's `~/.ssh/authorized_keys` file.
- `‎/mod_data/ssh.key` — private key. Used by the printer to connect to the server.

You don’t need the keys themselves.
Simply call the [ZSSH_ON](/Zmod/#zssh_on) macro with the following parameters:

- `SSH_SERVER` — IP or hostname of your server
- `SSH_PORT` — SSH port on the server (default: 22)
- `SSH_USER` — SSH server username
- `VIDEO_PORT` — Server port for receiving video stream from the camera (default: 8080)
- `MOON_PORT` — Server port for receiving data from moonraker (default: 7125)
- `REMOTE_enN` — Command to execute on the remote server

SSH usage consumes approximately 300 KB of memory.

**If the printer and server are on the same network, SSH is optional. Refer to the [telegram.conf](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/telegram.conf) configuration file.**
Download the configuration file from the printer at `mod/telegram/`. [Sample-config](https://github.com/nlef/moonraker-telegram-bot/wiki/Sample-config)

---
### Bot Registration
How to register your bot:

1. Go to [@BotFather](https://t.me/BotFather)
2. Send `/newbot`
3. Enter any name you like
4. Enter the bot name (must end with `_bot`, e.g., `ff5msuper_bot`)
5. You’ll receive a long ID — add this to the bot’s `bot_token` parameter in the settings.

---
### Server Deployment
#### One-Command Telegram Bot Installation on Debian

If you only need notifications in Telegram, then [use the Notify plugin](https://github.com/ghzserg/notify/)

Install the Telegram bot with [one command](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/telegram.sh) on Debian:

Execute as the `root` user:
```bash
bash <(wget --cache=off -q -O - https://github.com/ghzserg/zmod_ff5m/raw/refs/heads/1.6/telegram/telegram.sh)
```

If `wget` is not installed:
```bash
apt update && apt install wget -y
```

This script will:

1. Install Docker
2. Download [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/docker-compose.yml) and [telegram.conf](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/telegram.conf) [Sample-config](https://github.com/nlef/moonraker-telegram-bot/wiki/Sample-config)
3. Create a `tbot` user
4. Guide you through bot registration and request the `bot_token`
5. Guide you to obtain the `chat_id` and request it
6. Install [ff5m.sh](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/ff5m.sh)

Add SSH keys manually.

---
#### Step-by-Step Telegram Bot Installation

If you only need notifications in Telegram, then [use the Notify plugin](https://github.com/ghzserg/notify/)

1. Copy [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/docker-compose.yml) from the printer’s `mod/telegram/` directory.
2. Install Docker (Debian instructions):
```bash
apt update 
apt upgrade -y
apt install docker.io docker-compose docker apparmor -y
```

3. Create a directory for the bot:
```bash
mkdir bot1
cd bot1
```

4. Place [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/docker-compose.yml) here.

5. Create subdirectories:
```bash
mkdir config log timelapse_finished timelapse
chmod 777 config log timelapse_finished timelapse
```

6. Copy [telegram.conf](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/telegram.conf) from `mod/telegram/` to `config/` and edit it.

[Sample-config](https://github.com/nlef/moonraker-telegram-bot/wiki/Sample-config)

For more bot configuration details, see [here](https://github.com/nlef/moonraker-telegram-bot/wiki).

7. Start the bot:
```bash
docker-compose up -d
```

8. Create a user and grant permissions:
```bash
useradd tbot
usermod -a -G docker tbot
```

---
#### Adding SSH Keys

1. Log in as the `tbot` user:
   ```bash
   su - tbot
   ```

2. Add SSH keys:
   ```bash
   mkdir .ssh
   cat > .ssh/authorized_keys
   ```
   Paste the public key from `mod_data/ssh.pub.txt`, then press `Ctrl + D`.

---
#### Starting ZSSH on the Printer
After setup, run the [ZSSH_ON](/Zmod/#zssh_on) macro on the printer with the required parameters.

SSH will automatically restart 3 minutes after each reboot.

#### Spoolman

Edit the [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/docker-compose.yml) file.

Add:
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

Open the port in the firewall, if you are using one:
```
iptables -I INPUT -p tcp --dport 7912 -j ACCEPT
```

Create the `spoolman` directory:
```
mkdir spoolman
chmod 777 spoolman
```

Restart Docker:
```
docker-compose down && docker-compose up -d
```
or
```
docker compose down && docker compose up -d
```

On the printer, add to `mod_data/user.moonraker.conf`

`external_IP` — the external IP address of the server running Docker.

The printer MUST have access to this IP.

```
[spoolman]
server: http://external_IP:7912
sync_rate: 5
```

#### TimeZone

Edit the file [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/docker-compose.yml)

Specify your time zone. The example file specifies ```TZ=Asia/Yekaterinburg```

```docker-compose down && docker-compose up -d``` or ```docker compose down && docker compose up -d```

#### Installation and Setup for Armbian (by noyhay)

If you only need notifications in Telegram, then [use the Notify plugin](https://github.com/ghzserg/notify/)

Download Debian Minimal/IOT images with Armbian from the website [https://www.armbian.com/download/](https://www.armbian.com/download/)

Install Armbian on an SD card using balenaEtcher from [https://etcher.balena.io/](https://etcher.balena.io/)

Boot the system, set a root password, and create a new user

Proceed under the root user:
```
su - root
```

Configure Wi-Fi if not set up during user creation:
```
sudo armbian-config
```

Update the system:
```
sudo apt update && sudo apt upgrade -y
```

Install AppArmor (Linux kernel security module):
```
sudo apt install -y apparmor apparmor-utils
```

Install Telegram bot:
```
bash <(wget --cache=off -q -O - https://github.com/ghzserg/zmod_ff5m/raw/refs/heads/1.6/telegram/telegram.sh)
```

Add SSH keys:
Switch to the `tbot` user from root:
```
su - tbot
```

Set up SSH keys:
```
mkdir -p .ssh
cat > .ssh/authorized_keys
```
Enter the public key from the file `mod_data/ssh.pub.txt` on your host system, then press **CTRL+D**

Reboot the system:
```
sudo reboot
```

---

#### Telegram Bot Installation On Kubernetes Via Helm (by aldiserg)

If you only need notifications in Telegram, then [use the Notify plugin](https://github.com/ghzserg/notify/)

Download and install helm [https://helm.sh/docs/intro/install/](https://helm.sh/docs/intro/install/)

Clone helm chart from repo
```
git clone https://github.com/aldiserg/zmod_ff5m_tg_bot.git
```
Changes:

1. persistence.enabled change to "false" if you nont planned to store timelapses

2. persistence.volumes...storageClass change if you will use external storage

2. configMapAsFile.data.telegram.conf - this is main config file, should be changed a few lines:
   ```
   [bot]
   server: 3D_printer_host:7125
   bot_token: 1111111111:AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
   chat_id: 111111111

   [camera]
   host: http://3D_printer_host:8080/?action=stream
   host_snapshot: http://3D_printer_host:8080/?action=snapshot
   ```
How to get bot_token and chat_id look [here](/Telegram/#bot-registration)

Installation:

You should be in helm chart folder to run install/upgrade command
```
helm upgrade --install zmod_ff5m_tg_bot ./ -n default -f values.yaml
```
