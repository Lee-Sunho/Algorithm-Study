#include <bits/stdc++.h>
using namespace std;

int k, root, cnt_node, arr[1030];
vector<int> ret[12];

void func(int left, int right, int level) {
    if (left > right) return;

    if (left == right) {
        ret[level].push_back(arr[left]);
        return;
    }

    int mid = (left + right) / 2;
    func(left, mid - 1, level + 1);
    ret[level].push_back(arr[mid]);
    func(mid + 1, right, level + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k;
    cnt_node = pow(2, k) - 1;

    for (int i = 0; i < cnt_node; i++) {
        cin >> arr[i];
    }

    func(0, cnt_node - 1, 1);

    for (int i = 1; i <= k; i++) {
        for (int x : ret[i]) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}