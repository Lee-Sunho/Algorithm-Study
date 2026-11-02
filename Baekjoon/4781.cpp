#include <bits/stdc++.h>
using namespace std;

// 사탕 중복 구매 가능
// 칼로리의 합의 최대

int n;
double m;
int dp[10004];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        memset(dp, 0, sizeof(dp));
        cin >> n >> m;
        if (n == 0) break;

        int target = round(m * 100);

        for (int i = 0; i < n; i++) {
            int c;
            double p;

            cin >> c >> p;

            int cost = round(100 * p);

            for (int j = cost; j <= target; j++) {
                dp[j] = max(dp[j], dp[j - cost] + c);
            }
        }

        cout << dp[target] << '\n';
    }

    return 0;
}
