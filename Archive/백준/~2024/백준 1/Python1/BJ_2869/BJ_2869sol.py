a, b, v = map(int, input().split())

result = (v-b)/(a-b)
if result == int(result):
    print(int(result))
else:
    print(int(result) + 1)