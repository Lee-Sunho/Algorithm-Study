#include <bits/stdc++.h>
using namespace std;

int n, m, h, arr[31][11], ret = 999;

bool check() {
    for (int i = 1; i <= n; i++) {
        int start = i;
        for (int j = 1; j <= h; j++) {
            if (arr[j][start])
                start++;
            else if (arr[j][start - 1])
                start--;
        }

        if (i != start) return false;
    }
    return true;
}

void go(int start, int cnt) {
    if (cnt > 3) return;
    if (check()) {
        ret = min(ret, cnt);
    }
    for (int i = start; i <= h; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] || arr[i][j - 1] || arr[i][j + 1]) continue;
            arr[i][j] = 1;
            go(i, cnt + 1);
            arr[i][j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> h;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }

    go(1, 0);

    if (ret > 3) {
        cout << -1;
        return 0;
    }
    cout << ret;

    return 0;
}