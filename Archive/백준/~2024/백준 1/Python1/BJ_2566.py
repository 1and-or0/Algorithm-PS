matrix = [0]* 9

for i in range(9):
    matrix[i] = list(map(int, input().split()))

i_max = [-1, -1, -1]

for i in range(9):
    for j in range(9):
        if i_max[0] < matrix[i][j]:
            i_max[0] = matrix[i][j]
            i_max[1] = i
            i_max[2] = j

print(i_max[0])
print(i_max[1]+1, i_max[2]+1)
