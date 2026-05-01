#include <bits/stdc++.h>
using namespace std;

int n, mp, mf, ms, mv, min_cost = 1e9;
int arr[16][6];
vector<int> ret;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cin >> mp >> mf >> ms >> mv;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i < (1 << n); i++) {
        int sp = 0, sf = 0, ss = 0, sv = 0, sum = 0;
        vector<int> cur;

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sp += arr[j + 1][0];
                sf += arr[j + 1][1];
                ss += arr[j + 1][2];
                sv += arr[j + 1][3];
                sum += arr[j + 1][4];
                cur.push_back(j + 1);
            }
        }

        if (sp >= mp && sf >= mf && ss >= ms && sv >= mv) {
            if (sum < min_cost) {
                min_cost = sum;
                ret = cur;
            } else if (sum == min_cost) {
                if (cur < ret) ret = cur;
            }
        }
    }

    if (min_cost == 1e9) {
        cout << -1 << '\n';
    } else {
        cout << min_cost << '\n';
        for (int x : ret) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}