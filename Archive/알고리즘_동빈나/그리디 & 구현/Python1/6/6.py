import datetime

time0 = datetime.time()
maxTime = datetime.time()

keyNUm = 3

h = int(input())
maxTime = datetime.time(hour=h, minute=59, second=59)


def plus_sc(time1, add_sc):
    for _ in range(add_sc):
        if time1.minute == 59 and time1.second == 59:
            time1 = datetime.time(hour=time1.hour+1, minute=0, second=0)
        elif time1.second == 59:
            time1 = datetime.time(hour=time1.hour, minute=time1.minute+1, second=0)
        else:
            time1 = datetime.time(hour=time1.hour, minute=time1.minute, second=time1.second+1)
        checking(time1, 3)


def checking(time1, num):
    if (time1.second // 10) == num:
        print(time1)
    if time1.second != 0:
        if time1.second % 10 == num:
            print(time1)
    if (time1.minute // 10) == num:
        print(time1)
    if time1.minute != 0:
        if time1.minute % 10 == num:
            print(time1)
    if (time1.hour // 10) == num:
        print(time1)
    if time1.hour != 0:
        if time1.hour % 10 == num:
            print(time1)


hToS = h * 60 * 60
plus_sc(time0, hToS)
