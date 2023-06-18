#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) {
    return a.second < b.second ? true : false;
  }
  return a.first < b.first ? true : false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x;
    cin >> y;
    v.push_back({x, y});
  }

  sort(v.begin(), v.end(), compare);

  for (int i = 0; i < n; i++) {
    cout << v[i].first << ' ' << v[i].second << '\n';
  }
}
