'''
Given a string message, your task is to shift each vowel to the position of the next vowel in the string. The last vowel should be shifted to the position of the first vowel of the string. See the examples for a detailed explanation.

Note: The list of vowels is: "a", "e", "i", "o", "u".

Example

For message = "codesignal", the output should be solution(message) = "cadosegnil".

Explanation:

The given string "codesignal" contains the following vowels: message[1] = "o", message[3] = "e", message[5] = "i", message[8] = "a".
message[1] = "o" is moved to the position of the next vowel - message[3].
message[3] = "e" is moved to the position of the next vowel - message[5];
message[5] = "i" is moved to the position of the next vowel - message[8];
message[8] = "a" is the last vowel, so it is moved to the position of the first vowel in the string - message[1];
Finally, the resulting string becomes "cadosegnil".
For message = "plain text", the output should be solution(message) = "plean tixt".

For message = "some message with punctuation marks, e.g. commas, dots, etc.", the output should be solution(message) = "semo messega weth pinctuutain morks, a.g. cemmos, dats, otc.".

Input/Output

[execution time limit] 4 seconds (py3)

[input] string message

A string consisting of lowercase English letters, spaces, and punctuation marks (",", ".", "!", "?").

Guaranteed constraints:
1 ≤ message.length ≤ 1000.

[output] string

A converted string after performing the operations described above.

[Python 3] Syntax Tips

# Prints help message to the console
# Returns a string
def helloWorld(name):
    print("This prints to the console when you Run Tests")
    return "Hello, " + name

'''
def solution(message):
    arr = list()
    for i in range(len(message)):
        if message[i] == 'a' or message[i] == 'e' or message[i] == 'i' or message[i] == 'o' or message[i] == 'u':
            arr.append(i)

    arr_copy = [0] * len(arr)
    for i in range(len(arr)):
        if i == 0:
            arr_copy[i] = arr[len(arr) - 1]
        else:
            arr_copy[i] = arr[i - 1]

    res = ''
    j = 0
    for i in range(len(message)):
        if message[i] == 'a' or message[i] == 'e' or message[i] == 'i' or message[i] == 'o' or message[i] == 'u':
            # res[i] = message[arr_copy[j]]
            res += message[arr_copy[j]]
            j += 1
        else:
            # res[i] = message[i]
            res += message[i]
    return res


print(solution('codesignal'))