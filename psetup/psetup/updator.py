import urllib, urllib2, tarfile
import os, pip, sys
import psetup
import json

from termcolor import colored

def download_latest():
    os.chdir('/tmp/')
    urllib.urlretrieve("https://api.github.com/repos/p4p1/psetup/tarball", "/tmp/psetup.tar.gz")
    tar = tarfile.open("/tmp/psetup.tar.gz", "r:gz")
    tar.extractall()
    tar.close()

def set_root():
    euid = os.geteuid()
    if euid != 0:
        print colored("[!!] The installation process needs root privileges.."\
                , "red")
        args = ['sudo', sys.executable] + sys.argv + [os.environ]
        os.execlpe('sudo', *args)
    else:
        print colored("[!!] You already have permission to install!", "red")

def verrify_latest(cond=False):
    print colored("[*] Checking if in need of an update...", "green")
    response = urllib2.urlopen(\
            "https://api.github.com/repos/p4p1/psetup/releases/latest")
    data = response.read()
    format_data = json.loads(data)
    if not psetup.__version__ == format_data['tag_name'].strip('v') or cond:
        print colored("[^] Currently on version %s updating to %s" % \
                (psetup.__version__, format_data['tag_name'].strip('v')), "blue")
        download_latest()
        os.chdir('/tmp/')
        for dirr in os.listdir('.'):
            if "p4p1-psetup" in dirr:
                set_root()
                os.chdir('/tmp/'+dirr)
                pip.main(['install', '.'])
                break
        print colored("[^] Finished update..", "blue")
    else:
        print colored("[^] No updates needed", "blue")

def need_update():
    response = urllib2.urlopen(\
            "https://api.github.com/repos/p4p1/psetup/releases/latest")
    data = response.read()
    format_data = json.loads(data)
    if not psetup.__version__ == format_data['tag_name'].strip('v'):
        return True
    return False

if __name__ == "__main__":
    verrify_latest(True)
