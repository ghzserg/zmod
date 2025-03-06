#!/bin/sh

fix_mcu()
{
    echo "Start find 1"
    sync
    find /opt/PROGRAM/control/ -name Update -exec rm -f {} \;
    sync
    echo "Start find 2"
    find /opt/PROGRAM/control/ -name Update
    sync
    echo "Rm /mnt/flashforge_init.sh"
    rm -f /mnt/flashforge_init.sh
    sync
    echo "Umount /mnt"
    umount /mnt/
    sync
    sleep 5

    echo 6 > /sys/class/pwm/pwmchip0/export
    echo inversed > /sys/class/pwm/pwmchip0/pwm6/polarity
    echo 400000 > /sys/class/pwm/pwmchip0/pwm6/period
    echo 200000 > /sys/class/pwm/pwmchip0/pwm6/duty_cycle
    echo 1 > /sys/class/pwm/pwmchip0/pwm6/enable

    for  i in `seq 1 10`
    do
        echo "Beeping cycle..."

        echo 400000 > /sys/class/pwm/pwmchip0/pwm6/period
        echo 200000 > /sys/class/pwm/pwmchip0/pwm6/duty_cycle
        sleep 0.25
        echo 800000 > /sys/class/pwm/pwmchip0/pwm6/period
        echo 400000 > /sys/class/pwm/pwmchip0/pwm6/duty_cycle
        sleep 0.25
    done

    reboot
}

fix_mcu &> /mnt/fix_mcu.log

