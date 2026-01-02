board = input()
my = {"XXXX" : "AAAA", "XX": "BB"}

board = board.replace("XXXX", my["XXXX"])
board = board.replace("XX", my["XX"])

flag = True
for i in range(len(board)):
    if 'X' == board[i]:
        print(-1)
        flag = False
        break

if flag:
    print(board)