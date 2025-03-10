# tslib                                                                                
echo "export tslib"                                                                    
export TSLIBDIR=/opt/tslib-1.12
export TSLIB_TSDEVICE=/dev/input/event0
export TSLIB_CONFFILE=${TSLIBDIR}/etc/ts.conf
export TSLIB_PLUGINDIR=${TSLIBDIR}/lib/ts
if [ -e /opt/software1/pointercal ]; then
    export TSLIB_CALIBFILE=/opt/software1/pointercal
    export POINTERCAL_FILE=/opt/software1/pointercal
else
   export TSLIB_CALIBFILE=${TSLIBDIR}/etc/pointercal
   export POINTERCAL_FILE=${TSLIBDIR}/etc/pointercal
fi
export TSLIB_CONSOLEDEVICE=none
export TSLIB_FBDEVICE=/dev/fb0
export LD_LIBRARY_PATH=${TSLIBDIR}/lib:$LD_LIBRARY_PATH
