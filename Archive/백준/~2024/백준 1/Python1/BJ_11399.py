m = int(input())

p = list(map(int, input().split()))
p.sort()

list_ = []
temp = 0
for i in range(m):
    temp += p[i]
    list_.append(temp)
    
print(sum(list_))
