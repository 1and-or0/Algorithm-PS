def dfs(x, y):
    global check
    if x < 0 or x >= n or y < 0 or y >= n:
        return False

    if graph[x][y] == 0:
        return False

    if graph[x][y] == 1:
        check += 1
        graph[x][y] = 0

        dfs(x - 1, y)
        dfs(x + 1, y)
        dfs(x, y - 1)
        dfs(x, y + 1)
        return True

    return False


n = int(input())

graph = []
for _ in range(n):
    graph.append(list(map(int, list(input()))))

# 단지별 집 수
count = []
# 총 단지 수
result = 0
global check
for i in range(n):
    for j in range(n):
        check = 0
        if dfs(i, j):
            result += 1
            count.append(check)

count.sort()
print(result, *count, sep='\n')
