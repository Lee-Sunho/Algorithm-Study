#include <bits/stdc++.h>

using namespace std;

int dp[101][101];
bool pd[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    // 웅덩이 표시
    for (int i = 0; i < puddles.size(); i++) {
        int a = puddles[i][1];
        int b = puddles[i][0];
        pd[a][b] = true;
    }

    // dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (pd[i][j]) continue;
            if (i == 1 && j == 1) continue;

            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
        }
    }
    return dp[n][m];
}