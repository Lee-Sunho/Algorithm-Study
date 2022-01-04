n = int(input())
data = list(input().split())

x = 1
y = 1
for i in data:
    if i == 'L' and y != 1 :
        y -= 1
    elif i == 'R' and y != n:
        y += 1
    elif i == 'U' and x != 1:
        x -= 1
    elif i == 'D' and x != n:
        x += 1
        
print(x, y)