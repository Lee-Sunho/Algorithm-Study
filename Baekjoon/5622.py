data = input()
array = ['ABC', 'DEF', 'GHI', 'JKL', 'MNO', 'PQRS', 'TUV', 'WXYZ']
sum = 0
for i in data:
    for j in array:
        if i in j:
            sum += array.index(j) + 3
            break
print(sum)