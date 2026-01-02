from random import randint
n = randint(10, 30) #int(input())

a_list = []
b_list = []

for _ in range(n):
    a_list.append(randint(1, 100))
    # a_list.append(int(input()))

for _ in range(n):
    b_list.append(randint(1, 100))
    # b_list.append(int(input()))

print(a_list)
print(b_list)

k = randint(2, 5)  # int(input())

for _ in range(k):
    a_min = min(a_list)
    b_max = max(b_list)

    if a_min < b_max:
        a_i = a_list.index(a_min)
        b_i = b_list.index(b_max)
        a_list[a_i], b_list[b_i] = b_list[b_i], a_list[a_i]

print(a_list)
print(b_list)