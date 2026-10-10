#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Turtle {
    int id;
    int r;
    int c;
    bool isAlive;
    bool isEscaped;
    int escape_turn;
};

struct Volcano {
    int r;
    int c;
    int p;
    int cur_p;
    bool ing;
};

// 우하좌상
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int n, m, k, turn, INF = 1e9;
int board[21][21];
bool hasTurtle[21][21];
vector<Turtle> turtles;
vector<Volcano> volcanos;

vector<vector<int>> bfs(int y, int x) {
    queue<pair<int, int>> q;
    vector<vector<int>> dist(21, vector<int>(21, INF));

    q.push({n - 1, n - 1});
    dist[n - 1][n - 1] = 0;

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if (board[ny][nx] || dist[ny][nx] != INF) continue;
            if (hasTurtle[ny][nx] && !(ny == y && nx == x)) continue;  // 다른 거북이

            q.push({ny, nx});
            dist[ny][nx] = dist[cy][cx] + 1;
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        turtles.push_back({i, r, c, true, false, -1});
        hasTurtle[r][c] = true;
    }

    for (int i = 0; i < k; i++) {
        int r, c, p;
        cin >> r >> c >> p;
        volcanos.push_back({r, c, p, 0, false});
    }

    while (turn < 100) {
        turn++;

        // 1단계: 바다거북 이동
        for (auto& turtle : turtles) {
            if (!turtle.isAlive || turtle.isEscaped) continue;

            int r = turtle.r;
            int c = turtle.c;

            vector<vector<int>> dist = bfs(r, c);

            if (dist[r][c] != INF) {
                for (int i = 0; i < 4; i++) {
                    int ny = r + dy[i];
                    int nx = c + dx[i];

                    if (ny < 0 || ny >= n || nx < 0 || nx >= n || board[ny][nx] > 0) continue;
                    if (hasTurtle[ny][nx]) continue;
                    if (dist[ny][nx] != dist[r][c] - 1) continue;

                    hasTurtle[r][c] = false;
                    hasTurtle[ny][nx] = true;
                    turtle.r = ny;
                    turtle.c = nx;

                    if (turtle.r == n - 1 && turtle.c == n - 1) {
                        turtle.isEscaped = true;
                        turtle.escape_turn = turn;
                        hasTurtle[turtle.r][turtle.c] = false;
                    }
                    break;
                }
            }
        }

        // 2단계: 화산 압력 증가
        for (auto& vol : volcanos) {
            vol.cur_p += 10;
        }

        // 3단계: 화산 분출 및 연쇄 반응
        vector<vector<int>> heat(21, vector<int>(21, 0));
        bool flag = true;

        while (flag) {
            flag = false;
            for (auto& vol : volcanos) {
                if (vol.ing) continue;
                if (vol.cur_p + heat[vol.r][vol.c] >= vol.p) {
                    vol.ing = true;
                    flag = true;

                    // 열기 전파
                    heat[vol.r][vol.c] += vol.p;

                    for (int i = 0; i < 4; i++) {
                        int nh = vol.p / 2;
                        int nr = vol.r + dy[i];
                        int nc = vol.c + dx[i];

                        while (nr >= 0 && nr < n && nc >= 0 && nc < n && board[nr][nc] != 1 &&
                               nh > 0) {
                            heat[nr][nc] += nh;
                            nh /= 2;
                            nr += dy[i];
                            nc += dx[i];
                        }
                    }
                }
            }
        }

        // 바다거북 화석화
        for (auto& turtle : turtles) {
            if (!turtle.isAlive || turtle.isEscaped) continue;
            if (heat[turtle.r][turtle.c] >= 20) {
                turtle.isAlive = false;
                board[turtle.r][turtle.c] = 2;
                hasTurtle[turtle.r][turtle.c] = false;
            }
        }

        // 환경 초기화
        for (auto& vol : volcanos) {
            if (vol.ing) {
                vol.cur_p = 0;
                vol.ing = false;
            }
        }
    }

    for (auto& turtle : turtles) {
        cout << turtle.escape_turn << '\n';
    }

    return 0;
}