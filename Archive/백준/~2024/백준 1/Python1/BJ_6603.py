from itertools import combinations

while True:
    n = list(map(int, input().split()))
    if n[0] == 0:
        break

    nums, set_ = n[0], n[1:]

    result = list(combinations(set_, 6))

    for i in range(len(result)):
        for j in range(6):
            print(result[i][j], end=' ')
        print()
    print()
