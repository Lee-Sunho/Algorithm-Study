#include <bits/stdc++.h>
using namespace std;

int n, s, cnt;
int arr[20];

int main() {
  scanf("%d %d", &n, &s);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  for (int bit = 1; bit < (1 << n); bit++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (bit & (1 << i)) sum += arr[i];
    }
    if (sum == s) cnt++;
  }
  printf("%d", cnt);
}
