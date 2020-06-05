import threading
import time
import logging

def thread_function(name):
    logging.info("started thread : %s", name)
    time.sleep(5)
    logging.info("started stopped: %s", name)
    return str(name)+"_result"

if __name__ == "__main__":
    thrlist = []
    result = [] # lambda wrapper to collect results.
    #format = "%(asctime)s: %(message)s"
    logging.basicConfig(level=logging.INFO)
    for i in range(1,5):
        # without return value
        #x = threading.Thread(target=thread_function, args=(i,))
        # with return value inside result
        x = threading.Thread(target=lambda x:result.append(thread_function(x)), args=(i,))
        thrlist.append(x)

    for x in thrlist:
        x.start()

    for x in thrlist:
       x.join()

    print(result)
    logging.info("All thread done")





