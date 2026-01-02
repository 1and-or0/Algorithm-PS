from collections import deque
n = int(input())

result = 0
for i in range(n):
    q = deque()
    for a in list(input()):
        q.append(a)

    checked = deque(q[0])  # 
    result += 1
    while q:
        checked.append(q[0])
        if checked[-1] == q[0]:
            if checked[-2] == q[0]:
                q.popleft()
            elif checked.count(q[0]) == 1:
                q.popleft()
            else:
                result -= 1
                break
    

print(result)
