'''
Given two arrays of numbers, firstArray and secondArray. Return the length of the longest common prefix (LCP) between any pair of numbers from different arrays or 0 if no common prefix exists.

Note: A prefix of a number is a number formed by one or more of its digits, starting from its highest-order digit. For example, 123 is a prefix of the number 12345 and 2 is a prefix of the number 234. A common prefix of two numbers is a number, which is a prefix of both. For instance, longest common prefix (LCP) of 5655359 and 56554 is 5655 and there is no common prefix of 123 and 456.

Example

For firstArray = [25, 288, 2655, 54546, 54, 555] and secondArray = [2, 255, 266, 244, 26, 5, 54547], the output should be solution(firstArray, secondArray) = 4.

Explanation:

The best pair is 54546 from the first array and 54547 from the second array with the LCP 5454, where 5454 is of length 4.
For firstArray = [25, 288, 2655, 544, 54, 555] and secondArray = [2, 255, 266, 244, 26, 5, 5444444], the output should be solution(firstArray, secondArray) = 3.

Explanation:

The best pair is 544 from the first array and 5444444 from the second array with the LCP 544, where 544 is of length 3.
For firstArray = [817, 99] and secondArray = [1999, 1909], the output should be solution(firstArray, secondArray) = 0.

Explanation:

No pair of numbers from different arrays has a common prefix, hence the answer is 0.
Input/Output

[execution time limit] 4 seconds (py3)

[input] array.integer firstArray

The array of positive integers.

Guaranteed constraints:
1 ≤ firstArray.length ≤ 5 ⋅ 104,
1 ≤ firstArray[i] ≤ 109.

[input] array.integer secondArray

The array of positive integers.

Guaranteed constraints:
1 ≤ secondArray.length ≤ 5 ⋅ 104,
1 ≤ secondArray[i] ≤ 109.

[output] integer

Length of the longest common prefix (LCP) between any pair of numbers from different arrays.

[Python 3] Syntax Tips

# Prints help message to the console
# Returns a string
def helloWorld(name):
    print("This prints to the console when you Run Tests")
    return "Hello, " + name
'''


def solution(firstArray, secondArray):
    firstArray = list(map(str, firstArray))
    secondArray = list(map(str, secondArray))

    firstArray.sort(key=lambda x: len(x), reverse=True)
    secondArray.sort(key=lambda x: len(x), reverse=True)

    mx = 0
    for i in range(len(firstArray)):
        for j in range(len(secondArray)):
            c = 0
            for x in range(min(len(firstArray[i]), len(secondArray[j]))):
                if firstArray[i][x] == secondArray[j][x]:
                    c += 1
                else:
                    break
            if c > mx:
                mx = c
            if j != len(secondArray)-1:
                if mx >= len(secondArray[j+1]):
                    break
        if i != len(firstArray)-1:
            if mx >= len(firstArray[i+1]):
                break
    return mx


print(solution(firstArray=[25, 288, 2655, 54546, 54, 555], secondArray=[2, 255, 266, 244, 26, 5, 54547]))
print(solution(firstArray=[25, 288, 2655, 544, 54, 555], secondArray=[2, 255, 266, 244, 26, 5, 5444444]))
print(solution(firstArray=[817, 99], secondArray=[1999, 1909]))
