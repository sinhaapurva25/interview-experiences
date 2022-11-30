def efficientJanitor(weight):
    # if str(sum(weight)%3) == '0':
    #     return int(sum(weight)//3)
    # else:
    #     return int(sum(weight)//3+1)
    c, i = 0, 0
    j = len(weight) - 1
    weight.sort()
    while i <= j:
        c += 1
        if (weight[i] + weight[j] <= 3):
            i += 1
        j -= 1
    return c
print(efficientJanitor([1.01,1.99,2.5,1.5,1.01]))
print(efficientJanitor([1.01,1.991,1.32,1.4]))
1.32,1.4