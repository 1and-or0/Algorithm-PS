n = int(input())

cnt = 0
for i in range(1, n+1):
    if i**2 <= n:
        cnt += 1
    else:
        break

print(cnt)
