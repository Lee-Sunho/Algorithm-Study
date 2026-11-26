#include <bits/stdc++.h>
using namespace std;

string s;
bool dp[2504][2504];
int mindp[2504];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        dp[i][i] = true;
    }

    int n = s.size();

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) dp[i][i + 1] = true;
    }

    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int e = i + len - 1;
            if (s[i] == s[e] && dp[i + 1][e - 1]) dp[i][e] = true;
        }
    }

    fill(mindp, mindp + 2504, 1e9);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (dp[j][i]) {
                if (j == 0)
                    mindp[i] = 1;
                else
                    mindp[i] = min(mindp[i], mindp[j - 1] + 1);
            }
        }
    }

    cout << mindp[n - 1] << '\n';

    return 0;
}
