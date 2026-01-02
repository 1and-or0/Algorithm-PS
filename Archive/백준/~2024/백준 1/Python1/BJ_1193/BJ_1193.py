n = int(input())

n_cross = 0
end = 0
for cross in range(4473):
    cross_end = cross * (cross + 1) / 2
    if cross_end >= n:
        n_cross = cross
        end = int(cross_end)   
        break

if n_cross % 2 == 1:
    x = 1
    y = n_cross
    for i in range(end - n):
        x += 1
        y -= 1
else:  # n_cross % 2 == 0:
    x = n_cross
    y = 1
    for i in range(end - n):
        x -= 1
        y += 1

print(f"{x}/{y}")


# n = int(input())
line = 1

while n > line:
    n -= line
    line += 1

if line % 2 == 0:
    up = n
    down = line - n + 1
else:
    up = line - n + 1
    down = n

print(up,'/',down, sep="")


for i in range(1, 4472):
    print(i*(i+1)/2)