#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[8][8] = {0};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> v;
int res = 999;

vector<pair<int, int>> extend(int cur, int dir){
    vector<pair<int, int>> change;
    int x = v[cur].first;
    int y = v[cur].second;

    if(board[x][y] == 1){
        int temp_x = x;
        int temp_y = y;
        while(1){
            int nx = temp_x + dx[dir];
            int ny = temp_y + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 6)
                break;
            
            if(board[nx][ny] == 0){
                board[nx][ny] = 7;
                change.push_back({nx, ny});
            }
            temp_x = nx;
            temp_y = ny;
        }
    }

    else if(board[x][y] == 2){
        for(int i = 0; i <= 2; i += 2){
            int temp_x = x;
            int temp_y = y;
            while(1){
                int nx = temp_x + dx[(dir + i) % 4];
                int ny = temp_y + dy[(dir + i) % 4];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 6)
                    break;
                
                if(board[nx][ny] == 0){
                    board[nx][ny] = 7;
                    change.push_back({nx, ny});
                }
                temp_x = nx;
                temp_y = ny;
            }
        }
    }

    else if(board[x][y] == 3){
        for(int i = 0; i < 2; i++){
            int temp_x = x;
            int temp_y = y;
            while(1){
                int nx = temp_x + dx[(dir + i) % 4];
                int ny = temp_y + dy[(dir + i) % 4];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 6)
                    break;
                
                if(board[nx][ny] == 0){
                    board[nx][ny] = 7;
                    change.push_back({nx, ny});
                }
                temp_x = nx;
                temp_y = ny;
            }
        }
    }

    else if(board[x][y] == 4){
        for(int i = 0; i < 3; i++){
            int temp_x = x;
            int temp_y = y;
            while(1){
                int nx = temp_x + dx[(dir + i) % 4];
                int ny = temp_y + dy[(dir + i) % 4];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 6)
                    break;
                
                if(board[nx][ny] == 0){
                    board[nx][ny] = 7;
                    change.push_back({nx, ny});
                }
                temp_x = nx;
                temp_y = ny;
            }
        }
    }

    else if(board[x][y] == 5){
        for(int i = 0; i < 4; i++){
            int temp_x = x;
            int temp_y = y;
            while(1){
                int nx = temp_x + dx[(dir + i) % 4];
                int ny = temp_y + dy[(dir + i) % 4];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 6)
                    break;
                
                if(board[nx][ny] == 0){
                    board[nx][ny] = 7;
                    change.push_back({nx, ny});
                }
                temp_x = nx;
                temp_y = ny;
            }
        }
    }
    return change;
}

void func(int cur){
    if(cur == v.size()){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 0) cnt++;
            }
        }
        res = min(res, cnt);
        return;
    }
    for(int i = 0; i < 4; i++){
        vector<pair<int, int>> change = extend(cur, i);
        func(cur+1);
        for(pair<int, int> a : change){
            board[a.first][a.second] = 0;
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] > 0 && board[i][j] < 6){
                v.push_back({i, j});
            }
        }
    }
    func(0);
    cout << res;
}
