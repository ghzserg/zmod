<h1 align="center">Telegram Bot</h1>

| Funkce | [Notify Plugin](https://github.com/ghzserg/notify/) | [Moonraker Telegram Bot](/cs/Telegram/) |
| :--- | :---: | :---: |
| **Vyžaduje externí server** | – | + |
| **Vzdálené ovládání tiskárny** | – (možné přes [zmod.link](https://zmod.link/link/)) | + |
| **Vytváření časosběrů** | – (možné přes [timelapse](https://github.com/ghzserg/timelapse/)) | + |
| **Notifikace o událostech tisku** (start, pauza, zrušení, dokončení) | + | + |
| **Notifikace senzoru filamentu** | + | + |
| **Procentuální průběh tisku** | + | + |
| **Více tiskáren přes jednoho bota** | + | – |
| **Notifikace přes jiné služby** | + | – |
| **Spoolman** | - | + |

---

Pokud potřebujete pouze notifikace v Telegramu, [použijte Notify plugin](https://github.com/ghzserg/notify/)

## Telegram Bot
### Popis

Hlavní myšlenka:
Naše tiskárna je velmi pomalá a má omezenou paměť. Proto je nepraktické spouštět moonraker-telegram-bot přímo na ní.
Nicméně jej můžeme spustit na externím serveru. K tomu stačí jakýkoli server (fyzický/virtuální), ke kterému má tiskárna přístup přes SSH.

Nová verze automaticky generuje SSH klíče (používané pro přihlášení bez hesla).

Umístění klíčů:

- `/mod_data/ssh.pub.txt` — veřejný klíč. Zkopírujte jeho obsah do souboru `~/.ssh/authorized_keys` na serveru.
- `/mod_data/ssh.key` — soukromý klíč. Tiskárna ho používá pro připojení k serveru.

Samotné klíče nepotřebujete.
Jednoduše zavolejte makro [ZSSH_ON](/cs/Zmod/#zssh_on) s následujícími parametry:

- `SSH_SERVER` — IP nebo hostname vašeho serveru
- `SSH_PORT` — SSH port na serveru (výchozí: 22)
- `SSH_USER` — uživatelské jméno na serveru
- `VIDEO_PORT` — Port serveru pro příjem video streamu z kamery (výchozí: 8080)
- `MOON_PORT` — Port serveru pro příjem dat z Moonrakeru (výchozí: 7125)
- `REMOTE_RUN` — Příkaz k provedení na vzdáleném serveru

Použití SSH spotřebuje přibližně 300 KB paměti.

**Pokud jsou tiskárna a server ve stejné síti, SSH není nutné. Viz konfigurační soubor [telegram.conf](https://github.com/ghzserg/z_ff5m/blob/1.7/telegram/telegram.conf).**
Konfigurační soubor lze stáhnout z tiskárny ze složky `mod/telegram/`. [Ukázková konfigurace](https://github.com/nlef/moonraker-telegram-bot/wiki/Sample-config)

---

### Registrace bota
Jak zaregistrovat svého bota:

1. Přejděte na [@BotFather](https://t.me/BotFather)
2. Pošlete `/newbot`
3. Zadejte libovolné jméno
4. Zadejte uživatelské jméno bota (musí končit na `_bot`, např. `ff5msuper_bot`)
5. Obdržíte dlouhé ID — přidejte jej do parametru `bot_token` v nastavení bota.

---
### Nasazení na server
#### Instalace Telegram bota na Debian jedním příkazem

Pokud potřebujete pouze notifikace v Telegramu, [použijte Notify plugin](https://github.com/ghzserg/notify/)

Nainstalujte Telegram bota [jedním příkazem](https://github.com/ghzserg/z_ff5m/blob/1.7/telegram/telegram.sh) na Debian:

Spusťte jako uživatel `root`:
```bash
bash <(wget --cache=off -q -O - https://github.com/ghzserg/zmod_ff5m/raw/refs/heads/1.7/telegram/telegram.sh)
```

Pokud není nainstalován `wget`:
```bash
apt update && apt install wget -y
```

Tento skript:

1. Nainstaluje Docker
2. Stáhne [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.7/telegram/docker-compose.yml) a [telegram.conf](https://github.com/ghzserg/z_ff5m/blob/1.7/telegram/telegram.conf) [Ukázková konfigurace](https://github.com/nlef/moonraker-telegram-bot/wiki/Sample-config)
3. Vytvoří uživatele `tbot`
4. Provede vás registrací bota a požádá o `bot_token`
5. Provede vás získáním `chat_id` a požádá o něj
6. Nainstaluje [ff5m.sh](https://github.com/ghzserg/z_ff5m/blob/1.7/telegram/ff5m.sh)

Přidejte SSH klíče ručně.

---
#### Instalace Telegram bota krok za krokem

Pokud potřebujete pouze notifikace v Telegramu, [použijte Notify plugin](https://github.com/ghzserg/notify/)

1. Zkopírujte [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.7/telegram/docker-compose.yml) z adresáře `mod/telegram/` na tiskárně.
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

4. Umístěte [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.7/telegram/docker-compose.yml) sem.

5. Vytvořte podadresáře:
```bash
mkdir config log timelapse_finished timelapse
chmod 777 config log timelapse_finished timelapse
```

6. Zkopírujte [telegram.conf](https://github.com/ghzserg/z_ff5m/blob/1.7/telegram/telegram.conf) z `mod/telegram/` do `config/` a upravte jej.

[Ukázková konfigurace](https://github.com/nlef/moonraker-telegram-bot/wiki/Sample-config)

Více o konfiguraci bota najdete [zde](https://github.com/nlef/moonraker-telegram-bot/wiki).

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
Po nastavení spusťte makro [ZSSH_ON](/cs/Zmod/#zssh_on) na tiskárně s požadovanými parametry.

SSH se automaticky restartuje 3 minuty po každém restartu.

#### Spoolman

Upravte soubor [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.7/telegram/docker-compose.yml).

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

Na tiskárně přidejte do `mod_data/user.moonraker.conf`:

`external_IP` — externí IP adresa serveru, na kterém běží Docker.

Tiskárna MUSÍ mít přístup k této IP.

```
[spoolman]
server: http://external_IP:7912
sync_rate: 5
```

#### Časové pásmo

Upravte soubor [docker-compose.yml](https://github.com/ghzserg/z_ff5m/blob/1.7/telegram/docker-compose.yml)

Zadejte své časové pásmo. V ukázkovém souboru je ```TZ=Asia/Yekaterinburg```

```docker-compose down && docker-compose up -d``` nebo ```docker compose down && docker compose up -d```

#### Instalace a nastavení pro Armbian (od noyhay)

Pokud potřebujete pouze notifikace v Telegramu, [použijte Notify plugin](https://github.com/ghzserg/notify/)

Stáhněte obraz Debian Minimal/IOT s Armbianem z webu [https://www.armbian.com/download/](https://www.armbian.com/download/)

Nainstalujte Armbian na SD kartu pomocí balenaEtcher z [https://etcher.balena.io/](https://etcher.balena.io/)

Spusťte systém, nastavte heslo uživatele root a vytvořte nového uživatele.

Pokračujte pod uživatelem root:
```
su - root
```

Nastavte Wi-Fi, pokud jste to neudělali při vytváření uživatele:
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
bash <(wget --cache=off -q -O - https://github.com/ghzserg/zmod_ff5m/raw/refs/heads/1.7/telegram/telegram.sh)
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
Vložte veřejný klíč ze souboru `mod_data/ssh.pub.txt`, poté stiskněte `Ctrl + D`.

Restartujte systém:
```
sudo reboot
```

---

#### Instalace Telegram bota na Kubernetes přes Helm (od aldiserg)

Pokud potřebujete pouze notifikace v Telegramu, [použijte Notify plugin](https://github.com/ghzserg/notify/)

Stáhněte a nainstalujte Helm: [https://helm.sh/docs/intro/install/](https://helm.sh/docs/intro/install/)

Naklonujte repozitář s Helm chartem:
```
git clone https://github.com/aldiserg/zmod_ff5m_tg_bot.git
```
Změny:

1. persistence.enabled změňte na "false", pokud neplánujete trvale ukládat časosběry

2. persistence.volumes...storageClass změňte, pokud budete používat externí úložiště

3. configMapAsFile.data.telegram.conf - hlavní konfigurační soubor; změňte v něm několik řádků:
   ```
   [bot]
   server: 3D_printer_host:7125
   bot_token: 1111111111:AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
   chat_id: 111111111

   [camera]
   host: http://3D_printer_host:8080/?action=stream
   host_snapshot: http://3D_printer_host:8080/?action=snapshot
   ```
Jak získat bot_token a chat_id viz [zde](/cs/Telegram/#registrace-bota)

Instalace:

Příkazy install/upgrade spouštějte ve složce s Helm chartem.
```
helm upgrade --install zmod_ff5m_tg_bot ./ -n default -f values.yaml
```

#### Řešení problému s připojením tiskárny k serveru přes SSH

Po přeinstalaci operačního systému serveru se změní jeho **SSH host klíče** a tiskárna se odmítne připojit s chybou:

```text
ssh-ed25519 host key mismatch ...
```

##### Řešení

###### 1. Vymazání uložených klíčů v tiskárně

Připojte se k tiskárně přes SSH:

```bash
ssh root@<IP_tiskárny> -p 22
```

Výchozí heslo:

```text
root
```

Poté spusťte:

```bash
cd ~/.ssh
rm -f know*
```

Tím se odstraní staré uložené host klíče serveru.

###### 2. Opětovné vytvoření páru SSH klíčů v tiskárně (v případě potřeby)

Pokud je potřeba vytvořit nový pár klíčů, odstraňte staré soubory:

```bash
cd ~/mod_data
rm -f ssh.pub.txt ssh.key
```

Po restartu služba automaticky vytvoří nové klíče. Veřejný klíč (`ssh.pub.txt`) bude nutné znovu přidat na server do souboru `~/.ssh/authorized_keys` uživatele, pod kterým připojení funguje (například `tbot`).

###### 3. Ověření připojení

Po vymazání klíčů v tiskárně a aktualizaci souboru `authorized_keys` na serveru spusťte na tiskárně makro ZSSH_ON. Připojení by nyní mělo fungovat bez chyby.


#### Alternativa k botu

Vzhledem k občasným výpadkům Telegramu je alternativou vytváření časosběrných videí na samostatném serveru (na stejném serveru, který se dříve používal pro Telegram bota).

Příklad najdete v repozitáři [printer_timelapse](https://github.com/seligor/printer_timelapse). Po několika drobných úpravách jej lze propojit s [web-timelapse](https://github.com/seligor/web-timelapse) a získat podobné funkce bez použití komunikační aplikace.

Základní postup: server sleduje, zda na tiskárně začal tisk, během tisku pořizuje snímky a po dokončení z nich vytvoří video a náhledový obrázek. Podporuje více tiskáren.

