import sys
from collections import Counter
n = int(sys.stdin.readline())
data = []
for i in range(n):
    data.append(int(sys.stdin.readline()))
    
data.sort()
avg = sum(data) / len(data) # 산술 평균
mid = data[(n - 1) // 2] # 중앙값

most_nums = Counter(data).most_common()
print(most_nums) 
        
print(round(avg))  # round 함수로 반올림
print(mid)

if len(most_nums) > 1:  # 최빈값
    if most_nums[0][1] == most_nums[1][1]:
        print(most_nums[1][0])
    else:
        print(most_nums[0][0])
        
else:
    print(most_nums[0][0])
    
print(abs(data[n - 1] - data[0]))