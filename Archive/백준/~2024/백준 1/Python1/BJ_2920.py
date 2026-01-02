arr = list(map(int, input().split()))

result = ""
a0 = arr[0]
for i in range(1, len(arr)):
    if result == "":
        if a0 - arr[i] == -1:
            result = "ascending"
        elif a0 - arr[i] == 1:
            result = "descending"
        else:
            result = "mixed"
            break
    else:
        if result == "ascending":
            if a0 - arr[i] != -1:
                result = "mixed"
                break
        elif result == "descending":
            if a0 - arr[i] != 1:
                result = "mixed"
                break

    a0 = arr[i]

print(result)
