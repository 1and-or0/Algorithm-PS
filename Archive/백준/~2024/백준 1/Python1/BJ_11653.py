import sys
input = sys.stdin.readline

n = int(input())

if n != 1:
    
    decimal = []
    
    x = [1]*(n + 1)
    x[0] = 0
    x[1] = 0

    for num in range(2, int(n**0.5)+1):
        if x[num]:
            for i in range(num*num, n+1, num):
                x[i] = 0
    
    decimal = [i for i in range(2, n+1) if x[i] == 1]

    while n not in decimal:
        for deci_num in decimal:
            if n % deci_num == 0 and deci_num < n:
                n = n // deci_num
                print(deci_num)
                break
    print(n)