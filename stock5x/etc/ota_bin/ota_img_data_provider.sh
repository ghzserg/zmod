#!/bin/sh

# 注意:
#   本文件获取img_name000N的数据直接输出
#   所以只能用echo_err来输出打印信息，不能用echo，否则将导致镜像错误
echo_err()
{
    echo $* 1>&2
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

# 获得文件大小
size_file()
{
    local file=$1
    local result

    result="`ls -l -L $file`"
    if [ "$?" != "0" ]; then
        echo_err "ls failed: $file"
        return 1
    fi

    result=`get_word "$result" 4`
    if [ "result" = "" ]; then
        echo_err "ls failed 2: $file"
        return 1
    fi

    echo $result
    return 0
}

# 检查文件是否存在，以及是否为空
check_file()
{
    local file=$1
    local size

    if [ ! -e "$file" ]; then
        echo_err "error: $file not exist"
        return 1
    fi

    size=`size_file $file`
    if [ $? != 0 ]; then
        echo_err "error: failed to get size: $file"
        return 1
    fi

    if [ $size = 0 ]; then
        echo_err "error: do not support empty file: $file"
        return 1
    fi

    return 0
}

set_write_ok()
{
    echo "ota ok: $img_name $img_size" > $img_name.ok
}

set_write_failed()
{
    echo "ota ok: $1" > $img_name.failed
}

img_name=$1
img_size=$2

if [ "$img_name" = "" ]; then
    echo_err "img_name is not set"
    exit 1
fi

if [ "$img_size" = "" ]; then
    echo_err "img_size is not set"
    exit 1
fi

i=0
total_size=0

while true;
do
    num=`printf "%04d" $i`
    file=$img_name.$num

    # 等待 /tmp/ota/img_name000i.ok
    # 或者 /tmp/ota/img_name.quit 退出
    while true;
    do
        if [ -e $file.ok ]; then
            break
        fi

        if [ -e $img_name.quit ]; then
            echo_err "get $img_name.quit, now quit"
            set_write_failed "ota quit"
            exit 1
        fi

        sleep 0.01
    done

    # 检查 /tmp/ota/img_name000i
    check_file $file
    if [ $? != 0 ]; then
        echo_err "failed to check $file"
        set_write_failed "check file $file"
        exit 1
    fi

    size=`size_file $file`

    # 输出 /tmp/ota/img_name000i
    cat $file

    # 创建 /tmp/ota/img_name000i.done
    echo $size > $file.done

    # 如果 文件大小完成，那么退出
    let i=i+1
    let total_size=total_size+size
    if [ $total_size -ge $img_size ]; then
        echo_err "$img_name read ok, now quit"
        set_write_ok
        exit 0
    fi
done
