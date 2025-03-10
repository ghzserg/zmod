#!/bin/sh

unset LD_PRELOAD
unset LD_LIBRARY_PATH

if ! [ -f "/opt/config/mod_data/midi/$1" ]
    then
        echo "Файл mod_data/midi/$1 не найден"
        exit 1
fi

audio midi -m "/opt/config/mod_data/midi/$1" &
