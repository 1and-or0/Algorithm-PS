n = int(input())
a = list(map(int, input().split()))

m = int(input())
b = list(map(int, input().split()))

a.sort()

for i in b:
    start = 0
    end = n - 1
    in_list = False
    while start <= end:
        mid = (start + end) // 2

        if i == a[mid]:
            in_list = True
            break
        elif i < a[mid]:
            end = mid - 1
        elif i > a[mid]:
            start = mid + 1

    print(int(in_list), end=' ')
