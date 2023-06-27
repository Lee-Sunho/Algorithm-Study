#include <bits/stdc++.h>
using namespace std;

int arr[1001];
int dp[1001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i <= n; i++) {
    dp[i] = arr[i];
    for (int j = 1; j < i; j++) {
      if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + arr[i]);
    }
  }
  sort(dp, dp + n + 1);
  cout << dp[n];
}
