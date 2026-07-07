#include <bits/stdc++.h>
using namespace std;

int n, x, ans;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    cin >> x;

    sort(v.begin(), v.end());

    int l = 0, r = n - 1;
    while (l < r) {
        if (v[l] + v[r] == x) {
            ans++;
            l++;
            r--;
        } else if (v[l] + v[r] > x) {
            r--;
        } else
            l++;
    }

    cout << ans;

    return 0;
}