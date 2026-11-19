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
        int n, m;
        cin >> n >> m;

        vector<vector<int>> psum(20, vector<int>(20, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int a;
                cin >> a;
                psum[i + 1][j + 1] = a + psum[i][j + 1] + psum[i + 1][j] - psum[i][j];
            }
        }

        int k = n - m + 1;
        int ret = -1e9;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                int sum = psum[i + m][j + m] - psum[i][j + m] - psum[i + m][j] + psum[i][j];
                ret = max(ret, sum);
            }
        }
        cout << "#" << test_case << ' ' << ret << '\n';
    }
    return 0;  // 정상종료시 반드시 0을 리턴해야합니다.
}