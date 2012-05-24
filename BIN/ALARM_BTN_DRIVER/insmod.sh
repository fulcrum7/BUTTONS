#!/bin/bash
device="fma1125dc_alarm"
module=$device
mode="664"
# invoke insmod with all arguments we got
# and use a pathname, as newer modutils don't look in . by default
rmmod $module.ko 
/sbin/insmod ./$module.ko $* || exit 1
# remove stale nodes
rm -f /dev/${device}
major=$(cat /proc/devices | grep $device | awk '{print $1}')
echo $major

mknod /dev/${device} c $major 0


chmod $mode /dev/${device}

