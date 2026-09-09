#include <bits/stdc++.h>
using namespace std;

int n, ret;
int board[17][17], dp[17][17][3];

bool check(int y, int x, int pos) {
    if (pos == 0 || pos == 2) {
        if (board[y][x] == 0) return true;
    } else if (pos == 1) {
        if (board[y][x] == 0 && board[y - 1][x] == 0 && board[y][x - 1] == 0) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    dp[0][1][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][0];
            if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][0];

            if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][1];
            if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][1];
            if (check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][1];

            if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][2];
            if (check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][2];
        }
    }

    cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];

    return 0;
}