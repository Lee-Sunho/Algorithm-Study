n = int(input())
data = []

for i in range(n):
    time, benefit = map(int, input().rstrip().split())
    data.append((time, benefit))

max_value = 0
dp = [0] * n
for i in range(n):
    if data[i][0] + i > n:
        continue
    dp[i] = data[i][1]

    for j in range(i):
        if data[j][0] + j > i:
            continue
        dp[i] = max(dp[i], data[i][1] + dp[j])

    max_value = max(max_value, dp[i])

print(max_value)