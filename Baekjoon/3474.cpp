#include <bits/stdc++.h>
using namespace std;

int t, n, cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        cin >> n;

        int k = 5;
        while (k <= n) {
            cnt += n / k;
            k *= 5;
        }

        cout << cnt << '\n';
        cnt = 0;
    }

    return 0;
}