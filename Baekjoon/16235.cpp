/*
    모든 칸 양분 5
    한 칸에 여러 개 나무 가능, 나이가 어린 나무부터 양분을 먹음, 나이만큼 먹지 못할 시 바로 죽음.
    봄: 자신의 나이 만큼 양분을 먹고 나이 ++
    여름: 봄에 죽은 나무의 나이를 2로 나눈 값 만큼 양분으로 추가됨.
    가을: 나이가 5의 배수인 나무가 번식. 주변 8칸에 나이가 1인 나무 추가
    겨울: 각 칸에 A[r][c]만큼의 양분이 추가됨.

    K년이 지난 후 상도의 땅에 살아있는 나무의 개수 출력
*/

#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int age;
    int y;
    int x;
};

int n, m, k;
int A[54][54];
int soil[54][54];    // 양분
vector<Tree> trees;  // 나무 정보

int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool cmp(const Tree& a, const Tree& b) {
    if (a.age == b.age) {
        if (a.y == b.y) {
            return a.x < b.x;
        }
        return a.y < b.y;
    }
    return a.age < b.age;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    // 1-based index
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }

    fill(&soil[0][0], &soil[0][0] + 54 * 54, 5);

    // 나무 관리를 어떻게 하는게 좋을까? 최소힙? 근데 나무 개수 그렇게 많지 않음.
    // struct 최소힙 어케 만들지. -> 너무 복잡..
    // struct vector로 관리하고 매 턴마다 나이 오름차순으로 sort.

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        trees.push_back({z, x, y});
    }

    // k만큼 사계절 루프
    while (k--) {
        sort(trees.begin(), trees.end(), cmp);  // 나이 순 오름차순

        // 봄.
        vector<Tree> temp;
        vector<Tree> dead;
        for (int i = 0; i < trees.size(); i++) {
            int r = trees[i].y;
            int c = trees[i].x;
            int age = trees[i].age;

            if (soil[r][c] >= age) {
                soil[r][c] -= age;
                age++;
                temp.push_back({age, r, c});
            } else {
                dead.push_back({age, r, c});
            }
        }
        trees = temp;

        // 여름
        for (int i = 0; i < dead.size(); i++) {
            int r = dead[i].y;
            int c = dead[i].x;
            int value = dead[i].age / 2;

            soil[r][c] += value;
        }

        // 가을
        vector<Tree> newTree;
        for (int i = 0; i < trees.size(); i++) {
            int r = trees[i].y;
            int c = trees[i].x;
            int age = trees[i].age;

            if (age % 5 == 0) {
                for (int d = 0; d < 8; d++) {
                    int nr = r + dy[d];
                    int nc = c + dx[d];

                    if (nr < 1 || nr > n || nc < 1 || nc > n) continue;
                    newTree.push_back({1, nr, nc});
                }
            }
        }

        for (Tree t : newTree) trees.push_back(t);

        // 겨울
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                soil[i][j] += A[i][j];
            }
        }
    }

    // int ret = 0;
    // for (int i = 0; i < trees.size(); i++) {
    //     if (trees[i].isAlive) ret++;
    //     // cout << trees[i].isAlive << ' ';
    //     // cout << trees[i].age << '\n';
    // }

    cout << trees.size();

    return 0;
}
