# So kontaktieren Sie den Entwickler-Support

Öffnen Sie den Telegrammbot [@zmod_help_bot](http://t.me/zmod_help_bot) und stellen Sie ihm Ihre Frage, er kennt die gesamte Dokumentation.

1. [Aktualisieren Sie Z-Mod und alle Plugins auf die neueste Version](/de/Setup/#update-mod)
2. Übersetze den Mod ins Russische ```LANG LANG=ru```.
3. Beschreibe das Problem deutlich. Bildschirme, Fotos, Textbeschreibung.
4. Rufe [CLEAR_EMMC](/de/System/#clear_emmc) auf, um die Logs zu löschen
5. **Der Drucker muss ausgeschaltet werden**
6. Schalten Sie den Drucker ein
7. Erzeugen Sie ein Problem
8. Ausführen von [TAR_CONFIG](/de/Zmod/#tar_config) - Logdateien speichern
9. Poste eine Nachricht mit Beschreibung und `config-1.6.28-15.tar.gz`-Datei.
10. [Fehlermeldung hinzufügen](https://github.com/ghzserg/zmod/issues)

Falls `TAR_CONFIG` nicht ausgeführt werden kann:
- Laden Sie [log](https://wiki.zmod.link/cs/Native_FW/#log)
- Kopieren Sie `config-1.6.6-28.tar.gz` vom USB-Stick, wobei 1.6.6-28 die aktuelle Version des Mods ist

Oder verbinden Sie sich per SSH mit dem Drucker:

AD5M/AD5MPro:

```
chroot /data/.mod/.zmod/
/opt/konfig/mod/.shell/tar_config.sh
```

AD5X:

```
chroot /usr/data/.mod/.zmod/
/opt/konfig/mod/.shell/tar_config.sh
```

## Warum ich nach Tickets frage - eine "Token"-Erklärung

Stellen Sie sich vor, Ihr Drucker ist eine Maschine.
Und ich bin ein Mechaniker in einer großen Werkstatt, in der ich Hunderte verschiedener Autos gleichzeitig repariere.

Sie kommen an und schreien:
> "Mein Auto fährt nicht mehr!"

Und ich muss mit einer einfachen Frage beginnen:
> "Was für ein Auto haben Sie - Marke, Modell, Baujahr?"

### Warum es wichtig ist, es Stück für Stück zu zerlegen ###

Unsere "Flotte" hat **über 100 verschiedene Konfigurationen**. Nur die Grundlagen:

- **3 verschiedene Hersteller**:

  FF5M, FF5M Pro, AD5X

- **3 Versionen des "Motors" (Klipper)**:

  11, 12, 13

- **2 Prozessorarchitekturen**:

  ARM und MIPS

- **Salon-Optionen**:

    - mit nativem Bildschirm

      - mit GuppyScreen

      - mit HelixScreen

      - kein Bildschirm

- **Zwei Hauptsteuerungsschnittstellen**:

  Fluidd und Großsegel

- **Unterschiedliche Möglichkeiten, Aufgaben zum Drucken zu senden**:

  über den eigenen Bildschirm, Guppy, OrcaSlicer (FF-Protokoll, Klipper-Protokoll, usw.)

- **Zusätzliche "Optionen" (Plugins)**:

  `nopoop`, `recommend`, `bambufy`, `g28_tenz`, `timelapse`, `notify` und andere

- **Sensoren und Peripheriegeräte**:

  Fadensensor, Bewegungssensor, IFS, usw.

Und es gibt auch Fälle, in denen der Besitzer **etwas unter der Haube neu gelötet**, mit "unbekanntem Kraftstoff" (alte Firmware, Mods von Drittanbietern) gefüllt oder Ratschläge von AI gelesen hat, **nie seinen speziellen Drucker gesehen**.

#### Unterm Strich.

Wenn Sie nur **"funktioniert nicht "** schreiben, verbringe ich **Stunden** damit, es herauszufinden:

- Welches Modell haben Sie?
- Welche Firmware/Version von Klipper?
- Mit oder ohne Bildschirm?
- Welcher Slicer und welche Einstellungen?
- Welche Plugins sind aktiviert?

Das ist **ineffizient**, **verlangsamt die Hilfe** und **verärgert alle**.

---

## Wie man sein Auto richtig zum Service bringt - Anleitung zum Erstellen eines Tickets

Damit ich **nicht raten, sondern Ihnen gleich helfen kann**, machen Sie alles nach der Checkliste:

### 1. **Aktualisieren Sie auf die neueste Version**
> Folgen Sie den [offiziellen Upgrade-Anweisungen](/de/Setup/#upgrade-mod).

### 2. **Russische Sprache installieren**
> Starten Sie in der Konsole:

> ```bash
> LANG LANG=ru
> ```

### 3. **Beschreiben Sie das Problem klar und deutlich**
> ❌ Schlecht: _"Funktioniert nicht"_

> ✅ Gut:

> _"Nach der Aktualisierung von Z-Mod auf Version X.Y.Z beim Drücken von "Drucken" auf dem ursprünglichen Bildschirm:

> > - heizt sich der Tisch auf,

> - der Extruder heizt NICHT auf,

> - die Bildschirmtemperatur beträgt 0°C,

> - der Druck wird nach 2 Minuten einfach abgebrochen."_

> 🔹 Bitte **Screenshots der Fehler**, **Fotos** anhängen,

> 🔹 Beschreiben Sie die **Abfolge der Maßnahmen**,

> 🔹 Fügen Sie die **Datei, die Sie ausdrucken**, bei (es könnte ein Problem im G-Code geben!).

### 4. **Durchführen eines vollständigen Diagnosetests**
> Führen Sie ihn streng nacheinander durch:
> 1. CLEAR_EMMC" - alte Protokolle löschen

> 2. **Den Drucker vollständig ausstecken** → 10 Sekunden warten.

> 3. Schalten Sie den Drucker ein

> 4. **Reproduzieren Sie das Problem** (Druck starten, Taste drücken - Fehler verursachen)

> 5. Führen Sie `TAR_CONFIG` aus - dies erstellt ein `config.tar.gz`-Archiv mit allen Protokollen

### 5. **Füllen Sie das Ticket korrekt aus**
> - Gehen Sie zur [Problemseite](https://github.com/ghzserg/zmod/issues)

> - Erstellen Sie **eine** Nachricht

> - Darin:

> - Eine verständliche Beschreibung (Punkt 3),

> - **muss `config.tar.gz`** anhängen,

> - **G-Code** anhängen, wenn das Problem beim Drucken einer bestimmten Datei auftritt.

> ⚠️ Ohne `config.tar.gz` gibt es keine Diagnose - es ist wie ein Bluttest ohne Blut.

---

## Was bewirkt dieser Ansatz?

Sie hören auf zu schreien: "Das Auto läuft nicht."

und du fängst an, es zu mir zu bringen:

> 🚗 **Bestimmtes Modell**,

> 📋 **Störungsprotokoll**,

> 📊 **Diagnoseergebnisse**.

Und dann kann ich anfangen **zu reparieren - sofort, nicht raten**.

---

Danke für Ihr Verständnis und dafür, dass Sie die Zeit anderer Leute respektieren.

Das ist keine Bürokratie - es ist der einzige Weg, die Unterstützung **schnell und effizient** zu gestalten.
