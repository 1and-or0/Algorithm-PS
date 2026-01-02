from turtle import right


paper = [0]*100
time_re = 0
for i in range(100):
    paper[i] = [0]*100
    time_re +=1
n = int(input())

for _ in range(n):
    start_y, max_x = map(int, input().split())
    max_x = 99  - max_x

    for y in range(start_y, start_y + 10):
        for x in range(max_x - 9, max_x + 1):
            paper[x][y] = 1
            time_re +=1

result = 0
for i in range(100):
    for j in range(100):
        time_re +=1
        if paper[i][j] == 1:
            result += 1

print(result)
print(time_re)