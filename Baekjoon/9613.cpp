#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;

    int arr[n];
    for (int j = 0; j < n; j++) {
      cin >> arr[j];
    }

    // 100만 * 100만 * 100만
    long long ans = 0;
    for (int j = 0; j < n - 1; j++) {
      for (int k = j + 1; k < n; k++) {
        ans += gcd(arr[j], arr[k]);
      }
    }
    cout << ans << '\n';
  }
}
