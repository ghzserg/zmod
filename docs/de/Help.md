# So kontaktieren Sie den Entwickler-Support

Öffnen Sie den Telegram-Bot [@zmod_help_bot](http://t.me/zmod_help_bot) und stellen Sie ihm Ihre Frage — er kennt die gesamte Dokumentation.

1. [Aktualisieren Sie Z-Mod und alle Plugins auf die neueste Version](/de/Setup/#aktualisieren-sie-den-mod)
2. Beschreiben Sie das Problem deutlich: Screenshots, Fotos, Textbeschreibung.
3. Rufen Sie [CLEAR_EMMC](/de/System/#clear_emmc) auf, um die Logs zu löschen
4. **Schalten Sie den Drucker aus**
5. Schalten Sie den Drucker ein
6. Reproduzieren Sie das Problem
7. Führen Sie [TAR_CONFIG](/de/Zmod/#tar_config) aus, um die Logdateien zu speichern
8. Veröffentlichen Sie **eine** Nachricht mit der Beschreibung und der Datei `config-1.6.6-28.tar.gz`, wobei 1.6.6-28 die aktuelle Version des Mods ist.
9. [Fehlermeldung hinzufügen](https://github.com/ghzserg/zmod/issues)

Falls `TAR_CONFIG` nicht ausgeführt werden kann:

- Laden Sie [log](/de/Native_FW/#log) herunter
- Kopieren Sie `config-1.6.6-28.tar.gz` vom USB-Stick, wobei 1.6.6-28 die aktuelle Version des Mods ist

Oder verbinden Sie sich per SSH mit dem Drucker:

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

**[Ticket erstellen](https://github.com/ghzserg/zmod/issues)**

## Warum ich Sie bitte, Tickets zu erstellen – einfach erklärt

Stellen Sie sich vor, Ihr Drucker ist ein Auto.
Und ich bin ein Mechaniker in einer großen Werkstatt, in der ich jeden Tag Hunderte verschiedener Autos repariere.

Sie fahren vor und rufen:
> "Mein Auto fährt nicht mehr!"

Und ich muss mit einer einfachen Frage beginnen:
> "Was für ein Auto haben Sie - Marke, Modell, Baujahr?"

### Warum es wichtig ist, alles Stück für Stück aufzuschlüsseln

Unsere "Flotte" hat **über 100 verschiedene Konfigurationen**. Nur die Grundlagen:

- **5 verschiedene Druckermodelle**:

  FF5M, FF5M Pro, AD5X, C5, C5Pro

- **3 Versionen des "Motors" (Klipper)**:

  11, 12, 13

- **2 Prozessorarchitekturen**:

  ARM und MIPS

- **Anzeigeoptionen („Innenausstattung“)**:

    - mit nativem Bildschirm
    - mit GuppyScreen
    - mit HelixScreen
    - kein Bildschirm

- **Zwei Hauptsteuerungsschnittstellen**:

  Fluidd und Mainsail

- **Unterschiedliche Möglichkeiten, Aufgaben zum Drucker zu senden**:

  über den nativen Bildschirm, GuppyScreen, HelixScreen, OrcaSlicer (FF-Protokoll, Klipper-Protokoll, usw.)

- **Zusätzliche "Optionen" (Plugins)**:

  `nopoop`, `recommend`, `bambufy`, `g28_tenz`, `timelapse`, `notify` und andere

- **Sensoren und Peripheriegeräte**:

  Filamentsensor, Bewegungssensor, IFS usw.

Darüber hinaus kommt es vor, dass einige Benutzer **selbst Hardware modifizieren**, veraltete Firmware installieren oder Ratschläge aus Foren oder von KI-Modellen befolgen, die **ihren spezifischen Drucker noch nie gesehen haben**.

#### Unterm Strich

Wenn Sie nur **"funktioniert nicht"** schreiben, verbringe ich **Stunden** damit, herauszufinden:

- Welches Modell haben Sie?
- Welche Firmware/Version von Klipper?
- Mit oder ohne Bildschirm?
- Welcher Slicer und welche Einstellungen?
- Welche Plugins sind aktiviert?

Das ist **ineffizient**, **verlangsamt die Hilfe** und **verärgert alle**.

---

## ✅ Wie man sein Auto richtig in die Werkstatt bringt – Anleitung zum Erstellen eines Tickets

Damit ich **nicht raten muss, sondern Ihnen sofort helfen kann**, gehen Sie nach dieser Checkliste vor:

### 1. **Aktualisieren Sie auf die neueste Version**
> Folgen Sie den [offiziellen Update-Anleitung](/de/Setup/#aktualisieren-sie-den-mod).

### 2. **Beschreiben Sie das Problem klar und deutlich**
> ❌ Schlecht: _"Funktioniert nicht"_

> ✅ Gut:

> - "Nach der Aktualisierung von Z-Mod auf Version X.Y.Z beim Drücken von „Drucken“ auf dem nativen Bildschirm:

> - heizt sich das Bett auf,

> - der Extruder heizt NICHT auf,

> - auf dem Bildschirm wird 0 °C angezeigt,

> - der Druck wird nach 2 Minuten einfach abgebrochen."

> 🔹 Bitte **Screenshots der Fehler**, **Fotos** anhängen,

> 🔹 Beschreiben Sie die genauen **Schritte**, die zu dem **Problem** geführt haben,

> 🔹 Fügen Sie die **Datei, die Sie drucken**, bei (es könnte ein Problem im G-Code geben!).

### 3. **Führen Sie eine vollständige Diagnose durch**
> Führen Sie diese Schritte in strikter Reihenfolge aus:

> 1. [CLEAR_EMMC](/de/System/#clear_emmc) - alte Protokolle löschen

> 2. **Den Drucker vollständig ausschalten** → 10 Sekunden warten.

> 3. Schalten Sie den Drucker ein

> 4. **Reproduzieren Sie das Problem** (Druck starten, Taste drücken – Fehler hervorrufen)

> 5. Führen Sie `TAR_CONFIG` aus – dies erstellt ein `config.tar.gz`-Archiv mit allen Protokollen

### 4. **Füllen Sie das Ticket korrekt aus**
> - Gehen Sie zur [Issues-Seite](https://github.com/ghzserg/zmod/issues)

> - Erstellen Sie **eine** Nachricht

> - Fügen Sie hinzu:

> - Eine verständliche Beschreibung [Schritt 2](#2-beschreiben-sie-das-problem-klar-und-deutlich),

> - die angehängte **`config.tar.gz`**,

> - den **G-Code**, wenn das Problem beim Drucken einer bestimmten Datei auftritt.

> ⚠️ Ohne `config.tar.gz` gibt es keine Diagnose - es ist wie ein Bluttest ohne Blut.

---

## Was bringt dieser Ansatz?

Sie hören auf zu rufen: „Das Auto fährt nicht.“

und Sie bringen es zu mir:

> 🚗 **ein konkretes Modell**,

> 📋 **Störungsprotokoll**,

> 📊 **Diagnoseergebnisse**.

Und dann kann ich **sofort mit der Reparatur beginnen, statt zu raten**.

---

!!! tip
    Danke für Ihr Verständnis und dafür, dass Sie die Zeit anderer Leute respektieren.

    Das ist keine Bürokratie – es ist der einzige Weg, die Unterstützung **schnell und effizient** zu gestalten.

**[Ticket erstellen](https://github.com/ghzserg/zmod/issues)**
