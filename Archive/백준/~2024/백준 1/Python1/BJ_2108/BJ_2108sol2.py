import sys

list2 = [0] * 8001
for _ in range(int(sys.stdin.readline())):
    list2[int(sys.stdin.readline()) + 4000] += 1

# »ê¼ú Æò±Õ
sums = 0
for i, num in enumerate(list2):
    if num == 0:
        continue
    sums += num * (i - 4000)
print(round(sums / sum(list2)))

# Áß¾Ó°ª
mid = int((sum(list2) // 2) + 1)
for i, num in enumerate(list2):
    if num == 0:
        continue
    mid -= num
    if mid <= 0:
        print(i - 4000)
        break

# ÃÖºó°ª
max_cnt = []
m = max(list2)
for i, num in enumerate(list2):
    if num == m:
        max_cnt.append(i - 4000)
    if len(max_cnt) == 2:
        print(max_cnt[1])
        break
else:
    print(max_cnt[0])

# ¹üÀ§
for a, num in enumerate(list2):
    if num != 0:
        for b, num in enumerate(list2[::-1]):
            if num != 0:
                print((b - 4000) * -1 - (a - 4000))
                break
        break
