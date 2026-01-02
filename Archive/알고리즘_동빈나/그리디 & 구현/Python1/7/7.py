n = input()

# 현재 나이트의 위치 ex) a1
y = ord(n[0]) - ord('`')
x = int(n[1])

# 나이트가 움직일 수 있는 위치
moves = list()
moves = [[-1, -2], [-2, -1],
              [-2, 1], [-1, 2],
              [1, 2], [2, 1],
              [2, -1], [1, -2]]

for i in range(8):
    nx = x
    ny = y
    nx += moves[i][0]
    ny += moves[i][1]

    if nx > 0 and ny > 0 and nx < 9 and ny < 9:
        print(f"({nx}, {ny})")
        print(f"{chr(ny+ord('`'))}{nx}")
