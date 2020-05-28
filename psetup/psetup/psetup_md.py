import os, sys
import arrow

from termcolor import colored

class setupEnvironement():
    ''' Setup the markdown environnement for taking courses '''

    def __init__(self, name):
        print colored("[*] Creating environnement for %s..." % name, "green")
        self.pname = name

    def create_dirs(self):
        try:
            if not os.path.exists(self.pname):
                os.makedirs(self.pname)
                print colored("[^] Creating %s" % self.pname, "blue")
        except:
            print colored("[!!] Permission Error" ,"red")

    def readme_exists(self):
        if not os.path.exists('readme.md') or not\
        os.path.exists('README.md'):
            return True


    def create_readme(self):
        print colored("[^] Creating README.md", "blue")
        with open(self.pname+"/README.md", "w") as fp:
            fp.write("# %s" %self.pname)
            fp.write("\n\n<..>")
            fp.close()

    def create_files(self):
        print colored("[^] Creating %s/%s.md" %(self.pname, self.pname), "blue")
        with open(self.pname+'/'+self.pname+'.md', "w") as fp:
            fp.write("# %s\n" % self.pname)
            fp.write("\n<..>")
            fp.close()

    def setup(self):
        self.create_dirs()
        if self.readme_exists():
            self.create_readme()
        self.create_files()

if __name__ == "__main__":
    setupEnvironement('test').setup()
