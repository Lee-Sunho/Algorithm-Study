import sys
n = int(sys.stdin.readline())
data = []
for i in range(n):
    temp = list(sys.stdin.readline().rstrip().split())
    data.append((temp[0], int(temp[1]), int(temp[2]), int(temp[3])))

data.sort(key = lambda x: (-(int(x[1])), int(x[2]), -(int(x[3])), x[0]))
for i in data:
    print(i[0])