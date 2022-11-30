# Question - is China and china the same for a dictionary key in Python
print('china' in {'China':1,'Japan':1})

# defaultdict
import collections
a = collections.defaultdict(int)
print(a[1])

#remomve vowels from a word
print('HackerRank'.replace('a',''))