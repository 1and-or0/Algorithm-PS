n = int(input())

for i in range(n):
    print(' '*(n-i-1), end='')
    print('*'*(2*i+1))
    # print(' '*(n-i-1))

for i in range(n-1):
    print(' '*(i+1), end='')
    print('*'*(n*2 - 3 - 2*i))
    # print(' '*(i+1))