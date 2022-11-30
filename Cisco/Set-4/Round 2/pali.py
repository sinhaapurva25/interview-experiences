Arr1 = [2, 5, 6, 8]
Arr2 = [3, 12, 15, 18]

i = 0
j  = 0

s = 'fkldsfs'
print(s[::-1][1:][::-1])
print(s[-1] in [','])

# return sum([1 for i in z.split(" ") if i.isalpha()])
# for i in z.split(" "):
# n pali?
# bin(n) pali?

# string = 'hannah'
# string = 'kalak'
string = 'klak'
string2 = ''
l = len(string)
# print(6/2,6//2,6.0//2.0)
flag = 0
for i in range(l//2):
    if string[i] == string [l-i-1]:
        pass
    else:
        flag = 1
        break

if flag == 1:
    print('not a palindrome')
else:
    print('palindrome')



class Stack():
  
  def __init__(self):
    self.stack = []
    self.min = []
  
  def push(self, n):
    if n < self.stack[-1]:
      self.min.append(n)
    else:
      self.min.append(self.min[-1])
    self.stack.append(n)
  
  def pop(self):
    self.stack.pop()
    self.min.pop()
  
  def top(self):
    return self.stack[-1]
  
  def getMin(self):
    return self.min[-1]