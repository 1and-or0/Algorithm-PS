n = int(input())

nums = list(map(int, input().split()))

count = 0
for num in nums:
    denominator = []
    for i in range(1, int(num**0.5)+1):
        if num % i == 0:
            denominator.append(i)
            if (i**2) != num:
                denominator.append(int(num//i))

    if len(denominator) == 2:
        count += 1

print(count)
