start = int(input())
end = int(input())

nums = list(num for num in range(start, end + 1))

decimal = []

for num in nums:
    if num == 1:
        continue
    denominator = []
    for i in range(1, int(num**0.5)+1):
        if num % i == 0:
            denominator.append(i)
            if i ** 2 != num:
                denominator.append(int(num//i))

        if len(denominator) > 2:
            break

    if len(denominator) == 2:
        decimal.append(num)

if len(decimal) != 0:
    print(sum(decimal))
    print(decimal[0])
else:
    print(-1)