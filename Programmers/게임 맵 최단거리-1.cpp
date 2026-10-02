#include <bits/stdc++.h>
using namespace std;

int visited[104][104];

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;

int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();

    q.push({0, 0});
    visited[0][0] = 1;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] > 0) continue;
            if (maps[ny][nx] == 0) continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }

    return visited[n - 1][m - 1] > 0 ? visited[n - 1][m - 1] : -1;
}