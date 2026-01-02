n , k = map(int, input().split())

arr = []
for i in range(n):
    arr.append(i + 1)

index = k - 1
while len(arr) != 0:
    try:
        print(arr.pop(index), end=' ')
    except:
        index = index - len(arr)
    else:
        index += -1 + k
    