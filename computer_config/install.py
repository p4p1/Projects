#!/usr/bin/python
# -*- coding: utf-8 -*-
# Made by Leo smith
# install.py
# Help:
# install python-pip and python-apt

import os, sys      # system imports
import apt, pip     # installer imports
import getpass, grp # user and privilege imports
import urllib       # installer imports

class psetcfg():
    ''' psetcfg: python setup configuration tool,
    python class to install my config on an operating system under any debian
    operating system.
    Prerequesits: python-pip python-apt '''

    def __init__(self, argv=[]):
        self.pkg_list = [ "wireshark", "vim", "build-essential", "valgrind",
            "net-tools", "radare2", "php" ]
        self.pypkg_list = [ "termcolor", "scapy", "arp", "scrapy" ]
        self.users = [ getpass.getuser() ]
        for arg in argv:
            self.users.append(arg)
        if not sys.platform.startswith("linux2"):
            print >> sys.stderr, "[!!] You are not on linux!"
            sys.exit(84)
        if os.geteuid() != 0:
            print >> sys.stderr, "[!!] You are not root!"
            sys.exit(84)

    def set_bash_prompt(self):
        url_bashrc = "https://gist.githubusercontent.com/p4p1/3447d7aa3399dd2780a88bdbd545b5fb/raw/bf92bb78cbe5241c7cb19341fd6511df276e720b/bashrc%2520%257C%2520bash_profile"
        for user in self.users:
            if user == 'root':
                urllib.urlretrieve(url_bashrc, "/{0}/.bashrc".format(user))
            else:
                urllib.urlretrieve(url_bashrc, "/home/{0}/.bashrc".format(user))

    def vim_config_setup(self):
        url_vimrc = "https://gist.githubusercontent.com/p4p1/78586f1dad1c081410c2f917c85848b9/raw/f3b28657ca728379b14b74a5a1deadf14bb7e4c5/.vimrc"
        url_pyheader = "https://gist.githubusercontent.com/p4p1/78586f1dad1c081410c2f917c85848b9/raw/f3b28657ca728379b14b74a5a1deadf14bb7e4c5/dot_py.header"
        url_quantum = "https://gist.githubusercontent.com/p4p1/78586f1dad1c081410c2f917c85848b9/raw/f3b28657ca728379b14b74a5a1deadf14bb7e4c5/quantum.vim"
        url_plugvim = "https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim"
        for user in self.users:
            if user == 'root':
                urllib.urlretrieve(url_vimrc, "/{0}/.vimrc".format(user))
                try:
                    os.mkdir("/{0}/.vim".format(user))
                except:
                    print "/{0}/.vim already created!".format(user)
                try:
                    os.mkdir("/{0}/.vim/template/".format(user))
                except:
                    print "/{0}/.vim/template/ already created!".format(user)
                try:
                    os.mkdir("/{0}/.vim/autoload/".format(user))
                except:
                    print "/{0}/.vim/autoload/ already created!".format(user)
                try:
                    os.mkdir("/{0}/.vim/colors/".format(user))
                except:
                    print "/{0}/.vim/colors/ already created!".format(user)
                urllib.urlretrieve(url_pyheader, "/{0}/.vim/template/dot_py.header".format(user))
                urllib.urlretrieve(url_quantum, "/{0}/.vim/colors/quantum.vim".format(user))
                urllib.urlretrieve(url_plugvim, "/{0}/.vim/autoload/plug.vim".format(user))
            else:
                urllib.urlretrieve(url_vimrc, "/home/{0}/.vimrc".format(user))
                try:
                    os.mkdir("/home/{0}/.vim".format(user))
                except:
                    print "/home/{0}/.vim already created!".format(user)
                try:
                    os.mkdir("/home/{0}/.vim/template/".format(user))
                except:
                    print "/home/{0}/.vim/template/ already created!".format(user)
                try:
                    os.mkdir("/home/{0}/.vim/autoload/".format(user))
                except:
                    print "/home/{0}/.vim/autoload/ already created!".format(user)
                try:
                    os.mkdir("/home/{0}/.vim/colors/".format(user))
                except:
                    print "/home/{0}/.vim/colors/ already created!".format(user)
                urllib.urlretrieve(url_pyheader, "/home/{0}/.vim/template/dot_py.header".format(user))
                urllib.urlretrieve(url_quantum, "/home/{0}/.vim/colors/quantum.vim".format(user))
                urllib.urlretrieve(url_plugvim, "/home/{0}/.vim/autoload/plug.vim".format(user))

    def pip_wrapper(self, pkg_name):
        print "Installing {pkg}".format(pkg = pkg_name)
        arguments = [ "install", str(pkg_name) ]
        if hasattr(pip, "main"):
            pip.main(arguments)
        else:
            pip._internal.main(arguments)

    def apt_wrapper(self, pkg_name):
        cache = apt.cache.Cache()
        cache.update()
        cache.open()

        pkg = cache[pkg_name]
        if pkg.is_installed:
            print "{pkg_name} already installed".format(pkg_name=pkg_name)
        else:
            print "Installing {pkg}".format(pkg = pkg_name)
            pkg.mark_install()

            try:
                cache.commit()
            except Exception, arg:
                print >> sys.stderr, "Sorry, package installation failed:"
                print >> sys.stderr, str(arg)

    def main(self):
        print "Welcome to my personal operating system installer!"
        print "This program is made to install all of the package and software"
        print "that I use."
        for pkg in self.pkg_list:
            self.apt_wrapper(pkg)
        for pkg in self.pypkg_list:
            self.pip_wrapper(pkg)
        self.set_bash_prompt()
        self.vim_config_setup()

if __name__ == "__main__":
    user_list = []
    groups = grp.getgrall()
    for group in groups:
        for user in group[3]:
            if user not in user_list and os.path.isdir("/home/{0}/".format(user)):
                user_list.append(user)
    psetcfg(user_list).main()
