#include <bits/stdc++.h>
using namespace std;

int n, ret = 1e9;
vector<pair<int, int>> v;

void func(int idx, int sour, int bitter, bool flag) {
    if (idx == n) {
        if (flag) {
            ret = min(ret, abs(sour - bitter));
        }
        return;
    }

    for (int i = idx; i < n; i++) {
        func(i + 1, sour, bitter, flag);
        func(i + 1, sour * v[i].first, bitter + v[i].second, true);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    func(0, 1, 0, false);
    cout << ret;

    return 0;
}