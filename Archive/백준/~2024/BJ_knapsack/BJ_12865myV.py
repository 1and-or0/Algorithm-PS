n, k = map(int, input().split())

arr = [[0, 0]]  # == input, stuff  -  길게 작성하기 싫었어요...
for _ in range(n):
    arr.append(tuple(map(int, input().split())))
# dp ==> knapsack  -  길게 작성하기 싫었어요...
dp = [[0]*(k+1) for _ in range(n+1)]
# dp를 모두 돌며 냅색 알고리즘 갱신
for i in range(n+1):
    for j in range(k+1):
        weight = arr[i][0]
        value = arr[i][1]

        if j < weight:  # 무게가 커 현재 weight의 물건을 못 든다면 이전에 들었던 물건값 가져오기
            dp[i][j] = dp[i-1][j]
        else:  # j - weight를 하면 현재 물건의 weight를 빼고 나머지 weight로 들 수 있는 물건의 값을 가져오게 됨 <- 이것이 색냅알고리즘 lol!!
            dp[i][j] = max(value + dp[i-1][j-weight], dp[i-1][j])
# 냅색 알고리즘이므로 마지막 n행 k열이 최대
print(dp[n][k])
