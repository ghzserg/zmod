#!/bin/sh

F="/opt/klipper/klippy/mcu.py"

sed -i 's|^TRSYNC_TIMEOUT.*|TRSYNC_TIMEOUT = 0.025|' $F
sync
find /opt/klipper/ -name __pycache__ -type d -exec rm -r "{}" \; 2>/dev/null
sync
find /opt/klipper/ -name *.pyc -exec rm "{}" \; 2>/dev/null
sync
if grep "^/dev/sd[ab12]* /mnt " /proc/mounts
    then
      rm -f /mnt/Adventurer5MPro-e0017-*
      sync
      rm -f /mnt/Adventurer5M-e0017-*
      sync
fi
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

sleep 5
reboot
