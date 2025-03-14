#!/bin/sh

ota_rootfs_name=$1
ota_rootfs_size=$2
ota_rootfs_dev=$3

if [ $# != 3 ] ; then
    echo "usage: $0 ota/rootfs/file/name total_size /dev/mmcblk0pN" 1>&2
    exit 1
fi

set_write_failed()
{
    echo "ota failed: $1" > $ota_rootfs_name.failed
}

/etc/ota_bin/ota_img_data_provider.sh $ota_rootfs_name $ota_rootfs_size > $ota_rootfs_dev

if [ $? != 0 ]; then
    set_write_failed "write error $?"
    exit 1
fi

if [ -e $ota_rootfs_name.failed ]; then
    exit 1
fi

if [ ! -e $ota_rootfs_name.ok ]; then
    set_write_failed "ota_img_data_provider terminated"
    exit 1
fi

exit 0
