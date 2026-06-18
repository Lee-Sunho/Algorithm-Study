#include <bits/stdc++.h>

using namespace std;

int adj[104][104], visited[104];
int ret = 1e9;

int dfs(int start, int n) {
    int cnt = 1;

    for (int i = 1; i <= n; i++) {
        if (visited[i] || adj[start][i] == 0) continue;

        visited[i] = 1;
        cnt += dfs(i, n);
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    for (int i = 0; i < wires.size(); i++) {
        adj[wires[i][0]][wires[i][1]] = 1;
        adj[wires[i][1]][wires[i][0]] = 1;
    }

    for (int i = 0; i < wires.size(); i++) {
        memset(visited, 0, sizeof(visited));
        int cnt = 0;
        int cnt_other = 0;

        adj[wires[i][0]][wires[i][1]] = 0;
        adj[wires[i][1]][wires[i][0]] = 0;

        visited[1] = 1;
        cnt = dfs(1, n);
        cnt_other = n - cnt;
        ret = min(ret, abs(cnt - cnt_other));

        adj[wires[i][0]][wires[i][1]] = 1;
        adj[wires[i][1]][wires[i][0]] = 1;
    }

    return ret;
}