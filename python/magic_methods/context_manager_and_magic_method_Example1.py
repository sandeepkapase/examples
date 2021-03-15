#!/usr/bin/env python3.6
'''
__enter__ and [__exit__] both are methods that are invoked on entry to and exit from the body of
"the with statement" (PEP 343) and implementation of both is called context manager.
'''
class myclass:
    def __init__(self):
        print("__init__")

    def __enter__(self):
        print("__enter__")
        return self

    def __exit__(self, type, value, traceback):
        print("__exit__")

    def __del__(self):
        print("__del__")

    def run(self):
        print("running")


with myclass():
    print("body1")

#Produces the output:

#__init__
#__enter__
#body
#__exit__
#__del__
#A reminder: when using the syntax with myclass() as mc, variable mc gets the value returned by __enter__(), in the above case None! For such use, need to define return value, such as:

#def __enter__(self):
#    print('__enter__')
#    return self
#Share
with myclass() as c:
    print("body")
    c.run()
