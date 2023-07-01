#include <bits/stdc++.h>
#define DIV 10007
using namespace std;

long long dp[1010][1010];
int main() {
  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; i++) dp[i][0] = 1;
  dp[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % DIV;
    }
  }
  cout << dp[n][k];
}
