#include <bits/stdc++.h>
using namespace std;

int n, m, sx, sy, ex, ey, dist[304][304], y, x, flag;
char arr[304][304];
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

queue<pair<int, int>> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cin >> sx >> sy >> ex >> ey;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    q.push({sx, sy});
    dist[sx][sy] = 1;

    while (1) {
        queue<pair<int, int>> next_q;
        while (q.size()) {
            tie(x, y) = q.front();
            q.pop();

            if (y == ey && x == ex) {
                flag = 1;
                break;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 1 || nx > n || ny < 1 || ny > m || dist[nx][ny]) continue;
                if (arr[nx][ny] == '0') {
                    q.push({nx, ny});
                    dist[nx][ny] = dist[x][y];
                } else if (arr[nx][ny] == '1' || arr[nx][ny] == '#') {
                    arr[nx][ny] = 0;
                    next_q.push({nx, ny});
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
        q = next_q;
        if (flag) break;
    }

    cout << dist[ex][ey] - 1 << '\n';

    return 0;
}