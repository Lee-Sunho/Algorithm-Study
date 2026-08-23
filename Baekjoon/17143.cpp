#include <bits/stdc++.h>
using namespace std;

int n, m, num, ret;
vector<vector<int>> shark;
int board[104][104];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void fishing(int idx) {
    for (int i = 1; i <= n; i++) {
        if (board[i][idx] > 0) {
            ret += shark[board[i][idx] - 1][2];  // 상어의 크기
            board[i][idx] = 0;
            return;
        }
    }
}

void moving() {
    int temp[104][104];
    memset(temp, 0, sizeof(temp));

    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            if (board[y][x] > 0) {
                int idx = board[y][x] - 1;
                int dir = shark[idx][1] - 1;  // 상어 방향
                int speed = shark[idx][0];

                int ny = y;
                int nx = x;
                for (int i = 0; i < speed; i++) {
                    ny += dy[dir];
                    nx += dx[dir];

                    if (ny < 1 || ny > n || nx < 1 || nx > m) {
                        ny -= dy[dir];
                        nx -= dx[dir];
                        dir ^= 1;  // 비트 토클
                        ny += dy[dir];
                        nx += dx[dir];
                    }
                }
                shark[idx][1] = dir + 1;

                // 이미 이동한 칸에 상어가 있는 경우
                if (temp[ny][nx] > 0) {
                    if (shark[idx][2] > shark[temp[ny][nx] - 1][2]) temp[ny][nx] = idx + 1;
                } else {
                    temp[ny][nx] = idx + 1;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            board[i][j] = temp[i][j];
        }
    }
}

int solution() {
    for (int i = 1; i <= m; i++) {
        fishing(i);
        moving();
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> num;

    if (!num) {
        cout << 0;
        return 0;
    }

    for (int i = 1; i <= num; i++) {
        vector<int> v;
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;

        board[r][c] = i;

        v.push_back(s);
        v.push_back(d);
        v.push_back(z);
        shark.push_back(v);
    }

    cout << solution();

    return 0;
}
