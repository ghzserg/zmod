#!/bin/sh

# 获得ota 服务器地址
local_get_ota_site()
{
    get_key_word_from_file /etc/ota_info ota_site
    return $?

    # echo http://194.169.3.56:8081/ota/board_test
    # return 0
}

# 获得本地的版本号
local_get_current_version()
{
    get_key_word_from_file /etc/ota_info ota_version
    return $?

    # echo 0
    # return 0
}

# 检查 device 分区大小
local_device_check_size()
{
    mmc_check_size $@
    if [ $? != 0 ]; then
        return 1
    fi

    return 0
}

# 获得当前使用中的 kernel 的设备名
local_get_current_kernel_dev_path()
{
    local str=
    local tmp=
    local name=kernel2

    str=`mmc_read_str ota`
    if [ $? != 0 ]; then
        return 1
    fi

    tmp=$(echo "$str" | grep "ota:kernel2")
    if [ "$tmp" == "" ]; then
        name=kernel
    fi

    tmp=`mmc_name_to_dev $name`
    if [ $? != 0 ]; then
        return 1
    fi

    echo $tmp

    return 0
}

# 获得当前使用中的 rootfs 的设备名
local_get_current_rootfs_dev_path()
{
    local str=
    local tmp=
    local name=rootfs2

    str=`mmc_read_str ota`
    if [ $? != 0 ]; then
        return 1
    fi

    tmp=$(echo "$str" | grep "ota:kernel2")
    if [ "$tmp" = "" ]; then
        name=rootfs
    fi

    tmp=`mmc_name_to_dev $name`
    if [ $? != 0 ]; then
        return 1
    fi

    echo $tmp

    return 0
}

# 获得当前需要升级的 kernel 的设备名
local_get_kernel_dev_path()
{
    local str=
    local tmp=
    local name=kernel2

    str=`mmc_read_str ota`
    if [ $? != 0 ]; then
        return 1
    fi

    tmp=$(echo "$str" | grep "ota:kernel2")
    if [ "$tmp" != "" ]; then
        name=kernel
    fi

    tmp=`mmc_name_to_dev $name`
    if [ $? != 0 ]; then
        return 1
    fi

    echo $tmp

    return 0
}

# 获得当前需要升级的 rootfs 的设备名
local_get_rootfs_dev_path()
{
    local str=
    local tmp=
    local name=rootfs2

    str=`mmc_read_str ota`
    if [ $? != 0 ]; then
        return 1
    fi

    tmp=$(echo "$str" | grep "ota:kernel2")
    if [ "$tmp" != "" ]; then
        name=rootfs
    fi

    tmp=`mmc_name_to_dev $name`
    if [ $? != 0 ]; then
        return 1
    fi

    echo $tmp

    return 0
}

# 获得当前需要升级的 rtos 的设备名
local_get_rtos_dev_path()
{
    local str=
    local tmp=
    local name=rtos

    str=`mmc_read_str ota`
    if [ $? != 0 ]; then
        return 1
    fi

    tmp=$(echo "$str" | grep "ota:kernel2")
    if [ "$tmp" != "" ]; then
        name=rtos
    fi

    tmp=`mmc_name_to_dev $name`
    if [ $? != 0 ]; then
        return 1
    fi

    echo $tmp

    return 0
}

# 设置下次启动的设备名
local_set_next_boot_device()
{
    local str=
    local tmp=
    local name=kernel2

    str=`mmc_read_str ota`
    if [ $? != 0 ]; then
        return 1
    fi

    tmp=$(echo "$str" | grep "ota:kernel2")
    if [ "$tmp" != "" ]; then
        name=kernel
    fi

    mmc_write_str ota ota:$name

    return 0
}

# 此变量作为全局变量,其他地方不要操作
ota_saved_size=0


local_ota_cb()
{
    if [ "$OTA_CB_APP" != "" ]; then
        $OTA_CB_APP $*
    fi
}


# ota 数据流回调
local_on_ota_data_processed()
{
    local size=$1
    local n=
    local total_size=
    local total_size2=

    let total_size=ota_kernel_size+ota_rootfs_size+ota_rtos_size
    let n=size+ota_saved_size

    if [ $n == $total_size ]; then
        n=100
    else
        let n=n/1000
        let total_size2=total_size/1000
        let n=n*100/total_size2
        if [ $n == 100 ]; then
            n=99
        fi
    fi

    if [ "$2" = "done" ]; then
        let ota_saved_size=ota_saved_size+size
    fi

    echo "ota: data processed: $n% $size $total_size" 1>&2

    local_ota_cb process $n

}

# ota 开始升级回调
local_on_ota_start()
{
    echo "ota: started" 1>&2
    local_ota_cb started
}

# ota 升级失败回调
local_on_ota_error()
{
    echo "ota: error" 1>&2
    local_ota_cb failed
}

# ota 升级完成回调
local_on_ota_stop()
{
    local code=$1

    # code == 0 表示升级成功
    # 其他表示没有进行升级
    echo "ota: stoped $code" 1>&2
    local_ota_cb stop $code

}
