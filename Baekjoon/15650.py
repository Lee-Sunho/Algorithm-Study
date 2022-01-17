n, m = map(int, input().split())
s = []
num = 1
def dfs(s, num):
    if len(s) == m:
        print(' '.join(map(str, s)))
        return
    
    for i in range(num, n + 1):
        if i not in s:
            s.append(i)
            dfs(s, i)
            s.pop()
        
dfs(s, 1)