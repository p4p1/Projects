#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Script made by papi
# epm a email password manager, create a html file with a list of email with
# their password and the date they where added.

import sys, os
import socket
import time

data = """
<!DOCTYPE html>
<html>
	<head>
		<title>Email PassManager</title>
	</head>
	<body>
		<table>
 			<tr>
				<th class="date">Date</th>
				<th class="email">Email/Username</th>
				<th class="pass">Password</th>
				<th class="extra">Extra</th>
			</tr>
"""

class epm():
	'database for the email and password class'

	def __init__(self, fp="Table.html", lang="html"):
		try:
			f = open(fp, "r")
			f.close()

		except:
			f = open(fp, "w")
			f.write(data)
			f.close

		self.lang = lang
		self.file_name = fp
		self.date = time.strftime("%d/%m/%Y")

	def addAcount(self, user, psswd):

		try:
			fp = open(self.file_name, 'a')

		except:
			print "Can't open file!"
			sys.exit(-1)

		line = """
			<tr>
				<td class="date">%s</td>
				<td class="email">%s</td>
				<td class="pass">%s</td>
				<td class="extra">...</td>
			</tr>
		""" % (self.date, user, psswd)
		fp.write(line)
		fp.close()

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
	db = epm()
	db.addAcount("Hello", "World")
	db.listen(8888)
