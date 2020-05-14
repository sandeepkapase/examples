#!/usr/bin/env python
import sys
inputArray = []
num = 0
#hile True:
#   inputArray.append(int(raw_input()))
#   if inputArray[num] < 0:
#       inputArray.remove(inputArray[num])
#       break
#   num = num + 1

#print inputArray
inputArray = [3,6,36,32,32,121,66,24,26,371,661,6,4,8]
arrLen = len(inputArray)
brokeSequence = -1

def somereduceFun(i,j):
    global brokeSequence
    if brokeSequence != -1:
        return brokeSequence
    if inputArray[i] <= inputArray[j]:
        return j
    else:
        brokeSequence = i
        return brokeSequence

initIndex = 0
profit = 0
while initIndex < arrLen:
    brokeSequence = -1
    newIndex = reduce(lambda x,y : somereduceFun(x,y), range(initIndex,arrLen))
    if initIndex < newIndex:
        newProfit = inputArray[newIndex]-inputArray[initIndex]
        #print "Index Range", inputArray[initIndex:newIndex+1], "Profit:", newProfit
        if profit < newProfit:
            profit = newProfit
    initIndex = newIndex + 1

print profit
