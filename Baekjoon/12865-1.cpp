#include <bits/stdc++.h>
using namespace std;

int n, k;
int dp[104][100004];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    vector<pair<int, int>> item(n + 1, {0, 0});
    for (int i = 1; i <= n; i++) {
        int w, v;
        cin >> w >> v;
        item[i] = {w, v};
    }

    for (int i = 1; i <= item.size(); i++) {
        for (int j = 1; j <= k; j++) {
            if (item[i].first > j)
                dp[i][j] = dp[i - 1][j];
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - item[i].first] + item[i].second);
            }
        }
    }

    // dp[i][j] : i번째 항목까지 계산했을 때 무게 j에서 가치합 최댓값
    // k가 10만이면 배열 너무 커진다.. -> 이 문제에서는 4천만B: 40MB이므로 최적화 없이도 통과 가능
    // 최적화 - dp[w]: 무게 w일때 가질 수 있는 가치합 최댓값
    // for (int i = 0; i < item.size(); i++) {
    //     for (int w = k; w >= item[i].first; w--) {
    //         dp[w] = max(dp[w], dp[w - item[i].first] + item[i].second);
    //     }
    // }

    cout << dp[n][k];

    return 0;
}
