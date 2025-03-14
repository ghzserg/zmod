#!/bin/sh

# 引入功能函数
source /etc/ota_bin/ota_utils.sh

# 引入ota设备端的方法
source /etc/ota_bin/ota_local_method.sh

# 保存img相关选项,并且清空img相关变量
save_img_config()
{
    local is_saved=0

    if [ "$img_name" = "" ]; then
        echo "img_name not set" 1>&2
        return 1
    fi

    if [ "$img_size" = "" ]; then
        echo "img_size not set" 1>&2
        return 1
    fi

    if [ "$img_md5" = "" ]; then
        echo "img_md5 not set" 1>&2
        return 1
    fi

    # 保存 kernel 的ota信息
    if [ "$img_type" = "kernel" ]; then
        if [ $ota_kernel != 0 ]; then
            echo "ota_kernel double set" 1>&2
            return 1
        fi
        is_saved=1
        ota_kernel=1
        ota_kernel_name=$img_name
        ota_kernel_size=$img_size
        ota_kernel_md5=$img_md5
    fi

    # 保存 rootfs 的ota信息
    if [ "$img_type" = "rootfs" ]; then
        if [ $ota_rootfs != 0 ]; then
            echo "ota_rootfs double set" 1>&2
            return 1
        fi
        is_saved=1
        ota_rootfs=1
        ota_rootfs_name=$img_name
        ota_rootfs_size=$img_size
        ota_rootfs_md5=$img_md5
    fi

    # 保存 rtos 的ota信息
    if [ "$img_type" = "rtos" ]; then
        if [ $ota_rtos != 0 ]; then
            echo "ota_rtos double set" 1>&2
            return 1
        fi
        is_saved=1
        ota_rtos=1
        ota_rtos_name=$img_name
        ota_rtos_size=$img_size
        ota_rtos_md5=$img_md5
    fi

    if [ $is_saved = 0 ]; then
        echo "can not support this img_type: $img_type" 1>&2
        return 1
    fi

    img_type=
    img_name=
    img_size=
    img_md5=

    return 0
}

check_img_config()
{
    local config_name=$1
    local config_value=$2

    if [ "$img_type" = "" ]; then
        echo "img_type not set before $config_name" 1>&2
        return 1
    fi

    if [ "$config_value" != "" ]; then
        echo "$config_name double set $config_value" 1>&2
        return 1
    fi
}

# 解析ota_update.in的配置信息
parse_ota_update_config()
{
    local file=$1
    local new_version=$2
    local result

    while read line;
    do
        # 解析 ota_version =
        result=`get_key_word "$line" "ota_version"`
        if [ $? = 0 ]; then
            ota_version=$result
            if [ "$ota_version" != "$new_version" ]; then
                echo "ota version check not ok: $ota_version != $new_version" 1>&2
                return 1
            fi
            continue
        fi

        # 解析 img_type =
        result=`get_key_word "$line" "img_type"`
        if [ $? = 0 ]; then
            if [ "$img_type" != "" ]; then
                save_img_config
                if [ $? != 0 ]; then
                    return 1
                fi
            fi
            img_type=$result
            continue
        fi

        # 解析 img_name =
        result=`get_key_word "$line" "img_name"`
        if [ $? = 0 ]; then
            check_img_config img_name "$img_name"
            if [ $? != 0 ]; then
                return 1
            fi
            img_name=$result
            continue
        fi

        # 解析 img_size =
        result=`get_key_word "$line" "img_size"`
        if [ $? = 0 ]; then
            check_img_config img_size "$img_size"
            if [ $? != 0 ]; then
                return 1
            fi
            img_size=$result
            continue
        fi

        # 解析 img_md5 =
        result=`get_key_word "$line" "img_md5"`
        if [ $? = 0 ]; then
            check_img_config img_md5 "$img_md5"
            if [ $? != 0 ]; then
                return 1
            fi
            img_md5=$result
            continue
        fi
    done < $file

    if [ "$img_type" != "" ]; then
        save_img_config
        if [ $? != 0 ]; then
            return 1
        fi
    fi

    echo ota_kernel $ota_kernel 1>&2
    echo ota_kernel_name $ota_kernel_name 1>&2
    echo ota_kernel_size $ota_kernel_size 1>&2
    echo ota_kernel_md5 $ota_kernel_md5 1>&2
    echo ota_rootfs $ota_rootfs 1>&2
    echo ota_rootfs_name $ota_rootfs_name 1>&2
    echo ota_rootfs_size $ota_rootfs_size 1>&2
    echo ota_rootfs_md5 $ota_rootfs_md5 1>&2
    echo ota_rtos $ota_rtos 1>&2
    echo ota_rtos_name $ota_rtos_name 1>&2
    echo ota_rtos_size $ota_rtos_size 1>&2
    echo ota_rtos_md5 $ota_rtos_md5 1>&2

    return 0
}

