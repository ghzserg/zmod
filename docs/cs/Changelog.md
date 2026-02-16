# Changelog

- [Historie verzí](#historie-verzí)
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

### Verze 1.6.6
27.01.2026

* Aktualizován Fluidd/Mainsail/Klipper
* Aktualizace pro Klipper, Fluidd, Mainsail a Moonraker jsou nezávislé na aktualizacích modu

### Verze 1.6.5
14.01.2026

* Aktualizován Fluidd/Mainsail/Klipper
* Jsou k dispozici další nastavení kamery
* Automatický výběr Z offsetu

### Verze 1.6.4
11.12.2025

* Vylepšená snadnost nastavení a použití
* Aktualizace Fluidd/Mainsail/Klipper
* Plugin notify
* Odstraněn praskavý zvuk IFS

### Verze 1.6.3
**25.11.2025 — Narozeniny ZMOD!**

* [zmod.link](https://zmod.link/link/) | [ZLINK](Zmod.md#zlink) — vzdálený přístup k tiskárně přes cloud
* Makro [SCREEN](System.md#screen) — pořízení snímku obrazovky tiskárny
* Makro [LOAD_ZOFFSET_NATIVE](Calibrations.md#load_zoffset_native) — přenos nastavení Z-offsetu z nativní obrazovky do režimu bez obrazovky
* [AD5X](AD5X.md): Přidán globální parametr [REMOVE_FILAMENT](Global.md#remove_filament) — vysunutí filamentu po dokončení tisku
* Přidán [plugin doporučených nastavení](https://github.com/ghzserg/recommend)
* Přidána podpora českého jazyka
* Implementována kontrola verze MCU pro Klipper 13
* [AD5X](AD5X.md): Přidáno tlačítko pro vyrovnávání
* [AD5X](AD5X.md): Opravy pro Klipper 13
* [AD5X](AD5X.md): Vylepšení čištění trysky
* [AD5X](AD5X.md): Odstraněn skřípavý zvuk IFS
* `CAMERA_ON VIDEO=video99` — test všech dostupných kamer
* Kontrola aktualizací po dokončení tisku
* Při provádění vyrovnávání podložky přes Fluidd/Mainsail se tenzometry vynulují — ale uživatel musí předem ručně vyčistit trysku a předehřát podložku
* Opraven `PURGE_LINE` — již netiskne přes podpory
* Opravena kolize s okrajem rámu při opakovaném tisku
* Opraveno zobrazení tenzometrů — zabraňuje absurdním hodnotám v řádech tun
* Opraveno vypínání ventilátoru komory po dokončení tisku
* Opraveno zobrazení zbývajícího času v GuppyScreen pro jiné než ruské lokalizace

### Verze 1.6.2

* [Podpora pluginů](https://wiki.zmod.link/Plugin/)
* [Plugin g28_tenz](https://github.com/ghzserg/g28_tenz) - Parkování osy Z pomocí tenzometrů
* [Plugin bambufy](https://github.com/function3d/bambufy) - Kompatibilní s Bambu Studio a Orca Slicer, zlepšuje ovládání věže, poskytuje přesné odhady času a spotřeby materiálu, snižuje odpad, podporuje rychlé změny barev a nabízí pokročilé funkce tisku. Od @function3d
* [Plugin nopoop](https://github.com/ghzserg/nopoop) - Maximální snížení odpadu od @ninjamida
* Fluidd: Podpora barev
* Mainsail: Podpora barev od @function3d, opraveny chyby 404 po obnovení
* Guppy: Podpora barev. Opravena integrace HA.
* Přidáno automatické připojování flash disků při práci s Guppy
* Přidáno povolení [WiFi](Global.md#wifi) přímo bez použití nativní obrazovky
* [AD5X](AD5X.md): Vyřešen problém s odpadní nádobou a řezáním filamentu v nových revizích
* [AD5X](AD5X.md): Podpora barev při obnovení tisku
* [AD5X](AD5X.md): Možnost vytvářet [vlastní typy filamentů a barev](AD5X.md#7-add-custom-filament-types) při práci bez nativní obrazovky
* Aktualizován Klipper a Moonraker
* Přidána podpora pro ens160.py od @minicx
* Přidán portugalský jazyk
* Opravy chyb
* Vylepšená kompatibilita s nejnovějšími verzemi nativního firmwaru

### Verze 1.6.1

- [AD5X ](AD5X.md) - Podpora Klipper 13. [UPDATE_MCU](System.md#update_mcu)
- [AD5X ](AD5X.md) - Teplotní senzor v hlavě
- [AD5X](AD5X.md) - Práce bez nativní obrazovky. IFS funguje plně s nastavením resetovaného množství
- Drobné opravy

### Verze 1.6.0

- AD5M - Podpora Klipper 13. [UPDATE_MCU](System.md#update_mcu)
- AD5M - Teplotní senzor v hlavě
- Drobné opravy

Díky za podporu mcu [@darksimpson](https://github.com/darksimpson)

Díky za podporu tenz [@minicx](https://github.com/loss-and-quick/)

### Verze 1.5.4

- AD5X - zvuk funguje
- AD5X - tenzometry a kontrola nárazu trysky na stůl fungují
- AD5X - telegram bot funguje
- AD5X - senzor přítomnosti filamentu funguje
- AD5X - instalace PID stolu tiskárny funguje
- AD5X - čištění trysky je obnoveno při odstranění karty stolu
- AD5X - testován provoz modu na firmwaru 1.0.9, 1.1.0, 1.1.1
- AD5X - vytvořen [flash disk instalující verzi obrazovky 1.0.7 a všechny ostatní moduly verze 1.1.1](Native_FW.md)
- AD5x - vytvořen [flash disk pro resetování tiskárny do továrního nastavení](Native_FW.md)
- AD5X - vytvořen [flash disk pro aktivaci modu po aktualizaci nativního firmwaru](Native_FW.md)

### Verze 1.5.3

* Opravena chyba Klipperu [#119](https://github.com/ghzserg/zmod/issues/119), která vyžadovala použití [tohoto](Recomendations.md#avoid-using-russian-characters-in-filenames)
* Kontrola trysky je nyní povolena při tisku z obrazovky okamžitě
* Drobné kosmetické opravy

### Verze 1.5.2

* Aktualizace struktury dokumentace díky @TMTYD
* Nové makro RESTORE_TAR_CONFIG
* Oprava zobrazení Guppy
* **AD5X** Oprava chyby HOME
* Aktualizace Moonrakeru
* Změna zrychlení parkování
* Výchozí povolený CHINA_CLOUD

### Verze 1.5.1

- **AD5X**: podpora firmwaru AD5X-1.0.8-1.0.5-20250418
- **AD5X**: oprava _LINE_PURGE
- **AD5X**: podpora aktualizace MCU IFS
- **AD5X**: oprava MESH_TEST
- **AD5X**: oprava _SMART_PARK
- **AD5X**: oprava driver_fan
- **AD5X**: oprava _HOME
- Kosmetické opravy CHECK_MD5
- Vrácení chamber_fan do moonrakeru
- Oprava vyloučení objektů
- Oprava guppyscreen pro různé jazyky

### Verze 1.5.0
Podpora jazyků rozhraní:

- ZMOD - angličtina, němčina, francouzština, italština, španělština, čínština, japonština, korejština
- GuppyScreen - angličtina, němčina, francouzština, italština, španělština

### Verze 1.4.3

- Automatická konfigurace webkamery.
- Oznámení při přepínání webových rozhraní.
- **AD5X**: Opraveno rychlé zavírání dialogů.
- **AD5X**: Opraveno parkování.
- Opraven problém s vypínáním obrazovky na novějších revizích tiskárny.

### Verze 1.4.2

- Vylepšená [detekce kolize trysky](Global.md#nozzle_control) s volitelnou pauzou místo vypnutí. Problém [#23](https://github.com/ghzserg/zmod/issues/23).
!!! note
    
- Kontrola trysky nefunguje na AD5X viz zde[#75](https://github.com/ghzserg/zmod/discussions/75#discussion-8196449)
- Vylepšená funkce kontroly systému.
- Aktualizované barevné schéma Fluidd.
- Přidán globální parametr [SAVE_MOONRAKER](Macros.md#save_moonraker) pro vlastní rozložení tlačítek maker.
- **AD5X**: Podpora GuppyScreen.
- **AD5X**: Nové makro [COLOR](Filament.md#color) pro správu typu/barvy filamentu.
- Revidované testování podložky před tiskem s [MESH_TEST](Macros.md#mesh_test).
- Opraveno:
- [#13](https://github.com/ghzserg/zmod/issues/13) (Tisk ve vzduchu po KAMP).
- [#14](https://github.com/ghzserg/zmod/issues/14) (Obnovení tisku přes tovární obrazovku).
- [#31](https://github.com/ghzserg/zmod/issues/27) (Zamrzání GuppyScreen).
- [#25](https://github.com/ghzserg/zmod/issues/25) (Kalibrace podložky AD5X).
- [#26](https://github.com/ghzserg/zmod/issues/26) (Spektrogram pásů AD5X).
- [#27](https://github.com/ghzserg/zmod/issues/27) (Chyby instalátoru AD5X).

### Verze 1.4.1

- MD5 kontroly souborů během instalace.
- **Pro verze**: Opravena funkčnost tlačítka napájení.
- Podpora pro non-MJPEG kamery.
- Alfa podpora pro FF5X:
Známé vlastnosti:

- Žádný Entware, takže NEW_SAVE_CONFIG a CLOSE_DIALOGS nefungují
- Žádné přehrávání hudby
- Žádná kalibrace PID stolu, protože není PID
- Při aktivaci kamery specifikujte VIDEO3
- Žádné tenzometry, v důsledku čehož není ochrana stolu a reset tenzometrů.
- Žádný senzor pohybu filamentu přístupný z klipperu

### Verze 1.4.0

- Aktualizován Moonraker, Fluidd, Python.
- [Obnovení po ztrátě napájení](Zmod.md#zrestore).
- [Analýza spektrogramu pásů](Macros.md#belts_shaper_calibration).
- Detekce zatížení podložky.
- Integrace [senzoru pohybu filamentu](Macros.md#motion_sensor).
- **GuppyScreen**: Vyloučení objektů, logování chyb, ladění PID, kalibrace pásů.
- Makra spouštěná vrstvou: [další vrstva](Macros.md#set_pause_next_layer) nebo [specifická vrstva](Macros.md#set_pause_at_layer).
- Logování zpráv na nativní obrazovce.
- Kalibrace Shaperu s [úpravou SCV](https://www.klipper3d.org/Config_Reference.html#printer).
- Makro [MUTE](Macros.md#mute) pro dočasné vypnutí zvuku.
- Nastavení [časového limitu displeje](System.md#display_off_timeout).
- Skript `power_off.sh` pro úkoly při vypnutí.
- Chytré parkování KAMP.
- Opraveno:
- Problémy s odstraněním/zakázáním modu.
- Detekce kolize trysky (aktivní pouze během tisku).
- Ovládání pohybu hlavy ve Fluidd/GuppyScreen.
- Funkčnost pauzy v režimu bez hlavy.
- Stabilita KAMP.

### Verze 1.3.1

- **GuppyScreen**: COLDPULL, ovládání PID, firmwarová retrakce, kalibrační workflow.
- Detekce kolize trysky omezena na aktivní tisky.
- Vylepšená stabilita režimu bez hlavy.
- Rychlejší zavírání dialogů s [NEW_SAVE_CONFIG](Macros.md#new_save_config).

### Verze 1.3.0

- Integrace [GuppyScreen](System.md#display_off).
- Experimentální podpora Klipper v12 (standardně vypnuta).
- Aktualizované nástroje SSH (`dropbear`).
- Paměťově optimalizovaný `mjpg_streamer`.
- Opravy vyloučení objektů (včetně podpor).
- [FIX_SCV](Global.md#fix_scv) pro grafy shaperu.
- [CHECK_SYSTEM](System.md#check_system) kontrola oprávnění souborů.
- Odstraněn [SOFT_REMOVE](Macros.md#soft_remove).

### Verze 1.1.2

- [CHECK_SYSTEM](System.md#check_system) pro kontroly integrity OS.
- [NOZZLE_CONTROL](Global.md#nozzle_control) nouzové vypnutí.
- [UPDATE_MCU](Macros.md#update_mcu) aktualizátor firmwaru.
- Ladění priority procesů přes [NICE](Macros.md#nice).
- Experimentální [FIX_E0011](Global.md#fix_e0011) pro chyby homingu.
- Optimalizace EMMC.

### Verze 1.1.1

- Opraven [LOAD_CELL_TARE](Macros.md#load_cell_tare) od Alexandra K.
- Odstraněny zastaralé parametry.
- Sekvence parkování osy Z.
- Makro [CAMERA_RESTART](Macros.md#camera_restart).
- Opravy zrušení tisku.
- EXCLUDE_OBJECT_DEFINE od Igora Polunovskiyho.
- Perzistence motoru při opakovaných tiscích.
- [TEST_EMMC](Macros.md#test_emmc) hlášení opotřebení.

### Verze 1.1.0

- Aktualizace Moonrakeru.
- Rychlejší spuštění Moonrakeru.
- Skryté zastaralé makra.
- Požadavek na vyhřátou podložku pro reset tenzometrů.
- Nové parametry:
- [ALTER_CELL_TARE](Macros.md#alter_cell_tare) pro chyby senzorů.
- [CELL_WEIGHT](Macros.md#cell_weight) kalibrační práh.
- Přepínač [CHINA_CLOUD](Global.md#china_cloud).
- Opravy ventilátoru pro Pro verzi.
- Synchronizace časové zóny.

### Verze 1.0.5

- Možnost restartu firmwaru [AUTO_REBOOT](Macros.md#auto_reboot).
- Optimalizované použití G28.
- Univerzální [MD5 kontroly](System.md#check_md5).
- [MEM](Macros.md#mem) monitorování paměti.
- Prioritizace procesu Klipper.
- [BED_LEVEL_SCREWS_TUNE](Calibrations.md#bed_level_screws_tune) správa teploty.
- [Oprava E0017](Global.md#fix_e0017).

### Verze 1.0.4

- [Firmwarová retrakce](FAQ.md#what-is-firmware-retraction).
- Automatická aktivace ventilátoru driveru.
- [TEST_EMMC](Macros.md#test_emmc) testy rychlosti.
- [CLEAR_EMMC](System.md#clear_emmc) čištění logů.
- Automatické čištění Telegram bota.
- Záloha [LINE_PURGE](Global.md#clear).

### Verze 1.0.0

- Aktualizace přes síť.
- [CAMERA_ON](Zmod.md#camera_on) výběr zařízení.

### Verze 0.2.4

- Upozornění na aktualizace z USB.
- Priorita vyrovnávání obrazovky.
- Umístění tlačítka pauzy.
- Automatický restart instalátoru.

### Verze 0.2.3

- [M600](Macros.md#m600) změna filamentu.
- Varování při validaci MD5.

### Verze 0.2.2

- [FAST_CLOSE_DIALOGS](Macros.md#fast_close_dialogs).
- [LEVELING_PRINT_FILE](Macros.md#leveling_print_file) nativní vyrovnávání podložky.
- [COLDPULL](Filament.md#coldpull) čištění trysky.
- Parametry [SAVE_ZMOD_DATA](Global.md#save_zmod_data):
- `PRINT_LEVELING`: Nativní vyrovnávání podložky.
- `USE_KAMP`: Adaptivní mesh.
- `CLOSE_DIALOGS`: Automatické zavírání dialogů.
- `USE_SWAP`: Správa paměti.

### Verze 0.2.1.1

- Asynchronní přehrávání MIDI.
- [STOP_MOTOR](Global.md#save_zmod_data) po tisku.
- Časovač [AUTO_REBOOT](Global.md#save_zmod_data).
- [PRECLEAR](Global.md#save_zmod_data) čištění trysky.

### Verze 0.2.1

- Kalibrace [ZSHAPER](Calibrations.md#zshaper).
- Opravy režimu bez hlavy.

### Verze 0.2.0

- Aktualizace Fluidd/Mainsail.
- [NEW_SAVE_CONFIG](Macros.md#new_save_config) ukládání bez zamrzání.
- Parametry [SAVE_ZMOD_DATA](Global.md#save_zmod_data):
- Jas LED.
- MIDI spouštěče.

### Verze 0.1.8

- Integrace Telegram bota.
- Makra pro správu SSH.

### Verze 0.1.7

- Opravy stability maker.
- [STOP_ZMOD](Macros.md#stop_zmod) ovládání služby.

### Verze 0.1.6

- [KAMP](Calibrations.md#kamp) adaptivní meshing.
- Opravy kalibrace PID.

### Verze 0.1.5

- [ZSHAPER](Calibrations.md#zshaper) export do CSV.
- Kalibrace podložky s ohledem na teplotu.

### Verze 0.1.4

- Optimalizace paměti kamery.
- [CAMERA_ON](Zmod.md#camera_on) ovládání rozlišení.

### Verze 0.1.3

- Podpora přehrávání MIDI.
- Oddělení uživatelské konfigurace.

### Verze 0.1.1

- Režim bez hlavy ([DISPLAY_OFF](System.md#display_off)).
- [MEM](Macros.md#mem) monitor prostředků.

### Verze 0.0.9-fix

- Opravy instalátoru.

### Verze 0.0.9

- Počáteční podpora pauzy/obnovení/zrušení.
- Makra [REBOOT](Macros.md#reboot)/[SHUTDOWN](Macros.md#shutdown).