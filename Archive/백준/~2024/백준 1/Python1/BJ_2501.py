list_ = []

n, k = map(int, input().split())

a = 1
while (n / a) >= a:
    if n % a == 0:
        list_.append(a)
        if int(n//a) != a:
            list_.append(int(n//a))
    a += 1

list_.sort()

if (k) <= len(list_):
    print(list_[k-1])
else:
    print(0)