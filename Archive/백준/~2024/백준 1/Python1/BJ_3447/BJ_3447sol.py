import sys

for line in sys.stdin:
    while 'BUG' in line:
        line = line.replace('BUG', '')
    print(line, end='')
