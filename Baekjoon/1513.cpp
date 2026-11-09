#include <bits/stdc++.h>
using namespace std;

int n, m, c;

int dp[54][54][54][54], board[54][54];
int idx = 1;
int dy[] = {1, 0};
int dx[] = {0, 1};
int MOD = 1000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> c;
    for (int i = 1; i <= c; i++) {
        int y, x;
        cin >> y >> x;
        board[y][x] = i;
    }

    if (board[1][1] > 0) {
        dp[1][1][1][board[1][1]] = 1;
    } else {
        dp[1][1][0][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue;
            // 오락실인 경우
            if (board[i][j] > 0) {
                for (int cnt = 1; cnt <= c; cnt++) {
                    for (int prev = 0; prev < board[i][j]; prev++) {
                        dp[i][j][cnt][board[i][j]] =
                            (dp[i][j][cnt][board[i][j]] + dp[i - 1][j][cnt - 1][prev] +
                             dp[i][j - 1][cnt - 1][prev]) %
                            MOD;
                    }
                }
            }
            // 오락실 아닌 경우
            else {
                for (int cnt = 0; cnt <= c; cnt++) {
                    for (int prev = 0; prev <= c; prev++) {
                        dp[i][j][cnt][prev] =
                            (dp[i - 1][j][cnt][prev] + dp[i][j - 1][cnt][prev]) % MOD;
                    }
                }
            }
        }
    }

    for (int k = 0; k <= c; k++) {
        int sum = 0;
        for (int prev = 0; prev <= c; prev++) {
            sum = (sum + dp[n][m][k][prev]) % MOD;
        }
        cout << sum << ' ';
    }

    return 0;
}
