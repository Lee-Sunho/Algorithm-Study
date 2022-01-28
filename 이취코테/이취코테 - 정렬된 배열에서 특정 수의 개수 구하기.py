import sys
from bisect import bisect_left, bisect_right
n, x = map(int, sys.stdin.readline().rstrip().split())
data = list(map(int, sys.stdin.readline().rstrip().split()))

result = bisect_right(data, x) - bisect_left(data, x)

if result == 0:
    print(-1)
    
else:
    print(result)