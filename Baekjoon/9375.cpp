#include <bits/stdc++.h>
using namespace std;

int t, n;
string a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    for (int i = 0; i < t; i++) {
        map<string, int> m;
        cin >> n;

        for (int j = 0; j < n; j++) {
            cin >> a >> b;
            m[b]++;  // 종류의 개수만 저장
        }

        int result = 1;

        for (auto it : m) {
            result *= it.second + 1;
        }

        cout << result - 1 << '\n';
    }

    return 0;
}