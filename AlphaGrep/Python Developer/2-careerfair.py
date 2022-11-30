def maxEvents(arrival, duration):
    timings = sorted([(arrival[i],arrival[i]+duration[i]) for i in range(len(arrival))])
    res = 0
    for i in range(1,len(timings)-1):
        if timings[i][0]>=timings[i-1][1]:
            res += 1
    return res
print(maxEvents([1,3,3,5,7],[2,2,1,2,1]))
print(maxEvents([7,3,3,5,1],[1,2,1,2,2]))
print(maxEvents([1,3,5],[1,2,1,2,2]))