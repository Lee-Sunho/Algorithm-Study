#include <bits/stdc++.h>
#define INF 99999
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

  for (int i = 1; i <= k; i++) {
    dp[i] = INF;
  }

  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      if (j >= cost[i]) {
        dp[j] = min(dp[j], dp[j - cost[i]] + 1);
      }
    }
  }
  dp[k] == INF ? cout << -1 : cout << dp[k];
}
