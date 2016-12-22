""" Memory.py
Memory program to simulate 2 not or gates

"""
import os, sys
import datetime

class memory():
    'memory class'
    
    def __init__(self, a, b, R, S, filename):
        self.a = a
        self.b = b
        self.R = R
        self.S = S
        self.q = []
        self.p = []
        try:
            self.output = open(filename, 'w')
            
        except:
            print("can't open file")
            sys.exit(1)

    def mainLoop(self):

        while True:

            w = input('>>')
            
            if w == "R=1":
                self.R = True
            elif w == "R=0":
                self.R = False

            if w == "S=1":
                self.S = True
            elif w == "S=0":
                self.S = False

                
            temp_q = not(self.R or self.a)
            self.b = temp_q
            temp_p = not(self.S or self.b)
            self.a = temp_p

            self.q.append(temp_q)
            self.p.append(temp_p)


            print(self.p)
            print(self.q)





if __name__ == "__main__":
    test = memory(0,0,0,1, "qwerty.html")
    test.mainLoop()
