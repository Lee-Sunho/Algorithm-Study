#include <queue>
#include <vector>

using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int visited[104][104];
queue<pair<int, int>> q;

int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();

    q.push({0, 0});
    visited[0][0] = 1;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if (y == n - 1 && x == m - 1) return visited[y][x];

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (visited[ny][nx] || maps[ny][nx] == 0) continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }

    return -1;
}