a1, a0 = map(int, input().split())
c = int(input())
n_min = int(input())


result = True
for n in range(n_min, 100+1):
    fn = a1 * n + a0
    gn = n
    if fn > c* gn:
        result = False
        break

if result == True:
    print(1)
else:
    print(0)
