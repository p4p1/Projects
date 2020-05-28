import os, sys
import arrow, urllib2

from termcolor import colored

class setupEnvironement():
    ''' configure fish for my personnal use '''

    def __init__(self, path=os.environ['HOME']+'/.config/fish'):
        print colored("[*] Starting fish setup...", "green")
        if path is None:
            self.dname = os.environ['HOME']+'/.config/fish'
        else:
            self.dname = path
        self.url = "https://gist.githubusercontent.com/p4p1/7678ec92964a77e0f31551dbcd508b10/raw/20b0e26566d5eafdf4d901636b930f6a98da010b/config.fish"
        if not os.path.exists(self.dname):
            os.makedirs(self.dname)

    def download_script(self):
        print colored("[^] Downloading script...", "blue")
        response = urllib2.urlopen(self.url)
        with open(self.dname+"/config.fish", "w") as fp:
            fp.write(response.read())
            fp.close()

    def bash_exists(self):
        if os.path.exists('/usr/bin/fish'):
            return True
        return False

    def config(self):
        if not self.bash_exists():
            print colored("[!!] Please install fish on this machine", "red")
        self.download_script()
        print colored("[*] All done!", "green")

if __name__ == "__main__":
    setupEnvironement(".").config()
