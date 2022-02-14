import sys
from bisect import bisect_left
n = int(sys.stdin.readline())
data = list(map(int, sys.stdin.readline().rstrip().split()))

dp = [data[0]]
for i in range(1, n):
    if data[i] > dp[-1]:
        dp.append(data[i])

    else:
        idx = bisect_left(dp, data[i])
        dp[idx] = data[i] # 수열이 유지되는 위치의 원소와 교환

print(len(dp))