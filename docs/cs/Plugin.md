# Pluginy v Z-Modu

Každý uživatel může vytvořit a připojit svůj vlastní plugin do **Z-Mod**.

Pluginy obsažené v Z-Mod:

1. [Recommend](https://github.com/ghzserg/recommend) - Nastavení doporučená ihned po instalaci modu.
2. [G28_tenz](https://github.com/ghzserg/g28_tenz) – Parkování osy Z pomocí tenzometrů.
3. [Nopoop](https://github.com/ghzserg/nopoop) - Maximální snížení odpadu od ninjamida.
4. [TimeLapse](https://github.com/ghzserg/timelapse) - Moonraker Timelapse.
5. [Notify](https://github.com/ghzserg/notify) - Oznámení v Telegramu a ve více než 100 dalších službách.

Externí pluginy, které nevyvíjí autor Z-Mod:

1. [Bambufy](https://github.com/function3d/bambufy/blob/master/README_ru.md) - Kompatibilní s Bambu Studio, vylepšuje správu čisticí věže, poskytuje přesné odhady doby tisku a spotřeby materiálu, snižuje odpad, podporuje Mainsail, rychlé změny barev a pokročilé tiskařské funkce. NELZE POUŽÍT S NATIVNÍ OBRAZOVKOU.
2. [lessWaste](https://github.com/Hrybmo/lessWaste/blob/master/README_ru.md) - fork pluginu Bambufy.
3. [Dryer](https://github.com/pantata/dryer) - Sušení filamentu pomocí vyhřívané podložky
4. [IFS Jacker](https://github.com/ninjamida/ifs_jacker_plugin) – Doplněk pro podporu [hardwarového modu IFS Jacker](https://github.com/ninjamida/ifs-jacker), který umožňuje automatickou detekci počtu dostupných kanálů a integraci ventilátorů, LED a senzorů připojených přes IFS Jacker do Klipperu.
5. [HelixScreen](https://github.com/prestonbrown/helixscreen) – alternativní implementace obrazovky
6. [QuickSwap](https://github.com/ninjamida/quickswap-5x) - Plugin pro rychlejší změnu barev na AD5X
7. [Flook32](https://github.com/ghzserg/flook32_plugin) - Plugin pro připojení sušičky [Flook32](https://github.com/schreider/flook32) [En](https://github.com/ghzserg/flook32)
8. [Print Handy](https://github.com/catduckgnaf/print-handy) - Vypíše ostatní sloty IFS na AD5X se stejnou barvou a materiálem. Filament nepřepíná.
9. [Zmod AFC Lite](https://github.com/DIEHARDave/zmod_afclite) - Zobrazuje sloty IFS na AD5X nebo tiskové hlavy Creator 5 jako linky AFC v panelech AFC v Mainsail a Fluidd, včetně zavádění/vysouvání, barvy, materiálu a cívek Spoolman.

Chcete-li povolit repozitář externích pluginů, spusťte příkaz `PLUGINS`.

---

## Správa pluginů

**Povolit plugin:**
```gcode
ENABLE_PLUGIN name=g28_tenz
```
— stáhne plugin a v případě úspěchu restartuje Klipper.

**Zakázat plugin:**
```gcode
DISABLE_PLUGIN name=g28_tenz
```

---

## PLUGINS

Zobrazí nabídku správy pluginů.

<img width="849" height="838" alt="{9D0BE78C-816B-4F22-B3F1-8FC678AD8977}" src="../../images/a23b06e2-abe3-4ff0-93c7-079d2d057e1b.png" />

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
## Instalace klasických pluginů Klipperu s moduly Pythonu

Pro klasické pluginy Klipperu, které pracují s moduly Pythonu (např. [klipper-led_effect](https://github.com/julianschill/klipper-led_effect)), je vyžadován speciální instalační proces, který zahrnuje vytvoření symbolického odkazu na modul Klipperu.

### Příklad: Instalace led_effect

`led_effect` je plugin pro ovládání RGB LED pásků WS2812 přes Klipper.

**Krok 1: Klonujte repozitář**

Spusťte tyto příkazy v prostředí chroot:

```bash
# Pro AD5M:
chroot /data/.mod/.zmod/
# Pro AD5X:
chroot /usr/data/.mod/.zmod/

# Společné pro všechny modely:
cd /opt/config/mod_data/plugins/
git clone https://github.com/julianschill/klipper-led_effect.git
```

**Krok 2: Přidejte záznam do konfigurace Moonrakeru**

Do souboru `mod_data/user.moonraker.conf` přidejte následující sekci:

```ini
[update_manager led_effect]
type: git_repo
channel: stable
path: /opt/config/mod_data/plugins/klipper-led_effect
origin: https://github.com/julianschill/klipper-led_effect.git
is_system_service: False
primary_branch: master
```

**Krok 3: Vytvořte symbolický odkaz na modul Klipperu**

Vytvořte symbolický odkaz pro připojení modulu ke Klipperu:

```bash
exit
# Native Klipper
ln -s /opt/config/mod_data/plugins/klipper-led_effect/src/led_effect.py /usr/prog/klipper/klippy/extras/led_effect.py
# Klipper 13
ln -s /opt/config/mod_data/plugins/klipper-led_effect/src/led_effect.py /usr/data/zmod/klipper/klippy/extras/led_effect.py
```

Nahraďte:

- `klipper-led_effect` názvem složky vašeho pluginu
- `led_effect.py` názvem modulu (může se lišit v závislosti na pluginu)

**Krok 4: Restartujte Klipper**

Po vytvoření symbolického odkazu musíte restartovat Klipper pomocí tlačítka pro restart ve webovém rozhraní Fluidd/Mainsail.

### Důležité poznámky

> **Modul musí být kompatibilní s vaší verzí Klipperu**
> Ujistěte se, že verze pluginu je kompatibilní s vaší nainstalovanou verzí Klipperu.

---
## Vytvoření vlastního pluginu

Příklad pluginu: https://github.com/ghzserg/g28_tenz
(Ve všech níže uvedených příkladech se používá název `g28_tenz` — nahraďte jej názvem vašeho pluginu.)

---

### Přidání pluginu

Do souboru `mod_data/user.moonraker.conf` přidejte následující sekci:

```ini
[update_manager g28_tenz]
type: git_repo
channel: dev
path: /root/printer_data/config/mod_data/plugins/g28_tenz
origin: https://github.com/ghzserg/g28_tenz.git
is_system_service: False
primary_branch: main
```

- **Cesta k pluginu**: `/root/printer_data/config/mod_data/plugins/g28_tenz`
- **Zdroj**: `https://github.com/ghzserg/g28_tenz.git`

> Stabilní pluginy mohou být zahrnuty v distribuci Z-Mod, ale jsou aktualizovány a udržovány jejich příslušnými autory.

---

### Instalační skript

Po volání `ENABLE_PLUGIN` se automaticky spustí soubor `install.sh`.
Po volání `DISABLE_PLUGIN` se automaticky spustí soubor `uninstall.sh`.

### Skript aktualizace

Když správce aktualizací aktualizuje plugin, soubor `update.sh` se automaticky spustí, pokud existuje.

### Plugin s jedním jazykem
Musí obsahovat soubor:
```
g28_tenz.cfg
```
Veškerá funkčnost je uvnitř tohoto souboru.

### Plugin s více jazyky
Soubory jsou umístěny v podadresářích specifických pro daný jazyk:
```
en/g28_tenz.cfg
ru/g28_tenz.cfg
de/g28_tenz.cfg
...
```

Všechny výstupní řetězce musí být escapovány, například:
```gcode
RESPOND PREFIX="info" MSG="===Řežu filament==="
```

---

#### Překlad

Překlady jsou uloženy v adresáři `translate/` v souborech jako `de.csv`:

```csv
Cutting the filament;Filament schneiden
```

Formát:
```
Anglická fráze;Překlad do cílového jazyka
```

Pro vygenerování jazykových souborů spusťte:
```bash
./Make.sh
```
Skript vytvoří požadované adresáře a `.cfg` soubory.
