import sys
from collections import Counter
n = int(sys.stdin.readline())
ns = sys.stdin.readline().split()

m = int(sys.stdin.readline())
ms = sys.stdin.readline().split()

c = Counter(ns)
for k in ms:
    print(c[k], end=' ')