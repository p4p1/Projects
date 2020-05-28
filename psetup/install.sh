#!/bin/sh
# Run as Root | This is a quick setup script

apt install python-pip
pip2 install -U setuptools
apt install python-apt
pip2 install -U termcolor arrow
if [ -d /tmp/psetup/psetup-master ]; then
    pip2 install -U /tmp/psetup/psetup-master/
else
    pip2 install -U .
fi
