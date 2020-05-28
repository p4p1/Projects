import os, sys
import arrow, urllib2

from termcolor import colored

class setupEnvironement():
    ''' configure bash for my personnal use '''

    def __init__(self, path=os.environ['HOME']):
        print colored("[*] Starting Bash setup...", "green")
        if path is None:
            self.dname = os.environ['HOME']
        else:
            self.dname = path
        self.url = "https://gist.githubusercontent.com/p4p1/3447d7aa3399dd2780a88bdbd545b5fb/raw/257e5f3333b225a6d60b08f3895c5d0e1d7a7d01/bashrc%2520%257C%2520bash_profile"

    def download_script(self):
        print colored("[^] Downloading script...", "blue")
        response = urllib2.urlopen(self.url)
        with open(self.dname+"/.bashrc", "w") as fp:
            fp.write(response.read())
            fp.close()

    def bash_exists(self):
        if os.path.exists('/bin/bash'):
            return True
        return False

    def config(self):
        if not self.bash_exists():
            print colored("[!!] Please install bash on this machine", "red")
        self.download_script()
        print colored("[*] All done!", "green")

if __name__ == "__main__":
    setupEnvironement(".").config()
