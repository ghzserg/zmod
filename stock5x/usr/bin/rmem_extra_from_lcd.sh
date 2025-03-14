#!/bin/sh

lcd_mem_start=0
lcd_mem_size=0

cmdline=`cat /proc/cmdline`

for str in $cmdline;
do
    if [ "${str#lcd_mem=}" = "$str" ]; then
        continue
    fi

    str=${str#lcd_mem=}

    if [ "${str%%M@*}" = "$str" ]; then
        continue
    fi

    lcd_mem_size=${str%M@*}
    lcd_mem_start=${str#*M@}

    let lcd_mem_start=lcd_mem_start+0
    if [ $? != 0 ]; then
        lcd_mem_start=0
        lcd_mem_size=0
        continue
    fi

    let lcd_mem_size=lcd_mem_size*1024*1024
    if [ $? != 0 ]; then
        lcd_mem_start=0
        lcd_mem_size=0
        continue
    fi

    break
done

cmd_rmem_extra $lcd_mem_start $lcd_mem_size