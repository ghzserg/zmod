# Doporučení
## Doporučení ke zlepšení stability tiskárny

Tato doporučení platí pro nativní firmware i pro Z-Mod.

---

### Povolit vyloučení objektů

Povolte vyloučení objektů v Orce:

- `Process Profile` -> `Other` -> `G-code output` -> Zaškrtněte `Exclude objects`
- `Process Profile` -> `Other` -> `G-code output` -> Zaškrtněte `Label objects`

<img width="285" height="171" alt="image" src="../../images/faceef98-2791-4975-bf72-425f4a2b1dfa.png" />

---

### Nainstalujte nejnovější standardní firmware a aktualizace Z-Mod

Aktivně podporována je pouze nejnovější verze Z-Mod.

Vývojář nemá dostatek zdrojů na údržbu starších verzí, proto [nainstalujte nejnovější standardní firmware a aktualizace Z-Mod](/cs/Setup/).

---

### Nahraďte Spiral/Auto Z-Hop

Tiskárna tuto funkci nepodporuje.

**V Orce:**
`Printer Profile` -> `Extruder 1` -> `Z Hop Type` -> Nastavte na `Normal` nebo `Slanted`.

---

### Vypněte oblouky (arc_move)

Tiskárna obloukové pohyby podporuje, ale zhoršují kvalitu tisku a občas způsobují chyby.

**V Orce:**
`Process Profile` -> `Quality` -> `Precision` -> Zrušte zaškrtnutí `Arc fitting`.

---

### Deaktivujte vestavěnou kameru na obrazovce tiskárny

Vestavěná kamera spotřebovává příliš mnoho paměti a nabízí nízkou kvalitu obrazu. Místo toho použijte alternativní kameru.

**Na obrazovce tiskárny:**
`Settings` -> `Camera Tab` -> Deaktivujte přepínače `Camera` a `Video`.

