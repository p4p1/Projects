#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Script made by papi
# This script is made to setup any computer
# from scrath to my basic config for programming or anything basicly
# it will setup the terminal, install most import stuff
# create all of the configs for the server's.
# It works on any OS's and will instal everything.
# Windows is excluded, i don't use windows wtf?!

import os, sys
import platform

class setup():
	''' setup class for my computer, it will setup all of the important stuff '''

	def __init__(self, HOME_FOLDER="/User/k0oo", CWDIR="."):
		##### OPERATING SYSTEM DETECTION #####
		if platform.system() == 'Darwin':
			self.MAC_OS = True
			self.LINUX = False
		elif platform.system() == 'Windows':
			self.error("This OS is not suported!")
		else:
			self.LINUX = True
			self.MAC_OS = False
		##### DIRECTORY VARIABLES #####
		self.CWDIR = CWDIR + "/"
		self.BASH_CFG_FOLDER = self.CWDIR + "bash_configs/"
		self.EDITOR_CFG_FOLDER = self.CWDIR + "editor_config/"
		self.INSTALLER_FOLDER = self.CWDIR + "install/"
		self.SCRIPTS_FOLDER = self.CWDIR + "scripts/"
		self.THEME_FOLDER = self.CWDIR + "theme/"
		self.HOME_FOLDER = HOME_FOLDER + "/"
		self.PICTURE_FOLDER = self.HOME_FOLDER + "Picture/theme/"
		self.EDITOR_FOLDER = self.HOME_FOLDER + ".vim/"
		self.SCRIPT_FOLDER = self.HOME_FOLDER + ".scripts/"


	# error function, to display all of the errors in red!
	def error(msg="", err_code=-1):
		print "\x1B[31m",
		sys.stderr.write(msg)
		print "\x1B[0m"
		sys.exit(err_code)

	# Create the directories for this script
	def create_dir(self):
		try:
			if not os.path.isdir(self.EDITOR_FOLDER):
				print "\x1B[32mCreating folder {0}\x1B[0m".format(self.EDITOR_FOLDER)
				os.makedirs(self.EDITOR_FOLDER)
				os.makedirs(self.EDITOR_FOLDER+"colors/")
			if not os.path.isdir(self.SCRIPT_FOLDER):
				print "\x1B[32mCreating folder {0}\x1B[0m".format(self.SCRIPT_FOLDER)
				os.makedirs(self.SCRIPT_FOLDER)
			if not os.path.isdir(self.PICTURE_FOLDER):
				print "\x1B[32mCreating folder {0}\x1B[0m".format(self.PICTURE_FOLDER)
				os.makedirs(self.PICTURE_FOLDER)
			print "\x1B[36mAll folders created properly!\x1B[0m"
		except:
			self.error("Cannot create any of the directories provided by the script!")

	# load all of the bashrc files and setup the editor
	def load_cfg(self):
		if self.MAC_OS:
			print "\x1B[32mLoading on you're system: {0}\x1B[0m".format(self.BASH_CFG_FOLDER+"bash_profile")
			os.rename(self.BASH_CFG_FOLDER+"bash_profile", self.HOME_FOLDER+".bash_profile")
		elif self.LINUX:
			print "\x1B[32mLoading on you're system: {0}\x1B[0m".format(self.BASH_CFG_FOLDER+"bashrc")
			os.rename(self.BASH_CFG_FOLDER+"bashrc", self.HOME_FOLDER+".bashrc")
		else:
			self.error("This OS is not suported!")
		print "\x1B[32mLoading on you're system: {0}\x1B[0m".format(self.EDITOR_CFG_FOLDER+"vimrc")
		os.rename(self.EDITOR_CFG_FOLDER+"vimrc", self.HOME_FOLDER+".vimrc")
		print "\x1B[36mBash and vim setups have been installed properly\x1B[0m"
		os.rename(self.EDITOR_CFG_FOLDER+"quantum.vim", self.EDITOR_FOLDER+"colors/quantum.vim")
		print "\x1B[36mVim colors have been installed!\x1B[0m"
		os.rename(self.EDITOR_CFG_FOLDER+"c_main_header.txt", self.EDITOR_FOLDER+"c_main_header.txt")
		os.rename(self.EDITOR_CFG_FOLDER+"py_header.txt", self.EDITOR_FOLDER+"py_header.txt")
		os.rename(self.EDITOR_CFG_FOLDER+"bash_header.txt", self.EDITOR_FOLDER+"bash_header.txt")
		print "\x1B[36mVim Language headers ready...\x1B[0m"

	# load the scripts and the theme
	def load_scripts_theme(self):
		print "\x1B[32mLoading on you're system: {0}\x1B[0m".format(self.SCRIPTS_FOLDER+"call_home_script")
		os.rename(self.SCRIPTS_FOLDER+"call_home_script", self.SCRIPT_FOLDER+"call_home_script")
		print "\x1B[36mAll scripts installed properly!\x1B[0m"
		os.rename(self.THEME_FOLDER+"pingu.png", self.PICTURE_FOLDER+"pingu.png")
		os.rename(self.THEME_FOLDER+"wallpaper.jpg", self.PICTURE_FOLDER+"wallpaper.jpg")
		print "\x1B[36mTheme installed properly!\x1B[0m"

	# run the software installers
	def run_installers(self):
		print "\x1B[32Running installer programs\x1B[0m"
		if self.LINUX:
			os.system("chmod 755 "+self.INSTALLER_FOLDER+"linux_install.bash")
			os.system(self.INSTALLER_FOLDER+"linux_install.bash")
		elif self.MAC_OS:
			os.system("chmod 755 "+self.INSTALLER_FOLDER+"mac_install.bash")
			os.system(self.INSTALLER_FOLDER+"mac_install.bash")
		else:
			error("You're OS is not suported!")

if __name__ == "__main__":
	s = setup()
