#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m, ret = 1e9;

bool check(vector<int>& arr, int target) {
    int ret = 0;
    for (int i = 0; i < arr.size(); i++) {
        ret += arr[i] / target;
        if (arr[i] % target) ret++;
    }
    return ret <= n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    vector<int> v;
    int left = 0, right = -1;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        right = max(right, x);
    }

    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(v, mid)) {
            ret = min(ret, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ret;

    return 0;
}