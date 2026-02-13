#include <bits/stdc++.h>
using namespace std;

int n, l, r, arr[54][54], visited[54][54], cnt, sum;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> v;

void dfs(int y, int x) {
    visited[y][x] = 1;
    v.push_back({y, x});
    sum += arr[y][x];

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx] == 1) continue;
        if (abs(arr[y][x] - arr[ny][nx]) >= l && abs(arr[y][x] - arr[ny][nx]) <= r) {
            dfs(ny, nx);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    while (1) {
        bool flag = 0;
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 0) {
                    dfs(i, j);
                    if (v.size() >= 2) {
                        int ret = sum / v.size();
                        for (auto p : v) {
                            arr[p.first][p.second] = ret;
                            flag = 1;
                        }
                    }
                    sum = 0;
                    v.clear();
                }
            }
        }

        if (!flag) break;
        cnt++;
    }

    cout << cnt << '\n';

    return 0;
}
