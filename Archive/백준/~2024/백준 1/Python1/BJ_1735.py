def gcd(a, b):
    if a == b:
        return a  # b여도 ok

    big, small = (a, b) if a > b else (b, a)
    r = big % small
    while r != 0:
        big = small
        small = r
        r = big % small
    return small


a_s, a_m = map(int, input().split())
b_s, b_m = map(int, input().split())

gcd_a_b = gcd(a_m, b_m)

scm = a_m * b_m // gcd_a_b
for_a = scm//a_m
for_b = scm//b_m

for_son = a_s * for_a + b_s * for_b

# 분자 분모의 최대공약수로 나누기
gcd = gcd(for_son, scm)
for_son, for_mom = for_son//gcd, scm//gcd

# 기약분수이면
print(for_son, for_mom)
