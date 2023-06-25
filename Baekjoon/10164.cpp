#include <bits/stdc++.h>
using namespace std;

int dp[16][16];

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  int step = 1;
  int x, y;
  dp[1][0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (step == k) {
        x = j;
        y = i;
      }
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      step++;
    }
  }
  k ? cout << dp[y][x] * dp[n - y + 1][m - x + 1] : cout << dp[n][m];
}
