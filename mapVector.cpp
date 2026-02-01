#include <bits/stdc++.h>
using namespace std;

const int N = 3;
int arr[N][N], visited[N][N];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void go(int y, int x) {
    visited[y][x] = 1;
    cout << y << " : " << x << '\n';

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

        if (arr[ny][nx] == 0) continue;

        if (visited[ny][nx]) continue;

        go(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    go(0, 0);

    return 0;
}