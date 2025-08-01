#!/bin/sh
# Author:		chenhe
# Date:			2022-01-21

set -x

WORK_DIR=`dirname $0`

FIRMWARE_Board_M3=Mainboard-20230831.bin
FIRMWARE_Head_M3=Eboard-20231012.hex

CHECH_ARCH=`uname -m`
if [ "${CHECH_ARCH}" != "armv7l" ];then
    echo "Machine architecture error."
    echo ${CHECH_ARCH}
    exit 1
fi

cat $WORK_DIR/mcu.img > /dev/fb0

if [ -f $WORK_DIR/NationsCommand ];then
	chmod a+x $WORK_DIR/NationsCommand
	if [ -f $WORK_DIR/$FIRMWARE_Board_M3 ];then
		echo "burn M3 firmware..."
		$WORK_DIR/NationsCommand -c -d --fn $WORK_DIR/$FIRMWARE_Board_M3 --v -r
	fi
fi

if [ -f $WORK_DIR/IAPCommand ];then
	chmod a+x $WORK_DIR/IAPCommand
	if [ -f $WORK_DIR/$FIRMWARE_Head_M3 ];then
		echo "burn M3 firmware..."
		$WORK_DIR/IAPCommand $WORK_DIR/$FIRMWARE_Head_M3 /dev/ttyS1
		sync
	fi
fi

exit 0
