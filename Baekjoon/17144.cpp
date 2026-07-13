#include <bits/stdc++.h>
using namespace std;

int r, c, t, ret;
int arr[54][54];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> clean;

void clear() {
    int uy = clean[0].first;
    for (int i = uy - 1; i > 0; i--) arr[i][0] = arr[i - 1][0];
    for (int i = 0; i < c - 1; i++) arr[0][i] = arr[0][i + 1];
    for (int i = 0; i < uy; i++) arr[i][c - 1] = arr[i + 1][c - 1];
    for (int i = c - 1; i > 1; i--) arr[uy][i] = arr[uy][i - 1];
    arr[uy][1] = 0;

    int dy = clean[1].first;
    for (int i = dy + 1; i < r - 1; i++) arr[i][0] = arr[i + 1][0];
    for (int i = 0; i < c - 1; i++) arr[r - 1][i] = arr[r - 1][i + 1];
    for (int i = r - 1; i > dy; i--) arr[i][c - 1] = arr[i - 1][c - 1];
    for (int i = c - 1; i > 1; i--) arr[dy][i] = arr[dy][i - 1];
    arr[dy][1] = 0;
}

void func() {
    queue<pair<int, int>> q;
    int temp[54][54];
    memset(temp, 0, sizeof(temp));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] != -1 && arr[i][j] != 0) {
                q.push({i, j});
            }
        }
    }

    while (q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        int spread = arr[y][x] / 5;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= r || nx < 0 || nx >= c || arr[ny][nx] == -1) continue;
            temp[ny][nx] += spread;
            arr[y][x] -= spread;
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            arr[i][j] += temp[i][j];
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c >> t;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == -1) {
                clean.push_back({i, j});
            }
        }
    }

    while (t--) {
        func();
        clear();
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] > 0) ret += arr[i][j];
        }
    }

    cout << ret;

    return 0;
}
