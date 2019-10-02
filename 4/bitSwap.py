#! /usr/bin/python3

def bitSwap(a, i ,j):
    if (a>>i)&1 != (a>>j)&1:
        a^=((1<<i)|(1<<j))
    return a

print('Please give "a i j":')
a, b, c = [int(x) for x in input().split()]
print(bitSwap(a, b, c))
