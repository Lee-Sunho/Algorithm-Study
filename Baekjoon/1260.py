from collections import deque

n, m, v = map(int, input().split())
graph = [[9999] * (n + 1) for i in range(n + 1)]
visited_dfs = [0] * (n + 1)
visited_bfs = [0] * (n + 1)

for i in range(m):
    a, b = map(int, input().split())
    graph[a][b] = 1
    graph[b][a] = 1
    
def dfs(v):
    visited_dfs[v] = 1
    print(v, end = ' ')
    for i in range(1, n + 1):
        if graph[v][i] == 1 and not visited_dfs[i]:
            dfs(i)
            
def bfs(v):
    visited_bfs[v] = 1
    queue = deque([v])
    
    while queue:
        node = queue.popleft()
        print(node, end = ' ')
        for i in range(1, n + 1):
            if graph[node][i] == 1 and not visited_bfs[i]:
                queue.append(i)
                visited_bfs[i] = 1
                   
dfs(v)
print()
bfs(v)