#include <bits/stdc++.h>
using namespace std;

int n, ret[1000004];
stack<pair<int, int>> stk;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(ret, -1, sizeof(ret));

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        while (stk.size()) {
            if (stk.top().second < num) {
                ret[stk.top().first] = num;
                stk.pop();
            } else
                break;
        }
        stk.push({i, num});
    }

    for (int i = 0; i < n; i++) {
        cout << ret[i] << ' ';
    }

    return 0;
}