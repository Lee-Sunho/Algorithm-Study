#include <bits/stdc++.h>
using namespace std;

int n, m, ret = 1e9;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int board[10][10];
vector<pair<int, int>> cctv;

vector<pair<int, int>> extend(int cur, int dir) {
    vector<pair<int, int>> changed;
    int y = cctv[cur].first;
    int x = cctv[cur].second;

    if (board[y][x] == 1) {
        int temp_y = y;
        int temp_x = x;
        while (1) {
            int ny = temp_y + dy[dir];
            int nx = temp_x + dx[dir];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m || board[ny][nx] == 6) {
                break;
            }
            if (board[ny][nx] == 0) {
                board[ny][nx] = 7;
                changed.push_back({ny, nx});
            }
            temp_y = ny;
            temp_x = nx;
        }
    } else if (board[y][x] == 2) {
        for (int i = 0; i <= 2; i += 2) {
            int temp_y = y;
            int temp_x = x;
            while (1) {
                int ny = temp_y + dy[(dir + i) % 4];
                int nx = temp_x + dx[(dir + i) % 4];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m || board[ny][nx] == 6) {
                    break;
                }
                if (board[ny][nx] == 0) {
                    board[ny][nx] = 7;
                    changed.push_back({ny, nx});
                }
                temp_y = ny;
                temp_x = nx;
            }
        }
    } else if (board[y][x] == 3) {
        for (int i = 0; i < 2; i++) {
            int temp_y = y;
            int temp_x = x;
            while (1) {
                int ny = temp_y + dy[(dir + i) % 4];
                int nx = temp_x + dx[(dir + i) % 4];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m || board[ny][nx] == 6) {
                    break;
                }
                if (board[ny][nx] == 0) {
                    board[ny][nx] = 7;
                    changed.push_back({ny, nx});
                }
                temp_y = ny;
                temp_x = nx;
            }
        }
    } else if (board[y][x] == 4) {
        for (int i = 0; i < 3; i++) {
            int temp_y = y;
            int temp_x = x;
            while (1) {
                int ny = temp_y + dy[(dir + i) % 4];
                int nx = temp_x + dx[(dir + i) % 4];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m || board[ny][nx] == 6) {
                    break;
                }
                if (board[ny][nx] == 0) {
                    board[ny][nx] = 7;
                    changed.push_back({ny, nx});
                }
                temp_y = ny;
                temp_x = nx;
            }
        }
    } else if (board[y][x] == 5) {
        for (int i = 0; i < 4; i++) {
            int temp_y = y;
            int temp_x = x;
            while (1) {
                int ny = temp_y + dy[(dir + i) % 4];
                int nx = temp_x + dx[(dir + i) % 4];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m || board[ny][nx] == 6) {
                    break;
                }
                if (board[ny][nx] == 0) {
                    board[ny][nx] = 7;
                    changed.push_back({ny, nx});
                }
                temp_y = ny;
                temp_x = nx;
            }
        }
    }
    return changed;
}

void func(int cur) {
    if (cur == cctv.size()) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 0) cnt++;
            }
        }
        ret = min(ret, cnt);
        return;
    }

    for (int k = 0; k < 4; k++) {
        vector<pair<int, int>> extended = extend(cur, k);
        func(cur + 1);
        for (auto it : extended) {
            board[it.first][it.second] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];

            if (board[i][j] != 0 && board[i][j] != 6) {
                cctv.push_back({i, j});
            }
        }
    }

    func(0);

    cout << ret;
    return 0;
}
