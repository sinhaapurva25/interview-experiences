import sys
# import numpy as np
# import pandas as pd
# from sklearn import ...
'''
def square(n):
    print(n*n)

def main():
    n = input()
    square(int(n))

if __name__ == '_main_':
    main()
'''
for line in sys.stdin:
    print(int(line)*int(line), end="")
