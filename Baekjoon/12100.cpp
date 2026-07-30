#include <bits/stdc++.h>
using namespace std;

int n, init_arr[21][21], arr[21][21], ret = -1;
char moving[] = {'U', 'R', 'D', 'L'};
vector<char> v;

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = init_arr[i][j];
        }
    }
}

void rotate() {
    int temp[21][21];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[j][n - 1 - i] = arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = temp[i][j];
        }
    }
}

void go_up() {
    for (int i = 0; i < n; i++) {
        vector<int> temp, merged;
        for (int j = 0; j < n; j++) {
            if (arr[j][i] != 0) temp.push_back(arr[j][i]);
        }

        for (int j = 0; j < temp.size(); j++) {
            if (merged.empty())
                merged.push_back(temp[j]);
            else if (temp[j] == merged[merged.size() - 1]) {
                merged[merged.size() - 1] *= 2;
                if (j + 1 < temp.size()) merged.push_back(temp[j + 1]);
                j++;
            } else {
                merged.push_back(temp[j]);
            }
        }

        while (merged.size() < n) {
            merged.push_back(0);
        }

        for (int j = 0; j < n; j++) {
            arr[j][i] = merged[j];
        }
    }
}

int move() {
    int max_num = -1;
    init();

    for (char c : v) {
        switch (c) {
            case 'U':
                go_up();
                break;

            case 'R':
                for (int i = 0; i < 3; i++) rotate();
                go_up();
                rotate();
                break;

            case 'D':
                for (int i = 0; i < 2; i++) rotate();
                go_up();
                for (int i = 0; i < 2; i++) rotate();
                break;

            case 'L':
                rotate();
                go_up();
                for (int i = 0; i < 3; i++) rotate();
                break;

            default:
                break;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            max_num = max(max_num, arr[i][j]);
        }
    }

    return max_num;
}

void dfs(int cnt) {
    if (cnt == 5) {
        ret = max(ret, move());
        return;
    }

    for (int i = 0; i < 4; i++) {
        v.push_back(moving[i]);
        dfs(cnt + 1);
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> init_arr[i][j];
        }
    }

    dfs(0);

    cout << ret;

    return 0;
}