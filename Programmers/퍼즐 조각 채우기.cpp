#include <bits/stdc++.h>

using namespace std;

bool visited_g[54][54];
bool visited_p[54][54];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int n, idx_b, idx_p, ret;
vector<vector<pair<int, int>>> blank;
vector<vector<pair<int, int>>> puzzle;

void dfs(vector<vector<int>>& board, int y, int x, int target) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if (target == 0) {
            if (visited_g[ny][nx] || board[ny][nx] == 1) continue;
            visited_g[ny][nx] = true;
            blank[idx_b].push_back({ny, nx});
            dfs(board, ny, nx, target);
        } else {
            if (visited_p[ny][nx] || board[ny][nx] == 0) continue;
            visited_p[ny][nx] = true;
            puzzle[idx_p].push_back({ny, nx});
            dfs(board, ny, nx, target);
        }
    }
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    n = game_board.size();
    // 게임 보드 빈 칸 추출 dfs
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (game_board[i][j] == 0 && !visited_g[i][j]) {
                visited_g[i][j] = true;
                vector<pair<int, int>> v;
                v.push_back({i, j});
                blank.push_back(v);
                dfs(game_board, i, j, 0);
                idx_b++;
            }
        }
    }

    // 퍼즐 조각 추출 dfs
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (table[i][j] == 1 && !visited_p[i][j]) {
                visited_p[i][j] = true;
                vector<pair<int, int>> v;
                v.push_back({i, j});
                puzzle.push_back(v);
                dfs(table, i, j, 1);
                idx_p++;
            }
        }
    }

    vector<bool> found_b(blank.size(), false);
    vector<bool> found_p(puzzle.size(), false);

    // 게임 보드 칸 상대 좌표 기준 변환
    for (int i = 0; i < blank.size(); i++) {
        int min_y = 1e9, min_x = 1e9;
        for (int j = 0; j < blank[i].size(); j++) {
            pair<int, int> p = blank[i][j];
            min_y = min(min_y, p.first);
            min_x = min(min_x, p.second);
        }

        for (int j = 0; j < blank[i].size(); j++) {
            pair<int, int>& p = blank[i][j];
            p.first = p.first - min_y;
            p.second = p.second - min_x;
        }
        sort(blank[i].begin(), blank[i].end());
    }

    for (int i = 0; i < puzzle.size(); i++) {
        if (found_p[i]) continue;
        vector<pair<int, int>> cur_p = puzzle[i];

        for (int d = 0; d < 4; d++) {
            bool isFound = false;
            // 퍼즐 조각 4방향 회전
            for (int j = 0; j < cur_p.size(); j++) {
                int r = cur_p[j].first;
                int c = cur_p[j].second;
                cur_p[j].first = c;
                cur_p[j].second = n - r - 1;
            }

            // 상대 좌표로 전환
            vector<pair<int, int>> temp_p = cur_p;
            int min_y = 1e9, min_x = 1e9;
            for (int j = 0; j < temp_p.size(); j++) {
                min_y = min(min_y, temp_p[j].first);
                min_x = min(min_x, temp_p[j].second);
            }

            for (int j = 0; j < temp_p.size(); j++) {
                temp_p[j].first -= min_y;
                temp_p[j].second -= min_x;
            }

            sort(temp_p.begin(), temp_p.end());

            // 비교
            for (int j = 0; j < blank.size(); j++) {
                if (found_b[j]) continue;
                if (blank[j].size() != temp_p.size()) continue;
                bool flag = true;
                for (int k = 0; k < blank[j].size(); k++) {
                    if (blank[j][k].first != temp_p[k].first ||
                        blank[j][k].second != temp_p[k].second) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    ret += blank[j].size();
                    isFound = true;
                    // cout << "#" << i << ": " << ret << "\n";
                    found_b[j] = true;
                    found_p[i] = true;
                    break;
                }
            }
            if (isFound) break;
        }
    }

    // for (int i = 0; i < blank.size(); i++) {
    //     for (int j = 0; j < blank[i].size(); j++) {
    //         cout << blank[i][j].first << "," << blank[i][j].second << " ";
    //     }
    //     cout << '\n';
    // }
    // for (int i = 0; i < puzzle.size(); i++) {
    //     for (int j = 0; j < puzzle[i].size(); j++) {
    //         cout << puzzle[i][j].first << "," << puzzle[i][j].second << " ";
    //     }
    //     cout << '\n';
    // }
    return ret;
}