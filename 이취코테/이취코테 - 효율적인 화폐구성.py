import sys
n, m = map(int, sys.stdin.readline().rstrip().split())
cost = [int(sys.stdin.readline().rstrip()) for i in range(n)]
cost.sort()

d = [10001] * (m + 1)
d[0] = 0
for i in range(n):
    for j in range(cost[i], m + 1):
        if d[j - cost[i]] != 10001:
            d[j] = min(d[j - cost[i]] + 1, d[j])

if d[m] == 10001:
    print(-1)
else:
    print(d[m])