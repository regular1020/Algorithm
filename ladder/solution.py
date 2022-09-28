testCase = int(input())
for c in range(testCase):
    n, m, d = map(int, input().split(" "))
    ladder_map = []
    for i in range(m):
        ladder_map.append(input())
    current_y = m
    current_x = d*2-2
    while(current_y >= 0):
        current_y = current_y-1
        if (current_y < 0):
            break
        if (current_x+2 <= n*2-2):
            if (ladder_map[current_y][current_x+1] == "+"):
                current_x = current_x+2
        elif (current_x-2 >= 0):
            if (ladder_map[current_y][current_x-1] == "+"):
                current_x = current_x-2
    print(int((current_x+2)/2))
