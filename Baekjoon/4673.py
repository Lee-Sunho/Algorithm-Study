def func(n):
    sum = 0
    while(n >= 10):
        sum += n % 10
        n = n // 10
    sum += n
    return sum

data = set()
not_self = set()
for n in range(1, 10001):
    data.add(n)
    result = n + func(n)
    not_self.add(result)

result = data - not_self

for i in sorted(result):
    print(i)