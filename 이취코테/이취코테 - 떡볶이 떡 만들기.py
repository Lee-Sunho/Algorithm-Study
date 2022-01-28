import sys
n, m = map(int, sys.stdin.readline().rstrip().split())
data = list(map(int, sys.stdin.readline().rstrip().split()))

start = 0
end = max(data)
while start <= end:
    sum = 0
    h = (start + end) // 2
    for i in data:
        if i > h:
            sum += (i - h)
            
    if sum == m:
        break
    
    elif sum > m:
        start = h + 1
    
    else:
        end = h - 1

print(h)