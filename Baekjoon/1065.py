def func(n):
    num1 = (n // 10 % 10) - (n % 10)
    num2 = (n // 100) - (n // 10 % 10)
    
    return True if num1 == num2 else False

n = int(input())
cnt = 0
for i in range(1, n + 1):
    if i < 100:
        cnt += 1
    else:
        if func(i): cnt += 1

print(cnt)