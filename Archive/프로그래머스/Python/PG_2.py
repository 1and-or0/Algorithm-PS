# OX 퀴즈
def solution(quiz):
    answer = []
    for i in range(len(quiz)):
        arr = list(quiz[i].split("="))
        if eval(arr[0]) == eval(arr[-1]):
            answer.append("O")
        else:
            answer.append("X")
    return answer


quiz = ["3 - 4 = -3", "5 + 6 = 11"]
print(solution(quiz))
