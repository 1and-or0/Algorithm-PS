n = int(input())
nums = list(map(int, input().split()))

nums.sort()
result = 0
count = 0
maxLen = 0
for i in range(n):
    count += 1
    if count >= nums[i]:
        result += 1
        count = 0

print(result)
