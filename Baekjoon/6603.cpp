#include <bits/stdc++.h>
using namespace std;

int k, x, arr[13];
vector<int> ret;

void func(int depth, int idx) {
    if (depth == 6) {
        for (int num : ret) {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = idx; i < k; i++) {
        if (k - i < 6 - depth) break;

        ret.push_back(arr[i]);
        func(depth + 1, i + 1);
        ret.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        ret.clear();
        cin >> k;

        if (k == 0) break;

        for (int i = 0; i < k; i++) {
            cin >> arr[i];
        }

        func(0, 0);
        cout << '\n';
    }

    return 0;
}