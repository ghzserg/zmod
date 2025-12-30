#!/bin/sh

fix_loop()
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

    if [ "${CHECH_ARCH}" == "armv7l" ]; then
        find /etc/init.d/ -maxdepth 1 -type l -exec rm -v {} \; ||  echo "X not found"
    fi
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
    fi
    reboot -f
}

fix_loop &> /mnt/fix_loop.log
