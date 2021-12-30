n , k = map(int, input().split())
array = list()
num = 0
for i in range(n):
    array.append(int(input()))

for i in reversed(array):
    coin = i
    num += k // coin
    k %= coin

print(num)
