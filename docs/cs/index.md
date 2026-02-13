---
hide:
  - navigation
---

# FF5M / FF5M Pro / AD5X ZMOD

<img width="698" height="291" alt="zmod logo" src="https://github.com/user-attachments/assets/5e26413b-c9a2-49f2-b9b8-5ecde709c521" />

[zMod LINK je k dispozici na tomto odkazu ->](https://zmod.link/link/)

### **ZMOD pro FlashForge AD5M/PRO/AD5X: Plná kontrola nad vaší tiskárnou**

Gratulujeme k nákupu tiskárny FlashForge! Tovární firmware je skvělý pro začátek, ale pokud chcete odemknout plný potenciál vašeho zařízení, ZMOD je výkonné a bezplatné řešení, které promění vaši tiskárnu z „uživatelsky přívětivé“ na „profesionální úroveň“.

### Co je ZMOD?
ZMOD je vlastní modifikace firmwaru instalovaná *na* tovární software. **Nenahrazuje** původní firmware — místo toho ho rozšiřuje a přidává obrovské množství funkcí známých z pokročilých tiskáren, přičemž zachovává výhody a snadnost použití nativního rozhraní.

### Klíčové výhody ZMOD oproti továrnímu firmwaru
Zde je, co získáte instalací ZMOD:

#### 1. Plná vzdálená kontrola
**Tovární firmware**: Můžete posílat soubory přes Wi-Fi, ale pouze přes Orca FF nebo aplikaci FlashForge (obojí může být nedostupné kvůli problémům se servery).
**ZMOD**: Kompletní ovládání přes prohlížeč z vašeho PC nebo telefonu:

- **Fluidd / Mainsail**: Intuitivní webová rozhraní zobrazující živé statistiky tisku, teploty, ovládání rychlosti ventilátoru, pohyb os a plný přístup ke konzoli.
- **Nahrávání souborů ve stylu Octo/Klipper**: Bezproblémová integrace s Orca Slicer a dalšími slicery pro přímý přenos G-code souborů.
- **Přístup k webovému rozhraní tiskárny přes internet** pomocí cloudové služby [zmod.link](https://zmod.link)
- **Oznámení v Telegramu a více než 100 dalších službách** [plugin notify](https://github.com/ghzserg/notify/)

#### 2. Pokročilá kalibrace a vyrovnávání podložky
**Tovární firmware**: Základní automatické vyrovnávání podložky (ABL).
**ZMOD**:

- **Adaptivní síť (KAMP)**: Tiskárna generuje mapu sítě pouze nad oblastí, kde se nachází váš model — šetří čas a zlepšuje přesnost.
- **Ladění PID**: Přesná kalibrace tepelného chování extruderu a podložky pro stabilní teploty bez kmitání.
- **Input Shaping**: Analyzuje a kompenzuje vibrace rámu, což umožňuje rychlejší tisk bez artefaktů „zvonění“.
- **Spektrogram řemenů**: Diagnostikuje stav řemenů pro prediktivní údržbu.
- **Nastavení sklonu šroubů**: Plně vyrovnejte podložku za méně než 10 minut.

#### 3. Inteligentní funkce spolehlivosti
**Tovární firmware**: Základní detekce docházejícího filamentu. Žádné kontroly integrity firmwaru nebo souborů → možné zaseknutí tisku.
**ZMOD**:

- **Detekce kolize trysky**: Používá tenzometry k detekci kolizí trysky s tiskem nebo podložkou — a automaticky pozastaví tisk, aby se předešlo poškození.
- **Obnovení po ztrátě napájení**: Pamatuje si poslední pozici tisku a pokračuje po obnovení napájení.
- **Kontrola integrity firmwaru**: Ověřuje jak tovární firmware, tak soubory ZMOD, aby se předešlo poškození.
- **Kontrola integrity G-code souborů**: Ověřuje MD5 kontrolní součty během přenosu souborů.

#### 4. Flexibilní manipulace s filamentem (zejména pro AD5X)
**Tovární firmware**: Standardní výběr cívky přes menu UI.
**ZMOD (pro AD5X)**:

- **Chytré menu COLOR**: Vizuálně vybírejte cívky, změny barev a typy materiálů přímo z webového UI.
- **Režim nekonečné cívky**: Pokud více cívek používá stejný materiál, tiskárna se automaticky přepne na další, jakmile aktuální dojde.
- **Jemně laděné ovládání čištění**: Snižte objem čisticího filamentu během změn barev, čímž šetříte materiál.

#### 5. Ekosystém a integrace
**Tovární firmware**: Uzavřený systém.
**ZMOD**:

- **Telegram Bot**: Získávejte oznámení v reálném čase a snímky z kamery v Telegramu při zahájení/dokončení tisku.
- **Podpora pluginů**: Rozšiřte funkčnost pomocí modulů (např. `bambufy` pro lepší kompatibilitu s Bambu Studio).
- **Alternativní nastavení kamery**: Nastavitelné rozlišení, FPS a optimalizace paměti pro stabilní streamování.
- **Přehrávání melodií**: Přehrává vlastní melodie při zahájení nebo dokončení tisku.

#### 6. Optimalizace a nízkoúrovňové ovládání
**Tovární firmware**: Omezená konfigurovatelnost.
**ZMOD**:

- **Vypnutí továrního LCD**: Uvolňuje RAM (kritické na AD5M s pouze 128 MB).
- **GuppyScreen**: Vylepšené náhradní UI pro displej tiskárny.
- **Prohlížení logů**: Plné systémové logy pro diagnostiku.
- **Firmwarová retrakce**: Upravujte parametry retrakce za chodu, není třeba znovu slicovat.
- **Plný ROOT přístup**: Vždy je k dispozici plná kontrola nad systémem.

#### 7. Klipper 13
**Tovární firmware**: AD5M běží na zastaralém Klipperu v11, který je plný chyb (E0011, E0017, nesprávné vyloučení objektů, porušené SCV, chybné obnovení atd.).
**ZMOD**:

- Opravuje známé chyby Klipperu a umožňuje moderní, stabilní verzi.

---

### Shrnutí: Pro koho je ZMOD určen?

| Pokud jste… | ZMOD vám poskytne… |
|-------------|-----------------|
| **Začátečník** | Snadné dálkové ovládání a automatizované kalibrace pro spolehlivou kvalitu na první pokus. |
| **Nadšenec** | Plnou kontrolu nad každým parametrem tisku, pokročilé nástroje pro ladění a experimentování s rychlostí. |
| **Majitel AD5X** | Nejpohodlnější pracovní postup pro vícebarevný tisk a snížení plýtvání filamentem. |

ZMOD *nenahrazuje* tovární firmware — vylepšuje ho a dává vám na **výběr**: zůstat u známého dotykového UI, nebo využít moderní nástroje pro 3D tisk a získat z vaší FlashForge absolutní maximum. Je to logický další krok pro každého majitele FlashForge, který chce maximalizovat schopnosti své tiskárny.

!!! Pozor
    *Pokud chcete nainstalovat tento mod na svůj AD5M (Pro) / [AD5X](AD5X.md), mějte na paměti, že riskujete ztrátu záruky nebo poškození tiskárny. Pokud chcete tento mod vyzkoušet, postupujte na vlastní nebezpečí!*
    
    Pokud nevíte, co to je, nerozumíte, proč je potřeba webové rozhraní Klipper, nebo jste prostě spokojeni s továrním firmwarem, NENAINSTALUJTE tuto modifikaci. Pro všechny ostatní – **prosím, pečlivě si přečtěte celé pokyny!**
    
    Po instalaci modu, pokud se nechcete zabývat detaily – prostě tiskněte jako obvykle. Nejsou vyžadovány žádné další konfigurace ani změny. Pokud se rozhodnete prozkoumat více – pokračujte čtením [dokumentace](https://ghzserg.github.io/).

## Než začnete

#### NEINSTALUJTE tento mod, pokud vám stačí následující opravy továrního firmwaru

Tyto funkce jsou přeneseny do továrního firmwaru:

1. Chci nainstalovat Klipper. (Klipper je již v tiskárně, ale chybí webové rozhraní)
2. [Instalovat root](Native_FW.md#root)
3. [Oprava chyby E0011](Global.md#fix_e0011)
4. [Oprava chyby E0017](Global.md#fix_e0017)
5. [Vypnout aktualizace/telemetrii/čínské cloudy tiskárny](Global.md#china_cloud)
6. [Tovární reset](Setup.md#restoring-printer-to-factory-settings-required-for-mod-installation)
7. [Převést FF5M na FF5MPro](Native_FW.md#5m-to-5mpro)
8. [Převést FF5MPro na FF5M](Native_FW.md#5mpro-to-5m)


### Kompatibilita
Kompatibilní s čistými verzemi firmwaru:

- FF5M/FF5MPro: v2.7.5 nebo vyšší (2.7.5, 2.7.6, 2.7.7, 2.7.8, 2.7.9, 3.1.3, 3.1.4, 3.1.5, 3.1.9, **3.2.3**, 3.2.4, 3.2.5, 3.2.6, 3.2.7, 5.0.3)
- [AD5X](AD5X.md): pouze (1.0.2, 1.0.7, 1.0.8, 1.0.9, 1.1.1, 1.1.6, **1.1.7**, 1.1.9, 1.2.0, 1.2.1, 1.2.2, 1.2.3, 3.0.3)

Soubory nativního firmwaru se nacházejí [zde](Native_FW.md).

## Instalace/Aktualizace/Odstranění

[Průvodce instalací/aktualizací/odstraněním](Setup.md)

## FAQ

[Musíte si přečíst](FAQ.md)

## Doporučení pro stabilitu tiskárny

[Přečtěte si, pokud narazíte na problémy](Recomendations.md)

## Pluginy

zMod podporuje [Pluginy](Plugin.md)

## Podpořte vývoj

Protože se lidé ptali, přijímám dary, ale pamatujte, že na zMod pracuji pro zábavu a ne pro peníze. Nebudu přijímat dary za práci na konkrétních chybách nebo funkcích.

Dostupné metody podpory najdete na samostatné [stránce](Sponsor.md)
