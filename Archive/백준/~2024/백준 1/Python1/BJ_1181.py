n = int(input())

str_s = []
for _ in range(n):
    str_s.append(input())

str_s = list(set(str_s))
str_s.sort(key=lambda x : (len(x), x))  # 요소 길이로 우선 정렬, 이후에 사전순으로

for s in str_s:
    print(s)