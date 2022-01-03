n, m = map(int, input().split())
data = [list(map(int, input().split())) for i in range(n)]

min_values = [min(data[i]) for i in range(n)]
result = max(min_values)
print(result)
