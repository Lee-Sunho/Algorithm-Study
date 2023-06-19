#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

int t;
int arr[1000007];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 2; i <= MAX; i++) {
    arr[i] = i;
  }

  for (int i = 2; i <= MAX; i++) {
    if (arr[i] == 0) continue;
    for (int j = i + i; j <= MAX; j += i) {
      arr[j] = 0;
    }
  }

  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, cnt = 0;
    cin >> n;

    for (int j = 2; j <= n / 2; j++) {
      if (arr[j] == 0 || arr[n - j] == 0) continue;
      cnt++;
    }
    cout << cnt << '\n';
  }
}
