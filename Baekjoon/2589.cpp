#include <bits/stdc++.h>
using namespace std;

int n, m, visited[54][54], y, x, ret_dist;
string str;
char arr[54][54];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void bfs(int sy, int sx) {
    queue<pair<int, int>> q;
    visited[sy][sx] = 0;
    q.push({sy, sx});

    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (visited[ny][nx] == -1 && arr[ny][nx] == 'L') {
                q.push({ny, nx});
                visited[ny][nx] = visited[y][x] + 1;
                ret_dist = max(ret_dist, visited[ny][nx]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < m; j++) {
            arr[i][j] = str[j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            memset(visited, -1, sizeof(visited));
            if (arr[i][j] == 'L') {
                bfs(i, j);
            }
        }
    }

    cout << ret_dist << '\n';

    return 0;
}
