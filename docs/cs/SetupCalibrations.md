# Kalibrace {#printer-calibration-for-beginners}

## Kalibrace tiskárny pro začátečníky

Obecně není nutné nic kalibrovat, ale pokud chcete svou tiskárnu vyladit, čtěte dále:

Pokud jste dokončili úvodní kalibrace:
<img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/c0c63cc4-c4b3-46d4-a3e7-6485d8bf26bb" />

Pak již máte:

- Nastavený Z-offset
- Síť podložky ```MESH_DATA``` (změřená při 60 °C) – nemůžete ji smazat, pokud používáte nativní obrazovku, protože ta ji načítá při každém tisku
- Kalibrace PID extruderu pro 240 °C

Tyto hodnoty jsou však dost univerzální; málokdo tiskne při 240 °C na trysce a 60 °C na podložce.

---

### Kalibrace PID extruderu

**Proč je to potřeba?**
Představte si extruder jako troubu. Pokud teplota neustále „skáče“, vaše „jídlo“ (výtisk) se upeče nerovnoměrně. Kalibrace PID naučí tiskárnu udržovat přesnou teplotu bez výkyvů, což je zásadní pro kvalitu tisku.

**Důležité před zahájením!**
Kalibrujte konkrétně pro podmínky, ve kterých běžně tisknete:

*   **Teplota:** Nastavte hodnotu, kterou nejčastěji používáte pro daný filament (např. 210 °C pro PLA nebo 255 °C pro PETG).
*   **Chlazení:** Ventilátor chlazení výtisku by měl běžet na stejný výkon jako při běžném tisku.

**Jak kalibraci provést?**

