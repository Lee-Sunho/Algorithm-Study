data = list(input())
data.sort()

sum = 0
result = []
for i in data:
    if i.isdigit():
        sum += int(i)
    else:
        result.append(i)

result.append(str(sum))

for i in result:
    print(i, end = "")