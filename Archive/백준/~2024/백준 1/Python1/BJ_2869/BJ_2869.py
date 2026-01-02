a, b, n = map(int, input().split())

x = 0
condition1 = a+(a-b)*x

while n > condition1:
    x += 1
    condition1 = a+(a-b)*x

print(x+1)
