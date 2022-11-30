def getSumOfDoubleBasePalindromes(maximum):
    s = 0
    for i in range(1,maximum+1):
        bin =  "{:>b}".format(i)
        if (str(i)==str(i)[::-1]) and (str(bin)==str(bin)[::-1]):
            s += i
    return s
print(getSumOfDoubleBasePalindromes(5))