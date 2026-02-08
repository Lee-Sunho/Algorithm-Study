#include <bits/stdc++.h>
using namespace std;

int n, target, root, cnt;
vector<int> adj[55];

int dfs(int idx) {
    int cnt_child = 0;
    int ret = 0;

    for (int child : adj[idx]) {
        if (child == target) continue;
        ret += dfs(child);
        cnt_child++;
    }

    if (cnt_child == 0) return 1;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp == -1)
            root = i;
        else
            adj[temp].push_back(i);
    }

    cin >> target;
    if (target != root) {
        cnt = dfs(root);
    }
    cout << cnt << '\n';

    return 0;
}