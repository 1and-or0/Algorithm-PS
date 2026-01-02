str1 = input()

# 첫 번째 문자를 숫자로 변경하여 대입
result = int(str1[0])

for i in range(1, len(str1)):
    # 두 수 중에서 하나라도 '0' or '1'인 경우, + 연산 수행
    num = int(str1[i])
    if num <= 1 or result <= 1:
        result += num
    else:
        result *= num

print(result)
