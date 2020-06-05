import time
from concurrent.futures import ProcessPoolExecutor, ThreadPoolExecutor

TASKS = 4

def multithreading(func, args, workers):
    with ThreadPoolExecutor(workers) as ex:
        res = ex.map(func, args)
    return list(res)


def multiprocessing(func, args, workers):
    with ProcessPoolExecutor(workers) as ex:
        res = ex.map(func, args)
    return list(res)


def cpu_heavy(x):
    start = time.time()
    count = 0
    for i in range(10**8):
        count += i
    stop = time.time()
    return start, stop



avg = 0
# ('Average time: ', 31.881153225898743)
#for tm in multithreading(cpu_heavy, range(TASKS), TASKS):
#    avg = tm[1]-tm[0] + avg 

# ('Average time: ', 5.731821238994598)
for tm in multiprocessing(cpu_heavy, range(TASKS), TASKS):
    avg = tm[1]-tm[0] + avg

print("Average time: ", avg/TASKS)
