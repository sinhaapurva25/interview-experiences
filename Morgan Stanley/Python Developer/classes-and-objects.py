#!/bin/python3

import math
import os
import random
import re
import sys


class FancyTuple:
    # Implement the FancyTuple here
    arr = list()
    def __init__(self, arr):
        self.arr = arr
        
    def first(self):
        return self.arr[0]
    def second(self):
        return self.arr[1]
    def third(self):
        return self.arr[2]
    def fourth(self):
        return self.arr[3]
    def fifth(self):
        return self.arr[4]
    # def length(self):
    #     return sum([1 for i in self.arr])
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())
    items = [input() for _ in range(n)]

    t = FancyTuple(*items)

    q = int(input())
    for _ in range(q):
        command = input()
        if command == "len":
            fptr.write(str(len(t)) + "\n")
        else:
            try:
                elem = getattr(t, command)
            except AttributeError:
                fptr.write("AttributeError\n")
            else:
                fptr.write(elem + "\n")
    fptr.close()
