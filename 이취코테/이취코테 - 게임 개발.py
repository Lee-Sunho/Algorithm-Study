n, m = map(int, input().split())
x, y, direction = map(int, input().split())
map = [list(map(int, input().split())) for i in range(n)]
d = [[0] * m for i in range(n)]

d[x][y] = 1
cnt = 1
steps = [(-1, 0), (0, 1), (1, 0), (0, -1)]
while True:
    check = 0
    for i in range(4):
        if direction == 0:
            direction = 3
        else:
            direction = direction - 1

        step = steps[direction]
        next_x = x + step[0]
        next_y = y + step[1]
    
        if map[next_x][next_y] == 0 and d[next_x][next_y] == 0:
            x = next_x
            y = next_y
            d[x][y] = 1
            cnt += 1
            check = 1
            break
    
    if check == 0:
        next_x = x - step[0]
        next_y = y - step[1]
        
        if d[next_x][next_y] == 0:
            x = next_x
            y = next_y
        else:
            break
        
print(cnt)