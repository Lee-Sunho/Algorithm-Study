n = int(input())
key = "666"

cnt = 1
num = 666
while(cnt < n):
    num += 1
    if str(num).find(key) != -1:
        cnt += 1

print(num)
