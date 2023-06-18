#include <bits/stdc++.h>
using namespace std;

int n, max_num;
vector<int> v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }

  sort(v.begin(), v.end());

  do {
    int result = 0;
    for (int i = 0; i <= n - 2; i++) {
      result += abs(v[i] - v[i + 1]);
    }
    if (result > max_num) max_num = result;
  } while (next_permutation(v.begin(), v.end()));

  printf("%d", max_num);
}
