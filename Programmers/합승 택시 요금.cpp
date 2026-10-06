#include <bits/stdc++.h>

using namespace std;

int board[204][204];
int dist[204];
int INF = 987654321;

vector<int> dijkstra(int start, int n) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [cost, v] = pq.top();
        pq.pop();
        if (cost > dist[v]) continue;

        for (int next = 1; next <= n; next++) {
            if (board[v][next] == INF) continue;
            int newCost = cost + board[v][next];
            if (newCost < dist[next]) {
                dist[next] = newCost;
                pq.push({newCost, next});
            }
        }
    }
    return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    fill(dist, dist + 204, INF);
    for (int i = 0; i < 204; i++) fill(board[i], board[i] + 204, INF);

    for (int i = 0; i < fares.size(); i++) {
        board[fares[i][0]][fares[i][1]] = min(board[fares[i][0]][fares[i][1]], fares[i][2]);
        board[fares[i][1]][fares[i][0]] = min(board[fares[i][1]][fares[i][0]], fares[i][2]);
    }

    vector<int> distS = dijkstra(s, n);
    vector<int> distA = dijkstra(a, n);
    vector<int> distB = dijkstra(b, n);

    for (int k = 1; k <= n; k++) {
        if (distS[k] >= INF || distA[k] >= INF || distB[k] >= INF) continue;
        answer = min(answer, distS[k] + distA[k] + distB[k]);
    }

    return answer;
}