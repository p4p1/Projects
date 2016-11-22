#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Script made by papi

import os
import sys

class counter():
	'Counter class'

	def __init__(self, inital, *arg):
		self.numOfValues = len(arg)
		self.initialFund = inital
		self.arr = []
		for i in arg:
			self.arr.append(i)

	def debug(self):
		print "-" * 10
		print "numOfValues = %d" % self.numOfValues
		print "initialFund = %d" % self.initialFund
		print "self.arr = ", self.arr

	def main(self):
		total = self.initialFund
		for i in self.arr:
			total -= i
		print "End funds = ", total

if __name__ == "__main__":
	count = counter(50+37 , 13, 20, 14)
	count.main()
	sys.exit(0)
