#include <bits/stdc++.h>
#define MAX 100000000
using namespace std;

bool is_prime(int x) {
  if (x < 2) return false;
  for (int i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) return false;
  }
  return true;
}

bool is_palindrome(string str) {
  string origin, reversed;
  origin = str;
  reverse(str.begin(), str.end());
  reversed = str;
  if (origin == reversed) return true;
  return false;
}

int a, b;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(0);

  cin >> a >> b;

  /*
  1억까지의 소수팰린드롬을 출력한 결과 1천만 이상인 결과는 없음.
  즉, 1천만까지만 반복문을 돌아도 됨.

  또한 소수 중에서 팰린드롬 검사를 하는 것이 아니라
  팰린드롬 중에서 소수를 판별해야 시간초과에 안걸림
  */
  for (int i = a; i < 10000000; i++) {
    if (i > b) break;
    if (is_palindrome(to_string(i)) && is_prime(i)) {
      cout << i << '\n';
    }
  }
  cout << -1;
}
