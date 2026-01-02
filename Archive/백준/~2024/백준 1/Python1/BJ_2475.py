arr = list(map(int, input().split()))
len_ = 5
for i in range(len_):
    arr[i] = arr[i] ** 2

print(sum(arr) % 10)
