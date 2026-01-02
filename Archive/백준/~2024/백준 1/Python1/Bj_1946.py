t = int(input())

for _ in range(t):
    applicants = int(input())

    n_s_d = []
    for _ in range(applicants):
        doc, inter = map(int, input().split())
        n_s_d.append(tuple([doc, inter, doc+inter]))
    n_s_d.sort()
    n_s_i = [_ for _ in n_s_d]
    n_s_i.sort(key=lambda x: (x[1], x[0]))

    get_through = []
    for i in range(applicants):
        if i % 2 == 0:  # 짝수 doc 점수 확인
            try:
                if n_s_d[i][0] <= min(map(lambda x: x[0], get_through)):
                    get_through.append(n_s_d[i])
                elif n_s_d[i][1] <= min(map(lambda x: x[1], get_through)):
                    get_through.append(n_s_d[i])
            except ValueError:
                get_through.append(n_s_d[i])
        else:  # 홀수 inter 점수 확인
            try:
                if n_s_i[i][1] <= min(map(lambda x: x[1], get_through)):
                    get_through.append(n_s_i[i])
                elif n_s_i[i][0] <= min(map(lambda x: x[0], get_through)):
                    get_through.append(n_s_i[i])
            except ValueError:
                get_through.append(n_s_i[i])

    print(len(get_through))
