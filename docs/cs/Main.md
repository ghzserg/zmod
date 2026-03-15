<h1 align="center">Hlavní</h1>

Makro je malý program napsaný v jazyce Klipper/Gcode.

Lze jej vyvolat z:

- Souboru GCODE
- Konzoly Fluidd/Mainsail (stiskněte písmeno `C` v Fluiddu)

!!! note
    *Hodnota v závorkách je výchozí hodnota*

---

### START_PRINT

Nahradí výchozí spouštěcí G-code.
**Pro tiskárny s nativní obrazovkou** přidejte `M140`/`M190 S[bed_temp]` a `M109`/`M104 S[nozzle_temp]`.

Parametry:

- `EXTRUDER_TEMP` — teplota extrudéru (výchozí: `245`)
- `BED_TEMP` — teplota podložky (výchozí: `80`)
- `MESH` — název profilu síťě podložky (prázdné = žádná síť načtená/vytvořená)
- `FORCE_LEVELING` — vynutit vyrovnání podložky (výchozí: `False`)
- `SKIP_LEVELING` — úplně přeskočit vyrovnání podložky (přepíše `FORCE_KAMP`/`FORCE_LEVELING`, výchozí: `False`)
- `FORCE_KAMP` — vytvořit adaptivní síť podložky (KAMP, výchozí: `False`).
  *Doporučuje se přidat `SAVE_ZMOD_DATA CLEAR=LINE_PURGE` pro použití čisticích oblastí pro KAMP.*

- `Z_OFFSET` — nastavit Z offset (výchozí: `0.0`)
- `INTERNAL` - Pro verzi PRO při provozu bez nativní obrazovky, 1 - povolit vnitřní recirkulaci (0)
- `EXTERNAL` - Pro verzi PRO při provozu bez nativní obrazovky, 1 - povolit externí recirkulaci (0)

**Poznámky:**

