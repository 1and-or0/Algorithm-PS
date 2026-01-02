from turtle import right


not_EOF = True
result = 0
total_score = 0
total_credit = 0
credit = 0
chart_grade = {"A+": 4.5, "A0": 4.0, "B+": 3.5, "B0": 3.0, "C+": 2.5, "C0": 2.0, "D+": 1.5, "D0": 1.0, "F": 0.0, "P": -1} 

while not_EOF:
    try:
        n = input()

        if n[-1] == 'P':
            pass
        elif n[-1] == 'F':
            credit = float(n[-5:-2])
            total_credit += credit
        else:  # if n[-2] != ' ':
            credit = float(n[-6:-3])
            total_credit += credit

            grade = n[-2:]
            grade = chart_grade[grade]
            total_score += credit * grade
    except EOFError:
        result = total_score / total_credit
        not_EOF = False
    except Exception as E:
        print(E)
        result = total_score / total_credit
        not_EOF = False


print(result)
