#include <bits/stdc++.h>
using namespace std;

char board[12][6];
bool visited[12][6];

int answer = 0;
bool is_puyo = true;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void puyo(int y, int x) {
  queue<pair<int, int>> q;
  vector<pair<int, int>> tmp;

  q.push({y, x});
  visited[y][x] = true;
  char target = board[y][x];

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = cur.first + dy[i];
      int nx = cur.second + dx[i];

      if (nx < 0 || nx >= 6 || ny < 0 || ny >= 12) continue;

      if (!visited[ny][nx] && board[ny][nx] == target) {
        q.push({ny, nx});
        tmp.push_back({ny, nx});
        visited[ny][nx] = true;
      }
    }
  }

  if (tmp.size() >= 4) {
    for (auto c : tmp) {
      board[c.first][c.second] = '.';
    }
    is_puyo = true;
    return;
  }
  is_puyo = false;
}

void puyo_drop() {
  for (int col = 0; col < 6; col++) {
    int bottom = 11;
    for (int row = bottom; row > 0; row--) {
      if (board[row][col] == '.') continue;
      board[bottom][col] = board[row][col];
      bottom--;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 6; j++) {
      cin >> board[i][j];
    }
  }

  while (is_puyo) {
    for (int y = 0; y < 12; y++) {
      for (int x = 0; x < 6; x++) {
        if (!visited[y][x] && board[y][x] != '.') {
          puyo(y, x);
        }
      }
    }
    puyo_drop();
    answer++;
    for (int y = 0; y < 12; y++) {
      for (int x = 0; x < 6; x++) {
        visited[y][x] = false;
      }
    }
  }
  cout << answer;
}
