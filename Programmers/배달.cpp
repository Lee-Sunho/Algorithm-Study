#include <bits/stdc++.h>
using namespace std;

int board[54][54];
int INF = 987654321;
int dist[54];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    fill(dist, dist + 54, INF);
    for (int i = 0; i < 54; i++) fill(board[i], board[i] + 54, INF);

    for (int i = 0; i < road.size(); i++) {
        board[road[i][0]][road[i][1]] = min(board[road[i][0]][road[i][1]], road[i][2]);
        board[road[i][1]][road[i][0]] = min(board[road[i][0]][road[i][1]], road[i][2]);
    }

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (cost > dist[v]) continue;
        for (int next = 1; next <= N; next++) {
            if (board[v][next] == INF) continue;
            int newCost = cost + board[v][next];

            if (newCost < dist[next]) {
                dist[next] = newCost;
                pq.push({newCost, next});
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (dist[i] <= K) answer++;
    }

    return answer;
}