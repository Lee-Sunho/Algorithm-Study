from collections import deque
import sys
n, m, k, x = map(int,input().split())
graph = [[] for i in range(n + 1)]
distance = [-1] * (n + 1)
check = False

def bfs(x):
    queue = deque([x])
    distance[x] = 0
    while queue:
        v = queue.popleft()
        for i in graph[v]:
            if distance[i] == -1:
                distance[i] = distance[v] + 1
                queue.append(i)
        

for i in range(m):
    a, b = map(int, sys.stdin.readline().rstrip().split())
    graph[a].append(b)
    
bfs(x)
for i in range(1, n + 1):
    if distance[i] == k:
        print(i)
        check = True
    
if not check:
    print(-1)