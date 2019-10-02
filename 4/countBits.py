#! /usr/bin/python3

import sys
sys.path.append('../utils')

from timer import measure

@measure
def badCountBits(a):
    count = 0
    while a:
        if a&1:
            count+=1
        a>>=1
    return count

@measure
def goodCountBits(a):
    count = 0
    while a:
        count+=1
        a&=(a-1)
    return count

a = int(input())
print(badCountBits(a))
print(goodCountBits(a))
