from functools import cmp_to_key
import sys

n = int(sys.stdin.readline())

arr = list()
for i in range(n):
    x, y = map(int, sys.stdin.readline().split())
    arr.append((x, y))

arr.sort(key=lambda x:(x[1], x[0]))

cnt = 0
t_end = 0
for x in arr:
    if(t_end <= x[0]):
        cnt += 1
        t_end = x[1]

print(cnt)
