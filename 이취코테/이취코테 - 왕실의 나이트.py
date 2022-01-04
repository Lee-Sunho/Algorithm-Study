position = input()

dx = [-1, 1, -1, 1, 2, 2, -2, -2]
dy = [2, 2, -2, -2, -1, 1, -1, 1]

cnt = 0

for i in range(8):
    x = int(position[1])
    y = ord(position[0]) - ord('a') + 1
    
    x += dx[i]
    y += dy[i]
    
    if 1 <= x <= 8 and 1 <= y <= 8:
        cnt += 1

print(cnt)