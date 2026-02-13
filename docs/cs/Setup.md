# Nastavení

---

## Obnovení továrního nastavení tiskárny (nutné pro instalaci modifikace)

0. [Odinstalujte KlipperMod](https://github.com/xblax/flashforge_ad5m_klipper_mod/blob/master/docs/UNINSTALL.md), pokud byl dříve nainstalován.
1. Obnovte výchozí nastavení tiskárny.
2. Naformátujte USB disk na FAT/FAT16/FAT32.
3. Zkopírujte příslušný soubor z [nativního firmwaru](Native_FW.md) do kořenového adresáře USB:

    - [Adventurer5M-3.1.9-2.2.3-20250807-Factory.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-3.1.9-2.2.3-20250807-Factory.tgz) pro FF5M
    - [Adventurer5MPro-3.1.3-2.2.3-20250107-Factory.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-3.1.3-2.2.3-20250107-Factory.tgz) pro FF5M **Pro**
    - [AD5X-1.1.6-1.1.0-3.0.6-20250722.tgz](https://github.com/ghzserg/FF/releases/download/R/AD5X-1.1.6-1.1.0-3.0.6-20250722.tgz) pro AD5X

4. Vypněte tiskárnu.
5. Vložte USB disk do USB portu tiskárny.
6. Zapněte tiskárnu.
7. Počkejte, až se dokončí instalace standardního firmwaru.
8. Nakonfigurujte Wi‑Fi nebo LAN.
9. Získejte nejnovější aktualizace tiskárny nebo nainstalujte firmware 1.1.7 pro AD5X nebo 3.2.3 pro [AD5M](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-3.2.3-2.2.3-20251016-Factory.tgz)/[AD5MPro](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-3.2.3-2.2.3-20251017-Factory.tgz), pokud nechcete, aby tiskárna [měřila střed lože před každým tiskem](FAQ.md#before-each-print-the-printer-measures-the-center-of-the-bed).

---

## Instalace modifikace

[Video](https://www.youtube.com/watch?v=2sfb2OtY7wM)

1. **[Obnovte tovární nastavení tiskárny](#restoring-printer-to-factory-settings-required-for-mod-installation).**  [Varování pro AD5X](#ad5x-warning)
2. Naformátujte USB disk na FAT/FAT16/FAT32.
3. Zkopírujte soubor [soubor modu](https://github.com/ghzserg/zmod/releases/) do kořenového adresáře USB:

    - Pro FF5M: Adventurer5M-**zmod**-*.tgz
       - Pro FF5M Pro: Adventurer5MPro-**zmod**-\*.tgz
       - Pro [AD5X](AD5X.md): AD5X-**zmod**-*.tgz

4. Vypněte tiskárnu.
5. Vložte USB disk.
6. Zapněte tiskárnu.
7. Počkejte, až se dokončí instalace modulu.

   <img width="800" height="480" alt="install" src="https://github.com/user-attachments/assets/9d6b9ad7-e9ec-4bc2-bd8f-54c945b5add5" />
   
   <img width="800" height="480" alt="screenshot" src="https://github.com/user-attachments/assets/19d66329-72f9-4e92-aba6-35b7820ce9a0" />
   
   Instalace na AD5X může trvat až 40 minut.

8. Odpojte USB disk.
9. Zapněte tiskárnu.
10. **Otevřete IP adresu tiskárny v prohlížeči**.
    <img width="800" height="480" alt="main" src="https://github.com/user-attachments/assets/a0466fa8-03e8-458d-8cc5-c1efb8f565ac" />
    <img width="800" height="480" alt="ip" src="https://github.com/user-attachments/assets/1d7dd5fa-86f4-4b1a-bd42-364619b20229" />
    
    Pokud se webové rozhraní neotevře, znamená to, že standardní firmware tuto funkci zakázal. Chcete-li ji povolit, zkopírujte soubor [AD5X-ENABLE-zmod.tgz](https://github.com/ghzserg/FF/releases/download/R/AD5X-ENABLE-zmod.tgz) na USB flash disk a [aktivujte mod](Native_FW.md#ad5x-enable-zmodtgz).

12. Nastavte jazyk modu.

    <img width="564" height="583" alt="{8E14F84D-E8D1-4129-B192-AA335243A3D9}" src="https://github.com/user-attachments/assets/e6dd3f8a-3cc3-4a05-b5fb-ad8ba372ede6" />
    
    Nebo zadejte do konzole: ```LANG LANG=en```
    
    <img width="881" height="502" alt="image" src="https://github.com/user-attachments/assets/cf3f797d-80e0-4864-85b4-cd28886590f4" />

13. Nakonfigurujte mod

    <img width="558" height="219" alt="{B34D2AF2-F2A6-433D-B9F8-86A83389D5A7}" src="https://github.com/user-attachments/assets/a79ec692-a284-4cb8-a0ad-3be10f33d813" />
    
    Zde jsou uvedeny parametry použité na začátku tisku, na konci tisku a globální nastavení. Doporučujeme pouze zkontrolovat nastavení – neměňte je, pokud to není nutné. Popis jednotlivých parametrů naleznete [zde](Global.md).

    <img width="561" height="443" alt="{623507C1-D3AB-4FEF-9A92-E949A85DCB49}" src="https://github.com/user-attachments/assets/3a8028bf-b078-4edc-827b-07e9d49c52f9" />

    Musíte přejít na poslední obrazovku a stisknout tlačítko „OK“ nebo „Reboot“. Pokud tento krok přeskočíte, okno se bude zobrazovat při každém spuštění systému.
    <img width="564" height="228" alt="{BCEBDCCC-0703-46F3-8B7B-3BC58E78F27A}" src="https://github.com/user-attachments/assets/72d386a4-18ba-40a9-8f85-a6109a4e4c57" />

    Chcete-li toto okno později znovu zobrazit, zadejte do konzole: `GLOBAL`

14. Přejděte do části „Nastavení“ → „Aktualizace firmwaru“.
15. Klikněte na „Zkontrolovat aktualizace“ a počkejte, až se kontrola dokončí.
16. Klikněte na „Aktualizovat“ a aktualizujte všechny komponenty.

    <img width="1239" height="535" alt="image" src="https://github.com/user-attachments/assets/b42c4ce9-1c0a-45c0-a20c-36919a27d648" />

    Pokud se objeví mnoho chyb, je to normální. Pluginy nejsou součástí firmwaru a stahují se samostatně. Klikněte znovu na „Zkontrolovat aktualizace“ a poté obnovte a aktualizujte každý modul samostatně. Během tohoto procesu se tiskárna restartuje.

    <img width="671" height="844" alt="image" src="https://github.com/user-attachments/assets/d6fe3ad0-64be-4c07-8f5e-53647a6bd6ee" />

17. Povolte [doporučené pluginy](https://github.com/ghzserg/recommend/blob/main/Readme.md)

    <img width="560" height="224" alt="{E27E192D-3FC2-49AC-BEAF-F7B574FFEF45}" src="https://github.com/user-attachments/assets/dade8a2e-fc67-4df5-aad4-85cc5cd81d66" />

    Nebo zadejte do konzole: ```ENABLE_PLUGIN name=recommend```

    <img width="864" height="87" alt="image" src="https://github.com/user-attachments/assets/ca96c67f-cc58-4655-8fdf-9554d1a489a3" />

18. [Odesílání souborů k tisku pomocí „Octo/Klipper“](Recomendations.md#send-files-via-octoklipper-for-printing)

    **Musíte přepnout na protokol Octo/Klipper**:

    - Protokol: `Octo/Klipper`
        - Název hostitele: `Printer_IP:7125`
        - URL hostitele: `Printer_IP` nebo `Printer_IP:80`

    
    <img width="673" height="467" alt="image" src="https://github.com/user-attachments/assets/70d5da64-0604-44e5-9102-887b758b5cf0" />
    <img width="473" height="395" alt="image" src="https://github.com/user-attachments/assets/ca4c5330-dc88-4372-a3c8-51527ae76146" />

19. Celý startovací kód by měl být nahrazen tímto:
    ```
    START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
    M190 S[bed_temperature_initial_layer_single]
    M104 S[nozzle_temperature_initial_layer]
    SET_PRINT_STATS_INFO TOTAL_LAYER=[total_layer_count]
    ```
    
    ```START_PRINT EXTRUDER_TEMP=... BED_TEMP=...``` by mělo být napsáno na jednom řádku
    
    Koncový kód by měl vypadat takto:

    ```END_PRINT```
    
    <img width="612" height="443" alt="image" src="https://github.com/user-attachments/assets/0dfd8840-c183-4d33-92aa-46f882b8c32c" /> 
    
    Kód před změnou vrstvy na tento:

    ```SET_PRINT_STATS_INFO CURRENT_LAYER={layer_num + 1}``` 
    
    <img width="449" height="153" alt="image" src="https://github.com/user-attachments/assets/705fb49e-2c6b-451b-9b99-9d8d1f0e80f8" />

20. [Povolit ověření MD5](Recomendations.md#enable-md5-checksum-control)

    <img width="476" height="355" alt="image" src="https://github.com/user-attachments/assets/0b59a617-5613-4def-aa01-7fe038898863" />

21. [Přečtěte si doporučení](Recomendations.md)
22. [Přečtěte si často kladené otázky](FAQ.md)

### Varování AD5X

[@Khamai](https://t.me/Khamai)

Po instalaci nativního firmwaru nemusí být tisková hlava správně umístěna vůči odpadnímu koši na filament. (páčka uzávěru koše nemusí být zcela zatlačena, filament může být vytlačován na stůl atd.).
[Prostřednictvím debug menu ve standardním firmwaru](AD5X.md#setting-up-the-basket-on-the-ad5x-stock-firmware)

Pokud se setkáte s tímto problémem, musíte kalibrovat polohu tiskové hlavy pomocí následujícího algoritmu:

1. Stáhněte archiv [Set.XY.Offset.zip](https://github.com/ghzserg/FF/releases/download/R/Set.XY.Offset.zip) a rozbalte jej do kořenového adresáře flash disku.
2. Vložte flash disk do vypnuté tiskárny a zapněte ji.
3. Na displeji tiskárny se zobrazí kalibrační rozhraní. Stiskněte tlačítko Reset.
4. Pomocí ovládacích šipek umístěte tiskovou hlavu proti přijímači tak, aby tisková hlava pevně přitlačovala páčku uzávěru, tryska byla za pohyblivým uzávěrem a uzávěr byl v jedné rovině s přední plochou koše.
5. Stiskněte tlačítko Set (Nastavit) pro potvrzení výsledku kalibrace.
6. Vyjměte flash disk a restartujte tiskárnu.

---

## Aktualizace modu

Pokud se zobrazí hlášení („Aktualizujte ZMOD přes USB“), musíte provést aktualizaci přes USB, i když jste ji nedávno provedli.

**Aktualizace přes USB zachová všechna data.**

**Nejjednodušší metoda:** Použijte makro [ZFLASH](Zmod.md#zflash). Vložte USB disk, restartujte tiskárnu a spusťte `ZFLASH`. Makro provede následující:

- Zkontroluje nejnovější verzi.
- Stáhne nejnovější verzi pro váš model tiskárny.
- Ověří kontrolní součty.
- Restartuje tiskárnu.
- Automaticky nainstaluje aktualizaci (USB disk nechte zasunutý pro budoucí aktualizace).

Po instalaci:

1. Přejděte do Fluidd/Mainsail → „Nastavení“ → „Aktualizace softwaru“.
2. Klikněte na „Zkontrolovat aktualizace“ a nainstalujte nejnovější aktualizace ZMOD.

<img width="1239" height="535" alt="image" src="https://github.com/user-attachments/assets/b42c4ce9-1c0a-45c0-a20c-36919a27d648" />

Pokud se zobrazí mnoho chyb, je to normální.

Pluginy nejsou součástí firmwaru a stahují se samostatně.

Klikněte na `Zkontrolovat aktualizace`. Poté obnovte a aktualizujte všechny moduly jeden po druhém. Během tohoto procesu se tiskárna restartuje.

<img width="671" height="223" alt="image" src="https://github.com/user-attachments/assets/5744dc8e-ba58-4359-b78a-652be846ca07" />

**Kompatibilita verzí:**

- Verze operačního systému (v menu `System` → `Distribution`) musí odpovídat prvním dvěma číslicím verze ZMOD (v menu `Settings` → `Updates` → `ffm5/zmod`).
- **Nesoulad verzí způsobuje nestabilitu.**

**Manuální aktualizace přes USB:**

1. Naformátujte USB disk na FAT/FAT16/FAT32.
2. Zkopírujte [soubor modu](https://github.com/ghzserg/zmod/releases/) do kořenového adresáře USB.
3. Vypněte tiskárnu.
4. Vložte USB disk.
5. Zapněte tiskárnu.
6. Počkejte na restart a instalaci.
7. Vyjměte USB disk.
8. Vypněte a znovu zapněte tiskárnu.

---

## Odstranění nebo dočasné vypnutí modu

- **[SKIP_ZMOD](Zmod.md#skip_zmod)**: Restartuje tiskárnu bez spuštění Moonraker/Fluidd.
- **[REMOVE_ZMOD](Zmod.md#remove_zmod)**: Kompletně odinstaluje mod.

**Doporučená metoda:** Použijte makro `REMOVE_ZMOD`. Odstranění přes USB použijte pouze v případě, že makra nejsou dostupná.

Pozor!

- Pokud používáte Klipper 13, musíte spustit ```UPDATE_MCU```. Tím zabráníte tomu, aby MCU a Klipper měly různé verze.
- Pokud máte povolené pluginy, musíte je nejdříve deaktivovat pomocí ```DISABLE_PLUGIN name=g28_tenz```.

**Odstranění přes USB:**

1. Naformátujte USB disk na FAT/FAT16/FAT32.
2. Zkopírujte [flashforge_init.sh](https://github.com/ghzserg/zmod/blob/main/Native_firmware/rem_zmod/flashforge_init.sh) do kořenového adresáře USB.
3. Vypněte tiskárnu.
4. Vložte USB disk.
5. Zapněte tiskárnu.
6. Počkejte na tři restarty.
7. Vyjměte USB disk.

---

## Aktualizace nativního firmwaru

1. Deaktivujte všechny aktivní pluginy kromě `recommend`, `timelapse` a `notify`:
   ```DISABLE_PLUGIN name=plugin_name```

2. Pokud používáte **Klipper 13**, spusťte ```UPDATE_MCU``` *před* aktualizací nativního firmwaru. Tím předejdete problémům s nekompatibilitou verzí mezi MCU a Klipperem.
3. Povolení čínských cloudových služeb (pokud chcete aktualizovat přes nativní dotykový displej):
   ```SAVE_ZMOD_DATA CHINA_CLOUD=1```

**U [AD5X](AD5X.md) je nutná aktivace modu [zMod](Native_FW.md) pomocí `AD5X-ENABLE-zmod.tgz` z USB disku – po aktualizaci nativního firmwaru.**

---

## Podpořte vývoj modu

BTC `17wXTd9BqYp1K3zCLTxVyGLEXUDjf7XNLL`

---

## Obnova po selhání při startu

*Průvodce od [@darksimpson](https://t.me/darksimpson), [Alexander](https://github.com/DrA1ex), [@Ikaros413](https://t.me/Ikaros413), [@SoloMen88](https://t.me/SoloMen88)*

**Příznaky:** Tiskárna se zasekne na úvodní obrazovce a není dostupná přes LAN.

![](../images/ff.jpg)

Zkuste obnovit firmware instalací plného firmwaru:

- [FF5M](Native_FW.md#installing-full-firmware-on-ff5m)
- [AD5X](Native_FW.md#installing-full-firmware-on-ad5x)

**Postup:**

1. **Odpojte tiskárnu od napájení.**
2. Připravte si **3,3V UART/USB převodník** (ujistěte se, že je nastaven na 3,3V).

![](../images/ch340.jpg)

3. Otevřete zadní kryt tiskárny.
4. Připojte se k UART pinům (RX, TX, GND — **NEPŘIPOJUJTE 3,3V napájení**).

![](../images/connect.jpg)

**VAROVÁNÍ:** Napájení 5V poškodí základní desku!

5. Připojte převodník křížem:

    - Převodník RX → TX tiskárny
    - Převodník TX → RX tiskárny
    - Převodník GND → GND tiskárny

![](../images/connect_photo.jpg)

6. Identifikujte nově přidaný COM port ve vašem operačním systému.

![](../images/port.jpg)

7. Otevřete PuTTY:

    - **Typ připojení**: Serial
    - **Rychlost**: 115200
    - **COM port**: (např. COM6)

8. Zapněte tiskárnu.
9. Když se objeví hláška `Hit any key to stop autoboot`, stiskněte **Enter**.

10. V U-Bootu spusťte:
    ```
    setenv init /bin/sh
    boot
    ```

11. Po nabootování Linuxu přepněte souborový systém do zápisu:
    ```
    mount -t proc proc /proc
    mount -o remount,rw /
    ```

12. Opravte poškozené soubory (např. smažte chybné skripty):
    ```
    rm -f /etc/init.d/S01bad_script
    rm -f /opt/config/mod/.shell/S98camera
    ```

13. Uložte změny a restartujte:
    ```
    sync
    reboot
    ```
