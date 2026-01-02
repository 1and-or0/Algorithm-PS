st = input().upper()

count = [0] * 26;
#print(len(count))

for i in st:
    count[ord(i) - ord("A")] += 1
    
n_m = max(count)

if count.count(n_m) == 1:
    print( chr(count.index(max(count)) + ord("A")) )
else:
    print('?')
