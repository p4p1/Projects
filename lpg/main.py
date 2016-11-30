#!/usr/bin/env python
# -*- Code by papii	-*-
# -*- main.py		-*-

import os, sys
import itertools
from datetime import date

class lpg(self):
	''' Leo\'s password generator '''

	def __init__(self,  length, name, lname, age, month, day, color, fruit, *arg):
		self.length = length
		self.first_name = name
		self.last_name = lname
		self.age = age
		self.born = int(date.today().year) - age
		self.bd_month = month
		self.bd_day = day
		self.color = color
		self.fruit = fruit
		self.additional = []
		for i in arg:
			self.additional.append(i)

	def generate(self, filename=None):
		''' Main function '''
		

if __name__ == "__main__":
	gen = lpg()
	gen.generate()
