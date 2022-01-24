import sys
n = int(input())
array = list(map(int, sys.stdin.readline().rstrip().split()))
array.sort()
print(array[(n - 1) // 2]) # 홀수인경우 중앙값, 짝수인경우 중앙값 2개 중 작은 값