import sys
n = int(sys.stdin.readline())
graph = []
for _ in range(n):
    data = list(map(int, sys.stdin.readline().rstrip().split()))
    graph.append(data)

dp = [[0] * 3 for _ in range(n)]
dp[0] = graph[0]

for i in range(1, n):
    dp[i][0] = min(dp[i - 1][1] + graph[i][0], dp[i - 1][2] + graph[i][0])
    dp[i][1] = min(dp[i - 1][0] + graph[i][1], dp[i - 1][2] + graph[i][1])
    dp[i][2] = min(dp[i - 1][0] + graph[i][2], dp[i - 1][1] + graph[i][2])

print(min(dp[n - 1]))    