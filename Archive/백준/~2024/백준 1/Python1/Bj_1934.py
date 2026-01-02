# 유클리드 호제법
# 192 162  %->  30
# 162 30  %->  12
# 30 12  %->  6
# 12 6  %->  0
# 192 / 6 = 32
# 162 / 6 = 27
# 162 * 32 = 5184
# 192 * 27 = 5184
t = int(input())

for _ in range(t):
    small, big = map(int, input().split())
    small_temp, big_temp = small, big

    # gcd 최대공약수
    r = big_temp % small_temp
    while r != 0:
        big_temp = small_temp
        small_temp = r
        r = big_temp % small_temp
    gcd = small_temp

    # scm 최소공배수
    condition1 = small * (big//gcd)
    condition2 = big * (small//gcd)
    if condition1 == condition2:
        scm = condition1  # condition2로 해도 상관x
        print(scm)
