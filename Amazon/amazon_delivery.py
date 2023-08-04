import math
def deliveryPlan(allLocations, numDeliveries):
    # dist_arr = []
    # for i in allLocations:
    #     dist_arr.append(math.sqrt(i[0]*i[0]+i[1]*i[1]))
    # dist_map = sorted(dist_arr,key=lambda x:x)

    # filtered_dist_map = dist_map[:numDeliveries]
    # # for i in range(numDeliveries):
    # #     filtered_dist_map.append(dist_map[i])
    # #3 print(filtered_dist_map)

    # output = []
    # for i in allLocations:
    #     for j in filtered_dist_map:
    #         if math.sqrt(i[0]*i[0]+i[1]*i[1]) == j:
    #             output.append(i)
    # print(output)

    dist_arr = []
    for i in allLocations:
        dist_arr.append(math.sqrt(i[0]*i[0]+i[1]*i[1]))
    dist_arr_sorted = sorted(dist_arr,key=lambda x:x)[:numDeliveries]
    print(dist_arr_sorted)
    index = []
    for i in dist_arr_sorted:
        index.append(dist_arr.index(i))
    print(index)
    output = []
    for i in index:
        output.append(allLocations[i])
    print(output)

deliveryPlan([[-3,2],[-3,2]],1)