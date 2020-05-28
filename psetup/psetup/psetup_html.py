import os, sys
import arrow

from termcolor import colored

class setupEnvironement():
    ''' Setup the HTML environnement for programming '''

    def __init__(self, name):
        print colored("[*] Starting the HTML environnement....", "green")
        self.pname = name   # define project name

    def create_dirs(self):
        try:
            if not os.path.exists(self.pname):
                print colored("[^] Creating %s" % self.pname, "blue")
                os.makedirs(self.pname)
            if not os.path.exists(self.pname+'/img'):
                print colored("[^] Creating %s" % (self.pname+'/img'), "blue")
                os.makedirs(self.pname+'/img')
        except:
            print colored("[!!] Permission Error", "red")
            sys.exit(-1)
        print colored("[*] Directory setup", "green")

    def create_source(self):
        print colored("[^] Creating index file", "blue")
        with open(self.pname+'/index.html', "w") as fp:
            fp.write("<!DOCTYPE html>\n")
            fp.write("<html>\n")
            fp.write("\t<head>\n")
            fp.write("\t\t<title>%s</title>\n" % self.pname)
            fp.write('\t\t<meta name="viewport" content="width=device-width, initial-scale=1">\n')
            fp.write("\t</head>\n")
            fp.write("\t<body>\n")
            fp.write("\t</body>\n")
            fp.write("</html")
            fp.close()

    def setup(self):
        self.create_dirs()
        self.create_source()

if __name__ == "__main__":
    setupEnvironement('test').setup()
