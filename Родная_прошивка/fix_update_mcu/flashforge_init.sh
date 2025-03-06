#!/bin/sh

fix_mcu() 
{
    find /opt/PROGRAM/control/ -name Update -exec rm -f {} \;
    sync
    find /opt/PROGRAM/control/ -name Update
    sync
    rm -f /mnt/flashforge_init.sh
}

fix_mcu &> /mnt/fix_mcu.log

sleep 5
reboot
