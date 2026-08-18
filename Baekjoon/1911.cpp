#include <bits/stdc++.h>
using namespace std;

int n, len, ret;
vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> len;
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        v.push_back({s, e});
    }

    sort(v.begin(), v.end());

    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (idx > v[i].first) v[i].first = idx;

        if (v[i].first < v[i].second) {
            int size = v[i].second - v[i].first;
            int cnt = (size / len) + (size % len ? 1 : 0);
            idx = v[i].first + cnt * len;
            ret += cnt;
        }
    }

    cout << ret;

    return 0;
}
