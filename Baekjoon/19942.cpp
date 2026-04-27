#include <bits/stdc++.h>
using namespace std;

int n, mp, mf, ms, mv, min_cost = 1e9;
int arr[16][6];
vector<int> ret, cur;

void func(int idx, int sum_cost, int sum_p, int sum_f, int sum_s, int sum_v) {
    if (idx > n) return;
    if (sum_cost > min_cost) return;

    if (sum_p >= mp && sum_f >= mf && sum_s >= ms && sum_v >= mv) {
        if (sum_cost < min_cost) {
            min_cost = sum_cost;
            ret = cur;
        } else {
            if (cur < ret) ret = cur;
        }
    }

    cur.push_back(idx + 1);
    func(idx + 1, sum_cost + arr[idx + 1][4], sum_p + arr[idx + 1][0], sum_f + arr[idx + 1][1],
         sum_s + arr[idx + 1][2], sum_v + arr[idx + 1][3]);
    cur.pop_back();
    func(idx + 1, sum_cost, sum_p, sum_f, sum_s, sum_v);
}

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

    func(0, 0, 0, 0, 0, 0);

    if (min_cost == 1e9) {
        cout << -1 << '\n';
    } else {
        cout << min_cost << '\n';
        for (int x : ret) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}