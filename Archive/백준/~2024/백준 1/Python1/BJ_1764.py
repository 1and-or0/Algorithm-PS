import sys
input = sys.stdin.readline

n, m = map(int, input().split())
name_l = []
name_s = []

for i in range(n):
    name_l.append(input()[:-1])
    
for i in range(m):
    name_s.append(input()[:-1])
    
name = list(set(name_l) & set(name_s))
print(len(name))
name.sort()
for n in name:
    print(n)