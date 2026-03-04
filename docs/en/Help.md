# How to Contact Developer Support

Open the Telegram bot [@zmod_help_bot](http://t.me/zmod_help_bot) and ask it your question. It knows all the documentation.

1. [Update zMod and all plugins to the latest version](/ru/Setup/#updating-the-mod)
2. Clearly describe the issue: provide screenshots, photos, and a detailed textual explanation.
3. Run [CLEAR_EMMC](/System/#clear_emmc) to clear previous logs.
4. **Power off the printer completely.**
5. Power the printer back on.
6. Reproduce the issue.
7. Run [TAR_CONFIG](/Zmod/#tar_config) to collect log files.
8. Submit **one** post with your description and the generated `config-1.6.6-28.tar.gz` file. 1.6.6-28 - current version mod.
9. [Open the issue here](https://github.com/ghzserg/zmod/issues).

If it is impossible to execute `TAR_CONFIG`:  
- Download [flashforge_init.s](https://github.com/ghzserg/zmod/tree/main/Native_firmware/log/flashforge_init.sh) to a USB flash drive. [Instructions](https://github.com/ghzserg/zmod/tree/main/Native_firmware/log)
- Copy `config-1.6.6-28.tar.gz` from the USB flash drive, where 1.6.6-28 is the current version of the mod

Or connect to the printer via SSH:

AD5M/AD5MPro:

```
chroot /data/.mod/.zmod/
/opt/config/mod/.shell/tar_config.sh
```

AD5X:

```
chroot /usr/data/.mod/.zmod/
/opt/config/mod/.shell/tar_config.sh
```

## Why I Ask You to Create Tickets — Explained Simply

Imagine your printer is a car.

And I’m a mechanic in a huge garage, repairing *hundreds* of different vehicles every day.

You pull in and shout:

> **“My car won’t drive!”**

And I have to start with the most basic question:

> **“Okay — what make, model, and year is your car?”**

### Why This Matters — A Breakdown

Our “fleet” includes **over 100 unique configurations**. Just by major categories:

- **3 different printer models**:

  FF5M, FF5M Pro, AD5X

- **3 Klipper “engine” versions**:

  11, 12, 13

- **2 CPU architectures**:

  ARM and MIPS

- **Display options (“interior trim”)**:

    - Stock screen

      - GuppyScreen

      - HelixScreen

      - Headless (no screen)

- **Primary UIs**:

  Fluidd and Mainsail

- **Print initiation methods**:

  Via stock screen, Guppy, OrcaSlicer (using FF protocol, Klipper protocol, etc.)

- **Optional “features” (plugins)**:

  `nopoop`, `recommend`, `bambufy`, `g28_tenz`, `timelapse`, `notify` and others

- **Sensors and peripherals**:

  filament presence, filament motion, IFS, etc.

On top of that, some users **modify hardware themselves**, install outdated firmware, or follow advice from forums or AI models that have **never seen their specific printer**.

### The Result

When you write just **“doesn’t work”**, I waste **hours** just trying to identify:

- Which model you have

- Which Klipper/firmware version

- Whether you’re using a screen (and which one)

- Which slicer, settings, and plugins are active

That’s **inefficient**, **delays help**, and **frustrates everyone**.

---

## ✅ How to “Bring Your Car to the Shop” — Ticket Checklist

To help me **skip the guessing and start fixing**, please follow this checklist:

### 1. **Update to the latest version**
> Follow the [official update guide](/ru/Setup/#updating-the-mod).

### 2. **Describe the issue clearly and concretely**
> ❌ Bad: _“It doesn’t work.”_

> ✅ Good:

> _“After updating zMod to v.X.Y.Z, when starting a print from the stock screen:

> — the bed heats up,

> — the extruder does NOT heat (screen shows 0°C),

> — print aborts after ~2 minutes.”_

> 🔹 Attach **screenshots**, **photos**,

> 🔹 Describe **exact steps leading to the issue**,

> 🔹 Attach the **G-code file** (the problem may be in the file itself!).

### 3. **Run full diagnostics**
> Do these steps **in strict order**:
> 1. `CLEAR_EMMC` — clear old logs

> 2. **Unplug the printer from mains** → Wait 10 seconds

> 3. Power it back on

> 4. **Reproduce the issue** (start print, press button — trigger the error)

> 5. Run `TAR_CONFIG` — generates `config.tar.gz` containing all logs

### 4. **Submit the ticket correctly**
> - Go to [Issues page](https://github.com/ghzserg/zmod/issues)

> - Create **one** new issue

> - Include:

>   - Your clear description (step 2 above)

>   - **Attach `config.tar.gz`**

>   - Attach the **G-code file**, if applicable

> ⚠️ Without `config.tar.gz`, diagnosis is impossible — it’s like submitting a blood test… *without the blood*.

---

## What This Achieves

You stop shouting:

> **“My car won’t drive!”**

And instead deliver:

> 🚗 **Your exact vehicle**,

> 📋 **Full service history**,

> 📊 **Diagnostic reports**.

Then I can start **fixing — immediately, not speculating**.

---

Thank you for your understanding and respect for others’ time.

This is not bureaucracy — it’s the **only way** to make support **fast and effective**.
