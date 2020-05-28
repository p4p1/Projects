import os, sys
import arrow, urllib2

from termcolor import colored

class setupEnvironement():
    ''' configure vim for my personnal use '''

    def __init__(self, path=os.environ['HOME']):
        print colored("[*] Starting Vim setup....", "green")
        if path is None:
            self.dname = os.environ['HOME']
        else:
            self.dname = path
        self.url = "https://gist.githubusercontent.com/p4p1/6e738c7379040969de18d97f1a7d5a80/raw/5c6a6580d1d9216a1a3466a479274b5c28f39cbc/vimrc"

    def download_script(self):
        print colored("[^] Downloading script...", "blue")
        response = urllib2.urlopen(self.url)
        with open(self.dname+'/.vimrc', "w") as fp:
            fp.write(response.read())
            fp.close()
        response = urllib2.urlopen("https://gist.githubusercontent.com/p4p1/6e738c7379040969de18d97f1a7d5a80/raw/b5242ba81fb3d4d59d231dca3b033a761f233908/quantum.vim")
        with open(self.dname+'/.vim/colors/quantum.vim', 'w') as fp:
            fp.write(response.read())
            fp.close()
        respnse = urllib2.urlopen("https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim")
        with open(self.dname+'/.vim/autoload/plug.vim', 'w') as fp:
            fp.write(respnse.read())
            fp.close()

    def download_template(self):
        print colored("[^] Downloading templates...", "blue")
        response = urllib2.urlopen("https://gist.githubusercontent.com/p4p1/6e738c7379040969de18d97f1a7d5a80/raw/b5242ba81fb3d4d59d231dca3b033a761f233908/dot_c.header")
        with open(self.dname+'/.vim/template/dot_c.header', 'w') as fp:
            fp.write(response.read())
            fp.close()
        response = urllib2.urlopen("https://gist.githubusercontent.com/p4p1/6e738c7379040969de18d97f1a7d5a80/raw/b5242ba81fb3d4d59d231dca3b033a761f233908/dot_h.header")
        with open(self.dname+'/.vim/template/dot_h.header', 'w') as fp:
            fp.write(response.read())
            fp.close()
        print colored("[*] Templates installed", "green")

    def create_dirs(self):
        print colored("[*] Seting up vim folders...", "green")
        print colored("[^] Creating %s/.vim" % self.dname, "blue")
        if not os.path.exists(self.dname+'/.vim'):
            os.makedirs(self.dname+'/.vim')
        print colored("[^] Creating %s/.vim/colors" % self.dname, "blue")
        if not os.path.exists(self.dname+'/.vim/colors'):
            os.makedirs(self.dname+'/.vim/colors')
        print colored("[^] Creating %s/.vim/template" % self.dname, "blue")
        if not os.path.exists(self.dname+'/.vim/template'):
            os.makedirs(self.dname+'/.vim/template')
        print colored("[^] Creating %s/.vim/autoload" % self.dname, "blue")
        if not os.path.exists(self.dname+'/.vim/autoload'):
            os.makedirs(self.dname+'/.vim/autoload')

    def vim_exists(self):
        if os.path.exists('/usr/bin/vim'):
            return True
        return False

    def config(self):
        if not self.vim_exists():
            print colored("[!!] Please install Vim on this machine", "red")
        self.create_dirs()
        self.download_template()
        self.download_script()
        print colored("[*] All done!", "green")

if __name__ == "__main__":
    setupEnvironement(".").config()
