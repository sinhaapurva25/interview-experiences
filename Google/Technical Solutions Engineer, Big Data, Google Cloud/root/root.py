'''
       1       
      / \      
     /   \     
    /     \     
   2       3   
  / \     / \  
 /   \   /   \ 
4     5 6     7
'''
'''
Time limit: 5 mins.
Find the output of the following code, starting from 1
'''
class TreeNode:
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right = None
def myFunc(root):
    if not root:
        return
    print(root.val)
    myFunc(root.left)
    myFunc(root.right)
myFunc(root)