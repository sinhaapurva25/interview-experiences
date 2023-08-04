# !/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'maxPresentations' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY scheduleStart
#  2. INTEGER_ARRAY scheduleEnd
#

def maxPresentations(scheduleStart, scheduleEnd):
    maxcount = 1
    for i in range(len(scheduleStart)):
        count = 1
        checkWithIndices = [x for x in range(len(scheduleStart)) if x != i]

        nth_PresentationEndTime = scheduleEnd[i]

        for j in checkWithIndices:
            if scheduleStart[j] - nth_PresentationEndTime >= 0:
                nth_PresentationEndTime = scheduleEnd[j]
                count += 1

        if count > maxcount:
            maxcount = count

    return maxcount

print(maxPresentations([6, 1, 2, 3],[8, 9, 4, 7]))
print(maxPresentations([1,1,2,3],[2,3,3,4]))

# if __name__ == '__main__':
#     fptr = open(os.environ['OUTPUT_PATH'], 'w')
#
#     scheduleStart_count = int(input().strip())
#
#     scheduleStart = []
#
#     for _ in range(scheduleStart_count):
#         scheduleStart_item = int(input().strip())
#         scheduleStart.append(scheduleStart_item)
#
#     scheduleEnd_count = int(input().strip())
#
#     scheduleEnd = []
# 
#     for _ in range(scheduleEnd_count):
#         scheduleEnd_item = int(input().strip())
#         scheduleEnd.append(scheduleEnd_item)
#
#     result = maxPresentations(scheduleStart, scheduleEnd)
#
#     fptr.write(str(result) + '\n')
#
#     fptr.close()
