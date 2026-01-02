# 옹알이2
# 11줄에서 주의사항 raplace(a, "")으로 작성할 경우
# yayae라는 문자열을 확인할 때, ye가 남아버려 원래는 
def solution(babbling):
    a_can = ["aya", "ye", "woo", "ma"]  # 2, 3, 1개   4, 5, 6, 2개   7, 8, 3개   10 4개

    answer = 0

    for word in babbling:
        for a in a_can:
            if a*2 not in word:
                word = word.replace(a, " ")
        if word.strip() == '':
            answer += 1
    return answer

