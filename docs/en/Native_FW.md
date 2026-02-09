# Native firmware

[Here is the native firmware for AD5M, AD5MPro, AD5X printers](https://github.com/ghzserg/FF/releases/R)

## How to install native firmware

1. Reset the printer to default settings.
2. Format a USB drive to FAT/FAT16/FAT32.
3. Copy the appropriate file to the USB root directory
4. Power off the printer.
5. Insert the usb drive into printer usb port.
6. Power on the printer.

## AD5X native firmware

- [1.0.2](https://github.com/ghzserg/FF/releases/download/R/AD5X-1.0.2-1.0.2-20250120-Factory.tgz)
- [1.0.7](https://github.com/ghzserg/FF/releases/download/R/AD5X-1.0.7-1.0.3-20250408-Factory.tgz)
- [1.0.8](https://github.com/ghzserg/FF/releases/download/R/AD5X-1.0.8-1.0.5-20250418-Factory.tgz)
- [1.1.6](https://github.com/ghzserg/FF/releases/download/R/AD5X-1.1.6-1.1.0-3.0.6-20250722.tgz)
- [1.1.7](https://github.com/ghzserg/FF/releases/download/R/AD5X-1.1.7-1.1.0-3.0.6-20250912-Factory.tgz)
- [1.1.9](https://github.com/ghzserg/FF/releases/download/R/AD5X-1.1.9-1.1.1-3.0.7-20251201-Factory.tgz)
- [1.2.0](https://github.com/ghzserg/FF/releases/download/R/AD5X-1.2.0-1.1.1-3.0.7-20251212-Factory.tgz)
- [1.2.1](https://github.com/ghzserg/FF/releases/download/R/AD5X-1.2.1-1.1.1-3.0.7-20251217-Factory.tgz)
- [3.0.3](https://github.com/ghzserg/FF/releases/download/R/AD5X-3.0.3-1.1.1-3.0.7-20260119.tgz)

## AD5M native firmware

- [3.1.3](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-3.1.3-2.2.3-20250107-Factory.tgz)
- [3.1.9](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-3.1.9-2.2.3-20250807-Factory.tgz)
- [3.2.3](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-3.2.3-2.2.3-20251016-Factory.tgz)
- [3.2.5](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-3.2.5-2.2.3-20251205-Factory.tgz)
- [3.2.6](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-3.2.6-2.2.3-20251212-Factory.tgz)
- [3.2.7](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-3.2.7-2.2.3-20251217-Factory.tgz)
- [5.0.3](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-5.0.3-2.2.3-20260122.tgz)

## AD5MPro native firmware

- [3.1.3](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-3.1.3-2.2.3-20250107-Factory.tgz)
- [3.2.3](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-3.2.3-2.2.3-20251017-Factory.tgz)
- [3.2.4](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-3.2.4-2.2.3-20251114-Factory.tgz)
- [3.2.5](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-3.2.5-2.2.3-20251126-Factory.tgz)
- [3.2.7](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-3.2.7-2.2.3-20251217-Factory.tgz)
- [5.0.3](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-5.0.3-2.2.3-20260122.tgz)

## Installing full firmware on AD5X

Installation takes a long time, up to an hour.

Download to flash drive

- [AD5X-factory-1.0.9.tgz](https://github.com/ghzserg/FF/releases/download/R/AD5X-factory-1.0.9.tgz)
- [AD5X-factory.tar.xz](https://github.com/ghzserg/FF/releases/download/R/AD5X-factory.tar.xz)
- After the update, if you need to reflash the MCU, install [AD5X](https://github.com/ghzserg/FF/releases/download/R/AD5X-1.1.7-1.1.0-3.0.6-20250912-Factory.tgz)

## Installing full firmware on FF5M

Installation takes a long time, up to an hour.

Download to flash drive

- [Adventurer5M-factory-3.1.3.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-factory-3.1.3.tgz)
- [Adventurer5M-factory.tar.xz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-factory.tar.xz)
- `config.tar`, if you previously did it via `TAR_CONFIG`
- After the update, if you need to reflash the MCU, install [Adventurer5M-3.1.9-2.2.3-20250807-Factory.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-3.1.9-2.2.3-20250807-Factory.tgz)

## AD5X-ENABLE-zmod.tgz

Enabling zmod on AD5X after updating the native firmware allows you to activate the mod without completely reinstalling it

[AD5X-ENABLE-zmod.tgz](https://github.com/ghzserg/FF/releases/download/R/AD5X-ENABLE-zmod.tgz)

## SET XY

For those who've lost their minds and moved their "home" (parking lot to the poop bin). Extract the archive contents to the root of a flash drive, insert the flash drive, and reboot the printer. The calibration will load. First, press Reset. Then, use the on-screen control buttons to adjust the correct head position. Press the Set button to lock this. Reboot the printer without the flash drive. Archive from official Flashforge support.

[Set.XY.Offset.zip](https://github.com/ghzserg/FF/releases/download/R/Set.XY.Offset.zip)

## Root

- User: root
- Password: root

- [Adventurer5M-root](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-root.tgz)
- [Adventurer5MPro-root](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-root.tgz)
- [AD5X-root](https://github.com/ghzserg/FF/releases/download/R/AD5X-root.tgz)

## E0011 native firmware 

[fix_e0011](/Global/#fix_e0011)

Fix E0011 On

- [Adventurer5M-e0011-on.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-e0011-on.tgz)
- [Adventurer5MPro-e0011-on.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-e0011-on.tgz)

Fix E0011 Off

- [Adventurer5M-e0011-off.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-e0011-off.tgz)
- [Adventurer5MPro-e0011-off.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-e0011-off.tgz)

## E0017 native firmware

[fix_e0017](/Global/#fix_e0017)

- [Adventurer5M-e0017-4.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-e0017-4.tgz)
- [Adventurer5MPro-e0017-4.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-e0017-4.tgz)

## 5M to 5MPro

[Adventurer5M-3.1.3-2.2.3-20250107-Factory-5M2PRO.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5M-3.1.3-2.2.3-20250107-Factory-5M2PRO.tgz)

## 5MPro to 5M

[Adventurer5MPro-3.1.3-2.2.3-20250107-Factory-PRO25M.tgz](https://github.com/ghzserg/FF/releases/download/R/Adventurer5MPro-3.1.3-2.2.3-20250107-Factory-PRO25M.tgz)

## 5X IFS
Backup IFS firmware

- [3.0.6](https://github.com/ghzserg/FF/releases/download/R/ifc_3.0.6.zip)

- [IFS Firmware Recovery](/AD5X/#11-ifs-firmware-recovery)

## G-code

- [3DBenchy_PLA.3mf](https://github.com/ghzserg/FF/releases/download/R/3DBenchy_PLA.3mf)
- [FlashForge-TestModel-01.3mf](https://github.com/ghzserg/FF/releases/download/R/FlashForge-TestModel-01.3mf)
- [OrcaPlug_PLA.3mf](https://github.com/ghzserg/FF/releases/download/R/OrcaPlug_PLA.3mf)
- [Earphone.support_PLA.3mf](https://github.com/ghzserg/FF/releases/download/R/Earphone.support_PLA.3mf)
- [FISH_PLA.3mf](https://github.com/ghzserg/FF/releases/download/R/FISH_PLA.3mf)

## MD5

- [addMD5.bat](https://github.com/ghzserg/FF/releases/download/R/addMD5.bat)
- [addMD5.sh](https://github.com/ghzserg/FF/releases/download/R/addMD5.sh)
- [addMD5.py](https://github.com/ghzserg/FF/releases/download/R/addMD5.py)
- [addmd5-darwin-amd64](https://github.com/asd2003ru/addmd5/releases) (MacOS Intel)
- [addmd5-darwin-arm64](https://github.com/asd2003ru/addmd5/releases) (MacOS Silicon)
- [addmd5-linux-amd64](https://github.com/asd2003ru/addmd5/releases) (Linux)
- [addmd5-windows-amd64.exe](https://github.com/asd2003ru/addmd5/releases) (Windows)
