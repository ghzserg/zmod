# Pluginy v zModu

Každý uživatel může vytvořit a připojit svůj vlastní plugin do **zmod**.

Pluginy obsažené v zMod:

1. [Recommend](https://github.com/ghzserg/recommend) - Doporučená nastavení k okamžitému použití po instalaci modu.
2. [G28_tenz](https://github.com/ghzserg/g28_tenz) – Parkování osy Z pomocí tenzometrů.
3. [Nopoop](https://github.com/ghzserg/nopoop) - Maximální snížení odpadu od ninjamida.
4. [TimeLapse](https://github.com/ghzserg/timelapse) - Moonraker Timelapse.
5. [Notify](https://github.com/ghzserg/notify) - Přijímání oznámení v Telegramu a více než 100 dalších službách.

Externí pluginy, které nevyvíjí autor zMod.

1. [Bambufy](https://github.com/function3d/bambufy/blob/master/README_ru.md) - Kompatibilní s Bambu Studio, vylepšuje správu čisticí věže, poskytuje přesné odhady doby tisku a spotřeby materiálu, snižuje odpad, podporuje Mainsail, rychlé změny barev a pokročilé tiskařské funkce. NELZE POUŽÍT S NATIVNÍ OBRAZOVKOU.
2. [lessWaste](https://github.com/Hrybmo/lessWaste/blob/master/README_ru.md) - fork pluginu BamBufy.

Chcete-li povolit repozitář externích pluginů, které nevyvíjí autor zMod, spusťte příkaz `ENABLE_EXTRA_PLUGINS`.

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
ln -s /opt/config/mod_data/plugins/klipper-led_effect/src/led_effect.py /usr/prog/klipper/klippy/extras/led_effect.py
```

Nahraďte:

- `klipper-led_effect` názvem složky vašeho pluginu
- `led_effect.py` názvem modulu (může se lišit v závislosti na pluginu)

**Krok 4: Restartujte Klipper**

Po vytvoření symbolického odkazu musíte restartovat Klipper pomocí tlačítka pro restart v webovém rozhraní Fluidd/Mainsail.

### Důležité poznámky

> **Modul musí být kompatibilní s vaší verzí Klipperu**
> Ujistěte se, že verze pluginu je kompatibilní s vaší nainstalovanou verzí Klipperu.

---
## Vytvoření vlastního pluginu

Příklad pluginu: https://github.com/ghzserg/g28_tenz
(Ve všech níže uvedených příkladech se používá název `g28_tenz` — nahraďte jej názvem vašeho pluginu.)

---

### Přidání pluginu

V souboru
```mod_data/user.moonraker.conf```
přidejte následující sekci:

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

> Stabilní pluginy mohou být zahrnuty v distribuci zMod, ale jsou aktualizovány a udržovány jejich příslušnými autory.

---

### Instalační skript

Po volání `ENABLE_PLUGIN` se automaticky spustí soubor `install.sh`.
Po volání `DISABLE_PLUGIN` se automaticky spustí soubor `uninstall.sh`.

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
