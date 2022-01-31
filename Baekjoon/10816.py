import sys
n = int(sys.stdin.readline())
have = list(map(int , sys.stdin.readline().rstrip().split()))

m = int(sys.stdin.readline())
want = list(map(int , sys.stdin.readline().rstrip().split()))

count = [0] * 20000001
for i in have:
    count[i + 10000000] += 1
    
for i in want:
    print(count[i + 10000000], end = ' ')