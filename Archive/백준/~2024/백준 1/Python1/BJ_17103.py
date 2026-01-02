import sys
is_prime = [1]*1000001
is_prime[0], is_prime[1] = 0, 0

for num in range(2, int(1000001**0.5)+1):
    for j in range(num*2, 1000001, num):
        is_prime[j] = 0

t = int(sys.stdin.readline())

for _ in range(t):
    cnt = 0
    n = int(sys.stdin.readline())
    val1 = n // 2
    if val1 > 2 and val1 % 2 == 0:
        val1 -= 1

    for i in range(val1, 1, -2):
        if is_prime[i] and is_prime[n-i]:
            cnt += 1

    print(cnt)
