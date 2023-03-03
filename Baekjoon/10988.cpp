#include <bits/stdc++.h>
using namespace std;

string str;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> str;
  int length = str.length();
  for (int i = 0; i < length / 2; i++) {
    if (str[i] != str[length - 1 - i]) {
      cout << "0";
      return 0;
    }
  }
  cout << "1";
}
