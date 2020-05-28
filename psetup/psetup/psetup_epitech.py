from termcolor import colored
import os, urllib, pip, tarfile
import getpass

import updator

class setupConfig():

    def __init__(self, cfg):
        print colored("[*] Starting Epitech repo config...", "green")
        self.blih_dl_link = "https://api.github.com/repos/p4p1/psetup/tarball"
        self.cfg = cfg

    def install_blih(self):
        if os.path.exists("/usr/local/bin/blih"):
            print colored("[^] blih already installed", "blue")
            return
        updator.set_root()
        urllib.urlretrieve(self.blih_dl_link, "/tmp/blih.tar.gz")
        tar = tarfile.open("/tmp/blih.tar.gz", "r:gz")
        tar.extractall()
        tar.close()
        os.chdir("/tmp/")
        for dirr in os.listdir('.'):
            if "bocal-blih" in dirr:
                os.chdir('/tmp/'+dirr)
                os.rename("bin/blih", "/usr/bin/blih")
                break
        print colored("[^] Installed blih", "blue")

    def setup_blih(self):
        os.system("ssh-keygen")
        print colored("[^] Uploading key, Make shure you are om the eptech network",\
               "blue")
        raw_input("Press [Enter] to continue...")
        os.system("blih -u %s sshkey upload %s/.ssh/id_rsa.pub" %\
                (self.cfg.login, os.environ['HOME']))
        os.system("ssh git@git.epitech.eu")

    def create_repo(self, repo_name, psswd = None):
        if psswd == None:
            psswd = getpass.getpass(prompt=colored("[$] Password: ", "magenta"))
        print colored("[^] Creating repo %s ...." % repo_name, "blue")
        os.system("echo '%s' | blih -u %s repository create %s" % (psswd, self.cfg.login, repo_name))
        print colored("[^] Setting the permissions on the repo for ramassage-tek"\
                , "blue")
        os.system("echo '%s' | blih -u %s setacl %s ramassage-tek r" % (psswd, self.cfg.login, repo_name))
        os.system("git clone git@git.epitech.eu:/%s/%s" % (self.cfg.login, repo_name))
        print colored("[*] Repo %s clonned...." % repo_name, "green")
