#!/usr/bin/python
# -*- coding: utf-8 -*-
# Made by Leo smith
# crigen_usage.py
# Description:
# Usage script

import crigen
import sys

class Usage():
    ''' The Usage class for crigen '''

    def __init__(self, color=False):
        self.version_str = str(crigen.__version__)
        self.executable_name = sys.argv[0]
        self.repo_url = "https://github.com/p4p1/crigen"
        self.color = color

    def info_msg(self):
        print "%s, Version: %s, made by: p4p1 (Leo Smith). [%s]" %\
        (self.executable_name, self.version_str, self.repo_url)
        print "This software is used to generate Criterion Tests. I do not own,"
        print "Criterion nor any units tests that gets generated by this tools"
        print "for more information about Criterion see:",
        print "[https://github.com/Snaipe/Criterion]"

    def options(self):
        print "\t%s --make\t\t[Create the Makefile for units tests]" %\
                self.executable_name
        print "\t%s --srcs=[path]\t[Set the path of the source code]" %\
                self.executable_name
        print "\t%s --include=[path]\t[Set the path of the header files]" %\
                self.executable_name
        print "\t%s --lib=[path]\t[Set the path of the libraries]" %\
                self.executable_name
        print "\t%s --help\t\t[Show this message]" %\
                self.executable_name
        print "\t%s -v\t\t[verbose]" % self.executable_name

    def usage(self):
        self.info_msg()
        print "Usage:"
        self.options()


if __name__ == "__main__":
    # Display the general information about the software
    Usage().usage()
