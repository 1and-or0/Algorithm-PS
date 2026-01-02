
from collections import deque

# 큐 구현 - deque 라이브러리 사용
# deque는 양쪽에서 입출력이 가능하다고... 
# Queue라는 라이브러리 있지만 일반적으로 큐 구현하는 라이브러리 X
queue = deque()

queue.append(5)
queue.append(2)
queue.append(3)
queue.append(7)

queue.popleft()

queue.append(1)
queue.append(4)

queue.popleft()

# 먼저 들어온 순서대로 출력
print(queue)

#나중에 들어온 순서대로 출력
queue.reverse()
print(queue)