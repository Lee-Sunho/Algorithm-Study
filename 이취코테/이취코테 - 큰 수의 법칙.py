n, m, k = map(int, input().split())
data = list(map(int, input().split()))
cnt = 0
result = 0

data.sort(reverse=True)
for i in range(m):
    if(cnt != k):
        result += data[0]
        cnt += 1
    else:
        result += data[1]
        cnt = 0
        
print(result)
