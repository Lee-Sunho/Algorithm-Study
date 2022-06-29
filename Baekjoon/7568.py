import sys

n = int(sys.stdin.readline())
arr = list()
for i in range(n):
    x, y = map(int, sys.stdin.readline().split())
    arr.append((x, y))

for i in range(n):
    cnt = 1
    for j in range(n):
        if i == j:
            continue
        if(arr[i][0] < arr[j][0] and arr[i][1] < arr[j][1]):
            cnt += 1
    
    print(cnt, end=" ")
