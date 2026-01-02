t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    arr = list(map(int, input().split()))

    dp = []
    for i in range(n):
        dp.append(arr[i*m:i*m+m])

    for j in range(1, m):
        for k in range(n):
            # 왼쪽 위에서 오는 경우
            if i == 0:
                left_up = -1
            else:
                left_up = dp[k-1][j-1]

            # 왼쪽 아래에서 오는 경우
            if i == n-1:
                left_down = -1
            else:
                left_down = dp[k+1][j-1]

            # 왼쪽에서 오는 경우
            left = dp[k][j-1]

            dp[k][j] += max(left_up, left, left_down)

    result = -2
    for i in range(n):
        result = max(result, dp[i][-1])
    print(result)

