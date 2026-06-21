#include <bits/stdc++.h>
using namespace std;

int n, k, ret;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    vector<pair<int, int>> v(n);
    vector<int> bag(k);
    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 0; i < k; i++) {
        cin >> bag[i];
    }

    sort(v.begin(), v.end());
    sort(bag.begin(), bag.end());

    int idx = 0;

    for (int i = 0; i < k; i++) {
        while (idx < n && v[idx].first <= bag[i]) {
            pq.push(v[idx++].second);
        }
        if (pq.size()) {
            ret += pq.top();
            pq.pop();
        }
    }

    cout << ret;

    return 0;
}