#include <bits/stdc++.h>
using namespace std;

int n, k;
int dp[10004];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        for (int v = x; v <= k; v++) {
            dp[v] = dp[v] + dp[v - x];
        }
    }

    cout << dp[k];

    return 0;
}
