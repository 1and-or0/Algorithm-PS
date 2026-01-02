# 문자열 나누기
str_ = input()
answer = 0
criterion = ''
nums_crit = 0
nums_other = 0
for i in range(len(str_)):
    if criterion == '':
        criterion = str_[i]

    if criterion != str_[i]:
        nums_other += 1
    else:
        nums_crit += 1

    if nums_crit == nums_other:
        nums_crit = 0
        nums_other = 0
        criterion = ''
        answer += 1
if nums_crit != 0:
    answer += 1

print(answer)
