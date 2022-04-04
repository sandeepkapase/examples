#!/usr/bin/python
# [[file:../../../prep/python/Questions.org::python parameter_pass_by_ref example.][python parameter_pass_by_ref example.]]
from copy import deepcopy 
class testclass:
    def __init__(self):
        print("testclass initialized")
        self.var1 = 1
        self.var2 = 2
    def __repr__(self):
        return "var1:"+str(self.var1)+" var2:"+str(self.var2)

def testfun1(obj=None):
    obj.var1 = obj.var1 + obj.var1
    obj.var2 = obj.var2 + obj.var2

def testfun2(obj=None):
    obj[0] = 0
    obj[1] = 1

x = testclass()
print(x)
testfun1(x)
print(x)
testfun1(deepcopy(x)) # pass new object 
print(x)

y = [2,4]
print(y)
testfun2(y)
print(y)
# python parameter_pass_by_ref example. ends here
