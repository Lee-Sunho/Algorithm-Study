#include <iostream>
#include <queue>
using namespace std;

int m, n;
int board[1001][1001];
int day_cnt = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 1){
                q.push(make_pair(i, j));
            }
        }
    }

    while(!q.empty()){
        int cnt = q.size();

        for(int i = 0; i < cnt; i++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int j = 0; j < 4; j++){
                int nx = x + dx[j];
                int ny = y + dy[j];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                    continue;
                }

                if(board[nx][ny] == 0){
                    board[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
        day_cnt++;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 0){
                cout << "-1";
                return 0;
            }
        }
    }
    cout << day_cnt - 1;
}
