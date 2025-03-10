#!/bin/bash
for ((i=0;i<10;i++));
do
if [ -c "/dev/ttyACM$i" ]; then
	sysdevpath=$(udevadm info -a -n /dev/ttyACM$i)
	#echo "${sysdevpath%*1d50*}"
	str2="ATTRS{idVendor}==\"1d50\""
	result=$(echo $sysdevpath | grep -w "${str2}")
	if [[ "$result" != "" ]];then
		if [ -c "/dev/ttyboard" ]; then
			rm /dev/ttyboard
		fi
		ln -s /dev/ttyACM$i /dev/ttyboard
		echo "find board mcu"
	else
		str3="ATTRS{idVendor}==\"1d51\""
		result2=$(echo $sysdevpath | grep -w "${str3}")
		if [[ "$result2" != "" ]];then
			if [ -c "/dev/ttyeboard" ]; then
				rm /dev/ttyeboard
			fi
			ln -s /dev/ttyACM$i /dev/ttyeboard
			echo "find eboard mcu"
		else
			echo "no find eboard mcu"
		fi
	fi
fi
done
