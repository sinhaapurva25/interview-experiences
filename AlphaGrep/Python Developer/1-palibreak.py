#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'breakPalindrome' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING palindromeStr as parameter.
#
def isPalindrome(s):
    isPali = False
    for i in range(len(s)//2):
        if s[i]!=s[len(s)-1-i]:
            isPali = True
            break
    return isPali
def breakPalindrome(palindromeStr):
    # Write your code here
    possible = list()
    for i in range(len(palindromeStr)):
        if palindromeStr[i]>'a':
            for j in range(ord(palindromeStr[i])-1,96,-1):
                s = palindromeStr[:i]+chr(j)+palindromeStr[i+1:]
                if ~isPalindrome(s):
                    possible.append(s)
    if len(possible)==0:
        return 'IMPOSSIBLE'
    else:
        return sorted(possible)[0]
        
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    palindromeStr = input()

    result = breakPalindrome(palindromeStr)

    fptr.write(result + '\n')

    fptr.close()
