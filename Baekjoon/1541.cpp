#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> s;
  int ans = 0;
  int temp = 0;
  int sign = 1;

  for (auto c : s) {
    if (c == '+' || c == '-') {
      ans += temp * sign;
      if (c == '-') sign = -1;
      temp = 0;

    } else {
      temp = temp * 10 + (c - '0');
    }
  }
  ans += temp * sign;
  cout << ans;
}
