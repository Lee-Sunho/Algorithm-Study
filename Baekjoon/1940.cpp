#include <bits/stdc++.h>
using namespace std;

int n, m, result;
int cnt[100004];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cin >> m;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    if (m > 200000) {
        cout << 0;
        return 0;
    }

    for (int i = 1; i <= 100000; i++) {
        int target = m - i;
        if (target > i && target <= 100000) {
            if (cnt[i] && cnt[target]) {
                result++;
            }
        }
    }

    cout << result;

    return 0;
}