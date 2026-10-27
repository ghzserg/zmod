<h1 align="center">Globální parametry</h1>

Makro je malý program napsaný v jazyce Klipper/Gcode.

Lze ho vyvolat:

- ze souboru G-code
- z konzole Fluidd/Mainsail (ve Fluiddu stiskněte latinské písmeno `C`)

!!! note
    *Hodnota v závorkách je výchozí hodnota*

---

### LANG

Nastaví jazyk Z-Mod.

- LANG - jazyk: en (angličtina), ru (ruština), de (němčina), fr (francouzština), it (italština), es (španělština), zh (čínština), ja (japonština), ko (korejština), pt (portugalština), cs (čeština), tr (turečtina)

Příklad:
```
LANG LANG=en
```

---
### SET_TIMEZONE

Změna časového pásma.

- ZONE - časové pásmo (výchozí: `Asia/Yekaterinburg`)

Více: [SET_TIMEZONE](System.md#set_timezone).

---
### NOZZLE_CONTROL

Ochrana při nárazu trysky do podložky nebo odtržení dílu.

Nouzové vypnutí tiskárny při zjištění překročení hmotnosti (AD5M a AD5X).

- WEIGHT - hmotnost v gramech (1500)

Nastavení přetrvávají i po restartu.

Nastavte `NOZZLE_CONTROL WEIGHT=0` pro vypnutí této funkce.

*Kontrola je vypnutá, dokud není makro poprvé spuštěno.*

Po prvním spuštění se kontrola při tisku zapíná automaticky.

Při použití nativní obrazovky restartuje spuštění makra tiskárnu.

Bez nativní obrazovky restartuje Klipper (jsou upraveny konfigurační soubory).

Funguje automaticky; pro G-code jsou k dispozici další makra:

- `ZCONTROL_ON` - zapnout kontrolu
- `ZCONTROL_OFF` - vypnout kontrolu
- `ZCONTROL_STATUS` - zkontrolovat stav
- `ZCONTROL_PAUSE` - pozastavit při spuštění (pouze po vyprázdnění fronty příkazů; nepoužívejte na počátečních vrstvách)
- `ZCONTROL_ABORT` - při spuštění zastavit Klipper
- `ZCONTROL_AUTO` - při spuštění zastaví Klipper (pokud je výška Z < `ZCONTROL_Z`) nebo zavolá PAUSE, pokud je z >= `ZCONTROL_Z`
- `ZCONTROL_Z Z=10` - Nastavit výšku Z.
- `SAVE_ZMOD_DATA ZCONTROL_Z=10` - Uložit výšku Z. Pokud nechcete povolit pauzu, nastavte `SAVE_ZMOD_DATA ZCONTROL_Z=230`

Chcete-li v prvních vrstvách místo přerušení použít pauzu, přidejte `ZCONTROL_PAUSE` ve sliceru do požadované vrstvy.

_Hláška „Kontrola není aktivní“ znamená, že kontrola se právě nepoužívá; během tisku se zapne automaticky._

---

### GET_ZMOD_DATA

Zobrazí globální parametry/příznaky Z-Mod.
Po spuštění se v konzoli zobrazí uložené a aktuálně použité hodnoty.

`Fluidd` -> `Makra` -> `Hlavní` -> `Z-Mod PARAMETRY`

---

### PLUGINS

Zobrazí nabídku správy pluginů.

<img width="849" height="838" alt="{9D0BE78C-816B-4F22-B3F1-8FC678AD8977}" src="https://github.com/user-attachments/assets/a23b06e2-abe3-4ff0-93c7-079d2d057e1b" />

V této nabídce můžete zapínat, vypínat a úplně odstraňovat doplňkové pluginy.

- Levý sloupec (aktivace): kliknutím plugin zapnete nebo vypnete.
    - Zelené tlačítko — plugin je aktivní.
    - Šedé tlačítko — plugin je vypnutý.
- Pravý sloupec (aktualizace): zapíná nebo vypíná automatické aktualizace přes Moonraker.
    - UPDATE: ON — aktualizace jsou zapnuté.
    - UPDATE: OFF — aktualizace jsou vypnuté.

**Jak plugin úplně odstranit:**

Pokud plugin již nepotřebujete, přepněte obě jeho tlačítka na šedou (vypněte samotný plugin i jeho aktualizace), stiskněte SAVE (MOONRAKER RESTART) a poté restartujte tiskárnu. Systém automaticky smaže jeho složku z `mod_data/plugins/`.

---

### GLOBAL

Zjednodušená správa globálních parametrů. K dispozici jsou pouze parametry, které lze změnit kliknutím na tlačítko. Parametry, které vyžadují zadání čísla, názvu souboru atd., nejsou tímto makrem ovládány.

Po změně parametrů se doporučuje restartovat tiskárnu.

---

### SAVE_ZMOD_DATA

Uložit globální parametry/příznaky Z-Mod (aplikují se při každém tisku).

Nepřidávejte toto makro do startovacího/koncového G-code ani do souborů G-code. Spouštějte ho z konzole Fluidd/Mainsail. Parametry se ukládají do paměti tiskárny v souboru `mod_data/variables.cfg` a vypnutím se neztratí, takže je nemusíte zadávat pokaždé (**soubor neupravujte ručně — rozbijete Klipper nebo mod**).

**Pro úpravu parametrů:**

- Přejděte do `Fluidd` -> `Makra` -> `Systém` -> `SAVE Z-Mod PARAMETERS`, vyberte parametr, upravte ho a klikněte na `SEND`.
- Alternativně zadejte příkazy přímo do konzole Fluidd, např. `SAVE_ZMOD_DATA CLOSE_DIALOGS=2`.

[Zobrazit uložené parametry](#get_zmod_data)

---

### Parametry nabídky výběru barvy

**Všechny parametry nabídky výběru barvy jsou pouze pro AD5X.**

##### ALLOWED_TOOL_COUNT

Počet nástrojů, které se mají zobrazit v nabídce výběru barvy. Týká se to příkazů T0, T1 atd. v souboru G-code, nikoli fyzických cívek ve vašem IFS.

Pokud Z-Mod úspěšně zjistí použité nástroje ze souboru, tato hodnota se přepíše a zobrazí se jen nástroje použité v souboru.

Toto nastavení nelze použít, když je povolena nativní obrazovka.

[Viz nastavení předzpracování](/cs/Recommendations/#povolit-kontrolu-kontrolního-součtu-md5)

Příklad: `SAVE_ZMOD_DATA ALLOWED_TOOL_COUNT=4`

##### SCAN_FILE_COLORS

!!! note "3MF"
    U souborů 3MF probíhá prohledání a přiřazení barev okamžitě; [preprocesor](Global.md#force_md5) není potřeba.

Zapne prohledávání G-code souborů pro zjištění, které příkazy pro změnu nástroje (T0, T1 atd.) jsou použity a na jaké barvy a materiály jsou ve sliceru namapovány: 0 (vypnout), 1 (zapnout), 2 (bez úplného prohledávání, jen data připravená skriptem sliceru)

[Viz nastavení předzpracování](/cs/Recommendations/#povolit-kontrolu-kontrolního-součtu-md5)

Příklad: `SAVE_ZMOD_DATA SCAN_FILE_COLORS=0`

##### COLOR_MENU_1_BASED

Určuje, zda se mají v nabídce výběru barvy zobrazovat popisky založené na 0 (T0, T1 atd.) nebo na 1 (Barva 1, Barva 2 atd.). Nemění to nic jiného než způsob označení tlačítek a je to čistě pro pohodlí: 0 (založené na 0), 1 (založené na 1)

Příklad: `SAVE_ZMOD_DATA COLOR_MENU_1_BASED=1`

##### AUTO_ASSIGN_COLORS

Určuje, zda se při zahájení tisku automaticky přiřadí příkazů pro změnu nástroje (T0, T1 atd.) k fyzickému filamentu zavedenému ve vašem IFS. Pokud jste nepovolili tichý režim, nabídka výběru barvy se stále objeví; toto nastavení ovlivňuje pouze předvybrané hodnoty: 0 (vypnout), 1 (zapnout)

Toto nastavení se bude vztahovat i na tisky spuštěné v tichém režimu. Můžete ho nakonfigurovat tak, aby přerušil tisk, pokud se vyskytnou určité chyby s automatickým přiřazením: 2 (přerušit, pokud nelze spárovat materiál; nesoulad barev povolit), 30 (přerušit při jakýchkoli problémech)

Pro vlastní hodnoty pro chybové stavy v tichém režimu sečtěte následující hodnoty, abyste určili správné nastavení:

* 2 (Alespoň jeden materiál nelze spárovat; např. gcode soubor specifikuje ABS, ale máte vložený pouze PLA; nebo data o materiálu nelze načíst)
* 4 (Alespoň jednu barvu nelze vůbec spárovat, obvykle kvůli zakázanému nebo neúspěšnému prohledávání souborů)
* 8 (Alespoň jedna barva odpovídá špatně)
* 16 (Alespoň jedna fyzická cívka byla přiřazena k více než jednomu indexu nástroje v souboru)

[Viz nastavení předzpracování](/cs/Recommendations/#povolit-kontrolu-kontrolního-součtu-md5)

Příklad: `SAVE_ZMOD_DATA AUTO_ASSIGN_COLORS=0`

---

##### PURGE_ALL_EXTRUDERS

Pouze Creator 5 / Creator 5 Pro

Profouknutí extruderů při startu tisku:

- 0 - profouknout pouze první (startovní) extruder (výchozí)
- 1 - profouknout všechny použité extrudery

Profukují se extrudery, které se účastní přiřazení barev ze souboru k fyzickým cívkám. Pokud je na jednu cívku přiřazeno více barev, extruder se profoukne jen jednou.

Když je zapnuté Auto PA ([PRINT_AUTOPA](Global.md#print_autopa) nebo tlačítko `Auto PA` v menu tisku), všechny použité extrudery se profouknou už během kalibrace PA, proto tento parametr nemá žádný vliv.

Příklad: `SAVE_ZMOD_DATA PURGE_ALL_EXTRUDERS=1`

---

##### UNUSED_EXTRUDERS_OFF_TIME

Pouze Creator 5 / Creator 5 Pro

Vypnout ohřev nečinných extruderů při vícebarevném tisku po nastavené době (v minutách):

- 0 - nevypínat
- 5, 10, 20, 40, 60 - po kolika minutách nečinnosti se ohřev extruderu vypne

V menu se parametr zobrazuje jako „Vypnout nečinné extrudery za N min“.

Pro správnou funkci musí být ve sliceru zapnuta funkce **Ooze prevention** (`Nastavení tisku` > `Multimateriál` > `Ooze prevention`).

Příklad: `SAVE_ZMOD_DATA UNUSED_EXTRUDERS_OFF_TIME=5`

### Parametry startu tisku a měření sítě podložky [START_PRINT]:

##### MIDI_START

Přehrát MIDI při startu tisku (""), 0 pro vypnutí.

Příklad: `SAVE_ZMOD_DATA MIDI_START=Pain-Shut-your-mouth.mid`

---
##### PRECLEAR

Zapnout předčištění trysky v CLEAR_NOZZLE: 0 (ne), 1 (ano) (0).

Příklad: `SAVE_ZMOD_DATA PRECLEAR=0`

---
##### PRINT_LEVELING

Vytvořit síť podložky před každým tiskem (pomocí nativní obrazovky, pokud je povolena): 0 (ne), 1 (ano) (0).
*Aby nativní obrazovka mohla měřit síť podložky, zapněte v menu tiskárny „Pouze místní síť“: Nastavení -> Ikona Wi-Fi -> Režim sítě.*

Příklad: `SAVE_ZMOD_DATA PRINT_LEVELING=1`

---
##### PRINT_AUTOPA
Pouze pro Creator 5 / Creator 5 Pro

Určit PA (Pressure Advance) při každém tisku: 0 (ne), 1 (ano) (0). 

*Aby Auto PA fungovalo z nativní obrazovky, zapněte v menu tiskárny „Nastavení“ -> „Ikona Wi-Fi“ -> „Režim sítě“ -> přepínač „Pouze místní síť“.*

Příklad: `SAVE_ZMOD_DATA PRINT_AUTOPA=1`

---
##### USE_KAMP

!!! note "Rychlý KAMP"
    KAMP se zapíná automaticky a funguje bez pomalého vylučování objektů. U 3MF jsou data pro KAMP k dispozici okamžitě, u G-code po prohledání souboru.

Použít adaptivní mesh (KAMP) místo plného sítě podložky, kde je to možné: 0 (ne), 1 (ano) (0).
Doporučuje se nastavit `SAVE_ZMOD_DATA CLEAR=LINE_PURGE`, aby čištění probíhalo v oblasti KAMP.

*Umožňuje KAMP i při měření sítě přes síť z nativní obrazovky.*

Příklad: `SAVE_ZMOD_DATA USE_KAMP=1`

---

##### MESH_TEST

Testovat síť podložky před tiskem:

- 0 - nekontrolovat
- 1 - Test BEZ automatického ladění Z-Offsetu (výchozí)
- 2 - Test BEZ automatického ladění Z-Offsetu, pokud síť neodpovídá, spustí se KAMP
- 3 - Test S automatickým laděním Z-Offsetu, s čištěním trysky
- 4 - Test S automatickým laděním Z-Offsetu, s čištěním trysky, pokud síť neodpovídá, spustí se KAMP

**Automatické ladění Z-Offsetu**

Algoritmus pro automatickou kalibraci Z-Offsetu:

1.  **Zdrojová data:** V paměti tiskárny je uložen síť podložky (obvykle 25 bodů) získaný při posledním měření.
2.  **Příprava:**

    *   U AD5M/AD5X je tryska nahřátá na pracovní teplotu, otřena o podložku a ochlazena na teplotu měření: [TEMP_TEST_MAX](/cs/Global/#temp_test_max) (výchozí 151), pokud je cílová teplota trysky vyšší než 230°C, jinak [TEMP_TEST_MIN](/cs/Global/#temp_test_min) (výchozí 121).
    *   U Creator 5 / Creator 5 Pro se aktivní extruder odloží.

3.  **Výběr měřicího bodu:**

    *   Použije se **středový** bod sítě.

4.  **Měření a porovnání:**

    *   Na vybraném bodě se provede nové měření sondou (PROBE).
    *   Získaná hodnota se porovná s hodnotou uloženou v síti podložky.

5.  **Korekce offsetu:**

    *   Pokud je odchylka **menší než 0,3 mm**, rozdíl se přičte k aktuální hodnotě Z-Offsetu.
    *   Pokud je odchylka **větší nebo rovna 0,3 mm**, systém považuje uloženou síť za zastaralý a, pokud to nastavení dovoluje, automaticky zahájí nové měření sítě podložky (KAMP).

**Bez automatického ladění Z-Offsetu**

Algoritmus validace sítě podložky:

1.  **Měření:** Na aktuálním bodě se provede standardní měření sondou (PROBE).
2.  **Validace:** Získaná hodnota Z se zkontroluje na konzistenci s načtenou sítí.
3.  **Kritérium:** Hodnota musí být v rozsahu od (minimum sítě - 0,21 mm) do (maximum sítě + 0,21 mm).
4.  **Výsledek:**

    *   **Úspěch:** Síť je považována za správnou, tisk pokračuje.
    *   **Neúspěch:** Je vydáno varování a tisk se zastaví nebo, pokud to nastavení dovoluje, automaticky zahájí nové měření sítě podložky (KAMP).

**Poznámky ke kontrole bez automatického ladění:**

*   Tato kontrola je hrubý odhad. Je určena k detekci kritických chyb, například když je načtena síť pro PEI desku pro tlusté sklo a naopak.
*   **Nespoléhejte na tuto kontrolu jako na absolutní ochranu.**
*   Při použití chytrého čištění (KAMP) se čekání na ohřev odehrává poblíž místa čištění, nikoli v rohu podložky.
*   Kontrola probíhá s horkou tryskou.

Příklad: `SAVE_ZMOD_DATA MESH_TEST=0`

---

##### TEMP_TEST_MIN

Nižší teplota trysky pro test kontaktu s podložkou v režimech [MESH_TEST](/cs/Global/#mesh_test) 3/4 (s čištěním trysky). Pokud je cílová teplota trysky 230°C nebo nižší, ochladí se tryska před měřením na tuto teplotu. Výchozí hodnota: `121`.

Snižte hodnotu, pokud vaše podložka nesnese výchozí teplotu: na podložkách PC (teplota skelného přechodu ~145-150°C) a některých G10 zanechává horká tryska hluboké vtisky.

Tento parametr se nenastavuje přes `SAVE_ZMOD_DATA` — zadejte příkaz v konzoli Fluidd/Mainsail (hodnota se ukládá do `mod_data/variables.cfg`):

Příklad: `SAVE_VARIABLE VARIABLE=temp_test_min VALUE=110`

*   Doporučený rozsah: 100-150. Nová hodnota platí od dalšího tisku, restart není potřeba.
*   Používá se pouze při čištění trysky ([MESH_TEST](/cs/Global/#mesh_test) 3/4). V režimech 1/2 (výchozí) se síť kontroluje při plné tiskové teplotě bez ochlazení.

---

##### TEMP_TEST_MAX

Vyšší teplota trysky pro test kontaktu s podložkou v režimech [MESH_TEST](/cs/Global/#mesh_test) 3/4 (s čištěním trysky). Pokud je cílová teplota trysky vyšší než 230°C, ochladí se tryska před měřením na tuto teplotu. Výchozí hodnota: `151`.

Použití je stejné jako u [TEMP_TEST_MIN](/cs/Global/#temp_test_min) — snižte hodnotu pro teplotně citlivé podložky (PC, některé G10).

Příklad: `SAVE_VARIABLE VARIABLE=temp_test_max VALUE=140`

---

##### FORCE_MD5

Igor Polunovskiy

> Poznámka: Platí pouze při odesílání G-code. Pro 3MF není potřeba.

Ověřit MD5 součet souboru a při neshodě ho smazat: 0 (vypnout), 1 (zapnout) (1).

1. Vyberte a stáhněte soubor pro vaši architekturu a operační systém:

- [zmod_preprocess-windows-amd64.exe](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-windows-amd64.exe) - Windows
- [zmod_preprocess-linux-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-linux-amd64) - Linux. Nezapomeňte `chmod +x zmod_preprocess-linux-amd64`
- [zmod_preprocess-darwin-arm64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-arm64) - macOS Apple Silicon. Nezapomeňte spustit `chmod +x zmod_preprocess-darwin-arm64`
- [zmod_preprocess-darwin-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-amd64) - macOS Intel. Nezapomeňte spustit `chmod +x zmod_preprocess-darwin-amd64`
- [zmod-preprocess.py](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.py) - Univerzální Python. Nezapomeňte spustit `chmod +x zmod-preprocess.py`
- [zmod-preprocess.sh](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.sh) - Linux/macOS Bash. Nezapomeňte spustit `chmod +x zmod-preprocess.sh`

2. V Orce zadejte: `Process Profile` -> `Other` -> `Post Processing Scripts`.

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

1 (vypnout korekci SKEW), 0 (načíst `skew_profile` přes `SKEW_PROFILE LOAD=skew_profile`) (1).

[Detaily](https://www.klipper3d.org/Skew_Correction.html)

Příklad: `SAVE_ZMOD_DATA DISABLE_SKEW=1`

---
##### LOAD_ZOFFSET

!!! note "Creator 5 / Creator 5 Pro"
    U Creator 5 / Creator 5 Pro je Z-offset s nativní obrazovkou i v režimu bez nativní obrazovky stejný – oba jsou plně synchronizované. Pokud je nativní obrazovka vypnutá, můžete Z-offset měnit během tisku přes GuppyScreen, HelixScreen, Fluidd nebo Mainsail – uloží se.

Načíst Z-offset z globálních parametrů uložených přes SET_GCODE_OFFSET: 1 (ano), 0 (ne) (1).

[Jak funguje Z-Offset](FAQ.md#jak-funguje-z-offset)

Příklad: `SAVE_ZMOD_DATA LOAD_ZOFFSET=0`

---
##### DISABLE_PRIMING

Vypnout předtlačení (priming) trysky: 0 (ne), 1 (ano) (0).

[Podrobnosti](/cs/Global/#clear)

Příklad: `SAVE_ZMOD_DATA DISABLE_PRIMING=0`

---
##### CLEAR

Výběr algoritmu předtlačení trysky (LINE_PURGE):

- _CLEAR1 - styl Orca
- _CLEAR2 - styl skupiny FF
- _CLEAR3 - alternativa skupiny FF
- _CLEAR4 - kód Shreidera (zprava nahoře doprava dolů)
- _CLEAR_TRAP - pro kartáče (zprava nahoře doprava dolů)
- LINE_PURGE - čištění KAMP

Pokud používáte `KAMP`, čištění se vynutí na `LINE_PURGE` (místo _CLEAR1, _CLEAR2, _CLEAR3, _CLEAR4).

Pokud používáte `LINE_PURGE`, ale v Orca nemáte zapnuté označování objektů, použije se `_CLEAR2`.

Vlastní makra pro čištění lze přidat do `mod_data/user.cfg` — název makra uveďte v tomto parametru.

Příklad: `SAVE_ZMOD_DATA CLEAR=LINE_PURGE`

*5M/5M Pro: Nejde o náhradu nativního čištění (CLEAR_NOZZLE), kdy tryska ťukne doprostřed podložky a pak plast otře o podložku. Jde o předtlačení trysky těsně před tiskem.*

_Pro vypnutí předtlačení trysky linkou použijte [DISABLE_PRIMING](/cs/Global/#disable_priming)_

---

### Parametry konce/zrušení tisku [END_PRINT]:

##### MIDI_END

Přehrát MIDI na konci tisku (""), 0 pro vypnutí.

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

- 0 - ne (používá se senzor přítomnosti filamentu)
- 1 - ano (používá se senzor pohybu filamentu)

**Při použití senzoru pohybu filamentu ho vypněte na nativní obrazovce; jinak se tisk zastaví.**

Pokud se v režimu bez nativní obrazovky používá senzor přítomnosti filamentu, při jeho sepnutí se zobrazí zpráva: „Došel filament. Pauza za 30 sekund“.

Příklad: `SAVE_ZMOD_DATA MOTION_SENSOR=1`

---

##### SILENT

Pouze AD5X

Určuje, zda se při spuštění tisku zobrazí okno výběru barvy:

- 0 - zobrazit okno (výchozí)
- 1 - nezobrazovat okno, použít dříve nastavené barvy
- 2 - nezobrazovat okno, nepoužívat IFS

Příklad: `SAVE_ZMOD_DATA SILENT=0`

---

##### AUTOINSERT

Pouze AD5X

Automaticky zavádět filament:

- 0 - nezavádět automaticky
- 1 - zavádět automaticky (výchozí)

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

Pouze při běhu bez nativní obrazovky

Používat odpadní koš při změně barvy během tisku:

- 0 - nečistit do odpadního koše
- 1 - čistit do odpadního koše (výchozí)
- 2 - po změně barvy přejet k odpadnímu koši, ale nečistit

Příklad: `SAVE_ZMOD_DATA USE_TRASH_ON_PRINT=0`

---

##### REMOVE_FILAMENT

Pouze AD5X

Pouze při běhu bez nativní obrazovky

Vysunout filament po dokončení tisku:

- 0 — nevysunovat (výchozí)
- 1 — vysunout

Příklad: `SAVE_ZMOD_DATA REMOVE_FILAMENT=1`

---

##### FIX_SCV

Opravit nesprávné SCV ([square_corner_velocity](https://www.klipper3d.org/Config_Reference.html#printer)) při vykreslování grafů zrychlení a výpočtu Input Shaperů.

- 0 - ponechat parametr jako v továrním nastavení (5)
- 1 - použít `square_corner_velocity` z `mod_data/user.cfg` nebo `printer.base.cfg`

Příklad: `SAVE_ZMOD_DATA FIX_SCV=1`

V naší tiskárně je `square_corner_velocity: 25`, ale výpočty grafů shaperu a zrychlení jsou založeny na `SCV = 5`.

Ovlivňuje to hlavně zobrazená zrychlení a vypočítané vyhlazení.
`shaper_type_x`, `shaper_freq_x`, `shaper_type_y`, `shaper_freq_y` zůstávají nezměněny.

Se správným výpočtem však vypočtená zrychlení klesnou přibližně na polovinu.

Doporučení: přidejte následující do `mod_data/user.cfg`:
```
[printer]
square_corner_velocity: 9
```
Sníží se rychlost v rozích a celkově se zlepší kvalita tisku za cenu mírně nižší rychlosti.

---

##### WIFI

Na některých verzích firmwaru se Wi-Fi občas nespustí.

Pro opravu se nejprve připojte k Wi-Fi síti přes nativní obrazovku a poté:

1. Zavolejte `SAVE_ZMOD_DATA WIFI=1`
2. Vypněte tiskárnu
3. Zapněte tiskárnu

- 0 — použít Wi-Fi z nativní obrazovky
- 1 — použít Wi-Fi přes Z-Mod

---

##### FIX_E0011

Běžné příčiny chyby E0011 (Timer too close):

- Hostitel neodpověděl v daném čase (0.025 s)
- MCU neodpovědělo v daném čase (0.025 s)

Specifické příčiny:

- Zamrzlé MCU základní desky nebo desky extruderu. `Lost communication with MCU 'mcu'`. Řešení: restart; výměna základní desky (`mcu`) nebo desky extruderu (`eboard`).
- Přetížení CPU hostitele (výpočty shaperu/vykreslování grafů).
- Přetížení EMMC (operace git, zálohování, nahrávání velkých souborů během tisku atd.).
- Nedostatek RAM. Řešení: přepájení procesoru na verzi s 256 MB RAM.
- Poškozený kabel extruderu. Řešení: Vyměňte/opravte kabel.
- Uvolněný konektor kabelu desky extruderu. Řešení: Vyměňte desku extruderu.
- Načítání dat SWAP (SWAP je na EMMC, která pracuje rychlostí 10 MB/s; data SWAP během výpočtů shaperu mohou dosáhnout 25MB). Řešení: pokud máte 256 MB RAM, vypněte SWAP pomocí `SAVE_ZMOD_DATA USE_SWAP=0`.
- Pád firmwaru MCU. Řešení: Přeinstalujte firmware MCU pomocí [továrního resetu](Setup.md#obnovení-továrního-nastavení-tiskárny-nutné-pro-instalaci-modifikace) nebo pomocí makra [UPDATE_MCU](System.md#update_mcu).

Opravit chyby E0011 a `Communication timeout during homing`. Změna tohoto parametru restartuje tiskárnu. 0-ne, 1-ano (0):

- 0 - ponechat tovární parametr (0.025)
- 1 - nastavit parametr na 0.1

Příklad: `SAVE_ZMOD_DATA FIX_E0011=1`

Tato chyba se může také objevit:

- Velký počet vylučitelných objektů. Řešení: `Process profile` -> `Other` -> `G-code output` -> zrušte zaškrtnutí `Exclude objects`.
- Pokud jste vypnuli swap na FF5M/FF5MPro.

  Spusťte makro `MEM` a podívejte se, zda je swap a jakou má velikost.

  Zapněte swap, pokud je vypnutý: `SAVE_ZMOD_DATA USE_SWAP=1`

- Pokud na FF5M/FF5MPro spouštíte plný test, tedy kalibraci PID, měření sítě podložky a kalibraci shaperů současně.

  Je lepší provést všechny kalibrace [podle tohoto návodu](SetupCalibrations.md#printer-calibration-for-beginners)

- Pokud používáte Klipper 13 na AD5X. V tom případě se můžete vrátit k nativnímu Klipperu příkazem `UPDATE_MCU FORCE=12`.
- Pokud se používá fuzzy skin a procesor nestíhá počítat trasu. Vypněte fuzzy skin nebo upravte jeho parametry.

Chyba `Communication timeout during homing` se může objevit kvůli vysoké latenci komunikace mezi hostitelem a MCU. Doba odezvy by měla trvale zůstat pod 10 ms. Dočasné špičky latence mohou způsobit selhání homingu.

`TRSYNC_TIMEOUT` je parametr Klipperu (výchozí: 0.025 s), který kompenzuje systémové zpoždění.

Tovární soubor `/opt/klipper/klippy/mcu.py` nastavuje `TRSYNC_TIMEOUT = 0.025`. Patch ho mění na `TRSYNC_TIMEOUT = 0.1`.

**Jak opravit na továrním firmwaru:**

- Naformátujte USB disk na FAT32 (MBR).
- Uložte na USB soubor `flashforge_init.sh`:
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

- Nainstalujte [root](/cs/Native_FW/#root).
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

- Naformátujte USB disk na FAT32 (MBR).
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

- Nainstalujte [root](/cs/Native_FW/#root).
- Použijte [WinSCP](https://winscp.net/eng/download.php) pro SSH do tiskárny.
- Upravte `/opt/klipper/klippy/toolhead.py`.
- Najděte `LOOKAHEAD_FLUSH_TIME = 0.5` a změňte ho na `LOOKAHEAD_FLUSH_TIME = 0.150`.
- Uložte soubor a restartujte tiskárnu.

---
##### LED

Jas LED po zapnutí (50).

Příklad: `SAVE_ZMOD_DATA LED=50`

---
##### WEB_SCREEN

Pouze Creator 5 / Creator 5 Pro

Přesměrovat obrazovku tiskárny jako virtuální kameru `screen` do Fluidd/Mainsail a [zmod.link](https://zmod.link)

- 0 - Nepřesměrovávat
- 1 - Přesměrovávat (výchozí)

Příklad: `SAVE_ZMOD_DATA WEB_SCREEN=1`

---
##### MIDI_ON

Přehrát MIDI při zapnutí tiskárny (""). Pro vypnutí použijte `0`.

Příklad: `SAVE_ZMOD_DATA MIDI_ON=Pain-Shut-your-mouth.mid`

---
##### NEW_SAVE_CONFIG

Při kalibraci PID použít alternativní [NEW_SAVE_CONFIG](Main.md#new_save_config) (provede `SAVE_CONFIG` bez zamrznutí nativní obrazovky): 0 (ne), 1 (ano) (0).

Příklad: `SAVE_ZMOD_DATA NEW_SAVE_CONFIG=0`

---
##### USE_SWAP

Používat SWAP (1):

- 0 - ne (*pouze pro přepájený procesor s 256 MB RAM*)
- 1 - ano, na EMMC
- 2 - ano, přednostně na USB FLASH (_pro odvážné; ve skutečnosti asi o 90 % pomalejší než EMMC_)

Příklad: `SAVE_ZMOD_DATA USE_SWAP=1`

---
##### CHINA_CLOUD

Zapnout čínské cloudové služby: 0 (ne), 1 (ano) (1).

Příklad: `SAVE_ZMOD_DATA CHINA_CLOUD=0`

[Vypnout čínské cloudy](Recommendations.md#zakažte-čínské-cloudové-služby)

I když jsou všechny cloudové možnosti vypnuty přes obrazovku, tiskárna se stále snaží posílat fotky, videa a telemetrii na čínské servery.

Nastavení tohoto parametru na 0 tyto „funkce“ částečně vypne.

**Pokud jsou čínské cloudy vypnuté, tiskárna nebude kontrolovat aktualizace továrního firmwaru.**

Pro aktualizaci továrního firmwaru zapněte čínské cloudy pomocí `SAVE_ZMOD_DATA CHINA_CLOUD=1`, restartujte a pokračujte v aktualizaci.

Místo toho můžete použít:

- [zmod.link](Zmod.md#zlink) - cloud pro správu tiskáren přes Fluidd/Mainsail.
- [Telegram bot](Telegram.md).

**Jak vypnout čínské cloudy na továrním firmwaru:**

- Naformátujte USB disk na FAT32 (MBR).
- Umístěte [flashforge_init.sh](https://github.com/ghzserg/zmod/blob/main/Native_firmware/cloud/rem/flashforge_init.sh) na USB.
- Vypněte tiskárnu.
- Vložte USB do tiskárny.
- Zapněte tiskárnu (jednou se restartuje).
- Vyjměte USB.

**Jak zapnout čínské cloudy na továrním firmwaru:**

- Naformátujte USB disk na FAT32 (MBR).
- Umístěte [flashforge_init.sh](https://github.com/ghzserg/zmod/blob/main/Native_firmware/cloud/orig/flashforge_init.sh) na USB.
- Postupujte stejně jako výše.

---
##### NICE

Nastavit prioritu procesu Klipper: 1 (nejnižší) až 40 (nejvyšší) (20).

Příklad: `SAVE_ZMOD_DATA NICE=20`

Čím vyšší priorita, tím více prostředků Klipper dostane, ale tím častěji padají Moonraker a kamera.

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

Nastavit dobu (v sekundách), po které se nativní obrazovka v režimu bez nativní obrazovky vypne. Výchozí: 180.

Poznámka: Nativní obrazovka potřebuje alespoň 5 sekund na nastavení Wi-Fi.

Příklad: `SAVE_ZMOD_DATA DISPLAY_OFF_TIMEOUT=120`

---
##### PRO_POWEROFF_TIMEOUT

Doba (v minutách), po které FF5M Pro vypne napájení. Výchozí: 0 (vypnuto).

Příklad: `SAVE_ZMOD_DATA PRO_POWEROFF_TIMEOUT=10`

---

##### SAVE_MOONRAKER

- 0 - načítat rozložení tlačítek maker ze Z-Mod (výchozí)
- 1 - změny tlačítek maker se ukládají lokálně ve Fluidd/Moonraker

Lokálně uložená makra jsou uložena v samostatné sekci.

Příklad: `SAVE_ZMOD_DATA SAVE_MOONRAKER=1`

---

##### SAVE_FILAMENT_SENSORS

- 0 - neukládat stav senzorů filamentu přes restart; budou vždy zapnuté (výchozí)
- 1 - ukládat stav senzorů přes restart; vypnutý senzor zůstane vypnutý i po restartu

Příklad: `SAVE_ZMOD_DATA SAVE_FILAMENT_SENSORS=1`

