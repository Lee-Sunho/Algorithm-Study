#include <bits/stdc++.h>
using namespace std;

int numbers[101];
long long dp[101][21];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> numbers[i];
  }

  int first = numbers[0];
  int ans = numbers[n - 1];
  dp[0][first] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 20; j++) {
      if (j - numbers[i] >= 0) {
        dp[i][j] += dp[i - 1][j - numbers[i]];
      }
      if (j + numbers[i] <= 20) {
        dp[i][j] += dp[i - 1][j + numbers[i]];
      }
    }
  }
  cout << dp[n - 2][ans];
}
