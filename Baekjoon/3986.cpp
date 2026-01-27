#include <bits/stdc++.h>
using namespace std;

int n, cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a_even = 0, a_odd = 0, b_even = 0, b_odd = 0;
        string str;
        cin >> str;

        for (int i = 0; i < str.length(); i++) {
            if (str[i] == 'A') {
                if (i & 1) {
                    a_odd++;
                } else {
                    a_even++;
                }
            } else if (str[i] == 'B') {
                if (i & 1) {
                    b_odd++;
                } else {
                    b_even++;
                }
            }
        }

        if ((a_even == a_odd) && (b_even == b_odd)) {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}