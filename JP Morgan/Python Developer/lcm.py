num1 = int(input())
num2 = int(input())
def lcm(num1, num2):
    _num1_ = 1
    _num2_ = 1
    for i in range(2,9):
            k = num1//i
            l = num2//i
            if k ==1 or l ==1:
                break
        _num1_ = k
        _num2_ = l
    # def common_factors(number):
    #     common_factors_list = []
    #     for i in range(1,9):
    #         if number%i==0 and number!=i and i!=1:
    #             common_factors_list.append(i)
    #     return common_factors_list
    # print(common_factors(num1))
    # print(common_factors(num2))
lcm(9,36)


