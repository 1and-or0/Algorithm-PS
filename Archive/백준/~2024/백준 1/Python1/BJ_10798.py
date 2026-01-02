st_list = [0]*5

max_len = 0
for _ in range(5):
    st_e = input()
    st_list[_] = list(st_e)
    if max_len < len(st_e):
        max_len = len(st_e)


for i in range(max_len):
    for j in range(5):
        try:
            print(st_list[j][i], end='')
        except IndexError:
            continue