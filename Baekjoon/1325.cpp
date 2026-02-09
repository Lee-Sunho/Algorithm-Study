#include <bits/stdc++.h>
using namespace std;

int n, m, visited[10004], max_cnt;
vector<int> adj[10004];
vector<int> ret;

int check(int idx) {
    int ret = 1;
    visited[idx] = 1;
    if (adj[idx].size()) {
        for (int v : adj[idx]) {
            if (visited[v] == 0) ret += check(v);
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        int cnt = check(i);
        // cout << i << " : " << cnt << '\n';
        if (cnt > max_cnt) {
            ret.clear();
            ret.push_back(i);
            max_cnt = cnt;
        } else if (cnt == max_cnt) {
            ret.push_back(i);
        }
    }

    for (int num : ret) {
        cout << num << ' ';
    }

    return 0;
}