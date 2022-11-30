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