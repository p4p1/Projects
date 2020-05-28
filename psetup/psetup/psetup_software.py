import apt
import os, sys

from termcolor import colored

class setupEnvironement():
    ''' install all of my goto apps '''

    def __init__(self):
        print colored("[*] Starting installement script...", "green")
        self.pckg_list = [ 'vim', 'fish', 'git', 'moc', 'nasm', 'gparted',\
                'chromium-browser', 'nmap', 'fping', 'php', 'dialog',\
                'whois', 'wireshark' ]
        self.cache = apt.cache.Cache()

    def install_pckg(self, pckg):
        pkg = self.cache[pckg]
        if pkg.is_installed:
            print colored("[!!] %s is already installed" % pckg, "red")
            print colored("[!!] Skipping it...", "red")
        else:
            print colored("[>>] Preparing install %s" % pckg, "magenta")
            pkg.mark_install()

            try:
                print colored("[>>] Installing %s" % pckg, "magenta")
                self.cache.commit()
            except Exception, arg:
                print colored("[!!] %s Instalation failed!" % pckg, "red")
                print str(arg)

    def set_root(self):
        euid = os.geteuid()
        if euid != 0:
            print colored("[!!] The installation process needs root privileges.."\
                    , "red")
            args = ['sudo', sys.executable] + sys.argv + [os.environ]
            os.execlpe('sudo', *args)
        else:
            print colored("[!!] You already have permission to install!", "red")

    def config(self):
        print colored("[^] Updating cache of apt...", "blue")
        self.set_root()
        self.cache.update()
        for pkg_name in self.pckg_list:
            self.install_pckg(pkg_name)
        print colored("[*] Everything is installed!", "green")

if __name__ == "__main__":
    setupEnvironement().config()
