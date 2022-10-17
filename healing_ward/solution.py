tc = int(input())
for _ in range(tc):
    safe_zone_size, time = map(int, input().split())
    safe_zone = []
    for i in range(safe_zone_size):
        safe_zone.append([0]*safe_zone_size)
    
    dead_body_count, ward_count = map(int, input().split())
    for c in range(dead_body_count):
        dead_body_row, dead_body_col = map(int, input().split())
        for i in range(0, safe_zone_size):
            for j in range(0, safe_zone_size):
                if (max(abs(i-dead_body_row), abs(j-dead_body_col))-time-1) < 0:
                    safe_zone[i][j] += max(abs(i-dead_body_row), abs(j-dead_body_col))-time-1
        safe_zone[dead_body_row][dead_body_col] += 1
    
    for c in range(ward_count):
        ward_row, ward_col = map(int, input().split())
        for i in range(0, safe_zone_size):
            for j in range(0, safe_zone_size):
                if (abs(i-ward_row)+abs(j-ward_col) <= time):
                    if (time - (abs(i-ward_row) + abs(j-ward_col)) + 1) > 0:
                        safe_zone[i][j] += time - (abs(i-ward_row) + abs(j-ward_col)) + 1
        safe_zone[ward_row][ward_col] -= 1
    
    for i in range(safe_zone_size):
        for j in range(safe_zone_size):
            print(safe_zone[i][j], end= " ")
        print()