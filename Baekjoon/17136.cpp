#include <bits/stdc++.h>
using namespace std;

/*
    1 x 1 ~ 5 x 5 크기의 색종이 각각 5개씩 존재.
    1이 적힌 모든 칸을 붙이는데 필요한 색종이의 최소 개수 출력, 다 못 붙이는 경우 -1 출력

    완전탐색하며 백트래킹. 가장 큰 색종이부터 붙이기.
*/

int board[11][11];
int min_ret = 1e9;
int rest[6] = {0, 5, 5, 5, 5, 5};
int n = 10;

bool check(int y, int x, int s) {
    if (rest[s] == 0) return false;
    if (y + s > n || x + s > n) return false;  // 9에서 1칸짜리 붙이려면 10까지는 포함해야함.

    for (int i = y; i < y + s; i++) {
        for (int j = x; j < x + s; j++) {
            if (board[i][j] == 0) return false;
        }
    }
    return true;
}

void post(int y, int x, int s, int num) {
    for (int i = y; i < y + s; i++) {
        for (int j = x; j < x + s; j++) {
            board[i][j] = num;
        }
    }
}

void dfs(int y, int x, int cnt) {
    if (cnt >= min_ret) return;
    if (x == n) {
        dfs(y + 1, 0, cnt);
        return;
    }
    if (y == n) {
        min_ret = min(cnt, min_ret);
        return;
    }
    if (board[y][x] == 0) {
        dfs(y, x + 1, cnt);
        return;
    }

    for (int s = 5; s >= 1; s--) {
        if (check(y, x, s)) {
            rest[s]--;
            post(y, x, s, 0);        // 색종이 붙이기
            dfs(y, x + s, cnt + 1);  // s만큼 건너뛰기
            post(y, x, s, 1);        // 원복
            rest[s]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> board[i][j];
        }
    }

    dfs(0, 0, 0);

    // 중간에 색종이가 모자라서 재귀가 끊기는 경우 y == x에 도달할 수 없어서 1e9로 유지됨
    if (min_ret == 1e9)
        cout << -1;
    else
        cout << min_ret;
    return 0;
}
