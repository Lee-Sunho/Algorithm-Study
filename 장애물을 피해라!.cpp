#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int h, w, k, ans;

int dy[] = {1, -2};
int dx[] = {1, 1};

int wall[24][3];

void func(int x, int y) {
    if (y <= 0 || y >= h) return;

    if (x == w) {
        ans++;
        return;
    }

    for (int i = 0; i < 2; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny <= 0 || ny >= h) continue;

        bool flag = true;
        for (int j = 0; j < k; j++) {
            if (nx == wall[j][0]) {
                if (ny <= wall[j][1] || ny >= wall[j][2]) flag = false;
            }
        }

        if (flag) {
            func(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w;
    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> wall[i][0] >> wall[i][1] >> wall[i][2];
    }

    func(0, h / 2);

    cout << ans;

    return 0;
}
