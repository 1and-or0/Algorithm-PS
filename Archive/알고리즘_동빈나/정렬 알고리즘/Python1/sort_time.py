from random import randint
import time

array = []

for i in range(5000):
    array.append(randint(1, 100))

start_time = time.time()

array.sort()

end_time = time.time()

print(end_time - start_time)
# 0¿¡ ¼ö·Å