#include <bits/stdc++.h>
using namespace std;

int n, e, ret;
vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        if (v[i].first < e) {
            e += v[i].second;
        } else {
            e = v[i].first + v[i].second;
        }

        // e = max(e, v[i].first);
        // e += v[i].second;
    }

    cout << e;

    return 0;
}
