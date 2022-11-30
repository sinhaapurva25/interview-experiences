#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'taxiDriver' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts following parameters:
#  1. LONG_INTEGER_ARRAY pickup
#  2. LONG_INTEGER_ARRAY drop
#  3. INTEGER_ARRAY tip
#

def taxiDriver(pickup, drop, tip):
    s = 0
    for i in range(1,len(pickup)):
        for j in range(i):
            if pickup[i] >= drop[i-1]:
                pres = drop[i]-pickup[i]+tip[i]
                prev = drop[i-1]-pickup[i-1]+tip[i-1]
                if pres >= prev:
                    s += pres
                else:
                    s += prev
                    
    return s
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    pickup_count = int(input().strip())

    pickup = []

    for _ in range(pickup_count):
        pickup_item = int(input().strip())
        pickup.append(pickup_item)

    drop_count = int(input().strip())

    drop = []

    for _ in range(drop_count):
        drop_item = int(input().strip())
        drop.append(drop_item)

    tip_count = int(input().strip())

    tip = []

    for _ in range(tip_count):
        tip_item = int(input().strip())
        tip.append(tip_item)

    result = taxiDriver(pickup, drop, tip)

    fptr.write(str(result) + '\n')

    fptr.close()
