#include <bits/stdc++.h>
using namespace std;

int n, k, ret;
vector<pair<int, int>> turn;
vector<string> v;

int findL(int pos) {
    for (int i = pos; i > 0; i--) {
        if (v[i][6] == v[i - 1][2]) return i;
    }
    return 0;
}

int findR(int pos) {
    for (int i = pos; i < n - 1; i++) {
        if (v[i][2] == v[i + 1][6]) return i;
    }
    return n - 1;
}

void rotate(int idx, int dir) {
    if (dir == -1) {
        int prev = v[idx][0];
        for (int i = 1; i < 8; i++) {
            v[idx][i - 1] = v[idx][i];
        }
        v[idx][7] = prev;
    } else {
        int prev = v[idx][7];
        for (int i = 6; i >= 0; i--) {
            v[idx][i + 1] = v[idx][i];
        }
        v[idx][0] = prev;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        turn.push_back({--a, b});
    }

    for (auto it : turn) {
        int l = findL(it.first);
        int r = findR(it.first);

        int cnt = 0;
        for (int i = it.first; i >= l; i--) {
            int dir = it.second;
            rotate(i, cnt % 2 == 0 ? dir : -1 * dir);
            cnt++;
        }

        cnt = 1;
        for (int i = it.first + 1; i <= r; i++) {
            int dir = it.second;
            rotate(i, cnt % 2 == 0 ? dir : -1 * dir);
            cnt++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (v[i][0] == '1') ret++;
    }
    cout << ret;
    return 0;
}
