# Doporučení
## Doporučení ke zlepšení stability tiskárny

Tato doporučení se vztahují na původní firmware i ZMOD.

---

### Povolit vyloučení objektů

Povolte vyloučení objektů v Orce:

- `Process Profile` -> `Other` -> `Custom G-code` -> Zaškrtněte `Exclude objects`
- `Process Profile` -> `Other` -> `Custom G-code` -> Zaškrtněte `Label objects`

<img width="285" height="171" alt="image" src="https://github.com/user-attachments/assets/faceef98-2791-4975-bf72-425f4a2b1dfa" />

---

### Nainstalujte nejnovější standardní firmware a aktualizace ZMOD.

Aktivně podporována je pouze nejnovější verze ZMOD.

Vývojář nemá dostatek zdrojů na údržbu starších verzí, proto [nainstalujte nejnovější standardní firmware a aktualizace ZMOD](Setup.md).

---

### Nahraďte Spiral/Auto Z-Hop

Tiskárna tuto funkci nepodporuje.

**V Orce:**
`Printer Profile` -> `Extruder 1` -> `Z Hop Type` -> Nastavte na `Normal` nebo `Slanted`.

---

### Zakažte aproximaci "Arc Move"

Ačkoli tiskárna podporuje pohyby oblouku, snižují kvalitu tisku a mohou způsobit chyby.

**V Orce:**
`Process Profile` -> `Quality` -> `Precision` -> Zrušte zaškrtnutí `Arc Move Approximation`.

---

### Deaktivujte vestavěnou kameru na obrazovce tiskárny

Vestavěná kamera spotřebovává příliš mnoho paměti a nabízí nízkou kvalitu obrazu. Místo toho použijte alternativní kameru.

**Na obrazovce tiskárny:**
`Settings` -> `Camera Tab` -> Deaktivujte přepínače `Camera` a `Video`.

Poté spusťte makro [CAMERA_ON](Zmod.md#camera_on).

- [Co je alternativní kamera?](FAQ.md#what-is-an-alternative-camera)
- [Nainstaloval jsem ZMOD a moje kamera zmizela! Fungovala v Orca-FF!](FAQ.md#i-installed-the-printer-but-zmod-hid-my-camera-in-orca-ff-i-could-see-it-but-now-its-gone)

---

### Zakažte čínské cloudové služby

### Chyba režimu Lan

Tyto služby jsou nestabilní a mohou se přerušit. Pokusy o opětovné připojení mohou přetížit tiskárnu frontou požadavků a způsobit chyby.

Jejich vypnutí také umožňuje rychlejší zavření dialogů po tisku a nativní vyrovnání lůžka přes obrazovku.

**Na obrazovce tiskárny:**

1. `Settings` -> `WiFi Tab` -> `Network Mode` -> Povolte `Local Network Only`.
2. `Settings` -> `Cloud Tab` -> Deaktivujte `FlashCloud` a `Polar3d`.

Místo toho můžete použít:

- [zmod.link](Zmod.md#zlink) - cloud pro správu tiskáren prostřednictvím Fluidd/Mainsail.
- [Telegram bot](Macros.md).

[Více o čínských cloudových službách](Global.md#china_cloud).

---

### Povolit kontrolu kontrolního součtu [MD5]

Igor Polunovskiy

Přidejte [CHECK_MD5](System.md#check_md5) do svého pracovního postupu.

Doporučuje se použít [globální parametr FORCE_MD5](Global.md#force_md5) `SAVE_ZMOD_DATA FORCE_MD5=1`

1. Vyberte a stáhněte soubor pro vaši architekturu a operační systém:

- [zmod_preprocess-windows-amd64.exe](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-windows-amd64.exe) - Windows
- [zmod_preprocess-linux-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-linux-amd64) - Linux. Nezapomeňte chmod +x zmod_preprocess-linux-amd64
- [zmod_preprocess-darwin-arm64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-arm64) - MacOS (Intel). Nezapomeňte spustit ```chmod +x zmod_preprocess-darwin-arm64```
- [zmod_preprocess-darwin-amd64](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod_preprocess-darwin-amd64) - MacOS Silicon. Nezapomeňte spustit ```chmod +x zmod_preprocess-darwin-amd64```
- [zmod-preprocess.py](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.py) - General-Python. Nezapomeňte spustit ```chmod +x zmod-preprocess.py```
- [zmod-preprocess.sh](https://github.com/ghzserg/zmod_preprocess/releases/latest/download/zmod-preprocess.sh) - Linux/MacOS Bash. Nezapomeňte spustit ```chmod +x zmod-preprocess.sh```

2. V Orce musíte zadat: `Process Profile` -> `Other` -> `Post Processing Scripts`.

Zde jsou možnosti přidání:

- ```"С:\path_to_file\zmod_preprocess-windows-amd64.exe";```
- ```"C:\python_folder\python.exe" "C:\Scripts\zmod-preprocess.py";```
- ```"/usr/bin/python3" "/home/user/zmod-preprocess.py";```
- ```"/home/user/zmod-preprocess.py";```
- ```"/home/user/zmod_preprocess-darwin-amd64";```
- ```"/home/user/zmod_preprocess-darwin-arm64";```
- ```"/home/user/zmod_preprocess-linux-amd64";```

[Detaily](System.md#check_md5)

<img width="476" height="355" alt="image" src="https://github.com/user-attachments/assets/0b59a617-5613-4def-aa01-7fe038898863" />

*křeček*

---

### Odeslání souborů k tisku prostřednictvím „Octo/Klipper“

Nativní protokol FF občas přenáší poškozené soubory a postrádá podporu metadat pro bot Telegramu.

**V Orca:**

1. Klikněte na ikonu WiFi vedle tiskárny.
2. Nastavit:

    - **Protocol**: `Octo/Klipper`
       - **Hostname**: `Printer_IP:7125`
       - **Host URL**: `Printer_IP` or `Printer_IP:80`

Pokud používáte Mainsail, zadejte pouze tyto velikosti miniatur: ```140x110/PNG, 64x64/PNG```

V Orca, `Printer Profile` -> `General Information` -> `Advanced` -> `G-Code Thumbnails`

Vezměte na vědomí, že na nativní obrazovce se již nebudou zobrazovat miniatury.

---

### Povolit opravu chyby E0017

[E0017 Fix](Global.md#fix_e0017)

Ve výchozím nastavení povoleno.

---

### Povolit opravu chyby E0011

Řeší chyby `E0011` a `Časový limit komunikace během návratu do výchozí polohy`.

[E0011 Fix](Global.md#fix_e0011)

**Experimentální funkce** — ve výchozím nastavení je zakázána.

---

### Ověření integrity souborů operačního systému

Nesprávné vypnutí tiskárny může poškodit souborový systém, což může vést k menším nebo větším chybám.

Makro [CHECK_SYSTEM](System.md#check_system) kontroluje MD5 hash souboru a v případě potřeby opravuje symbolické odkazy.
---

### Povolit detekci kolize trysky

Ve výchozím nastavení je tato funkce vypnuta. Zapněte ji pomocí makra [NOZZLE_CONTROL](Global.md#nozzle_control):

```
NOZZLE_CONTROL WEIGHT=0
```

Tím se zastaví Klipper, pokud tryska poškrábe podložku nebo se uvolní část. **Důrazně doporučeno pro uživatele, kteří používají rutiny předběžného čištění trysek.**