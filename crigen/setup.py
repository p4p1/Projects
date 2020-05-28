#!/usr/bin/python
# -*- coding: utf-8 -*-
# Made by Leo smith
# setup.py
# Description:
# Setup file for crigen a criterion test generator

from setuptools import setup
import crigen

setup( name = "crigen",
        version = crigen.__version__,
        description = "criterion test generator",
        url = "http://github.com/p4p1/crigen",
        author = "p4p1",
        author_email = "leo.smith@epitech.eu",
        license = "None",
        packages = ["crigen"],
        scripts = ["bin/crigen"],
        zip_safe = False )
