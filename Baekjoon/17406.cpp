#include <bits/stdc++.h>
using namespace std;

int n, m, k, ret = 1e9;
int arr[104][104], temp[104][104], visited[104];
struct A {
    int r;
    int c;
    int s;
};
vector<A> v;
vector<int> v_idx;

void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            temp[i][j] = arr[i][j];
        }
    }
}

void rotate(int r, int c, int s) {
    for (int layer = 1; layer <= s; layer++) {
        int top = r - layer;
        int right = c + layer;
        int bottom = r + layer;
        int left = c - layer;

        int prev = temp[top][left];
        for (int i = top; i < bottom; i++) temp[i][left] = temp[i + 1][left];
        for (int i = left; i < right; i++) temp[bottom][i] = temp[bottom][i + 1];
        for (int i = bottom; i > top; i--) temp[i][right] = temp[i - 1][right];
        for (int j = right; j > left + 1; j--) temp[top][j] = temp[top][j - 1];
        temp[top][left + 1] = prev;
    }
}

int calc() {
    int ret = 1e9;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= m; j++) {
            sum += temp[i][j];
        }
        ret = min(ret, sum);
    }
    return ret;
}

void solve(int cnt) {
    if (cnt == k) {
        init();
        for (int idx : v_idx) {
            rotate(v[idx].r, v[idx].c, v[idx].s);
        }
        ret = min(ret, calc());
        return;
    }

    for (int i = 0; i < k; i++) {
        if (visited[i]) continue;
        v_idx.push_back(i);
        visited[i] = 1;
        solve(cnt + 1);
        v_idx.pop_back();
        visited[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, b, c});
    }

    solve(0);

    cout << ret;

    return 0;
}
