#include <bits/stdc++.h>
using namespace std;

int n, m, arr[104][104], visited[104][104], hour;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> v;

void check(int y, int x) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] == 1) continue;
        if (arr[ny][nx] == 0) {
            check(ny, nx);
        } else if (arr[ny][nx] == 1) {
            v.push_back({ny, nx});
            visited[ny][nx] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    while (1) {
        memset(visited, 0, sizeof(visited));
        v.clear();

        check(0, 0);
        hour++;

        for (auto p : v) {
            arr[p.first][p.second] = 0;
        }

        int flag = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 1) {
                    flag = 0;
                }
            }
        }

        if (flag) {
            cout << hour << '\n';
            cout << v.size() << '\n';
            break;
        }
    }

    return 0;
}