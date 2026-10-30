---
hide:

  - navigation
---

# FF5M / FF5M Pro / AD5X / Creator 5 / Creator 5 Pro Z-Mod

<img width="660" height="263" alt="Logo" src="../../images/2befbddc-c055-4006-9864-90ab3b182512.png" />

[Z-Mod LINK ist unter diesem Link verfügbar ->](https://zmod.link/link/)

### **Z-Mod für FlashForge AD5M/AD5M PRO/AD5X/Creator 5/Creator 5 Pro: Volle Kontrolle über Ihren Drucker**

Herzlichen Glückwunsch zum Kauf eines FlashForge Druckers! Die native Firmware eignet sich hervorragend für den Einstieg, aber wenn Sie das **volle Potenzial** Ihres Geräts ausschöpfen möchten, ist Z-Mod eine leistungsstarke und kostenlose Lösung, die Ihren Drucker vom „Haushaltsgerät“ zum „Profiwerkzeug“ macht.

### Was ist Z-Mod?

Z-Mod ist eine inoffizielle Firmware-Erweiterung (Modifikation), die zusätzlich zur Originalsoftware installiert wird. Sie ersetzt sie nicht, sondern **erweitert** sie, indem sie eine große Anzahl von Funktionen hinzufügt, die von fortgeschrittenen Druckern bekannt sind, während sie alle Vorteile und den Komfort der nativen Schnittstelle beibehält.

*Z-Mod: Qui non legit, non intrat*

> **Warum „Z-Mod“?** Der Autor ist seit über 20 Jahren unter dem Nicknamen [zserg](https://zserg.ru/) bekannt. Als es Zeit war, dem Mod einen Namen zu geben, lag die Antwort auf der Hand: erster Buchstabe des Nicknamens plus „mod". Kein versteckter Sinn, keine Symbolik — es ist wirklich genau so einfach, wie es klingt.

### Hauptvorteile von Z-Mod gegenüber nativer Firmware

Das erhalten Sie, wenn Sie Z-Mod installieren:

#### 1. Volle Fernsteuerung

* **Native Firmware:** Sie können Dateien über WLAN senden, aber nur über Orca FF oder die FlashForge-App (die aufgrund von Serverproblemen möglicherweise nicht verfügbar ist).
* **Z-Mod:** Sie haben die volle Kontrolle auf all Ihren Geräten – **egal ob im Browser, auf dem Computer oder dem Smartphone** – und können auch andere Slicer wie OrcaSlicer nutzen.

    - **Fluidd / Mainsail:** Benutzerfreundliche Weboberflächen, mit allen Druckinformationen, Temperaturen, Lüftersteuerung, Achsbewegung und vollem Zugriff auf die Befehlskonsole.
    - **Dateiversand über "Octo/Klipper":** Integration mit Orca Slicer und anderen Slicern für den direkten G-Code-Versand.
    - **Zugriff auf die Weboberfläche des Druckers über das Internet:** Cloud-Dienst [zmod.link](https://zmod.link)
    - **Benachrichtigungen in Telegram und über 100 anderen Diensten:** [Plugin notify](https://github.com/ghzserg/notify/blob/main/Readme.md)

#### 2. Erweiterte Kalibrierungs- und Nivellierungssysteme

* **Native Firmware:** Einfache automatische Druckbettnivellierung (ABL).
* **Z-Mod:**

    - **Adaptive Nivellierung (KAMP):** Der Drucker misst die Unebenheiten des Bettes nicht über die gesamte Fläche, sondern nur in dem Bereich, in dem sich Ihr Modell befindet. Das **spart Zeit** und verbessert die Genauigkeit.
    - **PID-Kalibrierung:** Feinabstimmung der Temperaturregelung von Extruder und Druckbett für stabile Temperaturen ohne Schwankungen.
    - **Vibrationsreduzierer (Input Shaper):** Analysiert und kompensiert Rahmenschwingungen, sodass Sie **schneller und ohne „Ringing“** drucken können.
    - **Riemen-Spektrogramm:** Analysiert den Zustand der Riemen für eine vorbeugende Wartung.
    - **Bettschraubenjustierung:** Ermöglicht es Ihnen, das Druckbett in 10 Minuten zu nivellieren.

#### 3. Intelligente Funktionen für Zuverlässigkeit

* **Native Firmware:** Einfache Filamentsensoren. Keine Kontrolle über die Integrität der Firmware und der übertragenen Dateien – was zu Druckfehlern führt.
* **Z-Mod:**

    - **Düsenkontrolle:** Das System kann mit Hilfe von Wägezellen erkennen, dass die Düse ein gedrucktes Teil oder das Bett berührt hat, und den Druck **automatisch stoppen**, um Bruch zu verhindern.
    - **Wiederherstellung nach Stromausfall:** Der Drucker merkt sich die Position beim Stromausfall und kann nach dem Wiedereinschalten weiterdrucken.
    - **Firmware-Integritätsprüfung:** Überprüft sowohl die Original-Firmware als auch Z-Mod-Dateien auf Beschädigungen.
    - **Kontrolle der an den Drucker übertragenen Dateien:** Prüfung der MD5-Summe bei der Übertragung.

#### 4. Flexible Handhabung von Filamenten (speziell für AD5X)

* **Native Firmware:** Spulensteuerung über Standardmenü.
* **Z-Mod (für AD5X):**

    - **Intelligentes Farbmenü (`COLOR`):** Visuelle Auswahl von Spule, Farbe und Kunststofftyp direkt über die Weboberfläche.
    - **„Endlosspulen“-Modus:** Wenn Sie mehrere Spulen desselben Kunststoffs haben, wechselt der Drucker automatisch zur nächsten, wenn die erste leer ist.
    - **Feineinstellung des Abfalls:** Sie können die Menge an Kunststoff, die der Drucker beim Farbwechsel ausspült, reduzieren und so Material sparen.

#### 5. Ökosystem und Integration

* **Native Firmware:** Geschlossenes System.
* **Z-Mod:**

    - **Telegram-Bot:** Erhalten Sie Benachrichtigungen über den Beginn und das Ende des Drucks, Fotos von der Kamera direkt in Telegram.
    - **Plugin-Unterstützung:** Installieren Sie zusätzliche Plugins (wie `bambufy` für eine bessere Kompatibilität mit Bambu Studio).
    - **Alternative Kamera:** Passen Sie die Auflösung und die FPS an und reduzieren Sie die Speicherbelastung für stabiles Streaming.
    - **Musikwiedergabe:** Spielt Musik zu Beginn oder am Ende des Drucks.

#### 6. Optimierung und Kontrolle

* **Native Firmware:** Eingeschränkte Einstellungen.
* **Z-Mod:**

    - **Deaktivieren des nativen Bildschirms:** Um RAM zu sparen (relevant für AD5M-Modelle mit 128 MB).
    - **GuppyScreen:** Eine alternative Oberfläche für den Druckerbildschirm mit erweiterten Funktionen.
    - **HelixScreen:** Eine weitere alternative Oberfläche für den Druckerbildschirm mit erweiterten Funktionen.
    - **Log Viewer:** Vollständige Informationen über alle Prozesse, um Probleme zu diagnostizieren.
    - **Firmware-Retraktion:** Retraktionsparameter können im laufenden Betrieb angepasst werden, ein erneutes Slicen ist nicht erforderlich.
    - **Voller ROOT-Zugriff:** Voller Zugriff auf den Drucker jederzeit.

#### 7. Klipper 13

* **Native Firmware:** AD5M verwendet den veralteten Klipper 11, der viele Fehler aufweist (E0011, E0017, falscher Objektausschluss, falscher SCV, falsche Druckwiederherstellung usw.).
* **Z-Mod:**
  
    - Behebt Fehler im nativen Klipper und ermöglicht die Verwendung einer moderneren Version.

---

### Fazit: Für wen ist Z-Mod?

| Wenn Sie … sind | Z-Mod gibt Ihnen … |
| :--- | :--- |
| **Einsteiger** | Einfache Fernsteuerung und automatische Kalibrierungen für gleichbleibende Qualität gleich beim ersten Mal. |
| **Enthusiast** | Volle Kontrolle über jeden Aspekt des Drucks, mit erweiterten Funktionen für die Feinabstimmung und das Experimentieren mit der Geschwindigkeit. |
| **AD5X-Besitzer** | Die ultimative Kontrolle über den Mehrfarbendruck und reduzierte Filamentkosten. |

**Z-Mod ersetzt die native Firmware nicht,** sondern ist eine Erweiterung, die Ihnen die **Wahl** lässt: wie gewohnt über den Bildschirm zu arbeiten oder alle modernen 3D-Druck-Werkzeuge zu nutzen. Dies ist der nächste logische Schritt für jeden FlashForge-Besitzer, der das Beste aus seinem Drucker herausholen möchte.

!!! danger
    *Wenn Sie diesen Mod auf Ihrem AD5M (Pro) / [AD5X](/de/AD5X/) installieren wollen, beachten Sie bitte, dass Sie den Verlust Ihrer Garantie oder eine Beschädigung Ihres Druckers **riskieren**. Es geschieht auf eigene Gefahr, wenn Sie diesen Mod ausprobieren wollen!
    
    Wenn Sie nicht wissen, was das ist, nicht verstehen, wozu Sie die Klipper-Weboberfläche brauchen, oder einfach mit der Standardversion zufrieden sind, installieren Sie diesen Mod nicht. Für alle anderen — **bitte lesen Sie die Anleitung vollständig**!
    
    Sie haben den Mod installiert und wollen sich mit nichts beschäftigen — drucken Sie wie bisher. Sie müssen überhaupt nichts einstellen oder ändern. Wenn Sie bereit sind, weiterzugehen, — lesen Sie die [Dokumentation](/de/SetupCalibrations/).

## Bevor Sie beginnen

#### Sie brauchen den Mod nicht zu installieren, wenn Sie nur die folgenden Probleme der nativen Firmware beheben möchten

Diese Funktionen sind auf die Standard-Firmware portiert:

1. Ich möchte Klipper. (Klipper ist bereits im Drucker vorhanden, aber es gibt keine Weboberfläche)
2. [Root installieren](/de/Native_FW/#root)
3. Fehler beheben [E0011](/de/Global/#fix_e0011)
4. Fehler beheben [E0017](/de/Global/#fix_e0017)
5. [Druckerupdates/Telemetrie/chinesische Cloud deaktivieren](/de/Global/#china_cloud)
6. [Drucker auf Werkseinstellungen zurücksetzen](/de/Setup/#drucker-auf-werkseinstellungen-zurücksetzen-erforderlich-für-die-installation-des-mods)
7. [FF5M zu FF5MPro neu flashen](/de/Native_FW/#5m-zu-5mpro-konvertieren)
8. [FF5MPro zu FF5M](/de/Native_FW/#5mpro-zu-5m-konvertieren)

### Kompatibilität
Wird auf einer sauberen Firmware-Version installiert:

- FF5M/FF5MPro **mindestens 2.7.5** (2.7.5, 2.7.6, 2.7.7, 2.7.8, 2.7.9, 3.1.3, 3.1.4, 3.1.5, 3.1.9, **3.2.3**, 3.2.4, 3.2.5, 3.2.6, 3.2.7, 5.0.3, 5.1.7, 5.1.9)
- [AD5X](/de/AD5X/) **nur** (1.0.2, 1.0.7, 1.0.8, 1.0.9, 1.1.1, 1.1.6, **1.1.7**, 1.1.9, 1.2.0, 1.2.1, 1.2.2, 1.2.3, 3.0.3, 3.0.9, 3.1.0, 3.1.5, 3.1.6, 3.1.7) _beliebige IFS-Version_
- [Creator 5/Creator 5 Pro](/de/C5PRO/) **nur** (1.9.9, 2.0.0).

Native Firmware ist [hier](/de/Native_FW/) verfügbar.

## Mod installieren/aktualisieren/deinstallieren

[Mod installieren/aktualisieren/deinstallieren](/de/Setup/)
 
## Häufig gestellte Fragen

[Unbedingt lesen](/de/FAQ/)

## Empfehlungen zur Verbesserung der Druckerstabilität

[Lesen, wenn etwas nicht richtig funktioniert](/de/Recommendations/)

## Plugins

Z-Mod unterstützt [Plugins](/de/Plugin/)

## Verwendete Erweiterungen

- Root basiert auf der Implementierung von [@darksimpson](https://t.me/darksimpson). Login und Passwort: root. [Link](https://t.me/c/2000598629/12695/186253)
- Beeper basiert auf der Implementierung von [@drmax_gc](https://t.me/drmax_gc). M300. M356 Für Elise. [Link](https://t.me/FF_5M_5M_Pro/1/333800)
- MD5-Prüfung von Igor Polunovskiy. [Link](https://t.me/FF_5M_5M_Pro/12695/272417)
- [GuppyScreen](https://github.com/ballaswag/guppyscreen)

Der Mod verwendet Entwicklungen von [KlipperMod](https://github.com/xblax/flashforge_ad5m_klipper_mod/), ist jedoch keine Weiterentwicklung davon und auch nicht mit ihm kompatibel — weder in der Makrosyntax noch binär.

## Unterstützung der Entwicklung

Da einige Leute danach gefragt haben, nehme ich Spenden an, aber bitte denken Sie daran, dass ich an Z-Mod zum Spaß arbeite, nicht für Geld. Ich werde keine Spenden annehmen, um an bestimmten Fehlern oder Funktionen zu arbeiten.

Die Möglichkeiten zur Unterstützung finden Sie auf einer separaten [Seite](/de/Sponsor/)