Poté spusťte makro [CAMERA_ON](/cs/Zmod/#camera_on).

- [Co je alternativní kamera?](/cs/FAQ/#co-je-to-alternativní-kamera)
- [Nainstaloval jsem Z-Mod a moje kamera zmizela! Fungovala v Orca-FF!](/cs/FAQ/#nainstaloval-jsem-tiskárnu-ale-z-mod-mi-skryl-kameru-v-orca-ff-jsem-ji-viděl-ale-teď-je-pryč)

---

### Zakažte čínské cloudové služby

### Chyba režimu LAN

Tyto služby jsou nestabilní a občas ztrácejí spojení. Při opětovném připojení nahromaděné požadavky přetíží tiskárnu a způsobí chyby.

Jejich vypnutí také zrychlí zavírání dialogů po tisku a umožní měření sítě podložky přes nativní obrazovku.

**Na obrazovce tiskárny:**

1. `Settings` -> `WiFi Tab` -> `Network Mode` -> Povolte `Local Network Only`.
2. `Settings` -> `Cloud Tab` -> Deaktivujte `FlashCloud` a `Polar3D`.

Místo toho můžete použít:

- [zmod.link](/cs/Zmod/#zlink) - cloud pro správu tiskáren prostřednictvím Fluidd/Mainsail.
- [Telegram bot](/cs/Telegram/).

[Více o čínských cloudových službách](/cs/Global/#china_cloud).

---

### Povolit kontrolu kontrolního součtu [MD5]

Igor Polunovskiy

> Poznámka: Platí pouze při odesílání G-code. Pro 3MF není potřeba.

Přidejte [CHECK_MD5](/cs/System/#check_md5) do svého pracovního postupu.

Doporučuje se použít [globální parametr FORCE_MD5](/cs/Global/#force_md5) `SAVE_ZMOD_DATA FORCE_MD5=1`

1. Vyberte a stáhněte soubor pro vaši architekturu a operační systém:

- [zmod_preprocess-windows-amd64.exe](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-windows-amd64.exe) - Windows
- [zmod_preprocess-linux-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-linux-amd64) - Linux. Nezapomeňte chmod +x zmod_preprocess-linux-amd64
- [zmod_preprocess-darwin-arm64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-arm64) - macOS Apple Silicon. Nezapomeňte spustit ```chmod +x zmod_preprocess-darwin-arm64```
- [zmod_preprocess-darwin-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-amd64) - macOS Intel. Nezapomeňte spustit ```chmod +x zmod_preprocess-darwin-amd64```
- [zmod-preprocess.py](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.py) - Univerzální Python. Nezapomeňte spustit ```chmod +x zmod-preprocess.py```
- [zmod-preprocess.sh](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.sh) - Linux/macOS Bash. Nezapomeňte spustit ```chmod +x zmod-preprocess.sh```

2. V Orce musíte zadat: `Process Profile` -> `Other` -> `Post Processing Scripts`.

Pokud cesta obsahuje mezery, uzavřete celou cestu do uvozovek — je ale lepší mezery v názvech složek nepoužívat.

Zde jsou možnosti přidání:

- ```"C:\path_to_file\zmod_preprocess-windows-amd64.exe";```
- ```"C:\python_folder\python.exe" "C:\Scripts\zmod-preprocess.py";```
- ```"/usr/bin/python3" "/home/user/zmod-preprocess.py";```
- ```"/home/user/zmod-preprocess.py";```
- ```"/home/user/zmod_preprocess-darwin-amd64";```
- ```"/home/user/zmod_preprocess-darwin-arm64";```
- ```"/home/user/zmod_preprocess-linux-amd64";```

[Detaily](/cs/System/#check_md5)

<img width="476" height="355" alt="image" src="../../images/0b59a617-5613-4def-aa01-7fe038898863.png" />

*křeček*

---

### Odeslání souborů k tisku prostřednictvím „Octo/Klipper“

Nativní protokol FF občas přenáší poškozené soubory a nevytváří náhledy ani metadata pro Telegram bota.

**V Orca:**

1. Klikněte na ikonu WiFi vedle tiskárny.
2. Nastavit:

    - **Host Type**: `Octo/Klipper`
    - **Printer Agent**: `Moonraker`

    Pro Creator 5 / Creator 5 Pro / AD5X:

    - **Hostname**: `IP_printer`

    <img width="612" height="447" alt="{D625ED9D-902D-4412-A99E-20FB0C5ED85F}" src="../../images/1c26beca-9aff-4c7c-846d-273efa8624f8.png" />

    Pro FF5M / FF5M Pro:

    - **Hostname**: `IP_printer:7125`
    - **Device UI**: `IP_printer` nebo `IP_printer:80`
    
    <img width="678" height="471" alt="{8FB1D8A5-A02F-41A8-8309-CD556007FD1B}" src="../../images/a9c3fc5e-3ec0-41ed-bbd7-779ee210c9a1.png" />

Pokud používáte Mainsail, zadejte pouze tyto velikosti miniatur: ```140x110/PNG, 64x64/PNG```

V Orca: `Printer Profile` -> `General Information` -> `Advanced` -> `G-Code Thumbnails`

Vezměte na vědomí, že na nativní obrazovce se již nebudou zobrazovat miniatury.


---

### Povolit opravu chyby E0017

[Oprava E0017](/cs/Global/#fix_e0017)

Ve výchozím nastavení povoleno.

---

### Povolit opravu chyby E0011

Řeší chyby `E0011` a `Communication timeout during homing`.

[Oprava E0011](/cs/Global/#fix_e0011)

---

### Ověření integrity souborů operačního systému

Nesprávné vypnutí tiskárny může poškodit souborový systém, což může vést k menším nebo větším chybám.

Makro [CHECK_SYSTEM](/cs/System/#check_system) kontroluje MD5 součty souborů a v případě potřeby opravuje symbolické odkazy.

---

### Povolit detekci kolize trysky

Ve výchozím nastavení je tato funkce vypnuta. Zapněte ji pomocí makra [NOZZLE_CONTROL](/cs/Global/#nozzle_control):

```
NOZZLE_CONTROL WEIGHT=1500
```

Po zapnutí se při tisku aktivuje automaticky.

Tím se zastaví Klipper, pokud tryska začne škrábat podložku nebo se odtrhne díl. **Důrazně doporučeno pro uživatele, kteří používají předčištění trysky.**