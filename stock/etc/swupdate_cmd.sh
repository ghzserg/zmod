#!/bin/sh
#Copyright (c) 2018-2020 Allwinner Technology Co. Ltd.


# ============================================================================
# GLOBAL FUNCTIONS
# ============================================================================
swupdate_cmd()
{
    while true
    do
        swu_param=$(fw_printenv -n swu_param 2>/dev/null)
        swu_software=$(fw_printenv -n swu_software 2>/dev/null)
        swu_mode=$(fw_printenv -n swu_mode 2>/dev/null)
        swu_version=$(fw_printenv -n swu_version 2>/dev/null)
        echo "swu_param: ##$swu_param##"
        echo "swu_software: ##$swu_software##"
        echo "swu_mode: ##$swu_mode##"

        check_version_para=""
        [ x"$swu_version" != x"" ] && {
            echo "now version is $swu_version"
            check_version_para="-N $swu_version"
        }

        [ x"$swu_mode" = x"" ] && {
            echo "no swupdate_cmd to run, wait for next swupdate"
            return
        }

        echo "###now do swupdate###"
        echo "###log in $swupdate_log_file###"

        echo "## swupdate -v $check_version_para $swu_param -e $swu_software,$swu_mode ##"
        #swupdate -v $check_version_para $swu_param -e "$swu_software,$swu_mode" >> "$swupdate_log_file" 2>&1
        swupdate -v $check_version_para $swu_param -e "$swu_software,$swu_mode"

        swu_next=$(fw_printenv -n swu_next 2>/dev/null)
        echo "swu_next: ##$swu_next##"
        if [ x"$swu_next" = "xreboot" ]; then
            fw_setenv swu_next
            reboot -f
        fi

        sleep 1
    done
}

# ============================================================================
# GLOBAL VARIABLES
# ============================================================================
swupdate_log_file=/mnt/UDISK/swupdate.log

# ============================================================================
# MAIN
# ============================================================================
mkdir -p /var/lock

[ $# -ne 0 ] && {
    echo "config new swupdate"
    rm -f $swupdate_log_file
    swu_input=$*
    echo "swu_input: ##$swu_input##"

    swu_param=$(echo " $swu_input" | sed -E 's/ -e +[^ ]*//')
#    echo "swu_param: ##$swu_param##"
    echo "swu_param $swu_param" > /tmp/swupdate_param_file
    swu_param_e=$(echo " $swu_input" | awk -F ' -e ' '{print $2}')
    swu_param_e=$(echo "$swu_param_e" | awk -F ' ' '{print $1}')
    swu_software=$(echo "$swu_param_e" | awk -F ',' '{print $1}')
#    echo "swu_software: ##$swu_software##"
    echo "swu_software $swu_software" >> /tmp/swupdate_param_file
    swu_mode=$(echo "$swu_param_e" | awk -F ',' '{print $2}')
#    echo "swu_mode: ##$swu_mode##"
    echo "swu_mode $swu_mode" >> /tmp/swupdate_param_file
    fw_setenv -s /tmp/swupdate_param_file
    sync

    echo "## set swupdate_param done ##"
}

swupdate_cmd
