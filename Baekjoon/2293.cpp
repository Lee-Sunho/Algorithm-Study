#include <bits/stdc++.h>
using namespace std;

int dp[10001];
int cost[101];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; i++) {
    cin >> cost[i];
  }

  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      if (j >= cost[i])
        dp[j] += dp[j - cost[i]];
    }
  }
  cout << dp[k];
}
