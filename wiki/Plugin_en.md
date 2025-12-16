# Plugins in zMod

Any user can create and connect their own plugin to **zmod**.

Plugins included with zMod:
1. [Recommend](https://github.com/ghzserg/recommend) - Settings recommended for immediate use after installing the mod.
2. [G28_tenz](https://github.com/ghzserg/g28_tenz) – Z-axis parking using load cells
3. [Bambufy](https://github.com/function3d/bambufy) - Compatible with Bambu Studio, improves prime tower management, provides accurate time/material estimates, reduces waste, supports Mainsail, fast color changes, and advanced printing features. CANNOT BE USED WITH NATIVE SCREEN
4. [Nopoop](https://github.com/ghzserg/nopoop) - Maximum waste reduction by ninjamida
5. [TimeLapse](https://github.com/ghzserg/timelapse) - Moonraker Timelapse
6. [Notify](https://github.com/ghzserg/notify) - Receive notifications in Telegram and over 100 other different services

---

## Plugin Management

**Enable plugin:**
```gcode
ENABLE_PLUGIN name=g28_tenz
```
— downloads the plugin and restarts Klipper on success.

**Disable plugin:**
```gcode
DISABLE_PLUGIN name=g28_tenz
```

---

## Creating Your Own Plugin

Plugin example: https://github.com/ghzserg/g28_tenz
(In all examples below, the name `g28_tenz` is used — replace it with your plugin’s name.)

---

### Adding a Plugin

In the file
```mod_data/user.moonraker.conf```
add the following section:

```ini
[update_manager g28_tenz]
type: git_repo
channel: dev
path: /root/printer_data/config/mod_data/plugins/g28_tenz
origin: https://github.com/ghzserg/g28_tenz.git
is_system_service: False
primary_branch: main
```

- **Plugin path**: `/root/printer_data/config/mod_data/plugins/g28_tenz`
- **Source**: `https://github.com/ghzserg/g28_tenz.git`

> Stable plugins may be included in the zmod distribution, but are updated and maintained by their respective authors.

---

### Installation Script

After calling `ENABLE_PLUGIN`, the file `install.sh` will be executed automatically.
After calling `DISABLE_PLUGIN`, the file `uninstall.sh` will be executed automatically.

### Single-language Plugin
Must contain the file:
```
g28_tenz.cfg
```
All functionality goes inside this file.

### Multi-language Plugin
Files are placed in language-specific subdirectories:
```
en/g28_tenz.cfg
ru/g28_tenz.cfg
de/g28_tenz.cfg
...
```

All output strings must be escaped, for example:
```gcode
RESPOND PREFIX="info" MSG="===Cutting the filament==="
```

---

#### Translation

Translations are stored in the `translate/` directory in files like `de.csv`:

```csv
Cutting the filament;Filament schneiden
```

Format:
```
English phrase;Translation in target language
```

To generate language files, run:
```bash
./Make.sh
```
The script will create the required directories and `.cfg` files.
