n = int(input())

people = []
for _ in range(n):
    age, name = input().split()
    people.append(tuple([int(age), name]))

people.sort(key=lambda x : x[0])

for p_info in people:
    print(p_info[0], p_info[1])