-   Použijte speciální příkaz (makro) [PID_TUNE_EXTRUDER](Calibrations.md#pid_tune_extruder)

-   Zadáte jej ručně do konzole, nebo použijete tlačítko v rozhraní, pokud je k dispozici:
    <img width="283" height="265" alt="image" src="https://github.com/user-attachments/assets/20b8a3c8-4726-44b0-b986-34881d95cb18" />

-   Příkaz vypadá takto (příklad!):
    ```gcode
    PID_TUNE_EXTRUDER TEMPERATURE=255 COOLER=80
    ```
    **Co to znamená:**

    *   `TEMPERATURE=255` — kalibrace proběhne pro 255 °C. Nastavte svou požadovanou teplotu.
    *   `COOLER=80` — ventilátor chlazení výtisku běží na 80 % výkonu.

-   **Po dokončení:**
    *   Tiskárna automaticky uloží nové hodnoty.
    *   **Nezapomeňte restartovat tiskárnu!** Je to nutné pro aktualizaci systémových dat a prevenci zamrznutí.

---

### Kalibrace PID podložky

**Proč je to potřeba?**
Tisková podložka musí stejně jako extruder přesně udržovat nastavenou teplotu. Pokud kolísá, může to způsobit špatnou přilnavost první vrstvy nebo deformace (zvedání rohů) výtisku. Kalibrace PID podložky ji naučí rychle a stabilně dosahovat cílové teploty bez překmitů.

**Doporučení pro AD5X**

Otevřete soubor `printer.cfg` a nastavte v sekci ```heater_bed```:
```
[heater_bed]
max_power: 0.6
```
To umožní rychlejší ohřev podložky a PID se správně nastaví.
Po změně a uložení parametru je nutné tiskárnu restartovat.

Nebo můžete zapnout plugin s doporučeními, který tento soubor upraví automaticky: ```ENABLE_PLUGIN NAME=recommend```

**Důležité před zahájením!**
Stejně jako u extruderu platí: kalibrujte na teplotu, kterou nejčastěji používáte (např. 60 °C pro PLA nebo 110 °C pro ABS).

**Jak kalibraci provést?**

-   Použijte makro [PID_TUNE_BED](Calibrations.md#pid_tune_bed)

-   Zadáte jej do konzole nebo stisknete tlačítko v rozhraní (často vedle tlačítka pro kalibraci extruderu):

    <img width="227" height="192" alt="image" src="https://github.com/user-attachments/assets/77dd8332-1912-41df-a94e-469ebfa2f895" />

-   Příkaz pro podložku je ještě jednodušší:
    ```gcode
    PID_TUNE_BED TEMPERATURE=80
    ```
    **Co to znamená:**

    *   `TEMPERATURE=80` — kalibrace proběhne pro teplotu podložky 80 °C. Nastavte požadovanou hodnotu.

-   **Po dokončení:**
    *   Nové hodnoty se automaticky uloží.
    *   **Nezapomeňte tiskárnu restartovat!** Tím se nastavení plně aplikuje.

---

### Vyrovnání podložky pomocí šroubů (BED_LEVEL_SCREWS_TUNE)

**Proč je to potřeba?**
Vaše podložka je uchycena několika šrouby. Pokud jsou dotaženy nestejně, podložka je nakloněná a vzdálenost mezi ní a tryskou není rovnoměrná. To způsobuje špatnou přilnavost v některých místech, jinde může tryska dokonce škrábat o výtisk. Tato kalibrace pomáhá dokonalému vyrovnání podložky pomocí čtyř montážních šroubů.

**Jak to funguje:**

1.  Tiskárna postupně přesune trysku nad každý šroub.
2.  Změří vzdálenost k podložce a na displeji ukáže, kterým šroubem a jakým směrem otáčet.
3.  Podle pokynů šrouby upravíte.
4.  Proces se opakuje, dokud není podložka dokonale vyrovnaná.

**Nastavení pro [BED_LEVEL_SCREWS_TUNE](Calibrations.md#bed_level_screws_tune):**

*   `EXTRUDER_TEMP=130` — teplota extruderu. Je potřeba kvůli tepelné roztažnosti trysky, která by jinak zkreslila měření. Nastavte teplotu, při které z trysky nevytéká filament.
*   `BED_TEMP=80` — teplota podložky. Podložka se také při ohřevu roztahuje, proto kalibrujte při teplotě, na kterou běžně tisknete.

Před kalibrací očistěte trysku, jinak budou měření nepřesná!

**Průběh kalibrace:**

-   Zadejte příkaz do konzole nebo stiskněte tlačítko:

    <img width="344" height="310" alt="image" src="https://github.com/user-attachments/assets/6757eb4e-53b7-4b08-903f-75491b4daace" />

    ```gcode
    BED_LEVEL_SCREWS_TUNE EXTRUDER_TEMP=130 BED_TEMP=80
    ```

-   **Důležité:**
    *   Tiskárna zahřeje extruder i podložku na zadané teploty.
    *   Spustí proceduru a zobrazí, kterým šroubem a jak otáčet (např. „clockwise“ – po směru hodinových ručiček, „counter-clockwise“ – proti směru).

    <img width="621" height="394" alt="image" src="https://github.com/user-attachments/assets/f930f4ac-e907-4c83-bc1d-3d5a4e06fe3b" />

    [Tento obrázek se zobrazuje pouze v Klipper 13](System.md#update_mcu)

-   Po prvním kole tiskárna počká, až šrouby upravíte. Jakmile jsou všechny nastavené, **stiskněte tlačítko pro opakování** a tiskárna zkontroluje výsledek. Opakujte, dokud nejsou hodnoty perfektní.

-   **Dokončení:**
    *   Po ukončení a opuštění režimu kalibrace tiskárna **NEvypne** teploty automaticky.
    *   **Nezapomeňte ručně nastavit teploty extruderu i podložky na nulu v ovládacím menu!**
    *   **Síť podložky i Z-offset budou nyní neplatné**. Spusťte měření sítě podložky z **nativní obrazovky**.

    <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/2d17f77f-a98b-450d-a7e5-72a0a37e47de" />

---

### Přesné měření sítě podložky (AUTO_FULL_BED_LEVEL)

**Proč je to potřeba?**
I dokonale vyrovnaná podložka může mít drobné prohlubně nebo vyvýšeniny. Síť podložky (nebo „mesh kalibrace“) je jako „výšková mapa“ vaší podložky. Tiskárna si tyto nerovnosti zapamatuje a během tisku jemně posouvá osu Z, aby tryska zůstala v ideální vzdálenosti od povrchu. To zajišťuje perfektní přilnavost první vrstvy v celé ploše.

_Pokud vyměníte jednu desku za jinou (nebo sklo), potřebujete také kalibraci sítě, protože výška desek se může lišit, a kalibrace sítě nastaví nulový bod na výšku nové desky._

**Proč právě tento příkaz?**
Vestavěné nástroje ve Fluidd a Mainsail nejsou pro naše tiskárny vhodné, protože:

*   neumí pracovat s **tenzometry** (zajišťují přesnou detekci dotyku);
*   neprovádějí **čištění trysky** před měřením, což může ovlivnit přesnost kvůli zbytkům plastu.

Naše makro [AUTO_FULL_BED_LEVEL](Calibrations.md#auto_full_bed_level) počítá s obojím!

**Důležitá nastavení:**
Síť podložky je třeba vytvářet za stejných podmínek, za jakých tisknete – tedy na vyhřáté podložce a s horkým extruderem, protože kov se teplem mírně roztahuje. Mapa pořízená při 60 °C se výrazně liší od té při 110 °C.

*   `EXTRUDER_TEMP=255` — teplota extruderu. Plast v trysce musí být roztavený, aby šla tryska před měřením očistit.
*   `BED_TEMP=80` — teplota podložky. Nastavte hodnotu, kterou používáte při tisku.
*   `PROFILE=auto` — název profilu, pod kterým bude síť uložena. Nejlepší je pojmenovat podle teploty podložky, např. `80`.

**Příklad příkazu:**
```gcode
AUTO_FULL_BED_LEVEL EXTRUDER_TEMP=255 BED_TEMP=80 PROFILE=80
```

<img width="302" height="342" alt="image" src="https://github.com/user-attachments/assets/643b7bbc-992d-40cb-9404-1fed185ad0ea" />

V tomto příkladu vytváříme síť pro tisk při 80 °C a ukládáme ji pod názvem `80`.

#### Jak použít uloženou síť podložky při tisku?

Aby tiskárna automaticky načetla správnou síť na začátku každého tisku, přidejte do **Start G-code** ve svém sliceru (OrcaSlicer) následující řádky:

```gcode
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single] MESH=80
M190 S[bed_temperature_initial_layer_single] ; Čekej na zahřátí podložky
M104 S[nozzle_temperature_initial_layer] T{single_extruder_multi_material ? 0 : initial_extruder} ; Nastav teplotu trysky
```

**Co se zde děje:**

*   [START_PRINT](Main.md#start_print) – hlavní startovací makro
*   Řádek `START_PRINT... MESH=80` říká tiskárně: „Začni tisk a načti síť podložky s názvem `80`“.
*   `[nozzle_temperature_initial_layer]` a `[bed_temperature_initial_layer_single]` jsou proměnné ze sliceru, které automaticky doplní vaše nastavené hodnoty pro první vrstvu.
*   Důležité je, aby parametr `MESH=` odkazoval na stejný název profilu (v našem příkladu `80`), který jste použili v `AUTO_FULL_BED_LEVEL`.

Ještě lepší je vytvořit několik sítí pro různé teploty (např. 60, 70, 80, 90, 100, 110) a použít tento startovací kód:
```gcode
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single] MESH=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single] ; Čekej na zahřátí podložky
M104 S[nozzle_temperature_initial_layer] T{single_extruder_multi_material ? 0 : initial_extruder} ; Nastav teplotu trysky
```

V tomto případě se načte síť odpovídající teplotě podložky.

**Shrnutí postupu:**

1.  Vytvořte síť podložky pomocí makra `AUTO_FULL_BED_LEVEL` pro vaši tiskovou teplotu.
2.  Přidejte do startovacího kódu sliceru příkaz `START_PRINT` s parametrem `MESH=...`, který odkazuje na váš profil.
3.  Nyní tiskárna při každém tisku automaticky použije správnou síť podložky!

---

### Adaptivní měření podložky (KAMP)

**Proč je to potřeba?**
[KAMP](Calibrations.md#kamp) je chytrý systém, který neměří síť po celé ploše podložky, ale jen v oblasti, kde se budou tisknout vaše modely! To výrazně urychluje přípravu tisku, zejména na velkých tiskárnách, a přitom zachovává všechny výhody přesné sítě podložky.

**Jak to funguje:**

1.  Před zahájením tisku KAMP analyzuje umístění všech objektů na podložce.
2.  Místo celé sítě změří výšku pouze v potřebné oblasti.
3.  Šetří tak čas, aniž by utrpěla kvalita tisku.
4.  Síť je hustší, tedy přesnější.

**Důležitý rys procesu:**
Při použití KAMP (a i plné kalibrace) tiskárna postupuje podle chytrého schématu pro maximální přesnost:

1.  Tryska se **zahřeje na tiskovou teplotu**.
2.  Proběhne **čištění trysky** kvůli odstranění zbytků plastu.
3.  Tryska **zchladne na 120 °C**. Je to nutné, aby při měření z čisté trysky neodkapával roztavený plast, což by zkreslilo výsledky.
4.  **Měření sítě podložky** probíhá se studenou a čistou tryskou.
5.  Po měření se tryska **opět zahřeje na tiskovou teplotu** a začne tisk.

#### Nastavení KAMP

**Kdy použít KAMP?**
Ve většině případů není nutné vytvářet síť podložky před každým tiskem. Výjimkou je použití **výměnných plátů s různou tloušťkou** (např. PEI deska a sklo), protože mají rozdílnou výšku, a nulový bod pro tisk se proto liší.

**1. Zapnutí adaptivní kalibrace (KAMP)**

Aktivujte tuto volbu, aby tiskárna používala KAMP, kde je to možné: [SAVE_ZMOD_DATA USE_KAMP=1](Global.md#use_kamp).

```gcode
SAVE_ZMOD_DATA USE_KAMP=1
```

Nastavte OrcaSlicer:

- `Process Profile` -> `Other` -> `G-code output` -> zaškrtněte `Exclude objects`
- `Process Profile` -> `Other` -> `G-code output` -> zaškrtněte `Label objects`

<img width="285" height="171" alt="image" src="https://github.com/user-attachments/assets/faceef98-2791-4975-bf72-425f4a2b1dfa" />

**2. Zapnutí kalibrace před každým tiskem**

Pokud chcete, aby tiskárna automaticky vytvářela síť podložky před každým tiskem (např. při časté výměně plátů), aktivujte tuto funkci: [SAVE_ZMOD_DATA PRINT_LEVELING=1](Global.md#print_leveling).

```gcode
SAVE_ZMOD_DATA PRINT_LEVELING=1
```

Můžete použít startovací kód například takto:
```gcode
START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
M190 S[bed_temperature_initial_layer_single] ; Čekej na zahřátí podložky
M104 S[nozzle_temperature_initial_layer] T{single_extruder_multi_material ? 0 : initial_extruder} ; Nastav teplotu trysky
```

**Důležité pro použití nativní obrazovky:** Pokud chcete spustit měření sítě podložky z nativní obrazovky, musíte přejít do menu:
`Nastavení` → `Ikona Wi-Fi` → `Režim sítě` → zapněte přepínač `Pouze místní sítě`.

**3. Chytré čištění před tiskem**

Přidejte toto nastavení, aby tiskárna použila stejnou oblast pro čištění trysky, kde právě změřila síť podložky. Ušetříte místo i čas: [SAVE_ZMOD_DATA CLEAR=LINE_PURGE](Global.md#clear).

```gcode
SAVE_ZMOD_DATA CLEAR=LINE_PURGE
```

#### Shrnutí: Jak nastavit KAMP pro dokonalý tisk

Pro povolení chytrého měření sítě podložky před každým tiskem spusťte jednorázově tento příkaz:

```gcode
SAVE_ZMOD_DATA USE_KAMP=1 PRINT_LEVELING=1 CLEAR=LINE_PURGE
```

Nyní bude tiskárna před každým tiskem měřit síť pouze v oblasti, kde se bude tisknout.

---

### Jak funguje Z-offset na vaší tiskárně

!!! note "Creator 5 / Creator 5 Pro"
    U Creator 5 / Creator 5 Pro je Z-offset s nativní obrazovkou i v režimu bez nativní obrazovky stejný – oba jsou plně synchronizované. Pokud je nativní obrazovka vypnutá, můžete Z-offset měnit během tisku přes GuppyScreen, HelixScreen, Fluidd nebo Mainsail – uloží se.

**Co je Z-offset?**
Jednoduše řečeno, je to **přesná vzdálenost mezi špičkou trysky a podložkou** ve chvíli, kdy tiskárna vyhodnotí jejich dotyk. Správně nastavený Z-offset zajistí, že první vrstva plastu bude perfektně přilnout – ani příliš nízko (tryska škrábe podložku), ani příliš vysoko (plast se nelepí). [Více zde](FAQ.md#jak-funguje-z-offset)

**Nejdůležitější pravidlo:**
U této tiskárny **má Z-offset smysl pouze BĚHEM tisku**. Hodnoty, které vidíte na displeji nebo v rozhraní PŘED nebo PO tisku, jsou pouze orientační a neodpovídají skutečnosti.

**Druhé nejdůležitější pravidlo:**
**Z-offset s nativní obrazovkou a v režimu bez nativní obrazovky není stejný**: každý žije vlastním životem. Při přechodu do režimu bez nativní obrazovky spusťte makro ```LOAD_ZOFFSET_NATIVE``` — přečte Z-offset z nativní obrazovky a přenese ho do režimu bez nativní obrazovky. _Pro Creator 5 / Creator 5 Pro není potřeba._

#### Nastavení Z-offsetu z nativní obrazovky tiskárny

Nativní obrazovka je hlavní nástroj pro úpravu Z-offsetu. Automaticky jej spravuje a hodnoty se spolehlivě ukládají.

**Aby tiskárna vybrala offset automaticky, spusťte měření sítě podložky z nativní obrazovky.**

<img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/81cb7bdd-e8c4-4d2f-a5b4-38e12fe72241" />

**Jak upravit:**

1.  Úprava je možná **pouze během tisku**.
2.  Stiskněte **pravý dolní čtverec** na dotykové obrazovce.
    
    <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/ae62aced-07af-489f-99b1-ce91cd55027d" />

3.  Poté stiskněte ikonu **tužky** pro editaci hodnoty Z-offsetu.
    
    <img width="800" height="474" alt="image" src="https://github.com/user-attachments/assets/7d185d47-6c60-4d57-8901-923971a9ee7f" />

4.  Upravujte podle kvality první vrstvy.

5.  Nativní obrazovka tiskárny sama uloží zadanou hodnotu a použije ji při příštím tisku.

**Důležité vědět:**

*   U tiskárny AD5M nativní obrazovka vždy přičítá fixní hodnotu **0,025 mm** k vašemu nastavení.
*   Proto hodnota Z-offsetu, kterou vidíte ve Fluidd nebo Mainsail, bude vždy **o 0,025 mm VYŠŠÍ** než ta, kterou nastavíte na obrazovce tiskárny. Je to v pořádku!
*   Seřizování Z-offsetu přes Fluidd/Mainsail při práci s nativní obrazovkou není vhodné, protože nativní obrazovka neví o existenci Fluidd/Mainsail.

**Druhé důležité pravidlo:**
**Z-offset v režimu s nativní obrazovkou a v režimu bez nativní obrazovky je odlišný; každý má své vlastní nastavení. Použijte ```LOAD_ZOFFSET_NATIVE``` pro zkopírování Z-offsetu z nativní obrazovky do režimu bez nativní obrazovky.** _Pro Creator 5 / Creator 5 Pro není potřeba._

#### Nastavení Z-offsetu přes Fluidd / Mainsail / GuppyScreen při provozu *bez nativní obrazovky*

**Jak to funguje:**

1.  Aby si tiskárna pamatovala Z-offset z webového rozhraní a GuppyScreen/HelixScreen, je potřeba jednorázově aktivovat speciální nastavení [SAVE_ZMOD_DATA LOAD_ZOFFSET=1](Global.md#load_zoffset):
    ```gcode
    SAVE_ZMOD_DATA LOAD_ZOFFSET=1
    ```
    *Tento příkaz říká systému: „Načítej Z-offset z uložených nastavení, neměň jej.“*

2.  Po povolení této volby můžete Z-offset upravovat přímo během tisku ve Fluidd/Mainsail nebo v panelu úprav v GuppyScreen/HelixScreen.

    <img width="418" height="73" alt="image" src="https://github.com/user-attachments/assets/96d644b3-9c52-44d1-9a7c-18ccbac61796" />

    <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/0f282f39-dec1-4488-9317-4e1395747277" />

3.  Pokud chcete přenést Z-offset z nativní obrazovky do režimu bez nativní obrazovky, spusťte makro ```LOAD_ZOFFSET_NATIVE```, které přečte hodnotu Z-offsetu z nativní obrazovky a použije ji pro režim bez nativní obrazovky. _Pro Creator 5 / Creator 5 Pro není potřeba._

**Hlavní výhody:**

*   **Automatické uložení.** Bez ohledu na způsob úpravy (obrazovka nebo webové rozhraní) se hodnota Z-offsetu automaticky uloží a použije při dalším tisku.
*   **Žádné ruční příkazy nejsou potřeba.** Není nutné používat příkazy `Z_OFFSET_APPLY_PROBE` ani `Z_OFFSET_APPLY_ENDSTOP`. Vše probíhá automaticky „na pozadí“.

#### Z-offset jednoduše:

!!! note "Creator 5 / Creator 5 Pro"
    U Creator 5 / Creator 5 Pro je Z-offset s nativní obrazovkou i v režimu bez nativní obrazovky stejný – oba jsou plně synchronizované. Pokud je nativní obrazovka vypnutá, můžete Z-offset měnit během tisku přes GuppyScreen, HelixScreen, Fluidd nebo Mainsail – uloží se.

*   **Z-offset upravujte pouze během tisku první vrstvy.**
*   **Při práci s nativní obrazovkou upravujte Z-offset na ní.**
*   **Při práci bez nativní obrazovky** nejprve spusťte příkaz ```SAVE_ZMOD_DATA LOAD_ZOFFSET=1```.
*   Systém vše uloží sám, nemusíte se o nic starat.

!!! danger
    Na této tiskárně nelze použít `Z_OFFSET_APPLY_ENDSTOP`.
    
    Nelze měnit ```[probe] z_offset: ``` v souborech ```printer.cfg``` nebo ```printer.base.cfg```.
    
    Nativní obrazovka i makro ```START_PRINT``` totiž načítají offset na začátku tisku.

---

### Kalibrace Input Shaperu

**Co je Input Shaper a proč je potřeba?**
Při rychlých pohybech tiskárny může docházet k vibracím, podobně jako auto při vysoké rychlosti. Tyto vibrace se projeví na výtisku jako „ghosting“ nebo „ringing“ na stěnách. Input Shaper jsou chytré algoritmy, které tyto vibrace „předpoví“ a potlačí, takže můžete tisknout rychleji bez ztráty kvality.

Tiskárna nastavila Input Shaper automaticky při první kalibraci, což pro většinu tisků stačí. Pokud ale chcete dosáhnout maximální kvality nebo chcete porozumět principu, můžete si prohlédnout grafy a nastavit parametry ručně.

#### Důležitá poznámka: parametr `FIX_SCV`

**V čem je problém?**
Grafy a výpočty Input Shaperu v Klipperu standardně používají hodnotu `square_corner_velocity = 5`. Ale u naší tiskárny je nastaveno `25`. Tento rozdíl způsobí, že vypočtené maximální hodnoty zrychlení na grafech jsou několikanásobně vyšší, než by měly být.

**Co s tím?**

1.  **Oprava výpočtů:** Aktivujte opravu pro správné zobrazení grafů: [SAVE_ZMOD_DATA FIX_SCV=1](Global.md#fix_scv).
    ```gcode
    SAVE_ZMOD_DATA FIX_SCV=1
    ```

2.  **Zlepšení kvality tisku (doporučeno):** Přidejte do souboru `mod_data/user.cfg` řádek:
    ```ini
    [printer]
    square_corner_velocity: 9
    ```

    *   **Co to udělá?** Tiskárna mírně zpomalí v ostrých rozích. Tisk se nepatrně prodlouží, ale vibrace se sníží a rohy budou ostřejší.

Chcete to mít jednodušší? Zadejte do konzole: `ENABLE_PLUGIN name=recommend`. Tento příkaz zapne plugin s doporučeními, ve kterém je `FIX_SCV` již aktivní a nastaveno `square_corner_velocity: 9`.

Nezapomeňte tiskárnu restartovat!

#### Jak používat makro `ZSHAPER`

[ZSHAPER](Calibrations.md#zshaper) – toto makro rozvibruje tiskárnu různými frekvencemi, změří odezvu a vytvoří grafy pro určení ideálních parametrů Input Shaperu pro osy X a Y.

**Specifika pro tiskárny s malou pamětí (AD5M, AD5M Pro):**
Aby nedošlo k přetížení systému, **kalibrujte osy zvlášť**.

*   `ZSHAPER` — kalibruje obě osy (X i Y).
*   `ZSHAPER X=1 Y=0` — kalibruje pouze osu X (rychlejší a méně náročné).
*   `ZSHAPER Y=1 X=0` — kalibruje pouze osu Y.

**Příklad použití a výstupu:**

1.  Zadejte do konzole příkaz pro kalibraci osy Y:
    ```gcode
    ZSHAPER Y=1 X=0
    ```

2.  Po dokončení měření získáte zprávu např.:
    ```
    // Recommended shaper is zv @ 53.2 Hz
    // Fitted shaper 'zv' frequency = 53.2 Hz (vibrations = 0.9%, smoothing ~= 0.074)
    // To avoid too much smoothing with 'zv', suggested max_accel <= 10200 mm/sec^2
    // Fitted shaper 'mzv' frequency = 54.2 Hz (vibrations = 0.0%, smoothing ~= 0.080)
    // To avoid too much smoothing with 'mzv', suggested max_accel <= 8700 mm/sec^2
    ```

    *   Systém doporučí shaper `zv`, protože má nejmenší „vyhlazení“.
    *   Ale shaper `mzv` zcela potlačí vibrace (`0.0%`), ale umožňuje jen nižší zrychlení.

#### Jak číst výsledky a rozhodnout se

**Kde najdete grafy?**
Po spuštění `ZSHAPER` se grafy a CSV soubory objeví na kartě **„Konfigurace“ -> mod_data** ve vašem webovém rozhraní (Fluidd/Mainsail).

<img width="996" height="596" alt="image" src="https://github.com/user-attachments/assets/7e1dbdf8-5de5-4ce6-8f4a-2c37b320b8b3" />

**Podrobný návod na čtení grafů:** [https://github.com/Tombraider2006/klipperFB6/blob/main/accel_graph/readme.md](https://github.com/Tombraider2006/klipperFB6/blob/main/accel_graph/readme.md)

**Možnost 1: Přijmout automatické nastavení**

Pokud vám vše vyhovuje, stačí kliknout na **`SAVE CONFIG & RESTART`** v rozhraní a tiskárna automaticky zapíše doporučené parametry.

<img width="324" height="68" alt="image" src="https://github.com/user-attachments/assets/9c76d5f7-0021-4e03-b495-6736f49dc1c9" />

<img width="745" height="389" alt="image" src="https://github.com/user-attachments/assets/b5b55e95-52af-4ee0-b34e-5bc6077d8d10" />

**Možnost 2: Ruční nastavení**

V příkladu výše je shaper `mzv` lepší, protože zcela eliminuje vibrace. Pokud jej chcete použít, přidejte tato nastavení do souboru `printer.cfg` (sekce `[input_shaper]`):

```ini
[input_shaper]
shaper_type_y = mzv   ; Vybraný typ shaperu pro osu Y
shaper_freq_y = 54.2  ; Rezonanční frekvence pro osu Y
```

**A nezapomeňte na zrychlení!**
Protože zvolený `mzv` shaper umožňuje maximální zrychlení pouze do 8700 mm/s², tuto hodnotu zapište do souboru `mod_data/user.cfg`:

```ini
[printer]
max_accel: 8700 ; Maximální zrychlení pro osy X a Y
```

#### Rychlý postup kalibrace Input Shaperu:

1.  Spusťte `SAVE_ZMOD_DATA FIX_SCV=1` pro správné výpočty.
2.  Přidejte `square_corner_velocity: 9` do `mod_data/user.cfg` pro lepší kvalitu.
3.  Spusťte kalibraci požadované osy, např. `ZSHAPER Y=1`.
4.  Prostudujte grafy a výstup v konzoli.
5.  Buď klikněte na `SAVE CONFIG`, nebo ručně zapište preferovaný `shaper_type` a `shaper_freq` do `printer.cfg` a také `max_accel` do `mod_data/user.cfg`.
6.  Restartujte tiskárnu.

---
