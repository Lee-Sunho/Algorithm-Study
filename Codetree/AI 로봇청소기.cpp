#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Cleaner {
    int r;
    int c;
};

// 우하좌상
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int N, K, L, INF = 1e9;
int board[34][34];
bool hasCleaner[34][34];
vector<Cleaner> vc;

void cleanup(int y, int x) {
    if (board[y][x] == -1) return;
    board[y][x] = max(0, board[y][x] - 20);
}

vector<vector<int>> bfs(int y, int x) {
    queue<pair<int, int>> q;
    vector<vector<int>> dist(34, vector<int>(34, 1e9));

    q.push({y, x});
    dist[y][x] = 0;

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 1 || ny > N || nx < 1 || nx > N || dist[ny][nx] != INF) continue;
            if (board[ny][nx] == -1 || hasCleaner[ny][nx]) continue;

            q.push({ny, nx});
            dist[ny][nx] = dist[cy][cx] + 1;
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K >> L;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        vc.push_back({r, c});
        hasCleaner[r][c] = true;
    }

    while (L--) {
        // 1. 청소기마다 BFS를 돌려서 가장 가까운 오염된 격자로 이동
        // 행 번호 -> 열 번호 오름차순 우선순위
        for (auto& c : vc) {
            pair<int, int> next = {-1, -1};
            int min_dist = INF;

            vector<vector<int>> dist = bfs(c.r, c.c);
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (board[i][j] > 0 && dist[i][j] < min_dist) {
                        next.first = i;
                        next.second = j;
                        min_dist = dist[i][j];
                    }
                }
            }

            if (next.first != -1 && next.second != -1) {
                hasCleaner[c.r][c.c] = false;
                c.r = next.first;
                c.c = next.second;
                hasCleaner[c.r][c.c] = true;
            }
        }

        // 2. 청소
        // 각 칸에서 우, 하, 좌, 상 방향으로 탐색하며 한 번에 청소할 수 있는 먼지 합 구하기
        for (auto& cc : vc) {
            int r = cc.r;
            int c = cc.c;

            vector<int> sum(4, 0);
            for (int d = 0; d < 4; d++) {
                sum[d] += min(20, max(0, board[r][c]));                  // 현재 칸
                sum[d] += min(20, max(0, board[r + dy[d]][c + dx[d]]));  // 바라보고 있는 칸
                sum[d] += min(20, max(0, board[r + dy[(d + 3) % 4]][c + dx[(d + 3) % 4]]));  // 왼쪽
                sum[d] +=
                    min(20, max(0, board[r + dy[(d + 1) % 4]][c + dx[(d + 1) % 4]]));  // 오른쪽
            }

            int dir;
            int max_sum = -1e9;
            for (int i = 0; i < 4; i++) {
                if (sum[i] > max_sum) {
                    dir = i;
                    max_sum = sum[i];
                }
            }

            // 정해진 방향으로 청소
            cleanup(r, c);
            cleanup(r + dy[dir], c + dx[dir]);
            cleanup(r + dy[(dir + 3) % 4], c + dx[(dir + 3) % 4]);
            cleanup(r + dy[(dir + 1) % 4], c + dx[(dir + 1) % 4]);
        }

        // 3. 먼지 축적
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (board[i][j] > 0) board[i][j] += 5;
            }
        }

        // 4. 먼지 확산 (동시 확산)
        vector<vector<int>> temp(34, vector<int>(34, 0));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                temp[i][j] = board[i][j];
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (board[i][j] == 0) {
                    int sum = 0;
                    for (int d = 0; d < 4; d++) {
                        int ny = i + dy[d];
                        int nx = j + dx[d];

                        if (ny < 1 || ny > N || nx < 1 || nx > N || board[ny][nx] == -1) continue;
                        sum += board[ny][nx];
                    }

                    temp[i][j] = sum / 10;
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                board[i][j] = temp[i][j];
            }
        }

        // 5. 출력
        int ret = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (board[i][j] > 0) ret += board[i][j];
            }
        }
        cout << ret << '\n';
        if (ret == 0) break;
    }
    return 0;
}