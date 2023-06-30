#include <bits/stdc++.h>
using namespace std;

int a[51];
int b[51];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  int ans = 0;
  sort(a, a + n);
  reverse(a, a + n);
  sort(b, b + n);

  for (int i = 0; i < n; i++) {
    ans += a[i] * b[i];
  }
  cout << ans;
}
