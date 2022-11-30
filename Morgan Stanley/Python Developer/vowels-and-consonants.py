class LetterFilter:

    def __init__(self, s):
        self.s = s
        

# Enter your code here. 
# Complete the classes below.
# Reading the inputs and writing the outputs are already done for you.
#
class LetterFilter:

    def __init__(self, s):
      self.s = s
	
    def filter_vowels(self):
        return ''.join([i for i in self.s if i in ['a','e','i','o','u']])

    def filter_consonants(self):
        # Enter your code here
        # Return a string
        return ''.join([i for i in self.s if i not in ['a','e','i','o','u']])

s = input()
f = LetterFilter(s)
print(f.filter_vowels())
print(f.filter_consonants())
