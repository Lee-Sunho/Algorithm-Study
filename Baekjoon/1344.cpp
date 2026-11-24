#include <bits/stdc++.h>
using namespace std;

// dp[idx][a][b]: idx 구간에서 A팀이 a골, B팀이 b골 넣을 확률
double dp[20][20][20];

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    double perA = (double)a / 100.0;
    double perB = (double)b / 100.0;

    dp[0][0][0] = 1.0;

    for (int idx = 0; idx < 18; idx++) {
        for (int i = 0; i <= idx; i++) {
            for (int j = 0; j <= idx; j++) {
                double cur = dp[idx][i][j];
                dp[idx + 1][i][j] += cur * (1.0 - perA) * (1.0 - perB);
                dp[idx + 1][i + 1][j] += cur * perA * (1.0 - perB);
                dp[idx + 1][i][j + 1] += cur * (1.0 - perA) * perB;
                dp[idx + 1][i + 1][j + 1] += cur * perA * perB;
            }
        }
    }

    double ans = 0.0;
    for (int i = 0; i <= 18; i++) {
        for (int j = 0; j <= 18; j++) {
            if (isPrime(i) || isPrime(j)) {
                ans += dp[18][i][j];
            }
        }
    }

    printf("%.10lf", ans);

    return 0;
}