#include <bits/stdc++.h>
using namespace std;

int n, arr[104][104], visited[104][104], max_cnt, max_h;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int y, int x, int h) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if (visited[ny][nx] == 0 && arr[ny][nx] > h) {
            dfs(ny, nx, h);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] > max_h) {
                max_h = arr[i][j];
            }
        }
    }

    for (int h = 0; h < max_h; h++) {
        int cnt = 0;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 0 && arr[i][j] > h) {
                    dfs(i, j, h);
                    cnt++;
                }
            }
        }
        if (cnt > max_cnt) {
            max_cnt = cnt;
        }
    }

    cout << max_cnt << '\n';
    return 0;
}