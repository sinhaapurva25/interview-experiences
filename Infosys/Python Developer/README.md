I. Prabhas:
1. list, tuple questions  - diff etc.
2. Is it possible to call one function's variable in another: no, not directly
3. common elements between two lists: you said using sets and intersection, but didn't know the exact intersection function usage
a = [1,2,3,4]
b = [2,3,4,5]
# Correct answer: print(list(set(a).intersection(set(b))))
4. print(type("apurva"), type(("apurva","qwerty")))
You said both will be tuples. Wrong, first one will be string, second will be tuple.
5. Join this list with space: list1  = ["my", "name", "is", "apurva"]
You said:
print([i for i in list1])
list1.join(" ")
Correct is: print((" ").join(list1))
6. Convert 'h' and 'w' to uppercase: s = "hello world"
You just wrote s.split() and then said you would find the space and convert the first word to Uppercase, but there must be an easier method.
Correct answer is: print(str.title(s))
# or this way
# s = "hello world"
# S = ""
# for i in s.split():
#     S = S + i[0].upper() + i[1:] + " "
# print(S)
7. Package vs module

II. Adithya asked from my GitHub about the face-web-app