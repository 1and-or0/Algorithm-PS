n = int(input())

list_ = []
for _ in range(n):
    list_.append(tuple(map(int, input().split())))  # [ (x, y), (x, y), (x, y),] 

list_.sort(key=lambda tu : (tu[1], tu[0]))

for i in list_:
    print(i[0], i[1])
