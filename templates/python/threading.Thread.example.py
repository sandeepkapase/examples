import threading
import time
import sys
import random


class Hello(threading.Thread):
    def __init__(self, min, max):
        self.min, self.max = min, max
        threading.Thread.__init__(self)

    def run(self):
        time.sleep(random.randint(1,3))
        print "This is simple string"




tLst = []
for i in range(1,10):
    tLst.append(Hello(0,i))

x = Hello(1,3)
x.start()
# This causes each thread to do its work
#h.start()
#k.start()
