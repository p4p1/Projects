import os, sys
from termcolor import colored
import getpass

import psetup_epitech as pepi

def c_repo_git_setup(cfg, pname):
        print colored("[^] setting up git command util", "blue")
        print colored("[#] Do you want to connect it to github?", "yellow")
        print colored("[!!] Make shure you have create the repo online!", "red")
        q = raw_input("(Y/n) ")
        if "Y" in q:
            os.chdir(pname)
            os.system("git init")
            os.system("git remote add origin git@github.com:%s/%s"\
                    % (cfg.git_name, pname))
        print colored("[#] Do you want to use blih?", "yellow")
        q = raw_input("(Y/n) ")
        if "Y" in q:
            psswd = getpass.getpass(prompt=colored("[$] Password: ", "magenta"))
            pepi.setupConfig(cfg).create_repo(pname, psswd)
            os.system("echo '%s' | blih -u %s repository create %s" % (psswd, cfg.login, pname))
            os.system("echo '%s' | blih -u %s repository setacl %s ramassage-tek r" % \
                    (psswd, cfg.login, pname))
            os.system("echo '%s' | blih -u %s repository getacl %s" % (psswd, cfg.login, pname))
        print colored("[*] Done.", "green")
