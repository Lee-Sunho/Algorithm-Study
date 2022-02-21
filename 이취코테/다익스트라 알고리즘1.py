import sys
input = sys.stdin.readline
INF = int(1e9) # 무한을 의미하는 값으로 10억을 설정

n, m = map(int, input().split())    # 노드의 개수, 간선의 개수 입력
start = int(input())    # 시작 노드 입력
graph = [[] for i in range(n + 1)]  # 노드 연결 정보를 담는 리스트
visited = [False] * (n + 1)     # 방문한 적이 있는지 체크하는 리스트
distance = [INF] * (n + 1)  # 최단 거리 테이블을 모두 무한으로 초기화

for _ in range(m): # 간선 정보 입력
    a, b, c = map(int, input().split())     # a번 노드에서 b번 노드로 가는 비용 c
    graph[a].append((b, c))


def get_smallest_node():    # 방문하지 않은 노드 중, 가장 최단 거리가 짧은 노드의 번호를 반환
    min_value = INF
    index = 0
    for i in range(1, n + 1):
        if distance[i] < min_value and not visited[i]:
            min_value = distance[i]
            index = i
    return index

def dijkstra(start):
    distance[start] = 0 # 시작 노드 초기화
    visited[start] = True
    for j in graph[start]:
        distance[j[0]] = j[1]

    for i in range(n - 1):  # 시작 노드 제외한 나머지 노드에 대해 반복
        now = get_smallest_node()
        visited[now] = True
        for j in graph[now]:
            cost = distance[now] + j[1]
            # 현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
            if cost < distance[j[0]]:
                distance[j[0]] = cost

dijkstra(start)
for i in range(1, n + 1):
    if distance[i] == INF:
        print("INFINITY")
    else:
        print(distance[i])