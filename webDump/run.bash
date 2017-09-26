#!/bin/bash
# script for basic execution, this mode is pretty stupid. i will improve this script later on

E_NOROOT=-1
script_name=webdump

if [[ $EUID -ne 0 ]]; then
	echo "[*] Must be run as root!"
	exit $E_NOROOT
fi

while [ 1 ]; do
  ./$script_name -c 1  >> file.out
done
