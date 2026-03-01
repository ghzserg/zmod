#!/bin/sh
# (C) 2024-2026 ghzserg https://github.com/ghzserg/zmod

set -e

tar_config_ff5m() 
{
    rm -f /opt/config/mod_data/*.tar /opt/config/mod_data/*.tar.gz 2>/dev/null >/dev/null
    tar -cf /mnt/config.tar \
        --exclude logo --exclude save \
        --exclude database --exclude shapers \
        --exclude ssh.key --exclude .git \
        --exclude .shell --exclude notify.txt \
        --exclude printer_data --exclude config.tar.gz \
        --exclude config.tar /opt/config/ /data/logFiles/
    VER=$(cat /opt/config/mod/version_5m.txt)
    mv /mnt/config.tar /mnt/config_${VER}.tar
    sync
}

tar_config_ad5x() 
{
    rm -f /usr/data/config/mod_data/*.tar /usr/data/config/mod_data/*.tar.gz 2>/dev/null >/dev/null
    tar -cf /mnt/config.tar \
        --exclude logo --exclude save \
        --exclude database --exclude shapers \
        --exclude ssh.key --exclude .git \
        --exclude .shell --exclude notify.txt \
        --exclude printer_data --exclude config.tar.gz \
        --exclude config.tar /usr/data/config/ \
        /usr/prog/config/ /usr/data/logs/ /usr/prog/app_startup.sh
    VER=$(cat /usr/data/config/mod/version_5x.txt)
    mv /mnt/config.tar /mnt/config_${VER}.tar
    sync
}

create_log()
{
    if [ "$(uname -m)" == "armv7l" ]; then
        tar_config_ff5m
    else
        tar_config_ad5x
    fi
}

if grep "^/dev/sd[ab12]* /mnt " /proc/mounts; then
  create_log &> /mnt/zmod_log.log
else
  create_log
fi

rm -f /mnt/flashforge_init.sh
sync
umount /mnt
sync
sleep 300
reboot
exit 0
