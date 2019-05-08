# multi_threaded.py
import time
from threading import Thread

COUNT = 500000000

def countdown(n):
    while n>0:
        n -= 1



t1 = Thread(target=countdown, args=(COUNT//8,))
t2 = Thread(target=countdown, args=(COUNT//8,))
t3 = Thread(target=countdown, args=(COUNT//8,))
t4 = Thread(target=countdown, args=(COUNT//8,))
t5 = Thread(target=countdown, args=(COUNT//8,))
t6 = Thread(target=countdown, args=(COUNT//8,))
t7 = Thread(target=countdown, args=(COUNT//8,))
t8 = Thread(target=countdown, args=(COUNT//8,))

start = time.time()

t1.start()
t2.start()
t3.start()
t4.start()
t5.start()
t6.start()
t7.start()
t8.start()

t1.join()
t2.join()
t3.join()
t4.join()
t5.join()
t6.join()
t7.join()
t8.join()

end = time.time()

print('Time taken in seconds -', end - start)
# Average time required : 33 seconds
# (cpu i5/16Gb/ssd/ubuntu 18.04/kernel 5.1)
