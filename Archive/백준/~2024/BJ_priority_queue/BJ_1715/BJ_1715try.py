from queue import PriorityQueue
import sys
input = sys.stdin.readline

p_q = PriorityQueue()

n = int(input())
for _ in range(n):
    p_q.put(int(input()))

now = p_q.get()
ans = 0
for i in range(p_q.qsize()):
    now += p_q.get()
    ans += now

print(ans)
