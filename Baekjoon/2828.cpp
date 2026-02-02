#include <bits/stdc++.h>
using namespace std;

int m, n, j, cnt, target, lf = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cin >> j;

    for (int i = 0; i < j; i++) {
        cin >> target;
        if (target >= lf && target < lf + m) continue;

        if (target < lf) {
            while (lf > 0) {
                lf--;
                cnt++;
                if (target >= lf && target < lf + m) break;
            }
        } else if (target >= lf + m) {
            while (lf + m <= n) {
                lf++;
                cnt++;
                if (target >= lf && target < lf + m) break;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}