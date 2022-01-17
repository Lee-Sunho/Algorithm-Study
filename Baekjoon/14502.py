import sys
n, m = map(int, input().split())
graph = [list(map(int, sys.stdin.readline().rstrip().split())) for i in range(n)]
temp = [[0] * m for i in range(n)]
cnt = 0
result = 0

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def virus(x, y):
    if temp[x][y] == 2:
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            
            if temp[nx][ny] == 0:
                temp[nx][ny] = 2
                virus(nx, ny)            
                

def dfs(cnt):
    num = 0
    global result
    if cnt == 3:
        for i in range(n):
            for j in range(m):
                temp[i][j] = graph[i][j]
        
        for i in range(n):
            for j in range(m):
                virus(i, j)
                
        for i in range(n):
            for j in range(m):
                if temp[i][j] == 0:
                    num += 1
        result = max(result, num)
        return
        
    for i in range(n):
        for j in range(m):
            if graph[i][j] == 0:
                graph[i][j] = 1
                cnt += 1
                dfs(cnt)
                graph[i][j] = 0
                cnt -= 1
                            
    
dfs(cnt)
print(result)