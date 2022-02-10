n = int(input())
data = []
data.append((0, 0))
for i in range(n):
    time, benefit = map(int, input().rstrip().split())
    data.append((time, benefit))

dp = [0] * (n + 1)
for i in range(n, 0, -1):
    if i == n and data[i][0] == 1:
        dp[i] = data[i][1]

    if i + data[i][0] <= n:
        dp[i] = dp[i + data[i][0]] + data[i][1]

    else:
        dp[i] = data[i][1]

print(max(dp))