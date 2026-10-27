# Jak kontaktovat vývojáře

Otevřete Telegram bot [@zmod_help_bot](http://t.me/zmod_help_bot) a položte mu svou otázku. Zná celou dokumentaci.

1. [Aktualizujte Z-Mod a všechny pluginy na nejnovější verzi](Setup.md#aktualizace-modu)
2. Jasně popište problém: uveďte snímky obrazovky, fotografie a podrobné textové vysvětlení.
3. Spusťte [CLEAR_EMMC](System.md#clear_emmc) pro vyčištění předchozích protokolů.
4. **Zcela vypněte tiskárnu.**
5. Znovu zapněte tiskárnu.
6. Reprodukujte problém.
7. Spusťte [TAR_CONFIG](Zmod.md#tar_config) pro sběr souborů protokolů.
8. Odešlete **jeden** příspěvek s vaším popisem a generovaným souborem `config-1.6.6-28.tar.gz`, kde 1.6.6-28 je aktuální verze modu.
9. [Založte hlášení zde](https://github.com/ghzserg/zmod/issues).

Pokud nelze provést `TAR_CONFIG`:

- Stáhněte si [log](/cs/Native_FW/#log)
- Zkopírujte z USB flash disku `config-1.6.6-28.tar.gz`, kde 1.6.6-28 je aktuální verze modu

Nebo se připojte k tiskárně přes SSH:

AD5M/AD5M Pro:

```
chroot /data/.mod/.zmod/
/usr/data/zmod/zmod/.shell/tar_config.sh
```

AD5X/C5/C5Pro:

```
chroot /usr/data/.mod/.zmod/
/usr/data/zmod/zmod/.shell/tar_config.sh
```

**[Vytvořit tiket](https://github.com/ghzserg/zmod/issues)**

## Proč vás žádám o tikety — jednoduše vysvětleno

Představte si, že vaše tiskárna je auto.

A já jsem automechanik v obrovské dílně, kde každý den opravuji *stovky* různých vozů.

Přijedete a křičíte:

> **„Moje auto nejede!“**

A musím začít se základní otázkou:

> **„Dobře — jaká je značka, model a ročník vašeho auta?“**

### Proč je důležité to rozebrat

Naši „flotilu“ tvoří **přes 100 jedinečných konfigurací**. Jen podle hlavních kategorií:

- **5 různých modelů tiskáren**:

  FF5M, FF5M Pro, AD5X, C5, C5Pro

- **3 verze „motoru“ (Klipperu)**:

  11, 12, 13

- **2 architektury CPU**:

  ARM a MIPS

- **Možnosti obrazovky („interiér“)**:

    - Nativní obrazovka
    - GuppyScreen
    - HelixScreen
    - Bez obrazovky (headless)

- **Primární uživatelská rozhraní**:

  Fluidd a Mainsail

- **Metody zahájení tisku**:

  Přes nativní obrazovku, GuppyScreen, HelixScreen, OrcaSlicer (protokol FF, protokol Klipper atd.)

- **Volitelné „doplňky“ (pluginy)**:

  `nopoop`, `recommend`, `bambufy`, `g28_tenz`, `timelapse`, `notify` a další

- **Senzory a periferní zařízení**:

  přítomnost filamentu, pohyb filamentu, IFS atd.

Navíc někteří uživatelé **sami upravují hardware**, instalují zastaralý firmware nebo se řídí radami z fór či od modelů AI, které **nikdy neviděly jejich konkrétní tiskárnu**.

### Výsledek

Když napíšete jen **„nefunguje“**, strávím **hodiny** zjišťováním:

- Který model máte

- Kterou verzi Klipperu/firmware

- Zda používáte obrazovku (a kterou)

- Který slicer, nastavení a pluginy jsou aktivní

To je **neefektivní**, **zpomaluje pomoc** a **frustruje všechny**.

---

## ✅ Jak „přivézt auto do servisu“ — Kontrolní seznam pro hlášení

Abyste mi pomohli **přeskočit hádání a začít opravovat**, postupujte prosím podle tohoto kontrolního seznamu:

### 1. **Aktualizujte na nejnovější verzi**
> Postupujte podle [oficiálního průvodce aktualizací](Setup.md#aktualizace-modu).

### 2. **Popište problém jasně a konkrétně**
> ❌ Špatně: _„Nefunguje to.“_

> ✅ Dobře:

> _„Po aktualizaci Z-Mod na v.X.Y.Z při spuštění tisku z nativní obrazovky:

> — podložka se nahřeje,

> — extruder se NENAHŘEJE (obrazovka ukazuje 0 °C),

> — tisk se přeruší po ~2 minutách.“_

> 🔹 Připojte **snímky obrazovky**, **fotografie**,

> 🔹 Popište **přesné kroky vedoucí k problému**,

> 🔹 Připojte **soubor G-code** (problém může být v samotném souboru!).

### 3. **Spusťte úplnou diagnostiku**
> Postupujte **přesně v tomto pořadí**:
> 1. `CLEAR_EMMC` — vyčistit staré logy

> 2. **Odpojte tiskárnu od sítě** → Počkejte 10 sekund

> 3. Znovu tiskárnu zapněte

> 4. **Reprodukujte problém** (spusťte tisk, stiskněte tlačítko — vyvolejte chybu)

> 5. Spusťte `TAR_CONFIG` — vygeneruje `config.tar.gz` obsahující všechny logy

### 4. **Odešlete hlášení správně**
> - Přejděte na [stránku Issues](https://github.com/ghzserg/zmod/issues)

> - Vytvořte **jedno** nové hlášení

> - Zahrňte:

>   - Váš jasný popis (krok 2 výše)

>   - **Připojte `config.tar.gz`**
>   - Připojte **soubor G-code**, pokud je to relevantní

> ⚠️ Bez `config.tar.gz` je diagnostika nemožná — je to jako poslat krevní testy… *bez krve*.

---

## Čeho tím dosáhnete

Přestanete křičet:

> **„Moje auto nejede!“**

A místo toho přivezete:

> 🚗 **Vaše přesné vozidlo**,

> 📋 **Úplnou servisní historii**,

> 📊 **Diagnostické zprávy**.

Pak mohu začít **opravovat — okamžitě, ne spekulovat**.

---

Děkuji za pochopení a respekt k času ostatních.

Toto není byrokracie — je to **jediný způsob**, jak udělat podporu **rychlou a efektivní**.

**[Vytvořit tiket](https://github.com/ghzserg/zmod/issues)**
