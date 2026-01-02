a, b, c, d, e, f = map(int, input().split())

solving = True
x, y = -999, -999
while (a*x + b*y != c) or (d*x + e*y != f):
    if x == 999:
        y += 1
        x = -999
    if y == 999:
        break
    # if y == 999:
    #     y = -999
    x += 1

print(x, y)
