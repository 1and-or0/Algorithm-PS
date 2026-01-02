# DFS 함수 정의 v: 탐색 시작 노드, visited: 각 노드의 방문 여부 확인, graph: 각 노드의 인접 노드에 대한 정보
def dfs(graph, v, visited):
    # 현재 노드를 방문 처리 True: 방문, False: 미방문
    visited[v] = True
    print(v, end=' ')
    # 현재 노드와 연결된 다른 노드를 재귀적으로 방문
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)


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

# 각 노드가 방문된 정보를 표현 (1차원 리스트)
visited = [False] * 9

# 정의된 DFS 함수 호출
dfs(graph, 1, visited)


# 자료구조 stack을 이용. 
# DFS 숫자가 낮은 노드부터 실행할 경우
# 시작노드: 1인 경우
# stack
# 5
# 4
# 3
# 8
# 6
# 7
# 2
# 1
