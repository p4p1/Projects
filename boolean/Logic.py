""" Logic.py
A class with all of the logic operations
"""

import os, sys

class logic():
	'logic class'

	def __init__(self, inpt1, inpt2):
		self.first_input = inpt1
		self.second_input = inpt2

	def or_gate(self):
		print self.first_input or self.second_input

	def and_gate(self):
		print self.first_input and self.second_input

	def not_gate_first(self):
		print not( self.first_input )

	def not_gate_second(self):
		print not( self.second_input )

if __name__ = "__main__":
	lgc = logic(True, False)
	lgc.or_gate()
