colored = []

time_re = 0

for i in range(100):
    for j in range(100):
        colored.append((i, j))
        time_re +=1
total = len(colored)

n = int(input())

for i in range(n):
    y_, x_ = map(int, input().split())
    x_ = 99 - x_ 

    for i in range(x_-9, x_+1):
        for j in range(y_, y_+10):
            time_re +=1
            if (i, j) in colored:
                colored.remove((i, j))
    
print(total - len(colored))
print(time_re)
