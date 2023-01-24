import math
def largestArea(samples):
    row_len = len(samples)
    col_len = len(samples[0])
      
    cache = [[0 for k in range(col_len)] for l in range(row_len)]
      
    for i in range(0, row_len): 
        for j in range(0, col_len):
            if (samples[i][j] == 1):
                # if row(i) or column(j) is 0, set to 1 or
                if i == 0 or j == 0:
                    cache[i][j] = min(samples[i][j], 1)
                else:
                    cache[i][j] = min(cache[i][j-1], cache[i-1][j],cache[i-1][j-1]) + 1
            else:
                cache[i][j] = 0
      
    max_in_cache = cache[0][0] 
    max_i = 0
    max_j = 0
      
    for i in range(row_len): 
        for j in range(col_len): 
            if max_in_cache < cache[i][j]: 
                max_in_cache = cache[i][j] 
                max_i = i 
                max_j = j 
    res = ""
    for i in range(max_i, max_i - max_in_cache, - 1): 
        for j in range(max_j, max_j - max_in_cache, - 1): 
            res = res + str(samples[i][j]) + " "
        res =  res + "\n"
    return int(math.sqrt(len(res.split())))
samples_rows = int(input().strip())
samples_columns = int(input().strip())

samples = []

for _ in range(samples_rows):
    samples.append(list(map(int, input().rstrip().split())))

result = largestArea(samples)
print(result)

'''
def largestArea(samples):
    res = 0
    for i in range(len(samples)):
        res = max(res, samples[i][0])
    for i in range(len(samples[0])):
        res = max(res, samples[0][i])
    for i in range(1, len(samples)):
        for j in range(1, len(samples[0])):
            if samples[i][j] == 1:
                samples[i][j] = min(samples[i - 1][j], samples[i - 1][j - 1], samples[i][j - 1]) + 1
        res = max(res, samples[i][j])
    return res * res
'''