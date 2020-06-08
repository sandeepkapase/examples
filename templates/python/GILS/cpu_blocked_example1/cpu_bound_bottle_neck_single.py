# single_threaded.py
import time


COUNT = 500000000

def countdown(n):
    while n>0:
        n -= 1

start = time.time()
countdown(COUNT)
end = time.time()

print('Time taken in seconds -', end - start)

# (cpu i5/16Gb/ssd/ubuntu 18.04/kernel 5.1)
# cpu_bound_bottle_neck_mprocess.py:# Average time required : 4 seconds
# cpu_bound_bottle_neck_mthreaded.py:# Average time required : 33 seconds
# cpu_bound_bottle_neck_single.py:# Average time required : 12 seconds
