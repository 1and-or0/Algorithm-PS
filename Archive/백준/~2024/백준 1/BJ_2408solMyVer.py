n = int(input())

list_ = []
for _ in range(2*n-1):
    list_.append(input())

op = ('+', '-', '*', '/')
result = ""
for i in list_:
    result += i

print(int(eval(result)))
