'''

Imagine you are calculating how you rate your favorite website over time using a random scale. You started with a rating of 1500, and whenever your rating changed, you recorded this change in the array diffs. Return an array with two numbers - your highest rating ever, and your current rating.

Note: It is guaranteed that your rating never changed to a negative value.

Example

For diffs = [100, -200, 350, 100, -600], the output should be solution(diffs) = [1850, 1250].

Explanation:
Here is the sequence of ratings after processing each change:

1500 - initial rating;
1500 + 100 = 1600;
1600 - 200 = 1400;
1400 + 350 = 1750;
1750 + 100 = 1850 - maximum value;
1850 - 600 = 1250 - current value.
Since your highest rating was 1850, and your current rating is 1250, the answer is [1850, 1250].

For diffs = [], the output should be solution(diffs) = [1500, 1500].

Explanation:
Since there aren't any changes to the initial rating, both the highest and the current rating values are 1500.

Input/Output

[execution time limit] 4 seconds (py3)

[input] array.integer diffs

An array of changes to your rating. It is guaranteed that the rating has never become negative.

Guaranteed constraints:
0 ≤ diffs.length ≤ 1000,
-1000 ≤ diffs[i] ≤ 1000.

[output] array.integer

An array with two values: your highest rating ever, and your current rating.

[Python 3] Syntax Tips

# Prints help message to the console
# Returns a string
def helloWorld(name):
    print("This prints to the console when you Run Tests")
    return "Hello, " + name

'''