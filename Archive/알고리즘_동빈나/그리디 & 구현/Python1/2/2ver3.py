# ver2 보다 별로인...
n, k = map(int, input().split())

count = 0
while n != 1:
    if n % k == 0:
        count += 1
        n //= k
    else:
        if n < k:
            count += n % k
            n -= n % k
        else:
            count += (n % k) - 1
            n -= (n % k) - 1

print(count)
