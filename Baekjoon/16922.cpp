#include <bits/stdc++.h>
using namespace std;

int n, ret, arr[4] = {1, 5, 10, 50}, check[1001];

void func(int cnt, int sum, int idx) {
    if (cnt == n) {
        if (!check[sum]) {
            ret++;
            check[sum] = 1;
        }
        return;
    }

    for (int i = idx; i < 4; i++) {
        func(cnt + 1, sum + arr[i], i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    func(0, 0, 0);

    cout << ret;

    return 0;
}