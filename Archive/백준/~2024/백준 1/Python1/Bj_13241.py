small, big = map(int, input().split())
if big < small:
    small, big = big, small

big_temp, small_temp = big, small

left = big_temp % small_temp
while left != 0:
    big_temp = small_temp
    small_temp = left
    left = big_temp % small_temp

print(big*small//small_temp)
