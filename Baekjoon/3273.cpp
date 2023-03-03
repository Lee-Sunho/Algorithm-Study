#include <bits/stdc++.h>
using namespace std;

int n, x, ans;
int arr[2000007];
vector<int> v;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    v.push_back(num);
  }
  cin >> x;

  for (auto c : v) {
    if (x > c && arr[x - c] == 1) {
      ans++;
      continue;
    }
    arr[c] = 1;
  }
  cout << ans;
}
