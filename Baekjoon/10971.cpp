#include <bits/stdc++.h>
using namespace std;

int n, arr[11][11], min_cost = 1e9, visited[11];

void func(int cur, int cnt, int cost) {
    if (cnt == n) {
        if (arr[cur][0] == 0) return;
        min_cost = min(min_cost, cost + arr[cur][0]);
        return;
    }

    if (cost > min_cost) return;

    for (int i = 1; i < n; i++) {
        if (visited[i] || arr[cur][i] == 0) continue;
        visited[i] = 1;
        func(i, cnt + 1, cost + arr[cur][i]);
        visited[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    // 0번 도시에서 시작하는 것으로 고정
    visited[0] = 1;
    func(0, 1, 0);

    cout << min_cost;

    return 0;
}