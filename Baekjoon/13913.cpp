#include <bits/stdc++.h>
using namespace std;

int n, k, visited[100004], _prev[100004];
queue<int> q;
vector<int> ret;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    if (n == k) {
        cout << 0 << '\n' << n << '\n';
        return 0;
    }

    q.push(n);
    visited[n] = 1;
    memset(_prev, -1, sizeof(_prev));

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int nx : {x - 1, x + 1, x * 2}) {
            if (nx < 0 || nx > 100000) continue;
            if (!visited[nx]) {
                visited[nx] = visited[x] + 1;
                q.push(nx);
                _prev[nx] = x;
            }
        }
    }

    int cur = k;
    ret.push_back(k);
    while (1) {
        if (_prev[cur] == -1) break;
        ret.push_back(_prev[cur]);
        cur = _prev[cur];
    }

    cout << visited[k] - 1 << '\n';

    for (int i = ret.size() - 1; i >= 0; i--) {
        cout << ret[i] << ' ';
    }

    return 0;
}