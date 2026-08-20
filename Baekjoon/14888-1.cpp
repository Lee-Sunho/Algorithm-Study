#include <bits/stdc++.h>
using namespace std;

int n, op[4], num[12], min_ret = 1e9, max_ret = -1e9;
// + - * /

int calc(int num1, int num2, int op) {
    int ret;
    switch (op) {
        case 0:
            ret = num1 + num2;
            break;

        case 1:
            ret = num1 - num2;
            break;

        case 2:
            ret = num1 * num2;
            break;

        case 3:
            ret = num1 / num2;
            break;

        default:
            break;
    }
    return ret;
}

void func(int cnt, int sum) {
    if (cnt == n) {
        min_ret = min(min_ret, sum);
        max_ret = max(max_ret, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (op[i]) {
            op[i]--;
            func(cnt + 1, calc(sum, num[cnt], i));
            op[i]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }

    func(1, num[0]);

    cout << max_ret << '\n' << min_ret;

    return 0;
}
