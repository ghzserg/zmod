#!/bin/sh

rtos_start=0
rtos_size=0

cmdline=`cat /proc/cmdline`

for str in $cmdline;
do
    if [ "${str#rtos_size=}" = "$str" ]; then
        continue
    fi

    str=${str#rtos_size=}

    if [ "${str%%M@*}" = "$str" ]; then
        continue
    fi

    rtos_size=${str%M@*}
    rtos_start=${str#*M@}

    let rtos_start=rtos_start+0
    if [ $? != 0 ]; then
        rtos_start=0
        rtos_size=0
        continue
    fi

    let rtos_size=rtos_size*1024*1024
    if [ $? != 0 ]; then
        rtos_start=0
        rtos_size=0
        continue
    fi

    break
done

cmd_rmem_extra $rtos_start $rtos_size