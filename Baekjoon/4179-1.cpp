#include <bits/stdc++.h>
using namespace std;

int r, c, y, x, dist_fire[1004][1004], dist[1004][1004];
string str;
char arr[1004][1004];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

queue<pair<int, int>> q_fire;
queue<pair<int, int>> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dist_fire, -1, sizeof(dist_fire));
    memset(dist, -1, sizeof(dist));

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> str;
        for (int j = 0; j < c; j++) {
            arr[i][j] = str[j];
            if (str[j] == 'J') {
                q.push({i, j});
                dist[i][j] = 0;
            } else if (str[j] == 'F') {
                q_fire.push({i, j});
                dist_fire[i][j] = 0;
            }
        }
    }

    while (q_fire.size()) {
        tie(y, x) = q_fire.front();
        q_fire.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if (dist_fire[ny][nx] > -1) continue;
            if (arr[ny][nx] == '#') continue;
            q_fire.push({ny, nx});
            dist_fire[ny][nx] = dist_fire[y][x] + 1;
        }
    }

    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= r || nx < 0 || nx >= c) {
                cout << dist[y][x] + 1 << '\n';
                return 0;
            }
            if (dist[ny][nx] > -1) continue;
            if (arr[ny][nx] == '#') continue;
            if (dist_fire[ny][nx] == -1 || dist_fire[ny][nx] > dist[y][x] + 1) {
                dist[ny][nx] = dist[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }

    cout << "IMPOSSIBLE" << '\n';

    return 0;
}
