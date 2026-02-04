#include <bits/stdc++.h>
using namespace std;

int h, w, ret[104][104];
char arr[104][104];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < h; i++) {
        int c_idx = -1;
        for (int j = 0; j < w; j++) {
            if (arr[i][j] == 'c') {
                c_idx = j;
            } else {
                if (c_idx == -1) {
                    ret[i][j] = -1;
                } else {
                    ret[i][j] = j - c_idx;
                }
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << ret[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}