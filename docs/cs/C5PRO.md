# Creator5 Pro

## Důležité vlastnosti

- Tiskárna vždy pracuje se **4 barvami** (T0, T1, T2, T3). Všechny čtyři sloty jsou dostupné v menu výběru.
- Pro zapnutí kamery použijte `CAMERA_ON VIDEO=video67`.
- Možný pád Klipperu. Řešení: `Profil procesu` -> `Ostatní` -> `Výstupní G-code` -> `Vyloučení modelů` — vypněte zaškrtávací políčko.
- Místo makra `CLOSE_DILALOGS` (pomalé zavírání) vždy používejte `FAST_CLOSE_DILAOGS` (rychlé zavírání).
- Makro `NEW_SAVE_CONFIG` nefunguje.
- Žádná podpora Klipperu 13

---

## Jak připravit soubor v Orca

- [Odesílejte soubory k tisku přes Octo/Klipper.](/cs/Recommendations/#send-files-via-octoklipper-for-printing)
- [Profily pro Orca Slicer](https://github.com/ghzserg/zmod_preprocess/tree/main/profiles/Creator_5)
- [Důrazně doporučujeme zapnout preprocesor](/cs/Global/#force_md5)

---
## BARVA
## Jak používat menu pro výběr barvy a typu filamentu

<img width="900" height="900" alt="ColorWeb" src="https://github.com/user-attachments/assets/93be6d16-8c78-48b5-b1ca-6068e1e7e538" />

<img width="554" height="502" alt="{7A4A77A2-1F88-4110-9502-24FA941B9A67}" src="https://github.com/user-attachments/assets/fd77a89c-08d6-4da5-8eac-3017ca563657" />

Vyberte cívku, se kterou chcete pracovat (například cívka 2):

<img width="559" height="466" alt="{355F6AEF-00B2-4EFE-841E-23516CAC64FA}" src="https://github.com/user-attachments/assets/81084141-88b8-4d65-b583-495796f0d4fa" />

Můžete provést čtyři akce:

- Změnit barvu cívky.
- Změnit typ plastu (PLA, PETG, ABS, ...).
- Nasadit tento extruder na vozík.
- Načíst nový filament do extruderu.

**Jak změnit barvu:**

Klikněte na „Změnit barvu“. Vyberte barvu ze seznamu. Tak vám tiskárna a původní obrazovka porozumí nejlépe.

<img width="844" height="431" alt="{A27DB9D5-1C03-43D0-AF0D-5D2E16E6FFE4}" src="https://github.com/user-attachments/assets/d9a0ab97-3f78-4b51-b1a4-c4c2c4dc2b68" />

Po výběru se vrátíte zpět a barva cívky v seznamu by se měla změnit.

Pokud se barva nezměnila: zavřete okno křížkem a spusťte makro `COLOR` znovu. Někdy se obrazovka nestihne aktualizovat.

**Jak změnit typ:**
Klikněte na „Změnit typ“. Vyberte typ ze seznamu.

<img width="848" height="511" alt="{95B6566B-4FC0-4811-BC6A-E65B79E3DED7}" src="https://github.com/user-attachments/assets/f4359f48-c998-4e52-a119-e088b38f0a26" />

Pokud se typ nezměnil: zavřete okno křížkem a spusťte makro `COLOR` znovu. Někdy se obrazovka nestihne aktualizovat.

**Tip:** Pokud pro několik cívek zadáte stejnou barvu a typ, tiskárna automaticky přepne na další cívku, když první dojde. Tomu se říká „režim nekonečné cívky“.

---

## TISK
## Menu tisku

Toto okno se otevře samo, když začnete tisknout, pokud je nastaven parametr `SAVE_ZMOD_DATA SILENT=0` ve výchozím stavu.

<img width="851" height="582" alt="{8C3C174F-A553-405C-8228-7BC8EB293094}" src="https://github.com/user-attachments/assets/d8089f7d-fcf5-4a47-b664-a27db8b7e9d8" />

**Jak pochopit, co je zde napsáno:**

- V levém sloupci jsou čísla nástrojů a barvy ze souboru předané ze sliceru.
- V pravém sloupci jsou čísla cívek a barvy načtené/použité na tiskárně.
- `Cube.gcode` – to je název souboru, který se tiskne.
- `1: PETG ->` – to je první barva ze souboru (oranžový PETG). Tiskne se filamentem z cívky 3 (oranžový PETG).
- `2: PLA ->` – to je druhá barva (šedý PLA). Tiskne se filamentem z cívky 4 (modrý PLA). Protože v tiskárně nejsou žádné jiné PLA plasty.
- `3: PETG ->` – třetí barva (černý PETG), tiskne se z cívky 3 (oranžový PETG). Protože v tiskárně nejsou žádné jiné PETG plasty.
- `4: PETG-CF ->` – čtvrtá barva (modrý PETG-CF), tiskne se z cívky 1 (černý PETG-CF). Protože v tiskárně nejsou žádné jiné PETG-CF plasty.

Pokud obrázek vypadá takto

<img width="837" height="571" alt="{013853B5-7E63-4AA0-9C1E-2243920F9FAD}" src="https://github.com/user-attachments/assets/a1bdc9e5-314d-4e69-9a73-5010faf4b233" />

Znamená to, že máte vypnutou volbu automatického přiřazení barev a/nebo skenování souborů. Můžete kliknout na tlačítko `AUTO_SELECT_COLORS` nebo ji zapnout v globálních parametrech:
```
SAVE_ZMOD_DATA SCAN_FILE_COLORS=1 AUTO_ASSIGN_COLORS=1
```

[Důrazně doporučujeme zapnout preprocesor](/cs/Global/#force_md5)

---

### Vytvoření mapy stolu a AUTO PA

V menu tisku jsou dvě důležitá tlačítka:

**Leveling (Mapa stolu):**

- `Snímat mapu stolu` — před tiskem bude automaticky vytvořena mapa stolu.
- `Nesnímat mapu stolu` — použije se dříve uložená mapa.

**Auto PA (Automatický výběr Pressure Advance):**

- Pokud je tlačítko `Auto PA` aktivní (zelené), tiskárna **před začátkem tisku** automaticky vybere optimální hodnotu Pressure Advance pro každý použitý extruder.
- Proces trvá několik minut, ale výrazně zlepšuje kvalitu rohů a tenkých prvků.
- Pokud je `Auto PA` vypnuté, použijí se hodnoty PA ze sliceru.

Automatická kalibrace probíhá od 0,01 do 0,04 a pro viskózní plasty, jako je PETG, je nepoužitelná

---

## Jemné ladění

Nejprve je třeba vypnout původní obrazovku tiskárny pomocí makra `DISPLAY_OFF`.

**Jak najít tato nastavení:**

1. Klikněte na kartu „Konfigurace“.
2. Najděte a otevřete složku `mod_data`.
3. V této složce najděte a otevřete soubor `filament.json`.

<img width="480" height="826" alt="{F5EAE8D4-1A9F-4E6C-99A1-B609A331E82D}" src="https://github.com/user-attachments/assets/4b7b5f91-b3ff-4c75-824d-4ec06e2ac6de" />

V tomto souboru je pro každý typ plastu (PLA, ABS, PETG atd.) seznam čísel. Zde je jejich význam:

| Parametr | Výchozí | Popis |
|---|---|---|
| `temp` | 220 | Teplota, na kterou se tryska zahřeje pro výměnu filamentu. Hodnota závisí na typu materiálu |
| `temp_manual` | 250 | Teplota proplachu v ručním režimu (při načítání přes menu). |
| `temp_wait` | 120 | Teplota nečinnosti — na tuto teplotu tryska vychladne po proplachu. |
| `filament_drop_length` | 50 | **Délka odhozu.** Kolik milimetrů plastu tiskárna vytlačí do odpadního koše, aby očistila trysku od staré barvy. |
| `filament_full_length` | 600 | **Délka trubice.** Kolik milimetrů plastu tiskárna vytlačí po aktivaci senzoru konce filamentu |
| `filament_tube_length` | 295 | Délka načtení filamentu při vložení nové cívky. |

**Výchozí teploty pro různé materiály:**

| Materiál | `temp` | `temp_manual` | `temp_wait` |
|---|---|---|---|
| PLA | 220 | 250 | 120 |
| PETG | 240 | 270 | 140 |
| PLA-CF | 220 | 250 | 120 |
| PETG-CF | 240 | 270 | 140 |
| ABS | 250 | 280 | 150 |
| ASA | 250 | 280 | 150 |
| SILK | 220 | 250 | 120 |
| PET-CF | 270 | 300 | 170 |
| S-PAHT | 280 | 310 | 180 |
| S-MULTI | 270 | 300 | 170 |
| PA-CF | 270 | 300 | 170 |
| HIPS | 250 | 280 | 150 |
| PVA | 220 | 250 | 120 |
| TPU-90A | 220 | 250 | 120 |
| TPU-95A | 220 | 250 | 120 |
| TPU-64D | 220 | 250 | 120 |

### Rozšířené parametry

| Parametr | Výchozí | Popis |
|---|---|---|
| `trash_x` | 275.0 | Souřadnice X odpadního koše. |
| `trash_y` | 254.0 | Souřadnice Y odpadního koše. |
| `trash_z` | 10.0 | Souřadnice Z odpadního koše. |
| `wiper_x` | 266.50 | Souřadnice X místa pro čištění trysky (guma). |
| `wiper_y` | 13.80 | Souřadnice Y místa pro čištění trysky. |
| `wiper_z` | 1.0 | Souřadnice Z místa pro čištění trysky. |
| `fan_speed` | 255.0 | Rychlost ventilátoru (od 0 do 255) při chlazení trysky po proplachu. |

> **Pozor!** Změna parametrů v rozšířené sekci může vést k nesprávnému fungování tiskárny, ucpání filamentu nebo poškození. Měňte je pouze tehdy, pokud plně rozumíte tomu, za co každý parametr odpovídá a jaké mohou být následky.

---

## Globální parametry

Aby se okno výběru barvy nezobrazovalo při začátku tisku, použijte globální parametr
**SILENT**:
- `0` — zobrazit okno (výchozí)
- `1` — nezobrazovat okno, použít dříve nastavené barvy
- `2` — nezobrazovat okno, při selhání automatického přiřazení zobrazit menu výběru
```
SAVE_ZMOD_DATA SILENT=1
```

---

Chcete-li zapnout skenování G-code souborů na přítomnost informací o nástrojích, barvách a materiálech, použijte parametr
**SCAN_FILE_COLORS**.
```
SAVE_ZMOD_DATA SCAN_FILE_COLORS=1
```
Můžete také nastavit hodnotu:
- `0` — parametr vypnout
- `1` — plné skenování G-code souboru
- `2` — kontrolovat pouze data připravená skriptem sliceru, bez skenování celého souboru
**!Pokud je skenování souborů vypnuté**, tiskárna neví, kolik extruderů se používá, a proto **bude Auto PA spuštěno pro všechny cívky**

---

Chcete-li zapnout **automatické přiřazení barev** z G-code souboru k fyzickým cívkám, použijte parametr
**AUTO_ASSIGN_COLORS**. Aby tato funkce fungovala, musí být zapnuto skenování souborů.
```
SAVE_ZMOD_DATA AUTO_ASSIGN_COLORS=30
```
Můžete nastavit vlastní hodnoty pro přerušení tisku v tichém režimu sečtením následujících čísel:
- `1` — tisk pokračuje, i když automatické přiřazení barev selhalo
- `2` — Alespoň jeden materiál neodpovídá (například v G-code je uveden ABS, ale máte načtený pouze PLA)
- `4` — Alespoň jedna barva vůbec neodpovídá (obvykle proto, že je vypnuté skenování souborů)
- `8` — Alespoň jedna barva odpovídá špatně
- `16` — Stejná fyzická cívka byla přiřazena více než jednomu indexu nástroje v souboru
Například použití hodnoty `30` povede k přerušení tisku v tichém režimu, pokud nastanou jakékoli problémy s automatickým přiřazením, a `AUTO_ASSIGN_COLORS=10` (2+8) přeruší tisk, pokud alespoň jeden materiál neodpovídá + alespoň jedna barva odpovídá špatně.

---

Chcete-li automaticky vypnout ohřev nepoužívaných extruderů při vícebarevném tisku, použijte parametr **unused_extruders_off_time**. Nastavuje dobu čekání (v minutách), po které bude nečinný nástroj vypnut, aby se zabránilo degradaci filamentu a zbytečnému provozu.

```
SAVE_ZMOD_DATA unused_extruders_off_time=5
```

Můžete nastavit následující hodnoty (v minutách):
* `0` — funkce vypnuta (extrudery se během nečinnosti nevypínají)
* `5`, `10`, `20`, `40`, `60` — doba, po které bude nepoužívaný extruder vypnut

**Důležité:** Pro správnou funkci této volby musí být ve sliceru zapnuta funkce **Ooze prevention** (Prevence vytékání plastu). Bez ní tiskárna nedokáže správně zpracovat teplotní režimy nečinných hotendů během výměny filamentu.

<img width="375" height="143" alt="{2CA02C09-7658-478E-A2A3-F7A9E9A077F2}" src="https://github.com/user-attachments/assets/6340a479-62a8-4476-93f1-c4054a279618" />

---

## Změna počtu pokusů o uchopení nebo odložení nástroje

Je třeba přidat do `mod_data/user.cfg`:

```
[zmod_color]
retry: 3
```

Výchozí je 5.

---

## Přidání vlastních typů filamentu

Aby tato nastavení fungovala, je třeba vypnout původní obrazovku tiskárny pomocí makra `DISPLAY_OFF`.

Pro přidání nového typu filamentu přidejte do `mod_data/user.cfg`:

```
[zmod_color]
filament_NEWTYPE: 300
```

Kde `NEWTYPE` nahraďte požadovaným typem filamentu (například `HIPS`) a číslo je teplota extruderu pro načtení, vyjmutí a proplach tohoto filamentu. Na základě této hodnoty se automaticky vypočítají `temp_manual` (+30) a `temp_wait` (−100).

Pro skrytí typu filamentu přidejte do `mod_data/user.cfg`:

```
[zmod_color]
hide_filament_types: XXX,YYY,ZZZ
```

Kde `XXX`, `YYY`, `ZZZ` nahraďte požadovanými typy filamentu (například `PLA-CF,PETG-CF,SILK`). To lze použít pro skrytí výchozích typů nebo typů, které jste přidali ručně. Typ filamentu se přitom nevypne, pouze se skryje v menu výběru typu.

---

## Přidání vlastních barev

Aby tato nastavení fungovala, je třeba vypnout původní obrazovku tiskárny pomocí makra `DISPLAY_OFF`.

Pro přidání nebo přejmenování barvy otevřete `mod_data/color/cs.json` (místo `cs` použijte svůj jazyk) a přidejte novou barvu nebo přejmenujte existující.

Aby se název barvy zobrazoval, musí název barvy začínat podtržítkem `_`.

**Příklad:**
```json
{
   "ffffff": "bílá",
   "fffff1": "_průhledná",
   "fef043": "jasně žlutá",
   "dcf478": "světle zelená",
   "0acc38": "zelená",
   "067749": "tmavě zelená",
   "0c6283": "modrozelená",
   "0de2a0": "tyrkysová",
   "75d9f3": "světle modrá",
   "45a8f9": "modrá",
   "2750e0": "tmavě modrá",
   "46328e": "fialová",
   "a03cf7": "jasně fialová",
   "f330f9": "purpurová",
   "d4b0dc": "lila",
   "f95d73": "růžová",
   "f72224": "červená",
   "7c4b00": "hnědá",
   "f98d33": "oranžová",
   "fdebd5": "béžová",
   "d3c4a3": "světle hnědá",
   "af7836": "terakotová",
   "898989": "šedá",
   "bcbcbc": "světle šedá",
   "161616": "černá"
}
```

Nápis `_průhledná` se zobrazí na tlačítkách.

---

## Kalibrace extruderů

Kalibrace extruderů umožňuje tiskárně přesně znát polohu každé ze čtyř trysek vůči sobě navzájem. To je nezbytné pro kvalitní vícebarevný tisk.

**Kdy je třeba kalibrovat:**
- Po výměně nebo opravě extruderu.
- Pokud si všimnete, že se barvy na modelu neshodují (posun v X, Y nebo Z).

**Jak spustit:**

1. **Sejměte tiskovou podložku** ze stolu!
2. Spusťte makro `CALIBRATE_EXTRUDERS` z menu nebo zadejte do konzole:
   ```
   CALIBRATE_EXTRUDERS
   ```
3. Zobrazí se potvrzovací okno. Klikněte na `OK`.

**Co se stane:**

- Tiskárna provede (G28).
- Zahřeje stůl na 65 °C.
- Postupně vezme každý ze 4 extruderů (T0–T3).
- Pro každý extruder: zahřeje trysku, provede proplach, očistí o gumu a poté pomocí senzorů určí přesné souřadnice X, Y a Z.
- Výsledky se automaticky zapíší do souboru `rw/extruder.json`.
- Na konci tiskárna vypíše do konzole nalezené posuny pro každý extruder.

**Další parametry** (pro pokročilé):

| Parametr | Výchozí | Popis |
|---|---|---|
| `BED_TEMP` | 65.0 | Teplota stolu při kalibraci |
| `SEARCH` | 14.0 | Poloměr hledání senzoru (mm) |
| `HOVER` | 0.6 | Výška vznášení nad bodem |
| `SAFE_Z` | 10.0 | Bezpečná výška Z |

**Příklad s parametry:**

```
CALIBRATE_EXTRUDERS BED_TEMP=70 SEARCH=12
```

> **Pozor!** Nepřerušujte kalibraci. Proces trvá několik minut.

---

## Kalibrace VFA

Kalibrace VFA (Vertical Fine Artifacts) umožňuje omezit vertikální artefakty na povrchu tisku způsobené rezonancemi krokových motorů.

**Jak spustit:**

Zadejte do konzole:
```
CALIBRATE_VFA T=0
```

Kde `T=0` je číslo extruderu (0–3), který bude během kalibrace použit.

**Co se stane:**

- Tiskárna vezme zadaný extruder.
- Vynuluje všechny G-code posuny.
- Přesune hlavu do středu stolu (X130 Y130).
- Spustí automatickou kalibraci rezonancí (`STEPPER_RESONANCE_FACTORY_CALIBRATE`).
- Vrátí extruder na místo.
- Uloží konfiguraci (`SAVE_CONFIG`).

> **Tip:** Kalibraci VFA doporučujeme provést, když se na povrchu tisku objeví viditelné vertikální pruhy.

---

## Makro `T_INFO`

Makro `T_INFO` zobrazuje aktuální stav všech extruderů a senzorů tiskárny.

**Jak spustit:**
```
T_INFO
```

**Co se vypíše do konzole:**

```
// T0: home
// T1: HEAD
// T2: home
// T3: home
// Door: Close
// Top: Close
// Offset: X=0.000 Y=0.000 Z=0.061 (0.000)
```

**Jak to číst:**

- `home` — extruder je na svém místě (v parkovací kapse).
- `HEAD` — extruder je nasazen na tiskové hlavě.
- `?` — neurčitý stav (senzory nezareagovaly).
- `ERROR (both)` — chyba: extruder je současně doma i na hlavě (desynchronizace senzorů).
- `Door` — stav předních dvířek (`Close` / `Open`).
- `Top` — stav horního krytu (`Close` / `Open`).
- `Offset` — aktuální G-code posuny podél os X, Y, Z.

---

## Režimy ventilace

Creator5 Pro je vybaven systémem ventilace komory s několika ventilátory. Správné řízení ventilace je kriticky důležité pro kvalitu tisku různých materiálů.

**Externí přívod (PLA, TPU):**

Makro `AIR_CIRCULATION_EXTERNAL` zapíná odsávání z komory a přívod čerstvého vzduchu. Je potřeba pro PLA a TPU, aby plast rychle chladl a nezměkl teplem komory.
```
AIR_CIRCULATION_EXTERNAL
```
| Ventilátor | Rychlost |
|---|---|
| `chamber_fan` (odsávání) | 0.5 |
| `chamber_cool_fan` (chlazení) | 0.7 |
| `chamber_heat_fan` (ohřev) | 0.0 |
| `chamber_loop_fan` (cirkulace) | 0.0 |

**Vnitřní cirkulace (ABS, ASA):**

Makro `AIR_CIRCULATION_INTERNAL` zapíná vnitřní cirkulaci a ohřev komory. Je potřeba pro ABS a ASA, aby se zabránilo delaminaci a deformaci z teplotních rozdílů.
```
AIR_CIRCULATION_INTERNAL
```
| Ventilátor | Rychlost |
|---|---|
| `chamber_fan` (odsávání) | 0.0 |
| `chamber_cool_fan` (chlazení) | 0.0 |
| `chamber_heat_fan` (ohřev) | 0.9 |
| `chamber_loop_fan` (cirkulace) | 0.3 |

**Zastavení ventilace:**
Makro `AIR_CIRCULATION_STOP` zcela vypne všechny ventilátory komory.
```
AIR_CIRCULATION_STOP
```

### Kam přidat makra ventilace

> **Doporučení:** Nejlepší je přidat volání maker ventilace do **kódu filamentu** ve sliceru. Tím se zajistí automatické přepnutí režimu při změně materiálu.

**V OrcaSliceru:**

1. Otevřete nastavení filamentu.
2. Přejděte na kartu „Nastavení filamentu“.
3. Do pole **Počáteční G-code filamentu** přidejte potřebné makro:
   - Pro PLA: `AIR_CIRCULATION_EXTERNAL`
   - Pro ABS: `AIR_CIRCULATION_INTERNAL`
   - Pro TPU: `AIR_CIRCULATION_EXTERNAL`

**Příklad pro PLA:**
```
; Filament start gcode
AIR_CIRCULATION_EXTERNAL
```

**Příklad pro ABS:**
```
; Filament start gcode
AIR_CIRCULATION_INTERNAL
```

Takto se při vícebarevném tisku s různými materiály ventilace automaticky přepne do potřebného režimu pro každý extruder.

---

## Zrychlení tisku

Napište do 'mod_data/user.cfg'

```
[printer]
short_move_limit: False
short_extrude_move_limit: False
```

Toto nastavení výrazně zrychluje tisk, ale může způsobit pády tiskárny při tisku s fuzzy skin.

---

## Vypnutí rychlého návratu hlavy a předehřevu

Napište do 'mod_data/user.cfg'

```
[virtual_sdcard]
enable_speed_return: False
enable_preheat: False
```

- **enable_speed_return**: False — Vypne nucený návrat hlavy k modelu rychlostí 600 mm/s, čímž se odstraní riziko silných kinematických nárazů a zlomení hotendu o vytištěné části (prime tower). Řízení bezpečné trajektorie návratu je plně předáno OrcaSliceru.
- **enable_preheat**: False — Vypne skenování souborů Klipperu na pozadí a odlehčí procesoru. Vestavěná funkce zrychlovala ohřev při použití více než dvou trysek v krátkém intervalu, protože tiskárna nemůže ohřívat více než dvě trysky současně. Předběžný ohřev se přesněji vypočítává na straně OrcaSliceru.

---

## Vypnutí oznámení o otevřených dvířkách

Chcete-li odstranit oznámení o otevřeném krytu nebo dvířkách v režimu bez původní obrazovky

Napište do 'mod_data/user.cfg'

```
[gcode_button topDoor]
press_gcode:
release_gcode:

[gcode_button frontDoor]
press_gcode:
release_gcode:
```
