<h1 align="center">Zmod</h1>

Makro je malý program napsaný v jazyce Klipper/Gcode.

Lze jej spustit z:

- GCODE souboru
- Konzole Fluidd/Mainsail (stiskněte anglické písmeno `C` ve Fluidd)

!!! poznámka
    *Hodnota v závorkách je výchozí hodnota*

---

### CAMERA_ON

Zapne alternativní implementaci kamery.
Parametry:

- `WIDTH` — šířka obrázku (výchozí: `640`)
- `HEIGHT` — výška obrázku (výchozí: `480`)
- `FPS` — snímky za sekundu (výchozí: `20`)
- `VIDEO` — video zařízení (výchozí: `video0`)
- `FS` — `1` = zapnout omezovač velikosti snímků pro nestabilní kamery, `0` = vypnout (výchozí: `0`)
- `STREAMER` - jaký streamer použít (auto, mjpg_streamer, ustreamer)
- `FORMAT` - Formát obrázku pro ustreamer: YUYV, YVYU, UYVY, RGB565, RGB24, BGR24, MJPEG, JPEG; výchozí: MJPEG

*Vypněte kameru na obrazovce tiskárny před zavoláním tohoto makra.*

Chcete-li kameru zapnout, použijte ```CAMERA_ON VIDEO=video0``` nebo ```CAMERA_ON VIDEO=video3``` nebo ```CAMERA_ON VIDEO=video99```.

<img width="734" height="221" alt="{D2A001DD-7C89-4AB9-9CB9-741B7007B0B4}" src="https://github.com/user-attachments/assets/e8ddbbd3-ebbf-4b4e-86cc-2a62365a4a88" />

Pokud kamera nefunguje, podívejte se na logy `mod_data/log/cam`

Spotřeba RAM pro základní kamery:

- 640x480: 2,9 MiB
- 1280x720: 7,8 MiB
- 1920x1080: 18,1 MiB

*Mnoho kamer z AliExpressu/Ozonu/Wildberries vždy spotřebuje 18 MiB.*

