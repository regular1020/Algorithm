case = int(input())

for i in range(case):
    line = input()
    a = int(line.split(" ")[0])
    b = int(line.split(" ")[1])
    a = a % 10
    process = 1
    squared_list = [a]
    j = 2
    while True:
        if ((a**j) % 10) == a:
            break
        squared_list.append((a**j) % 10)
        j = j+1
    result = squared_list[(b-1) % len(squared_list)]
    if result == 0:
        print(10)
    else:
        print(result)