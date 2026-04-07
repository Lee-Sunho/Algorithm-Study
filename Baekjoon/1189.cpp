#include <bits/stdc++.h>
using namespace std;

int r, c, k, visited[7][7], ret = 0;
char arr[7][7];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void func(int y, int x, int dist) {
    if (dist == k) {
        if (y == 1 && x == c) ret++;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 1 || ny > r || nx < 1 || nx > c || visited[ny][nx] || arr[ny][nx] == 'T') continue;
        visited[ny][nx] = 1;
        func(ny, nx, dist + 1);
        visited[ny][nx] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c >> k;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> arr[i][j];
        }
    }

    visited[r][1] = 1;
    func(r, 1, 1);

    cout << ret;

    return 0;
}