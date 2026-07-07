#include <bits/stdc++.h>
using namespace std;

int n, x, ans;
int arr[2000004];
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
        arr[num] = i;
    }

    cin >> x;

    for (int i = 0; i < n; i++) {
        if (arr[abs(x - v[i])] > i) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}