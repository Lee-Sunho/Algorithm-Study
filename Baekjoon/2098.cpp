#include <bits/stdc++.h>
using namespace std;

int n, INF = 987654321;
int adj[17][17], dp[17][1 << 16];

int tsp(int here, int visited) {
    // 만약 모든 도시 다 방문 했다면?
    if (visited == (1 << n) - 1) {
        return adj[here][0] ? adj[here][0] : INF;
    }
    // 메모이제이션 확인
    if (dp[here][visited] != -1) return dp[here][visited];

    dp[here][visited] = INF;
    for (int i = 0; i < n; i++) {
        // i번째 도시 방문했는지 확인
        if (visited & (1 << i)) continue;
        // 현재 도시에서 i번째 도시 경로 있는지 확인
        if (adj[here][i] == 0) continue;
        // 현재 위치에서 남은 도시 다 도는데 걸리는 최솟값 갱신
        dp[here][visited] = min(dp[here][visited], tsp(i, visited | (1 << i)) + adj[here][i]);
    }
    return dp[here][visited];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << tsp(0, 1);

    return 0;
}
