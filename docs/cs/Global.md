<h1 align="center">Globální parametry</h1>

Makro je malý program napsaný v jazyce Klipper/Gcode.

Lze jej spustit z:

- Souboru GCODE
- Konzole Fluidd/Mainsail (stiskněte anglické písmeno `C` ve Fluidd)

!!! note
    *Hodnota v závorkách je výchozí hodnota*

---

### LANG

Nastavte jazyk pro provoz ZMOD.

- LANG - jazyk: en (angličtina), ru (ruština), de (němčina), fr (francouzština), it (italština), es (španělština), zh (čínština), ja (japonština), ko (korejština), pt (portugalština), cs (čeština), tr (turečtina)

Příklad:
```
LANG LANG=en
```

---
### SET_TIMEZONE

Změna časového pásma.

- ZONE - časové pásmo (např. Europe/Prague)

---
### NOZZLE_CONTROL

Kontrola kolize trysky s podložkou nebo oddělení dílu.

Nouzové vypnutí, pokud hmotnost překročí nastavený limit.

- WEIGHT - hmotnost v gramech (1500)

Nastavení přetrvávají i po restartu.

Nastavte `NOZZLE_CONTROL WEIGHT=0` pro vypnutí této funkce.

*Kontrola je vypnutá, dokud není makro poprvé spuštěno.*

Při použití nativní obrazovky restartuje spuštění makra tiskárnu.

Bez nativní obrazovky restartuje Klipper (jsou upraveny konfigurační soubory).

Funguje automaticky, ale pro Gcode jsou k dispozici další makra:

- `ZCONTROL_ON` - povolit kontrolu
- `ZCONTROL_OFF` - zakázat kontrolu
- `ZCONTROL_STATUS` - zkontrolovat stav
- `ZCONTROL_PAUSE` - pozastavit při spuštění (pouze po vyprázdnění fronty příkazů; nepoužívejte na počátečních vrstvách)
- `ZCONTROL_ABORT` - přerušit Klipper při spuštění
- `ZCONTROL_AUTO` - Při spuštění zastaví Klipper (pokud je výška Z < `ZCONTROL_Z`) nebo zavolá PAUSE, pokud je z >= `ZCONTROL_Z`
- `ZCONTROL_Z Z=10` - Nastavit výšku Z.
- `SAVE_ZMOD_DATA ZCONTROL_Z=10` - Uložit výšku Z. Pokud nechcete povolit pauzu, nastavte `SAVE_ZMOD_DATA ZCONTROL_Z=230`

Pro povolení kontroly trysky na počátečních vrstvách přidejte `ZCONTROL_PAUSE` ve sliceru na požadované vrstvě.

---

### GET_ZMOD_DATA

Získat globální parametry/příznaky ZMOD.
Po spuštění se v konzoli zobrazí uložené parametry aplikované za běhu.

`Fluidd` -> `Makra` -> `Hlavní` -> `ZMOD PARAMETRY`

---

### GLOBAL

Zjednodušená správa globálních parametrů. K dispozici jsou pouze parametry, které lze změnit kliknutím na tlačítko. Parametry, které vyžadují zadání čísla, názvu souboru atd., nejsou tímto makrem ovládány.

Po změně parametrů se doporučuje restartovat tiskárnu.

---

### SAVE_ZMOD_DATA

Uložit globální parametry/příznaky ZMOD (aplikují se při každém tisku).

Nepřidávejte toto makro do startovního/koncového G-kódu nebo do souborů G-kódu. Spouštějte ho z konzole Fluidd/Mainsail. Parametry se ukládají do `mod_data/variables.cfg` po vypnutí (**neupravujte ručně**).

**Pro úpravu parametrů:**

- Přejděte do `Fluidd` -> `Makra` -> `Systém` -> `SAVE ZMOD PARAMETERS`, vyberte parametr, upravte ho a klikněte na `SEND`.
- Alternativně zadejte příkazy přímo do konzole Fluidd, např. `SAVE_ZMOD_DATA CLOSE_DIALOGS=2`.

