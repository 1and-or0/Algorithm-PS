# 퀵 정렬 평균 시간복잡도: O(NlongN), 최악: O(N^2)
array = [7, 5, 9, 0, 3, 1, 6, 2, 4, 8]

# 퀵 정렬 함수(배열, 시작 인덱스, 끝 인덱스)
def quick_sort(array, start, end):
    if start >= end:  # 원소가 1개인 경우 종료
        return

    pivot = start  # 피벗(= 기준값)은 첫 번째 원소
    left = start + 1
    right = end

    # left와 right가 가르키는 값이 서로 교차하지 않으면: 참
    while left <= right:
        # 피벗보다 큰 데이터를 찾을 때까지 반복
        while (left <= end and array[left] <= array[pivot]):
            left += 1

        # 피벗보다 작은 데이터를 찾을 때까지 반복
        while(right > start and array[right] >= array[pivot]):
            right -= 1

        # 엇갈린 경우 left가 가리킨 데이터와 pivot을 swap
        if left > right:
            array[right], array[pivot] = array[pivot], array[right]
        else: # left와 right가 가리키는 데이터 swap
            array[left], array[right] = array[right], array[left]

    # 분할 이후 pivot을 기준으로 왼쪽과 오른쪽 각각 정렬 수행 
    quick_sort(array, start, right - 1)  # array[right]: pivot
    quick_sort(array, right + 1, end)  # array[right]: pivot


quick_sort(array, 0, len(array)-1)
print(array)
