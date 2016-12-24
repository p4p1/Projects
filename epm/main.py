#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Script made by papi

import sys, os
import socket

class pme():
	'database for the email and password class'

	def __init__(self, fp, lang="html"):
		try:
			self.file = open(fp, 'a')
		except:
			print "Can't open file!"
			sys.exit(-1)
		self.lang = lang
		self.file_name = fp

	def addAcount(self, user, psswd):
		line = """
			Username : %s
			Password : %s
		""" % (user, psswd)
		self.file.write(line)
	def listen(self, port):
		f = open(self.file_name, "r")
		s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		content = f.read()
		s.bind(("0.0.0.0", port))
		s.listen(1)
		while True:
			print "Waiting for new connection"
			new_s, c_addr = s.accept()
			try:
				print "Connection from", c_addr
				data = new_s.recv(1024)
				print data
				new_s.sendall(content)
			finally:
				new_s.close()

if __name__ == "__main__":
	db = pme("Table.html")
	db.addAcount("hy", "hy")
	db.listen(8888)
