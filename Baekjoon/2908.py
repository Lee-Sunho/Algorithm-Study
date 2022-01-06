a, b = map(list,input().split())
a.reverse()
b.reverse()

a = ''.join(a)
b = ''.join(b)

result = max(a,b)
print(result)