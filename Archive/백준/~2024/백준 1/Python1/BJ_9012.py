t = int(input())

for _ in range(t):
    arr = input()
    len_ = len(arr)
    if len_ % 2 == 1:
        print("NO")
        continue

    while "()" in arr:
        arr = arr.replace("()", '')

    if len(arr) == 0:
        print("YES")
    else:
        print("NO")
