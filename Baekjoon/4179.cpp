#include <iostream>
#include <string>
#include <queue>
using namespace std;

int r, c;
int cnt = 0;
string board[1001];
int board_fire[1001][1001];
int board_path[1001][1001];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> path;
queue<pair<int, int>> fire;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c;

    for(int i = 0; i < r; i++){
        cin >> board[i];
        fill(board_fire[i], board_fire[i] + c, -1);
        fill(board_path[i], board_path[i] + c, -1);
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(board[i][j] == 'J'){
                path.push(make_pair(i, j));
                board_path[i][j] = 0;
            }
                
            else if(board[i][j] == 'F'){
                fire.push(make_pair(i, j));
                board_fire[i][j] = 0;
            }
        }
    }

    while(!fire.empty()){
        int x = fire.front().first;
        int y = fire.front().second;
        fire.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= r || ny < 0 || ny >= c){
                continue;
            }

            if(board_fire[nx][ny] >= 0 || board[nx][ny] == '#')
                continue;

            board_fire[nx][ny] = board_fire[x][y] + 1;
            fire.push(make_pair(nx, ny));
        }
    }

    while(!path.empty()){
        int x = path.front().first;
        int y = path.front().second;
        path.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= r || ny < 0 || ny >= c){
                cout << board_path[x][y] + 1;
                return 0;
            }

            if(board_path[nx][ny] >= 0 || board[nx][ny] == '#')
                continue;

            if(board_fire[nx][ny] != -1 && board_fire[nx][ny] <= board_path[x][y] + 1){
                continue;
            }
            board_path[nx][ny] = board_path[x][y] + 1;
            path.push(make_pair(nx, ny));
            
        }
    }
    cout << "IMPOSSIBLE";
}
