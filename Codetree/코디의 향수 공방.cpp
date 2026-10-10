#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int q;
vector<int> perfume;
bool isDeleted[1104];

void init() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        perfume.push_back(v);
    }
}

void add() {
    int v;
    cin >> v;
    perfume.push_back(v);
}

void discard() {
    int num;
    cin >> num;
    int idx = num - 1;
    if (isDeleted[idx] || num > perfume.size())
        cout << -1 << '\n';
    else {
        isDeleted[idx] = true;
        cout << perfume[idx] << '\n';
    }
}

void blending() {
    int k;
    cin >> k;

    vector<int> dp(3004, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < perfume.size(); j++) {
            if (isDeleted[j]) continue;
            if (perfume[j] <= i) dp[i] = min(dp[i], dp[i - perfume[j]] + 1);
        }
    }

    if (dp[k] == 0 || dp[k] == 1e9)
        cout << -1 << '\n';
    else
        cout << dp[k] << '\n';
}

void compose() {
    int k;
    cin >> k;
    vector<int> vals;
    for (int i = 0; i < perfume.size(); i++) {
        if (!isDeleted[i]) vals.push_back(perfume[i]);
    }

    int n = vals.size();

    vector<int> freq(3004, 0);
    vector<int> suffix(3004, 0);

    for (int v : vals) freq[v]++;
    for (int v = 3000; v >= 1; v--) suffix[v] = suffix[v + 1] + freq[v];

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int need = k - vals[i] - vals[j];
            if (need <= 0)
                ans += n;
            else if (need <= 3000)
                ans += suffix[need];
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> q;
    while (q--) {
        int worknum;
        cin >> worknum;

        switch (worknum) {
            case 1:
                init();
                break;
            case 2:
                add();
                break;
            case 3:
                discard();
                break;
            case 4:
                blending();
                break;
            case 5:
                compose();
                break;
        }
    }
    return 0;
}