!!! poznámka

    - [Co je alternativní kamera?](FAQ.md#what-is-an-alternative-camera)
        - [Nainstaloval jsem tiskárnu a ZMOD skryl mou kameru! Viděl jsem ji v Orca-FF a nyní je pryč!](FAQ.md#i-installed-the-printer-but-zmod-hid-my-camera-in-orca-ff-i-could-see-it-but-now-its-gone)

`Camera Off Waiting...` - tato zpráva se zobrazí, pokud stream kamery není ještě k dispozici. Kamera se spustí po spuštění Klipperu během zobrazení informací o globálních nastaveních.

#### Nastavení kamery

**Základní parametry**

| Parametr | Popis | Výchozí hodnota |
|---|---|---|
| `WIDTH` | Šířka obrázku | 640 |
| `HEIGHT` | Výška obrázku | 480 |
| `FPS` | Snímky za sekundu | 20 |
| `VIDEO` | Zařízení kamery | video0 |
| `FS` | Oprava problematických kamer (1 – ano, 0 – ne) | 0 |
| `STREAMER` | Program pro zpracování streamu kamery | auto |
| `FORMAT` | Formát obrázku (pouze pro ustreamer) | MJPEG |

**Co je to streamer?**

Streamer je program, který vezme obraz z kamery a zobrazí jej v prohlížeči.

**Jsou k dispozici dvě možnosti:**

- **mjpg_streamer** – jednoduchý program, funguje pouze s MJPG kamerami
- **ustreamer** – výkonnější ale spotřebuje více paměti; podporuje různé kamery

Parametr `STREAMER=auto` automaticky zvolí vhodný streamer.

**Formáty obrázků (pouze pro ustreamer)**

Můžete si vybrat: YUYV, YVYU, UYVY, RGB565, RGB24, BGR24, MJPEG, JPEG.

Výchozí je MJPEG.

**Příklady příkazů**

Jednoduchý start kamery video0 přes mjpg_streamer:
```
CAMERA_ON VIDEO=video0
```

Start kamery video0 přes ustreamer s vlastním nastavením:
```
CAMERA_ON VIDEO=video0 STREAMER=ustreamer FORMAT=YUYV WIDTH=640 HEIGHT=480
```

**Kde se dívat na obrázek?**

Otevřete v prohlížeči: `http://printer_ip_address:8080`

Tam můžete upravit jas, kontrast a další nastavení.

**Řešení problémů**

Kamera není detekována?
Spusťte:
```
CAMERA_ON VIDEO=video99
```
Program zobrazí seznam dostupných kamer.

**Logy (záznamy chyb)** se nacházejí v adresáři: `log/cam/`

---
### CAMERA_OFF

Vypne alternativní implementaci kamery.

---
### CAMERA_RESTART

Restartuje alternativní implementaci kamery.

---
### REMOVE_ZMOD

Odinstaluje Zmod.

- `FULL`: `0` = zachovat `/opt/config/mod_data`, `1` = smazat `/opt/config/mod_data` (výchozí: `0`)

Adresář `/opt/config/mod_data` ukládá konfigurace pro `zmod`, `fluidd`, `moonraker` a `mainsail`.
Ve výchozím nastavení není smazán, aby se zabránilo náhodné ztrátě dat.

Varování! Sami deaktivujte všechny pluginy a přejděte na nativní Klipper.

---
### SKIP_ZMOD

Restartuje do původního systému bez Zmod.
Deaktivuje konfigurace Zmod, Moonraker a Fluidd.

Varování! Sami deaktivujte všechny pluginy a přejděte na nativní Klipper.

Zůstane aktivní:

- Alternativní kamera
- SSH

---
### TAR_CONFIG

Zálohuje konfigurační soubory do archivu.
Stáhněte archiv přes: **Configuration → mod_data → config.tar.gz**

---
### RESTORE_TAR_CONFIG

Obnoví konfigurace z archivu `config.tar.gz`.
Nahrát archiv na: **Configuration → mod_data → config.tar.gz**

---
### ZFLASH

Aktualizuje firmware přes síť pomocí USB disku.

1. Vložte USB disk do tiskárny a zapněte ji.
2. Pokud používáte bez nativní obrazovky, ujistěte se, že je USB vložen **před** zapnutím.
3. Toto makro kontroluje nejnovější vydání, stáhne jej na USB, ověří MD5 hash a nainstaluje jej po restartu.

---

### STOP_ZMOD

Vyčistí guppy, moonraker a fluidd/Mainsail z paměti. Telegram bot také přestane fungovat.

Parametry:

- GUPPY (0 - nevyčišťovat, 1 - vyčistit)
- MOONRAKER (0 - nevyčišťovat, 1 - vyčistit)
- HTTP (0 - nevyčišťovat, 1 - vyčistit)

Příklad:
```
STOP_ZMOD GUPPY=1 MOONRAKER=0 HTTP=0
```

Pokud je tento řádek přidán do startovacího kódu, bude GUPPY vyčištěn z paměti po zahájení tisku.

---

### START_ZMOD

Znovu zapne guppy, moonraker a fluidd/Mainsail po STOP_ZMOD.

Parametry:

- GUPPY (0 - nenačíst, 1 - načíst)
- MOONRAKER (0 - nenačíst, 1 - načíst)
- HTTP (0 - nenačíst, 1 - načíst)

Příklad:
```
START_ZMOD GUPPY=1 MOONRAKER=0 HTTP=0
```

Pokud je tento řádek přidán do koncového kódu, bude GUPPY spuštěn po dokončení tisku.

---
### ZSSH_ON

Zapne SSH tunelování.
Parametry:

- `SSH_SERVER` — IP/hostname vzdáleného SSH serveru
- `SSH_PORT` — SSH port (výchozí: `22`)
- `SSH_USER` — uživatelské jméno vzdáleného serveru
- `VIDEO_PORT` — port vzdáleného serveru pro video streaming (výchozí: `8080`)
- `MOON_PORT` — port vzdáleného serveru pro Moonraker (výchozí: `7125`)
- `REMOTE_enN` — příkaz k provedení na vzdáleném serveru (výchozí: `"NONE"`).
  Příklad: Použijte `./ff5m.sh bot1` (umístěno v `mod/telegram/`) pro restart Telegram bota.

**Skript nastavení (pokud není nainstalován jedním příkazem):**
```bash
su - tbot  # Přepněte na uživatele bot service
wget --cache=off -q -O ff5m.sh https://raw.githubusercontent.com/ghzserg/zmod_ff5m/main/telegram/ff5m.sh
chmod +x ff5m.sh
```

**Příklad použití v konzoli Fluidd/Mainsail:**
```
ZSSH_ON SSH_SERVER=remote.server.ru SSH_PORT=22 SSH_USER=tbot VIDEO_PORT=8080 MOON_PORT=7125 REMOTE_enN="./ff5m.sh bot1"
```

SSH se spustí 3 minuty po startu Klipperu a automaticky se restartuje na začátku tisku (přes makro `START_PRINT`).

[Detaily o Telegram bot](Telegram.md)

---
### ZSSH_OFF

Vypne SSH klienta.

---
### ZSSH_RESTART

Restartuje SSH klienta.

---
### ZSSH_RELOAD

Znovu načte SSH klienta, pokud neběží.
Toto makro se spouští na začátku tisku (přes `START_PRINT`).

---
### ZRESTORE

Obnoví tisk po výpadku napájení nebo chybách tiskárny.

**Požadavky:**

- Nativní obrazovka musí být vypnutá (nativní obnovení je v konfliktu se ZRESTORE).
- Název tisknutého souboru **nesmí začínat číslem**.

---

### ZLINK

Připojí se ke cloudu [zmod.link](https://zmod.link/link/)

- Cloud vám umožní spravovat tiskárnu přes Fluidd nebo Mainsail odkudkoliv.
- Spotřeba paměti na tiskárně se zvýší o 1 MB.
- Data se odesílají z tiskárny do cloudu pomocí šifrování.
- Přístup do cloudu odkudkoliv také používá šifrování.
- Uživatel vidí pouze své vlastní tiskárny a nemůže se připojit k ostatním.
- Přístup k tiskárnám uživatele je chráněn přihlášením a heslem

Jak získat přihlášení a heslo:

1. Připojte se na bot [@zmod_help_bot](https://t.me/zmod_help_bot)
2. Zadejte příkaz ```cloud``` - pokud jste se zaregistrovali dříve, řekne vám vaše přihlášení
3. Chcete-li zaregistrovat uživatele se jménem `test`, zadejte: ```cloud register test```
4. Chcete-li resetovat heslo, zadejte: ```cloud reset_password```

Jak se připojit ke cloudu [zmod.link](https://zmod.link/link/):

1. Navštivte web [zmod.link](https://zmod.link/link//) a zadejte vaše přihlášení a heslo

   <img width="547" height="615" alt="{264D6782-600F-4700-B9D2-0582F7427FD2}" src="https://github.com/user-attachments/assets/d8d3f51e-4fc7-4e1e-8fa7-dfc07ddbeab2" />

2. Klikněte na tlačítko "Add Printer"

   <img width="569" height="502" alt="image" src="https://github.com/user-attachments/assets/72346ee6-dde6-4736-80b1-2eb2927bf983" />

3. Otevřete tiskárnu v samostatné kartě a v konzoli tiskárny zadejte příkaz ```ZLINK```

   <img width="1563" height="163" alt="{90DC4366-D258-4912-8028-22C589DF4E91}" src="https://github.com/user-attachments/assets/bee350ee-8d99-465c-9621-48788c6f7a9c" />

4. Zkopírujte klíč do schránky - je zvýrazněn na snímku
5. Zadejte jméno tiskárny a klíč, který jste zkopírovali v předchozím kroku

   Příklad:

   - `testprinter`
       - `ecdsa-sha2-nistp256 AAAAE2VjZHNhLXNoYTItbmlzdHAyNTYAAAAIbmlzdHAyNTYAAABBBDxX5XzNDXg+sbTArdiOzFpMtHXzgAhfC2N2ogS4TUsQYV4AD6HfSFL3J4ISNZ2DgesZf35rfH1I/qI2ckQVGlE=`

   <img width="557" height="775" alt="{E4FC2206-84BC-4134-92C2-B4253D8F23E5}" src="https://github.com/user-attachments/assets/b6401b71-5827-480d-ba1c-b7114f87177b" />

   Klikněte na tlačítko "Add Printer"

6. Zkopírujte příkaz poskytnutý webem a vložte jej do konzoly tiskárny

   <img width="558" height="652" alt="{CDC8146F-B9DF-44A1-9C0B-3E6828CD540E}" src="https://github.com/user-attachments/assets/ed92a80f-93cc-41b8-bde1-aa0b2b2c0ecc" />

   V příkladu: ```zlink p=testprinter u=test m=10006 c=30006```

   Klikněte na tlačítko ```Již jsem vložil řetězec do tiskárny```

   Poté bude tiskárna schopna se připojit ke cloudu.

   Chcete-li zakázat připojení, zadejte ```ZLINK_OFF```

7. Nyní máte schopnost se připojit k Fluidd nebo Mainsail přes internet

   <img width="526" height="654" alt="{CA6FC599-6060-4E3B-B525-EBB76D8780A1}" src="https://github.com/user-attachments/assets/0208dbad-8627-4636-b971-cfe0c5d7f8bd" />

   Stačí vybrat požadované tlačítko.

PS: Kamera se může načíst později než rozhraní - je to normální

PPS: Pokud něco nefunguje správně, obnovte stránku pomocí Ctrl + F5 a přejděte na [zmod.link](https://zmod.link/link/)

   <img width="540" height="449" alt="{30D01CA4-3E9E-40EC-BCD1-9A8597DCCFDE}" src="https://github.com/user-attachments/assets/0d48b9be-a9df-4bfd-a38a-6d883ab31e73" />

   <img width="500" height="393" alt="{D03D643F-907C-4A6D-A48E-D881AAC33268}" src="https://github.com/user-attachments/assets/69f9d8d5-67ca-476e-b362-e35abb1d4832" />
