import sys
data = sys.stdin.readline().strip()

cnt = 0
for i in data:
    if i == " ":
       cnt += 1

if len(data) != 0:
    cnt += 1       
print(cnt)