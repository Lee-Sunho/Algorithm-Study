#include <bits/stdc++.h>
using namespace std;

int n, m, arr[54][54], min_cnt = 1e9;
vector<pair<int, int>> chk;
vector<pair<int, int>> home;
vector<pair<int, int>> selected;

void solve(int start) {
    if (selected.size() == m) {
        int sum = 0;
        for (auto h : home) {
            int min_dist = 1e9;
            for (auto ch : selected) {
                int dist = abs(h.first - ch.first) + abs(h.second - ch.second);
                min_dist = min(min_dist, dist);
            }
            sum += min_dist;
        }
        min_cnt = min(min_cnt, sum);
        return;
    }

    for (int i = start + 1; i < chk.size(); i++) {
        selected.push_back(chk[i]);
        solve(i);
        selected.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                home.push_back({i, j});
            } else if (arr[i][j] == 2) {
                chk.push_back({i, j});
            }
        }
    }

    solve(-1);

    cout << min_cnt << '\n';

    return 0;
}