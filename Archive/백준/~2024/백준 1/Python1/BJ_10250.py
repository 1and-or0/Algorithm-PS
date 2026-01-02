t = int(input())

for _ in range(t):
    h, w, n = map(int, input().split())
    x = 1 # YYXX호에서 XX 부분
    y = 0 # YYXX호에서 YY 부분

    x += ((n - 1) // h)
    y += (n % h)
    
    if y == 0:
        print(h, end='')
    else:
        print(y, end='')

    if x < 10:
        print(f"0{x}")
    else:
        print(x)