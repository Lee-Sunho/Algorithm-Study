#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
vector<char> lcs;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  string s1, s2;
  cin >> s1 >> s2;

  int i = 1, j = 1;
  for (i = 1; i <= s1.length(); i++) {
    for (j = 1; j <= s2.length(); j++) {
      if (s1[i - 1] != s2[j - 1])
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      else
        dp[i][j] = dp[i - 1][j - 1] + 1;
    }
  }
  cout << dp[--i][--j] << '\n';
  while (i && j) {
    if (dp[i][j] == dp[i - 1][j]) {
      i--;
    } else if (dp[i][j] == dp[i][j - 1]) {
      j--;
    } else {
      lcs.push_back(s1[i - 1]);
      i--;
      j--;
    }
  }
  reverse(lcs.begin(), lcs.end());
  for (auto c : lcs) cout << c;
}
