#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> turn90(vector<vector<int>>& v, int n) {
    vector<vector<int>> temp(8, vector<int>(8, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[j][n - i - 1] = v[i][j];
        }
    }
    return temp;
}

int main(int argc, char** argv) {
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        int n;
        int idx = 0;
        cin >> n;

        vector<vector<int>> board(8, vector<int>(8, 0));
        vector<vector<string>> ans(8, vector<string>(8, ""));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> board[i][j];
            }
        }

        // 회전
        for (int k = 0; k < 3; k++) {
            board = turn90(board, n);
            for (int i = 0; i < n; i++) {
                string s;
                for (int j = 0; j < n; j++) {
                    s += to_string(board[i][j]);
                }
                ans[i][idx] = s;
            }
            idx++;
        }

        // 출력
        cout << "#" << test_case << '\n';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << ans[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;  // 정상종료시 반드시 0을 리턴해야합니다.
}