n, k = map(int, input().split())

result = 0
count_b = 0
while True:
    count_b += 1
    # N이 K로 나누어 떨어지는 수가 될 때까지 빼기 위한 수 target
    target = (n//k) * k
    result += (n - target)
    n = target
    # N이 K보다 작을 때(더 이상 나눌 수 없을 때) 반복문 탈출
    if n < k:
        break
    result += 1
    n //= k

result += (n-1)
print(result)
print(count_b)
