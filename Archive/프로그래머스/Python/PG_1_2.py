# 개인 정보 수집 유효 기간
def solution(today, terms, privacies):
    dict_ = {}
    for t in terms:
        t_type, duration = t.split()
        dict_[t_type] = int(duration)

    today_static = list(map(int, today.split('.')))

    answer = []
    for case_ in range(len(privacies)):
        date_, term = privacies[case_].split()
        term = dict_[term]

        date_ = list(map(int, date_.split('.')))

        if date_[1] + term > 12:
            date_[0] += (date_[1] + term) // 12
            date_[1] = (date_[1] + term) - ((date_[1] + term) // 12 * 12)
        else:
            date_[1] += term

        date_sum = date_[0]*12*28 + date_[1]*28 + date_[2]
        today_sum = today_static[0]*12*28 + today_static[1]*28 + today_static[2]
        if today_sum >= date_sum:
            answer.append(case_ + 1)
    return answer


today = "2020.01.01"
terms = ["Z 3", "D 5"]
privacies = ["2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z"]
print(solution(today, terms, privacies))
