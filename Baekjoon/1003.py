import sys
n = int(sys.stdin.readline())

for i in range(n):
    num = int(sys.stdin.readline())
    cnt0 = 1
    cnt1 = 0

    for j in range(num):
        cnt0, cnt1 = cnt1, (cnt0 + cnt1)

    print(cnt0, cnt1)