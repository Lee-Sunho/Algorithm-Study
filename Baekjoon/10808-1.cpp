/* 1-B 알파벳 개수 */

#include <bits/stdc++.h>
using namespace std;

string s;
int alpha[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        int idx = s[i] - 'a';
        alpha[idx]++;
    }

    for (int a : alpha) {
        cout << a << ' ';
    }
}