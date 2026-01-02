n, m = map(int, input().split())

# 화폐의 종류를 저장하는 moneys 리스트
money = []
for _ in range(n):
    money.append(int(input()))


d = [10001] * (m + 1)
d[0] = 0
for i in range(n):  # 화폐 전부 돌음
    for j in range(money[i], m + 1):  # 화폐 단위 ~ 만들 총 합계
        if d[j - money[i]] != 10001:  # 화폐의 조합으로 만들 수 있는 합계인 경우
            d[j] = min(d[j], d[j - money[i]] + 1)

result = d[m]
if result == 10001:
    result = -1

print(result)
