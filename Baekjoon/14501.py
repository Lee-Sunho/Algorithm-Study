n = int(input())
data = []

for i in range(n):
    time, benefit = map(int, input().rstrip().split())
    data.append((time, benefit))

dp = [0] * (n + 1)
max_value = 0
for i in range(n - 1, -1, -1):
    if i + data[i][0] <= n:
        dp[i] = max(dp[i + data[i][0]] + data[i][1], max_value)
        max_value = dp[i]

    else:
        dp[i] = max_value

print(max_value)