<h1 align="center">Telegram Bot</h1>

| Funkce / Schopnost | [Notify Plugin](https://github.com/ghzserg/notify/) | [Moonraker Telegram Bot](Telegram.md) |
| :--- | :---: | :---: |
| **Vyžaduje externí server** | – | + |
| **Vzdálené ovládání tiskárny** | – (možné přes [zmod.link](https://zmod.link/link/)) | + |
| **Vytváření časosběrů** | – (možné přes [timelapse](https://github.com/ghzserg/timelapse/)) | + |
| **Notifikace o událostech tisku** (start, pauza, zrušení, dokončení) | + | + |
| **Notifikace senzoru filamentu** | + | + |
| **Procentuální průběh tisku** | + | + |
| **Více tiskáren přes jednoho bota** | + | – |
| **Notifikace přes jiné služby** | + | – |
| **Splooman** | - | + |

---

Pokud potřebujete pouze notifikace v Telegramu, [použijte Notify plugin](https://github.com/ghzserg/notify/)

## Telegram Bot
### Popis

Pokud potřebujete pouze notifikace v Telegramu, [použijte Notify plugin](https://github.com/ghzserg/notify/)

Hlavní myšlenka:
Naše hardware je velmi pomalé a má omezenou paměť. Proto je nepraktické spouštět moonraker-telegram-bot přímo na hardwaru.
Nicméně jej můžeme spustit na externím serveru. To vyžaduje jakýkoliv server (fyzický/virtuální), ke kterému má tiskárna přístup přes SSH.

Nová verze automaticky generuje SSH klíče (používané pro přihlášení bez hesla).

Umístění klíčů:

- `‎/mod_data/ssh.pub.txt` — veřejný klíč. Zkopírujte jeho obsah do souboru `~/.ssh/authorized_keys` na serveru.
- `‎/mod_data/ssh.key` — soukromý klíč. Používá se tiskárnou pro připojení k serveru.

Samotné klíče nepotřebujete.
Jednoduše zavolejte makro [ZSSH_ON](Zmod.md#zssh_on) s následujícími parametry:

- `SSH_SERVER` — IP nebo hostname vašeho serveru
- `SSH_PORT` — SSH port na serveru (výchozí: 22)
- `SSH_USER` — uživatelské jméno na serveru
- `VIDEO_PORT` — Port serveru pro příjem video streamu z kamery (výchozí: 8080)
- `MOON_PORT` — Port serveru pro příjem dat z moonrakeru (výchozí: 7125)
- `REMOTE_enN` — Příkaz k provedení na vzdáleném serveru

Použití SSH spotřebuje přibližně 300 KB paměti.

**Pokud jsou tiskárna a server ve stejné síti, SSH není nutné. Viz konfigurační soubor [telegram.conf](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/telegram.conf).**
Stáhněte konfigurační soubor z tiskárny na `mod/telegram/`. [Ukázkový-konfig](https://github.com/nlef/moonraker-telegram-bot/wiki/Sample-config)

---

### Registrace bota
Jak zaregistrovat svého bota:

1. Přejděte na [@BotFather](https://t.me/BotFather)
2. Pošlete `/newbot`
3. Zadejte libovolné jméno
4. Zadejte jméno bota (musí končit `_bot`, např. `ff5msuper_bot`)
5. Obdržíte dlouhé ID — přidejte jej do parametru `bot_token` v nastavení bota.

---
### Nasazení na server
#### Instalace Telegram bota na Debian jedním příkazem

Pokud potřebujete pouze notifikace v Telegramu, [použijte Notify plugin](https://github.com/ghzserg/notify/)

Nainstalujte Telegram bota [jedním příkazem](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/telegram.sh) na Debian:

Spusťte jako uživatel `root`:
```bash
bash <(wget --cache=off -q -O - https://github.com/ghzserg/zmod_ff5m/raw/refs/heads/1.6/telegram/telegram.sh)
```

Pokud není nainstalován `wget`:
```bash
apt update && apt install wget -y
```

Tento skript:

1. Nainstaluje Docker
2. Stáhne [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/docker-compose.yml) a [telegram.conf](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/telegram.conf) [Ukázkový-konfig](https://github.com/nlef/moonraker-telegram-bot/wiki/Sample-config)
3. Vytvoří uživatele `tbot`
4. Provede vás registrací bota a požádá o `bot_token`
5. Provede vás získáním `chat_id` a požádá o něj
6. Nainstaluje [ff5m.sh](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/ff5m.sh)

Přidejte SSH klíče ručně.

---
#### Krok za krokem instalace Telegram bota

Pokud potřebujete pouze notifikace v Telegramu, [použijte Notify plugin](https://github.com/ghzserg/notify/)

1. Zkopírujte [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/docker-compose.yml) z adresáře `mod/telegram/` na tiskárně.
2. Nainstalujte Docker (instrukce pro Debian):
```bash
apt update 
apt upgrade -y
apt install docker.io docker-compose docker apparmor -y
```

3. Vytvořte adresář pro bota:
```bash
mkdir bot1
cd bot1
```

4. Umístěte [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/docker-compose.yml) sem.

5. Vytvořte podadresáře:
```bash
mkdir config log timelapse_finished timelapse
chmod 777 config log timelapse_finished timelapse
```

6. Zkopírujte [telegram.conf](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/telegram.conf) z `mod/telegram/` do `config/` a upravte jej.

[Ukázkový-konfig](https://github.com/nlef/moonraker-telegram-bot/wiki/Sample-config)

Pro více detailů o konfiguraci bota viz [zde](https://github.com/nlef/moonraker-telegram-bot/wiki).

7. Spusťte bota:
```bash
docker-compose up -d
```

8. Vytvořte uživatele a přidělte oprávnění:
```bash
useradd tbot
usermod -a -G docker tbot
```

---
#### Přidání SSH klíčů

1. Přihlaste se jako uživatel `tbot`:
   ```bash
   su - tbot
   ```

2. Přidejte SSH klíče:
   ```bash
   mkdir .ssh
   cat > .ssh/authorized_keys
   ```
   Vložte veřejný klíč z `mod_data/ssh.pub.txt`, poté stiskněte `Ctrl + D`.

---
#### Spuštění ZSSH na tiskárně
Po nastavení spusťte makro [ZSSH_ON](Zmod.md#zssh_on) na tiskárně s požadovanými parametry.

SSH se automaticky restartuje 3 minuty po každém restartu.

#### Spoolman

Upravte soubor [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/docker-compose.yml).

Přidejte:
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

Otevřete port ve firewallu, pokud jej používáte:
```
iptables -I INPUT -p tcp --dport 7912 -j ACCEPT
```

Vytvořte adresář `spoolman`:
```
mkdir spoolman
chmod 777 spoolman
```

Restartujte Docker:
```
docker-compose down && docker-compose up -d
```
nebo
```
docker compose down && docker compose up -d
```

Na tiskárně přidejte do `mod_data/user.moonraker.conf`

`external_IP` — externí IP adresa serveru, na kterém běží Docker.

Tiskárna MUSÍ mít přístup k této IP.

```
[spoolman]
server: http://external_IP:7912
sync_rate: 5
```

#### Časové pásmo

Upravte soubor [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.6/telegram/docker-compose.yml)

Specifikujte své časové pásmo. Příklad souboru uvádí ```TZ=Asia/Yekaterinburg```

```docker-compose down && docker-compose up -d``` nebo ```docker compose down && docker compose up -d```

#### Instalace a nastavení pro Armbian (od noyhay)

Pokud potřebujete pouze notifikace v Telegramu, [použijte Notify plugin](https://github.com/ghzserg/notify/)

Stáhněte Debian Minimal/IOT obrazy s Armbian z webu [https://www.armbian.com/download/](https://www.armbian.com/download/)

Nainstalujte Armbian na SD kartu pomocí balenaEtcher z [https://etcher.balena.io/](https://etcher.balena.io/)

Spusťte systém, nastavte heslo root a vytvořte nového uživatele

Pokračujte pod uživatelem root:
```
su - root
```

Nakonfigurujte Wi-Fi, pokud nebylo nastaveno během vytváření uživatele:
```
sudo armbian-config
```

Aktualizujte systém:
```
sudo apt update && sudo apt upgrade -y
```

Nainstalujte AppArmor (bezpečnostní modul jádra Linuxu):
```
sudo apt install -y apparmor apparmor-utils
```

Nainstalujte Telegram bota:
```
bash <(wget --cache=off -q -O - https://github.com/ghzserg/zmod_ff5m/raw/refs/heads/1.6/telegram/telegram.sh)
```

Přidejte SSH klíče:
Přepněte na uživatele `tbot` z root:
```
su - tbot
```

Nastavte SSH klíče:
```
mkdir -p .ssh
cat > .ssh/authorized_keys
```
Zadejte veřejný klíč ze souboru `mod_data/ssh.pub.txt` na vašem hostitelském systému, poté stiskněte **CTRL+D**

Restartujte systém:
```
sudo reboot
```

---

#### Instalace Telegram bota na Kubernetes přes Helm (od aldiserg)

Pokud potřebujete pouze notifikace v Telegramu, [použijte Notify plugin](https://github.com/ghzserg/notify/)

Stáhněte a nainstalujte helm [https://helm.sh/docs/intro/install/](https://helm.sh/docs/intro/install/)

Naklonujte helm chart z repozitáře
```
git clone https://github.com/aldiserg/zmod_ff5m_tg_bot.git
```
Změny:

1. persistence.enabled změňte na "false", pokud neplánujete ukládat časosběry

2. persistence.volumes...storageClass změňte, pokud budete používat externí úložiště

2. configMapAsFile.data.telegram.conf - toto je hlavní konfigurační soubor, mělo by být změněno několik řádků:
   ```
   [bot]
   server: 3D_printer_host:7125
   bot_token: 1111111111:AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
   chat_id: 111111111

   [camera]
   host: http://3D_printer_host:8080/?action=stream
   host_snapshot: http://3D_printer_host:8080/?action=snapshot
   ```
Jak získat bot_token a chat_id viz [zde](Telegram.md#bot-registration)

Instalace:

Měli byste být ve složce helm chart pro spuštění příkazu install/upgrade
```
helm upgrade --install zmod_ff5m_tg_bot ./ -n default -f values.yaml
```
