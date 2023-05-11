#!/bin/bash

# Check if the user is root
if [[ $EUID -ne 0 ]]; then
  echo "This script must be run as root"
  exit 1
fi

if [[ -f /etc/lsb-release || -f /etc/debian_version ]]; then
  echo "Install Debian/Ubuntu dependencies"
  apt update
  apt install -y make cmake g++ git libconfig-dev libsfml-dev zenity
elif [[ -f /etc/fedora-release ]]; then
  echo "Install Fedora dependencies"
  dnf update
  dnf install g++ make cmake git libconfig-devel SFML zenity
else
  echo "Unsupported distribution"
  exit 1
fi

# Install stb_image
echo "Install stb_image"
if [[ -f /usr/local/include/stb_image.h ]]; then
  echo "stb_image already installed"
else
  cd /tmp || exit 1
  git clone https://github.com/nothings/stb.git
  cp stb/stb_image.h /usr/local/include/
  rm -r stb
fi

echo "Install dependencies done"
