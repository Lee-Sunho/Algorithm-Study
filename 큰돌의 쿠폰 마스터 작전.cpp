#include <math.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
long long ans;
vector<int> price;
vector<int> coupon;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        price.push_back(num);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        coupon.push_back(num);
    }

    sort(price.rbegin(), price.rend());
    sort(coupon.rbegin(), coupon.rend());

    for (int i = 0; i < n; i++) {
        if (i < m) {
            long long ret = floor(price[i] * ((100 - coupon[i])) / 100);
            ans += ret;
        } else {
            ans += price[i];
        }
    }

    cout << ans;

    return 0;
}