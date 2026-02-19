### [Installation](#installation-mod)

### Drucker auf Werkseinstellungen zurücksetzen (erforderlich für die Installation des Mods)

0. [KlipperMod](https://github.com/xblax/flashforge_ad5m_klipper_mod/blob/master/docs/UNINSTALL.md) deinstallieren, wenn er installiert wurde
1. Setzen Sie den Drucker auf die Standardeinstellungen zurück.
2. den USB-Stick auf FAT/FAT16/FAT32 formatieren
3. Legen Sie die Datei von [Native Firmware](/de/Native_FW/) in den Stammordner des USB-Flash-Laufwerks

    - [Adventurer5M-3.1.9-2.2.3-20250807-Factory.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-3.1.9-2.2.3-20250807-Factory.tgz) für FF5m
    - [Adventurer5MPro-3.1.3-2.2.3-20250107-Factory.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-3.1.3-2.2.3-20250107-Factory.tgz) für FF5m**Pro** Version
    - [AD5X-1.1.7-1.1.0-3.0.6-20250912.tgz](https://github.com/ghzserg/FF/releases/download/R/AD5X-1.1.7-1.1.0-3.0.6-20250912-Factory.tgz.gz) für AD5X

4. Schalten Sie den Drucker aus
5. Stecken Sie den USB-Stick in den Drucker
6. Schalten Sie den Drucker ein
7. Warten Sie, bis die native Firmware installiert ist.
8. WiFi oder Lan einrichten *neuer Biber*
9. Holen Sie sich die neuesten Drucker-Updates oder installieren Sie die Firmware 1.1.7 für AD5X bzw. 3.2.3 für [AD5M](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-3.2.3-2.2.3-20251016-Factory.tgz)/[AD5MPro](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-3.2.3-2.2.3-20251017-Factory.tgz), wenn Sie nicht möchten, dass der Drucker [vor jedem Druckauftrag die Mitte des Druckbetts misst](https://wiki.zmod.link/de/FAQ/#misst-die-tabelle-vor-jedem-druckauftrag-zentriert)

---

## Installieren der Mod

[Video](https://www.youtube.com/watch?v=2sfb2OtY7wM)

1. **[Drucker auf Werkseinstellungen zurücksetzen](/de/Setup/#drucker-auf-werkseinstellungen-zur-installation-von-mod-zuruecksetzen)** [Vorsicht AD5X](/de/Setup/#Vorsicht-ad5x)
2. formatieren Sie den USB-Stick auf FAT/FAT16/FAT32
3. Legen Sie die [Datei](https://github.com/ghzserg/zmod/releases/) im Stammverzeichnis des USB-Flash ab.

    - für FF5M: Adventurer5M-**zmod**-\*.tgz
       - für FF5MPro: Adventurer5MPro-**zmod**-\*.tgz
       - für [AD5X](/de/AD5X/): AD5X-**zmod**-\*.tgz

4. Schalten Sie den Drucker aus
5. Stecken Sie den USB-Stick in den Drucker
6. Schalten Sie den Drucker ein
7. Warten Sie auf die Installation des Mods

   <img width="800" height="480" alt="install" src="https://github.com/user-attachments/assets/9d6b9ad7-e9ec-4bc2-bd8f-54c945b5add5" />
   
   <img width="800" height="480" alt="Bildschirmfoto" src="https://github.com/user-attachments/assets/19d66329-72f9-4e92-aba6-35b7820ce9a0" />
   
   Auf dem AD5X kann die Installation bis zu **40 Minuten** dauern.

8. Entfernen Sie den USB-Stick
9. Schalten Sie den Drucker aus
10. Schalten Sie den Drucker ein
11. **Drucker-IP im Browser öffnen**
    <img width="800" height="480" alt="main" src="https://github.com/user-attachments/assets/a0466fa8-03e8-458d-8cc5-c1efb8f565ac" />
    <img width="800" height="480" alt="ip" src="https://github.com/user-attachments/assets/1d7dd5fa-86f4-4b1a-bd42-364619b20229" />
    
    Wenn sich das Webinterface nicht öffnet, hat die native Firmware den Mod deaktiviert. Um sie zu aktivieren, müssen Sie die USB-Flash-Datei [AD5X-ENABLE-zmod.tgz](https://github.com/ghzserg/FF/releases/download/R/AD5X-ENABLE-zmod.tgz) und [activate mod](de/Native_FW/#ad5x-enable-zmodtgz) installieren.
     
12. Übersetzen Sie den Mod in Ihrer Sprache.
    
    <img width="564" height="583" alt="{8E14F84D-E8D1-4129-B192-AA335243A3D9}" src="https://github.com/user-attachments/assets/e6dd3f8a-3cc3-4a05-b5fb-ad8ba372ede6" />
    
    Oder geben Sie in der Konsole ````LANG LANG=ru``` für die passende Sprache ein.
    
    <img width="881" height="502" alt="image" src="https://github.com/user-attachments/assets/cf3f797d-80e0-4864-85b4-cd28886590f4" />

13. Konfigurieren Sie den Mod
    
    <img width="558" height="219" alt="{B34D2AF2-F2A6-433D-B9F8-86A83389D5A7}" src="https://github.com/user-attachments/assets/a79ec692-a284-4cb8-a0ad-3be10f33d813" />
    
    Dies zeigt die Parameter, die am Anfang und am Ende verwendet werden, sowie die globalen Parameter. Es wird empfohlen, die Einstellungen nur zu lesen, sie aber nicht zu ändern. Die Werte der einzelnen Einstellungen können [hier](/de/Global/) eingesehen werden.

    <img width="561" height="443" alt="{623507C1-D3AB-4FEF-9A92-E949A85DCB49}" src="https://github.com/user-attachments/assets/3a8028bf-b078-4edc-827b-07e9d49c52f9" />

    Sie müssen zum letzten Bildschirm gelangen und auf "OK" oder "Neustart" drücken. Wenn Sie das nicht tun, wird dieses Fenster bei jedem Start erscheinen

    <img width="564" height="228" alt="{BCEBDCCC-0703-46F3-8B7B-3BC58E78F27A}" src="https://github.com/user-attachments/assets/72d386a4-18ba-40a9-8f85-a6109a4e4c57" />

    Wenn Sie dieses Fenster wieder sehen wollen - dann geben Sie `GLOBAL` in die Konsole ein

14. Gehen Sie zu `Einstellungen` -> `Software Updates`.
15. Klicken Sie auf "Nach Updates suchen" und warten Sie, bis die Updates geprüft wurden.
16. Klicken Sie auf **Update** und aktualisieren Sie alle Komponenten.
    <img width="1239" height="535" alt="image" src="https://github.com/user-attachments/assets/b42c4ce9-1c0a-45c0-a20c-36919a27d648" />

    Wenn es viele Fehler anzeigt, ist das normal. Plugins sind nicht Teil der Firmware und werden separat heruntergeladen. Sie müssen auf "Nach Updates suchen" klicken.
    Stellen Sie dann alle Plug-ins wieder her und aktualisieren Sie sie nacheinander. Der Drucker wird neu gestartet.
    
    <img width="671" height="844" alt="image" src="https://github.com/user-attachments/assets/d6fe3ad0-64be-4c07-8f5e-53647a6bd6ee" />

17. Aktivieren Sie das [Empfehlungs-Plugin](https://github.com/ghzserg/recommend/blob/main/Readme.md)
    
    <img width="560" height="224" alt="{E27E192D-3FC2-49AC-BEAF-F7B574FFEF45}" src="https://github.com/user-attachments/assets/dade8a2e-fc67-4df5-aad4-85cc5cd81d66" />

    Oder geben Sie in der Konsole ````ENABLE_PLUGIN name=recommend``` ein.

    <img width="864" height="87" alt="image" src="https://github.com/user-attachments/assets/ca96c67f-cc58-4655-8fdf-9554d1a489a3" />

18. [Orca-Slicer anpassen](/de/Recomendations/#send-files-to-print-octoklipper)
    Der gesamte Startcode muss durch diesen ersetzt werden:

    ```
    START_PRINT EXTRUDER_TEMP=[nozzle_temperature_initial_layer] BED_TEMP=[bed_temperature_initial_layer_single]
    M190 S[bed_temperature_initial_layer_single]
    M104 S[düse_temperatur_anfangsschicht]
    SET_PRINT_STATS_INFO TOTAL_LAYER=[total_layer_count]
    ```
    
    ````START_PRINT EXTRUDER_TEMP= BED_TEMP=```` **muss in eine Zeile geschrieben werden**

    Der endgültige Code zu diesem:

    ```END_PRINT```

    <img width="612" height="443" alt="image" src="https://github.com/user-attachments/assets/0dfd8840-c183-4d33-92aa-46f882b8c32c" />

    Code, bevor Sie die Ebene in diese ändern:

    ````SET_PRINT_STATS_INFO CURRENT_LAYER={layer_num + 1}```.

    <img width="449" height="153" alt="image" src="https://github.com/user-attachments/assets/705fb49e-2c6b-451b-9b99-9d8d1f0e80f8" />

    Es ist notwendig, auf das Protokoll "Octo/Klipper" umzuschalten:

      - Protokoll: `Octo/Klipper`.
          - Hostname: "IP-Druckername:7125".
          - Url-Adresse des Hosts: `IP_printer` oder `IP_printer:80`

    <img width="673" height="467" alt="image" src="https://github.com/user-attachments/assets/70d5da64-0604-44e5-9102-887b758b5cf0" />
    <img width="473" height="395" alt="image" src="https://github.com/user-attachments/assets/ca4c5330-dc88-4372-a3c8-51527ae76146" />

19. [MD5-Kontrolle aktivieren](de/Recomendations/#aktivieren-sie-die-md5-kontrolle))

    <img width="476" height="355" alt="image" src="https://github.com/user-attachments/assets/0b59a617-5613-4def-aa01-7fe038898863" />

20. [Lesen Sie die Empfehlungen](/de/Recomendations/)
21. [FAQ lesen](/de/FAQ/)

### Achtung AD5X

[@Khamai](https://t.me/Khamai)

Nach der Installation der Native Firmware kann es vorkommen, dass der Druckkopf nicht richtig am Filamentempfänger geparkt ist (Unterklemmen des Empfängervorhangs, Herausdrücken des Filaments auf dem Tisch usw.).

[Über das Engineering-Menü der nativen Firmware][(/de/AD5X/#korb-setup-auf-nativer-ad5x-firmware)

Wenn Sie auf diese Situation stoßen, müssen Sie das Parken mit Hilfe des folgenden Algorithmus kalibrieren:

1. Laden Sie das Archiv [Set.XY.Offset.zip](https://github.com/ghzserg/FF/releases/download/R/Set.XY.Offset.zip) herunter und entpacken Sie es in das Stammverzeichnis des Flash-Laufwerks
2. Stecken Sie den USB-Stick in den ausgeschalteten Drucker und schalten Sie ihn ein.
Die Kalibrierungsschnittstelle wird auf dem Bildschirm des Druckers angezeigt. Sie müssen auf Reset drücken.
4. Verwenden Sie die Steuerpfeile, um den Druckkopf so am Empfänger zu parken, dass der Druckkopf genügend Druck auf den Verschlusshebel ausübt, die Düse hinter dem beweglichen Verschluss liegt und der Verschluss selbst mit der Vorderseite des Empfängers bündig ist.
5. Sichern Sie das Kalibrierungsergebnis mit der Set-Taste.
6. Entfernen Sie den Speicherstick und starten Sie den Drucker neu.

---

## Aktualisieren Sie die Mod

Wenn der Mod sagt `Update zMOD vom Flash-Laufwerk`, müssen Sie zMod vom Flash-Laufwerk aktualisieren, auch wenn Sie es kürzlich aktualisiert haben.

**Wenn Sie von einem USB-Stick aktualisieren, werden alle Daten gespeichert.**

**Der einfachste Weg, zMod von einem USB-Stick zu aktualisieren, ist die Verwendung des Makros [ZFLASH](/de/Zmod/#zflash)**.

In diesem Fall müssen Sie den USB-Stick in den Drucker stecken, den Drucker neu starten und das Makro "ZFLASH" aufrufen.

- Das Makro sucht nach der letzten aktuellen Version
- Laden Sie die neueste Version für Ihr Druckermodell herunter
- Überprüft die Prüfsummen
- Neustart des Druckers
- Die neue Version wird nach dem Neustart automatisch installiert (der USB-Stick muss nicht entfernt werden, Sie können ihn für künftige Aktualisierungen im Drucker belassen).
- Gehen Sie dann auf die Registerkarte "Einstellungen" -> "Software-Update". Klicken Sie auf "Nach Updates suchen" und installieren Sie die neuesten "ZMOD"-Updates.

<img width="1239" height="535" alt="image" src="https://github.com/user-attachments/assets/b42c4ce9-1c0a-45c0-a20c-36919a27d648" />

Wenn es viele Fehler anzeigt, ist das normal.

Denn die Plugins sind nicht Teil der Firmware und werden separat heruntergeladen.

Sie müssen auf "Nach Updates suchen" klicken. Und die Plug-ins nacheinander wiederherstellen und aktualisieren. Der Drucker wird neu gestartet.

<img width="671" height="223" alt="image" src="https://github.com/user-attachments/assets/5744dc8e-ba58-4359-b78a-652be846ca07" />

Sie können die aktuelle Version des Betriebssystems des Mods unter der Registerkarte "System" -> "Verteilung" einsehen

Die aktuelle Version von zMod (Registerkarte "Einstellungen" -> "Update" -> "ffm5/zmod"), **muss** in den ersten beiden Ziffern mit der Version auf der Registerkarte "System" übereinstimmen.

<u>Wenn sie nicht übereinstimmen, wird die Mod **nicht richtig funktionieren**, in diesem Fall beschweren Sie sich nicht über ZMOD</u>.

Update über USB-Stick:

1. den USB-Stick auf FAT/FAT16/FAT32 formatieren
2. Legen Sie [file](https://github.com/ghzserg/zmod/releases/) in den Stammordner des USB-Sticks.

    - für FF5M: Adventurer5M-**zmod**-\*.tgz
    - für FF5MPro: Adventurer5MPro-**zmod**-\*.tgz
    - für AD5X: AD5X-**zmod**-\*.tgz

3. Schalten Sie den Drucker aus
4. Stecken Sie den USB-Stick in den Drucker
5. Schalten Sie den Drucker ein
6. Warten Sie den Neustart des Druckers ab (entfernen Sie den USB-Stick nicht)
7. Warten Sie auf die Installation des Mods
8. Wenn der Drucker schreibt, dass die Installation abgeschlossen ist
9. Ziehen Sie den USB-Stick heraus
10. Schalten Sie den Drucker aus
11. Schalten Sie den Drucker ein
12. Gehen Sie in Fluidd/Mainsail auf die Registerkarte `Einstellungen` -> `Software-Update`. Klicken Sie auf "Nach Updates suchen" und installieren Sie die neuesten "ZMOD"-Updates.

---

## Hilfe Entwicklung

[SBP, Bankkarte, T-pay](https://pay.cloudtips.ru/p/3cbf9e9f)

<img width="262" height="262" alt="qrCode" src="https://github.com/user-attachments/assets/e7c1ebf3-3a54-4b46-b071-06656ac06ae1" />

BTC `17wXTd9BqYp1K3zCLTxVyGLEXUDjf7XNLL`.

---

## Löschen - vorübergehende Deaktivierung der Mod

- [SKIP_ZMOD](/de/Zmod/#skip_zmod) - Makro zum Neustart ohne Moonraker und Fluidd zu starten
- [REMOVE_ZMOD](/de/Zmod/#remove_zmod) - Makro zum Entfernen von Mods

Es wird empfohlen, **den Mod über das Makro `REMOVE_ZMOD`** zu entfernen, die Entfernung über ein Flash-Laufwerk nur zu verwenden, wenn es keine Möglichkeit gibt, das Makro auszuführen.

Achtung!

- Wenn Sie Klipper 13 benutzen, ist es notwendig, ```UPDATE_MCU``` auszuführen. Dadurch wird die Situation vermieden, dass MCU und Klipper unterschiedliche Versionen haben.
- Wenn Sie Plug-Ins aktiviert haben, müssen Sie diese zuerst deaktivieren ````DISABLE_PLUGIN name=g28_tenz````.

Entfernen Sie die Mod komplett ```REMOVE_ZMOD FULL=1```.

Deinstallation des Mods über ein Flash-Laufwerk:

- Formatiere das Flash-Laufwerk auf FAT/FAT16/FAT32
- Kopiere die Datei [flashforge_init.sh](https://github.com/ghzserg/zmod/blob/main/Native_firmware/rem_zmod/flashforge_init.sh) auf einen USB-Stick
- Schalten Sie den Drucker aus
- Stecken Sie den USB-Stick in den Drucker
- Schalten Sie den Drucker ein
- Der Drucker wird 3 Mal neu starten
- Entfernen Sie das Flash-Laufwerk und verwenden Sie die Standard-Firmware

---

## Wie aktualisiere ich die Standard-Firmware?

1. deaktivieren Sie alle aktiven Plugins außer recommend, timelamse, notify (```DISABLE_PLUGIN name=plugin_name```).
2. Wenn Sie **Klipper 13** benutzen, sollten Sie ```UPDATE_MCU``` durchführen, bevor Sie die native Firmware aktualisieren. Dadurch wird die Situation vermieden, dass MCU und Klipper unterschiedliche Versionen sind.
3. Aktivieren Sie die chinesische Wolke, wenn Sie das Update vom nativen Bildschirm aus durchführen wollen ```SAVE_ZMOD_DATA CHINA_CLOUD=1```.

Wenn der native Bildschirm das Update nicht findet:

- Ihre Seriennummer wurde noch nicht von der Update-Verteilung getroffen
- [Installieren Sie das native Firmware-Update von einem USB-Stick](/de/Native_FW/)

**Für [AD5X](/de/AD5X/) erfordert [Aktivieren Sie zMod](/de/Native_FW/) über `AD5X-ENABLE-zmod.tgz` von einem USB-Stick, nach dem Stock-Update**.

---

## Boot wiederherstellen

Autoren der Anleitungen: [@darksimpson](https://t.me/darksimpson), [Alexander](https://github.com/DrA1ex), [@Ikaros413](https://t.me/Ikaros413), [@SoloMen88](https://t.me/SoloMen88)

Für diejenigen, die einen Drucker haben, der beim Einschalten im Bildschirmschoner hängen bleibt und nicht per LAN-Kabel erreichbar ist.

![](../images/ff.jpg)

Versuchen Sie, die Firmware über eine vollständige Firmware-Installation wiederherzustellen:

- [FF5M](/de/Native_FW/#Vollständige-Firmware-auf-ff5m-installieren)
- [AD5X](/de/Native_FW/#Vollständige-Firmware-auf-Ad5x-installieren)

Wiederherstellungs-Algorithmus:

1. **Schalten Sie den Drucker aus**
2. UART/USB-Konverter vorbereiten (3,3V- oder 5V/3,3V-Jumper erforderlich)

![](../images/ch340.jpg)

**WARNUNG!** Der Konverter muss mit 3,3 Volt betrieben werden, bei 5 Volt brennt der Prozessor durch!

3. Öffnen Sie die Rückseite des FlashForge.
4. Verbinde mit dem UART-Pin auf der Platine (RX, TX, GND, **3.3V nicht anschließen**).

![](../images/connect.jpg)

Sie MÜSSEN den Jumper (wenn Sie einen haben) von 5V auf 3,3V umstecken. Wenn Sie auf 5V anschließen, müssen Sie die Hauptplatine ersetzen.
So sollte der Anschluss am Ende aussehen:

- RX/TX sind kreuzweise verbunden RX-TX TX-RX
- GND des Konverters mit GND auf der Platine
- 3.3V ist nirgends angeschlossen

![](../images/connect_photo.jpg)

5. Ein neuer COM-Anschluss sollte auf dem System erscheinen.

![](../images/port.jpg)

6. Starten Sie das Programm [PuTTY](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html), geben Sie dort Ihren COM-Port ein (im obigen Beispiel COM6), Geschwindigkeit `115200`, Verbindungstyp - `Seriell`.

7. Schließen Sie den Drucker an die normale Stromversorgung an.

8. Warten Sie im Terminal auf die Zeile:
```
Drücken Sie eine beliebige Taste, um den Autoboot zu stoppen
```
Drücken Sie dann schnell `Enter`.

9. Dies wird Sie zu `U-Boot` bringen. Sie koennen dort eine Menge Dinge tun (schreiben Sie `Hilfe`)

Aber wir müssen nur den Startbefehl für den Linux-Kernel überschreiben, um die Shell zu bekommen.

Wir schreiben in U-Boot über das Terminal:

```
setenv init /bin/sh
booten
```

10. Wenn Sie alles richtig gemacht haben, werden Sie nach dem Booten des Linux-Kernels `sh` erhalten.

11. Das Dateisystem ist im Nur-Lese-Modus eingehängt, also müssen Sie es neu einhängen:

```
mount -t proc proc /proc
mount -o remount,rw /
```

12. Reparieren Sie, was kaputt ist, z.B. `rm -f /etc/init.d/S01bad_script`, oder `rm -f /opt/config/mod/.shell/S98camera`, wenn Sie keinen Start wegen der Kamera bekommen.

13. Sie müssen die Änderungen speichern: ```Sync```.

14. Und neu starten: ```reboot```.

