n = int(input())
result = []

for i in range(n):
    repeat, data = input().split()
    temp = ""
    for j in range(len(data)):
        temp = temp + data[j] * int(repeat)
    
    result.append(temp)

for i in range(n):
    print(result[i])