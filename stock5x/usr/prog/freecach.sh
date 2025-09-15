#!/bin/sh

MAXRATE=$1
if [ ! "$MAXRATE" ] ; then
	MAXRATE=80
fi

 
TOTAL=`free -m | awk 'NR==2' | awk '{print $2}'`
BUFFCACH=`free -m | awk 'NR==2' | awk '{print $6}'`
FREE=`free -m | awk 'NR==2' | awk '{print $4}'`
RATE=$(($BUFFCACH*100/$TOTAL));
log=/usr/data/logs/mem.log
echo "===========================" >> $log
date >> $log
echo "current_rate: $RATE"
echo "Memory usage | [Total:${TOTAL}MB][Cach：${BUFFCACH}MB][Free：${FREE}MB]" >> $log
if [ "$RATE" -ge "$MAXRATE" ] ; then
	sync && echo 3 > /proc/sys/vm/drop_caches
	echo "OK" >> $log
else
	echo "Not required" >> $log
fi

TARGET_DIR="/usr/data/logs/NIM"
SIZE_LIMIT=100
dir_size=$(du -sm "$TARGET_DIR" | awk '{print $1}')
echo "[$(date +'%F %T')] : $TARGET_DIR : ${dir_size}MB" >> "$log"
if [ "$dir_size" -gt "$SIZE_LIMIT" ]; then
        rm $TARGET_DIR/* -r
	new_size=$(du -sm "$TARGET_DIR" | awk '{print $1}')
        echo "[$(date +'%F %T')] : ${new_size}MB" >> "$log"
fi
