def count(string, k):
    dct = {}
    for i in string:
        if i in dct:
            dct[i] += 1
        else:
            dct[i] = 1
    # print(dct)
    return len(dct) == sum([1 for i in dct.values() if i == k])

# from collections import Counter
def count2(string, k):
    st = set(string)
    flag = True
    m = 0
    for i in st:
        # instances = sum([1 for j in string if j==i])
        # instances = Counter(string).get(i)
        instances = string.count(i)
        if instances != k:
            flag = False
            break
        else:
            m += 1
    if m!= len(st):
        flag = False
    return flag

# def perfectSubstring(s, k):
#     c = 0
#     for i in range(len(s)):
#         for j in range(i+1, len(s)+1):
#             if len(s[i:j]) > 0:
#                 # if count(s[i:j], k):
#                 if count2(s[i:j], k):
#                     c += 1
#     return c

def perfectSubstring(s, k):
    c = 0
    for i in range(len(s)):
        for j in range(i+1, len(s)+1):
            # if count(s[i:j], k):
            if count2(s[i:j], k):
                c += 1
    return c

# from itertools import combinations
# def perfectSubstring(s, k):
#     c = 0
#     for x, y in combinations(range(len(s) + 1), r = 2):
#         if count2(s[x:y], k):
#             c += 1
#     return c