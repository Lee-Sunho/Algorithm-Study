#include <bits/stdc++.h>
using namespace std;

int n, m, visited[10], ret[10];

void func(int depth) {
    if (depth == m) {
        for (int i = 1; i <= m; i++) {
            cout << ret[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            ret[depth + 1] = i;
            func(depth + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    func(0);

    return 0;
}