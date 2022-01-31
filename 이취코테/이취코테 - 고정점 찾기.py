import sys
n = int(sys.stdin.readline())
data = list(map(int, sys.stdin.readline().rstrip().split()))

start = 0
end = n - 1
check = False
while start <= end:
    mid = (start + end) // 2
    if data[mid] == mid:
        check = True
        break
    
    elif data[mid] > mid:
        end = mid - 1
    
    else:
        start = mid + 1
        
if check == True:
    print(mid)
    
else:
    print(-1)