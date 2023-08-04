# !/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'minNum' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER samDaily
#  2. INTEGER kellyDaily
#  3. INTEGER difference
#

def minNum(samDaily, kellyDaily, difference):
    if kellyDaily <= samDaily:
        return -1
    else:
        samSolved = 0
        kellySolved = 0
        samSolved = samDaily + difference
        kellySolved = kellyDaily
        count = 1
        while not (kellySolved > samSolved):
            samSolved += samDaily + difference
            kellySolved += kellyDaily + difference
            count += 1
        return count


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    samDaily = int(input().strip())

    kellyDaily = int(input().strip())

    difference = int(input().strip())

    result = minNum(samDaily, kellyDaily, difference)

    fptr.write(str(result) + '\n')

    fptr.close()
