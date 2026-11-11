#include <bits/stdc++.h>
using namespace std;

vector<int> v_hp;
vector<int> v_joy;

int n;
int dp[104];  // 해당 체력 미만으로 소모했을 때 얻을 수 있는 최대 기쁨

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v_hp.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v_joy.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 100; j > v_hp[i]; j--) {
            dp[j] = max(dp[j], dp[j - v_hp[i]] + v_joy[i]);
        }
    }

    // int ret = -1e9;
    // for (int i = 0; i <= 100; i++) {
    //     ret = max(ret, dp[i]);
    // }

    cout << dp[100];

    return 0;
}
