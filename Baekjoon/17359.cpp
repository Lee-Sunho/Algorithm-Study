#include <bits/stdc++.h>
using namespace std;

int n, base, min_num = 999999;
vector<string> v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    v.push_back(s);
    for (int j = 0; j < s.length() - 1; j++) {
      if (s[j] != s[j + 1]) base++;
    }
  }

  sort(v.begin(), v.end());

  do {
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
      if (v[i][v[i].length() - 1] != v[i + 1][0]) cnt++;
    }
    if (cnt < min_num) min_num = cnt;
  } while (next_permutation(v.begin(), v.end()));

  cout << min_num + base << '\n';
}
