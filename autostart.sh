#!/bin/bash

running_apps=$(ps aux)

function run {
	# search_name? command
	is_running=$(echo "$running_apps" | rg $1)
	if ! [ "$is_running" ]; then
		if [ $# -eq 2 ]; then
			# echo "launching $1"
			$2 &
		else
			# echo "launching $1"
			$1 &
		fi

	# else
	# 	echo "$1 already running"
	fi
}

# Gnome theme
run "gsd-xsettings" "/usr/libexec/gsd-xsettings"

# # Numlock
# numlockx on

# # Disable screen blanking and power management, set keyboard repeat rate
# /usr/bin/xset s off && /usr/bin/xset s noblank && /usr/bin/xset -dpms &
# /usr/bin/xset r rate 350 40 &

# Wallpaper
nitrogen --restore &

# Keyring
# dbus-update-activation-environment --all &
# gnome-keyring-daemon --start --components=secrets &

# Polkit
run "polkit-gnome-authentication-agent-1" "/usr/libexec/polkit-gnome-authentication-agent-1"

# run "kwallet" "/usr/lib/pam_kwallet_init"
# run "polkit-kde-auth" "/usr/lib/polkit-kde-authentication-agent-1"

# Clipmenu
run "clipmenud"

# keyd
XDG_CURRENT_DESKTOP=dwm keyd-application-mapper -d &

# Dropbox
run "dropbox" "dropbox start"

# Mouse speed
# xinput set-prop 8 305 0, 1 &
# xinput set-prop 8 303 -0.5 &
# xinput set-prop 11 310 0, 1 &
# xinput set-prop 11 307 0.1 &
# xinput set-prop "Logitech Gaming Mouse G600" "libinput Accel Profile Enabled" 0, 1 &
# xinput set-prop "Logitech Gaming Mouse G600" "libinput Accel Speed" 0.1 &

# Emacs daemon
# emacs --daemon /home/karol/Dropbox/org/ &

# Night color
# run "redshift"

# Notifications
run "dunst"

# Netowrk manager
# run "nm-applet"

# DWM blocks
run "dwmblocks"

# Compositor
run "compton"

# # Set volume
# /usr/bin/pactl set-sink-volume @DEFAULT_SINK@ 100%
# pkill -RTMIN+10 dwmblocks &

/home/karol/.config/suckless/dwm/autostart-1.sh &
