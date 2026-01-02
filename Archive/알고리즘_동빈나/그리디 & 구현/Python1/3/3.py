s = "02984"
a = list(s)

for i in range(len(s)):
    a[i] = int(a[i])

result = a[0]
for i in range(1, len(s)):
    if a[i-1] <= 1 or a[i] <= 1:
        print("+ 연산을 수행")
        result += a[i]
    else:
        print("x 연산을 수행")
        result *= a[i]

print(result)
