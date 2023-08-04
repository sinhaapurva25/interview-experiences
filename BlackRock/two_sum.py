nums = [2,7,11,15]
target = 9
res = list()


for i in range(len(nums)):
    for j in range(i+1, len(nums)):
        if nums[i]+nums[j] == target:
            res.append([nums[i], nums[j]])

print(res)

