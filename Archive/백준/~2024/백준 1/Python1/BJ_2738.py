n , m = map(int, input().split())

a = [0]*n
b = [0]*n

for i in range(n):
    a[i] = list(map(int, input().split()))

for i in range(n):
    b[i] = list(map(int, input().split()))

#print(a)
#print(b)

for i in range(n):
    for j in range(len(a[i])):
        a[i][j] += b[i][j]
        print(a[i][j], end=' ')
    print()

#print(a)
#print(b)
#print()
