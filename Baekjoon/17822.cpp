#include <bits/stdc++.h>
using namespace std;

int n, m, t, ret;
int board[101][101];

void check() {
    int temp[101][101];
    bool flag = false;
    memcpy(temp, board, sizeof(board));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (board[i][j] == 0) continue;

            // 같은 원판 내
            int next_j = (j == m) ? 1 : j + 1;
            if (board[i][j] == board[i][next_j]) {
                flag = true;
                temp[i][j] = 0;
                temp[i][next_j] = 0;
            }

            // 다른 원판
            if (i < n && board[i][j] == board[i + 1][j]) {
                flag = true;
                temp[i][j] = 0;
                temp[i + 1][j] = 0;
            }
        }
    }

    if (flag) {
        memcpy(board, temp, sizeof(temp));
    } else {
        double sum = 0;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (board[i][j] != 0) {
                    sum += board[i][j];
                    count++;
                }
            }
        }

        if (count == 0) return;

        double avg = sum / count;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (board[i][j] == 0) continue;
                if (board[i][j] < avg) {
                    board[i][j]++;
                }

                else if (board[i][j] > avg) {
                    board[i][j]--;
                }
            }
        }
    }
}

void rotate_board(int idx, int dir, int k) {
    k %= m;  // k가 m보다 클 경우 대비
    if (k == 0) return;

    if (dir == 0) {  // 시계 방향
        rotate(&board[idx][1], &board[idx][m + 1 - k], &board[idx][m + 1]);
    } else if (dir == 1) {  // 반시계 방향
        rotate(&board[idx][1], &board[idx][1 + k], &board[idx][m + 1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // n, m, t 입력
    cin >> n >> m >> t;

    // n x m 배열에 숫자 저장
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }

    // t번의 회전
    while (t--) {
        int xi, di, ki;
        cin >> xi >> di >> ki;
        // 회전
        for (int i = xi; i <= n; i += xi) {
            rotate_board(i, di, ki);
        }

        // 인접하면서 같은 수 지우기
        // 없는 경우에는 원판에 적힌 수의 평균을 구하고, 평균보다 큰 수에서 1을 빼고, 작은 수에는
        // 1을 더한다.
        check();
    }

    // 원판에 적힌 수의 합 출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ret += board[i][j];
        }
    }
    cout << ret;

    return 0;
}
