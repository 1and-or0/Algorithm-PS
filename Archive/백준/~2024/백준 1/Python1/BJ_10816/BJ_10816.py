n = int(input())

count1 = [0]* (10000000+1)
count2 = [0]* (1000000+1)

for a in list(map(int, input().split())):
    if a < 0:
        count2[a] += 1
    else:
        count1[a] += 1
m = int(input())
nums = list(map(int, input().split()))

for n in nums:
    if n < 0:
        print(count2[n], end=' ')
    else:
        print(count1[n], end=' ')
