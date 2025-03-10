export TSLIBDIR=/opt/tslib-1.12
export TSLIB_TSEVENTTYPE=INPUT
export TSLIB_CONSOLEDEVICE=none
export TSLIB_FBDEVICE=/dev/fb0
export TSLIB_TSDEVICE=/dev/input/event0
export TSLIB_CALIBFILE=/opt/tslib-1.12/etc/pointercal
export TSLIB_CONFFILE=/opt/tslib-1.12/etc/ts.conf
export TSLIB_PLUGINDIR=/opt/tslib-1.12/lib/ts
export QWS_MOUSE_PROTO=TSLIB:/dev/input/event0
export LD_PRELOAD=/opt/tslib-1.12/lib/libts.so


export QTDIR=/opt/qt-gm-4.8.6
export QT_QPA_PLATFORM_PLUGIN_PATH=/opt/qt-gm-4.8.6/plugins
export QT_QPA_PLATFORM=linuxfb:tty=/dev/fb0:size=600x1024:mmsize=115x170:offset=0
export QWS_DISPLAY=transformed:rot180:LinuxFB:mmWidth115:mmHeight170:0
export QT_QWS_FONTDIR=/opt/qt-gm-4.8.6/lib/fonts
export QT_QPA_GENERIC_PLUGINS=tslib

export LD_LIBRARY_PATH=/opt/qt-gm-4.8.6/lib:$LD_LIBRARY_PATH

export LD_LIBRARY_PATH=/opt/openssl-1.0.2d/lib:$LD_LIBRARY_PATH

export LD_LIBRARY_PATH=/opt/cloud/curl-7.55.1/lib:$LD_LIBRARY_PATH

