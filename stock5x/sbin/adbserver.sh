#!/bin/sh

#set -m

result=`which adbd`
if [ "$result" = "" ]; then
	echo "adbd not installed, exit"
	exit
fi

while [ true ]
do
case "$1" in
    510)
	    adbd
	    wait
	    ;;
    440)
	    mount -t functionfs adb /dev/usb-ffs/adb
	    adbd &
	    wait
	    umount /dev/usb-ffs/adb
	    ;;
    310)
	    adbd
	    wait
	    ;;
    *)
	    echo "Usage: $0 {510|440|310}"
	    exit 1
esac

done
