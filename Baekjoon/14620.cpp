#include <bits/stdc++.h>
using namespace std;

int n, arr[11][11], visited[11][11], min_ret = 1e9;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void func(int cnt, int sum) {
    if (cnt == 3) {
        min_ret = min(min_ret, sum);
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool flag = true;

            if (visited[i][j]) continue;

            for (int k = 0; k < 4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];

                if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) {
                    flag = false;
                    break;
                };
            }

            if (flag) {
                int cost = arr[i][j];
                visited[i][j] = 1;
                for (int k = 0; k < 4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];

                    visited[ny][nx] = 1;
                    cost += arr[ny][nx];
                }

                func(cnt + 1, sum + cost);

                visited[i][j] = 0;
                for (int k = 0; k < 4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    visited[ny][nx] = 0;
                }
            }
        }
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

    func(0, 0);

    cout << min_ret;
    return 0;
}