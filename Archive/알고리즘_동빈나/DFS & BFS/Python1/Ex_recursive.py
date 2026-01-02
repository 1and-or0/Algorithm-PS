print("Hello world")

# 반복적으로 구현한 펙토리얼
def factorial_iterative(n):
    result = 1

    for i in range(1, n+1):
        result *= i 
    return result


# 재귀적으로 구현한 펙토리얼
def factorial_recursive(n):
    if n <= 1:
        return 1
    else:
        return n * factorial_recursive(n-1)

print("iterative", factorial_iterative(5))
print("recursive", factorial_recursive(5))