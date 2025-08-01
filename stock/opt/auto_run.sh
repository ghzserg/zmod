#!/bin/sh

WORK_DIR=/opt
MACHINE=Adventurer5M
PID=0023

#cat /opt/boot.img > /dev/fb0


if [ ! "`mount | grep "mmcblk0p7"`" ]; then
	echo "mmcblk0p7 not mounted and will fsck";
	fsck -y /dev/mmcblk0p7 && mount /dev/mmcblk0p7 /data;
fi


if [ -d /data/update ];then
	rm -rf /data/update
fi

insmod /lib/modules/8821cu.ko
#wait for USB
sleep 2

for i in 1 2 3 4;
do
  if [ ! -e /dev/sda$i ]; then
     echo "sda$i not exist"
	 if [ ! -e /dev/sda ];then
     	continue
	 else
	 	echo "find /dev/sda. start mount."
  		mount -t vfat -o,codepage=936,iocharset=utf8 /dev/sda /mnt
	 fi
  else
  	mount -t vfat -o,codepage=936,iocharset=utf8 /dev/sda$i /mnt
  fi

  if [ $? -ne 0 ]; then
        echo "mount /dev/sda or /dev/sda$i to /mnt failed"
        continue
  else
  		ls -1t /mnt/Adventurer5M-*.tgz
		if [ $? -eq 0 ];then
			UPDATEFILE=`ls -1t /mnt/Adventurer5M-*.tgz | head -n 1`
			if [ -f $UPDATEFILE ];then
				echo "find update file: ${UPDATEFILE}"
				rm -rf /data/update
				cp -a ${UPDATEFILE} /data/
				if [ $? -ne 0 ];then
					rm -rf /data/Adventurer5M-*.tgz
					sync
					umount /mnt
					break
				fi
				sync
				mkdir -p /data/update
				sync
				SRCFILE="/data/`basename ${UPDATEFILE}`"
				if [ -f ${SRCFILE} ];then
					tar -xvf ${SRCFILE} -C /data/update/
					sync
					rm -rf ${SRCFILE}
					/data/update/flashforge_init.sh ${MACHINE} ${PID}
					if [ $? -eq 0 ];then
						umount /mnt
						rm -rf /data/update
						sleep 100000
					fi
					umount /mnt
					rm -rf /data/update
					break
				fi
			fi
		fi

        if [ -f /mnt/flashforge_init.sh ]; then
             echo "found /mnt/flashforge_init.sh"
             chmod a+x /mnt/flashforge_init.sh
             /mnt/flashforge_init.sh ${MACHINE} ${PID}
			 if [ $? -eq 0 ];then
				umount /mnt
				sleep 100000
			 fi
             umount /mnt
             break
        fi
        umount /mnt
  fi
done

/opt/klipper/usb_map.sh

CONTROL_DIR=/opt/PROGRAM/control/
CONTROL_VERSION=`ls -1t ${CONTROL_DIR} | head -n 1`
CONTRIL_FLAG=${CONTROL_DIR}${CONTROL_VERSION}/Update
echo "check update control file"
echo $CONTRIL_FLAG

if [ -f ${CONTRIL_FLAG} ];then
	cd ${CONTROL_DIR}${CONTROL_VERSION}
	./run.sh

	reboot -f
fi

rm /opt/config/printer-*
#rm /data/logFiles/printer.log*

/opt/PROGRAM/ffstartup-arm -f /opt/PROGRAM/ffstartup.cfg &

