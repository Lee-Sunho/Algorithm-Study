#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[26] = {0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    cnt[s[i] - 'a']++;
  }

  for (int i = 0; i < 26; i++) {
    cout << cnt[i] << ' ';
  }
}
