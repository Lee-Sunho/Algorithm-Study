#include <bits/stdc++.h>
using namespace std;
#define MAX 5000000

int n;
vector<int> v;
int arr[5000007];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }

  for (int i = 2; i <= MAX; i++) {
    if (arr[i]) continue;
    arr[i] = i;
    for (int j = i + i; j <= MAX; j += i)
      if (!arr[j]) arr[j] = i;
  }

  for (int i = 0; i < n; i++) {
    int target = v[i];
    int div = 2;
    while (target > 1) {
      cout << arr[target] << " ";
      target /= arr[target];
    }
    cout << "\n";
  }
}
