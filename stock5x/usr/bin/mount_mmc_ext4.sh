#!/bin/sh

prg_name=$0
partition_name=$1
dev_path=$1
mount_path=$2

# 显示错误和使用方法并退出
usage_exit()
{
	echo $1 1>&2
	echo "usage: $prg_name partition_name/dev_path mount_path" 1>&2
	exit 1
}

# 显示错误并退出
error_exit()
{
	echo $1 1>&2
	exit 1
}

# 获得字符串中的第几个word
get_word()
{
    local str="$1"
    local n=$2
    local i=0

    for word in $str
    do
        if [ $i = $n ]; then
            echo $word
            return 0
        fi
        let i=i+1
    done

    return 1
}

# 判读是否为10进制数字
is_digital()
{
    local d=$1
    local tmp=$1

    let d=d+1 2>/dev/null
    if [ $d = $tmp ]; then
        return 1
    fi

    d=$tmp

    let d=d+0 2>/dev/null
    if [ $tmp != $d ]; then
        return 1
    fi

    return 0
}

if [ "$2" = "" ] || [ "$3" != "" ]; then
    usage_exit "args != 2"
fi

result=`which mke2fs`
if [ "$result" = "" ]; then
    error_exit "mke2fs not found"
fi

# 每次等待时间（单位：秒）
per_wait_time_s=0.1

# 计算最大等待次数
max_wait_count=50

# 目前已经等待次数
now_wait_count=0

# 在快启镜像中，容易出现分区表信息未初始化完成，导致后续挂载失败
echo "Check whether the partition table is initialized successfully!"
while true; do
    if [ -e "/dev/mmcblk0" ];then
        break
    fi

    let "now_wait_count++"

    if [ $now_wait_count -ge $max_wait_count ]; then
        echo "The partition table not found!"
        break
    fi
    sleep $per_wait_time_s
done

detect_dev=

while read line;
do
    line=`echo "$line" | grep mmcblk`
    if [ "$line" = "" ]; then
        continue
    fi

    str=`get_word "$line" 3`

    is_digital ${str#mmcblk}
    if [ $? != 0 ]; then
        continue
    fi

    dev=/dev/$str
    str=`fdisk -l $dev | grep $partition_name`
    if [ "$str" = "" ]; then
        continue
    fi

    tmp=`get_word "$str" 5`
    if [ "$tmp" = "" ]; then
	tmp=`get_word "$str" 4`
    fi

    if [ "$tmp" != "$partition_name" ]; then
        continue
    fi

    is_ok=0
    is_digital `get_word "$str" 0` && \
    is_digital `get_word "$str" 1` && \
    is_digital `get_word "$str" 2` && \
    is_ok=1

    if [ $is_ok != 1 ]; then
        continue
    fi

    detect_dev=${dev}p`get_word "$str" 0`
    break;
done < /proc/partitions

if [ "$detect_dev" = "" ]; then
    detect_dev=`readlink -f $dev_path`
    if [ "$detect_dev" = "" ]; then
        error_exit "mount mmc: $dev_path not valid"
    fi
fi

result=`mount | grep -e $detect_dev -e $mount_path`
if [ "$result" != "" ]; then
	error_exit "resource busy: $result" 
fi

mkdir -p $mount_path
if [ ! -e $mount_path ]; then
	error_exit "can't create mount path: $mount_path"
fi

fsck -y -t ext4 $detect_dev
mount -o sync -t ext4 $detect_dev $mount_path
if [ $? != 0 ]; then
    #mke2fs $detect_dev
    mkfs.ext4 $detect_dev
    mount -o sync -t ext4 $detect_dev $mount_path
fi
