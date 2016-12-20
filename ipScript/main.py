#!/usr/bin/env python
import urllib
import socket
import time
import sys
import re
import os

#\t\t\t<tr>\n\t\t\t\t<th scope=\"col\" width=\"150\">%s</th>\n\t\t\t\t<th scope=\"col\">%s</th>\n\t\t\t\t<th scope=\"col\">%s</th>\n\t\t\t\t<th scope=\"col\">%s</th>\n\t\t\t</tr>\n

fp = open("Table.html", 'a')

# external ip
site = urllib.urlopen("http://checkip.dyndns.org/").read()
grab = re.findall('([0-9]+\.[0-9]+\.[0-9]+\.[0-9]+)', site)
address = grab[0]

#current date & computer name
date = time.strftime("%d/%m/%Y")
name = socket.gethostname()

text = "\t\t\t<tr>\n\t\t\t\t<th scope=\"col\" width=\"150\">%s</th>\n\t\t\t\t<th scope=\"col\">%s</th>\n\t\t\t\t<th scope=\"col\" colspan=\"2\" width=\"200\">%s</th>\n\t\t\t</tr>\n" % (date, name, address)
#print(text)

c = raw_input('>>')
fp.write(text)
fp.close()
