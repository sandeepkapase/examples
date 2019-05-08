# multi_threaded.py
import time
from multiprocessing import Pool

COUNT = 500000000

def countdown(n):
    while n>0:
        n -= 1

if __name__ == "__main__":
    pool = Pool(processes=8)
    start = time.time()
    r1 = pool.apply_async(countdown, [COUNT//8])
    r2 = pool.apply_async(countdown, [COUNT//8])
    r3 = pool.apply_async(countdown, [COUNT//8])
    r4 = pool.apply_async(countdown, [COUNT//8])
    r5 = pool.apply_async(countdown, [COUNT//8])
    r6 = pool.apply_async(countdown, [COUNT//8])
    r7 = pool.apply_async(countdown, [COUNT//8])
    r8 = pool.apply_async(countdown, [COUNT//8])
    pool.close()
    pool.join()
    end = time.time()
    print('Time taken in seconds -', end - start)


# (cpu i5/16Gb/ssd/ubuntu 18.04/kernel 5.1)
# cpu_bound_bottle_neck_mprocess.py:# Average time required : 4 seconds
# cpu_bound_bottle_neck_mthreaded.py:# Average time required : 33 seconds
# cpu_bound_bottle_neck_single.py:# Average time required : 12 seconds
