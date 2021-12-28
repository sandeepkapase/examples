#!/usr/bin/python
# [[file:../../../config_utils/info/python.org::python debugger example.][python debugger example.]]
import pdb
def somefun():
    print("YYYYY")
    # some operations here
    pdb.set_trace() # This will drop you to pdb prompt for debugging
somefun()
# python debugger example. ends here
