import sys
input = sys.stdin.readline

n , m = map(int, input()[:-1].split())

site_pw = dict()

for _ in range(n):
    name, pw = input()[:-1].split()
    site_pw[name] = pw

sites = []
for _ in range(m):
    sites.append(input()[:-1])

for site in sites:
    print(site_pw[site])
