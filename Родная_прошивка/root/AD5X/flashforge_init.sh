#!/bin/sh

set -x
root_setup() {
    mount /usr/prog/etc /etc
	cp /etc/passwd /etc/shadow /mnt
	sync
    date 2024.01.01-00:00:00
	yes root | passwd
	sync
	rm /mnt/flashforge_init.sh
	sync
}

if grep "^/dev/sd[ab12]* /mnt " /proc/mounts; then
  root_setup &> /mnt/root.log
else
  root_setup
fi

reboot
sync
exit 0
