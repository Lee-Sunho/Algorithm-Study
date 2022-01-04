data = input()
left = 0
right = 0

for i in range(len(data)//2):
    left += int(data[i])

for i in range(len(data)//2, len(data)):
    right += int(data[i])
    
if left == right:
    print("LUCKY")

else:
    print("READY")