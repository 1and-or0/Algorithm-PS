import sys
input = sys.stdin.readline

t = int(input())
nums = []
for _ in range(t):
    nums.append(int(input()))
    
nums.sort()

for i in range(len(nums)):
    print(nums[i])