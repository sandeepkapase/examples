#!/usr/bin/env python
''' In python tupple is immutable.
Summary:
========

* In python variables are nothing but names/aliases given to actual objects.

* If tupple consist of reference to other mutable data then we can actually
modify its data.

* If tupple is consiste of reference which is itself is immutable)
then we can not modify its data.

Eg. We have tuple ""tpl"" which consist of three lists "l1", "l2", "l3"
    >> tpl = l1,l2,l3
    
    Here we can not modify tupple once it is created. But we can modify contents
    of its member i.e references of lists.
    >> tpl[0]    = l4         ==> Can not modify tupple
    >> tpl[0][1] = 1234       ==> Can modify memeber data.

* Every object has an identity, a type and a value.
** An object’s identity never changes once it has been created;
** You may think of it as the object’s address in memory.
** The ‘is’ operator compares the identity of two objects;
** The id() function returns an integer representing its identity.

* Integers,  floats, Booleans, strings, frozen sets, and bytes) are immutable; their value doesn't change.
* Lists, dictionaries, sets, arrays, and bytearrays on the other hand, are mutable.

 '''


print "\n"*100
l1 = [1,2,3]
l2 = [4,5,6]

# created tuple with list reference.
tp1 = (l1,l2) # OR tp2 = l1,l2

print tp1
print type(tp1)
print id(tp1)
print tp2
print type(tp2)
print id(tp2)

# change actual object
l1.append(111)
l2.append(222)

# actual object changes reflected into tupple.
print tp1
print type(tp1)
print id(tp1)
print tp2
print type(tp2)
print id(tp2)

tp1[0][0] = 234
l1.append(111)
l2.append(222)
print tp1
print type(tp1)
print id(tp1)
print tp2
print type(tp2)
print id(tp2)

