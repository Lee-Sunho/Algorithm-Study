#include <bits/stdc++.h>
#define MAX 100000000
using namespace std;

int n;
long long ans = 1;
bool is_prime[MAX + 9];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 2; i <= n; i++) {
    is_prime[i] = true;
  }

  // 에라토스테네스 체 sqrt(n)까지만 해야 시간초과 안남
  for (int i = 2; i <= sqrt(n); i++) {
    if (is_prime[i] == 0) continue;
    for (int j = i + i; j <= n; j += i) {
      is_prime[j] = false;
    }
  }

  for (int i = 2; i <= n; i++) {
    if (is_prime[i]) {
      long long temp = 1;
      while (i * temp <= n) {
        temp *= i;
      }
      ans = ans * temp % (1LL << 32);
    }
  }
  cout << ans;
}
