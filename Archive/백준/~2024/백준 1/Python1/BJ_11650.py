n = int(input())

list_ = []
for _ in range(n):
    list_.append(tuple(map(int, input().split())))

list_.sort()

for x_y in list_:
    print(x_y[0], x_y[1])
