from termcolor import colored
import os
import psetup_epitech as pepitech

class config():
    ''' Configuration for file generator '''
    login = None
    name = None
    git_email = None
    git_name = None

    def __init__(self, login=None, name=None, git_login=None, git_name=None):
        self.login = login
        self.name = name
        self.git_email = git_login
        self.git_name = git_name
        self.directory = os.environ['HOME'] + '/.config/psetup'
        self.flogin = self.directory + '/psetup_login'
        self.fname = self.directory + '/psetup_name'
        self.fgit_login = self.directory + '/psetup_git_login'
        self.fgit_name = self.directory + '/psetup_git_name'

    def ask_cfg(self):
        print colored("[#] What is your' email? ", "yellow"),
        self.login = raw_input()
        print colored("[#] What is your' name? ", "yellow"),
        self.name = raw_input()
        print colored("[#] What is your' git email? ", "yellow"),
        self.git_email = raw_input()
        print colored("[#] What is your' git name? ", "yellow"),
        self.git_name = raw_input()

    def git_cfg(self):
        print colored("[#] Do you want to configure for personal use?", "yellow")
        q = raw_input(colored("(Y/n)", "magenta"))
        if os.path.exists("/usr/bin/git") and self.git_name != None\
                or self.git_email != None:
            os.system("git config --global user.name \"%s\"" % self.git_name)
            os.system("git config --global user.email \"%s\"" % self.git_email)
            os.system("git config --global push.default simple")
            print colored("[*] git has been configured..", "green")
        else:
            print colored("[!!] git not installed!", "red")
        print colored("[^] Generating keygen", "blue")
        if q == 'Y' or q == 'y':
            os.system("ssh-keygen -t rsa -b 4096 -C \"%s\"" % self.git_email)
            print colored("[*] Copy your' key inside of the github settings to use\
                ssh", "green")
        else:
            pepitech.setupConfig(self).setup_blih()

    def is_cfg(self):
        if os.path.isfile(self.flogin) and os.path.isfile(self.fname) and\
                os.path.isfile(self.fgit_login) and os.path.isfile(self.fgit_name):
            return True
        return False

    def save_cfg(self):
        with open(self.flogin, "w") as fp:
            fp.write(self.login)
            fp.close()
        os.system("chmod 777 %s" % self.flogin)
        with open(self.fname, "w") as fp:
            fp.write(self.name)
            fp.close()
        os.system("chmod 777 %s" % self.fname)
        with open(self.fgit_login, "w") as fp:
            fp.write(self.git_email)
            fp.close
        os.system("chmod 777 %s" % self.fgit_login)
        with open(self.fgit_name, "w") as fp:
            fp.write(self.git_name)
            fp.close()
        os.system("chmod 777 %s" % self.fgit_name)

    def load_cfg(self):
        with open(self.flogin, "r") as fp:
            self.login = fp.read()
            fp.close()
        with open(self.fname, "r") as fp:
            self.name = fp.read()
            fp.close()
        with open(self.fgit_login, "r") as fp:
            self.git_email = fp.read()
            fp.close()
        with open(self.fgit_name, "r") as fp:
            self.git_name = fp.read()
            fp.close()

    def setup(self):
        if not os.path.exists(self.directory):
            os.makedirs(self.directory)
        if self.is_cfg():
            self.load_cfg()
        else:
            self.ask_cfg()
            self.save_cfg()
            self.git_cfg()

if __name__ == "__main__":
    cfg = config().setup()
