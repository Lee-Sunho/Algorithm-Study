import sys
n, c = map(int, sys.stdin.readline().rstrip().split())
data = []
for i in range(n):
    data.append(int(sys.stdin.readline()))

data.sort()
start = 1
end = data[-1] - data[0]

while start <= end:
    count = 1
    mid = (start + end) // 2
    value = data[0]
    for i in range(1, n):
        if data[i] >= value + mid:
            value = data[i]
            count += 1

    if count >= c:
        result = mid
        start = mid + 1

    else:
        end = mid - 1

print(result)