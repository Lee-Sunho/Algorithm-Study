#include <bits/stdc++.h>

using namespace std;

int board[108][108];
queue<pair<int, int>> q;
int dist[108][108];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    for (auto rec : rectangle) {
        int sx = rec[0] * 2;
        int sy = rec[1] * 2;
        int ex = rec[2] * 2;
        int ey = rec[3] * 2;

        for (int y = sy; y <= ey; y++) {
            for (int x = sx; x <= ex; x++) {
                board[y][x] = 1;
            }
        }
    }

    for (auto rec : rectangle) {
        int sx = rec[0] * 2;
        int sy = rec[1] * 2;
        int ex = rec[2] * 2;
        int ey = rec[3] * 2;

        for (int y = sy + 1; y < ey; y++) {
            for (int x = sx + 1; x < ex; x++) {
                board[y][x] = 0;
            }
        }
    }

    memset(dist, -1, sizeof(dist));
    q.push({characterY * 2, characterX * 2});
    dist[characterY * 2][characterX * 2] = 0;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= 108 || nx < 0 || nx >= 108 || dist[ny][nx] != -1) continue;
            if (board[ny][nx] != 1) continue;

            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});
        }
    }

    return dist[itemY * 2][itemX * 2] / 2;
}