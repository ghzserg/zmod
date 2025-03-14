#!/bin/sh

recovery_version_dir="/usr/data/.recovery"
recovery_version_file="recovery_version"

# 获得recovery的版本号
local_get_recovery_version()
{
    local str=

    str=`cat $recovery_version_dir"/"$recovery_version_file`
    if [ $? != 0 ]; then
        return 1
    fi

    echo ${str#*recovery_version=}

    return 0
}

# 设置rec的版本号
local_set_recovery_version()
{
    local version="$1"

    mkdir -p $recovery_version_dir
    touch $recovery_version_dir"/"$recovery_version_file
    if [ ! -e $recovery_version_dir"/"$recovery_version_file ]; then
        echo "version file not exist!"
        return 1
    fi

    echo "recovery_version=$version" > $recovery_version_dir"/"$recovery_version_file
}
