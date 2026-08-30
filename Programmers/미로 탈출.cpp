#include <bits/stdc++.h>

using namespace std;

queue<pair<int, int>> q1;
queue<pair<int, int>> q2;
int visited[101][101];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
bool flag = false;
int ret;

int solution(vector<string> maps) {
    pair<int, int> start;
    pair<int, int> labber;
    pair<int, int> exit;
    int n = maps.size();
    int m = maps[0].size();

    // S 위치, L 위치, E 위치 찾아서 저장
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maps[i][j] == 'S') {
                start.first = i;
                start.second = j;
            } else if (maps[i][j] == 'L') {
                labber.first = i;
                labber.second = j;
            } else if (maps[i][j] == 'E') {
                exit.first = i;
                exit.second = j;
            }
        }
    }

    // S 좌표부터 bfs 돌려서 L까지의 최단거리 구하고
    q1.push({start.first, start.second});
    visited[start.first][start.second] = 1;
    while (!q1.empty()) {
        int y = q1.front().first;
        int x = q1.front().second;

        if (y == labber.first && x == labber.second) {
            flag = true;
            ret += visited[labber.first][labber.second] - 1;
            break;
        }

        q1.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m || maps[ny][nx] == 'X') continue;

            if (!visited[ny][nx]) {
                visited[ny][nx] = visited[y][x] + 1;
                q1.push({ny, nx});
            }
        }
    }

    // L부터 E까지의 최단거리 구해서 더함
    if (flag) {
        memset(visited, 0, sizeof(visited));
        q2.push({labber.first, labber.second});
        visited[labber.first][labber.second] = 1;
        while (!q2.empty()) {
            int y = q2.front().first;
            int x = q2.front().second;

            if (y == exit.first && x == exit.second) {
                ret += visited[exit.first][exit.second] - 1;
                break;
            }

            q2.pop();
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m || maps[ny][nx] == 'X') continue;

                if (!visited[ny][nx]) {
                    visited[ny][nx] = visited[y][x] + 1;
                    q2.push({ny, nx});
                }
            }
        }
    }

    if (visited[labber.first][labber.second] && visited[exit.first][exit.second]) {
        return ret;
    }
    return -1;
}