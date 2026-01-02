n = int(input())
x, y = 1, 1  # 출발점 행렬 시작값

plans = input().split()

# L, R, U, D에 따른 방향 이동 (벡터  =>     #  (0, 0)       (0, 1)       (0, 2)     (0, 3) /\
dx = [0, 0, -1, 1]  # 행렬 참고    =>     #  (1, 0) <={L} (1, 1) {R}=> (1, 2) {D} (1, 3) {U}
dy = [-1, 1, 0, 0]  # 행렬 참고    =>     #  (2, 0)       (2, 1)       (2, 2) \/  (2, 3)
move_types = ['L', 'R', 'U', 'D']

# 이동 계획(= plans)을 하나씩 확인
for plan in plans:
    # 이동 후 좌표 구하기
    for i in range(len(move_types)):
        if plan == move_types[i]:
            nx = x + dx[i]  # nx: x 변위
            ny = y + dy[i]  # ny: y 변위
    # 공간을 벗어난 경우는 무시
    if nx < 1 or ny < 1 or nx > n or ny > n:
        continue
    # 이동 수행
    x, y = nx, ny

print(x, y)