# ota 服务器地址
ota_site=`local_get_ota_site`
if [ $? != 0 ]; then
    echo "failed to get ota site" 1>&2
    return 1
fi

# ota 版本文件地址
ota_site_config=$ota_site/ota_config.in

mkdir -p /tmp/ota_wget_msg/
rm -rf /tmp/ota_wget_msg/*
mkdir -p /tmp/ota/
rm -rf /tmp/ota/*
cd /tmp/ota/

# 获取服务器的 ota_config.in 文件
wget_retry $ota_site_config ota_site_config.in 20
if [ $? != 0 ]; then
    echo "failed to get $ota_site_config" 1>&2
    local_on_ota_error
    exit 1
fi

# 服务器的 main os 版本信息
new_main_os_version=`get_key_word_from_file ota_site_config.in current_version`
if [ $? != 0 ] || [ "$new_main_os_version" = "" ]; then
    echo "failed to get main os released version" 1>&2
    local_on_ota_error
    exit 1
fi

# 获取当前 ota 版本
current_version=`local_get_current_version`
if [ $? != 0 ]; then
    echo "failed to get local current version" 1>&2
    local_on_ota_error
    exit 1
fi

# 比较本地 ota 版本和服务器的 ota 版本
if [ "$current_version" -ge "$new_main_os_version" ]; then
    echo "ota not update: current version is newest $current_version $new_main_os_version"
    local_on_ota_stop version_is_new
    exit 2
fi

ota_site_dir=$ota_site/main_os/ota_v$new_main_os_version
ota_site_version_ok=$ota_site/main_os/ota_v$new_main_os_version/ota_v$new_main_os_version.ok

# 获取服务器的 ota_v'N'/ota_v'N'.ok 文件
# 防止 ota 部署的过程中出错，另外可以用于开发者测试时不创建此文件
wget_retry $ota_site_version_ok ota_site_version.ok 20
if [ $? != 0 ]; then
    echo "failed to get $ota_site_version_ok" 1>&2
    local_on_ota_error
    exit 1
fi

# 获取服务器的 ota_update.in 文件
wget_retry $ota_site_dir/ota_update.in ota_site_update.in 20
if [ $? != 0 ]; then
    echo "failed to get $ota_site_dir/ota_update.in" 1>&2
    local_on_ota_error
    exit 1
fi

# 获取服务器的 main os 信息
ota_version=

img_type=
img_name=
img_size=
img_md5=

ota_kernel=0
ota_kernel_name=
ota_kernel_size=
ota_kernel_md5=

ota_rootfs=0
ota_rootfs_name=
ota_rootfs_size=
ota_rootfs_md5=

ota_rtos=0
ota_rtos_name=
ota_rtos_size=
ota_rtos_md5=

parse_ota_update_config ota_site_update.in $new_main_os_version
if [ $? != 0 ]; then
    echo "failed to parse ota update config" 1>&2
    local_on_ota_error
    exit 1
fi

# 获得 kernel 对应的设备节点
if [ $ota_kernel = 1 ]; then
    ota_kernel_dev=`local_get_current_kernel_dev_path`
    if [ $? != 0 ]; then
        echo "failed to get local kernel dev path" 1>&2
        local_on_ota_error
        exit 1
    fi

    local_device_check_size $ota_kernel_dev $ota_kernel_size 100
    if [ $? != 0 ]; then
        echo "failed to check kernel device size" 1>&2
        local_on_ota_error
        exit 1
    fi
fi

# 获得 rootfs 对应的设备节点
if [ $ota_rootfs = 1 ]; then
    ota_rootfs_dev=`local_get_current_rootfs_dev_path`
    if [ $? != 0 ]; then
        echo "failed to get local rootfs dev path" 1>&2
        local_on_ota_error
        exit 1
    fi

    local_device_check_size $ota_rootfs_dev $ota_rootfs_size 100
    if [ $? != 0 ]; then
        echo "failed to check kernel device size" 1>&2
        local_on_ota_error
        exit 1
    fi
fi

# 获得 rtos 对应的设备节点
if [ $ota_rtos = 1 ]; then
    ota_rtos_dev=`local_get_rtos_dev_path`
    if [ $? != 0 ]; then
        echo "failed to get local rtos dev path" 1>&2
        local_on_ota_error
        exit 1
    fi

    local_device_check_size $ota_rtos_dev $ota_rtos_size 100
    if [ $? != 0 ]; then
        echo "failed to check kernel device size" 1>&2
        local_on_ota_error
        exit 1
    fi
fi

if [ $ota_kernel = 1 ] || [ $ota_rootfs = 1 ] || [ $ota_rtos = 1 ]; then
    echo "device check ok"
    echo "ready to update main os"
    exit 0
else
    echo "ota not update: no device selected"
    local_on_ota_stop no_device_update
    exit 2
fi
