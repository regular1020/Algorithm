n = input()
f = int(input())

head = int(n[:-2])
left = head % f
tail = str(f - 1)
if len(tail) == 1:
    tail = "0"+tail
tmp = int(str(left) + tail)
lft = tmp % f
if lft != 0:
    print_str = str(f - 1 - lft)
    if len(print_str) == 1:
        print_str = "0" + print_str
    print(print_str)
else:
    print(tail)
