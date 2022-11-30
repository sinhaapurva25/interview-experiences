from math import sqrt

def isPrime(n):
    if (n <= 1):
        return False
    for i in range(2, int(sqrt(n))+1):
        if (n % i == 0):
            return False
    return True

def rotateStrings(string):
    rotatedStrings = []
    n = len(string)
    temp = string + string
    for i in range(n):
        k = ''
        for j in range(n):
            k = k + temp[i+j]
        rotatedStrings.append(k)
    return rotatedStrings

# def rotateStrings(string):
#     rotatedStrings = []
#     n = len(string)
#     temp = string + string
#     for i in range(n):
#         for j in range(n):
#             rotatedStrings.append(temp[i+j])
#     return rotatedStrings
    
def countCircularPrimes(number):
    # Write your code here
    count = 0
    for i in range(number+1):
        num = str(i)
        perms = rotateStrings(num)
        no_of_cirular_primes = sum([1 for i in perms if isPrime(int(i))])
        if no_of_cirular_primes == len(perms):
            count += 1
    return count
print(countCircularPrimes(100))
# print(rotateStrings('197'))