#include <iostream>

using namespace std;

int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(int argc, char** argv) {
    int test_case;
    int T;

    cin >> T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for (test_case = 1; test_case <= T; ++test_case) {
        int n, m;
        cin >> n >> m;

        int board[10][10] = {0};  // 0 빈칸, 1 흑돌, 2 백돌
        int mid = n / 2;

        // 1-based
        board[mid][mid] = 2;
        board[mid][mid + 1] = 1;
        board[mid + 1][mid] = 1;
        board[mid + 1][mid + 1] = 2;

        for (int i = 0; i < m; i++) {
            int x, y, c;
            cin >> x >> y >> c;

            board[y][x] = c;
            int opp = 3 - c;

            for (int d = 0; d < 8; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];

                int yy = ny, xx = nx;
                while (yy >= 1 && yy <= n && xx >= 1 && xx <= n && board[yy][xx] == opp) {
                    yy += dy[d];
                    xx += dx[d];
                }

                if (yy >= 1 && yy <= n && xx >= 1 && xx <= n && board[yy][xx] == c) {
                    yy -= dy[d];
                    xx -= dx[d];
                    while (board[yy][xx] == opp) {
                        board[yy][xx] = c;
                        yy -= dy[d];
                        xx -= dx[d];
                    }
                }
            }
        }

        int cnt_1 = 0, cnt_2 = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (board[i][j] == 1)
                    cnt_1++;
                else if (board[i][j] == 2)
                    cnt_2++;
            }
        }

        cout << "#" << test_case << ' ' << cnt_1 << ' ' << cnt_2 << '\n';
    }
    return 0;  // 정상종료시 반드시 0을 리턴해야합니다.
}