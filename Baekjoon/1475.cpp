#include <bits/stdc++.h>
using namespace std;

int n, cnt[10], ans;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  while (n != 0) {
    int num = n % 10;
    cnt[num]++;
    n = n / 10;
  }

  for (int i = 0; i < 10; i++) {
    if (i == 6 || i == 9) {
      continue;
    }
    ans = max(ans, cnt[i]);
  }

  ans = max(ans, (cnt[6] + cnt[9] + 1) / 2);
  cout << ans;
}
