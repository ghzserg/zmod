---
hide:
  - navigation
---

# FF5M / FF5M Pro / AD5X ZMOD

<img width="698" height="291" alt="logo zmod" src="https://github.com/user-attachments/assets/5e26413b-c9a2-49f2-b9b8-5ecde709c521" />

[zMod LINK verfügbar unter diesem Link ->](https://zmod.link/link/)

### **ZMOD für FlashForge AD5M/PRO/AD5X: Volle Kontrolle über Ihren Drucker**

Herzlichen Glückwunsch zum Kauf eines FlashForge Druckers! Die native Firmware eignet sich hervorragend für den Einstieg, aber wenn Sie das **volle Potenzial** Ihres Geräts ausschöpfen möchten, ist ZMOD eine leistungsstarke und kostenlose Lösung, die Ihren Drucker von "benutzerdefiniert" auf "professionell" umstellt.

**Was ist ZMOD?**
ZMOD ist eine benutzerdefinierte Firmware (Modifikation), die zusätzlich zur Originalsoftware installiert wird. Sie ersetzt sie nicht, sondern **erweitert** sie, indem sie eine große Anzahl von Funktionen hinzufügt, die von fortgeschrittenen Druckern bekannt sind, während sie alle Vorteile und den Komfort der nativen Schnittstelle beibehält.

---

### **Hauptvorteile von ZMOD gegenüber nativer Firmware**

Das erhalten Sie, wenn Sie ZMOD installieren:

#### **1. Volle Fernsteuerung**

* **Native Firmware:** Sie können Dateien über Wi-Fi senden, aber nur über Orca FF oder die FlashForge-App (die aufgrund von Serverproblemen möglicherweise nicht verfügbar ist).
* **ZMOD:** Sie haben die volle Kontrolle auf all Ihren Geräten – **egal ob im Browser, auf dem Computer oder dem Smartphone** – und können dort auch andere Slicer wie den OrcaSlicer nutzen.

    - **Fluidd / Mainsail:** Benutzerfreundliche Weboberflächen, auf denen Sie alle Druckinformationen, die Temperatur, die Steuerung der Lüftergeschwindigkeiten, das Bewegen der Achsen und vollen Zugriff auf die Befehlskonsole sehen.
    - **Dateiversand über "Octo/Klipper":** Integration mit Orca Slicer und anderen Slicern für den direkten G-Code-Versand.
    - **Zugang zum Drucker-Webinterface über Internet** Cloud-Service [zmod.link](https://zmod.link)
    - **Benachrichtigung an Telegram und 100+ andere Dienste** [plugin notify](https://github.com/ghzserg/notify/blob/main/Readme_ru.md)

#### **2. Erweiterte Kalibrierungs- und Nivellierungssysteme**

* **Native Firmware:** Einfache automatische Druckbettnivellierung (ABL).
* **ZMOD:**

    - **Adaptive Nivellierung (KAMP):** Der Drucker erstellt keine Karte der Bedunregelmäßigkeiten über die gesamte Fläche, sondern nur in dem Bereich, in dem sich Ihr Modell befindet. Das **spart Zeit** und verbessert die Genauigkeit.
    - **PID-Kalibrierung:** Feineinstellung der Extruder- und Druckbetttemperatur für stabile Temperaturen ohne Schwankungen.
    - **Vibrationsreduzierer (Input Shaper):** Analysiert und kompensiert Körperschwingungen, so dass Sie **schneller und ohne "Ringe "** an Modellen drucken können.
    - **Band-Spektrogramm:** Analysiert den Zustand der Druckerbänder für eine vorbeugende Wartung.
    - **Tischschraubenjustierung:** Ermöglicht es Ihnen, das Druckbett in 10 Minuten zu nivellieren.

#### **3. Intelligente Funktionen für Zuverlässigkeit**

* **Firmware:** Einfache Sensoren für den Filamentabschluss. Keine Kontrolle über die Firmware und die übertragenen Dateien - was zu Druckfehlern führt.
* **ZMOD:**

    - **Düsenkontrolle:** Das System kann mit Hilfe von Kraftmesszellen erkennen, dass die Düse ein gedrucktes Teil oder einen Tisch berührt hat, und den Druck **automatisch stoppen**, um Bruch zu verhindern.
    - **Wiederherstellung nach Stromausfall:** Der Drucker merkt sich den Ort des Stromausfalls und kann nach dem Wiedereinschalten des Stroms weiterdrucken.
    - **Firmware-Integritätsprüfung:** Überprüft sowohl die Original-Firmware als auch ZMOD-Dateien auf Beschädigungen..
    - **Kontrolle der an den Drucker übertragenen Dateien:** MD5-Summenkontrolle bei der Übertragung von Dateien.

#### **4. Flexible Handhabung von Filamenten (speziell für AD5X)**

* **Native Firmware:** Spulensteuerung über Standardmenü.
* **ZMOD (für AD5X):**

    - **Smart Colour Menu (`COLOR`):** Visuelle Auswahl von Spule, Farbwechsel und Kunststofftyp direkt über das Webinterface.
    - **"Endlosspulenmodus":** Wenn Sie mehrere Spulen desselben Kunststoffs haben, wechselt der Drucker automatisch zur nächsten, wenn die erste leer ist.
    - **Feinabfall-Einstellung:** Sie können die Menge an Kunststoff, die der Drucker beim Farbwechsel ausspült, reduzieren und so Material sparen.

#### **5. Ökosystem und Integration**

* **Native Firmware:** Geschlossenes System.
* **ZMOD:**

    - **Telegram-Bot:** Erhalten Sie Benachrichtigungen über den Beginn und das Ende des Drucks, Fotos von der Kamera direkt in Telegram.
    - **Plugin-Unterstützung:** Installieren Sie zusätzliche Plugins (wie `bambufy` für eine bessere Kompatibilität mit Bambu Studio).
    - **Alternative Kamera:** Passen Sie die Auflösung und die FPS an und reduzieren Sie die Speicherbelastung für stabiles Streaming.
    - **Musikwiedergabe:** Spielt Musik, wenn der Druck beginnt oder endet

#### **6. Optimierung und Kontrolle**

* **Native Firmware:** Eingeschränkte Einstellungen.
* **ZMOD:**

    - **Deaktivieren des nativen Bildschirms:** Um RAM zu sparen (relevant für AD5M-Modelle mit 128MB).
    - **GuppyScreen:** Eine alternative Schnittstelle für den Druckerbildschirm mit erweiterten Funktionen.
    - **Log Viewer:** Vollständige Informationen über alle Prozesse, um Probleme zu diagnostizieren.
    - **Firmware-Retraktion:** Retraktionsparameter können im laufenden Betrieb angepasst werden, ein erneutes Slicing ist nicht erforderlich..
    - **Voller ROOT-Zugriff:** Voller Zugriff auf den Drucker ist jederzeit möglich

#### **7. Klipper 13**

* **Native Firmware:** AD5M verwendet den veralteten Klipper 11, der viele Fehler aufweist (E0011, E0017, falscher Objektausschluss, falscher SCV, falsche Druckwiederherstellung usw.).
* **ZMOD:**
  
    - Behebt Fehler im nativen Klipper und ermöglicht die Verwendung einer moderneren Version

---

### **Résumé: Für wen ist ZMOD?**

| Wenn Sie... | ZMOD wird Ihnen... |
| :--- | :--- |
| **Neueinsteiger** | Einfache Fernsteuerung und automatische Kalibrierungen für gleichbleibende Qualität "gleich beim ersten Mal". | |
| **Ethusiast** | Volle Kontrolle über jeden Aspekt des Drucks, mit erweiterten Funktionen für die Feinabstimmung und das Experimentieren mit der Geschwindigkeit. | **Enthusiast** |
| **Ad5X-Besitzer** | Die ultimative Kontrolle über den Mehrfarbendruck und reduzierte Filamentkosten. | |

**ZMOD setzt die native Firmware nicht außer Kraft,** sondern wird zu einem Add-on, das Ihnen die **Wahl** gibt, auf die alte Art zu arbeiten, über den Bildschirm, oder alle modernen 3D-Druck-Tools zu nutzen. Dies ist der nächste logische Schritt für jeden FlashForge-Besitzer, der das Beste aus seinem Drucker herausholen möchte.

!!! Gefahr
    *Wenn Sie diesen Mod auf Ihrem AD5M (Pro) / [AD5X](/de/AD5X/) installieren wollen, beachten Sie bitte, dass Sie den Verlust Ihrer Garantie oder eine Beschädigung Ihres Druckers **riskieren**. Es geschieht auf eigene Gefahr, wenn Sie diesen Mod ausprobieren wollen!
    
    Wenn du nicht weißt, was das ist, nicht verstehst, warum du die Klipper-Webseite brauchst oder einfach nur mit der Standardversion zufrieden bist, installiere diesen Mod nicht, für alle anderen - **bitte lies die vollständige Anleitung**!
    
    Du hast den Mod installiert. Sie wollen nichts verstehen - Sie drucken, wie Sie es getan haben. Sie müssen überhaupt nichts anpassen oder ändern. Sie haben beschlossen, dass Sie bereit sind, weiterzumachen - Sie machen weiter - indem Sie die [Dokumentation](https://ghzserg.github.io/) lesen.

## Bevor Sie beginnen

#### Sie brauchen den Mod nicht zu installieren, wenn Sie nur die folgenden Probleme mit der nativen Firmware beheben müssen

Diese Funktionen sind auf die Standard-Firmware portiert:

1. Ich möchte Klipper. (Klipper ist bereits im Drucker vorhanden, aber es gibt keine Web-Schnittstelle)
2. [Root installieren](/de/Native_FW/#root)
3. Fehler beheben [E0011](/de/Global/#fix_e0011)
4. behebt Fehler [E0017](/de/Global/#fix_e0017)
5. [Deaktivieren von Drucker/Telemetrie/China_cloud-Updates](/de/Global/#china_cloud)
6. [Drucker auf Werkseinstellungen zurücksetzen](/de/Setup/#return-printer-to-factory-settings-needed-for-installation-mod)
7. [FF5M zu FF5MPro neu flashen](/de/Native_FW/#re-flash-5m-to-5mpro)
8. [FF5MPro zu FF5M](/de/Native_FW/#übersetzen-5mpro-zu-5m)



### Kompatibilität
Installiert auf einer sauberen Version:

- FF5M/FF5MPro **mindestens 2.7.5** (2.7.5, 2.7.6, 2.7.7, 2.7.8, 2.7.9, 3.1.3, 3.1.4, 3.1.5, 3.1.9, **3.2.3**, 3.2.4, 3.2.5, 3.2.6, 3.2.7, 5.0.3)
- [AD5X](/de/AD5X/) **nur** (1.0.2, 1.0.7, 1.0.8, 1.0.9, 1.1.1, 1.1.6, **1.1.7**, 1.1.9, 1.2.0, 1.2.1, 1.2.2, 1.2.3, 3.0.3)

Native Firmware ist [hier](/de/Native_FW/) verfügbar.

## Mods installieren/aktualisieren/deinstallieren

[Mods installieren/aktualisieren/deinstallieren](/de/Setup/)
 
## Häufig gestellte Fragen

[Muss man lesen](/de/FAQ/)

## Empfehlungen zur Verbesserung der Druckerstabilität

[Lesen - wenn etwas nicht richtig funktioniert](/de/Recomendations/)

## Plug-ins

zMod unterstützt [Plugins](/de/Plugin/)

## Hilfe zur Entwicklung

Da einige Leute danach gefragt haben, nehme ich Spenden an, aber bitte denken Sie daran, dass ich an zMod zum Spaß arbeite, nicht für Geld. Ich werde keine Spenden annehmen, um an bestimmten Fehlern oder Funktionen zu arbeiten.

Verfügbare Möglichkeiten zur Unterstützung finden sich auf einer separaten [Seite](/de/Sponsor/)
