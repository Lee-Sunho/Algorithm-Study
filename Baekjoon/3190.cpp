#include <bits/stdc++.h>
using namespace std;

int n, k, L, cnt;
int arr[104][104];
queue<pair<int, char>> turning;
int direction = 0;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

bool isAlive = true;
deque<pair<int, int>> snake;

void go() {
    snake.push_front(
        {snake[0].first + dy[direction], snake[0].second + dx[direction]});  // 머리 이동
    pair<int, int> head = snake[0];

    if (head.first < 1 || head.first > n || head.second < 1 || head.second > n ||
        arr[head.first][head.second] == 2) {
        isAlive = false;
        return;
    }

    if (arr[head.first][head.second] != 1) {
        arr[snake.back().first][snake.back().second] = 0;
        snake.pop_back();
    }
    arr[head.first][head.second] = 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int y, x;
        cin >> y >> x;
        arr[y][x] = 1;  // 사과
    }
    cin >> L;
    for (int i = 0; i < L; i++) {
        int a;
        char c;
        cin >> a >> c;
        turning.push({a, c});
    }

    arr[1][1] = 2;  // 뱀
    snake.push_back({1, 1});

    while (1) {
        cnt++;
        go();

        if (!isAlive) break;

        if (turning.size() && turning.front().first == cnt) {
            if (turning.front().second == 'D')
                direction = (direction + 1) % 4;
            else
                direction = (direction + 3) % 4;
            turning.pop();
        }
    }

    cout << cnt;

    return 0;
}
