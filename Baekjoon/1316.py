import sys
num = int(sys.stdin.readline())

cnt = 0
for i in range(num):
    str = sys.stdin.readline().rstrip()
    
    check = 1
    c = str[0]
    for j in range(len(str)):
        if(c != str[j]):
            for k in range(j - 1):
                if(str[k] == str[j]):
                    check = 0
                    break
        c = str[j]
        
    if check == 1:
        cnt = cnt + 1

print(cnt)
