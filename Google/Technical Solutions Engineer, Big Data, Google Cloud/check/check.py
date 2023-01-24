# What will be the output of the following code?
def check(word):
    x = 0
    y = len(word)-1

    if x<y:
        if word[x]!=word[y]:
            return False
    x += 1
    y -= 1
    return True
check("noon")
check("refer")
check("moon")