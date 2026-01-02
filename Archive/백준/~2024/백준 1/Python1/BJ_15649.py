import sys
input = sys.stdin.readline
from itertools import permutations

n, m = map(int, input().split())

a = list(range(1, n+1))

for x in permutations(a, m):
    print(*x)
