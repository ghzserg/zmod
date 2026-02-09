# Plugins in zMod

Any user can create and connect their own plugin to **zmod**.

Plugins included with zMod:

1. [Recommend](https://github.com/ghzserg/recommend) - Settings recommended for immediate use after installing the mod.
2. [G28_tenz](https://github.com/ghzserg/g28_tenz) – Z-axis parking using load cells
2. [Nopoop](https://github.com/ghzserg/nopoop) - Maximum waste reduction by ninjamida
3. [TimeLapse](https://github.com/ghzserg/timelapse) - Moonraker Timelapse
4. [Notify](https://github.com/ghzserg/notify) - Receive notifications in Telegram and over 100 other different services

External plugins not developed by the zMod author.

1. [Bambufy](https://github.com/function3d/bambufy/blob/master/README_ru.md) - Compatible with Bambu Studio, improves feed tower control, provides accurate time and material consumption estimates, reduces waste, supports Mainsail, quick color changes, and advanced printing features. CANNOT BE USED WITH THE NATIVE SCREEN.
2. [lessWaste](https://github.com/Hrybmo/lessWaste/blob/master/README_ru.md) - a fork of BamBufy

To enable the repository of external plugins not developed by the zMod author, run the command `ENABLE_EXTRA_PLUGINS`.

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
## Installing Classic Klipper Plugins with Python Modules

For classic Klipper plugins that work with Python modules (e.g., [klipper-led_effect](https://github.com/julianschill/klipper-led_effect)), a special installation process is required that involves creating a symbolic link to the Klipper module.

### Example: Installing led_effect

`led_effect` is a plugin for controlling WS2812 RGB LED strips through Klipper.

**Step 1: Clone the repository**

Run these commands in the chroot environment:

```bash
# For AD5M:
chroot /data/.mod/.zmod/
# For AD5X:
chroot /usr/data/.mod/.zmod/

# Same for all models:
cd /opt/config/mod_data/plugins/
git clone https://github.com/julianschill/klipper-led_effect.git
```

**Step 2: Add an entry to the Moonraker config**

In the file `mod_data/user.moonraker.conf`, add the following section:

```ini
[update_manager led_effect]
type: git_repo
channel: stable
path: /opt/config/mod_data/plugins/klipper-led_effect
origin: https://github.com/julianschill/klipper-led_effect.git
is_system_service: False
primary_branch: master
```

**Step 3: Create a symbolic link to the Klipper module**

Create a symbolic link to connect the module to Klipper:

```bash
ln -s /opt/config/mod_data/plugins/klipper-led_effect/src/led_effect.py /usr/prog/klipper/klippy/extras/led_effect.py
```

Replace:

- `klipper-led_effect` with your plugin's folder name
- `led_effect.py` with the module name (may differ depending on the plugin)

**Step 4: Restart Klipper**

After creating the symbolic link, you need to restart Klipper using the restart button in the Fluidd/Mainsail web interface.

### Important Notes

> **The module must be compatible with your Klipper version**
> Ensure that the plugin version is compatible with your installed Klipper version.

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
