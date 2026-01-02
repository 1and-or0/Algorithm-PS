import sys
input = sys.stdin.readline
count = 0
dist = 1

n = int(input())
for i in range(2, n):
    count += 1
    if count == dist*6:
        count = 0
        dist += 1

if n == 1:
    print(dist)
else:
    print(dist + 1)
