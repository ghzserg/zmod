#!/bin/sh

rmem_start=0
rmem_size=0

rtos_start=0
rtos_size=0

cmdline=`cat /proc/cmdline`

for cmdstr in $cmdline;
do
    if [ "${cmdstr#rmem=}" = "$cmdstr" ] && [ "${cmdstr#rtos_size=}" = "$cmdstr" ]; then
        continue
    fi

    if [ "${cmdstr#rmem=}" != "$cmdstr" ]; then
        str=${cmdstr#rmem=}
    else
        str=${cmdstr#rtos_size=}
    fi

    if [ "${str%%M@*}" = "$str" ]; then
        continue
    fi

    size=${str%M@*}
    start=${str#*M@}

    let start=start+0
    if [ $? != 0 ]; then
        start=0
        size=0
        continue
    fi

    let size=size*1024*1024
    if [ $? != 0 ]; then
        start=0
        size=0
        continue
    fi

    if [ "${cmdstr#rmem=}" != "$cmdstr" ]; then
        let rmem_start=start+0
        let rmem_size=size+0
    else
        let rtos_start=start+0
        let rtos_size=size+0
    fi

done
insmod rmem_manager.ko  rmem_start=$rmem_start rmem_size=$rmem_size rtos_start=$rtos_start rtos_size=$rtos_size
