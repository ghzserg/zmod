---
hide:
  - navigation
---

# FF5M / FF5M Pro / AD5X ZMOD

<img width="698" height="291" alt="zmod logo" src="https://github.com/user-attachments/assets/5e26413b-c9a2-49f2-b9b8-5ecde709c521" />

[zMod LINK is available at this link ->](https://zmod.link/link/)

### **ZMOD for FlashForge AD5M/PRO/AD5X: Full Control Over Your Printer**

Congratulations on your FlashForge printer purchase! The stock firmware is great for getting started, but if you want to unlock your device’s full potential, ZMOD is a powerful and free solution that transforms your printer from “user-friendly” to “professional-grade”.

### What is ZMOD?
ZMOD is a custom firmware modification installed *on top of* the stock software. It does **not** replace the original firmware — instead, it extends it, adding a vast number of features familiar from advanced printers, all while preserving the benefits and ease of use of the native interface.

### Key Advantages of ZMOD vs. Stock Firmware
Here’s what you gain by installing ZMOD:

#### 1. Full Remote Control
**Stock firmware**: You can send files over Wi-Fi, but only via Orca FF or the FlashForge app (both may be unavailable due to server issues).
**ZMOD**: Complete browser-based control from your PC or phone:

- **Fluidd / Mainsail**: Intuitive web interfaces showing live print stats, temperatures, fan speed control, axis movement, and full console access.
- **Octo/Klipper-style file upload**: Seamless integration with Orca Slicer and other slicers for direct G-code file transfers.
- **Access to the printer's web interface via the Internet** cloud service [zmod.link](https://zmod.link)
- **Notification in Telegram and 100+ other services** [notify plugin](https://github.com/ghzserg/notify/)

#### 2. Advanced Calibration & Bed Leveling
**Stock firmware**: Basic automatic bed leveling (ABL).
**ZMOD**:

- **Adaptive Mesh (KAMP)**: The printer generates a mesh map only over the area where your model is located — saving time and improving accuracy.
- **PID Tuning**: Precise calibration of extruder and bed thermal behavior for stable, oscillation-free temperatures.
- **Input Shaping**: Analyzes and compensates for frame vibrations, enabling faster printing without “ringing” artifacts.
- **Belt Spectrogram**: Diagnoses belt condition for predictive maintenance.
- **Screw Tilt Adjustment**: Fully level the bed in under 10 minutes.

#### 3. Intelligent Reliability Features
**Stock firmware**: Basic filament-runout detection. No firmware or file integrity checks → print hangs possible.
**ZMOD**:

- **Nozzle Collision Detection**: Uses strain gauges to detect nozzle collisions with the print or bed — and automatically pauses to prevent damage.
- **Power-loss Recovery**: Remembers the last print position and resumes after power is restored.
- **Firmware Integrity Check**: Validates both stock firmware and ZMOD files to prevent corruption.
- **G-code File Integrity Check**: Verifies MD5 checksums during file transfer.

#### 4. Flexible Filament Handling (Especially for AD5X)
**Stock firmware**: Standard spool selection via UI menu.
**ZMOD (for AD5X)**:

- **Smart COLOR Menu**: Visually select spools, color changes, and material types directly from the web UI.
- **Infinite Spool Mode**: If multiple spools use the same material, the printer automatically switches to the next one when the current runs out.
- **Fine-tuned Purge Control**: Reduce purge filament volume during color changes, saving material.

#### 5. Ecosystem & Integration
**Stock firmware**: Closed system.
**ZMOD**:

- **Telegram Bot**: Get real-time notifications and camera snapshots in Telegram for print start/completion.
- **Plugin Support**: Extend functionality via modules (e.g., `bambufy` for better Bambu Studio compatibility).
- **Alternative Camera Setup**: Adjustable resolution, FPS, and memory optimization for stable streaming.
- **Jingle Playback**: Plays custom tunes when prints start or finish.

#### 6. Optimization & Low-level Control
**Stock firmware**: Limited configurability.
**ZMOD**:

- **Stock LCD Disable**: Frees up RAM (critical on AD5M with only 128 MB).
- **GuppyScreen**: Enhanced replacement UI for the printer’s display.
- **Log Viewing**: Full system logs for diagnostics.
- **Firmware Retraction**: Adjust retraction parameters on-the-fly, no reslicing needed.
- **Full ROOT Access**: Full system control always available.

#### 7. Klipper 13
**Stock firmware**: AD5M runs outdated Klipper v11, plagued by bugs (E0011, E0017, incorrect object exclusion, broken SCV, faulty resume, etc.).
**ZMOD**:

- Fixes known Klipper bugs and enables a modern, stable version.

---

### Summary: Who Is ZMOD For?

| If you are… | ZMOD gives you… |
|-------------|-----------------|
| A **beginner** | Easy remote control and automated calibrations for reliable “first-try” quality. |
| An **enthusiast** | Full control over every printing parameter, advanced tuning tools, and speed experimentation. |
| An **AD5X owner** | The most convenient multi-color workflow and reduced filament waste. |

ZMOD doesn’t *replace* the stock firmware — it enhances it, giving you the **choice**: stick with the familiar touchscreen UI, or leverage modern 3D printing tools to get the absolute most from your FlashForge. It’s the logical next step for any FlashForge owner aiming to maximize their printer’s capabilities.

!!! danger
    *If you want to install this mod on your AD5M (Pro) / [AD5X](/AD5X/), be aware that you risk voiding the warranty or damaging the printer. Proceed at your own risk if you wish to try this mod!*
    
    If you don’t know what this is, don’t understand why a Klipper web interface is needed, or are simply satisfied with the stock firmware, do NOT install this modification. For everyone else – **please read the entire instructions carefully!**
    
    After installing the mod, if you don’t want to delve into details – just print as usual. No additional configuration or changes are required. If you decide to explore further – proceed by reading the [documentation](https://ghzserg.github.io/).

## Before start

#### Do NOT install this mod if the following stock firmware fixes suffice

These features are ported to the stock firmware:

1. I want to install Klipper. (Klipper is already in the printer, but there is no web interface)
2. [Install root](/Native_FW/#root)
3. [E0011 error fix](/Global/#fix_e0011)
4. [E0017 error fix](/Global/#fix_e0017)
5. [Disable printer updates/telemetry/Chinese clouds](/Global/#china_cloud)
6. [Factory reset](/Setup/#restoring-printer-to-factory-settings-required-for-mod-installation)
7. [Convert FF5M to FF5MPro](/Native_FW/#5m-to-5mpro)
8. [Convert FF5MPro to FF5M](/Native_FW/#5mpro-to-5m)


### Compatibility
Compatible with clean firmware versions:

- FF5M/FF5MPro: v2.7.5 or higher (2.7.5, 2.7.6, 2.7.7, 2.7.8, 2.7.9, 3.1.3, 3.1.4, 3.1.5, 3.1.9, **3.2.3**, 3.2.4, 3.2.5, 3.2.6, 3.2.7, 5.0.3)
- [AD5X](/AD5X/): only (1.0.2, 1.0.7, 1.0.8, 1.0.9, 1.1.1, 1.1.6, **1.1.7**, 1.1.9, 1.2.0, 1.2.1, 1.2.2, 1.2.3, 3.0.3)

Native firmware files are located [here](/Native_FW/).

## Installation/Update/Removal

[Installation/Update/Removal Guide](/Setup/)

## FAQ

[Must-read](/FAQ/)

## Printer Stability Recommendations

[Read if encountering issues](/Recomendations/)

## Plugins

zMod support [Plugins](/Plugin/)

## Support Development

Since people have been asking, I accept donations but please remember that I work on zMod for fun and not for the money. I will not accept donations to work on specific bugs or features.

You can find available support methods on a separate [page](/Sponsor/)

