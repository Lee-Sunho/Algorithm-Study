#include <iostream>
using namespace std;

int n, num[11], op[4];
int max_res = -1000000000;
int min_res = 1000000001;

int calc(int num1, int num2, int op) {
    int ret = 0;
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

void func(int depth, int cur) {
    if (depth == n) {
        max_res = max(max_res, cur);
        min_res = min(min_res, cur);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (op[i]) {
            op[i]--;
            func(depth + 1, calc(cur, num[depth], i));
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

    cout << max_res << "\n" << min_res;
}
