#include <bits/stdc++.h>
using namespace std;

int r, c, alpha[26], max_cnt = -1e9;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
char arr[21][21];

void func(int depth, int y, int x) {
    max_cnt = max(max_cnt, depth);

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= r || nx < 0 || nx >= c || alpha[arr[ny][nx] - 'A']) continue;

        alpha[arr[ny][nx] - 'A'] = 1;
        func(depth + 1, ny, nx);
        alpha[arr[ny][nx] - 'A'] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    alpha[arr[0][0] - 'A'] = 1;
    func(1, 0, 0);

    cout << max_cnt;

    return 0;
}