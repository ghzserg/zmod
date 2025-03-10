#!/home/pi/klippy-env/bin/python
# -*- coding: utf-8 -*-

import sys
import os
import serial

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: %s <dev>" % (sys.argv[0]))
        sys.exit(0)

    dev = serial.Serial(sys.argv[1], 115200)
    while True:
        print("cmd: ")
        cmd = sys.stdin.readline()
        if cmd == '\n':
            continue
        dev.write(cmd.encode())
        while True:
            recv = dev.readline()
            print('recv: %s' % (recv))
            #if recv[:2] == 'ok':
            #   break
            if 'ok' in str(recv,'utf-8'):
                break
    dev.close()
