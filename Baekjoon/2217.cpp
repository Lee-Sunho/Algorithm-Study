#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }

  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, v[i] * (i + 1));
  }
  cout << ans;
}
