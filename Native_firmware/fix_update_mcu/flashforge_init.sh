#!/bin/sh

fix_mcu()
{
    CHECH_ARCH=`uname -m`
    if [ "${CHECH_ARCH}" == "armv7l" ]; then
        CONFIG_DIR="/opt/PROGRAM/control/"
    else if [ "${CHECH_ARCH}" == "mips" ]; then
        CONFIG_DIR="/usr/prog/PROGRAM/control/"
    else
        echo "Machine architecture error."
        echo ${CHECH_ARCH}
        exit 1
    fi
    fi

    echo "Start find 1"
    sync
    find ${CONFIG_DIR} -name Update -exec rm -f {} \;
    sync
    echo "Start find 2"
    find ${CONFIG_DIR} -name Update
    sync
    echo "Rm /mnt/flashforge_init.sh"
    rm -f /mnt/flashforge_init.sh
    sync
    echo "Umount /mnt"
    umount /mnt/
    sync
    sleep 5

    if [ "${CHECH_ARCH}" == "armv7l" ]; then
        echo 6 > /sys/class/pwm/pwmchip0/export
        echo inversed > /sys/class/pwm/pwmchip0/pwm6/polarity
        echo 400000 > /sys/class/pwm/pwmchip0/pwm6/period
        echo 200000 > /sys/class/pwm/pwmchip0/pwm6/duty_cycle
        echo 1 > /sys/class/pwm/pwmchip0/pwm6/enable

        for  i in `seq 1 10`; do
            echo "Beeping cycle..."

            echo 400000 > /sys/class/pwm/pwmchip0/pwm6/period
            echo 200000 > /sys/class/pwm/pwmchip0/pwm6/duty_cycle
            sleep 0.25
            echo 800000 > /sys/class/pwm/pwmchip0/pwm6/period
            echo 400000 > /sys/class/pwm/pwmchip0/pwm6/duty_cycle
            sleep 0.25
        done

    reboot -f
}

fix_mcu &> /mnt/fix_mcu.log
