#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Script made by Leo Smith
# Description: setup script for any computer under unix

import os, sys
import getpass, urllib, subprocess

#--------------------global variables------------------
operating_system = sys.platform
MAC_OS = 'darwin'
LINUX_OS = 'Linux'
packages = [ 'nmap', 'fping', 'vim', 'git', 'mingw-w64', 'whois',\
        'dialog', 'irssi', 'lighttpd', 'php-cgi', 'shc',\
        'dfu-programmer', 'dfu-util', 'python-pip' ]
python-packages = [ 'thefuck' ]

#--------------------go to home folder-----------------
if operating_system == MAC_OS:
    os.chdir('/Users/%s/' % (getpass.getuser()))
elif operating_system == LINUX_OS:
    os.chdir('/home/%s/' % (getpass.getuser()))
else:
    sys.stderr.write('OS Not suported')
    sys.exit(-1)

#-------------------clear home folder-----------------
if os.path.exists('.vimrc'):
    os.remove('.vimrc')
if os.path.exists('.bashrc'):
    os.remove('.bashrc')
if not os.path.exists('.vim/'):
    os.mkdirs('.vim/')
    os.mkdirs('.vim/colors')
else:
    if not os.path.exists('.vim/colors'):
        os.mkdirs('.vim/colors')
if not os.path.exists('.vim/autoload'):
    os.mkdirs('.vim/autoload')

#-------------------download everything--------------
urllib.urlretrieve("[github link]/bashrc", ".bashrc")
urllib.urlretrieve("[github link]/vimrc", ".vimrc")
urllib.urlretrieve("[github link]/color_theme", "color_theme")
urllib/urlretrieve("https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim", ".vim/autoload/plug.vim")

for i in packages:
    print 'Installing %s ...' % i
    if operating_system == LINUX_OS:
        proc = subprocess.Popen('apt-get install -y %s'%i, shell=True, stdin=None, stdout=open("/dev/null", "w"), stderr=None, executable="/bin/bash")
    else:
        proc = subprocess.Popen('brew install -y %s'%i, shell=True, stdin=None, stdout=open("/dev/null", "w"), stderr=None, executable="/bin/bash")

    proc.wait()
print 'all command line software has benn instaled'
print 'run :PlugInstall to finish vim installation'
