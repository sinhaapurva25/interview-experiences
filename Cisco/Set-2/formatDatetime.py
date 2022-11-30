import calendar
from datetime import datetime

dates_count = int(input().strip())
dates = []
for _ in range(dates_count):
    dates_item = input()
    dates.append(dates_item)
def preprocessDate(dates):
    monthArr = ['Jan','Feb','Mar','Apr','May','Jun','Jul','Aug','Sep','Oct','Nov','Dec']
    datesRes = list()
    for date in dates:
        d,m,y = date.split()
        d = d[::-1][2:][::-1]
        monthNum = str(monthArr.index(m)+1)
        if len(monthNum) == 1:
            monthNum = '0' + monthNum
        if len(d) == 1:
            d = '0' + d
        datesRes.append(y + '-' + monthNum + '-' + d)
    return datesRes
result = preprocessDate(dates)
print(result)