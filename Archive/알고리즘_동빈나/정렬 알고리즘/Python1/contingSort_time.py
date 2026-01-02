from random import randint
import time

array = []

for i in range(5000):
    array.append(randint(1, 100))

start_time = time.time()

count = [0] * (max(array)+1)

for i in range(len(array)):
    count[array[i]] += 1

for i in range(len(count)):
    for j in range(count[i]):
        print(i, end=' ')
    print()

end_time = time.time()

print(end_time - start_time)
# 0.1106727123260498