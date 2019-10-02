#! /usr/bin/python3

import math

# Will create a hashmap for 4 bits, which would be 2**4-1
PRECOMPUTED_REVERSE = {
    0:0,
    1:8,
    2:4,
    3:12,
    4:2,
    5:10,
    6:6,
    7:14,
    8:1,
    9:9,
    10:5,
    11:13,
    12:3,
    13:11,
    14:7,
    15:15
}

def reverseBit(a):
    # Word length is 64 as default.
    word_length = 64
    # Precomputed bit length.
    pre_length = 4
    # Bit mask to get relevant bits.
    bit_mask = 0xF
    # mask_length, 
    mask_length = math.ceil(word_length/pre_length)
    ans = 0
    for i in range(mask_length):
        ans|=(PRECOMPUTED_REVERSE[(a>>(pre_length*i))&bit_mask] << ((mask_length-i-1)*pre_length))
    return ans

a = int(input())
print(reverseBit(a))
