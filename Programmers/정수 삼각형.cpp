#include <string>
#include <vector>

using namespace std;

int dp[10001][10001];

int solution(vector<vector<int>> triangle) {
    // 위에서부터 내려오면서 dp 갱신
    // 각 줄에서 첫 값, 끝 값은 전 값이 하나이므로 예외처리
    // dp[i - 1][j - 1], dp[i - 1][j] 중 큰 값 + 현재 값
    int n = triangle.size();
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][0] + triangle[i][j];
            } else if (j == triangle[i].size() - 1) {
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            } else {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
        }
    }

    // 마지막 줄에서 가장 큰 값 구하기
    int ret = -1;
    for (int i = 0; i < triangle[n - 1].size(); i++) {
        ret = max(ret, dp[n - 1][i]);
    }
    return ret;
}