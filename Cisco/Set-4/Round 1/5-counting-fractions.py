def HCF(x, y):
    while(y):
        x, y = y, x % y
    return x

def countProperFractions(max_d):
    c = 0
    for i in range(1,max_d+1):
        for j in range(i+1,max_d+1):
            # print(str(i)+'/'+str(j),sep='')
            # print(HCF(i,j))
            if HCF(i,j) == 1:
                c += 1
    return c
print(countProperFractions(8))