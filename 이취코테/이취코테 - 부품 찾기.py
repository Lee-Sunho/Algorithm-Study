import sys
n = int(sys.stdin.readline())
store = list(map(int, sys.stdin.readline().rstrip().split()))
store.sort()

m = int(sys.stdin.readline())
need = list(map(int, sys.stdin.readline().rstrip().split()))

i = 0
for x in need:
    check = False
    start = 0
    end = n - 1
    while start <= end:
        mid = (start + end) // 2
        if store[mid] == x:
            check = True
            break
        elif store[mid] < x:
            start = mid + 1
        else:
            end = mid - 1
    
    if check == True:
        need[i] = 'yes'
    else:
        need[i] = 'no'
    i += 1

print(' '.join(need))