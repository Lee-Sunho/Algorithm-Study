#include <bits/stdc++.h>
using namespace std;

int n, m, ret[10];

void func(int depth, int idx) {
    if (depth == m) {
        for (int i = 0; i < m; i++) cout << ret[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = idx; i <= n; i++) {
        ret[depth] = i;
        func(depth + 1, i + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    func(0, 1);

    return 0;
}