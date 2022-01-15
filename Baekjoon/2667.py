import sys
n = int(input())
graph = [list(map(int, sys.stdin.readline().rstrip())) for i in range(n)]
visited = [[False] * n for i in range(n)]
num = 1
result = []
cnt = 0

def dfs(x,y):
    global cnt
    if 0 <= x < n and 0 <= y < n:
        if graph[x][y] != 0 and not visited[x][y]:
             visited[x][y] = True
             cnt += 1
             dfs(x + 1, y)
             dfs(x, y + 1)
             dfs(x - 1, y)
             dfs(x, y - 1)
             return True
        return False
    return False
        

for i in range(n):
    for j in range(n):
        cnt = 0
        if dfs(i, j) == True:
            result.append(cnt)
            

print(len(result))
result.sort()
for i in result:
    print(i)