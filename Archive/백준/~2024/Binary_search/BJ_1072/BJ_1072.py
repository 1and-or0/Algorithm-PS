import sys
input = sys.stdin.readline

x, y = map(int, input().split())

# 부동소수점 오류 생각해서 int() 쓰지 말고 // 사용. *100 순서도 중요
z = (y * 100) // x
temp = z

# 승률이 99 이상이면 바로 -1을 출력 아... 99... 멍청한 나
if z < 99 :
    left = y
    right = 1000000000*2
    mid = 0
    while left + 1 < right:
        mid = (left + right) // 2
        # 승률 재계산 총 이긴 횟수/총 게임 횟수 * 100
        temp = (mid * 100) // (x + mid - y)
        
        if temp == z:
            left = mid
        else: 
            right = mid
            
    print(right - y)
else:
    print(-1)
