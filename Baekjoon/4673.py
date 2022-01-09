def func(n):
    sum = 0
    while(n >= 10):
        sum += n % 10
        n = n // 10
    sum += n
    return sum

n = 1
data = set()
not_self = set()
while n < 10000:
    data.add(n)
    result = n + func(n)
    not_self.add(result)
    n += 1

result = data - not_self


for i in sorted(result):
    print(i)