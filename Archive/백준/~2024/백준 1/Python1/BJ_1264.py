import sys
input = sys.stdin.readline

vowel = ['a', 'e', 'i', 'o', 'u', 'I', 'A', 'O', 'U', 'E']

st1 = input()[:-1]
while st1[0] != '#':
    ans = 0
    for i in vowel:
        ans += st1.count(i)
    print(ans)
    
    st1 = input()[:-1]    
