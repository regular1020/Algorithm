testCase = int(input())
for c in range(testCase):
    n, m, d = map(int, input().split())
    ladder_map = []
    for i in range(m):
        ladder_map.append(input())
    current_y = m-1
    current_x = d
    while(current_y >= 0):
        if (current_x < n):
            if (ladder_map[current_y][current_x*2-1] == "+"):
                current_x = current_x+1
        elif (current_x > 0):
            if (ladder_map[current_y][current_x*2-3] == "+"):
                current_x = current_x-1
        current_y = current_y-1
    print(current_x)
