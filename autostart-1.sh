#!/bin/bash

if [[ -z "$1" ]]; then
	sleep 8
fi

# Numlock
numlockx on

# Disable screen blanking and power management, set keyboard repeat rate
xset s off && xset s noblank && xset -dpms

# Set keyboard repeat rate
while [ $(xset -q | rg "auto repeat delay" | awk '{print $4}') -ne 250 ]; do
	# xset r rate 330 40
	xset r rate 250 40
	sleep 0.5
done

# Set volume
pactl set-sink-volume @DEFAULT_SINK@ 100%
pkill -RTMIN+10 dwmblocks &

dunstify "Done"
