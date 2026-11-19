#include <iostream>
#include <vector>

using namespace std;

int check(vector<vector<int>>& v, int y, int x, int m) {
    int ret = 0;
    for (int i = y; i < y + m; i++) {
        for (int j = x; j < x + m; j++) {
            ret += v[i][j];
        }
    }
    return ret;
}

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

        vector<vector<int>> board(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> board[i][j];
            }
        }

        int k = n - m + 1;
        int ret = -1e9;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                ret = max(ret, check(board, i, j, m));
            }
        }
        cout << "#" << test_case << ' ' << ret << '\n';
    }
    return 0;  // 정상종료시 반드시 0을 리턴해야합니다.
}