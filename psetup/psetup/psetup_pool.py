import os, sys
import arrow

from psetup import psetup_git
from termcolor import colored

class setupEnvironement():
    ''' Setup the CPool environnement for programming '''

    def __init__(self, name, cfg, git=False):
        print colored("[*] Starting %s environnement..." % name \
                , "green")
        self.pname = name
        self.cfg = cfg
        self.git = git
        self.func_name = []
        self.func_porto = []

    def create_dirs(self):
        try:
            if not os.path.exists(self.pname):
                print colored("[^] Creating %s" % self.pname, "blue")
                os.makedirs(self.pname)
            if not os.path.exists(self.pname+'/test/'):
                print colored("[^] Creating %s" % (self.pname+'/tests'), "blue")
                os.makedirs(self.pname+'/tests')
            if not os.path.exists(self.pname+'/bin/'):
                print colored("[^] Creating %s" % (self.pname+'/bin'), "blue")
                os.makedirs(self.pname+'/bin')
        except:
            print colored("[!!] Permission Error", "red")
            sys.exit(-1)
        print colored("[*] Directory setup", "green")

    def create_header(self, fname):
        print colored("[^] Creating header in %s" % \
                (self.pname+'/'+fname+'.h'), "blue")
        with open(self.pname+'/'+fname+'.h', "w") as fp:
            fp.write("/*\n")
            fp.write("** EPITECH PROJECT, 2017\n")
            fp.write("** %s\n" % fname)
            fp.write("** File description:\n")
            fp.write("** <..>\n")
            fp.write("*/\n")
            fp.write("#ifndef %s_H_\n" % fname.upper())
            fp.write("#define %s_H_\n\n" % fname.upper())
            for func in self.func_porto:
                fp.write("%s;\n" % func)
            fp.write("\n#endif /* end of %s.h header file */" % fname)
            fp.close()

    def create_source(self, fname, proto):
        print colored("[^] Creating source in %s" % \
                (self.pname+'/'+fname+'.c'), "blue")
        with open(self.pname+'/'+fname+'.c', "w") as fp:
            fp.write("/*\n")
            fp.write("** EPITECH PROJECT, 2017\n")
            fp.write("** %s\n" % fname)
            fp.write("** File description:\n")
            fp.write("** <..>\n")
            fp.write("*/\n")
            fp.write("\nvoid my_putchar(char c);\n%s\n" % proto)
            fp.close()
        print colored("[^] Creating test source in %s" % \
                (self.pname+'/tests/tests_'+fname+'.c'), "blue")
        with open(self.pname+'/tests/tests_'+fname+'.c', "w") as fp:
            fp.write("/*\n")
            fp.write("** EPITECH PROJECT, 2017\n")
            fp.write("** %s\n" % fname)
            fp.write("** File description:\n")
            fp.write("** <..>\n")
            fp.write("*/\n")
            fp.write("#include <criterion/criterion.h>\n")
            fp.write("\n%s;\n\n" % proto)
            fp.write("Test(%s, <..>)\n" % fname)
            fp.write("{\n}\n")
            fp.close()
        print colored("[^] Creating my_putchar in /tmp/my_putchar.c", "blue")
        with open("/tmp/my_putchar.c", "w") as fp:
            fp.write("#include <unistd.h>\n\n")
            fp.write("void my_putchar(char c)\n")
            fp.write("{\n")
            fp.write("\twrite(1, &c, 1);\n")
            fp.write("}")
            fp.close()

    def create_makefile(self):
        print colored("[^] Creating Makefile in %s" % \
                (self.pname+'/tests/Makefile'), "blue")
        with open(self.pname+'/tests/Makefile', "w") as fp:
            fp.write('#\n')
            fp.write("# EPITECH PROJECT, 2017\n")
            fp.write("#\n")
            fp.write("# File decription:\n")
            fp.write("# Makefile for unit tests.\n")
            fp.write("\n")
            fp.write("SRC_DIR=\t$(realpath ..)\n")
            fp.write("\n")
            fp.write("SRC=\t\t")
            for func in self.func_name:
                fp.write("$(SRC_DIR)/%s.c \\\n\t\t\t" % func)
            fp.write("SRC_UT_DIR=\t$(realpath .)\n")
            fp.write("\n")
            fp.write("SRC_UT=\t\t")
            for func in self.func_name:
                fp.write("$(SRC_UT_DIR)/tests_%s.c \\\n\t\t\t" % func)
            fp.write("\nOBJ=\t\t$(SRC:.c=.o) $(SRC_UT:.c=.o)\n")
            fp.write("GCDA=\t\t$(SRC:.c=.gcda) $(SRC_UT:.c=.gcda)\n")
            fp.write("GCNO=\t\t$(SRC:.c=.gcno) $(SRC_UT:.c=.gcno)\n")
            fp.write("\n")
            fp.write("CFLAGS=\t\t-Wall -Wextra -Werror --coverage\n")
            fp.write("LDFLAGS=\t-lcriterion -lgcov -L../lib/my/ -lmy\n")
            fp.write("NAME=\t\tunits\n")
            fp.write("\n")
            fp.write("all:\t\t$(NAME) clean\n")
            fp.write("$(NAME):\t$(OBJ)\n")
            fp.write("\tgcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)\n")
            fp.write("clean:\n")
            fp.write("\trm -rf $(OBJ)\n")
            fp.write("\trm -rf $(GCDA)\n")
            fp.write("\trm -rf $(GCNO)\n")
            fp.write("fclean:\t\tclean\n")
            fp.write("\trm -rf $(NAME)\n")
            fp.write("re:\t\tfclean all\n")

    def create_gitignore(self):
        print colored("[^] Creating gitignore...", "blue")
        with open(self.pname+"/.gitignore", "w") as fp:
            fp.write("*.o\n")
            fp.write("*/*.o\n")
            fp.write("*.swp\n")
            fp.write("*/*.swp\n")
            fp.write("*.gcda\n")
            fp.write("*/*.gcda\n")
            fp.write("*.gcno\n")
            fp.write("*/*.gcno\n")
            fp.write("%s.h\n" % self.pname)
            fp.write("bin/\n")
            fp.write("tests/units\n")
            fp.write("a.out\n")
            fp.close()

    def get_func_name(self):
        while True:
            print colored("[*] Please enter the number of ex:", "green")
            no = 'a'
            while not no.isdigit():
                no = raw_input(colored("[#] #> ", "yellow"))
            i = 0
            print colored("[$] Enter each ex name and then enter it's prototype", "magenta")
            while i < int(no):
                self.func_name.append(raw_input(\
                        colored("[#] %d> " % (i+1), "yellow")))
                self.func_porto.append(raw_input(\
                        colored("[#] proto %d> " %(i+1), "yellow")))
                i += 1
            print colored("[^] Your' ex: ", "blue"),
            print self.func_name
            print colored("[^] Your' prototypes: ", "blue"),
            print self.func_porto
            print colored("[#] Are you satisfied of those options?", "yellow")
            q = raw_input(colored("(Y/n)", "magenta"))
            if q == 'Y' or q == 'y':
                break

    def setup(self):
        self.get_func_name()
        if self.git:
            psetup_git.c_repo_git_setup(self.cfg, self.pname)
        self.create_dirs()
        self.create_makefile()
        self.create_gitignore()
        for func in self.func_name:
            self.create_source(func, self.func_porto[self.func_name.index(func)])
        print colored("[*] Done!", "green")

if __name__ == "__main__":
    setupEnvironement('PDay_TEST').setup()

