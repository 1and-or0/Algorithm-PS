# 동빈이네 떡집 절단기

# 떡의 길이가 19, 17, 14, 10
# 손님이 요청한 길이 6
# 절단기 길이 15
# 바뀐 떡의 길이 15, 15, 14, 10 잘려 나온 떡의 길이 4, 2, 총 6

# 손님이 요청한 길이를 입력받고 적어도 그 만큼의 떡을 자르기위한
# 절단기 길이의 최댓값을 구하기

request = int(input())

basic_ddack = list(map(int, input().split()))

# 내가 생각한 해결 아이디어 
# 떡의 길이를 입력받은 리스트에서, 이진 탐색을 수행하며 절단 과정을 수행
# 그렇게 잘려나온 떡의 길이가 손님이 요청한 떡의 길이보다 크거나 같을 때
# 를 찾아가기

basic_ddack.sort()
ddack = [dd for dd in basic_ddack]

start = 0
end = len(basic_ddack) - 1
while start <= end:
    mid = (start + end) // 2
    h = basic_ddack[mid]
    for i in range(start, end+1):
        if basic_ddack[i] > h:
            ddack[i] = basic_ddack[i] - h

    if sum(ddack) == request:
        break
    elif sum(ddack) < request:
        end = mid - 1
    elif sum(ddack) > request:
        start = mid + 1

        
print()