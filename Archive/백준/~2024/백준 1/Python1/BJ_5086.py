n = input()

while n != "0 0":
    a1, a2 = map(int, n.split())

    if a2 % a1 == 0:
        print("factor")
    elif a1 % a2 == 0:
        print("multiple")
    else:
        print("neither")

    n = input()