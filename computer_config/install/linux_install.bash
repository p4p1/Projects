#!/bin/bash
# Made by: papii
# Description:
#	Installer program for linux based systems that use apt-get.
# it will have all of the basic composents i need.

if [ $EUID -eq "0" ]; then

	if [[ "$1" = "1" ]]; then	# basic install

		printf "\[\e[1;32m\][*] Basic only install ...\[\e[m\]\n"
		apt-get install vim											# install the editor
		apt-get install build-essential					# install gcc g++ etc..
		apt-get install ncurses-dev							# install ncurses lbrary
		apt-get install libunwind8 libicu55			# install other library
		apt-get install mingw-w64								# install windows compiler for linux
		apt-get install git											# install git, for projects
		apt-get install nmap										# install network scanner
		apt-get install fping										# fping to get connected computers
		apt-get install whois										# whois to get info from domain name
		apt-get install lighttpd								# light web server to host pages
		apt-get install php-cgi									# php cgi to work on php projects
		apt-get install dialog									# dialog command

	elif [[ "$1" = "2" ]]; then	# advanced install

		printf "\[\e[1;32m\][*] Advanced only install ...\[\e[m\]\n"
		apt-get install shc											# shc to compile bash scripts
		apt-get install wireshark								# network scanner to see packets
		apt-get install irssi										# irc client for terminal
		apt-get install dfu-programmer dfu-util	# dfu programmer to mod arduinos
		apt-get install openjdk-8-jdk-headless	# java dev kit to work in java
		apt install musl-tools									# an other c compiler
		apt-get install aircrack-ng							# aircrack to brute force WEP keys
		apt-get install unrar										# unrar to open .rar compressed file
		apt-get install arduino									# arduino

	else	# full install

		printf "\[\e[1;32m\][*] full install ...\[\e[m\]\n"
		apt-get install vim											# install the editor
		apt-get install build-essential					# install gcc g++ etc..
		apt-get install ncurses-dev							# install ncurses lbrary
		apt-get install libunwind8 libicu55			# install other library
		apt-get install mingw-w64								# install windows compiler for linux
		apt-get install git											# install git, for projects
		apt-get install nmap										# install network scanner
		apt-get install fping										# fping to get connected computers
		apt-get install whois										# whois to get info from domain name
		apt-get install lighttpd								# light web server to host pages
		apt-get install php-cgi									# php cgi to work on php projects
		apt-get install shc											# shc to compile bash scripts
		apt-get install wireshark								# network scanner to see packets
		apt-get install irssi										# irc client for terminal
		apt-get install dfu-programmer dfu-util	# dfu programmer to mod arduinos
		apt-get install openjdk-8-jdk-headless	# java dev kit to work in java
		apt install musl-tools									# an other c compiler
		apt-get install aircrack-ng							# aircrack to brute force WEP keys
		apt-get install unrar										# unrar to open .rar compressed file
		apt-get install arduino									# arduino
		apt-get install dialog									# dialog command

	fi

else

	printf "\[\e[;31m\][!] you are not running this script as root\n"
	printf "[!] The programs have not been installed\[\e[m\]\n"

fi
