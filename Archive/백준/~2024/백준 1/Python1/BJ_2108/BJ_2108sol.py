from collections import Counter
import sys
input = sys.stdin.readline

n = int(input())

nums = []
for _ in range(n):
    nums.append(int(input()))

average = int(round(sum(nums)/n))
print(average)
nums.sort()
mid = nums[n//2]
print(mid)

# Counter(배열) -> 배열의 요소 개수 반환

# Counter(배열).most_common() -> 배열에서 최빈값 반환
# cnt = 리스트 요소로 튜플을 가짐 튜플은 (최빈값1, 등장횟수)로 구성
# 아래의 경우 예제 입력3에서 cnt = [(-2, 2), (-1, 2)]로 구성됨
most_nums = Counter(nums).most_common(2)

if len(most_nums) > 1:
    # 최빈값의 등장 횟수가 같으면
    if most_nums[0][1] == most_nums[1][1]:
        print(most_nums[1][0]) # 두번째로 작은 값 출력
    else: # 아니면 최빈값 출력
        print(most_nums[0][0])
else:
    print(most_nums[0][0])

print(max(nums)-min(nums))