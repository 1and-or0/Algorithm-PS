import sys
input = sys.stdin.readline

data = []
n = int(input())
for _ in range(n):
    data.append(list(map(int, input().split())))
# d[i] i일 상담할 때의 최대 금액
d = [0] * (n+1)
for i in range(1, n+1):
    t, p = data[i-1][0], data[i-1][1]
    if i+t-1 <= n:  # 상담이 퇴사일 전까지 끝나면
        d[i+t-1] = max(d[i+t-1], d[i-1] + p)
    if d[i] < d[i-1]:  # 하루 적게 상담할 때의 금액이 더 큰 경우
        d[i] = d[i-1]

print(max(d))
