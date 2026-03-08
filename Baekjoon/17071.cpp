#include <bits/stdc++.h>
using namespace std;

int n, k, visited[2][500004], flag;
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    visited[0][n] = 1;
    q.push(n);

    if (n == k) {
        cout << 0 << '\n';
        return 0;
    }

    int turn = 1;

    while (!q.empty()) {
        k += turn;

        if (k > 500000) break;
        if (visited[turn % 2][k]) {
            flag = 1;
            break;
        }

        int q_size = q.size();
        for (int i = 0; i < q_size; i++) {
            int x = q.front();
            q.pop();

            for (int nx : {x - 1, x + 1, x * 2}) {
                if (nx < 0 || nx > 500000) continue;

                if (!visited[turn % 2][nx]) {
                    visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1;
                    if (nx == k) {
                        flag = 1;
                        break;
                    }
                    q.push(nx);
                }
            }
            if (flag) break;
        }
        if (flag) break;
        turn++;
    }

    if (flag) {
        cout << turn << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}