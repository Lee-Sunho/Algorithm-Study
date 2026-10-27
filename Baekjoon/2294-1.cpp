#include <bits/stdc++.h>
using namespace std;

int n, k;
// dp[j]: 합이 j일때 동전 최소 사용 횟수
// dp[j]: min(dp[j], dp[j - v] + 1);
vector<int> dp(10004, 1e9);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;

        dp[0] = 0;
        for (int j = v; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - v] + 1);
        }
    }

    if (dp[k] == 1e9)
        cout << -1;
    else
        cout << dp[k];

    return 0;
}
