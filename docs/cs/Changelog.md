# Changelog

- [Historie verzí](#historie-verzí)
      - [Verze 1.7.5](#verze-175)
      - [Verze 1.7.4](#verze-174)
      - [Verze 1.7.3](#verze-173)
      - [Verze 1.7.2](#verze-172)
      - [Verze 1.7.1](#verze-171)
      - [Verze 1.7.0](#verze-170)
      - [Verze 1.6.6](#verze-166)
      - [Verze 1.6.5](#verze-165)
      - [Verze 1.6.4](#verze-164)
      - [Verze 1.6.3](#verze-163)
      - [Verze 1.6.2](#verze-162)
      - [Verze 1.6.1](#verze-161)
      - [Verze 1.6.0](#verze-160)
      - [Verze 1.5.4](#verze-154)
      - [Verze 1.5.3](#verze-153)
      - [Verze 1.5.2](#verze-152)
      - [Verze 1.5.1](#verze-151)
      - [Verze 1.5.0](#verze-150)
      - [Verze 1.4.3](#verze-143)
      - [Verze 1.4.2](#verze-142)
      - [Verze 1.4.1](#verze-141)
      - [Verze 1.4.0](#verze-140)
      - [Verze 1.3.1](#verze-131)
      - [Verze 1.3.0](#verze-130)
      - [Verze 1.1.2](#verze-112)
      - [Verze 1.1.1](#verze-111)
      - [Verze 1.1.0](#verze-110)
      - [Verze 1.0.5](#verze-105)
      - [Verze 1.0.4](#verze-104)
      - [Verze 1.0.0](#verze-100)
      - [Verze 0.2.4](#verze-024)
      - [Verze 0.2.3](#verze-023)
      - [Verze 0.2.2](#verze-022)
      - [Verze 0.2.1.1](#verze-0211)
      - [Verze 0.2.1](#verze-021)
      - [Verze 0.2.0](#verze-020)
      - [Verze 0.1.8](#verze-018)
      - [Verze 0.1.7](#verze-017)
      - [Verze 0.1.6](#verze-016)
      - [Verze 0.1.5](#verze-015)
      - [Verze 0.1.4](#verze-014)
      - [Verze 0.1.3](#verze-013)
      - [Verze 0.1.1](#verze-011)
      - [Verze 0.0.9-fix](#verze-009-fix)
      - [Verze 0.0.9](#verze-009)

---

## Historie verzí

### Verze 1.7.5
28.10.2026

* Z-Mod: Podpora formátu 3MF
* Z-Mod: Při tisku 3MF probíhá přiřazení barev okamžitě — [preprocesor](/cs/Global/#force_md5) už není potřeba
* Z-Mod: Rychlý KAMP — zapíná se automaticky a funguje bez pomalého vylučování objektů. U 3MF jsou data pro KAMP k dispozici okamžitě, u G-code po prohledání souboru
* C5Pro: Podpora až 100 barev v souboru s přiřazením ke 4 extruderům
* Nové makro [PLUGINS](/cs/Global/#plugins) — nabídka správy pluginů
* Nové makro [_USER_PREPARE_PRINT](/cs/Main/#_user_prepare_print) — volá se před odesláním souboru k tisku
* Nový globální parametr [PURGE_ALL_EXTRUDERS](/cs/Global/#purge_all_extruders) — profouknutí všech použitých extruderů při startu tisku
* Nový globální parametr [UNUSED_EXTRUDERS_OFF_TIME](/cs/Global/#unused_extruders_off_time) — vypnutí ohřevu nečinných extruderů po nastavené době
* Telegram bot podpory [@zmod_help_bot](https://t.me/zmod_help_bot) nyní využívá AI
* Fluidd: Podpora 3MF
* Mainsail: Podpora 3MF
* Moonraker: Podpora 3MF
* Opravy chyb

**Změny přijaté do hlavních projektů:**

* Fluidd: seskupování akčních tlačítek v dialozích prompt [#1977](https://github.com/fluidd-core/fluidd/pull/1977)
* Mainsail: podpora HEX barev ve třetím parametru prompt maker, společně s @function3d [#2687](https://github.com/mainsail-crew/mainsail/pull/2687)
* OrcaSlicer (bude ve verzi 2.5.0, nyní v betě):
    * Tolerance zjednodušení obrysů vylučovaných objektů je nyní uživatelským nastavením [#16503](https://github.com/OrcaSlicer/OrcaSlicer/pull/16503)
    * Pro AD5M/AD5M Pro, AD5X, Creator 5 / 5 Pro nastavena tolerance 0.2 mm — méně bodů obrysu, více objektů na podložce bez chyby „Timer too close“ [#16687](https://github.com/OrcaSlicer/OrcaSlicer/pull/16687)
    * Skripty postprocesingu se aplikují na G-code uvnitř .gcode.3mf [#16464](https://github.com/OrcaSlicer/OrcaSlicer/pull/16464)
    * Opraven posun bbox první vrstvy v plate_N.json na všech podložkách kromě první [#16860](https://github.com/OrcaSlicer/OrcaSlicer/pull/16860)

### Verze 1.7.4
24.09.2026 

* C5Pro: Funguje vše, co na AD5X, kromě Klipperu 13 
* C5Pro: Přidán režim bez nativní obrazovky 
* C5Pro: Přidány kalibrace: extruderů, VFA 
* C5Pro: Streamování obrazovky tiskárny 
* AD5X: Streamování obrazovky tiskárny 
* GuppyScreen: Podpora pro více extruderů

### Verze 1.7.3
09.09.2026

* Alfa podpora Creator 5 / Creator 5 Pro (bez podpory režimu bez nativní obrazovky a Klipperu 13, ne všechna makra otestována)
* AD5M: Podpora pro nativní firmware 5.1.9
* AD5X: Zrychlení cyklu dotazování od @ninjamida

### Verze 1.7.2
16.08.2026

* Aktualizovány Fluidd/Mainsail/Klipper


### Verze 1.7.1
14.05.2026

* Aktualizovány Fluidd/Mainsail/Klipper
* Automatické obnovení konfigurace GuppyScreen, pokud ji uživatel smaže
* Ochrana Klipperu před OOM-killerem
* Výpis událostí načtení/vymazání `BED_MESH` do konzole
* Zápis `dmesg` do archivu konfigurace
* Oprava funkce Wi-Fi
* Indikace `SAVE_CONFIG...` při ukládání
* Kontrola zaseknutí tenzometrů
* Snížení podložky o 5 mm při pozastavení z nativní obrazovky
* Makro `IP` – výpis IP adresy do konzole po spuštění
* Rebranding: `ZMOD` → `Z-Mod`

### Verze 1.7.0
15.03.2026

* Aktualizovány Fluidd/Mainsail/Klipper
* [NoPoop 2](/cs/AD5X/#čištění-řízené-slicerem-slicer-controlled-purge) od @ninjamida
* HelixScreen - alternativní obrazovka. (`ENABLE_EXTRA_PLUGINS`, `DISPLAY_OFF HELIX=1`)
* Na vydání této verze se významně podílel @xyzroe

### Verze 1.6.6
27.01.2026

* Aktualizovány Fluidd/Mainsail/Klipper
* Aktualizace pro Klipper, Fluidd, Mainsail a Moonraker jsou nezávislé na aktualizacích modu

### Verze 1.6.5
14.01.2026

* Aktualizovány Fluidd/Mainsail/Klipper
* Jsou k dispozici další nastavení kamery
* Automatické ladění Z-offsetu

### Verze 1.6.4
11.12.2025

* Jednodušší nastavení a použití
* Aktualizace Fluidd/Mainsail/Klipper
* Plugin notify
* Odstraněno praskání IFS

### Verze 1.6.3
25.11.2025 — Z-Mod slaví první rok!

* [zmod.link](https://zmod.link/link/) | [ZLINK](/cs/Zmod/#zlink) — vzdálený přístup k tiskárně přes cloud
* Makro [SCREEN](/cs/System/#screen) — pořízení snímku obrazovky tiskárny
* Makro [LOAD_ZOFFSET_NATIVE](/cs/Calibrations/#load_zoffset_native) — přenos nastavení Z-offsetu z nativní obrazovky do režimu bez nativní obrazovky
* [AD5X](AD5X.md): Přidán globální parametr [REMOVE_FILAMENT](/cs/Global/#remove_filament) — vysunutí filamentu po dokončení tisku
* Přidán [plugin doporučených nastavení](https://github.com/ghzserg/recommend)
* Přidána podpora českého jazyka
* Implementována kontrola verze MCU pro Klipper 13
* [AD5X](AD5X.md): Přidáno tlačítko pro měření sítě podložky
* [AD5X](AD5X.md): Opravy pro Klipper 13
* [AD5X](AD5X.md): Vylepšení čištění trysky
* [AD5X](AD5X.md): Odstraněno praskání IFS
* `CAMERA_ON VIDEO=video99` — test všech dostupných kamer
* Kontrola aktualizací po dokončení tisku
* Při měření sítě podložky přes Fluidd/Mainsail se tenzometry vynulují — ale uživatel musí předem ručně vyčistit trysku a předehřát podložku
* Opraven `PURGE_LINE` — již netiskne přes podpory
* Opraven náraz do okraje při opakovaném tisku
* Opraveno zobrazení tenzometrů — zabraňuje absurdním hodnotám v řádech tun
* Opraveno vypínání ventilátoru komory po dokončení tisku
* Opraveno zobrazení zbývajícího času v GuppyScreen pro jiné než ruské lokalizace

### Verze 1.6.2
27.10.2025

* [Podpora pluginů](/cs/Plugin/)
* [Plugin g28_tenz](https://github.com/ghzserg/g28_tenz) - Parkování osy Z pomocí tenzometrů
* [Plugin bambufy](https://github.com/function3d/bambufy) - Kompatibilní s Bambu Studio a Orca Slicer, zlepšuje správu čisticí věže, poskytuje přesné odhady času a spotřeby materiálu, snižuje odpad, podporuje rychlé změny barev a nabízí pokročilé funkce tisku. Od @function3d
* [Plugin nopoop](https://github.com/ghzserg/nopoop) - Maximální snížení odpadu od @ninjamida
* Fluidd: Podpora barev
* Mainsail: Podpora barev od @function3d, opraveny chyby 404 po obnovení
* Guppy: Podpora barev. Opravena integrace HA.
* Přidáno automatické připojování flash disků při práci s Guppy
* Přidána možnost zapnout [Wi-Fi](/cs/Global/#wifi) přímo bez nativní obrazovky
* [AD5X](AD5X.md): Vyřešeny problémy s odpadním košem a řezáním filamentu v nových revizích
* [AD5X](AD5X.md): Podpora barev při obnovení tisku
* [AD5X](AD5X.md): Možnost vytvářet [vlastní typy filamentů a barev](AD5X.md#7-přidat-nebo-odebrat-typy-filamentů) při práci bez nativní obrazovky
* Aktualizovány Klipper a Moonraker
* Přidána podpora pro ens160.py od @minicx
* Přidán portugalský jazyk
* Opravy chyb
* Vylepšená kompatibilita s nejnovějšími verzemi nativního firmwaru

### Verze 1.6.1
06.09.2025

- [AD5X](AD5X.md) - Podpora Klipperu 13. [UPDATE_MCU](/cs/System/#update_mcu)
- [AD5X](AD5X.md) - Teplotní senzor v hlavě
- [AD5X](AD5X.md) - Práce bez nativní obrazovky. IFS plně funguje, s nastavitelným množstvím proplachu
- Drobné opravy

### Verze 1.6.0
14.08.2025

- AD5M - Podpora Klipperu 13. [UPDATE_MCU](/cs/System/#update_mcu)
- AD5M - Teplotní senzor v hlavě
- Drobné opravy

Díky za podporu MCU: [@darksimpson](https://github.com/darksimpson)

Díky za podporu tenzometrů: [@minicx](https://github.com/loss-and-quick/)

### Verze 1.5.4
28.06.2025

- AD5X - zvuk funguje
- AD5X - tenzometry a kontrola nárazu trysky do podložky fungují
- AD5X - Telegram bot funguje
- AD5X - senzor přítomnosti filamentu funguje
- AD5X - kalibrace PID podložky funguje
- AD5X - obnoveno čištění trysky při měření sítě podložky
- AD5X - testován provoz modu na firmwaru 1.0.9, 1.1.0, 1.1.1
- AD5X - vytvořen [flash disk instalující verzi obrazovky 1.0.7 a všechny ostatní moduly verze 1.1.1](/cs/Native_FW/)
- AD5X - vytvořen [flash disk pro resetování tiskárny do továrního nastavení](/cs/Native_FW/)
- AD5X - vytvořen [flash disk pro aktivaci modu po aktualizaci nativního firmwaru](/cs/Native_FW/)

### Verze 1.5.3
03.06.2025

* Opravena chyba Klipperu [#119](https://github.com/ghzserg/zmod/issues/119), kvůli které bylo nutné se v názvech objektů vyhýbat nelatinkovým znakům
* Kontrola trysky je nyní aktivní i při tisku z obrazovky
* Drobné kosmetické opravy

### Verze 1.5.2
15.05.2025

* Aktualizace struktury dokumentace díky @TMTYD
* Nové makro RESTORE_TAR_CONFIG
* Oprava zobrazení Guppy
* **AD5X** Oprava chyby HOME
* Aktualizace Moonrakeru
* Změna zrychlení parkování
* CHINA_CLOUD ve výchozím stavu zapnutý

### Verze 1.5.1
23.04.2025

- **AD5X**: podpora firmwaru AD5X-1.0.8-1.0.5-20250418
- **AD5X**: oprava _LINE_PURGE
- **AD5X**: podpora aktualizace MCU IFS
- **AD5X**: oprava MESH_TEST
- **AD5X**: oprava _SMART_PARK
- **AD5X**: oprava driver_fan
- **AD5X**: oprava _HOME
- Kosmetické opravy CHECK_MD5
- chamber_fan vrácen do Moonrakeru
- Oprava vyloučení objektů
- Oprava GuppyScreen pro různé jazyky

### Verze 1.5.0
17.04.2025
Podpora jazyků rozhraní:

- Z-Mod - angličtina, němčina, francouzština, italština, španělština, čínština, japonština, korejština
- GuppyScreen - angličtina, němčina, francouzština, italština, španělština

### Verze 1.4.3
23.03.2025

- Automatická konfigurace webkamery.
- Oznámení při přepínání webových rozhraní.
- **AD5X**: Opraveno rychlé zavírání dialogů.
- **AD5X**: Opraveno parkování.
- Opraven problém s vypínáním obrazovky na novějších revizích tiskárny.

### Verze 1.4.2
19.03.2025

- Vylepšená [detekce kolize trysky](/cs/Global/#nozzle_control) s volitelnou pauzou místo vypnutí. Úkol [#23](https://github.com/ghzserg/zmod/issues/23).
- Kontrola trysky nefunguje na AD5X, viz [#75](https://github.com/ghzserg/zmod/discussions/75#discussion-8196449)
- Vylepšená funkce kontroly systému.
- Aktualizované barevné schéma Fluidd.
- Přidán globální parametr [SAVE_MOONRAKER](/cs/Global/#save_moonraker) - umožňuje vlastní rozložení tlačítek maker.
- **AD5X**: Funguje GuppyScreen.
- **AD5X**: Nové makro [COLOR](/cs/Filament/#color) - správa typu a barvy plastu, zavádění a vysouvání filamentu z barevných cívek.
- Změněn algoritmus testování podložky před tiskem, nový globální parametr [MESH_TEST](/cs/Global/#mesh_test).
- Opraveno:
    - [#13](https://github.com/ghzserg/zmod/issues/13) (Tisk ve vzduchu po KAMP).
    - [#14](https://github.com/ghzserg/zmod/issues/14) (Obnovení tisku na nativní obrazovce).
    - [#31](https://github.com/ghzserg/zmod/issues/31) (Zamrzání GuppyScreen).
    - [#25](https://github.com/ghzserg/zmod/issues/25) (AD5X. Nesprávně funguje kalibrace podložky).
    - [#26](https://github.com/ghzserg/zmod/issues/26) (AD5X. Chybí spektrogram řemenů).
    - [#27](https://github.com/ghzserg/zmod/issues/27) (AD5X. Chyba instalátoru).

### Verze 1.4.1
09.03.2025

- Při instalaci Z-Mod se kontroluje MD5 součet rozbalených souborů. Tiskárna při kopírování souborů z flash disku do souborového systému občas soubory poškodí.
- Makro CHECK_SYSTEM nově obsahuje vlastní kontrolu systému
- Na verzi Pro funguje tlačítko vypnutí
- Lze použít i jiné než MJPEG kamery
- Alfa podpora FF5X:
  Známé zvláštnosti:

  - Není Entware, proto nefungují NEW_SAVE_CONFIG a CLOSE_DIALOGS
  - Nehraje hudba
  - Není kalibrace PID podložky, protože podložka není řízena PID
  - Při aktivaci kamery uveďte VIDEO3
  - Nejsou tenzometry, a proto chybí ochrana podložky a reset tenzometrů.
  - Není senzor pohybu filamentu dostupný z Klipperu

### Verze 1.4.0
04.03.2025

- Aktualizace Moonraker, Fluidd, Python
- [Obnovení tisku po výpadku napájení](/cs/Zmod/#zrestore)
- [Spektrogram řemenů](/cs/Macros/#belts_shaper_calibration)
- Kontrola vložené desky: ověřuje, že síť podložky přibližně odpovídá aktuálně vložené desce
- Podpora [senzoru pohybu filamentu](/cs/Global/#motion_sensor)
- GuppyScreen: vylučování objektů, výpis chyb, retrakce z firmwaru, kalibrace PID, reset hmotnosti, podpora FF5M Pro
- Spuštění makra v [další vrstvě](/cs/Macros/#set_pause_next_layer) nebo [v konkrétní vrstvě](/cs/Macros/#set_pause_at_layer)
- Logování všech zpráv nativní obrazovky v Klipperu a odpovědí na ně
- Změněn algoritmus kalibrace shaperů, grafy shaperů zohledňují SCV
- Makro MUTE - vypnutí zvuku do restartu
- Nový parametr - [doba vypnutí nativní obrazovky](/cs/Global/#display_off_timeout)
- Nový soubor `mod_data/power_off.sh` - umožňuje psát kód, který se spustí při vypnutí tiskárny
- Při použití KAMP je zapnuto chytré parkování
- Opraveno odstranění, vypnutí a úplné odstranění modu
- Opraveno předčištění
- Opravena kontrola nárazu trysky do podložky. Funguje pouze během tisku.
- Opraven pohyb hlavy tlačítky ve Fluidd/GuppyScreen
- Opravena pauza v režimu bez nativní obrazovky
- Opraveno KAMP

### Verze 1.3.1

- Vylepšení GuppyScreen: COLDPULL, ovládání PID, retrakce z firmwaru, kalibrace shaperů, kalibrace řemenů, kosmetické opravy
- Kontrola trysky nyní funguje pouze při tisku
- BELTS_SHAPER_CALIBRATION
- Vylepšený režim bez nativní obrazovky
- Vylepšené pomalé zavírání oken a NEW_SAVE_CONFIG

### Verze 1.3.0
08.02.2025

- Podpora [GuppyScreen](/cs/System/#display_off)
- Klipper 12, [v testovacím režimu](/cs/Macros/#update_mcu) (ve výchozím stavu vypnutý). Nefunguje v něm: ohřev extruderu, teplota extruderu, váhy.
- SSH klient a SSH server `dropbear` nahrazeny aktuální verzí.
- `mjpg_streamer` nahrazen verzí s patchem od Alexandra, která snižuje spotřebu paměti 2-4krát.
- Opraveno vylučování objektů od Igor Polunovskiy (nyní se zohledňují podpory).
- Grafy shaperů zohledňují SCV ([square_corner_velocity](https://www.klipper3d.org/Config_Reference.html#printer)) [FIX_SCV](/cs/Global/#fix_scv).
- [CHECK_SYSTEM](/cs/System/#check_system) - přidána kontrola oprávnění souborů a adresářů, kontrola odkazů a obnova.
- Odstraněno makro SOFT_REMOVE.
- Aktualizace Moonraker, Fluidd, Mainsail

### Verze 1.1.2
03.02.2025

- Nové makro [CHECK_SYSTEM](/cs/System/#check_system) - kontrola operačního systému tiskárny na poškozené soubory.
- Nové makro [NOZZLE_CONTROL](/cs/Global/#nozzle_control) - nouzové vypnutí tiskárny při odtržení dílu nebo nárazu trysky do podložky.
- Nové makro [UPDATE_MCU](/cs/Macros/#update_mcu) - aktualizace MCU tiskárny.
- Nový globální příznak [NICE](/cs/Global/#nice) - priorita procesu Klipper, 1 - nejnižší, 40 - nejvyšší (20).
- Nový globální příznak [FIX_E0011](/cs/Global/#fix_e0011) - oprava chyby E0011 a také `Communication timeout during homing`
- Vyčištění smazaných souborů ze souborového systému tiskárny zrychluje EMMC.
- Spousta drobných oprav

### Verze 1.1.1
24.01.2025

- Opraven problém s pořadím, když se zpětné volání zablokuje v obsluze tlačítek [#6440](https://github.com/Klipper3d/klipper/pull/6440), který našel [Alexander K](https://github.com/drA1ex) - [LOAD_CELL_TARE](/cs/Macros/#load_cell_tare) nyní funguje správně.
- Odstraněny globální parametry: `ALTER_CELL_TARE`, `IGNORE_CELL_TARE`, `CELL_WEIGHT`
- Prodloužen timeout zsend. Vypisují se další zprávy.
- G28 nyní nejdříve zaparkuje Z, potom X a Y
- Nové makro [CAMERA_RESTART](/cs/Macros/#camera_restart) - restart alternativní implementace kamery
- Opraven kód zrušení tisku bez nativní obrazovky
- Implementace EXCLUDE_OBJECT_DEFINE od Igor Polunovskiy
- Při opakovaném tisku se motory nevypínají a tiskárna se nerestartuje, i když je to nastaveno v globálních parametrech
- Makro [TEST_EMMC](/cs/Macros/#test_emmc) vypisuje opotřebení EMMC
- Opraveno vypnutí čínských cloudů

### Verze 1.1.0
15.01.2025

- Aktualizace Moonraker
- Výrazně zrychlené spouštění Moonraker
- Skryto `level_h1`, `level_h2`, `level_h3`, `power_off`, `clear_power_off`, `level_clear`, `check_level_pin_alt`
- Reset tenzometrů v režimu bez nativní obrazovky používá implementaci Igor Polunovskiy
- Reset tenzometrů nyní pouze na nahřáté podložce
- Nový globální parametr `ALTER_CELL_TARE`. Umožňuje obejít chybu resetu tenzometrů.
- Nový globální parametr `CELL_WEIGHT` určuje hmotnost, při které se kalibrace tenzometrů neprovádí
- Nový globální parametr [CHINA_CLOUD](/cs/Global/#china_cloud) - umožňuje vypnout čínské cloudy
- Přepsána aktualizace konfigurace tiskárny
- Na verzi Pro nyní správně fungují ventilátory chlazení. Výchozí úhly 165/105
- Při kalibraci extruderu se nyní nastavuje rychlost ventilátoru
- Čas a časové pásmo v Moonraker nyní odpovídají času Klipperu
- Na kartě `Informace o systému` se zobrazuje verze nativního firmwaru.
- Mod je méně upovídaný

### Verze 1.0.5
13.01.2025

- Do [AUTO_REBOOT](/cs/Global/#auto_reboot) přidán parametr umožňující restart firmwaru
- G28 se v makrech volá jen když je to potřeba
- Algoritmus MD5 byl téměř celý přepsán. Kontrola MD5 nyní funguje odkudkoli a nevyžaduje ohřev podložky ani extruderu
- Vylepšené makro [MEM](/cs/Macros/#mem): nyní vypisuje paměť Moonraker, Klipper, obrazovky a využití SWAP
- Proces Klipper má vyšší prioritu než ostatní procesy
- Globální parametr [PRINT_LEVELING](/cs/Global/#print_leveling) nyní funguje i v režimu bez nativní obrazovky
- Makro [BED_LEVEL_SCREWS_TUNE](/cs/Calibrations/#bed_level_screws_tune) nyní správně používá teplotu
- Makro [TEST_EMMC](/cs/Macros/#test_emmc) umí testovat EMMC, USB flash i RAM.
- Swap lze nyní (ale není nutné) umístit na USB flash
- Makro [CLEAR_EMMC](/cs/System/#clear_emmc) - mazání logů a/nebo GCODE
- Řešení problému [E0017](/cs/Global/#fix_e0017)

### Verze 1.0.4
05.01.2025

- Podpora [retrakce z firmwaru](/cs/FAQ/#co-je-to-firmwarová-retrakce)
- Řešení problému [E0017](/cs/Global/#fix_e0017)
- Automatické zapnutí chlazení driverů při zapnutí motorů. Řeší kalibraci shaperů bez chlazení na stocku.
- Nové makro [TEST_EMMC](/cs/Macros/#test_emmc) - zapíše SIZE MB na EMMC a vypíše rychlost čtení/zápisu.
- Nové makro [CLEAR_EMMC](/cs/System/#clear_emmc) - vyčistí EMMC.
- Automatický [restart bota při práci přes SSH](/cs/Macros/#zssh_on)
- [Automatické mazání](https://github.com/ghzserg/zmod_ff5m/blob/1.4/telegram/docker-compose.yml) videí starších než 10 dní v botovi.
- Nastavení [požadovaného časového pásma](https://github.com/ghzserg/zmod_ff5m/blob/1.4/telegram/docker-compose.yml) v botovi
- Automatický přechod z čištění KAMP [LINE_PURGE](/cs/Global/#clear) na _CLEAR2, pokud nejsou nalezeny objekty
- Opraveno [SKIP_ZMOD](/cs/Macros/#skip_zmod)
- Aktualizace Fluidd/Mainsail už nevyžaduje restart
- Přepnutí z Fluidd na Mainsail už nevyžaduje restart
- Z-Mod upozorní na soubory, které používají oblouky
- Opraven skript `addMD5.sh`
- Opraveno ovládání chlazení driverů v režimu bez nativní obrazovky
- Při startu tiskárny v režimu bez nativní obrazovky se načítá síť podložky `auto`

### Verze 1.0.0
23.12.2024

- Nový systém aktualizací a instalace; téměř všechny aktualizace lze nyní získat přes síť
- Nový parametr makra [CAMERA_ON](/cs/Zmod/#camera_on), VIDEO - video zařízení (video0)

### Verze 0.2.4
21.12.2024

- Z-Mod automaticky hlásí, zda je nutná aktualizace z flash disku - nyní červeně
- Pokud se používá měření sítě podložky nativní obrazovkou (PRINT_LEVELING=1), parametry FORCE_LEVELING, FORCE_KAMP, SKIP_LEVELING, MESH v START_PRINT se ignorují
- Pauza v pravém zadním rohu i při tisku z obrazovky
- Parametr PRECLEAR nyní funguje i při tisku s měřením sítě z obrazovky
- Změněn algoritmus instalace: po úspěšné instalaci už není nutné vyjímat flash disk - tiskárna se sama restartuje a instalační soubor smaže.

### Verze 0.2.3
19.12.2024

- Z-Mod automaticky hlásí, zda je nutná aktualizace z flash disku
- Vylepšené makro [M600](/cs/Macros/#m600) - výměna filamentu s pauzou během tisku
- Vylepšená kontrola MD5 - nyní se zobrazí zpráva, pokud MD5 není nalezen

### Verze 0.2.2
17.12.2024

- Nové makro [FAST_CLOSE_DIALOGS](/cs/Macros/#fast_close_dialogs) - rychlé zavírání dialogů nativní obrazovky. Používá se k zavření okna na konci tisku nebo při jeho zrušení. *Pro rychlé zavírání přejděte na obrazovce tiskárny do "Nastavení" -> "Ikona WiFi" -> "Režim sítě" a zapněte "Pouze místní sítě".* Implementace: @darksimpson
- Nové makro `LEVELING_PRINT_FILE` - tisk souboru s měřením sítě podložky z nativní obrazovky. *Pro LEVELING_PRINT_FILE přejděte na obrazovce tiskárny do "Nastavení" -> "Ikona WiFi" -> "Režim sítě" a zapněte "Pouze místní sítě"*
- Nové makro [COLDPULL](/cs/Filament/#coldpull) - cold pull (čištění trysky) bez násilí. Implementace [tohoto algoritmu](https://t.me/FF_5M_5M_Pro/2836/447172)
- Nové parametry [SAVE_ZMOD_DATA](/cs/Global/#save_zmod_data):
    - [PRINT_LEVELING](/cs/Global/#save_zmod_data) - při každém tisku měřit síť podložky nativní obrazovkou 0-ne, 1-ano (0). *Pro měření sítě z nativní obrazovky přejděte do "Nastavení" -> "Ikona WiFi" -> "Režim sítě" a zapněte "Pouze místní sítě"*
    - [USE_KAMP](/cs/Global/#save_zmod_data) - kde je to možné, použít adaptivní síť podložky (KAMP) místo plné sítě 0-ne, 1-ano (0). *Umožňuje použít KAMP při měření sítě přes síť z nativní obrazovky*
    - [CLOSE_DIALOGS](/cs/Global/#save_zmod_data) - automaticky zavírat dialogy na konci a při zrušení tisku 0-ne, 1-ano pomalu, 2-ano rychle. *Pro rychlé zavírání přejděte do "Nastavení" -> "Ikona WiFi" -> "Režim sítě" a zapněte "Pouze místní sítě"* (0).
    - [USE_SWAP](/cs/Global/#save_zmod_data) - použít SWAP 0-ne, 1-ano (1). *Pokud nemáte přepájený procesor, je SWAP povinný*

### Verze 0.2.1.1
10.12.2024

- Asynchronní algoritmus přehrávání MIDI
- Oprava instalace
- Opraven SHUTDOWN z hlavního menu
- Nový skript [addMD5.sh](https://github.com/ghzserg/zmod_ff5m/blob/1.4/addMD5.sh) - kontrola MD5 pro macOS/Linux - díky Alexandrovi
- Nový parametr [STOP_MOTOR](/cs/Global/#save_zmod_data) - automaticky vypnout motory 25 sekund po skončení/zrušení tisku.
- Nový parametr [AUTO_REBOOT](/cs/Global/#save_zmod_data) - automaticky restartovat tiskárnu 1,5 minuty po tisku.
- Nový parametr [PRECLEAR](/cs/Global/#save_zmod_data) - použít předčištění trysky v START_PRINT
- Nová hudba: BattleCity, IndianaJones, WeWillRockYou od [@drmax_gc](https://t.me/drmax_gc)

### Verze 0.2.1
10.12.2024

- Grafy shaperů přímo z tiskárny. Makro [ZSHAPER](/cs/Calibrations/#zshaper)
- Oprava chyby v režimu bez nativní obrazovky

### Verze 0.2.0
09.12.2024

- Aktualizace Fluidd/Mainsail
- Přidány mc, opkg, gdb
- Restart přes horní menu Fluidd
- Opravy chyb
- Výrazné přepracování makra [START_PRINT](/cs/Main/#start_print)
- Makro [NEW_SAVE_CONFIG](/cs/Macros/#new_save_config) - uložit změny/restartovat Klipper bez zamrznutí nativní obrazovky. Implementace: @darksimpson
- Makro [CLOSE_DIALOGS](/cs/Macros/#close_dialogs) - zavřít okna na konci a při zrušení tisku. Implementace: @darksimpson
- Makro [STOP_ZMOD](/cs/Macros/#stop_zmod) - vypnout Moonraker
- Makro [START_ZMOD](/cs/Macros/#start_zmod) - zapnout Moonraker
- Makro [SAVE_ZMOD_DATA](/cs/Global/#save_zmod_data) - uložit parametry Z-Mod
    - CLOSE_DIALOGS - automaticky zavírat dialogy na konci a při zrušení tisku 0-ne, 1-ano (0)
    - NEW_SAVE_CONFIG - použít alternativní NEW_SAVE_CONFIG při kalibraci PID 0-ne, 1-ano (0)
    - LED - jas LED při zapnutí (50)
    - MIDI_ON - přehrát MIDI při zapnutí ("")
    - MIDI_START - přehrát MIDI při startu tisku ("")
    - MIDI_END - přehrát MIDI na konci tisku ("")

### Verze 0.1.8
04.12.2024

- Podpora připojení Telegram bota
- Makro [ZSSH_ON](/cs/Macros/#zssh_on) - ZSSH_ON SSH_SERVER SSH_PORT SSH_USER VIDEO_PORT MOON_PORT
- Makro [ZSSH_OFF](/cs/Macros/#zssh_off) - vypnout SSH klienta
- Makro [ZSSH_RESTART](/cs/Macros/#zssh_restart) - restart SSH klienta

### Verze 0.1.7
03.12.2024

- Mnoho oprav maker
- Makro [STOP_ZMOD](/cs/Macros/#stop_zmod) - dočasně vypne Fluidd/Mainsail a Moonraker

### Verze 0.1.6
02.12.2024

- Opraveno umístění logů
- Opraveno makro [LOAD_CELL_TARE](/cs/Macros/#load_cell_tare)
- Opraveno makro kalibrace PID extruderu a podložky
- Makro [CLEAR_NOZZLE](/cs/Macros/#clear_nozzle) - čištění trysky jako v nativním firmwaru
- Makro [KAMP](/cs/Calibrations/#kamp) extruder_temp=[nozzle_temperature_initial_layer] bed_temp=[bed_temperature_initial_layer_single]. Adaptivní síť podložky s čištěním trysky.
- [AUTO_FULL_BED_LEVEL](/cs/Calibrations/#auto_full_bed_level) - makro kompletně přepsáno

### Verze 0.1.5
30.11.2024

- Přidán Mainsail. Přepínání makrem WEB
- Makro STOP - vypne motory, zapisuje se do koncového gcode
- Makro [ZSHAPER](/cs/Calibrations/#zshaper) - kalibrace shaperů a export CSV do /mod_data v konfiguraci. Další analýza přes [Klipper-Input-Shaping-Assistant](https://github.com/theycallmek/Klipper-Input-Shaping-Assistant/releases)
- Makro [LOAD_CELL_TARE](/cs/Macros/#load_cell_tare) - reset tenzometrů
- Opravena kalibrace podložky. Nyní lze nastavit teplotu podložky a extruderu pro kalibraci. Výchozí 120/80
- Opraveno vypínání obrazovky v režimu bez nativní obrazovky. Vypne se po 4 minutách.

### Verze 0.1.4
29.11.2024

- Přidáno ovládání kamery z modu. Šetří paměť a umožňuje pracovat s kamerou při vypnuté obrazovce. Lze také změnit rozlišení kamery. (Implementace inspirována Pavlem Mironovem)
- Opravena chyba instalátoru, který v předchozí verzi mohl odstranit [heater_bed] z konfiguračních souborů
- Nové obrázky při instalaci. Vytvořil [@drmax_gc](https://t.me/drmax_gc)
- Makra rozdělena do kategorií a přeložena do ruštiny
- Makro [DATE_GET](/cs/Macros/#date_get) - zobrazit aktuální čas
- Makro [DATE_SET](/cs/Macros/#date_set) - nastavit aktuální čas
- Makro [CAMERA_ON](/cs/Zmod/#camera_on) - použít alternativní implementaci kamery
- Makro [CAMERA_OFF](/cs/Macros/#camera_off) - vypnout alternativní implementaci kamery

### Verze 0.1.3
28.11.2024

- Přidáno přehrávání MIDI. Soubory jsou v mod_data/midi - přístup přes kartu „Konfigurace“. Díky [@drmax_gc](https://t.me/drmax_gc)
- Makro [PLAY_MIDI](/cs/Macros/#play_midi). Přehraje melodii: PLAY_MIDI FILE=Pain-Shut-your-mouth.mid
- Makro `SOFT_REMOVE`. Odstraní pouze Z-Mod, ponechá audio, md5, root
- Po aktualizaci se nastavení Moonraker zachovají
- Uživatelská nastavení Klipperu přesunuta do mod_data/user.cfg
- Uživatelská nastavení Moonraker přesunuta do mod_data/user.moonraker.conf
- Při vypnutí obrazovky se na ní zobrazí text, že je obrazovka vypnutá. Díky @drmax_gc
- Opravena kalibrace podložky makrem. Podložka se nyní ohřívá.
- Opraveno seřízení podložky makrem. Podložka se nyní ohřívá.

### Verze 0.1.1
27.11.2024

- Podpora práce s vypnutým nativním displejem. Ušetří 20 MB RAM. Režim zapnete makrem DISPLAY_OFF. Klipper se restartuje a použije alternativní konfigurační soubory. Doporučuje se změřit síť podložky a uložit ji do profilu default. Po restartu bude obrazovka po 5 minutách nedostupná a načte se síť podložky z profilu default.
- Makro [MEM](/cs/Macros/#mem) - ukáže, kolik paměti se používá a kterou aplikací.
- Makro [DISPLAY_ON](/cs/System/#display_on) - vrátí obrazovku do standardního režimu, tiskárna se restartuje
- Makro [LED](/cs/Macros/#led) - zapne osvětlení na 50 %
- Makro [LED_ON](/cs/Macros/#led_on) - zapne osvětlení na 100 %
- Makro [LED_OFF](/cs/Macros/#led_off) - vypne osvětlení

### Verze 0.0.9-fix
25.11.2024

- Opravena chyba instalace.

### Verze 0.0.9
25.11.2024

- Pauza při tisku, zpracovávaná přes nativní obrazovku
- Obnovení po pauze, zpracovávané přes nativní obrazovku
- Zrušení tisku, zpracovávané přes nativní obrazovku
- [REBOOT](/cs/Macros/#reboot) - makro pro restart tiskárny
- [SHUTDOWN](/cs/Macros/#shutdown) - makro pro vypnutí tiskárny
- [SKIP_ZMOD](/cs/Macros/#skip_zmod) - makro pro restart bez spuštění Moonraker a Fluidd
- [REMOVE_ZMOD](/cs/Macros/#remove_zmod) - makro pro odstranění modu
- Opraveno: "Po pauze kvůli senzoru pohybu filamentu se tisk obnoví, ale tiskne ve vzduchu asi 3 cm nad místem, kde má"
