#include <bits/stdc++.h>
using namespace std;

/*
    N(1 <= N <= 2000), M 최대 백만, 0.5초 => O(N^2) X M 안됨. 완탐 X
    DP ???
*/

bool dp[2004][2004];  // dp[s][e] : s ~ e 펠린?
int v[2004];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    // 길이 1인 경우
    for (int i = 1; i <= n; i++) {
        dp[i][i] = true;
    }

    // 길이 2인 경우
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i + 1]) dp[i][i + 1] = true;
    }

    // 길이 3 이상인 경우
    for (int len = 3; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int e = i + len - 1;
            if (v[i] == v[e] && dp[i + 1][e - 1]) dp[i][e] = true;
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        cout << dp[s][e] << '\n';
    }

    return 0;
}
