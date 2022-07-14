#include <bits/stdc++.h>
using namespace std;
int T;
int m, n, k; // m = 가로길이 n = 세로길이 k = 배추의개수
int board[51][51];
bool is_visited[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] =  {0, 1, 0, -1};
queue<pair<int, int>> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;

    for(int t = 0; t < T; t++){
        int cnt = 0;
        cin >> m >> n >> k;
        memset(board, 0, sizeof(board));
        memset(is_visited, false, sizeof(is_visited));

        for(int i = 0; i < k; i++){
            int x, y;
            cin >> y >> x;
            board[x][y] = 1;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 1 && is_visited[i][j] == false){
                    q.push({i, j});
                    is_visited[i][j] = true;
                    cnt++;

                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        if(board[x][y] == 1 && is_visited[x][y] == false){
                            is_visited[x][y] = true;
                            cnt++;
                        } 

                        for(int i = 0; i < 4; i++){
                            int nx = x + dx[i];
                            int ny = y + dy[i];
                            
                            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                            if(board[nx][ny] == 1 && is_visited[nx][ny] == false){
                                is_visited[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
}
