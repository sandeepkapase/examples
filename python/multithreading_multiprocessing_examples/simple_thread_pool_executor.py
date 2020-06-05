from concurrent.futures import ThreadPoolExecutor
from concurrent.futures import multithreading
import time
import logging
logging.basicConfig(level=logging.INFO)

def thread_function(name):
    logging.info("started thread : %d", name)
    time.sleep(5)
    logging.info("started stopped: %d", name)

if __name__ == "__main__":
    with ThreadPoolExecutor(max_workers=5) as pool:
        pool.map(thread_function, list(range(1,5)))

    logging.info("All thread done")
