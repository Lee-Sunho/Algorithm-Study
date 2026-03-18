#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, ret;
int visited[104];
vector<int> adj[104];

int dfs(int start) {
    int cnt = 1;
    visited[start] = 1;

    for (int x : adj[start]) {
        if (visited[x]) continue;
        cnt += dfs(x);
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ret = dfs(1);
    cout << ret - 1;

    return 0;
}