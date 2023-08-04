area = [[0,1,0],[0,0,0],[1,1,1],[9,0,0]]
start = [0,0]
destination = [0,0]
for i in range(0, len(area)):
    for j in range(0, len(area[i])):
        if area[i][j]==9:
            destination = [i,j]
            break
road = []
for i in range(0, len(area)):
    for j in range(0,len(area[i])):
        if area[i][j]==1:
            road.append([i,j])
print(road)
import math
path = []
for i in range(0,len(road)):
    dist = []
    for j in range(i,len(road)):
        dist.append(math.sqrt(math.pow(j[0]-i[0],2)+math.pow(j[1]-i[1],2)))
    path.append(road.index(min(dist)))
print(len(path)-1)