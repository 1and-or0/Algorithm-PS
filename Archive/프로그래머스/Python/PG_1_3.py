def solution(survey, choices):
    match = [('R', 'T'), ('C', 'F'), ('J', 'M'), ('A', 'N')]

    dict_score = {}
    for t in range(len(match)):
        for t2 in range(len(match[t])):
            dict_score[match[t][t2]] = 0
    # exit_keys.sort()
    # match = [0] * 4  # ('T', 'R'), ('C', 'F'), ('J', 'M'), ('A', 'N')  # [ A C _F J _M _N R _T ]
    # for k in dict_keys:
    #     if k == 'A' or k == 'N':
    #         match[3] = tuple(['A', 'N'])
    #     elif k == 'C' or k == 'F':
    #         match[1] = tuple(['C', 'F'])
    #     elif k == 'J' or k == 'M':
    #         match[2] = tuple(['J', 'M'])
    #     else:
    #         match[0] = tuple(['T', 'R'])
    for j in range(len(choices)):
        negative = survey[j][0]
        positive = survey[j][1]

        if choices[j] == 4:
            continue
        elif choices[j] > 4:  # 동의 choices[] 5 이면 1, 6이면 2, 7이면 3 따라서 choic - 4
            # pass  # positive 점수 up
            dict_score[positive] += choices[j] - 4
        elif choices[j] < 4:  # 비동의 choices[] 3 이면 1, 2이면 2, 1이면 3 따라서 4 - choic
            # pass  # negative 점수 up
            dict_score[negative] += 4 - choices[j]

    answer = ''
    for i in range(len(match)):
        # if dict_score[match[i][0]] == dict_score[match[i][1]]:
        #     answer += match[i][0]
        #     continue
        if dict_score[match[i][0]] >= dict_score[match[i][1]]:
            answer += match[i][0]
        elif dict_score[match[i][0]] < dict_score[match[i][1]]:
            answer += match[i][1]

    return answer


survey = ["AN", "CF", "MJ", "RT", "NA"]
choices = [5, 3, 2, 7, 5]
print(solution(survey, choices))
