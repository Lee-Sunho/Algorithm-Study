#include <bits/stdc++.h>
using namespace std;

int n, m, arr[15][15], temp[15][15], max_cnt;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> v;

void virus(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (temp[ny][nx] == 0) {
            temp[ny][nx] = 2;
            virus(ny, nx);
        }
    }
}

int countZero() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp[i][j] == 0) cnt++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) v.push_back({i, j});
        }
    }

    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            for (int k = j + 1; k < v.size(); k++) {
                arr[v[i].first][v[i].second] = 1;
                arr[v[j].first][v[j].second] = 1;
                arr[v[k].first][v[k].second] = 1;

                memcpy(temp, arr, sizeof(arr));
                for (int r = 0; r < n; r++) {
                    for (int c = 0; c < m; c++) {
                        if (arr[r][c] == 2) {
                            virus(r, c);
                        }
                    }
                }
                max_cnt = max(max_cnt, countZero());

                arr[v[i].first][v[i].second] = 0;
                arr[v[j].first][v[j].second] = 0;
                arr[v[k].first][v[k].second] = 0;
            }
        }
    }

    cout << max_cnt << '\n';

    return 0;
}