#!/bin/sh
############################################################
# file wlan_softap.sh
# 
# 
#
############################################################

WIFI_LIB_PATH=`find /lib -name "xr829.ko" | head -1`
insmod $WIFI_LIB_PATH
ifconfig wlan0 up
ifconfig wlan0 192.168.188.1 
hostapd /etc/hostapd.conf&
udhcpd /etc/udhcpd.conf
