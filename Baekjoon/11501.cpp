#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    int n;
    cin >> n;

    long long ans = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }

    int max = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (v[i] > max) {
        max = v[i];
        continue;
      }
      ans += max - v[i];
    }
    cout << ans << '\n';
  }
}
