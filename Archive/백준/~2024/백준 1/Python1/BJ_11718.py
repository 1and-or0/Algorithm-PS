# 백준에서 테스트 케이스로 입력되는 값이 파일로부터 읽어오는구나
# try except 문을 여기서 활용 가능하구나... ㄷㄷ
while True:
    try:
        print(input())
    except EOFError:
        break
