#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Point {
    int y;
    int x;
};

int n, r, c, d, cnt_sea;
int board[54][54];
bool visited[54][54];
vector<Point> res;

// 1-상, 2-하, 3-좌, 4-우
int dy[] = {0, -1, 1, 0, 0};
int dx[] = {0, 0, 0, -1, 1};
int L90[] = {0, 3, 4, 2, 1};  // 좌회전: 상→좌, 하→우, 좌→하, 우→상
int R90[] = {0, 4, 3, 1, 2};  // 우회전: 상→우, 하→좌, 좌→상, 우→하
int opp[] = {0, 2, 1, 4, 3};  // 180도

queue<Point> q;

bool step1(int& y, int& x) {
    int dir[] = {d, L90[d], R90[d], opp[d]};

    for (int i = 0; i < 4; i++) {
        int nd = dir[i];
        int ny = y + dy[nd];
        int nx = x + dx[nd];

        if (ny < 1 || ny > n || nx < 1 || nx > n) continue;
        if (board[ny][nx] != 0 || visited[ny][nx]) continue;

        visited[ny][nx] = true;
        res.push_back({ny, nx});
        y = ny;
        x = nx;
        d = nd;
        return true;
    }
    return false;
}

void bfs(int sy, int sx, int dist[54][54]) {
    memset(dist, -1, sizeof(int) * 54 * 54);
    queue<Point> q;
    dist[sy][sx] = 0;
    q.push({sy, sx});
    while (!q.empty()) {
        int cy = q.front().y, cx = q.front().x;
        q.pop();
        for (int i = 1; i <= 4; i++) {
            int ny = cy + dy[i], nx = cx + dx[i];
            if (ny < 1 || ny > n || nx < 1 || nx > n) continue;
            if (board[ny][nx] == 1 || dist[ny][nx] != -1) continue;
            dist[ny][nx] = dist[cy][cx] + 1;
            q.push({ny, nx});
        }
    }
}

void step2(int& y, int& x) {
    int dist[54][54], dist2[54][54];
    bfs(y, x, dist);

    int best = 1e9;
    Point target = {-1, -1};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i][j] != 0 || visited[i][j] || dist[i][j] == -1) continue;
            if (dist[i][j] < best) {
                best = dist[i][j];
                target = {i, j};
            }
        }
    }

    bfs(target.y, target.x, dist2);
    int order[] = {3, 2, 4, 1};  // 좌, 하, 우, 상
    while (!(y == target.y && x == target.x)) {
        for (int i = 0; i < 4; i++) {
            int nd = order[i];
            int ny = y + dy[nd];
            int nx = x + dx[nd];

            if (ny < 1 || ny > n || nx < 1 || nx > n) continue;
            if (dist2[ny][nx] == -1 || dist2[ny][nx] != dist2[y][x] - 1) continue;
            y = ny;
            x = nx;
            d = nd;
            break;
        }
    }
    visited[y][x] = true;
    res.push_back({y, x});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> r >> c >> d;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) cnt_sea++;
        }
    }

    visited[r][c] = true;
    res.push_back({r, c});
    int y = r;
    int x = c;

    while (1) {
        while (step1(y, x));
        if (res.size() == cnt_sea) break;
        step2(y, x);
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i].y << ' ' << res[i].x << '\n';
    }

    return 0;
}