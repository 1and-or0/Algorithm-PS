n = int(input())
a = list()

for _ in range(n):
    a.append(int(input()))

count = [0] * (max(a) + 1)
for i in range(len(a)):
    count[a[i]] += 1
    
for i in range(len(count)):
    for j in range(count[i]):
        print(i)
