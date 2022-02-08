import sys
n = int(sys.stdin.readline())
dp = []
for i in range(n):
    dp.append(list(map(int, sys.stdin.readline().rstrip().split())))

for i in range(1, n):
    for j in range(i + 1):
        if j == 0:
            dp[i][j] = dp[i][j] + dp[i - 1][j]
        
        elif j == i:
            dp[i][j] = dp[i][j] + dp[i - 1][j - 1]

        else:
            dp[i][j] = dp[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1])

print(max(dp[n - 1]))