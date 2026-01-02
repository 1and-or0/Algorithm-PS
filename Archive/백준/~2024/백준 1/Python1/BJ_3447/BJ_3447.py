list_ = []
list_len = 0
while True:
    try:
        list_len += 1;
        list_.append(input())
        if list_[-1] == '..':
            break
    except:
        list_len -= 1
        break

for i in range(list_len):
    while "BUG" in list_[i]:
        list_[i] = list_[i].replace("BUG", '')

for i in range(list_len):
    print(list_[i])