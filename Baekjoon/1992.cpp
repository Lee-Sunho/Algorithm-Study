#include <bits/stdc++.h>
using namespace std;

int n, arr[70][70];
string ans;

void solve(int y, int x, int size) {
    bool isSame = true;
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (arr[y][x] != arr[i][j]) {
                isSame = false;
                break;
            }
        }
    }

    if (isSame) {
        ans += to_string(arr[y][x]);
    } else {
        ans += "(";
        solve(y, x, size / 2);
        solve(y, x + size / 2, size / 2);
        solve(y + size / 2, x, size / 2);
        solve(y + size / 2, x + size / 2, size / 2);
        ans += ")";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }

    solve(0, 0, n);
    printf("%s\n", ans.c_str());

    return 0;
}