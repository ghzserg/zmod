#!/bin/sh
dev_node="/sys/kernel/config/usb_gadget/adb_demo/UDC"
otg_name=`ls /sys/class/udc/`

sleep 0.5
echo "" > $dev_node
sleep 0.5
echo $otg_name > $dev_node

