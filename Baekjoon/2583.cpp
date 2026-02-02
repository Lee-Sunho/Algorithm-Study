#include <bits/stdc++.h>
using namespace std;

int m, n, k, arr[104][104], visited[104][104], cnt;
vector<int> ans;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int dfs(int y, int x) {
    visited[y][x] = 1;
    int ret = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
        if (visited[ny][nx] == 0 && arr[ny][nx] == 0) {
            ret += dfs(ny, nx);
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n >> k;

    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int i = y1; i < y2; i++) {
            for (int j = x1; j < x2; j++) {
                arr[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == 0 && arr[i][j] == 0) {
                cnt++;
                ans.push_back(dfs(i, j));
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << cnt << '\n';
    for (int v : ans) {
        cout << v << ' ';
    }

    return 0;
}