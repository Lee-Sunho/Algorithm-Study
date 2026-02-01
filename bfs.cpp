#include <bits/stdc++.h>
using namespace std;

int n, m, sy, sx, ey, ex, y, x;
int arr[104][104], visited[104][104];
queue<pair<int, int>> q;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void bfs(int sy, int sx) {
    visited[sy][sx] = 1;
    q.push({sy, sx});

    while (q.size()) {
        tie(y, x) = q.front();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (arr[ny][nx] && visited[ny][nx] == 0) {
                q.push({ny, nx});
                visited[ny][nx] = visited[y][x] + 1;
            }
        }
        q.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cin >> sy >> sx;
    cin >> ey >> ex;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    bfs(sy, sx);

    cout << visited[ey][ex] << '\n';

    // 디버깅
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}