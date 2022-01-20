import sys
from collections import deque
n, k = map(int, input().split())
graph = [list(map(int, sys.stdin.readline().rstrip().split())) for i in range(n)]
s, x_result, y_result = map(int, input().split())

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

cnt = 0
virus = []
for i in range(n):
    for j in range(n):
        if graph[i][j] != 0:
            virus.append((i, j, graph[i][j], cnt))
            
virus.sort(key = lambda x: x[2])

queue = deque(virus)

while queue:
    x, y, num, cnt = queue.popleft()
    
    if cnt == s:
        break
    
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        
        if nx < 0 or nx >= n or ny < 0 or ny >= n:
            continue
        
        if graph[nx][ny] == 0:
            graph[nx][ny] = num
            queue.append((nx, ny, num, cnt + 1))
            
print(graph[x_result - 1][y_result - 1])