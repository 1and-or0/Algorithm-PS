import sys
from math import gcd  # 유클리드 호제법 알고리즘 라이브러리가 있었네... 나는 몰랐네... 직접 작성했었는데...

n = int(sys.stdin.readline())

before_num = int(sys.stdin.readline())

gaps = []

for i in range(n-1):
    num_after = int(sys.stdin.readline())
    gaps.append(num_after - before_num)
    before_num = num_after

min_g = gaps[0]
for j in range(1, len(gaps)):
    min_g = gcd(min_g, gaps[j])  # 수열의 수마다 서로의 최대공약수를 반복적으로 구해가면 모든 정의역의 최대공약수가 구해짐!

result = 0
for a_gap in gaps:  # 8의 간격이 있고, 2의 간격으로 나무를 심어줘야 할 때, 나무는 3그루 = 8//2 - 1그루를 더 심어야 함
    result += a_gap // min_g - 1
print(result)
