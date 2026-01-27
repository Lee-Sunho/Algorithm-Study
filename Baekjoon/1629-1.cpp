#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, c;

ll func(ll a, ll b, ll c) {
    if (b == 1) {
        return a % c;
    }

    ll ret = func(a, b / 2, c);
    ret = ret * ret % c;

    if (b % 2) {
        ret = ret * a % c;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b >> c;
    cout << func(a, b, c);

    return 0;
}