import sys
input_ = sys.stdin.readline
n = int(input_())

stack_ = []
for _ in range(n):
    for i in range(n):
        in_line = input_()
        in_line = in_line.strip('\n')
        if ' ' in in_line:
            order, x = in_line.split()
            stack_.append(int(x))
        else:
            if in_line == "pop":
                if len(stack_) > 0:
                    print(stack_.pop())
                else:
                    print(-1)
            elif in_line == "size":
                print(len(stack_))
            elif in_line == "empty":
                print(1 if len(stack_) == 0 else 0)
            elif in_line == "top":
                if len(stack_) != 0:
                    print(stack_[-1])
                else:
                    print(-1)
