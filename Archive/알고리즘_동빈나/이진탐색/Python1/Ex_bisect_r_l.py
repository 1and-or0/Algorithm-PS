from bisect import bisect_left, bisect_right
# _left는 원소가 삽입될 수 있는 가장 왼쪽 인덱스 반환
# _right는 원소가 삽입될 수 있는 가장 오른쪽 인덱스 반환
a = [1, 2, 4, 4, 8]
x = 4

print(bisect_right(a, 4))
print(a)
a.insert(bisect_right(a, 4), x)

print(bisect_left(a, 4))
print(a)

# 특정 범위에 속하는 데이터 개수 구하기
# 값이 [left_value, right_value]인 데이터 개수를 반환하는 함수
def count_by_range(a, left_val, right_val):
    right_index = bisect_right(a, right_val)
    left_index = bisect_left(a, left_val)
    return right_index - left_index

