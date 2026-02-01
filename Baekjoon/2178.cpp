#include <bits/stdc++.h>
using namespace std;

int n, m, y, x, arr[104][104], visited[104][104];
queue<pair<int, int>> q;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }

    visited[1][1] = 1;
    q.push({1, 1});

    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny > n || nx < 0 || nx > m) continue;
            if (visited[ny][nx] == 0 && arr[ny][nx]) {
                q.push({ny, nx});
                visited[ny][nx] = visited[y][x] + 1;
            }
        }
    }

    cout << visited[n][m] << '\n';

    return 0;
}