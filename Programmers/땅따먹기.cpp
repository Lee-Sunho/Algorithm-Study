#include <bits/stdc++.h>
using namespace std;

int dp[100001][4];
int solution(vector<vector<int>> land) {
    int answer = 0;
    int n = land.size();

    for (int i = 0; i < 4; i++) {
        dp[0][i] = land[0][i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            int max_value = -1;
            for (int k = 0; k < 4; k++) {
                if (k != j && dp[i - 1][k] > max_value) max_value = dp[i - 1][k];
            }
            dp[i][j] = max_value + land[i][j];
        }
    }

    return max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2], dp[n - 1][3]});
}