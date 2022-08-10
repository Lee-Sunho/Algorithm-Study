#include <bits/stdc++.h>
using namespace std;

int dp[20];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int n;
        cin >> n;

        for(int j = 4; j <= n; j++){
            dp[j] = dp[j-1] + dp[j-2] + dp[j-3];
        }
        cout << dp[n] << '\n';
    }
}
