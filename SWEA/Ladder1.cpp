#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int test_case;
    // int T;

    // cin>>T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for (test_case = 1; test_case <= 10; ++test_case) {
        int t, n = 100;
        cin >> t;

        int board[101][101];

        int curY;
        int curX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> board[i][j];
                if (board[i][j] == 2) {
                    curY = i;
                    curX = j;
                }
            }
        }

        while (curY > 0) {
            if (curX - 1 >= 0 && board[curY][curX - 1]) {
                while (curX - 1 >= 0 && board[curY][curX - 1]) curX--;
            } else if (curX + 1 < n && board[curY][curX + 1]) {
                while (curX + 1 < n && board[curY][curX + 1]) curX++;
            }
            curY--;
        }

        cout << "#" << t << ' ' << curX << '\n';
    }
    return 0;  // 정상종료시 반드시 0을 리턴해야합니다.
}