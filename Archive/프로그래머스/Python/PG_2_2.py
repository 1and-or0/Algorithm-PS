from itertools import permutations


def solution(babbling):
    a_word = ["aya", "ye", "woo", "ma"]
    words = a_word[:]
    for i in range(2, len(a_word)+1):
        for x in list(permutations(a_word, i)):
            word = ""
            for j in range(len(x)):
                word += x[j]
            words.append(word)

    answer = 0
    for bb in babbling:
        if bb in words:
            answer += 1
    return answer


babbling = ["ayaye", "uuuma", "ye", "yemawoo", "ayaa"]
print(solution(babbling))
