import os, sys
import arrow, pip

from termcolor import colored

class setupEnvironement():
    ''' Setup the environement for python programming '''

    def __init__(self, name):
        self.pname = name
        self.package_list = [ 'scapy', 'arrow' ]

    def create_dirs(self):
        try:
            if not os.path.exists(self.pname):
                os.makedirs(self.pname)
                print colored("[^] Creating %s" % self.pname, "blue")
            if not os.path.exists(self.pname+'/bin'):
                os.makedirs(self.pname+'/bin')
                print colored("[^] Creating %s" % (self.pname+'/bin'), "blue")
            if not os.path.exists(self.pname+'/'+self.pname):
                os.makedirs(self.pname+'/'+self.pname)
                print colored("[^] Creating %s" %\
                        (self.pname+'/'+self.pname), "blue")
        except:
            print colored("[!!] Permission Error", "red")
            sys.exit(-1)
        print colored("[*] Directory setup: Done.", "green")

    def create_files(self):
        print colored("[^] Create file %s" %\
                (self.pname+'/'+self.pname+'/'+self.pname+'.py'), "blue")
        with open(self.pname+'/'+self.pname+'/'+self.pname+'.py', "w") as fp:
            fp.write("import os, sys\n\n")
            fp.close()
        print colored("[^] Create file %s" %\
                (self.pname+'/'+self.pname+'/__init__.py'), "blue")
        with open(self.pname+'/'+self.pname+'/__init__.py', "w") as fp:
            fp.write("from %s import *\n" % self.pname)
            fp.close()
        print colored("[^] Create file %s" %\
                (self.pname+'/bin/'+self.pname), "blue")
        with open(self.pname+'/bin/'+self.pname, "w") as fp:
            fp.write("#!/usr/bin/env python\n\n")
            fp.close()
        print colored("[^] Create file %s" %\
                (self.pname+'/setup.py'), "blue")
        with open(self.pname+'/setup.py', "w") as fp:
            fp.write("from setuptools importetup\n\n")
            fp.write("setup( name='%s',\n" % self.pname)
            fp.write("\t\tversion='0.0.1',\n")
            fp.write("\t\tdescription='<..>',\n")
            fp.write("\t\turl='<..>',\n")
            fp.write("\t\tauthor='<..>',\n")
            fp.write("\t\tauthor_email='<..>',\n")
            fp.write("\t\tlicense='<..>',\n")
            fp.write("\t\tpackages=['%s'],\n" % self.pname)
            fp.write("\t\tscripts=['bin/%s'],\n" % self.pname)
            fp.write("\t\tzip_safe=False )\n")
            fp.close()

    def install_modules(self):
        for pckg in self.package_list:
            print colored("[>>] Installing %s.." % pckg, "magenta")
            try:
                pip.main(['install', pckg])
                print colored("[*] Done!", "green")
            except:
                print colored("[!!] Error installing %s" % pckg, "red")

    def setup(self):
        print colored('[*] Creating env for %s...' % name, "green")
        self.create_dirs()
        self.create_files()

if __name__ == "__main__":
    setupEnvironement("test").setup()
    setupEnvironement(None).install_modules()