[Zobrazit uložené parametry](#get_zmod_data)

---

### Parametry nabídky výběru barvy tisku ###

**Všechny parametry nabídky výběru barvy jsou pouze pro AD5X.**

##### ALLOWED_TOOL_COUNT

Počet nástrojů, které se mají zobrazit v nabídce výběru barvy. Týká se to příkazů T0, T1 atd. v souboru gcode, nikoli fyzických cívek ve vašem IFS.

Pokud zMod dokáže úspěšně prohledat soubor pro použité nástroje, toto bude přepsáno a zobrazí se nástroje použité v souboru.

Toto nastavení nelze použít, když je povolena nativní obrazovka.

[Viz předzpracování](https://wiki.zmod.link/Recomendations/#enable-md5-checksum-control)

Příklad: `SAVE_ZMOD_DATA ALLOWED_TOOL_COUNT=4`

##### SCAN_FILE_COLORS

Povolí prohledávání gcode souborů pro zjištění, které příkazy pro změnu nástroje (T0, T1 atd.) jsou použity a na jaké barvy a materiály jsou ve sliceru namapovány: 0 (zakázat), 1 (povolit), 2 (zakázat úplné prohledávání, ale hledat data připravená skriptem sliceru)

[Viz předzpracování](https://wiki.zmod.link/Recomendations/#enable-md5-checksum-control)

Příklad: `SAVE_ZMOD_DATA SCAN_FILE_COLORS=0`

##### COLOR_MENU_1_BASED

Určuje, zda se mají v nabídce výběru barvy zobrazovat popisky založené na 0 (T0, T1 atd.) nebo na 1 (Barva 1, Barva 2 atd.). Nemění to nic jiného než způsob označení tlačítek a je to čistě pro pohodlí: 0 (založené na 0), 1 (založené na 1)

Příklad: `SAVE_ZMOD_DATA COLOR_MENU_1_BASED=1`

##### AUTO_ASSIGN_COLORS

Určuje, zda se má pokusit o automatické mapování příkazů pro změnu nástroje (T0, T1 atd.) na fyzický filament vložený ve vašem IFS při zahájení tisku. Pokud jste nepovolili tichý režim, nabídka výběru barvy se stále objeví; toto nastavení ovlivňuje pouze výchozí výběry: 0 (zakázat), 1 (povolit)

Toto nastavení se bude vztahovat i na tisky spuštěné v tichém režimu. Můžete ho nakonfigurovat tak, aby přerušil tisk, pokud se vyskytnou určité chyby s automatickým přiřazením: 2 (přerušit, pokud nelze spárovat žádný materiál, povolit nesoulad barev), 30 (přerušit při jakýchkoli problémech)

Pro vlastní hodnoty pro chybové stavy v tichém režimu sečtěte následující hodnoty, abyste určili správné nastavení:

* 2 (Alespoň jeden materiál nelze spárovat; např. gcode soubor specifikuje ABS, ale máte vložený pouze PLA; nebo data o materiálu nelze načíst)
* 4 (Alespoň jednu barvu nelze vůbec spárovat, obvykle kvůli zakázanému nebo neúspěšnému prohledávání souborů)
* 8 (Alespoň jedna barva je potenciálně špatně spárována)
* 16 (Alespoň jedna fyzická cívka byla přiřazena k více než jednomu indexu nástroje v souboru)

[Viz předzpracování](https://wiki.zmod.link/Recomendations/#enable-md5-checksum-control)

Příklad: `SAVE_ZMOD_DATA AUTO_ASSIGN_COLORS=0`

### Parametry startu tisku/mapování podložky [START_PRINT]:

##### MIDI_START

Přehrát MIDI při startu tisku (""), 0 pro zakázání.

Příklad: `SAVE_ZMOD_DATA MIDI_START=Pain-Shut-your-mouth.mid`

---
##### PRECLEAR

Povolit předčištění trysky v CLEAR_NOZZLE: 0 (ne), 1 (ano) (0).

Příklad: `SAVE_ZMOD_DATA PRECLEAR=0`

---
##### PRINT_LEVELING

Vytvořit mesh podložky před každým tiskem (pomocí nativní obrazovky, pokud je povolena): 0 (ne), 1 (ano) (0).
*Pro vyrovnávání podložky pomocí nativní obrazovky povolte "Pouze lokální síť" přes menu tiskárny: Nastavení -> Ikona WiFi -> Síťový režim.*

Příklad: `SAVE_ZMOD_DATA PRINT_LEVELING=1`

---
##### USE_KAMP

Použít adaptivní mesh (KAMP) místo plného meshe podložky, kde je to možné: 0 (ne), 1 (ano) (0).
Doporučuje se nastavit `SAVE_ZMOD_DATA CLEAR=LINE_PURGE`, aby se umístění čištění shodovalo s KAMP meshem.

Příklad: `SAVE_ZMOD_DATA USE_KAMP=1`

---

##### MESH_TEST

Testovat mesh podložky před tiskem:

- 0 - Ne
- 1 - Test BEZ automatického ladění Z-Offsetu (výchozí)
- 2 - Test BEZ automatického ladění Z-Offsetu, pokud se mesh neshoduje, spustí se KAMP
- 3 - Test S automatickým laděním Z-Offsetu, s čištěním trysky
- 4 - Test S automatickým laděním Z-Offsetu, s čištěním trysky, pokud se mesh neshoduje, spustí se KAMP

**Automatické ladění Z-Offsetu**

Algoritmus pro automatickou kalibraci Z-Offsetu:

1.  **Zdrojová data:** V paměti tiskárny je uložen mesh podložky (obvykle 25 bodů) získaný při posledním vyrovnávání.
2.  **Příprava:**

    *   Tryska je nahřátá na pracovní teplotu, otřena o podložku a ochlazena na 151°C.

3.  **Výběr měřicího bodu:**

    *   Použije se **středový** bod meshe.

4.  **Měření a porovnání:**

    *   Na vybraném bodě se provede nové měření sondou.
        *   Získaná hodnota se porovná s hodnotou uloženou v meshi podložky.

5.  **Korekce offsetu:**

    *   Pokud je odchylka **menší než 0,3 mm**, rozdíl se přičte k aktuální hodnotě Z-Offsetu.
        *   Pokud je odchylka **větší nebo rovna 0,3 mm**, systém považuje uložený mesh za zastaralý a, pokud to nastavení dovoluje, automaticky zahájí nové vyrovnávání podložky (KAMP).

**Bez automatického ladění Z-Offsetu**

Algoritmus validace meshe podložky:

1.  **Měření:** Na aktuálním bodě se provede standardní měření sondou.
2.  **Validace:** Získaná hodnota Z se zkontroluje na konzistenci s načteným meshem.
3.  **Kritérium:** Hodnota musí být v rozsahu od (minimum meshe - 0,21 mm) do (maximum meshe + 0,21 mm).
4.  **Výsledek:**

    *   **Úspěch:** Mesh je považován za správný, tisk pokračuje.
        *   **Neúspěch:** Je vydáno varování a tisk se zastaví nebo, pokud to nastavení dovoluje, automaticky zahájí nové vyrovnávání podložky (KAMP).

**Poznámky:**

*   Tato kontrola je hrubý odhad. Je určena k detekci kritických chyb, například když je načten mesh pro PEI list pro tlusté sklo a naopak.
*   **Nespoléhejte na tuto kontrolu jako na absolutní ochranu.**
*   Při použití chytrého čištění (KAMP) se čekání na ohřev odehrává poblíž místa čištění, nikoli v rohu podložky.

Příklad: `SAVE_ZMOD_DATA MESH_TEST=0`

---

##### FORCE_MD5

Igor Polunovskiy

Ověřit MD5 hash souboru a při neshodě smazat: 0 (zakázat), 1 (povolit) (1).

1. Vyberte a stáhněte soubor pro vaši architekturu a operační systém:

- [zmod_preprocess-windows-amd64.exe](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-windows-amd64.exe) - Windows
- [zmod_preprocess-linux-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-linux-amd64) - Linux. Nezapomeňte `chmod +x zmod_preprocess-linux-amd64`
- [zmod_preprocess-darwin-arm64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-arm64) - MacOS (Apple Silicon). Nezapomeňte spustit `chmod +x zmod_preprocess-darwin-arm64`
- [zmod_preprocess-darwin-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-amd64) - MacOS (Intel). Nezapomeňte spustit `chmod +x zmod_preprocess-darwin-amd64`
- [zmod-preprocess.py](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.py) - Obecný Python. Nezapomeňte spustit `chmod +x zmod-preprocess.py`
- [zmod-preprocess.sh](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.sh) - Linux/MacOS Bash. Nezapomeňte spustit `chmod +x zmod-preprocess.sh`

2. V Orce musíte specifikovat: `Process Profile` -> `Other` -> `Post Processing Scripts`.

Zde jsou možnosti pro přidání:

- ```"C:\cesta_k_souboru\zmod_preprocess-windows-amd64.exe";```
- ```"C:\složka_pythonu\python.exe" "C:\Skripty\zmod-preprocess.py";```
- ```"/usr/bin/python3" "/home/user/zmod-preprocess.py";```
- ```"/home/user/zmod-preprocess.py";```
- ```"/home/user/zmod_preprocess-darwin-amd64";```
- ```"/home/user/zmod_preprocess-darwin-arm64";```
- ```"/home/user/zmod_preprocess-linux-amd64";```

Příklad: `SAVE_ZMOD_DATA FORCE_MD5=1`

---
##### DISABLE_SKEW

1 (zakázat korekci SKEW), 0 (načíst `skew_profile` přes `SKEW_PROFILE LOAD=skew_profile`) (1).

[Detaily](https://www.klipper3d.org/Skew_Correction.html)

Příklad: `SAVE_ZMOD_DATA DISABLE_SKEW=1`

---
##### LOAD_ZOFFSET

Načíst Z-offset z globálních parametrů uložených přes SET_GCODE_OFFSET: 1 (ano), 0 (ne) (1).

[Jak funguje Z-Offset](FAQ.md#how-does-z-offset-work)

Příklad: `SAVE_ZMOD_DATA LOAD_ZOFFSET=0`

---
##### DISABLE_PRIMING

Zakázat přípravu trysky extruzí: 0 (ne), 1 (ano) (0).

Příklad: `SAVE_ZMOD_DATA DISABLE_PRIMING=0`

---
##### CLEAR

Vybrat algoritmus čištění trysky (LINE_PURGE):

- _CLEAR1 - styl Orca (může poškrábat podložku s KAMP)
- _CLEAR2 - styl skupiny FF (může poškrábat podložku s KAMP)
- _CLEAR3 - alternativa skupiny FF (může poškrábat podložku s KAMP)
- _CLEAR4 - kód Shreidera (zprava nahoře doprava dolů)
- _CLEAR_TRAP - Pro kartáče (zprava nahoře doprava dolů)
- LINE_PURGE - čištění KAMP

Vlastní makra pro čištění lze přidat do `mod_data/user.cfg`.

Příklad: `SAVE_ZMOD_DATA CLEAR=LINE_PURGE`

---

### Parametry konce/zrušení tisku [END_PRINT]:

##### MIDI_END

Přehrát MIDI na konci tisku (""), 0 pro zakázání.

Příklad: `SAVE_ZMOD_DATA MIDI_END=Pain-Shut-your-mouth.mid`

---
##### CLOSE_DIALOGS

Automaticky zavřít dialogy po konci/zrušení tisku: 0 (ne), 1 (ano, pomalu), 2 (ano, rychle) (0).
*Pro rychlé zavírání povolte "Pouze lokální síť" v menu tiskárny.*

Příklad: `SAVE_ZMOD_DATA CLOSE_DIALOGS=2`

---
##### STOP_MOTOR

Automaticky vypnout motory 25 sekund po konci/zrušení tisku: 0 (ne), 1 (ano) (1).

Příklad: `SAVE_ZMOD_DATA STOP_MOTOR=1`

---
##### AUTO_REBOOT

Automaticky restartovat tiskárnu po dokončení tisku (0):

- 0 - žádný restart
- 1 - restartovat tiskárnu pomocí příkazu `REBOOT`
- 2 - bez nativní obrazovky: restartovat firmware pomocí `FIRMWARE_RESTART`; s obrazovkou: restartovat tiskárnu pomocí příkazu `REBOOT`

Příklad: `SAVE_ZMOD_DATA AUTO_REBOOT=0`

---

### Systémové parametry:

##### MOTION_SENSOR

Použít [senzor pohybu filamentu](https://aliexpress.ru/item/1005007480443587.html) místo senzoru přítomnosti filamentu (0):

- 0 - ne
- 1 - ano

Při použití senzoru pohybu filamentu ho vypněte na nativní obrazovce; jinak se tisk pozastaví.

Příklad: `SAVE_ZMOD_DATA MOTION_SENSOR=1`

---

##### SILENT

Pouze AD5X

Nezobrazovat okno pro výběr barvy při spuštění tisku

- 0 - zobrazit okno (výchozí)
- 1 - nezobrazovat okno, použít dříve nastavené barvy
- 2 - nezobrazovat okno, nepoužívat IFS

Příklad: `SAVE_ZMOD_DATA SILENT=0`

---

##### AUTOINSERT

Pouze AD5X

Automaticky načíst filament

- 0 - Automaticky nenačítat filament
- 1 - Automaticky načíst filament (výchozí)

Příklad: `SAVE_ZMOD_DATA AUTOINSERT=0`

---

##### ALWAYS_FULL_COLOR_CHANGE

Pouze AD5X

Určuje, zda přeskočit proces změny barvy, pokud jsou předchozí a následující barvy mapovány na stejnou fyzickou cívku.

- 0 - přeskočit proces
- 1 - nepřeskakovat proces

Příklad: `SAVE_ZMOD_DATA ALWAYS_FULL_COLOR_CHANGE=0`

##### USE_TRASH_ON_PRINT

Pouze AD5X

Pouze při běhu bez nativního displeje

Použít koš při změně barvy během tisku

- 0 - nepoužívat
- 1 - používat (výchozí)

Příklad: `SAVE_ZMOD_DATA USE_TRASH_ON_PRINT=0`

---

##### REMOVE_FILAMENT

Pouze AD5X

Pouze při běhu bez nativního displeje

Vysunout filament po dokončení tisku:

- 0 — nevysunovat (výchozí)
- 1 — vysunout

Příklad: `SAVE_ZMOD_DATA REMOVE_FILAMENT=1`

---

##### FIX_SCV

Opravit nesprávné SCV ([square_corner_velocity](https://www.klipper3d.org/Config_Reference.html#printer)) při vykreslování grafů zrychlení a výpočtu input shaperů.

- 0 - ponechat parametr jako v továrním nastavení (5)
- 1 - použít `square_corner_velocity` z `mod_data/user.cfg` nebo `printer.base.cfg`

Příklad: `SAVE_ZMOD_DATA FIX_SCV=1`

V naší tiskárně je `square_corner_velocity: 25`, ale výpočty grafů shaperu a zrychlení jsou založeny na `SCV = 5`.

To primárně ovlivňuje zobrazená zrychlení a vypočítané úrovně vyhlazování.
`shaper_type_x`, `shaper_freq_x`, `shaper_type_y`, `shaper_freq_y` zůstávají nezměněny.

Nicméně, se správnými výpočty klesnou výsledná zrychlení přibližně o polovinu.

Doporučení: přidejte následující do `mod_data/user.cfg`:
```
[printer]
square_corner_velocity: 9
```
To snižuje rychlosti v zatáčkách a obecně zlepšuje kvalitu tisku s mírným kompromisem v rychlosti.

---

##### WIFI

Na některých verzích firmwaru se Wi-Fi občas nespustí.

Pro opravu se připojte k Wi-Fi síti přes nativní obrazovku.

Spusťte `SAVE_ZMOD_DATA WIFI=1`

Poté vypněte Wi-Fi na nativní obrazovce.

- 0 — použít Wi-Fi z nativní obrazovky
- 1 — použít Wi-Fi přes zMod

---

##### FIX_E0011

Běžné příčiny chyby E0011 (Timer too close):

- Hostitel neodpověděl v daném čase (0.025 s)
- MCU neodpovědělo v daném čase (0.025 s)

Specifické příčiny:

- Zamrzlá základní deska Nations MCU nebo eboard. `Ztracena komunikace s MCU 'mcu'`. Řešení: Restart. Vyměňte základní desku (`mcu`) nebo desku extruderu (`eboard`).
- Přetížení CPU hostitele (výpočty shaperu/vykreslování grafů).
- Přetížení EMMC (operace git, zálohování, nahrávání velkých souborů během tisku atd.).
- Nedostatek RAM. Řešení: Přepájejte CPU a upgradujte na 256MB RAM.
- Poškozený kabel extruderu. Řešení: Vyměňte/opravte kabel.
- Uvolněné připojení kabelu desky extruderu. Řešení: Vyměňte desku extruderu.
- Načítání dat SWAP (SWAP je na EMMC, která pracuje rychlostí 10 MB/s; data SWAP během výpočtů shaperu mohou dosáhnout 25MB). Řešení: Vypněte SWAP, pokud máte 256MB RAM pomocí `SAVE_ZMOD_DATA USE_SWAP=0`.
- Pád firmwaru MCU. Řešení: Přeinstalujte firmware MCU pomocí [továrního resetu](Setup.md#restoring-printer-to-factory-settings-required-for-mod-installation) nebo použijte mod [UPDATE_MCU](System.md#update_mcu).

Opravit chyby E0011 a `Communication timeout during homing`. Změna tohoto parametru restartuje tiskárnu. 0-ne, 1-ano (0):

- 0 - ponechat tovární parametr (0.025)
- 1 - nastavit parametr na 0.1

Příklad: `SAVE_ZMOD_DATA FIX_E0011=1`

Tato chyba se může také objevit:

- Velký objem vyloučení modelů: Řešení `Process profile` -> `Other` -> `Output G-cod` -> zrušte zaškrtnutí `Exclude models`.
- Pokud jste vypnuli swap na FF5M/FF5MPro.

  Spusťte makro `MEM` a podívejte se, zda je swap a jakou má velikost.

  Povolte swap, pokud je vypnutý: `SAVE_ZMOD_DATA USE_SWAP=1`

- Pokud používáte FF5M/FF5MPro, spusťte plný test. To zahrnuje kalibraci PID, odstranění mapy stolu a odstranění shaperů současně.

  Je lepší provést všechny kalibrace [zde podle těchto pokynů](SetupCalibrations.md#printer-calibration-for-beginners)

Chyba `Communication timeout during homing` se může objevit kvůli vysoké latenci komunikace mezi hostitelem a MCU. Doba odezvy by měla konzistentně zůstat pod 10ms. Dočasné špičky latence mohou způsobit selhání homingu.

`TRSYNC_TIMEOUT` je parametr Klipperu (výchozí: 0.025 s), který kompenzuje systémové zpoždění.

Tovární soubor `/opt/klipper/klippy/mcu.py` nastavuje `TRSYNC_TIMEOUT = 0.025`. Patch ho mění na `TRSYNC_TIMEOUT = 0.1`.

**Jak opravit na továrním firmwaru:**

- Naformátujte USB disk jako FAT32.
- Uložte soubor `flashforge_init.sh` na USB:
    - [Opravit parametr Adventurer5M](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-e0011-on.tgz)
      - [Obnovit tovární parametr Adventurer5M](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-e0011-on.tgz)
      - [Opravit parametr Adventurer5MPro](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-e0011-on.tgz)
      - [Obnovit tovární parametr Adventurer5MPro](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-e0011-on.tgz)

- Vypněte tiskárnu.
- Vložte USB do tiskárny.
- Zapněte tiskárnu (bude hlasitě pípat).
- Počkejte na restart.
- Vyjměte USB.
- Znovu vytiskněte problematický soubor; E0011 by se již neměla objevit.

**Ruční oprava na továrním firmwaru:**

- Nainstalujte [root](https://wiki.zmod.link/Native_FW/#root).
- Použijte [WinSCP](https://winscp.net/eng/download.php) pro SSH do tiskárny.
- Upravte `/opt/klipper/klippy/mcu.py`.
- Najděte `TRSYNC_TIMEOUT = 0.025` a změňte ho na `TRSYNC_TIMEOUT = 0.1`.
- Uložte soubor a restartujte tiskárnu.

---
##### FIX_E0017

Opravit chybu E0017. Změna tohoto parametru restartuje tiskárnu. 0-ne, 1-ano (1):

V továrním souboru `/opt/klipper/klippy/toolhead.py` je `LOOKAHEAD_FLUSH_TIME = 0.5`. Původní Klipper používá `LOOKAHEAD_FLUSH_TIME = 0.250`. Náš mod funguje nejlépe s `LOOKAHEAD_FLUSH_TIME = 0.150`.

- 0 - nastavit na tovární hodnotu
- 1 - nastavit na 0.150

Příklad: `SAVE_ZMOD_DATA FIX_E0017=1`

**Jak opravit na továrním firmwaru:**

- Naformátujte USB disk jako FAT32.
- Uložte příslušný soubor na USB:
    - [Adventurer5M-e0017-4.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-e0017-4.tgz) pro FlashForge 5M
      - [Adventurer5MPro-e0017-4.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-e0017-4.tgz) pro FlashForge 5M Pro

- Vypněte tiskárnu.
- Vložte USB do tiskárny.
- Zapněte tiskárnu (bude hlasitě pípat).
- Počkejte na restart.
- Vyjměte USB.
- Znovu vytiskněte problematický soubor; E0017 by se již neměla objevit.

**Ruční oprava na továrním firmwaru:**

- Nainstalujte [root](https://wiki.zmod.link/Native_FW/#root).
- Použijte [WinSCP](https://winscp.net/eng/download.php) pro SSH do tiskárny.
- Upravte `/opt/klipper/klippy/toolhead.py`.
- Najděte `LOOKAHEAD_FLUSH_TIME = 0.5` a změňte ho na `LOOKAHEAD_FLUSH_TIME = 0.150`.
- Uložte soubor a restartujte tiskárnu.

---
##### LED

Jas LED při spuštění (50).

Příklad: `SAVE_ZMOD_DATA LED=50`

---
##### MIDI_ON

Přehrát MIDI při spuštění (""). Použijte `0` pro zakázání.

Příklad: `SAVE_ZMOD_DATA MIDI_ON=Pain-Shut-your-mouth.mid`

---
##### NEW_SAVE_CONFIG

Použít alternativní SAVE_CONFIG (vyvolá `SAVE_CONFIG` bez zamrznutí nativní obrazovky). [NEW_SAVE_CONFIG](Main.md#new_save_config) pro kalibraci PID: 0-ne, 1-ano (0).

Příklad: `SAVE_ZMOD_DATA NEW_SAVE_CONFIG=0`

---
##### USE_SWAP

Povolit SWAP (1):

- 0 - ne (*Pouze pro upgradovanou 256MB RAM*)
- 1 - ano, na EMMC
- 2 - ano, preferovat USB FLASH

Příklad: `SAVE_ZMOD_DATA USE_SWAP=1`

---
##### CHINA_CLOUD

Povolit čínské cloudové služby: 0-ne, 1-ano (1).

Příklad: `SAVE_ZMOD_DATA CHINA_CLOUD=0`

[Zakázat čínské cloudy](Recomendations.md#disable-chinese-cloud-services)

I když jsou všechny cloudové možnosti vypnuty přes obrazovku, tiskárna se stále snaží posílat fotky, videa a telemetrii na čínské servery.

Nastavení tohoto parametru na 0 částečně zakáže tyto "funkce".

**Pokud jsou čínské cloudy zakázány, tiskárna nebude kontrolovat aktualizace továrního firmwaru.**

Pro aktualizaci továrního firmwaru povolte čínské cloudy pomocí `SAVE_ZMOD_DATA CHINA_CLOUD=1`, restartujte a pokračujte v aktualizaci.

Místo toho můžete použít:

- [zmod.link](Zmod.md#zlink) - cloud, pro správu tiskáren přes Fluidd/Mainsail.
- [Telegram bot](Macros.md).

**Jak zakázat čínské cloudy na továrním firmwaru:**

- Naformátujte USB disk jako FAT32.
- Umístěte [flashforge_init.sh](https://github.com/ghzserg/zmod/blob/main/Native_firmware/cloud/rem/flashforge_init.sh) na USB.
- Vypněte tiskárnu.
- Vložte USB do tiskárny.
- Zapněte tiskárnu (jednou se restartuje).
- Vyjměte USB.

**Jak povolit čínské cloudy na továrním firmwaru:**

- Naformátujte USB disk jako FAT32.
- Umístěte [flashforge_init.sh](https://github.com/ghzserg/zmod/blob/main/Native_firmware/cloud/orig/flashforge_init.sh) na USB.
- Postupujte stejně jako výše.

---
##### NICE

Nastavit prioritu procesu Klipper: 1 (nejnižší) až 40 (nejvyšší) (20).

Příklad: `SAVE_ZMOD_DATA NICE=20`

Vyšší priorita přiděluje více zdrojů Klipperu, ale může způsobit odpojení Moonrakeru a kamery.

Pro uživatele Linuxu:
```
NICE=20
grep -q "^nice = " /opt/config/mod_data/variables.cfg && NICE=$(grep "^nice = " /opt/config/mod_data/variables.cfg | cut -d "=" -f2| awk '{print $1}')
NICE=$((20-$NICE))
[ $NICE -ge 20 ]  && NICE=19
[ $NICE -lt -20 ] && NICE=-20
renice $NICE $(ps |grep klippy.py| grep -v grep| awk '{print $1}')
```

---
##### DISPLAY_OFF_TIMEOUT

Nastavit časový limit (v sekundách) pro vypnutí nativní obrazovky při nečinnosti. Výchozí: 180.

Poznámka: Nativní obrazovka potřebuje alespoň 5 sekund na konfiguraci WiFi.

Příklad: `SAVE_ZMOD_DATA DISPLAY_OFF_TIMEOUT=120`

---
##### PRO_POWEROFF_TIMEOUT

Nastavit časový limit (v minutách) pro automatické vypnutí FF5M Pro. Výchozí: 0 (zakázáno).

Příklad: `SAVE_ZMOD_DATA PRO_POWEROFF_TIMEOUT=10`

---

##### SAVE_MOONRAKER

- 0 - Načíst rozložení tlačítek maker ze ZMOD (výchozí).
- 1 - Povolit ukládání změn tlačítek maker lokálně ve Fluidd/Moonraker.

Lokálně uložená makra jsou uložena v samostatné sekci.

Příklad: `SAVE_ZMOD_DATA SAVE_MOONRAKER=1`

---

##### SAVE_FILAMENT_SENSORS

- 0 - Neukládat stav senzorů filamentu po restartu; budou vždy povoleny (výchozí)
- 1 - Uložit stav senzorů po restartu. Pokud senzor zakážete, bude zakázán i po restartu.

Příklad: `SAVE_ZMOD_DATA SAVE_FILAMENT_SENSORS=1`