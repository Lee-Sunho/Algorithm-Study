#include <bits/stdc++.h>
using namespace std;

int n, psum, ret = -1001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        psum = max(num, psum + num);
        ret = max(ret, psum);
    }
    cout << ret;

    return 0;
}
