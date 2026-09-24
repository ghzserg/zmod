# Creator5 Pro

1. [Důležité poznámky](#důležité-poznámky)
2. [Jak připravit soubor v Orca](#jak-připravit-soubor-v-orca)
3. [Jak používat nabídku výběru barvy](#jak-používat-nabídku-výběru-barvy)
4. [Nabídka tisku](#nabídka-tisku)
5. [Jemné ladění](#jemné-ladění)
6. [Globální parametry](#globální-parametry)
7. [Přidání vlastních typů filamentů](#přidání-vlastních-typů-filamentů)
8. [Přidání vlastních barev](#přidání-vlastních-barev)
9. [Kalibrace extruderů](#kalibrace-extruderů)
10. [Kalibrace VFA](#kalibrace-vfa)
11. [Makro `T_INFO`](#makro-t_info)
12. [Režimy ventilace](#režimy-ventilace)

---

## Důležité poznámky

- Tiskárna vždy pracuje se **4 barvami** (T0, T1, T2, T3). Všechny čtyři sloty jsou dostupné v nabídce výběru.
- Pro zapnutí kamery je nutné použít `CAMERA_ON VIDEO=video67`.
- Může dojít k pádu Klipperu. Řešení: `Profil procesu` -> `Ostatní` -> `Výstupní G-kód` -> zrušit zaškrtnutí `Vyloučit objekty`.
- Pokud odesíláte soubor `3mf`, používejte pouze režim s originálním displejem.
- Pokud odesíláte soubor `gcode`, je problematické změnit pořadí barev při tisku s originálním displejem.
- Místo makra `CLOSE_DILALOGS` (pomalé zavírání) vždy používejte `FAST_CLOSE_DILAOGS` (rychlé zavírání).
- Makro `NEW_SAVE_CONFIG` nefunguje.
- Žádná podpora pro Klipper 13.

---

## Jak připravit soubor v Orca

[Odesílejte soubory k tisku přes Octo/Klipper.](/ru/Recommendations/#отправляйте-файлы-на-печать-через-octoklipper)

---
## COLOR
## Jak používat nabídku výběru barvy

<img width="881" height="856" alt="image" src="https://github.com/user-attachments/assets/7acd4ccf-3623-4afe-83bf-fcb96f5a416b" />

<img width="554" height="502" alt="{7A4A77A2-1F88-4110-9502-24FA941B9A67}" src="https://github.com/user-attachments/assets/fd77a89c-08d6-4da5-8eac-3017ca563657" />

Nyní vyberte cívku, se kterou chcete pracovat (např. cívka 2):

<img width="559" height="466" alt="{355F6AEF-00B2-4EFE-841E-23516CAC64FA}" src="https://github.com/user-attachments/assets/81084141-88b8-4d65-b583-495796f0d4fa" />

Můžete provést čtyři akce:
- Změnit barvu cívky.
- Změnit typ plastu (např. z PLA na PETG).
- Umístit tento extruder na vozík (karétu).
- Načíst novou cívku do extruderu.

**Jak změnit barvu:**
Klikněte na „Změnit barvu“. Vyberte barvu ze seznamu. Takto tiskárně a originálnímu displeji nejlépe porozumíte.

<img width="560" height="834" alt="{55C179BC-DB74-480D-BA6A-DBDF193794B5}" src="https://github.com/user-attachments/assets/32dfabcf-23c6-4ed8-b606-fa1e0fb01e67" />

Po výběru se vrátíte zpět a barva cívky v seznamu by se měla změnit.

Pokud se barva nezměnila: zavřete okno křížkem a spusťte makro `COLOR` znovu. Někdy se displej nestihne aktualizovat.

**Jak změnit typ:**
Klikněte na „Změnit typ“. Vyberte typ ze seznamu.

<img width="554" height="830" alt="{07CF6B87-8483-4300-B354-554431CCBE54}" src="https://github.com/user-attachments/assets/31445f6c-18b7-4e26-80fb-4f8306b11d57" />

Pokud se typ nezměnil: zavřete okno křížkem a spusťte makro `COLOR` znovu. Někdy se displej nestihne aktualizovat.

**Tip:** Pokud pro více cívek zadáte stejnou barvu a typ, tiskárna automaticky přepne na další cívku, jakmile první dojde. Tomu se říká „režim nekonečné cívky“ (infinite spool).

---

## PRINT
## Nabídka tisku

Toto okno se otevře samo, když začnete tisknout.

<img width="562" height="593" alt="{A688018F-CB9C-4EFA-9431-AAE9E2DE842E}" src="https://github.com/user-attachments/assets/92cababe-52b1-49aa-aea3-1ad6ddf03cfe" />

**Jak porozumět tomu, co je zde napsáno:**

`Cube.gcode` – název souboru, který se tiskne.
`1` – první barva ze souboru. Tiskne se filamentem z cívky 2 (oranžový PETG).
`2` – druhá barva. Tiskne se filamentem z cívky 4 (šedý PLA).
`3` – třetí barva, tiskne se z cívky 1 (černý PETG).

### Vyrovnávání podložky a AUTO PA

V nabídce tisku jsou dvě důležitá tlačítka:

**Leveling (Vyrovnávání podložky):**
- `Vyrovnat podložku` – před tiskem se automaticky vytvoří mapa podložky.
- `Nevyrovnávat podložku` – použije se dříve uložená mapa.

**Auto PA (Automatické ladění Pressure Advance):**
- Pokud je tlačítko `Auto PA` aktivní (zelené), tiskárna **před zahájením tisku** automaticky vybere optimální hodnotu Pressure Advance pro každý používaný extruder.
- Proces trvá několik minut, ale výrazně zlepšuje kvalitu rohů a jemných prvků.
- Pokud je `Auto PA` vypnuté, použijí se hodnoty PA ze sliceru.

Automatická kalibrace probíhá v rozsahu 0,01 až 0,04 a pro viskózní plasty, jako je PETG, je zbytečná.

---

## Jemné ladění

Nejprve je nutné vypnout originální displej tiskárny pomocí makra `DISPLAY_OFF`.

**Jak najít tato nastavení:**
1. Klikněte na kartu „Konfigurace“.
2. Najděte a otevřete složku `mod_data`.
3. V této složce najděte a otevřete soubor `filament.json`.

<img width="480" height="826" alt="{F5EAE8D4-1A9F-4E6C-99A1-B609A331E82D}" src="https://github.com/user-attachments/assets/4b7b5f91-b3ff-4c75-824d-4ec06e2ac6de" />

V tomto souboru je pro každý typ plastu (PLA, ABS, PETG atd.) seznam čísel. Zde je vysvětlení, co znamenají:

| Parametr | Výchozí | Popis |
|---|---|---|
| `temp` | 220 | Teplota, na kterou se tryska zahřeje pro výměnu filamentu. Hodnota závisí na typu materiálu. |
| `temp_manual` | 250 | Teplota pročištění v ručním režimu (při načítání přes nabídku). |
| `temp_wait` | 120 | Teplota klidového stavu – teplota, na kterou tryska po pročištění vychladne. |
| `filament_drop_length` | 50 | **Délka pročištění.** Kolik milimetrů plastu tiskárna vytlačí do odpadního koše, aby vyčistila trysku od staré barvy. |
| `filament_tube_length` | 295 | Délka načítání filamentu při vložení nové cívky. |

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

### Pokročilé parametry

| Parametr | Výchozí | Popis |
|---|---|---|
| `trash_x` | 275.0 | Souřadnice X odpadního koše. |
| `trash_y` | 254.0 | Souřadnice Y odpadního koše. |
| `trash_z` | 10.0 | Souřadnice Z odpadního koše. |
| `wiper_x` | 266.50 | Souřadnice X místa pro čištění trysky (stěrka). |
| `wiper_y` | 13.80 | Souřadnice Y místa pro čištění trysky. |
| `wiper_z` | 1.0 | Souřadnice Z místa pro čištění trysky. |
| `fan_speed` | 255.0 | Rychlost ventilátoru (od 0 do 255) při chlazení trysky po pročištění. |

> **Upozornění!** Změna parametrů v pokročilé sekci může vést k nesprávné funkci tiskárny, zaseknutí filamentu nebo poškození. Měňte je pouze tehdy, pokud plně rozumíte tomu, za co každý parametr odpovídá a jaké mohou být důsledky.

---

## Globální parametry

Aby se okno výběru barvy nezobrazovalo na začátku tisku, použijte globální parametr **SILENT**:
- `0` – zobrazit okno (výchozí)
- `1` – nezobrazovat okno, použít dříve nastavené barvy
- `2` – nezobrazovat okno, nepoužívat podávací systém

```
SAVE_ZMOD_DATA SILENT=1
```

Pro povolení skenování souborů gcode za účelem získání informací o nástrojích, barvách a materiálech použijte parametr **SCAN_FILE_COLORS**. Můžete také nastavit hodnotu `2`, abyste kontrolovali pouze data připravená skriptem sliceru, bez skenování celých souborů:
```
SAVE_ZMOD_DATA SCAN_FILE_COLORS=1
```

Pro povolení **automatického přiřazování barev** ze souboru gcode k fyzickým cívkám použijte parametr **AUTO_ASSIGN_COLORS**. Aby tato funkce fungovala, musí být aktivováno skenování souborů. Použití hodnoty `30` povede k přerušení tisku v tichém režimu, pokud dojde k jakýmkoli problémům s automatickým přiřazením:
```
SAVE_ZMOD_DATA AUTO_ASSIGN_COLORS=30
```

Můžete nastavit vlastní hodnoty pro přerušení tisku v tichém režimu sečtením následujících čísel:
- `2` – Alespoň jeden materiál neodpovídá (např. v gcode je uveden ABS, ale máte načteno pouze PLA)
- `4` – Alespoň jedna barva vůbec neodpovídá (obvykle proto, že skenování souborů je vypnuté)
- `8` – Alespoň jedna barva odpovídá jen slabě
- `16` – Stejná fyzická cívka byla přiřazena více než jednomu indexu nástroje v souboru

**Pokud je skenování souboru vypnuté**, tiskárna neví, kolik extruderů se používá, a proto se **Auto PA spustí pro všechny cívky**.

---

## Přidání vlastních typů filamentů

Aby tato nastavení fungovala, musíte vypnout originální displej tiskárny pomocí makra `DISPLAY_OFF`.

Pro přidání nového typu filamentu do `mod_data/user.cfg` přidejte:

```
[zmod_color]
filament_NEWTYPE: 300
```

Kde `NEWTYPE` nahraďte požadovaným typem filamentu (např. `HIPS`) a číslo je teplota extruderu pro načítání, vyjímání a pročištění tohoto filamentu. Na základě této hodnoty se automaticky vypočítají `temp_manual` (+30) a `temp_wait` (−100).

Pro skrytí typu filamentu do `mod_data/user.cfg` přidejte:

```
[zmod_color]
hide_filament_types: XXX,YYY,ZZZ
```

Kde `XXX`, `YYY`, `ZZZ` nahraďte typy filamentů, které chcete skrýt (např. `PLA-CF,PETG-CF,SILK`). To lze použít ke skrytí výchozích typů nebo typů, které jste přidali ručně. Typ filamentu není deaktivován, pouze se skryje v nabídce výběru typu.

---

## Přidání vlastních barev

Aby tato nastavení fungovala, musíte vypnout originální displej tiskárny pomocí makra `DISPLAY_OFF`.

Pro přidání nebo přejmenování barvy otevřete `mod_data/color/cs.json` (místo `cs` použijte kód vašeho jazyka) a přidejte novou barvu nebo přejmenujte existující.

Aby se název barvy zobrazil, musí začínat podtržítkem `_`.

**Příklad:**
```json
{
   "ffffff": "bílá",
   "fffff1": "_průhledná",
   "fef043": "zářivě žlutá",
   "dcf478": "světle zelená",
   "0acc38": "zelená",
   "067749": "tmavě zelená",
   "0c6283": "modrozelená",
   "0de2a0": "tyrkysová",
   "75d9f3": "světle modrá",
   "45a8f9": "modrá",
   "2750e0": "tmavě modrá",
   "46328e": "fialová",
   "a03cf7": "zářivě fialová",
   "f330f9": "purpurová",
   "d4b0dc": "liliová",
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

Text `_průhledná` se zobrazí na tlačítkách.

---

## Kalibrace extruderů

Kalibrace extruderů umožňuje tiskárně přesně znát polohu každé ze čtyř trysek vůči sobě navzájem. To je nezbytné pro kvalitní vícebarevný tisk.

**Kdy kalibrovat:**
- Po výměně nebo opravě extruderu.
- Pokud si všimnete, že barvy na modelu nesedí (posun v ose X, Y nebo Z).

**Jak spustit:**

1. **Sejměte tiskovou podložku** ze stolu!
2. Spusťte makro `CALIBRATE_EXTRUDERS` z nabídky nebo zadejte do konzole:
   ```
   CALIBRATE_EXTRUDERS
   ```
3. Zobrazí se potvrzovací okno. Klikněte na `OK`.

**Co se stane:**
- Tiskárna provede homing (G28).
- Zahřeje podložku na 65 °C.
- Postupně vezme každý ze 4 extruderů (T0–T3).
- Pro každý extruder: zahřeje trysku, provede pročištění, vyčistí ji o stěrku a poté pomocí senzorů určí přesné souřadnice X, Y a Z.
- Výsledky se automaticky uloží do souboru `rw/extruder.json`.
- Po dokončení tiskárna vypíše do konzole nalezené posuny pro každý extruder.

**Další parametry** (pro pokročilé):

| Parametr | Výchozí | Popis |
|---|---|---|
| `BED_TEMP` | 65.0 | Teplota podložky během kalibrace |
| `SEARCH` | 14.0 | Poloměr hledání senzoru (mm) |
| `HOVER` | 0.6 | Výška vznášení nad bodem |
| `SAFE_Z` | 10.0 | Bezpečná výška Z |

**Příklad s parametry:**
```
CALIBRATE_EXTRUDERS BED_TEMP=70 SEARCH=12
```

> **Upozornění!** Nepřerušujte kalibraci. Proces trvá několik minut.

---

## Kalibrace VFA

Kalibrace VFA (Vertical Fine Artifacts) pomáhá snížit vertikální artefakty na povrchu tisku způsobené rezonancemi krokových motorů.

**Jak spustit:**

Zadejte do konzole:
```
CALIBRATE_VFA T=0
```

Kde `T=0` je číslo extruderu (0–3), který bude během kalibrace použit.

**Co se stane:**
- Tiskárna vezme zadaný extruder.
- Vynuluje všechny posuny G-kódu.
- Přesune hlavu do středu podložky (X130 Y130).
- Spustí automatickou kalibraci rezonancí (`STEPPER_RESONANCE_FACTORY_CALIBRATE`).
- Vrátí extruder na místo.
- Uloží konfiguraci (`SAVE_CONFIG`).

> **Tip:** Doporučuje se provádět kalibraci VFA, když se na povrchu tisku objeví viditelné vertikální pruhy.

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
- `home` – extruder je na svém místě (v parkovací kapse).
- `HEAD` – extruder je nasazen na tiskové hlavě.
- `?` – nedefinovaný stav (senzory nespustily).
- `ERROR (both)` – chyba: extruder je současně doma i na hlavě (desynchronizace senzorů).
- `Door` – stav předních dveří (`Close` / `Open`).
- `Top` – stav horního krytu (`Close` / `Open`).
- `Offset` – aktuální posuny G-kódu podél os X, Y, Z.

---

## Režimy ventilace

Creator5 Pro je vybaven systémem ventilace komory s několika ventilátory. Správné řízení ventilace je kritické pro kvalitu tisku různých materiálů.

**Externí sání (PLA, TPU):**
Makro `AIR_CIRCULATION_EXTERNAL` – zapíná odsávání z komory a přívod čerstvého vzduchu. Je potřeba pro PLA a TPU, aby plast rychle chladl a nezměkl teplem komory.
```
AIR_CIRCULATION_EXTERNAL
```
| Ventilátor | Rychlost |
|---|---|
| `chamber_fan` (odsávání) | 0.5 |
| `chamber_cool_fan` (chlazení) | 0.7 |
| `chamber_heat_fan` (ohřev) | 0.0 |
| `chamber_loop_fan` (cirkulace) | 0.0 |

**Interní cirkulace (ABS, ASA):**
Makro `AIR_CIRCULATION_INTERNAL` – zapíná vnitřní cirkulaci a ohřev komory. Je potřeba pro ABS a ASA, aby se předešlo delaminaci a kroucení v důsledku teplotních výkyvů.
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
Makro `AIR_CIRCULATION_STOP` – zcela vypne všechny ventilátory komory.
```
AIR_CIRCULATION_STOP
```

### Kam přidat makra ventilace

> **Doporučení:** Nejlepší je přidat volání maker ventilace do **kódu filamentu** ve sliceru. Tím se zajistí automatické přepínání režimu při změně materiálu.

**V OrcaSlicer:**
1. Otevřete nastavení filamentu.
2. Přejděte na kartu „Nastavení filamentu“.
3. Do pole **Počáteční G-kód filamentu** přidejte požadované makro:
   - Pro PLA: `AIR_CIRCULATION_EXTERNAL`
   - Pro ABS: `AIR_CIRCULATION_INTERNAL`
   - Pro TPU: `AIR_CIRCULATION_EXTERNAL`

**Příklad pro PLA:**
```gcode
; Filament start gcode
AIR_CIRCULATION_EXTERNAL
```

**Příklad pro ABS:**
```gcode
; Filament start gcode
AIR_CIRCULATION_INTERNAL
```

Tímto způsobem se při vícebarevném tisku s různými materiály ventilace automaticky přepne do požadovaného režimu pro každý extruder.
