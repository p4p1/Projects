#!/bin/bash
# Made by: papii
# Description:
# Installer program for mac based systems that use brew.
# it will have all of the basic composents i need.
if [ $EUID -eq "0" ]; then

	brew tap cosmo0920/mingw_w64

	if [[ "$1" = "1" ]]; then # basic install

		printf "\e[1;32m[*] Basic only install ...\e[m\n"
		brew install vim								# installing the editor
		brew install git								# installing version control software
		brew install fping							# network analyser tool
		brew install nmap								# network maper
		brew install whois							# get whois info for domain name
		brew install dialog							# dialog command
		brew install mingw-w64							# install mingw54 cros compiler


	elif [[ "$1" = "2" ]]; then # advanced install

		printf "\[\e[1;32m\][*] Advanced only install ...\[\e[m\]\n"
		brew install dfu-programmer			# install the programmer for custom arduino
		brew install php70							# install php
		brew install shc								# install shell compiler
		# brew install wireshark					# install tshark util
		# there is an error with tshark on mac osX i don;t know how to change it,
		# this is the error:
		#		-Please set WIRESHARK_APP_DIR to its proper location and try again.

	else  # full install

		printf "\[\e[1;32m\][*] full install ...\[\e[m\]\n"
		brew install vim								# installing the editor
		brew install git								# installing version control software
		brew install fping							# network analyser tool
		brew install nmap								# network maper
		brew install whois							# get whois info for domain name
		brew install dfu-programmer			# install the programmer for custom arduino
		brew install php70							# install php
		brew install shc								# install shell compiler
		#brew install wireshark					# install tshark util
		brew install dialog							# dialog command
		brew install mingw-w64							# install mingw54 cros compiler

	fi

else

	printf "\e[;31m[!] you are not running this script as root\n"
	printf "[!] The programs have not been installed\e[m\n"

fi
