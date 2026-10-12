#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

struct Box {
    int id, r, c, w, startTurn;
    int still;  // 연속으로 이동하지 못한 턴 수
    bool on, broken;
    int done;  // 적재 턴
};

int N, B;
int N, B;
int board[10][10];
int occ[10][10];  // 칸 위 택배 인덱스, 없으면 -1
// 1:우 2:상 3:좌 4:하
int dr[] = {0, 0, -1, 0, 1};
int dc[] = {0, 1, 0, -1, 0};
vector<Box> boxes;

bool lighter(int i, int j) {
    if (boxes[i].w != boxes[j].w) return boxes[i].w < boxes[j].w;
    return boxes[i].id < boxes[j].id;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    cin >> B;
    for (int i = 0; i < B; i++) {
        int t, r, c, w;
        cin >> t >> r >> c >> w;
        boxes.push_back({i + 1, r, c, w, t, 0, false, false, 0});
    }
    memset(occ, -1, sizeof(occ));

    int remain = B;
    for (int turn = 1; turn <= 100 && remain > 0; turn++) {
        // 1. 이동
        vector<int> act;
        for (int i = 0; i < B; i++)
            if (boxes[i].on) act.push_back(i);

        vector<int> tr(B), tc(B);
        vector<bool> can(B, false);
        int win[10][10];
        memset(win, -1, sizeof(win));

        // 목표 칸 계산 + 칸마다 (무게, id)가 가장 작은 택배 찾기 - 규칙 2
        for (int i : act) {
            int d = board[boxes[i].r][boxes[i].c];
            tr[i] = boxes[i].r + dr[d];
            tc[i] = boxes[i].c + dc[d];
            int& w = win[tr[i]][tc[i]];
            if (w == -1 || lighter(i, w)) w = i;
        }
        // 목표 칸에서 우선 순위인 인덱스들 추출
        for (int i : act) can[i] = (win[tr[i]][tc[i]] == i);

        // 규칙 1 : 목표 칸의 기존 택배가 못 움직이면 나도 못 움직임
        bool changed = true;
        while (changed) {  // 변화가 없을때까지 반복
            changed = false;
            for (int i : act) {
                if (!can[i]) continue;
                int j = occ[tr[i]][tc[i]];
                if (j != -1 && !can[j]) {
                    can[i] = false;
                    changed = true;
                }
            }
        }

        // 이동 적용: 원래 칸을 모두 비우고, 그 다음 새 칸을 채움.
        for (int i : act)
            if (can[i]) occ[boxes[i].r][boxes[i].c] = -1;
        for (int i : act) {
            if (can[i]) {
                boxes[i].r = tr[i];
                boxes[i].c = tc[i];
                boxes[i].still = 0;
            } else {
                boxes[i].still++;
            }
        }

        // 2. 적재 및 파손
        for (int i : act) {
            if (board[boxes[i].r][boxes[i].c] == 9) {
                boxes[i].on = false;
                boxes[i].done = turn;
                remain--;
            } else {
                if (can[i]) occ[boxes[i].r][boxes[i].c] = i;
                if (boxes[i].still >= 3) boxes[i].broken = true;
            }
        }

        // 3. 택배 올리기
        for (int i = 0; i < B; i++) {
            if (boxes[i].startTurn != turn) continue;
            if (occ[boxes[i].r][boxes[i].c] != -1) {
                boxes[i].startTurn = turn + 1;
                continue;
            }
            boxes[i].on = true;
            occ[boxes[i].r][boxes[i].c] = i;
        }
    }

    for (int i = 0; i < B; i++) {
        cout << (boxes[i].broken ? -boxes[i].done : boxes[i].done);
        cout << (i + 1 < B ? ' ' : '\n');
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}