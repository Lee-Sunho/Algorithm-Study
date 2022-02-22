import sys
input = sys.stdin.readline
INF = int(1e9) # 무한을 의미하는 값으로 10억을 설정

n, m = map(int, input().split())    # 노드의 개수, 간선의 개수 입력
graph = [[INF] * (n + 1) for _ in range(n + 1)] # 2차원 리스트(그래프 표현)를 만들고, 무한으로 초기화

# 자기 자신에서 자기 자신으로 가는 비용은 0으로 초기화
for a in range(1, n + 1):
    for b in range(1, n + 1):
        if a == b:
            graph[a][b] = 0

for _ in range(m): # 간선 정보 입력
    a, b, c = map(int, input().split())     # a번 노드에서 b번 노드로 가는 비용 c
    graph[a][b] = c

# 점화식에 따라 플로이드 워셜 알고리즘을 수행
# 점화식: Dab = min(Dab, Dak + Dkb)
for k in range(1, n + 1):
    for a in range(1, n + 1):
        for b in range(1, n + 1):
            graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])

for a in range(1, n + 1):
    for b in range(1, n + 1):
        if graph[a][b] == INF:
            print("INFINITY", end = " ")
        else:
            print(graph[a][b], end = " ")
    print()