goal = int(input())

num = 665
count = 0
while count != goal:
    num += 1
    # 이렇게 하면 6이 연속되지 않은 것도 세어버림
    # if list(str(num)).count('6') >= 3:
    if "666" in str(num):  # 이렇게 하면 정답!
        count += 1
        
print(num)
