# psetup - Leo's config installer

Psetup is the swiss army knife of environement setup. It will install my
config to program and it will create the acording environement to the language
provided.

## Install:
```
curl -fLo /tmp/psetup.zip --create-dirs \
    https://github.com/p4p1/psetup/archive/master.zip ;\
    unzip -d /tmp/psetup /tmp/psetup.zip ;\
    sudo chmod +x /tmp/psetup/psetup-master/install.sh ;\
    sudo /tmp/psetup/psetup-master/install.sh
```

## Usage:

```
psetup -all        # do a full setup
psetup -c [name]   # create a C env
psetup -py [name]  # create a py env
psetup -md [name]  # create a md env
psetup -html [name]# create a html env
psetup -pool [name]# create pool env [EPITECH ONLY]
psetup -rep [name] # create a repo for anything
psetup -blih       # install custom blih [EPITECH ONLY]
psetup -vim        # install my vim config
psetup -bash       # install bash config
psetup -fish       # install fish config
psetup -cfg        # update the configartion of psetup
psetup -pymodule   # install python modules
psetup -software   # install all of the important software
psetup -git        # setup git
psetup -man        # show the info page
psetup -h          # display the usage
```

