#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int test_case;
    int T;

    cin >> T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for (test_case = 1; test_case <= T; ++test_case) {
        int n, k;
        cin >> n >> k;

        int board[n + 1][n + 1];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> board[i][j];
            }
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            int row = 0;
            int col = 0;
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 0) {
                    if (row == k) sum++;
                    row = 0;
                } else
                    row++;
                if (board[j][i] == 0) {
                    if (col == k) sum++;
                    col = 0;
                } else
                    col++;
            }
            if (row == k) sum++;
            if (col == k) sum++;
        }

        cout << "#" << test_case << ' ' << sum << '\n';
    }
    return 0;  // 정상종료시 반드시 0을 리턴해야합니다.
}