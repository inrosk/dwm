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
# run "gsd-xsettings" "/usr/libexec/gsd-xsettings"

# Wallpaper
# nitrogen --restore &

# Gnome
## Keyring
# dbus-update-activation-environment --all &
# gnome-keyring-daemon --start --components=secrets &

## Polkit
# run "polkit-gnome-authentication-agent-1" "/usr/libexec/polkit-gnome-authentication-agent-1"

# KDE
## Keyring
# run "kwallet" "/usr/lib/pam_kwallet_init"

## Polkit
# run "polkit-kde-auth" "/usr/lib/polkit-kde-authentication-agent-1"

# Clipmenu
# run "clipmenud"

# keyd
# XDG_CURRENT_DESKTOP=dwm keyd-application-mapper -d &

# Dropbox
# run "dropbox" "dropbox start"

# Night color
# run "redshift"

# Notifications
# run "dunst"

# Netowrk manager
# run "nm-applet"

# DWM blocks
# run "dwmblocks"

# Compositor
# run "compton"
