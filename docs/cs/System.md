<h1 align="center">Systém</h1>

Makro je malý program napsaný v jazyce Klipper/Gcode.

Lze jej spustit z:

- GCODE souboru
- Konzole Fluidd/Mainsail (stiskněte anglické písmeno `C` ve Fluidd)

!!! poznámka
    *Hodnota v závorkách je výchozí hodnota*

---

### DISPLAY_ON

Zapne standardní obrazovku a restartuje tiskárnu.

---
### DISPLAY_OFF

- `GUPPY`: `0` = vypnout GuppyScreen, `1` = zapnout GuppyScreen (výchozí: `1`)

Vypne standardní obrazovku. Ušetří 13 MB RAM (20 MB u starších verzí firmwaru).

**GuppyScreen** (alternativní implementace obrazovky):

- Podporuje všechny funkce nativní obrazovky kromě konfigurace WiFi.
- Používá 9 MB RAM (oproti 23 MB u nativní obrazovky).
- Zabraňuje zamrzání Klipperu během restartů.
- Doporučeno pro pracovní postupy bez nativní obrazovky.
- Lepší obnova tisku po přerušeních.
- Založeno na [tomto forku](https://github.com/ghzserg/guppyscreen_ff5m).

**Varování:**

- Nevypínejte obrazovku, pokud plně nerozumíte nivelaci podložky, Z-offsetu a makrům `START_PRINT`/`END_PRINT`.
- Obrazovka zůstane aktivní 3 minuty po restartu, ale neovlivňuje Z-offset ani tisk.

Upravte čas aktivace pomocí globálního parametru [`DISPLAY_OFF_TIMEOUT`](Global.md#display_off_timeout).

[Zjistěte více o režimech obrazovky](FAQ.md#whats-the-difference-between-using-the-screen-and-without-the-native-screen).

---
### MEM

Zobrazí využití paměti.

---
### TEST_EMMC

Otestuje výkon a úroveň opotřebení EMMC.
Parametry:

- `SIZE` — velikost dat k zápisu v MB (výchozí: `100`).
- `SYNC` — `1` = synchronní režim (měření rychlosti), `0` = asynchronní zápis na pozadí (výchozí: `1`).
- `FLASH` — cílové úložiště: `0` = EMMC, `1` = USB flash, `2` = RAM (výchozí: `0`).
- `RANDOM` — použití náhodných dat: `1` = ano, `0` = ne (výchozí: `0`).

**Příkaz pro stock firmware:**
```bash
./zfs.sh 400 1
```

---
### CLEAR_EMMC

Vymaže úložiště EMMC.
Parametry:

- `LOG` — vymazat log soubory: `1` = ano, `0` = ne (výchozí: `1`).
- `ANY` — vymazat všechny soubory (G-code, obrázky, videa): `1` = ano, `0` = ne (výchozí: `0`).

---
### DATE_GET

Zobrazí aktuální systémový čas.

---
### DATE_SET

Nastaví datum a čas systému.

- `DT` — datum/čas ve formátu `YYYY.MM.DD-HH:MM:SS`.

---
### WEB

Přepíná mezi webovými rozhraními Fluidd a Mainsail.

Po spuštění makra:

- Stiskněte Ctrl + F5 nebo Ctrl + Shift + R nebo Option + Command + E
- Pokud máte problém v Orca, stiskněte Ctrl + F5 nebo Ctrl + Shift + R nebo Option + Command + E

Pokud používáte Mainsail, specifikujte pouze tyto velikosti náhledů: ```140x110/PNG, 64x64/PNG```

V Orca: `Printer Profile` -> `General Information` -> `Advanced` -> `G-Code Thumbnails`

Všimněte si, že nativní obrazovka již nebude zobrazovat náhledy.

Pozor! Autor používá Fluidd; Mainsail je testován pouze uživateli. Pokud máte s Mainsail problémy, vytvořte [ticket](Help.md)

---
### SET_TIMEZONE

Nastaví časové pásmo.

- `ZONE` — identifikátor časového pásma (výchozí: `Asia/Yekaterinburg`).

---
### CHECK_MD5

Igor Polunovskiy

Ověří integritu souboru pomocí kontrolního součtu MD5.

- `DELETE` — smazat poškozené soubory: `ano`/`ne`.

**Použití:**

1. Vyberte a stáhněte soubor pro vaši architekturu a operační systém:

- [zmod_preprocess-windows-amd64.exe](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-windows-amd64.exe) - Windows
- [zmod_preprocess-linux-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-linux-amd64) - Linux. Nezapomeňte spustit ```chmod +x zmod_preprocess-linux-amd64```
- [zmod_preprocess-darwin-arm64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-arm64) - MacOS (Intel). Nezapomeňte spustit ```chmod +x zmod_preprocess-darwin-arm64```
- [zmod_preprocess-darwin-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-amd64) - MacOS Silicon. Nezapomeňte spustit ```chmod +x zmod_preprocess-darwin-amd64```
- [zmod-preprocess.py](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.py) - General-Python. Nezapomeňte spustit ```chmod +x zmod-preprocess.py```
- [zmod-preprocess.sh](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.sh) - Linux/MacOS Bash. Nezapomeňte spustit ```chmod +x zmod-preprocess.sh```

2. V Orca musíte specifikovat: `Process Profile` -> `Other` -> `Post Processing Scripts`.

Zde jsou možnosti přidání:

- ```"С:\path_to_file\zmod_preprocess-windows-amd64.exe";```
- ```"C:\python_folder\python.exe" "C:\Scripts\zmod-preprocess.py";```
- ```"/usr/bin/python3" "/home/user/zmod-preprocess.py";```
- ```"/home/user/zmod-preprocess.py";```
- ```"/home/user/zmod_preprocess-darwin-amd64";```
- ```"/home/user/zmod_preprocess-darwin-arm64";```
- ```"/home/user/zmod_preprocess-linux-amd64";```

3. Přidejte `CHECK_MD5` nebo `CHECK_MD5 DELETE=true` do vašeho startovacího G-code.

**Poznámka:** Ve výchozím nastavení povoleno pomocí [`FORCE_MD5`](Global.md#force_md5).

---
### UPDATE_MCU

Aktualizuje MCU tiskárny.

Změní firmware MCU z nativní verze Klipperu (11 pro FF5M/FF5MPRO, 12 pro AD5X) na Klipper 13 a zpět.

Klipper 13 (ve výchozím nastavení zakázán).

Parametr FORCE:

- 11 - načte firmware Klipper 11 - FF5M
- 12 - načte firmware Klipper 12 - AD5X
- 13 - načte firmware Klipper 13

Bez parametrů změní firmware na opačnou verzi.

Příklad: `UPDATE_MCU FORCE=13` vynutí stažení firmwaru Klipper 13.

Pokud nerozumíte, jak [obnovit konfigurace a firmware MCU](Native_FW.md#installing-full-firmware-on-ad5x), nespouštějte tento příkaz.

Pokud se něco pokazí, jediná cesta zpět je přes [tovární nastavení](Native_FW.md).

---

### RESET_PASSWD

Nastaví heslo root pro ssh na root

---
### CHECK_SYSTEM

Diagnostikuje integritu souborů OS.

- `RESTORE` — `0` = bez opravy, `1` = opravit poškozené soubory (výchozí: `0`).

Kontroly:

- Oprávnění souborů/MD5 hashe.
- Oprávnění adresářů.
- Symbolické odkazy.

**Obnova:** Stáhněte neporušené soubory z [tohoto odkazu](https://github.com/ghzserg/FF/tree/main/stock).

---

### SCREEN

Pořídí snímek obrazovky tiskárny

Fotografie bude uložena v ```mod_data/screen.jpg```
