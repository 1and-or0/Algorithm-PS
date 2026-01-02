def Zfunc(x, y, size):
    global result
    if x == row and y == column:
        print(result)
        return

    if x <= row < x + size and y <= column < y + size:
        Zfunc(x, y, size // 2)
        Zfunc(x, y + size // 2, size // 2)
        Zfunc(x + size // 2, y, size // 2)
        Zfunc(x + size // 2, y + size // 2, size // 2)
    else:
        result += size * size


n, row, column = map(int, input().split())
result = 0
Zfunc(0, 0, 2 ** n)
