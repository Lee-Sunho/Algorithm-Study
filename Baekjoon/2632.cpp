#include <bits/stdc++.h>
using namespace std;

int target, m, n, ret;
vector<int> v1, v2;
int p_sum1[2004], p_sum2[20004];
map<int, int> cnt1, cnt2;

void make(int n, int p_sum[], map<int, int>& mp) {
    mp[0] = 1;
    for (int len = 1; len < n; len++) {
        for (int start = 1; start <= n; start++) {
            int sum = p_sum[start + len - 1] - p_sum[start - 1];
            mp[sum]++;
        }
    }
    mp[p_sum[n]]++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> target >> m >> n;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        v1.push_back(a);
    }

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v2.push_back(a);
    }

    p_sum1[0] = 0;
    for (int i = 1; i <= m; i++) p_sum1[i] = p_sum1[i - 1] + v1[i];
    for (int i = m; i <= 2 * m; i++) p_sum1[i] = p_sum1[i - 1] + v1[i - m];

    p_sum2[0] = 0;
    for (int i = 1; i <= n; i++) p_sum2[i] = p_sum2[i - 1] + v2[i];
    for (int i = n; i <= 2 * n; i++) p_sum2[i] = p_sum2[i - 1] + v2[i - n];

    make(m, p_sum1, cnt1);
    make(n, p_sum2, cnt2);

    ret = cnt1[target] + cnt2[target];
    for (int i = 1; i < target; i++) {
        ret += cnt1[i] * cnt2[target - i];
    }

    cout << ret;
    return 0;
}
