n = int(input())

nums = list(map(int, input().split()))
dict_ = {}

no_repeat = list(set(nums))
no_repeat.sort()
for i in range(len(no_repeat)):
    dict_[no_repeat[i]] = i

for i in range(len(nums)):
    print(dict_[nums[i]], end=' ')
