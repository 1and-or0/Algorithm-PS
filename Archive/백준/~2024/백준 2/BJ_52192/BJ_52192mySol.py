import sys
input = sys.stdin.readline

# 입력 받기
n = int(input())

# <알고리즘~>
ans = 0
names = set()
for _ in range(n):
    keyword = input()[:-1]
    if keyword != "ENTER":
        names.add(keyword)
    else:
        ans += len(names)
        names = set()

if names:
    ans += len(names)
# <~알고리즘>

# 정답 출력
print(ans)
