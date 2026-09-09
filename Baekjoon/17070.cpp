#include <bits/stdc++.h>
using namespace std;

int n, ret;
int board[17][17];

// 가로, 대각선, 세로
int dy[] = {0, 1, 1};
int dx[] = {1, 1, 0};

void move(int y, int x, int pos) {
    if (y == n - 1 && x == n - 1) {
        ret++;
        return;
    }
    // 현재 방향 가로인 경우
    if (pos == 0) {
        for (int i = 0; i < 2; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 이동 시 테두리 벽에 닿는 경우
            if (ny >= n || nx >= n) continue;

            // 중간 벽 때문에 이동이 불가능한 경우
            if (board[ny][nx] == 1) continue;
            if (i == 1) {
                if (board[ny - 1][nx] == 1 || board[ny][nx - 1] == 1) continue;
            }

            move(ny, nx, i);
        }
    } else if (pos == 1) {  // 현재 방향 대각인 경우
        for (int i = 0; i < 3; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 이동 시 테두리 벽에 닿는 경우
            if (ny >= n || nx >= n) continue;

            // 중간 벽 때문에 이동이 불가능한 경우
            if (board[ny][nx] == 1) continue;
            if (i == 1) {
                if (board[ny - 1][nx] == 1 || board[ny][nx - 1] == 1) continue;
            }

            move(ny, nx, i);
        }
    } else if (pos == 2) {  // 현재 방향 세로인 경우
        for (int i = 1; i < 3; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 이동 시 테두리 벽에 닿는 경우
            if (ny >= n || nx >= n) continue;

            // 중간 벽 때문에 이동이 불가능한 경우
            if (board[ny][nx] == 1) continue;
            if (i == 1) {
                if (board[ny - 1][nx] == 1 || board[ny][nx - 1] == 1) continue;
            }

            move(ny, nx, i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    move(0, 1, 0);
    cout << ret;

    return 0;
}
