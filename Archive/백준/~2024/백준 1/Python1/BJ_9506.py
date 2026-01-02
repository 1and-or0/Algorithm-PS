t = int(input())

while t != -1:
    list_ = []
    i = 1
    while int(t/i) >= i:
        if t % i == 0:
            list_.append(i)
            if int(t/i) != i and int(t/i) != t:
                list_.append(int(t/i))
        i += 1

    list_.sort()

    if sum(list_) == t:
        print(f"{t} ", end='=')
        for i in range(len(list_) - 1):
            print(f" {list_[i]} " , end="+")
        print(f" {list_[-1]}")
    else:
        print(f"{t} is NOT perfect.")
     
    t = int(input())