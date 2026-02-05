#include <bits/stdc++.h>
using namespace std;

int n, cnt = 1, target = 666;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    while (cnt < n) {
        target++;
        string s_target = to_string(target);
        if (s_target.find("666") != string::npos) {
            cnt++;
        }
    }

    cout << target << '\n';

    return 0;
}