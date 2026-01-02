from collections import deque

n, m = map(int, input().split())

b_list = list(range(1, n+1))

# print(b_list.pop(2))

for i in range(m):
    start, end, mid = map(int, input().split())
    start -= 1
    end -= 1
    mid -= 1

    q = deque()

    for i in range(start, end + 1):
        if i < mid:
            q.append(b_list[i])
        if i < start + end - mid + 1:
            b_list[i] = b_list[i+mid-start]
        if i > start + end - mid:
            b_list[i] = q.popleft()


for i in range(len(b_list)):
    print(b_list[i], end=' ')
