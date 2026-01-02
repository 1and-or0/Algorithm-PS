ns = list(input())

ns = [int(n) for n in ns]
ns.sort(reverse=True)
for i in range(len(ns)):
    print(ns[i], end='')