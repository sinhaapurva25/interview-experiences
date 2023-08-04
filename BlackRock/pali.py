n = 123898321
n = 2334
m = n
s = 0
while m>0:
    r = m%10
    s = s*10 + r
    m //= 10

if s == n:
    print("pali")