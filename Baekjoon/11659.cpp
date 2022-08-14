#include <bits/stdc++.h>
using namespace std;

int dp[100005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        dp[i] = dp[i-1] + x;
    }

    for(int T = 0; T < m; T++){
        int a, b;
        cin >> a >> b;

        cout << dp[b] - dp[a-1] << '\n';
    }

}
