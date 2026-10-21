#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check(vector<vector<int>>& board, int offset, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i + offset][j + offset] != 1) return false;
        }
    }
    return true;
}

vector<vector<int>> rotate(vector<vector<int>>& key) {
    int n = key.size();
    vector<vector<int>> temp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[j][n - i - 1] = key[i][j];
        }
    }
    return temp;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int n = lock.size();
    int m = key.size();

    int expand_n = n + 2 * (m - 1);
    int offset = m - 1;

    // 자물쇠 배열 확장, 가운데에 원본 배치
    vector<vector<int>> expanded(expand_n, vector<int>(expand_n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            expanded[i + offset][j + offset] = lock[i][j];
        }
    }

    // 열쇠 4방향으로 회전하면서, 모든 좌표에 대해 이동하면서 체크
    for (int i = 0; i < 4; i++) {
        for (int y = 0; y <= expand_n - m; y++) {
            for (int x = 0; x <= expand_n - m; x++) {
                // 열쇠 덧셈
                for (int r = 0; r < m; r++) {
                    for (int c = 0; c < m; c++) {
                        expanded[y + r][x + c] += key[r][c];
                    }
                }
                // 자물쇠 확인
                if (check(expanded, offset, n)) return true;

                // 원복
                for (int r = 0; r < m; r++) {
                    for (int c = 0; c < m; c++) {
                        expanded[y + r][x + c] -= key[r][c];
                    }
                }
            }
        }
        key = rotate(key);
    }

    // for (int i = 0; i < expanded.size(); i++) {
    //     for (int j = 0; j < expanded.size(); j++) {
    //         cout << expanded[i][j];
    //     }
    //     cout << '\n';
    // }

    return false;
}