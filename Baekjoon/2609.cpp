/*유클리드 호제법
- gcd(a, b) = gcd(a % b, b) = gcd(b, a % b);
- lcm(a, b) = a * b / gcd(a, b)
*/

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

int main() {
  int a, b, g;
  scanf("%d %d", &a, &b);

  g = gcd(a, b);
  printf("%d\n", g);
  printf("%d", a * b / g);
}
