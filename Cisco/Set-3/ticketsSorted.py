#!/bin/python3

import math
import os
import random
import re
import sys



# Complete the maxTickets function below.
def maxTickets(tickets):
    ss = [[]]
    pres = 0
    tickets_sorted = sorted(tickets)
    ss = [[tickets_sorted[0]]]
    for i in range(len(tickets_sorted)-1):
        diff = tickets_sorted[i+1] - tickets_sorted[i]
        if diff == 0 or diff == 1:
            # ss[pres].append(i)
            ss[pres].append(tickets_sorted[i])
        else:
            pres += 1
            # ss.append([i])
            ss.append([tickets_sorted[i]])
    return max([len(i) for i in ss])

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    tickets_count = int(input().strip())

    tickets = []

    for _ in range(tickets_count):
        tickets_item = int(input().strip())
        tickets.append(tickets_item)

    res = maxTickets(tickets)

    fptr.write(str(res) + '\n')

    fptr.close()