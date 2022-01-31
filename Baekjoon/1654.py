import sys
k, n = map(int, sys.stdin.readline().rstrip().split())

data = []
for i in range(k):
    data.append(int(sys.stdin.readline().rstrip()))

start = 1
end = max(data)

while start <= end:
    mid = (start + end) // 2
    cnt = 0
    for x in data:
        cnt += x // mid
    
    if cnt >= n:
        start = mid + 1
        
    else:
        end = mid - 1
        
print(end)