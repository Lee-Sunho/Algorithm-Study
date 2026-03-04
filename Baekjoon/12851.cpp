#include <bits/stdc++.h>
using namespace std;

int n, k, visited[100004], ways[100004];
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    if (n == k) {
        cout << 0 << '\n' << 1 << '\n';
        return 0;
    }

    q.push(n);
    visited[n] = 1;
    ways[n] = 1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int nx : {x - 1, x + 1, 2 * x}) {
            if (nx < 0 || nx > 100000) continue;
            if (visited[nx] == 0) {
                visited[nx] = visited[x] + 1;
                ways[nx] += ways[x];
                q.push(nx);
            } else if (visited[nx] == visited[x] + 1) {
                ways[nx] += ways[x];
            }
        }
    }

    cout << visited[k] - 1 << '\n' << ways[k] << '\n';

    return 0;
}