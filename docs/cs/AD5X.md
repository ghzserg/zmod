### AD5X

1. [Klíčové vlastnosti](#1-klíčové-vlastnosti)
2. [Jak připravit soubor v Orca](#2-jak-připravit-soubor-v-orca)
3. [Jak používat menu pro výběr barvy (makro `COLOR`)](#3-jak-používat-menu-pro-výběr-barvy-makro-color)
4. [Menu tisku (`PRINT`)](#4-menu-tisku-print)
    - [Globální parametry AD5X](#globální-parametry-ad5x)
5. [Jak ručně sdělit tiskárně, která cívka je vložena](#5-jak-ručně-sdělit-tiskárně-která-cívka-je-vložena)
6. [Jak konfigurovat odpadní filament při výměně filamentu](#6-jak-konfigurovat-odpadní-filament-při-výměně-filamentu)

    - 🔧 [Základní parametry (nejčastěji upravované)](#základní-parametry-nejčastěji-upravované)
       - ⚙️ [Pokročilé parametry (neupravujte, pokud si nejste jisti výsledkem)](#pokročilé-parametry-neupravujte-pokud-si-nejste-jisti-výsledkem)

7. [Přidat vlastní typy filamentů](#7-přidat-vlastní-typy-filamentů)
8. [Přidat vlastní barvy](#8-přidat-vlastní-barvy)
9. [Oprava funkce odpadní nádobky a nože na řezání filamentu](#9-oprava-funkce-odpadní-nádobky-a-nože-na-řezání-filamentu)

    - [Nastavení koše v továrním firmwaru AD5X](#nastavení-koše-v-továrním-firmwaru-ad5x)
       - [Přes USB disk v továrním firmwaru](Setup.md#ad5x-warning)

10. [Příkazy IFS](#10-příkazy-ifs)
11. [Obnova firmwaru IFS](#11-obnova-firmwaru-ifs)

### [Pluginy](https://github.com/ghzserg/g28_tenz/blob/main/Plugin_en.md)

- [**bambufy**](https://github.com/function3d/bambufy) - Kompatibilita s Bambu Studio, lepší čistící věže, přesné odhady, snížení odpadu
- [**nopoop**](https://github.com/ghzserg/nopoop) - Maximální snížení odpadu od ninjamida
- [lessWaste](https://github.com/Hrybmo/lessWaste/) - fork bambufy

---

## **1. Klíčové vlastnosti**

Rozdíly oproti AD5M:

*   Žádná podpora `Entware`
*   **Vždy používejte** `FAST_CLOSE_DIALOGS` (rychlé zavírání) místo `CLOSE_DIALOGS` (pomalé zavírání).
*   Makro `NEW_SAVE_CONFIG` **nefunguje**.
*   Pro povolení kamery použijte ```CAMERA_ON VIDEO=video3``` nebo ```CAMERA_ON VIDEO=video0``` nebo ```CAMERA_ON VIDEO=video99```.
*   Klipper může spadnout. Řešení: 'Process Profile' -> 'Other' -> 'Output G-code' -> 'Exclude Models', zrušte zaškrtnutí.

---

## **2. Jak připravit soubor v Orca**

[Odeslat soubory přes "Octo/Klipper" pro tisk](Recomendations.md#send-files-via-octoklipper-for-printing)

**Musíte odstranit nepoužívané cívky ze seznamu v Orce.**

**Příklad:**
Tiskárna má 4 cívky (č. 1, č. 2, č. 3, č. 4). K tisku jsou potřeba pouze cívky č. 1 a č. 3.

*   V souboru budou pojmenovány **T0** (první barva) a **T1** (druhá barva).
*   V menu budete muset vybrat:
    - **T0** → cívka č. 1
      - **T1** → cívka č. 3

---

## **3. Jak používat menu pro výběr barvy (makro `COLOR`)**

<img width="874" height="286" alt="image" src="https://github.com/user-attachments/assets/c0538a17-88a9-4aee-a65c-cff4cc1773d0" />

<img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/b6eb3ddd-ad7d-4cc2-b1b5-9f1aef918b29" />

<img width="563" height="550" alt="image" src="https://github.com/user-attachments/assets/cc0c951f-48c1-469d-8940-90832ad1d3f5" />

<img width="800" height="480" alt="color" src="https://github.com/user-attachments/assets/4145baef-a695-49e6-a914-c12dd3f6b8a4" />

*   `Extruder: 1 (PETG/Orange)` – To znamená, že v tiskárně je aktuálně vložen oranžový PETG filament z cívky č. 1.
*   `IFS: True` – Automatický systém podávání filamentu je aktivní.

**Nyní vyberte cívku, se kterou chcete pracovat (např. cívka 2):**

<img width="568" height="455" alt="image" src="https://github.com/user-attachments/assets/f7ea3ed0-28a5-48d5-99db-eade0a199e99" />

<img width="800" height="480" alt="screenshot" src="https://github.com/user-attachments/assets/c42cbefa-a29c-4df0-a62a-d99842c13961" />

Můžete provést čtyři akce:

1.  **Změnit barvu** cívky.
2.  **Změnit typ materiálu** (např. z PLA na PETG).
3.  **Vložit** tento filament do tiskárny.
4.  **Vysunout** filament z tiskárny.

**Jak změnit barvu:**

1.  Klikněte na „Change Color“.
2.  **Vyberte barvu ze seznamu.** Tím zajistíte, že tiskárna a nativní obrazovka pochopí váš výběr.
<img width="561" height="823" alt="image" src="https://github.com/user-attachments/assets/8dbff228-dfc0-4705-92f9-d94df80b7a4e" />

<img width="800" height="480" alt="screenshot" src="https://github.com/user-attachments/assets/f51f91a2-4131-4ba3-a8a0-3b9519f61f6d" />

3.  Po výběru se vrátíte do menu a barva cívky **by se měla aktualizovat**.
<img width="556" height="545" alt="image" src="https://github.com/user-attachments/assets/f32a9239-44c6-449d-bbf7-5f453f149ef7" />

<img width="800" height="480" alt="screenshot" src="https://github.com/user-attachments/assets/4fa7bb58-ee03-4613-ba06-a5af9b2ddfa6" />

**Pokud se barva nezmění:** Zavřete okno tlačítkem „X“ a restartujte makro `COLOR`. Někdy se obrazovka neobnoví okamžitě.

**Jak změnit typ materiálu:**

1.  Klikněte na „Change Type“.
2.  **Vyberte typ materiálu ze seznamu.**
<img width="562" height="710" alt="image" src="https://github.com/user-attachments/assets/baf7b807-c4f5-4ab4-8bfd-2fc43bb448cd" />

<img width="800" height="480" alt="screenshot" src="https://github.com/user-attachments/assets/2d7b4f12-a8f1-4c99-a555-7c422bd5ffe4" />

**Pokud se typ nezmění:** Zavřete okno tlačítkem „X“ a restartujte makro `COLOR`. Někdy se obrazovka neobnoví okamžitě.

**Tip:** Pokud je více cívkám přiřazena **stejná barva a typ materiálu**, tiskárna se automaticky přepne na další cívku, když současná dojde. Toto se nazývá **„nekonečný režim cívek“**.

---

## **4. Menu tisku (makro `PRINT`)** {#4-menu-tisku-print}

Toto okno se otevře **automaticky** při spuštění tisku.
<img width="567" height="564" alt="image" src="https://github.com/user-attachments/assets/a046c089-22d3-474e-89b6-89815412d068" />

<img width="800" height="480" alt="screenshot" src="https://github.com/user-attachments/assets/f1ad0f49-e2bd-43c8-9301-7c58b9c05c22" />

**Jak interpretovat zobrazení:**

*   `Cube.gcode` – Název tištěného souboru.
*   `T0` – První barva v souboru. Tiskne se pomocí **cívky č. 4** (oranžová PLA).
*   `T1` – Druhá barva. Tiskne se pomocí **cívky č. 3** (černá PLA).
*   `T2` – Třetí barva. Tiskne se pomocí **cívky č. 2** (zelená PLA).
*   `T3` – Čtvrtá barva. Tiskne se také pomocí **cívky č. 2** (zelená PLA).

**Pro změnu cívky pro barvu během tisku:**

*   Jednoduše **klikněte na cílové T** (např. T1) a vyberte jinou cívku ze seznamu.
<img width="553" height="550" alt="image" src="https://github.com/user-attachments/assets/4d831fdb-6ff5-4a0d-ac9e-10154d1c7956" />

<img width="800" height="480" alt="screenshot" src="https://github.com/user-attachments/assets/a87d6115-87e4-4cb1-af3e-b194edefb42b" />

---

### Globální parametry AD5X

Abyste zabránili zobrazení dialogu pro výběr barvy na začátku tisku, použijte globální parametr [SILENT](Global.md#silent):

- 0 – zobrazit dialog (výchozí)
- 1 – nezobrazovat dialog, použít dříve nastavené barvy
- 2 – nezobrazovat dialog, nepoužívat IFS

```gcode
SAVE_ZMOD_DATA SILENT=1
```

Pro zakázání automatického vkládání filamentu do extruderu použijte globální parametr [AUTOINSERT](Global.md#autoinsert):

```gcode
SAVE_ZMOD_DATA AUTOINSERT=0
```

Chcete-li zakázat vypouštění filamentu do koše při tisku, použijte parametr [USE_TRASH_ON_PRINT](Global.md#use_trash_on_print).

```gcode
SAVE_ZMOD_DATA USE_TRASH_ON_PRINT=0
```

Chcete-li po dokončení tisku vysunout filament, použijte parametr [REMOVE_FILAMENT](Global.md#remove_filament).

```gcode
SAVE_ZMOD_DATA REMOVE_FILAMENT=1
```

Chcete-li nastavit, kolik nástrojů se zobrazí v okně pro výběr barvy (pokud soubor nelze pro tuto informaci prohledat), použijte parametr [ALLOWED_TOOL_COUNT](Global.md#allowed_tool_count).

[Viz předzpracování](https://wiki.zmod.link/Recomendations/#enable-md5-checksum-control)

```gcode
SAVE_ZMOD_DATA ALLOWED_TOOL_COUNT=16
```

Chcete-li povolit prohledávání gcode souborů pro informace o nástroji, barvě a materiálu, použijte parametr [SCAN_FILE_COLORS](Global.md#scan_file_colors). Můžete jej také nastavit na 2 pro kontrolu dat připravených skriptem sliceru, ale nepokoušejte se prohledávat celé soubory.

[Viz předzpracování](https://wiki.zmod.link/Recomendations/#enable-md5-checksum-control)

```gcode
SAVE_ZMOD_DATA SCAN_FILE_COLORS=1
```

Chcete-li se pokusit o automatické mapování barev v gcode souboru na fyzické cívky, použijte parametr [AUTO_ASSIGN_COLORS](Global.md#auto_assign_colors). Pro jeho užitečnost musíte povolit prohledávání souborů. Použití hodnoty 30 přeruší tisk v tichém režimu, pokud dojde k jakémukoli problému s automatickým přiřazením.

Můžete vytvořit vlastní hodnoty pro přerušení v tichém režimu sečtením následujících hodnot:

* 2 (Alespoň jeden materiál nelze spárovat; např. gcode soubor specifikuje ABS, ale máte vložený pouze PLA; nebo data o materiálu nelze načíst)
* 4 (Alespoň jednu barvu nelze vůbec spárovat, obvykle kvůli zakázanému nebo neúspěšnému prohledávání souborů)
* 8 (Alespoň jedna barva je potenciálně špatně spárována)
* 16 (Alespoň jedna fyzická cívka byla přiřazena k více než jednomu indexu nástroje v souboru)

[Viz předzpracování](https://wiki.zmod.link/Recomendations/#enable-md5-checksum-control)

```gcode
SAVE_ZMOD_DATA AUTO_ASSIGN_COLORS=30
```

Když je narazen na příkaz ke změně barvy, pokud indikuje přepnutí na již vloženou barvu, obvykle by byl proces změny přeskočen jako zbytečný. Pokud z nějakého důvodu chcete povolit plný proces změny barvy, použijte parametr [ALWAYS_FULL_COLOR_CHANGE](Global.md#always_full_color_change).

```gcode
SAVE_ZMOD_DATA ALWAYS_FULL_COLOR_CHANGE=0
```


---

## **5. Jak ručně sdělit tiskárně, která cívka je vložena**

Někdy ručně změníte cívku, ale tiskárna to nerozpozná a zobrazuje zastaralé informace.

K nápravě použijte specializovaný příkaz.

**Zadejte tuto frázi do konzole:**

```gcode
SET_EXTRUDER_SLOT SLOT=1
```

**Co to znamená:**

*   `SET_EXTRUDER_SLOT` – Příkaz, který říká tiskárně: "Zapamatuj si tuto cívku!"
*   `SLOT=1` – Číslo cívky, kterou jste právě vložili. **Toto číslo můžete změnit!**

**Příklady:**

*   Pokud jste vložili filament z cívky č. 3: `SET_EXTRUDER_SLOT SLOT=3`
*   Pokud z cívky č. 2: `SET_EXTRUDER_SLOT SLOT=2`

Po tomto příkazu bude tiskárna vědět, která cívka je aktivní, a nebude míchat barvy.

---

## **6. Jak konfigurovat odpadní filament při výměně filamentu**

Tato nastavení pomáhají snížit plýtvání plastem při přepínání cívek. Chcete-li je upravit, nejprve **vypněte nativní obrazovku tiskárny** pomocí makra `DISPLAY_OFF`.

V režimu vypnuté obrazovky jsou povoleny tyto senzory:

- `Head Switch Sensor` – Detekuje přítomnost filamentu v extruderu
- `Ifs Motion Sensor` – Sleduje pohyb filamentu v IFS


**Jak najít tato nastavení:**

1.  Otevřete kartu **"Configuration"**.
2.  Přejděte do složky **`mod_data`**.
3.  Otevřete soubor **`filament.json`**.

![Umístění souboru](https://github.com/user-attachments/assets/109b0f0a-c87d-4f5c-9333-ebfbb8065b87)

V tomto souboru má každý typ materiálu (PLA, ABS, PETG atd.) seznam hodnot. Zde je jejich význam:

---

#### **Základní parametry (nejčastěji upravované):**

Aby tato nastavení fungovala, musíte **vypnout nativní displej tiskárny** pomocí makra `DISPLAY_OFF`.

1.  **`temp`** — Teplota trysky pro výměnu filamentu. **Výchozí hodnota závisí na typu materiálu.**
2.  **`filament_drop_length` (Délka čištění)**

    *   **Jednoduše řečeno:** Kolik milimetrů filamentu tiskárna vytlačí do odpadní nádobky, aby **vyčistila trysku** od předchozí barvy.
    *   **Tip:** Zvyšte tuto hodnotu, pokud se barvy míchají při výměně cívek. Snižte ji, abyste snížili odpad.

3.  **`filament_drop_length_add` (Dodatečné čištění)**

    *   **Jednoduše řečeno:** Extra délka čištění při přechodu mezi **typy materiálů** (např. z PLA na PETG), nejen barvami.
    *   **Proč je to potřeba:** Různé materiály se špatně mísí, proto je nutné hlubší čištění trysky.

4.  **`nozzle_cleaning_length`** — Délka (v mm) filamentu vytaženého z extruderu při čištění trysky, když se cívka již nepoužívá. **Výchozí: 60 mm.**

5.  **`filament_unload_into_tube`** — Kolik filamentu vysunout z modulu 4 v 1, když se extrudér již nepoužívá. **Výchozí: 70 mm.**

    *   Pokud máte modul 4 v 1 nové verze, zvyšte `filament_unload_into_tube` nebo v krajním případě zvyšte `nozzle_cleaning_length`

---

##### **Pokročilé parametry (neupravujte, pokud si nejste jisti výsledkem):**

Aby tato nastavení fungovala, musíte **vypnout nativní displej tiskárny** pomocí makra `DISPLAY_OFF`.

*   **`filament_tube_length`** — Celková délka PTFE hadičky od modulu IFS k extruderu. Užitečné pro nestandardní hadičky. **Výchozí: 1000 mm.**
*   **`filament_unload_before_cutting`** — Vzdálenost zvednutí filamentu **před** řezáním. **Výchozí: 0 mm.**
*   **`filament_unload_after_cutting`** — Vzdálenost zvednutí filamentu **po** řezání, před přesunem do odpadní nádobky. **Výchozí: 5 mm.**
*   **`filament_unload_after_drop`** — Vzdálenost retrakce po čištění, aby se zabránilo odkapávání. **Výchozí: 3 mm.**
*   **`filament_extruder_speed`** — Rychlost (v mm/min), kterou je filament zaváděn do extrudéru. **Výchozí: 300 mm/min (5 mm/s).**
*   **`filament_ifs_speed`** — Rychlost (v mm/min), kterou pracuje modul IFS. **Výchozí: 12000 mm/min (20 mm/s).**
*   **`filament_fan_speed`** — Rychlost ventilátoru (0–255) během čištění pro chlazení odkapávání. **Výchozí: 102.**
*   **`filament_autoinsert_empty_length`** — Délka filamentu taženého při automatickém vkládání do prázdného extruderu. **Výchozí: 600 mm.**
*   **`filament_autoinsert_full_length`** — Délka filamentu taženého při výměně stávajícího filamentu. **Výchozí: 550 mm.**
*   **`filament_autoinsert_ret_length`** — Vzdálenost retrakce po spuštění senzoru extruderu (pouze prázdný extruder). **Výchozí: 90 mm.**
*   **`filament_autoinsert_speed`** — Rychlost automatického vkládání (mm/min). **Výchozí: 1200 mm/min (20 mm/s).**

**Varování!** Úprava pokročilých parametrů může způsobit poruchy tiskárny, ucpání filamentu nebo poškození hardwaru. Upravujte pouze tehdy, pokud plně rozumíte účelu a potenciálním následkům každého parametru.

**Klíčový poznatek:** Chcete-li snížit odpad, začněte snížením **`filament_drop_length`** a **`filament_drop_length_add`** pro váš materiál. Nezapomeňte po změnách soubor uložit!

## **7. Přidat vlastní typy filamentů**

Aby tato nastavení fungovala, musíte **vypnout nativní displej tiskárny** pomocí makra `DISPLAY_OFF`.

Chcete-li přidat nový typ filamentu, přidejte následující do ```mod_data/user.cfg```:
```
[zmod_ifs]
filament_NEWTYPE: 300
```
Kde NEWTYPE je nahrazen požadovaným typem filamentu (např. HIPS) a číslo je teplota tání tohoto filamentu.

```IFS_PRINT_DEFAULTS``` - zobrazí dostupné typy filamentů a jejich teploty tání

---

## **8. Přidat vlastní barvy**

Aby tato nastavení fungovala, musíte **vypnout nativní displej tiskárny** pomocí makra `DISPLAY_OFF`.

Chcete-li přidat nebo přejmenovat barvu, otevřete ```mod_data/colors/cs.cfg``` (místo cs použijte svůj jazyk):

Přidejte novou barvu nebo přejmenujte stávající.

Aby se název barvy zobrazil, musí název barvy začínat podtržítkem ```_```

Příklad:
```
{
"ffffff": "bílá",
"fffff1": "_průhledná",
"fef043": "jasně žlutá",
"dcf478": "světle zelená",
"0acc38": "zelená",
"067749": "tmavě zelená",
"0c6283": "modrozelená",
"0de2a0": "tyrkysová",
"75d9f3": "azurová",
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

Text ```_průhledná``` se zobrazí na tlačítkách.

---

## 9. Oprava funkce odpadní nádobky a nože na řezání filamentu

[Alternativní verze pokynů](Setup.md#ad5x-warning)

Různé tiskárny AD5X mohou mít různé souřadnice pro odpadní nádobku a nůž. Někdy může být rozdíl až 4 mm.

Kvůli tomu:

- Filament nemusí dosáhnout do odpadní nádobky;
- Nůž neřeže filament;
- Hlava tiskárny může narazit do zdi.

K nápravě je třeba:

1. Aktualizovat zMod.
2. Otevřít soubor `/rw/Adventurer5M.json`.
3. Najít tyto řádky:
```json
{
        "CutXOffset" : 0.5,
        "CutYOffset" : -0.20000001788139343,
        "xOffset" : 0.0,
        "yOffset" : -0.20000001788139343,
        "zOffset" : 0.0,
        "zProbeOffset" : 0.004999995231628418
},
```
<img width="504" height="241" alt="image" src="https://github.com/user-attachments/assets/8647b1fe-594c-4bb3-91ee-560cfe4a58fd  " />

Nahraďte **pouze** tyto hodnoty:
```json
"CutXOffset": 0.0,
"CutYOffset": 0.0,
"yOffset": 0.0,
```

4. Zadat příkaz: `UPDATE_FF_OFFSET` (tím se aktualizují nastavení).
5. Poté zadat: `_GOTO_TRASH` (tím se přesune k odpadní nádobce).

---

### Kalibrace odpadní nádobky

[Alternativní verze pokynů](Setup.md#ad5x-warning)

1. Zadejte příkaz `_GOTO_TRASH` — hlava tiskárny se přesune k odpadní nádobce.
2. Pokud se nádobka nezavře. Opatrně posouvejte hlavu, dokud se nádobka nezavře. Musíte použít GCODE: ```G1 Y230.2```
3. Zkontrolujte, jakou máte nyní souřadnici **Y**.
4. Odečtěte od tohoto čísla 229. Výsledek bude váš `yOffset`.

Příklady:

- Pokud Y = 230.2, pak `yOffset = 230.2 - 229 = 1.2`
- Pokud Y = 228.4, pak `yOffset = 228.4 - 229 = -0.6`
- Vzorec: `yOffset = Y - 229`

Zapište toto číslo do souboru `/rw/Adventurer5M.json`. Nádobka je zkalibrována.

5. Zadejte příkaz: `UPDATE_FF_OFFSET` (tím se aktualizují nastavení).
6. Poté zadejte: `_GOTO_TRASH` (tím se přesune k odpadní nádobce).

---

### Kalibrace nože

[Alternativní verze pokynů](Setup.md#ad5x-warning)

1. Zadejte příkaz `_CUT_PRUTOK` — hlava se přesune k noži.
2. Musíte použít GCODE: ```G1 Y-7.7``` ```G1 X-1.7```, posouvejte hlavu, dokud se nůž neaktivuje.
3. Zkontrolujte, jaké máte souřadnice X a Y.
4. Pro **Y**:

    - Odečtěte vaši souřadnici Y od **7.5** v absolutní hodnotě.
       - Příklad: pokud Y = -7.7, pak `CutYOffset = 7.5 - 7.7 = -0.2`
       - Příklad: pokud Y = -5.9, pak `CutYOffset = 7.5 - 5.9 = 1.6`
       - Vzorec: `CutYOffset = 7.5 + Y`

5. Pro **X**:

    - Odečtěte vaši souřadnici X od **2.5** v absolutní hodnotě.
       - Příklad: pokud X = -1.7, pak `CutXOffset = 2.5 - 1.7 = 0.8`
       - Příklad: pokud X = -2.8, pak `CutXOffset = 2.5 - 2.8 = -0.3`
       - Vzorec: `CutXOffset = 2.5 + X`

Zapište tato čísla do souboru `/rw/Adventurer5M.json`. Nůž je zkalibrován.

6. Zadejte příkaz: `UPDATE_FF_OFFSET` (tím se aktualizují nastavení).
7. Poté zadejte: `_GOTO_TRASH` (tím se přesune k odpadní nádobce).

Restartujte tiskárnu — vše je připraveno.

---

## Nastavení koše v továrním firmwaru AD5X

1. Přejděte na kartu „i“ a stiskněte tlačítko `Status`
   
   <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/08a99d33-c970-4e86-933d-0064b447f5b7" />
   
2. Přejděte na 6. kartu
   
   <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/a0eb4b8f-552b-4e58-86d7-2b47b8b0035c" />
   
3. Stiskněte a podržte `Move the extruder to waste tray position` po dobu 20 sekund
   <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/81213d65-bf06-4d33-8e4a-eb3aae2782d7" />
   
4. Upravte polohu hlavy v odpadní nádobce tak, aby se zavřela. Pomocí ovládacích šipek zaparkujte tiskovou hlavu u přijímače tak, aby tisková hlava dostatečně stlačila páčku závěrky, tryska byla za pohyblivou závěrkou a samotná závěrka byla v jedné rovině s přední plochou přijímače.
   
   <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/7b506200-0d61-4b88-aaf8-40475e3ad463" />
   
   Stiskněte tlačítko `Set`.
   
5. Stiskněte a podržte `Move the extruder to cutter striker position` po dobu 20 sekund
   <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/e61c61c0-f1a1-4535-b9ef-37baa4ab1d8c" />
   
6. Upravte nůž. Stiskněte `CutX` — nůž by měl řezat filament bez prokluzování nebo nárazů.
   
   <img width="800" height="480" alt="image" src="https://github.com/user-attachments/assets/a0c1939e-dada-48cb-8789-df43999bf99b" />
   
   Stiskněte tlačítko `Set`.

---

## **10. Příkazy IFS**

Aby tato nastavení fungovala, musíte **vypnout nativní displej tiskárny** pomocí makra `DISPLAY_OFF`.

- `IFS_F10` - Vložit filament
- `IFS_F11` - Odebrat filament
- `IFS_F13` - Stav IFS
- `IFS_F15` - Resetovat ovladač
- `F18` - Čištění filamentu všude
- `F23` - Označit filament jako vložený
- `F24` - Svorka filamentu
- `F39` - Čištění filamentu
- `F112` - Zastavit podávání filamentu
- `PURGE_PRUTOK_IFS` - Čištění filamentu z IFS do extruderu
- `REMOVE_PRUTOK_IFS` - Odebere filament podle čísla filamentu
- `INSERT_PRUTOK_IFS` - Vloží filament do IFS podle čísla filamentu
- `SET_CURRENT_PRUTOK` - Sdělí klipperu, který filament je aktuálně aktivní
- `ANALOG_PRUTOK` - Načíst analogovou tyč
- `IFS_MOTION` - Zkontrolovat, zda se filament zastavil nebo došel

Parametry modulu IFS:

- debug - ladění (True, *False*)
- silk_count - počet pokusů o načtení tyče do IFS (*1*)
- stall_count - počet pokusů o započítání tyče jako zastavené (*1*)
- retry_count - počet opakování příkazu při chybě (*3*)
- filament_NEWFILEMENT - Přidat nový typ filamentu. Parametr - teplota výměny pro tento typ plastu.

Nastavte přes `mod_data/user.cfg`:
```
[zmod_ifs]
debug: True
silk_count: 1
stall_count: 1
filament_NEWTYPE: 300
```

## **11. Obnova firmwaru IFS**

K obnově firmwaru IFS potřebujete programátor **ARM J-LINK V9**.

<img width="800" height="800" alt="image" src="https://github.com/user-attachments/assets/ae91768b-00d8-4e36-a62d-3056a7e117bf" />

<img width="960" height="479" alt="image" src="https://github.com/user-attachments/assets/f623fa41-4bc3-40a4-a434-5d8ad717792b" />

Připájejte dráty k desce iFS.

<img width="579" height="774" alt="image" src="https://github.com/user-attachments/assets/cb2b2f72-9eba-4831-8cea-072813b6e0e3" />

Připojte:

- CLK k SWCK
- DIO k SWIO
- VCC k 3.3
- GND k GND

<img width="346" height="390" src="https://github.com/user-attachments/assets/19438d58-9879-48e5-8acc-bfb21ce4549c" />

- Cílové zařízení - `Nations N32G455RE`
- Cílové rozhraní: `SWD`
- Rychlost: `4000`
- Zaškrtněte první políčko.
- Zrušte zaškrtnutí druhého políčka.

1. Připojte.
2. Vyberte [soubor firmwaru](Native_FW.md#5x-ifs). **Nezapomeňte jej rozbalit**.
3. Stiskněte **F7** a počkejte, až se zařízení nahraje.

## IFS: chyba senzoru: Chyba sériové komunikace: čtení se nezdařilo: zařízení hlásí připravenost ke čtení, ale nevrátilo žádná data (zařízení odpojeno nebo vícenásobný přístup na port?)

Tato chyba nastává, když nativní displej a mod přistupují k IFS současně.

Nejlepší je zkrátit životnost nativního displeje na 10 sekund: ```SAVE_ZMOD_DATA DISPLAY_OFF_TIMEOUT=10```