#include <bits/stdc++.h>
using namespace std;

int n, dist[64][64][64], visited[64][64][64], a, b, c;
vector<int> v;
queue<tuple<int, int, int>> q;

int da[] = {-9, -9, -3, -3, -1, -1};
int db[] = {-3, -1, -9, -1, -9, -3};
int dc[] = {-1, -3, -1, -9, -3, -9};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    while (v.size() != 3) {
        v.push_back(0);
    }

    q.push(make_tuple(v[0], v[1], v[2]));

    while (q.size()) {
        tie(a, b, c) = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            int na = a + da[i];
            int nb = b + db[i];
            int nc = c + dc[i];

            if (na < 0) na = 0;
            if (nb < 0) nb = 0;
            if (nc < 0) nc = 0;

            if (!visited[na][nb][nc]) {
                q.push(make_tuple(na, nb, nc));
                visited[na][nb][nc] = 1;
                dist[na][nb][nc] = dist[a][b][c] + 1;
            }
        }
    }

    cout << dist[0][0][0] << '\n';

    return 0;
}