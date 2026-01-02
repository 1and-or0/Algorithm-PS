# 두 큐 합 같게 만들기
from collections import deque
def solution(queue1, queue2):
    queue1, queue2 = deque(queue1), deque(queue2)
    answer = 0
    s1, s2 = sum(queue1), sum(queue2)
    max_repeat = len(queue1)+len(queue2) * 2

    for _ in range(max_repeat):
        if s1 == s2:
            return answer
        elif s1 > s2:
            answer += 1
            temp = queue1.popleft()
            s1 -= temp
            queue2.append(temp)
            s2 += temp
        else:  # s1 < s2:
            answer += 1
            temp = queue2.popleft()
            s2 -= temp
            queue1.append(temp)
            s1 += temp

    answer = -1
    return answer


queue1 = [3, 2, 7, 2]  # 14   3  11 / [1, 2, 1, 2]
queue2 = [4, 6, 5, 1]  # 16   4  12 / [1, 10, 1, 2]
print(solution(queue1, queue2))
