from collections import deque
import sys
input = sys.stdin.readline

n, m, v = map(int, input().split())

graph = [0] * (n+1)

for i in range(1, len(graph)):
    graph[i] = []

for i in range(m):
    val1, val2 = map(int, input().split())
    graph[val1].append(val2) 
    graph[val2].append(val1) 

visited1 = [False] * (len(graph) + 1)
visited2 = [False] * (len(graph) + 1)

for i in range(1, n+1):
    graph[i].sort()

def dfs(graph, start, visited):
    visited[start] = True

    print(start, end=' ')

    for i in graph[start]:
        if not visited[i]:
            dfs(graph, i, visited)


def bfs(graph, start, visited):
    visited[start] = True
    q = deque([start])   
    while q:
        v = q.popleft()
        print(v, end=' ')

        for i in graph[v]:
            if not visited[i]:
                q.append(i)
                visited[i] = True


dfs(graph, v, visited1)
print()
bfs(graph, v, visited2)