#!/usr/bin/env python
# By default, main execution will wait for thread to complete without
# performing join. i.e.  main will be blocked at the end till threads
# created complete their execution.
# If thread is marked as daemon then main thread execution will not
# stop for thread thread while exiting.
# In example below if we set set daemon flag True then main execution
# will exit program and thread will be killed.
# By default this flag is False i.e. if we remove daemon flag,
# programm will wait till execution of all threads.
# Note when thread.join operation is used, it will wait till execution
# of thread irrespective of daemon flag.
import threading
import time
import logging
def thread_function(name):
    logging.info("started thread : %s", name)
    time.sleep(5)
    logging.info("started stopped: %s", name)

if __name__ == "__main__":
    thrlist = []
    logging.basicConfig(level=logging.INFO)
    for i in range(1,5):
        x = threading.Thread(target=thread_function, args=(i,))
        x.daemon = True
        thrlist.append(x)

    for x in thrlist:
        x.start()

    for x in thrlist:
        x.join()

    logging.info("All thread done")
