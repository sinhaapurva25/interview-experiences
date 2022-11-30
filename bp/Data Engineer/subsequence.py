import sys
# import numpy as np
# import pandas as pd
# from sklearn import ...
def subsequence(s):
    res = []
    for i in range(len(s)):
        for j in range(i,len(s)):
            res.append(s[i:j+1])
    return res

def commonSubsequence(s1,s2):
    commonSequence=list(set(subsequence(s1)).intersection(set(subsequence(s2))))
    l = len(commonSequence)
    if l>0:
        commonSequence.sort(key=lambda item: (-len(item),item))
        return commonSequence[0]
    else:
        return None

def commonSubsequence2(s1,s2):
    m = 0
    res = ''
    print(subsequence(s1))
    print(subsequence(s2))
    for i in subsequence(s1):
        for j in subsequence(s2):
            # print(i,j)
            if i == j:
                print(i,j)
    #             if len(i) > m:
    #                 res = i
    #                 m = len(i)
    # return res
        
for line in sys.stdin:
    s1, s2 = line.rstrip().split(';')
    print(commonSubsequence(s1,s2), end="")


# print(set(['a','pu']))
# XMJYAUZ;MZJAWXU
# MJAU
