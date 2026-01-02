n = int(input())

hex_layer = 1

count = 1
while n > count:
    count += hex_layer * 6
    hex_layer += 1

print(hex_layer)