- Jakákoli kalibrace (např. `FORCE_KAMP`/`FORCE_LEVELING`) spustí [CLEAR_NOZZLE](Global.md#clear_nozzle).
- `[ZSSH_RELOAD](Zmod.md#zssh_reload)` se volá během `START_PRINT` pro obnovení SSH, pokud je potřeba.

**Příklad pro Orca Slicer s nativní obrazovkou:**
Nahraďte spouštěcí G-code s:
```gcode
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single]
M104 S[nozzle_temperature_initial_layer]
```

**Příklad pro Orca Slicer bez nativní obrazovky:**
```gcode
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
```

**Sledování vrstvy ve Fluiddu:**
Přidejte do spouštěcího G-code:
```gcode
SET_PRINT_STATS_INFO TOTAL_LAYER=[total_layer_count]
```
Přidejte do G-code pro změnu vrstvy:
```gcode
SET_PRINT_STATS_INFO CURRENT_LAYER={layer_num + 1}
```

[Možnosti vyrovnání podložky](FAQ.md#what-options-are-available-for-bed-leveling)

---

#### Globální příznaky (nastavte pomocí [`SAVE_ZMOD_DATA`](Global.md#start_print)):

- `PRECLEAR` — předčištění trysky v `CLEAR_NOZZLE`: `0` = vypnout, `1` = zapnout (výchozí: `0`).
- `CLEAR` — metoda čištění trysky (`LINE_PURGE`).
- `PRINT_LEVELING` — povolit vyrovnání podložky pro každý tisk: `0` = vypnout, `1` = zapnout (výchozí: `0`).
- `USE_KAMP` — použít adaptivní síť podložky (KAMP), kde je to možné: `0` = vypnout, `1` = zapnout (výchozí: `0`).
- `DISABLE_PRIMING` — vypnout přípravu (priming) trysky: `0` = zapnout, `1` = vypnout (výchozí: `0`).
- `FORCE_MD5` — ověřit MD5 hashe souborů (výchozí: `1`).
    1. Vyberte a stáhněte soubor pro vaši architekturu a operační systém:

    - [zmod_preprocess-windows-amd64.exe](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-windows-amd64.exe) - Windows
    - [zmod_preprocess-linux-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-linux-amd64) - Linux. Nezapomeňte spustit `chmod +x zmod_preprocess-linux-amd64`
    - [zmod_preprocess-darwin-arm64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-arm64) - MacOS (Intel). Nezapomeňte spustit ```chmod +x zmod_preprocess-darwin-arm64```
    - [zmod_preprocess-darwin-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-amd64) - MacOS (Apple Silicon). Nezapomeňte spustit ```chmod +x zmod_preprocess-darwin-amd64```
    - [zmod-preprocess.py](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.py) - Obecný Python. Nezapomeňte spustit ```chmod +x zmod-preprocess.py```
    - [zmod-preprocess.sh](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.sh) - Linux/MacOS Bash. Nezapomeňte spustit ```chmod +x zmod-preprocess.sh```
    
    2. V Orca Sliceru musíte zadat: `Process Profile` -> `Other` -> `Post Processing Scripts`.
    
    Zde jsou možnosti pro přidání:
    
    - ```"C:\cesta_k_souboru\zmod_preprocess-windows-amd64.exe";```
    - ```"C:\slozka_pythonu\python.exe" "C:\Skripty\zmod-preprocess.py";```
    - ```"/usr/bin/python3" "/home/user/zmod-preprocess.py";```
    - ```"/home/user/zmod-preprocess.py";```
    - ```"/home/user/zmod_preprocess-darwin-amd64";```
    - ```"/home/user/zmod_preprocess-darwin-arm64";```
    - ```"/home/user/zmod_preprocess-linux-amd64";```

- `DISABLE_SKEW` — vypnout korekci zkosení (skew): `1` = vypnout, `0` = načíst `skew_profile` (výchozí: `1`).
- `AUTO_REBOOT` — automatický restart po tisku: `0` = vypnout, `1` = zapnout, `2` = restart firmwaru (výchozí: `0`).
- `CLOSE_DIALOGS` — automatické zavírání dialogů: `0` = vypnout, `1` = pomalé, `2` = rychlé (vyžaduje povolení "Pouze místní síť" na obrazovce tiskárny).
- `STOP_MOTOR` — vypnutí motorů po tisku: `0` = vypnout, `1` = zapnout (výchozí: `1`).
- `MIDI_START` — MIDI soubor k přehrání na začátku tisku (např. `"start.mid"`).
- `MIDI_END` — MIDI soubor k přehrání na konci tisku.

---

#### Logika vyrovnávání podložky:

1. Načte síť z `MESH`, pokud je zadána.
2. Přeskočí vyrovnávání, pokud `SKIP_LEVELING = True`.
3. Vytvoří KAMP síť, pokud `FORCE_KAMP = True`.
4. Vytvoří plnou síť, pokud není žádná síť načtena nebo `FORCE_LEVELING = True`.

---
### END_PRINT

Nahradí výchozí koncový G-code.

#### Globální příznaky (nastavte pomocí [`SAVE_ZMOD_DATA`](Global.md#end_print)):

- `AUTO_REBOOT` — automatický restart po tisku (stejné jako výše).
- `CLOSE_DIALOGS` — automatické zavírání dialogů (stejné jako výše).
- `STOP_MOTOR` — vypnutí motorů po tisku (stejné jako výše).
- `MIDI_END` — MIDI soubor k přehrání na konci tisku.

---
### _USER_START_PRINT

Vlastní makro pro uživatelsky definované akce na začátku tisku.

Toto makro je automaticky voláno na konci makra `START_PRINT`. Použijte jej k rozšíření standardního procesu inicializace tisku o vlastní příkazy.

**Běžné případy použití:**

- Přidání vlastních příkazů pro ohřev nebo kalibraci
- Provedení dalšího nastavení před zahájením tisku
- Zapnutí/vypnutí zařízení (ventilátory, senzory atd.)
- Přidání vlastního čištění trysky nebo jiné přípravy

**Příklad přepsání v `mod_data/user.cfg`:**
```gcode
[gcode_macro _USER_START_PRINT]
gcode:
    # Povolit další ventilátor
    SET_PIN PIN=my_fan VALUE=1
    # Nějaký vlastní příkaz
    G4 P1000  ; pauza na 1 sekundu
    # Další vlastní akce
```

**Poznámka:** Ve výchozím stavu je toto makro prázdné a uživatel si jej může přepsat podle svých potřeb.

---
### _USER_END_PRINT

Vlastní makro pro uživatelsky definované akce na konci tisku.

Toto makro je automaticky voláno na konci makra `END_PRINT`. Použijte jej k rozšíření standardního procesu dokončení tisku o vlastní příkazy.

**Běžné případy použití:**

- Provedení dalších akcí po dokončení tisku
- Vypnutí dalších zařízení
- Uložení statistik nebo logů
- Spuštění vlastních rutin čištění nebo údržby

**Příklad přepsání v `mod_data/user.cfg`:**
```gcode
[gcode_macro _USER_END_PRINT]
gcode:
    # Vypnout další ventilátor
    SET_PIN PIN=my_fan VALUE=0
    # Odeslat oznámení
    M118 Tisk dokončen!
    # Nebo jiné vlastní příkazy
```

**Poznámka:** Ve výchozím stavu je toto makro prázdné a uživatel si jej může přepsat podle svých potřeb.

---
### CANCEL

Zruší aktuální tisk.

---
### CLEAR_NOZZLE

Čištění trysky (jako ve standardním firmwaru).
Parametry:

- `EXTRUDER_TEMP` — teplota extrudéru (výchozí: `230`)
- `BED_TEMP` — teplota podložky (výchozí: `80`)

*`PRECLEAR` (nastaveno pomocí `SAVE_ZMOD_DATA PRECLEAR=1`) povoluje předčištění. [Zjistit více](Global.md#save_zmod_data).*

---
### LED_ON

Zapne LED osvětlení.

---
### LED_OFF

Vypne LED osvětlení.

---
### LED

Nastaví jas LED.

- `S` — procento jasu (výchozí: `50`).

---
### PAUSE

Pozastaví tisk.

---
### RESUME

Obnoví tisk po pozastavení.

---
### PLAY_MIDI

Přehraje MIDI soubor.

- `FILE` — název souboru (výchozí: `For_Elise.mid`). Soubory jsou uloženy v `mod_data/midi/`.

---
### REBOOT

Restartuje tiskárnu.

---
### CLOSE_DIALOGS

Zavře dialogy na nativní obrazovce (pomalá metoda).
*Může způsobit zamrznutí tiskárny.*
Ovládáno globálním parametrem [`CLOSE_DIALOGS`](Global.md#close_dialogs).

---
### FAST_CLOSE_DIALOGS

Rychle zavře dialogy (doporučeno).
*Povolte "Pouze místní síť" v nastavení tiskárny: **Nastavení → Ikona WiFi → Režim sítě → Přepnout "Pouze místní síť"**.*
Ovládáno globálním parametrem [`CLOSE_DIALOGS`](Global.md#close_dialogs).

---
### NEW_SAVE_CONFIG

Spustí `SAVE_CONFIG` bez zamrznutí nativní obrazovky.
*Může trvat ~1 minutu a občas způsobit grafické chyby na obrazovce.*

---
### SHUTDOWN

Vypne tiskárnu.
