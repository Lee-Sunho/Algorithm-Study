#include <string>
#include <vector>

using namespace std;

int dh[] = {0, 1, -1, 0};
int dw[] = {1, 0, 0, -1};

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int n = board.size();

    for (int i = 0; i < 4; i++) {
        int nh = h + dh[i];
        int nw = w + dw[i];

        if (nh < 0 || nh >= n || nw < 0 || nw >= n) continue;

        if (board[h][w] == board[nh][nw]) answer++;
    }
    return answer;
}