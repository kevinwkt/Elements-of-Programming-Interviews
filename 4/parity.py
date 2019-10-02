#! /usr/bin/python3

def parity(a):
    parity = 0
    while a:
        parity^=1
        a&=(a-1)
    return parity

a = int(input())

print(parity(a))
