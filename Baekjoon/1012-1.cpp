#include <bits/stdc++.h>
using namespace std;

int t, n, m, k, arr[54][54], visited[54][54], x, y;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx > m) continue;
        if (visited[ny][nx] == 0 && arr[ny][nx]) {
            dfs(ny, nx);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        int cnt = 0;

        cin >> m >> n >> k;
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            arr[y][x] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] == 0 && arr[i][j]) {
                    cnt++;
                    dfs(i, j);
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}