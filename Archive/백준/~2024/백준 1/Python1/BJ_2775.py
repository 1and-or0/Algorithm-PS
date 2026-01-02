t = int(input())

for _ in range(t):
    a = int(input())
    b = int(input())
    list_ = [i for i in range(1, b+1)]

    for j in range(a):
        sum_ = 0
        for i in range(b):
            sum_ += list_[i]
            if i != 0:
                list_[i] = sum_

    print(list_[b-1])
