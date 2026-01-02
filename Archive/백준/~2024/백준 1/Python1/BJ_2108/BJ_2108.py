from bisect import bisect_left, bisect_right
n = int(input())

nums =[]
for _ in range(n):
    nums.append(int(input()))

nums.sort()

set_ = set(nums)

# average = sum(nums) // n 을 하면 오류 발생... -1//3 = 0이 나와야 하나 -1이 나옴...
average = int(round(sum(nums)/n))
mid = nums[n//2]

max_gap_num = 0
max_gap = 0
# 시간초과~~ counter 쓰기~~ most_common(2)
for i in set_:
    left_ = bisect_left(nums, i)
    right_ = bisect_right(nums, i)
    gap = right_ - left_
    if max_gap < gap:
        max_gap = gap
        max_gap_num = i

min_max = max(nums) - min(nums)

print(average)
print(mid)
print(max_gap_num)
print(min_max)
