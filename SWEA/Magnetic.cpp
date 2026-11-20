#include <cstring>
#include <iostream>

using namespace std;

// 0 빈칸, 1 빨강 (아래로 이동), 2 파랑 (위로 이동)
int board[101][101];

int main(int argc, char** argv) {
    int test_case;
    int T = 10;

    for (test_case = 1; test_case <= T; ++test_case) {
        memset(board, 0, sizeof(board));
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> board[i][j];
            }
        }

        // 교착 상태 개수 카운트 (위부터 빨강 > 파랑 이순으로 맞닿아있는 개수)
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 1) {
                    int ny = i + 1;
                    while (ny < n) {
                        if (board[ny][j] == 1)
                            break;
                        else if (board[ny][j] == 2) {
                            ans++;
                            break;
                        }
                        ny++;
                    }
                }
            }
        }

        cout << "#" << test_case << ' ' << ans << '\n';
    }
    return 0;  // 정상종료시 반드시 0을 리턴해야합니다.
}
