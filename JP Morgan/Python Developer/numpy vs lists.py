import numpy
import time

def jpmorgan():
    x = 100000
    l1 = range(x)
    l2 = range(x)
    a1 = numpy.arange(x)
    a2 = numpy.arange(x)
    start = time.time()
    result = [(x,y) for x,y in zip(l1,l2)]
    print((time.time()-start)*1000)

    start = time.time()
    result = [a1+a2]
    print((time.time()-start)*1000)

# jpmorgan()

def apurva():
    x=1000000
    l1 = range(x)
    l2 = range(x)
    np1 = numpy.arange(x)
    np2 = numpy.arange(x)

    start = time.time()
    l = [l1[i]+l2[i] for i in range(x)]#l = [l1[i]+l2[i] for i in l1]
    # print(l)
    lt = time.time()-start

    start = time.time()
    np = np1+np2
    # print(np)
    npt = time.time()-start

    print(lt/npt)

    l1 = [i for i in range(5)]
    l2 = [i for i in range(5,10)]
    for i in range(len(l2)):
        l1.append(l2[i])
    print(l1)

apurva()