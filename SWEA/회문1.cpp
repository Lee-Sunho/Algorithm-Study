#include <iostream>
#include <vector>

using namespace std;

bool isPelin(vector<char>& v) {
    int left = 0;
    int right = v.size() - 1;

    while (left <= right) {
        if (v[left] != v[right]) return false;
        left++;
        right--;
    }
    return true;
}

int main(int argc, char** argv) {
    int test_case;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for (test_case = 1; test_case <= 10; ++test_case) {
        int len, n = 8;
        cin >> len;

        char board[10][10];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> board[i][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                vector<char> v1, v2;
                if (i + len - 1 < n) {
                    for (int k = 0; k < len; k++) {
                        v1.push_back(board[i + k][j]);
                    }
                    if (isPelin(v1)) ans++;
                }

                if (j + len - 1 < n) {
                    for (int k = 0; k < len; k++) {
                        v2.push_back(board[i][j + k]);
                    }
                    if (isPelin(v2)) ans++;
                }
            }
        }

        cout << "#" << test_case << ' ' << ans << '\n';
    }
    return 0;  // 정상종료시 반드시 0을 리턴해야합니다.
}