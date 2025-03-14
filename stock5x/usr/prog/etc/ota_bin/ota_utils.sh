#!/bin/sh

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

# 获取关键字的值
get_key_word()
{
    local str="$1"
    local key="$2"
    local word=
    local tmp
    local len

    #　情况1　"key = words"
    tmp=`get_word "$str" 0`
    if [ "$tmp" = "$key" ]; then
        tmp=`get_word "$str" 1`
        if [ "$tmp" != "=" ]; then
            return 1
        fi

        echo ${str##*=}
        return 0
    fi

    #　情况2　"key=words"
    len=${#key}
    let len=len+1
    tmp=${str:0:$len}
    if [ "$tmp" = "$key=" ]; then
        echo ${str:$len}
        return 0
    fi

    return 1;
}

# 从文件中获得关键字
get_key_word_from_file()
{
    local file=$1
    local key=$2
    local is_find
    local result
    local result_save

    if [ ! -e "$file" ]; then
        echo "no such file: $file" 1>&2
        return 1
    fi

    while read line;
    do
        result=`get_key_word "$line" "$key"`
        if [ $? = 0 ]; then
            is_find=1
            result_save=$result
            continue
        fi
    done < "$file"

    if [ "$is_find" != "" ]; then
        echo $result_save
        return 0
    fi

    return 1
}

# 获得文件大小
size_file()
{
    local file=$1
    local result

    result="`ls -l -L $file`"
    if [ "$?" != "0" ]; then
        echo 0
        return 1
    fi

    result=`get_word "$result" 4`
    if [ "result" = "" ]; then
        echo 0
        return 1
    fi
    echo $result
}

# 等待文件出现
wait_file()
{
    local file=$1
    local count=$2
    local i=0

    while true;
    do
        if [ -e $file ]; then
            return 0
        fi

        if [ "$i" = "$count" ]; then
            return 1
        fi

        let i=i+1
        sleep 0.01
    done
}

# 获得文件的md5sum
md5sum_file()
{
    local file=$1
    local result

    result="`md5sum $file`"
    if [ $? != 0 ]; then
        echo "md5sum failed: $file" 1>&2
        exit 1
    fi

    result=`get_word "$result" 0`
    if [ "$result" = "" ]; then
        echo "md5sum get failed: $file" 1>&2
        exit 1
    fi
    echo $result
}

# wget 带重试次数
wget_retry()
{
    local site="$1"
    local file="$2"
    local count=$3
    local i=0

    while true;
    do
        echo "try to get $site" 1>&2
        wget -t 1 -T 20 "$site" -O "$file" -o /tmp/ota_wget_msg/$file.log
        if [ $? = 0 ]; then
            return 0;
        fi

        if [ $i = $count ]; then
            return 1
        fi

        let i=i+1
        sleep 1
    done
}

# 由mmc分区名获得mmc设备节点
mmc_name_to_dev()
{
    local partition_name=$1

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
        str=`fdisk -l $dev | grep -w $partition_name`
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

    echo $detect_dev
}

# 写入字符串到mmc分区
mmc_write_str()
{
    local partition_name=$1
    local str=$2
    local dev

    dev=`mmc_name_to_dev "$partition_name"`
    if [ $? != 0 ]; then
        echo "failed to get mmc dev $partition_name" 1>&2
        return 1
    fi

    echo $str > $dev
    if [ $? != 0 ]; then
        echo "failed to write $dev" 1>&2
        return 1
    fi

    return 0
}

# 从mmc分区读取字符串
mmc_read_str()
{
    local partition_name=$1
    local dev

    dev=`mmc_name_to_dev "$partition_name"`
    if [ $? != 0 ]; then
        return 1
    fi

    dd if=$dev bs=1 count=256
    if [ $? != 0 ]; then
        return 1
    fi

    return 0
}


# 检查mmc 分区大小
mmc_check_size()
{
    local dev_path=$1
    local img_size=$2
    local percent=$3
    local mmc_info

    mmc_info=`fdisk -l $dev_path`
    if [ $? != 0 ]; then
        echo "mmc get info failed: $dev_path" 1>&2
        return 1
    fi

    mmc_info=`fdisk -l $dev_path | grep "bytes,"`
    if [ $? != 0 ]; then
        echo "mmc grep info failed: $dev_path" 1>&2
        return 1
    fi

    if [ "$mmc_info" = "" ]; then
        echo "why mmcinfo is empty: $dev_path" 1>&2
        return 1
    fi

    local mmc_size=`get_word "$mmc_info" 4`
    if [ "$mmc_size" = "" ] || [ "$mmc_size" = "$tmp" ]; then
        echo "mmcinfo format is change: $dev_path: $mmc_info" 1>&2
        return 1
    fi

    if [ "$percent" = "" ]; then
        return 0
    fi

    local mmc_size2
    let mmc_size2=mmc_size/1000*percent/100
    local img_size2
    let img_size2=img_size/1000
    if [ $mmc_size2 -lt $img_size2 ]; then
        echo "mmc size2 less than require size: $mmc_size $img_size $mmc_size2 $percent" 1>&2
        return 1
    fi

    return 0
}

