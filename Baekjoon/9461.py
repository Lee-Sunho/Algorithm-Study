t = int(input())
dp = [1] * 101
for _ in range(t):
    n = int(input())
    for i in range(1, n - 2):
        dp[i + 3] = dp[i] + dp[i + 1]

    print(dp[n])