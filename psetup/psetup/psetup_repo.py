import os, sys

from psetup import psetup_git
from termcolor import colored

class setupEnvironement():
    ''' Setup environement for a repo... '''

    def __init__(self, name, cfg):
        print colored("[*] Starting %s environnement..." % name\
                , "green")
        self.pname = name
        self.dirr_list = []
        self.exx_list = []
        self.cfg = cfg
        self.git = git

    def create_dirs(self):
        try:
            if not os.path.exists(self.pname):
                print colored("[^] Creating %s" % self.pname, "blue")
                os.makedirs(self.pname)
            print colored("[^] Dow you want to create dirs?", "blue")
            q = raw_input(colored("[#] (Y/n) ", "yellow"))
            if q == 'Y':
                print colored("[^] Enter the number of dirs..", "blue")
                no = int(raw_input(colored("[#] -> ", "yellow")))
                i = 0
                while i < no:
                    self.dirr_list.append(raw_input("[#:%d] -> " % i, "yellow"))
                    i+=1
                i = 0
                while i < no:
                    if not os.path.exists(self.pname+'/'+self.dirr_list[i]):
                        print colored("[^] Creating %s"\
                                % (self.pname+'/'+self.dirr_list[i]), "blue")
                        os.makedirs(self.pname+'/'+self.dirr_list[i])
                        self.get_ex()
                    i+=1
        except:
            print colored("[!!] Permission Error", "red")
            sys.exit(-1)
        print colored("[*] Directory setup", "green")

    def create_ex(self, exn):
        with open(self.pname+'/'+exn, "w") as fp:
            fp.write("\n")
            fp.close()

    def get_ex(self):
        print colored("[^] Do you want to create exercices inside of this dir?", "blue")
        q = raw_input(colored("[#] (Y/n) ", "yellow"))
        if q == 'Y':
            print colored("[^] Enter the number of ex..", "blue")
            no = int(raw_input(colored("[#] -> ", "yellow")))
            i = 0
            while i < no:
                self.exx_list.append(raw_input("[#:%d] -> " % i, "yellow"))
                i+=1
            i = 0
            while i < no:
                if not os.path.exists(self.pname+'/'+self.dirr_list[i]):
                    print colored("[^] Creating %s"\
                            % (self.pname+'/'+self.dirr_list[i]), "blue")
                    self.create_ex(self.pname+'/'+self.dirr_list[i])
                i+=1


    def setup(self):
        psetup_git.c_repo_git_setup(self.cfg, self.pname)
        self.create_dirs()
        os.chdir(self.pname)
        os.system("git add .")
        os.system("git commit -m 'setup...'")
        os.system("git push")
