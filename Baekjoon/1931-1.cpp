#include <bits/stdc++.h>
using namespace std;

int n, e, ret;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++) {
        if (v[i].first < e) continue;
        e = v[i].second;
        ret++;
    }

    cout << ret;

    return 0;
}
