#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    int test_case;
    int T;

    cin >> T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for (test_case = 1; test_case <= T; ++test_case) {
        int n;
        cin >> n;

        int mid = n / 2;
        vector<vector<int>> board(50, vector<int>(50, 0));

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++) {
                board[i][j] = s[j] - '0';
            }
        }

        int idx = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j < mid - idx) continue;
                if (j > mid + idx) continue;
                sum += board[i][j];
            }
            if (i < mid)
                idx++;
            else
                idx--;
        }
        cout << "#" << test_case << ' ' << sum << '\n';
    }
    return 0;  // 정상종료시 반드시 0을 리턴해야합니다.
}