#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
  return b ? gcd(b, a % b) : a;
}

long long lcm(long long a, long long b) {
  return a * b / gcd(a, b);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    long long a, b;
    cin >> a >> b;
    cout << lcm(a, b) << '\n';
  }
}
