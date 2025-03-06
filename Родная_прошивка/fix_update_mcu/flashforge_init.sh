#!/bin/sh

find /opt/PROGRAM/control/ -name Update -exec rm -f {} \;
sync
sleep 5
reboot
