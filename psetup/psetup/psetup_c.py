import os, sys
import arrow

from psetup import psetup_git
from termcolor import colored

class setupEnvironement():
    ''' Setup the C environnement for programming '''

    def __init__(self, name, cfg, git=False):
        print colored("[*] Starting up C environnement...", "green")
        self.pname = name       # define project name
        self.cfg = cfg
        self.git = git

    def create_dirs(self):
        try:
            if not os.path.exists(self.pname):
                print colored("[^] Creating %s" % self.pname, "blue")
                os.makedirs(self.pname)
            if not os.path.exists(self.pname+'/src'):
                print colored("[^] Creating %s" % (self.pname+'/src'), "blue")
                os.makedirs(self.pname+'/src')
            if not os.path.exists(self.pname+'/include'):
                print colored("[^] Creating %s" % (self.pname+'/include'), "blue")
                os.makedirs(self.pname+'/include')
            if not os.path.exists(self.pname+'/test/'):
                print colored("[^] Creating %s" % (self.pname+'/test'), "blue")
                os.makedirs(self.pname+'/test')
        except:
            print colored("[!!] Permission Error", "red")
            sys.exit(-1)
        print colored("[*] Directory setup", "green")

    def setup(self):
        if self.git:
            psetup_git.c_repo_git_setup(self.cfg, self.pname)
        self.create_dirs()


if __name__ == "__main__":
    import psetup_config
    setupEnvironement('test', psetup_config.config("",'','','')).setup()
