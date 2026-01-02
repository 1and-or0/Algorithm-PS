import sys
input = sys.stdin.readline

n = int(input())
len_ = int(input())
str_ = input()

pn = "I"
pn_1 = "I"
for i in range(n):
    pn += "OI"
    pn_1 += "OI"
pn_1 = pn_1[:-2]

print("pn:", pn)
print("pn-1:", pn_1)

result = 0
while pn in str_:
    result += str_.count(pn)
    str_ = str_.replace(pn, pn_1)
print(result)
