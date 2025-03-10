#!/bin/sh
############################################################
# file wlan-test.sh
# version 0.0.1
# date 2018-05-06
# author huanglibin
# wlan-connect.sh Mi10S 12345678 1 
# (0:no pass 1:wpa  2:wep 16 3:wep ASCII)
############################################################
#set -x

echo $#

if [ $# -lt 3 ]; then
    echo "less arams "
	echo "example: wlan-connect.sh Mi10S 12345678 1"
	exit
fi


WLANDEV=wlan0
WPA_CLI="wpa_cli -i $WLANDEV -p /etc/wifi/sockets/"


SSID=$1
PASS=$2
TYPE=$3

WIFI_LIB_PATH=`find /lib -name "xr829.ko" | head -1`
WIFI_LIB_WEP_PATH=`find /lib -name "xr829_wep.ko" | head -1`

echo $WIFI_LIB_PATH
echo $WIFI_LIB_WEP_PATH


wifi_clear()
{
	udhcpc=`ps | grep udhcpc | grep -v grep`
	killall -9 udhcpc
	ifconfig wlan0 down
	rmmod xr829
	xr829=`lsmod | grep xr829 | grep -v grep`
	if [ "$wpa" != "" ]; then
		echo "rmmod xr829"
		rmmod xr829
	fi
		
}

wifi_init()
{
	mount -t debugfs none /sys/kernel/debug
	#insmod /lib/modules/5.4.61+/xr829.ko
	if [[ "$TYPE" == "2" ]] || [[ "$TYPE" == "3" ]]; then
		echo "insmod wep"
		insmod $WIFI_LIB_WEP_PATH
	else
		echo "insmod other"
		insmod $WIFI_LIB_PATH	
	fi
	
	ifconfig wlan0 up
	#echo 0x84B,0x84B > /sys/kernel/debug/ieee80211/phy0/xradio/parse_flags

}


wpa_up()
{
	wpa=`ps | grep wpa_supplicant | grep -v grep`
	[ "$wpa" == "" ] && \
	{
		echo "start wpa_suplicant!!!!!!!!!!!!!!!!!"
		wpa_supplicant -iwlan0 -Dnl80211 -c/etc/wifi/wpa_supplicant.conf -O/etc/wifi/sockets -B
	}
}

wpa_connect()
{
	
	if [ "$3" == 0 ]; then
		echo "=============Set OPEN Security============="
		${WPA_CLI} remove_network all
		${WPA_CLI} add_network
		${WPA_CLI} disable_network all
		${WPA_CLI} set_network 0 ssid \"$SSID\"
		${WPA_CLI} set_network 0 priority 0
		${WPA_CLI} set_network 0 key_mgmt NONE
#		${WPA_CLI} set_network 0 auth_alg OPEN
		${WPA_CLI} set_network 0 scan_ssid $TYPE
		${WPA_CLI} enable_network all
#		${WPA_CLI} reassociate
		return 0
	elif [ "$3" == 1 ]; then
		echo "=============Set WPA Security============="
		${WPA_CLI} remove_network all
		${WPA_CLI} add_network
		${WPA_CLI} disable_network all
		${WPA_CLI} set_network 0 proto RSN
		${WPA_CLI} set_network 0 ssid \"$SSID\"
		${WPA_CLI} set_network 0 priority 0
		${WPA_CLI} set_network 0 key_mgmt WPA-PSK
		${WPA_CLI} set_network 0 psk \"$PASS\"
		${WPA_CLI} set_network 0 scan_ssid $TYPE
		${WPA_CLI} enable_network all
		return 0
	elif [ "$3" == 2 ]; then
		echo "=============Set wep Security============="
		${WPA_CLI} remove_network all
		${WPA_CLI} add_network
		${WPA_CLI} disable_network all
		${WPA_CLI} set_network 0 ssid \"$SSID\"
		${WPA_CLI} set_network 0 key_mgmt NONE
		${WPA_CLI} set_network 0 wep_key0 $PASS
		${WPA_CLI} enable_network all
		return 0
	elif [ "$3" == 3 ]; then
		echo "=============Set wep Security Ascii========="
		${WPA_CLI} remove_network all
		${WPA_CLI} add_network
		${WPA_CLI} disable_network all
		${WPA_CLI} set_network 0 ssid \"$SSID\"
		${WPA_CLI} set_network 0 key_mgmt NONE
		${WPA_CLI} set_network 0 wep_key0 \"$PASS\"
		${WPA_CLI} enable_network all
		return 0
	else
		${WPA_CLI} disconnect
		echo "==========Security ERROR==================="
		return 1
	fi
}

udh_start()
{
	echo "start udhcpc"
	udhcpc -iwlan0 &
}

wifi_clear
wifi_init
wpa_up
wpa_connect $SSID $PASS $TYPE
udh_start
