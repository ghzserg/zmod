#!/bin/sh
############################################################
# file wlan-test.sh
# version 0.0.1
# date 2018-05-06
# 
############################################################

#insmod /lib/modules/4.9.170/xradio_btlpm.ko

# reset bt 
echo 0 > /sys/class/rfkill/rfkill0/state
sleep 1
echo 1 > /sys/class/rfkill/rfkill0/state
sleep 1

# bt bind uart
hciattach -n ttyS1 xradio > /dev/null 2>&1 &

sleep 8

# bt power on
hciconfig hci0 up    
hciconfig hci0 piscan

# bt scan 
hcitool scan

bluetoothd -n &

bluealsa -p a2dp-sink &

bluetoothctl
