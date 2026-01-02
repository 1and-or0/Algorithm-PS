from collections import deque

def bfs(x, y):
    queue = deque()
    queue.append((x, y))
    # graph[x][y] = -1
    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            # 맵의 범위를 벗어난 경우
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue

            # 몬스터 or 벽이 있는 경우
            if graph[nx][ny] == 0:
                continue

            # 해당 노드를 처음 방문하면, 시작점부터 그 노드까지 최단 거리 기록
            if graph[nx][ny] == 1:
                graph[nx][ny] = graph[x][y] + 1
                queue.append((nx, ny))
    # 행렬에서 왼쪽 상단을 시작점, 우측 하단을 도착점으로 상정하고 짠 코드
    # 따라서 도착지는 무조건 graph의 [n-1][m-1]이므로 마지막에 return graph[n-1][m-1];하는 것임
    return graph[n-1][m-1]


n, m = map(int, input().split())

graph = []

for i in range(n):
    graph.append(list(map(int, input())))

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

print(bfs(0, 0))
