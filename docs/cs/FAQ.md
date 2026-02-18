# FAQ
## Často kladené otázky

!!! note
    Nainstalovali jste mod.
    
    Nechcete nic řešit - tiskněte jako dříve.
    
    Není třeba nic konfigurovat ani měnit.
    
    Rozhodli jste se, že jste připraveni jít dál - pokračujte čtením dokumentace.

---

## Úložiště konfigurace

Přístup do složky **mod_data** přes webové rozhraní Fluidd:
`Configuration` → `Configuration Files` → `mod_data`

- Vlastní nastavení Klipperu patří do `mod_data/user.cfg`, které může přepsat/doplnit `printer_base.cfg` a soubory zMod.
- Vlastní nastavení Moonrakeru patří do `mod_data/user.moonraker.conf`.
- Vlastní MIDI soubory jsou uloženy v `mod_data/midi/`.
- Globální nastavení modu se ukládají pomocí makra [SAVE_ZMOD_DATA](Global.md#save_zmod_data).
- Skripty pro vypnutí jsou uloženy v `mod_data/power_off.sh`.
- Skripty pro zapnutí jsou uloženy v `mod_data/power_on.sh`.

**Nemůžete provádět změny v souborech zmod a doplňků**, protože to naruší systém aktualizací.

Jakoukoliv funkci lze přepsat v `mod_data/user.cfg` nebo `printer.cfg`.

---

## Známé zvláštnosti: {#known-peculiarities}

- Během akcí jako `M109` (nahřívání extruderu), `M190` (nahřívání podložky), kalibrace PID nebo jakéhokoli úkolu pozastavujícího g-kód, se tovární obrazovka zasekne.
- Restartování Klipperu zasekne tovární obrazovku (pro restarty použijte [NEW_SAVE_CONFIG](Main.md#new_save_config)).
- Po zrušení tisku stiskněte "OK" na tovární obrazovce (použijte [CLOSE_DIALOGS](Main.md#close_dialogs) nebo [FAST_CLOSE_DIALOGS](Main.md#fast_close_dialogs)).

- Tovární obrazovka vždy načte profil `DEFAULT_MESH` při zahájení tisku a po tisku smaže profil `Default`.

---

## Poznámky k verzi bez obrazovky: {#notes-on-screenless-version}

- Odstraňte veškerý startovací g-kód a použijte makra [START_PRINT](Main.md#start_print) a [END_PRINT](Main.md#end_print).
- Tovární kamera je vypnutá; použijte alternativu přes [CAMERA_ON](Zmod.md#camera_on).
- Ručně nastavte [Z_OFFSET] v [START_PRINT](Main.md#start_print) nebo použijte [LOAD_ZOFFSET](Global.md#load_zoffset) k načtení uložených offsetů.
- Pokud chcete přenést z-offset z nativní obrazovky do režimu bez obrazovky, spusťte makro ```LOAD_ZOFFSET_NATIVE```, které přečte hodnotu z-offsetu z nativní obrazovky a aplikuje ji do režimu bez obrazovky.
- Mesh podložky `auto` se načítá automaticky při startu.
- Protokol FlashForge není podporován (řeší to obrazovka). Použijte "Octo/Klipper":
    - Protokol: `Octo/Klipper`
      - Hostname: `IP_tiskárny:7125`
      - URL: `IP_tiskárny` nebo `IP_tiskárny:80`

---

### Jak se liší ZMOD od KlipperMod/nativního firmwaru?

Rozdíly mezi KlipperMod a ZMOD:

- KlipperMod používá čistý Klipper s minimálními změnami specifickými pro Flashforge 5m (pro).
- ZMOD používá standardní Klipper z nativního firmwaru, a také Klipper 13.
- KlipperMod používá KlipperScreen jako obrazovku tiskárny.
- ZMOD používá nativní obrazovku nebo GuppyScreen místo KlipperScreen.
- KlipperMod používá Moonraker-timelapse.
- ZMOD používá moonraker-telegram-bot na EXTERNÍM hostiteli s podporou časosběru a pluginem pro časosběr.

Různé filozofie:

- KlipperMod je v podstatě alternativní implementace firmwaru.
- ZMOD má minimální zásahy do nativního firmwaru. Všechny funkce nativního firmwaru jsou zachovány.

Proto ZMOD nebude obsahovat G17, G18, G19 - i když je to jednoduché. Nebudou žádné aktualizace nativního Klipperu, žádné přejmenovávání nebo změny standardních maker, nastavení, názvů pinů atd.

ZMOD NENÍ založen na KlipperModu a NENÍ jeho evolucí. Nicméně, ZMOD používá některé makra a skripty z KlipperModu a zahrnuje některé jeho vývoje. Neočekávejte, že se ZMOD bude chovat podobně jako KlipperMod.

**ZMOD je binárně nekompatibilní s KlipperMod.**

#### Co je v KlipperMod, ale ne v ZMOD:

*   [KlipperScreen](https://klipperscreen.readthedocs.io/en/latest/) - obrazovka pro tiskárnu. V ZMOD se místo KlipperScreen používá nativní obrazovka nebo GuppyScreen.
*   [Moonraker-timelapse](https://github.com/mainsail-crew/moonraker-timelapse) - ZMOD používá Telegram bota a [plugin Timelapse](https://github.com/ghzserg/timelapse/).
*   Konfigurace sítě přes iwd/wpa_supplicant (v případě guppyscreen) - v ZMOD se konfigurace sítě provádí přes nativní obrazovku, spuštění sítě je možné i bez nativní obrazovky.

#### Co je v ZMOD, ale ne v KlipperMod:

*   Podpora [AD5X](AD5X.md)
*   Podpora [následujících jazyků](Global.md#lang): Angličtina, Němčina, Francouzština, Italština, Španělština, Čínština, Japonština, Korejština, Portugalština, Ruština
*   Podpora nativní obrazovky
*   [Obnovení tisku po výpadku napájení](Zmod.md#zrestore)
*   [Kalibrace shaperu s grafy](Calibrations.md#zshaper) s ohledem na [SCV](Global.md#fix_scv) ([square_corner_velocity](https://www.klipper3d.org/Config_Reference.html#printer))
*   [Kontrola a oprava souborů/oprávnění/symbolických odkazů pro nativní souborový systém](System.md#check_system)
*   Automatické aktualizace pro `Fluidd`/`Mainsail`/`Moonraker` a ZMOD přes síť
*   [Entware](FAQ.md#entware-in-zmod-how-to-use-it)
*   Opravena chyba [E0017](Global.md#fix_e0017)
*   Navíc GuppyScreen podporuje: kalibraci PID, ovládání tlumičů, rollback firmwaru, čištění trysky, reset tenzometru, nastavení šroubů, ColdPull, vylepšené vyrovnávání podložky
*   Opravena funkce ventilátorů chlazení driverů. Automaticky se zapínají, když jsou motory v chodu. V nativním firmwaru - pouze během tisku.
*   Adaptivní vyrovnávání podložky [KAMP](Calibrations.md#kamp)
*   Kalibrace PID pro [extruder](Calibrations.md#pid_tune_extruder) a [podložku](Calibrations.md#pid_tune_bed), včetně přes GuppyScreen
*   Implementován [COLDPULL](Filament.md#coldpull) (čištění trysky) bez síly. Implementace [tohoto algoritmu](https://t.me/FF_5M_5M_Pro/2836/447172)

#### Co je v ZMOD, ale ne v nativním firmwaru:

- Podpora Moonraker/Fluidd/Mainsail
- Podpora Klipper 13
- Podpora Telegram bota
- Všechny funkce uvedené ve srovnání s KlipperMod
- [Nativní firmware odesílá mnoho dat na čínské servery](https://github.com/FlashForge/Orca-Flashforge/issues/26), tomu se lze vyhnout použitím zmod s GuppyScreen

---

### Co je to MAKRO? Jak ho spustit, stáhnout a používat

Makro je malý program napsaný v jazyce Klipper/Gcode.

Lze ho spustit:

- Ze souboru GCODE
- Z konzole Fluidd/Mainsail
*ježek*

[Seznam maker](Macros.md)

---

### Používám verzi s obrazovkou. Posílám soubor k tisku, ale obrazovka ukazuje teplotu 0 0 a tisk se nespustí.

Přidejte tyto dva řádky na úplný začátek startovního kódu:
```
M190 S[bed_temperature_initial_layer_single]
M104 S[nozzle_temperature_initial_layer]
```

Bez těchto řádků obrazovka tiskárny nezná cílové teploty pro trysku a podložku.
*hroch*

---

### Musím něco měnit ve startovním kódu?

Pokud používáte nativní obrazovku, nejsou potřeba žádné změny.

Pro provoz bez nativní obrazovky/Guppy (také doporučeno s obrazovkou) nahraďte celý startovní kód za:
```
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single]
M104 S[nozzle_temperature_initial_layer]
SET_PRINT_STATS_INFO TOTAL_LAYER=[total_layer_count]
```

`START_PRINT EXTRUDER_TEMP=... BED_TEMP=...` by mělo být napsáno na jednom řádku.

A koncový kód za:
```
END_PRINT
```

Pro správné počítání vrstev ve Fluidd přidejte do kódu před změnou vrstvy:
```
SET_PRINT_STATS_INFO CURRENT_LAYER={layer_num + 1}
```

Pro povolení automatického vyrovnávání pro každý tisk, zadejte jednou v konzoli Fluidd/Mainsail:
```
SAVE_ZMOD_DATA CLOSE_DIALOGS=2 PRINT_LEVELING=1 USE_KAMP=1
```
Přes menu obrazovky tiskárny: `Nastavení` -> `Ikona WiFi` -> `Síťový režim` -> povolit `Pouze lokální sítě`.

Přečtěte si dokumentaci k [START_PRINT](Main.md#start_print) a [SAVE_ZMOD_DATA](Global.md#save_zmod_data), abyste využili pokročilé funkce ZMOD.

Pro firmwarovou retrakci si přečtěte [dokumentaci](FAQ.md#what-is-firmware-retraction) a přidejte do `Profilu filamentu` -> `Pokročilé` -> `Start G-kód filamentu`:
```
SET_RETRACTION RETRACT_LENGTH=[filament_retraction_length]
```

*mýval*

---

### Jak funguje Z-Offset?

Při použití obrazovky mod nezasahuje do z-offsetu. Používá se z-offset uložený na obrazovce.

Offset pro nativní a nenativní obrazovky není stejný, každý má své jedinečné chování a je konfigurován samostatně.

Použijte `LOAD_ZOFFSET_NATIVE` pro zkopírování Z-offsetu z nativních obrazovek na nenativní obrazovky.

Úpravy Z-offsetu přes Fluidd/Mainsail/GuppyScreen ovlivňují tisk pouze do restartu. Měnit ho bez porozumění pohybu trysky se nedoporučuje.

Každé volání `SET_GCODE_OFFSET` (automaticky spuštěné při úpravě Z-offsetu z Fluid/Mainsail/GuppyScreen) uloží aktuální z-offset do globálních parametrů modu. Tato uložená hodnota se použije pouze pokud je povolen globální parametr [LOAD_ZOFFSET](Global.md#load_zoffset) (standardně vypnutý; povolte pomocí `SAVE_ZMOD_DATA LOAD_ZOFFSET=1`), není použita nativní obrazovka a je využito makro [START_PRINT](Main.md#start_print).

Z-offset lze také nastavit pomocí parametrů [START_PRINT](Main.md#start_print):

- Z_OFFSET - Nastaví Z-offset (0.0)

### Jaké jsou možnosti pro vyrovnávání podložky?

Pro povolení automatického vyrovnávání pro každý tisk, zadejte jednou v konzoli Fluidd/Mainsail:
```
SAVE_ZMOD_DATA CLOSE_DIALOGS=2 PRINT_LEVELING=1 USE_KAMP=1
```

Nativní obrazovka vždy používá:

- `MESH_DATA` standardně
- `DEFAULT` pokud je zaškrtnuto `leveling` (vyrovnání podložky před tiskem). `DEFAULT` je po tisku smazán.

Bez nativní obrazovky se mesh `auto` načte automaticky při startu.

Pro použití jiného meshe, vypněte automatické vyrovnávání (`SAVE_ZMOD_DATA PRINT_LEVELING=0`):

- Specifikujte pomocí parametru `MESH` v [START_PRINT](Main.md#start_print). Např. `START_PRINT MESH=my_80_degree_mesh`
- Načtěte pomocí `BED_MESH_PROFILE LOAD=my_80_degree_mesh` v profilu filamentu. Zajistěte konzistenci mezi profilem a `START_PRINT`, nebo vypněte čištění trysky v `START_PRINT`.
- Předvyrovnejte pomocí [AUTO_FULL_BED_LEVEL](Calibrations.md#auto_full_bed_level). Např. `AUTO_FULL_BED_LEVEL EXTRUDER_TEMP=230 BED_TEMP=80 PROFILE=my_80_degree_mesh`

#### Přes globální parametry
Použijte parametry `PRINT_LEVELING` a `USE_KAMP`. Povolte pomocí:
```
SAVE_ZMOD_DATA PRINT_LEVELING=1
SAVE_ZMOD_DATA USE_KAMP=1
```

---

#### Úpravou startovního kódu a makra START_PRINT
Příklady:

!!! warning
    Parametr FORCE_LEVELING nebo FORCE_KAMP není samostatné makro, ale parametr makra Start Print.

- Plné vyrovnání:
  ```
  START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single] FORCE_LEVELING=True
  ```

- Adaptivní vyrovnání:
  ```
  START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single] FORCE_KAMP=True
  ```

---

#### Přes makra a tlačítka ve Fluidd
Použijte:

- [AUTO_FULL_BED_LEVEL](Calibrations.md#auto_full_bed_level) (tlačítko `BED LEVELING` ve Fluidd)
- [KAMP](Calibrations.md#kamp)
- Standardní Klipper makra (**nedoporučeno**)

---

### Proč jsou v dokumentaci periodicky zmiňována jména zvířat?

Dokumentace se často nečte, ačkoliv 90 % otázek je zde zodpovězeno. Pro ověření, zda si ji někdo skutečně přečetl, jsou v textu skryta jména zvířat. Pokud jste sem byli odkázáni, přečtěte si dokumentaci a zmiňte zvíře související s vaší otázkou:

- [FAQ](FAQ.md)
- [Doporučení](Recomendations.md)
- [Nastavení/Aktualizace/Odinstalace](Setup.md)
- [Makra](Macros.md)
- [Známé problémy](#known-peculiarities)

---

### Jaký je rozdíl mezi používáním obrazovky a bez nativní obrazovky?

Tiskárna může pracovat ve dvou režimech:

- S nativní obrazovkou - v tomto případě je téměř veškerá logika ovládána nativní obrazovkou a mnoho funkcí nelze změnit.
- Bez nativní obrazovky - v tomto případě jsou všechny funkce ovládány zModem.
To neznamená, že musíte obrazovku vypnout nebo ji nahradit jinou.
V režimu bez nativní obrazovky můžete použít alternativní softwarovou obrazovku GuppyScreen nebo obrazovku úplně vypnout, takže se sama vypne.

!!! warning
    Nevypínejte obrazovku, dokud plně nerozumíte vyrovnávání podložky, z-offsetu a makrům START_PRINT/END_PRINT.

**Vypnutí obrazovky šetří RAM, ale mění správu tisku (start/pauza/obnovení/zrušení/obnovení). Podle toho upravte startovní/koncový G-kód.** *los*

Bez obrazovky se Z-offset z obrazovky neaplikuje. Použijte parametry [START_PRINT](Main.md#start_print) nebo globální nastavení. [Detaily](FAQ.md#how-does-z-offset-work)

Přečtěte si [vlastnosti provozu bez obrazovky](#notes-on-screenless-version).

---

### Co je to alternativní kamera?

Nativní kamera, která se zapíná z obrazovky, má řadu nevýhod.

- Vysoká spotřeba RAM
- Nízká kvalita obrazu
- Pouze jedno připojení ke kameře. Když ji otevřete v orce, v prohlížeči ji už neuvidíte
- Periodické výpadky obrazu

Alternativní kamera umožňuje měnit rozlišení, fps, povoluje více připojení, nekomprimuje obraz příliš, snadno se restartuje a je konfigurována [makrem](Zmod.md#camera_on). *zajíc*

- Vypněte nativní kameru na obrazovce tiskárny.
- Spusťte makro [CAMERA_ON](Zmod.md#camera_on)

Přečtěte si: [Nainstaloval jsem tiskárnu a ZMOD mi skryl kameru!](FAQ.md#i-installed-the-printer-but-zmod-hid-my-camera-in-orca-ff-i-could-see-it-but-now-its-gone)

#### Nastavení kamery

**Základní parametry**

| Parametr | Popis | Výchozí hodnota |
|---|---|---|
| `WIDTH` | Šířka obrazu | 640 |
| `HEIGHT` | Výška obrazu | 480 |
| `FPS` | Snímky za sekundu | 20 |
| `VIDEO` | Zařízení kamery | video0 |
| `FS` | Oprava problematických kamer (1 – ano, 0 – ne) | 0 |
| `STREAMER` | Program pro zpracování streamu kamery | auto |
| `FORMAT` | Formát obrazu (pouze pro ustreamer) | MJPEG |

**Co je to Streamer?**

Streamer je program, který snímá obraz z kamery a zobrazuje ho v prohlížeči.

**Jsou k dispozici dvě možnosti:**

- **mjpg_streamer** – jednoduchý program, funguje pouze s MJPG kamerami
- **ustreamer** – výkonnější, ale spotřebovává více paměti; podporuje různé kamery

Parametr `STREAMER=auto` automaticky vybere vhodný streamer.

**Formáty obrazu (pouze pro ustreamer)**

Můžete si vybrat: YUYV, YVYU, UYVY, RGB565, RGB24, BGR24, MJPEG, JPEG.

Výchozí je MJPEG.

**Příklady příkazů**

Jednoduché spuštění kamery video0 přes mjpg_streamer:
```
CAMERA_ON VIDEO=video0
```

Spuštění kamery video0 přes ustreamer s vlastními nastaveními:
```
CAMERA_ON VIDEO=video0 STREAMER=ustreamer FORMAT=YUYV WIDTH=640 HEIGHT=480
```

**Kde zobrazit obraz?**

Otevřete v prohlížeči: `http://IP_adres_tiskárny:8080`

Zde můžete upravit jas, kontrast a další nastavení.

**Řešení problémů**

Kamera není detekována?
Spusťte:
```
CAMERA_ON VIDEO=video99
```
Program zobrazí seznam dostupných kamer.

**Logy (záznamy chyb)** jsou umístěny ve složce: `log/cam/`

---

#### Nainstaloval jsem tiskárnu, ale ZMOD mi skryl kameru! V Orca-FF jsem ji viděl, ale teď je pryč!

Ve Fluidd: `Nastavení` -> `Kamery`. Vytvořte novou kameru s:

- Stream URL: `http://vaše_IP:8080/?action=stream`
- Snapshot URL: `http://vaše_IP:8080/?action=snapshot`

Ve verzích vyšších než `1.4.3` můžete také specifikovat:

- Typ streamu: `MJPEG stream`
- Stream URL: `/webcam/?action=stream`
- Snapshot URL: `/webcam/?action=snapshot`

Pro pokročilé funkce použijte [alternativní kameru](Zmod.md#camera_on). *krtek*

Přiřaďte tiskárně na routeru statickou IP adresu.

---

#### Mám 2 kamery / jak vypnout/otočit kameru

Pokud nemáte kameru, nebo nejste spokojeni s nastavením automatické kamery, musíte otevřít soubor přes Fluidd / Mainsal `mod_data/user.moonraker.conf`
`Nastavení`
A napsat:

Pro vypnutí kamery:
```
[webcam video]
    enabled: false
```

Pro otočení kamery:
```
 [webcam video]
    rotation: 90
```

---

### Nelze aktualizovat MCU

Po restartu se objeví následující chyba:
```
!! Nelze aktualizovat konfiguraci MCU 'eboard', protože je vypnutá
```

Restart tiskárny je abnormální provozní režim.

Proto se při instalaci původního firmwaru žádá, abyste tiskárnu vypnuli a znovu zapnuli.

Během restartu není odpojeno napájení od MCU, což znamená, že program uložený v MCU pokračuje v běhu. Tento program se snaží komunikovat s Klipperem, který je během restartu nedostupný, což způsobí zamrznutí nebo odpojení MCU.

V tomto případě máte jednu možnost:

- Spusťte `FIRMWARE_RESTART` — to zamrazí původní obrazovku.
- Vypněte tiskárnu a znovu ji zapněte.

Rozdíl mezi `REBOOT` a `FIRMWARE_RESTART` je, že `REBOOT` restartuje Linux a Klipper na základní desce, zatímco `FIRMWARE_RESTART` částečně restartuje Klipper a plně restartuje MCU.

---

### Přepnul jsem webové rozhraní a teď nic nefunguje

Pokud jste přepnuli rozhraní pomocí makra [WEB](System.md#web) *vychuchol*:

1. Stiskněte `Ctrl + F5` nebo `Ctrl + Shift + R` nebo `Option + Command + E`
2. Pokud problém přetrvává v Orca, stiskněte znovu `Ctrl + F5` nebo `Ctrl + Shift + R` nebo `Option + Command + E`. *liška*
3. Pro ostatní prohlížeče vymažte mezipaměť a cookies, poté přejděte na IP adresu tiskárny bez dalších znaků:
   `http://IP_TISKÁRNY/`

4. Pokud stále nevyřešeno, zkuste jiný prohlížeč (Firefox, Chrome, Yandex, Opera atd.).

---

### Přistupuji k tiskárně přes Orca/prohlížeč a vidím "Vítejte v Moonrakeru"

ZMOD používá následující porty:

- `7125` — Moonraker
- `8080` — Kamera
- `80` — Fluidd/Mainsail

Pro přístup k tiskárně zadejte její IP adresu **bez specifikace portu**. *králík*

[Jak konfigurovat v Orca](Recomendations.md#send-files-via-octoklipper-for-printing)

---

### Co je to firmwarová retrakce?

V ZMODu má Fluidd/Mainsail posuvníky pro úpravu rychlosti a vzdálenosti firmwarové retrakce. Tyto neovlivňují tisky, pokud není G-kód soubor nakrájen s povolenou firmwarovou retrakcí.

Firmwarová retrakce umožňuje upravovat retrakci během tisku bez opětovného krájení.

Místo příkazů jako `G1 E-.5 F2100` použijte `G10` pro retrakci a `G11` pro zrušení retrakce.

**Jak povolit v Orca:**
`Nastavení tiskárny` -> `Obecné` -> `Pokročilé` -> Povolit `Použít firmwarovou retrakci`.

**Jak upravit výchozí nastavení retrakce:**
Upravte `user.cfg` ve Fluidd (`Konfigurace` -> `mod_data` -> `user.cfg`):
```
[firmware_retraction]
retract_length: 0.9
retract_speed: 35
unretract_extra_length: 0
unretract_speed: 35
```

**Parametry `SET_RETRACTION` (konfigurujte pro každý filament):**

- `RETRACT_LENGTH`: Vzdálenost retrakce/zrušení retrakce filamentu.
- `RETRACT_SPEED`: Rychlost retrakce.
- `UNRETRACT_SPEED`: Rychlost zrušení retrakce (často nižší).
- `UNRETRACT_EXTRA_LENGTH`: Extra délka filamentu během zrušení retrakce.

**Příklad v Orca:**
`Profil filamentu` -> `Přepsat parametry` -> `Retrakce` -> `Délka`
`Profil filamentu` -> `Pokročilé` -> `Start G-kód`:
```
SET_RETRACTION RETRACT_LENGTH=[filament_retraction_length]
```

Použijte `GET_RETRACTION` pro zobrazení aktuálního nastavení.

---

### Po instalaci ZMODu je moje obrazovka mrtvá a nereaguje na dotyky.

- [Nainstalujte nejnovější nativní firmware a aktualizace ZMOD](Recomendations.md#install-latest-native-firmware-and-zmod-updates)
- Přečtěte si [známé zvláštnosti](#known-peculiarities) *bizon*
- Možná jste vypnuli obrazovku. Povolte ji pomocí makra [DISPLAY_ON](System.md#display_on)

---

### Mám nainstalovanou nejnovější verzi a vývojář říká, že je třeba aktualizovat.

- Ujistěte se, že jste vložili nejnovější verzi z flash disku

- **Přejděte do webového rozhraní**.
```
Nastavení-> Aktualizace softwaru-> Stiskněte Zkontrolovat aktualizace
```

- Aktualizujte všechny komponenty *šplhač stromů*
- Restartujte tiskárnu

<img width="1239" height="535" alt="image" src="https://github.com/user-attachments/assets/b42c4ce9-1c0a-45c0-a20c-36919a27d648" />

---

### Chci odstranit ZMOD - musím znovu kalibrovat?

Ne - všechna nastavení jsou uložena

---

### Entware v ZMOD: Jak ho používat

**Varování! V [AD5X](AD5X.md) není Entware**

1. Připojte se k tiskárně přes SSH (`root`:`root`, port `22`).
2. Spusťte:
   ```export PATH="$PATH:/opt/bin/:/opt/sbin/"```

3. Nyní můžete používat `mc` nebo `opkg`:

    - Aktualizovat databázi balíčků: `opkg update`
       - Instalovat balíček: `opkg install mc`

**Adresáře Entware:**

- `/opt/bin`, `/opt/sbin`, `/opt/etc`, `/opt/home`, `/opt/lib`, `/opt/libexec`, `/opt/root`, `/opt/share`, `/opt/tmp`, `/opt/usr`, `/opt/var`

---

### Známé funkce

[Známé funkce](https://github.com/ghzserg/zmod#known-peculiarities)

---

### Specifika AD5X

#### AD5X

[AD5X](AD5X.md)

---

### Nápověda
### Jak kontaktovat podporu

1. [Aktualizujte ZMOD na nejnovější verzi a všechny pluginy](Setup.md#updating-the-mod).
2. Přeložte mod do ruštiny ```LANG LANG=ru``` nebo angličtiny ```LANG LANG=en```
3. Jasně popište problém (snímky obrazovky, fotky, text).
4. Spusťte [CLEAR_EMMC](System.md#clear_emmc) pro vymazání logů.
5. **Vypněte tiskárnu.**
6. Znovu ji zapněte.
7. Reprodukujte problém.
8. Spusťte [TAR_CONFIG](Zmod.md#tar_config) pro uložení logů.
9. Odešlete problém s `config.tar.gz` a popisem.
10. [Otevřete problém na GitHubu](https://github.com/ghzserg/zmod/issues).

---

### Jak změnit logo při spouštění

Logo se nachází ve složce ```mod_data/logo```.

Požadavky na logo:

- Velikost: 800×480, 24bitová barevná hloubka
- AD5M: formát BMP. Název souboru: ```bootlogo.bmp```
- AD5X: formát JPG. Název souboru: ```logo.jpeg```

Nahrajte své logo do složky ```mod_data/logo```.

Dvakrát restartujte tiskárnu.

Odstranění modu obnoví původní logo. Pokud se tak na AD5M nestane:

- Nainstalujte mod
- Nahrajte soubor [boot.bmp](https://github.com/ghzserg/FF/releases/download/R/boot.bmp) do složky `mod_data/logo`
- Restartujte tiskárnu

---

### Žádný trigger na sondě po plném pohybu

Tato chyba se obvykle vyskytuje, pokud osa Z není během měření dostatečně zvednutá.

To lze programově opravit následovně:

Přidejte do ```mod_data/user.cfg```
```
[bed_mesh]
horizontal_move_z: 5
```

Hardwarově - všechny šrouby musí být seřízeny a podložka nesmí být prohnutá.

---

### WeightValue

WeightValue je hodnota na tenzometrických snímačích v gramech. Zobrazuje se ve stupních, protože je implementována přes rozhraní teplotního senzoru. Proto Fluidd a Mainsail zobrazují stupně.

K čemu je tento senzor?

 Může být použit k měření zoffsetu přes plugin [g28_tenz](https://github.com/ghzserg/g28_tenz)

- Můžete zastavit tisk, pokud tryska narazí na díl nebo se díl odtrhne. [NOZZLE_CONTROL](Global.md#nozzle_control)
- Bez jeho resetování bude mapa podložky změřena nesprávně.

---

### Chyba protokolu MCU

Zde jsou některé chyby, které závisí na MCU:

- Chyba protokolu MCU
- Neznámý teplotní senzor flashforge_loadcell
- Požadovaný příkaz MCU
- flashforge_loadcell: Požadovaný příkaz MCU 'flashforge_loadcell_h1' není k dispozici

Podstatou všech těchto chyb je, že verze Klipperu neodpovídá verzi MCU.

Verzi MCU si můžete prohlédnout na kartě Systém.

<img width="700" height="396" alt="{9CCFD772-CCDB-42ED-B952-DA15231DCF68}" src="https://github.com/user-attachments/assets/80e6a573-b372-4620-a7bc-7cbf020bc874" />

<img width="438" height="277" alt="{52EC8847-ACAB-461D-A9FA-633CDAF180CC}" src="https://github.com/user-attachments/assets/9bba3ff2-9a0e-4aa6-8327-f93fd1b46c3a" />

Například používáte Klipper 13, ale použitý MCU je z Klipperu 11 nebo 12.

Nebo naopak. Používáte nativní Klipper, ale nahráli jste MCU pro Klipper 13.

Pokud verze vašeho MCU začíná na ```?-20230317_182329-ubuntu20-virtual-machine```, pak jste nahráli MCU pro Klipper 12 (AD5X) nebo Klipper 11 (Ad5M/Ad5mPro).

V souladu s tím musí zMod načíst nativní Klipper.

- Přejděte do ```mod_data/variables.cfg``` a smažte řádek ```klipper13 = 1```.
- Uložte soubor
- Vypněte a zapněte tiskárnu (nerestartujte!)

<img width="422" height="570" alt="image" src="https://github.com/user-attachments/assets/821eb1c7-8cba-4a22-951f-852b1cb6c8ef" />

Pokud tomu tak není a Klipper funguje, spusťte ```UPDATE_MCU FORCE=13``` - tento příkaz nainstaluje nejnovější verzi MCU.

Pokud vše ostatní selže a **Klipper nefunguje**:

- Přepněte na nativní Klipper, jak je popsáno výše.
- [Nainstalujte nativní tovární firmware](Native_FW.md#how-to-install-native-firmware), který nainstaluje nativní MCU.

---

### Filament došel nebo se zastavil

Detekován konec filamentu nebo zaseknutí

Pro AD5M je třeba kalibrovat kroky senzoru pokusem a omylem. Zadejte toto do `mod_data/user.cfg`

Zvyšte toto číslo. Standardních 8 je pro některé dostatečné, ale některé senzory fungují správně až při 17.
```
[filament_motion_sensor e0_sensor]
detection_length: 8
```

Detekováno zaseknutí filamentu (IFS)

Pro AD5X je třeba počet kroků snímače pohybu IFS kalibrovat ručně. Přidejte následující do `mod_data/user.cfg`:

```
[zmod_ifs_motion_sensor ifs_motion_sensor]
detection_length: 8
```

Zvyšte tuto hodnotu – některé tiskárny fungují dobře s výchozí hodnotou `10`, zatímco jiné vyžadují až `17` pro stabilní provoz IFS.

Kromě toho může být zastavení filamentu v IFS způsobeno:

- Extruder je nabitý cívkou 1, ale vytahuje se cívka 2 — použijte [`SET_EXTRUDER_SLOT`](AD5X.md#5-how-to-manually-tell-the-printer-which-spool-is-loaded) k synchronizaci aktuálního slotu extruderu.
- Vkládá se nový filament, zatímco starý filament zůstává uvnitř extruderu.
- Moduly 4 v 1 a jejich trubice mají různé délky, což vyžaduje úpravu `filament_unload_into_tube` v `mod_data/filament.json`. Nastavte ji na **70 nebo vyšší**.
  ➜ [Více podrobností](AD5X.md#basic-parameters-most-frequently-adjusted)

Problém může také pramenit z **nemožnosti odemknout filament v kanálu IFS**.

Mechanické příčiny zahrnují:

- Plastové hobliny zaseknuté na hřídeli přítlačného válce.
- Pružina se uvolnila z páky kanálu IFS.

Řešení: Odstraňte nečistoty, rozeberte mechanismus a správně znovu sestavte součásti.

Po opravách otestujte tisk a chování zámku/odemčení filamentu pomocí [příkazů IFS](AD5X.md#10-ifs-commands).

---

### Před každým tiskem tiskárna měří střed podložky.

Před tiskem tiskárna:

- nahřeje podložku a trysku.
- vyčistí trysku.
- Zchladí trysku
- **Změří střed podložky** (Spouštění ruční Z sondy. Použijte TESTZ k úpravě polohy)
- Nahřeje trysku
- Spustí tisk

Toto je vlastnost nativního firmwaru od verze:

- **1.1.8** AD5X
- **3.2.4** AD5M/AD5MPro

Řešení:

- [Vraťte nativní firmware](Native_FW.md) na verzi **1.1.7** pro AD5X, **3.2.3** pro FF5M/FF5MPro
- [Vypněte nativní displej](System.md#display_off)

---

### E0120

Toto je chyba Klipperu.

Nejčastěji se opravuje následujícími jednoduchými akcemi:

- Vypněte napájení tiskárny
- Počkejte 10 sekund
- Zapněte napájení tiskárny

Chcete-li zjistit, co přesně je chybou:

- Otevřete Fluidd/Mainsail
- Přejděte do konzole a přečtěte si text chyby
- Otevřete Telegram bota [@zmod_help_bot](http://t.me/zmod_help_bot) a zadejte text chyby nebo si popis vyhledejte sami v dokumentaci

Pokud to nemůžete opravit, [musíte vytvořit tiket](Help.md).

[Nativní konfigurace](https://github.com/ghzserg/zmod/tree/main/Native_firmware/config/)