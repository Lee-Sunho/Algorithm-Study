data = input()
data = data.upper()
count = [0] * 26

for i in data:
    index = ord(i) - ord('A')
    count[index] += 1

max = 0    
for i in range(len(count)):
    if max < count[i]:
        max = count[i]
        max_alpha = i
        
result = chr(ord('A') + max_alpha)
count.sort(reverse=True)
if count[0] == count[1]:
    print("?")
else:
    print(result)