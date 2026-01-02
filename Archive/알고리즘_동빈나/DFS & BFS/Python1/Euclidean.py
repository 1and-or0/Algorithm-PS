def Euclidean_algorithm_iterative(a, b):
    temp_a = a
    a = a if a>b else b
    b = b if a>b else temp_a
    
    r = a % b
    while r!=0:
        a = b
        b = r
        r = a % b
    return b

def Euclidean_algorithm_recursive(a, b):
    temp_a = a
    a = a if a>b else b
    b = b if a>b else temp_a

    r = a%b
    if r != 0:
        return Euclidean_algorithm_recursive(b, r)
    else:
        return b

a = int(input())
b = int(input())

print(Euclidean_algorithm_iterative(a, b))
print(Euclidean_algorithm_recursive(a, b))
