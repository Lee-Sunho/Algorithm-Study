a = int(input())

for i in range(a):
    num, str = input().split()
    for x in str:
        print(int(num)*x, end='')
    print()