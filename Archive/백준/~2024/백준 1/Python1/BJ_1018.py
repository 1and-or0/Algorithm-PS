n, m = map(int, input().split())

board = []
for _ in range(n):
    board.append(list(input()))

start = []
for x in range(n-7):
    for y in range(m-7):
        start.append(tuple([x, y]))

does1_B = [] # 처음 시작이 B로 칠하는 경우
does1_W = [] # 처음 시작이 W로 칠하는 경우
for x_y in start:
    do1 = 0
    do2 = 0
    for x in range(x_y[0], x_y[0]+8):
        for y in range(x_y[1], x_y[1]+8):
            if x % 2 == 0 and y % 2 == 0:
                if board[x][y] != 'B':
                    do1 += 1
                else:  # board[x][y] != 'W':
                    do2 += 1

            elif x % 2 == 1 and y % 2 == 1:  # x % 2 == 1 and y % 2 == 1:
                if board[x][y] != 'B':
                    do1 += 1
                else: # board[x][y] != 'W':
                    do2 += 1

            elif x % 2 == 1 and y % 2 == 0: 
                if board[x][y] != 'W':
                    do1 += 1
                else:
                    do2 += 1

            elif x % 2 == 0 and y % 2 == 1:
                if board[x][y] != 'W':
                    do1 += 1
                else:
                    do2 += 1
    does1_B.append(do1)
    does1_W.append(do2)

print(min(does1_B) if min(does1_B) < min(does1_W) else min(does1_W))
