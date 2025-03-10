#!/bin/sh
############################################################
# file wlan-test.sh
# version 0.0.1
# date 2018-05-06
# 
############################################################

#insmod /lib/modules/4.9.170/xradio_btlpm.ko

bt_clear()
{
	killall -9 hciattach
	killall -9 bluetoothd
	killall -9 bluetoothctl
	hciconfig hci0 down
	echo 0 > /sys/class/rfkill/rfkill0/state
}


echo $#

if [ $# -lt 1 ]; then
    echo "less arams"
	echo "example: bt_init.sh Mi10S"
	exit
fi

BT_NAME=$1

# reset bt 
echo "reset bt"
echo 0 > /sys/class/rfkill/rfkill0/state
sleep 1
echo 1 > /sys/class/rfkill/rfkill0/state
sleep 1

# bt bind uart
echo "bt bind uart"
hciattach -n ttyS1 xradio > /dev/null 2>&1 &

sleep 8

# bt power on
echo "bt power on"
hciconfig hci0 up    
hciconfig hci0 piscan



# bt scan 
echo "bt scan"
i=0
while [ $i -le 5 ]
do
	echo "scan $i times"
	str=`hcitool scan | grep $BT_NAME`
	echo $str
	if [ "x$str" != "x" ]; then
		echo "find $BT_NAME"
		break;
	fi
	let i++
done	

if [ $i -ge 5 ]; then
	echo "no find $BT_NAME"
	bt_clear
	exit
fi


array=(${str// / })

i=0
BT_MAC=""
for var in ${array[@]}
do
	echo $i $var
	if [ $i -eq 0 ]; then
			BT_MAC=$var
	fi
	let i++
done

echo "BT_MAC: $BT_MAC"

# bluetoothd service
bluetoothd -n &
bluealsa -p a2dp-sink &

#str=`bluetoothctl scan on | grep Mi10S`

echo "scan on"
bluetoothctl scan on &
sleep 8
bluetoothctl scan off
killall -9 bluetoothctl

bluetoothctl connect $BT_MAC

sleep 5

bluealsa-aplay --pcm=hw:audiocodec $BT_MAC&




