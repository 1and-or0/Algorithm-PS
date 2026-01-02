from collections import deque

# BFS 함수 정의
def bfs(graph, start, visited):
    queue = deque([start])
    # print(type([start]))
    # 현재 노드를 방문 처리
    visited[start] = True
    
    while queue:
        v = queue.popleft()
        print(v, end=' ')

        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True

    
visited = [False] * 9

graph = [
    [],  # 0번 노드... 없으...
    [2, 3, 8],  # 1번 노드와 인접한 노드        ____ 1______
    [1, 7],  # 2번 노드와 인접한 노드         _2    _3_     8
    [1, 4, 5],  # 3번 노드와 인접한 노드    _7     4---5   /  
    [3, 5],  #                           6  \___________/ 
    [3, 4],
    [7],
    [2, 6, 8],
    [1, 7]
]

bfs(graph, 1, visited)
