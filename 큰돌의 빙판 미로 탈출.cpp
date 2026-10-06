#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int n, m;
char board[104][104];
pair<int, int> start;
pair<int, int> ending;
int ans = 1e9;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
string dirName = "URDL";

queue<pair<int, int>> q;
int dist[104][104];
pair<int, int> parent[104][104];
string cmd[104][104];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dist, -1, sizeof(dist));

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];

            if (board[i][j] == 'S') start = {i, j};
            if (board[i][j] == 'E') ending = {i, j};
        }
    }

    q.push({start.first, start.second});
    dist[start.first][start.second] = 0;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if (board[y][x] == 'E') break;

        for (int i = 0; i < 4; i++) {
            // 일반 이동과 슬라이드 구분
            for (int slide = 0; slide < 2; slide++) {
                int cy = y;
                int cx = x;
                bool isArrived = false;
                int cnt = 0;

                while (1) {
                    int ny = cy + dy[i];
                    int nx = cx + dx[i];

                    if (ny < 0 || ny >= n || nx < 0 || nx >= m || board[ny][nx] == '#') break;
                    cy = ny;
                    cx = nx;
                    cnt++;

                    if (board[cy][cx] == 'E') break;
                    if (!slide) break;  // 일반 이동은 1칸만
                }

                if (cnt == 0) continue;
                if (dist[cy][cx] != -1) continue;

                dist[cy][cx] = dist[y][x] + 1;
                parent[cy][cx] = {y, x};
                cmd[cy][cx] = string(slide ? "K" : "") + dirName[i];
                q.push({cy, cx});
            }
        }
    }

    if (dist[ending.first][ending.second] == -1)
        cout << -1;
    else {
        cout << dist[ending.first][ending.second] << '\n';
        vector<string> path;

        int y = ending.first;
        int x = ending.second;

        while (!(y == start.first && x == start.second)) {
            path.push_back(cmd[y][x]);
            auto p = parent[y][x];
            y = p.first;
            x = p.second;
        }
        reverse(path.begin(), path.end());
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << ' ';
        }
    }

    return 0;
}
